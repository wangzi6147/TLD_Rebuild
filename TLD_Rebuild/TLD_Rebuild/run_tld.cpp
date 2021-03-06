﻿#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <tld_utils.h>
#include <iostream>
#include <sstream>
#include <TLD.h>
#include <videoInput.h>
#include <ffmpegDecode.h>
#include <HBManager.h>
#include <DShow.h>
#include <strmif.h>

#pragma comment(linker, "/NODEFAULTLIB:atlthunk.lib")
#pragma comment(lib, "cudart.lib")
#pragma comment(lib, "7000sdk.lib")
#pragma comment(lib, "HBPlaySDK.lib")
#pragma comment(lib, "videoInput.lib")

#define FROM_CAMERA

using namespace cv;
using namespace std;
//Global variables
Rect box;
bool drawing_box = false;
bool gotBB = false;
bool tl = true;
bool rep = false;
bool fromfile = false;
string video;

extern cv::Mat decodeFrame;


void readBB(char* file){
	ifstream bb_file(file);
	string line;
	getline(bb_file, line);
	istringstream linestream(line);
	string x1, y1, x2, y2;
	getline(linestream, x1, ',');
	getline(linestream, y1, ',');
	getline(linestream, x2, ',');
	getline(linestream, y2, ',');
	int x = atoi(x1.c_str());// = (int)file["bb_x"];
	int y = atoi(y1.c_str());// = (int)file["bb_y"];
	int w = atoi(x2.c_str()) - x;// = (int)file["bb_w"];
	int h = atoi(y2.c_str()) - y;// = (int)file["bb_h"];
	box = Rect(x, y, w, h);
}
//bounding box mouse callback
void mouseHandler(int event, int x, int y, int flags, void *param){
	switch (event){
	case CV_EVENT_MOUSEMOVE:
		if (drawing_box){
			box.width = x - box.x;
			box.height = y - box.y;
		}
		break;
	case CV_EVENT_LBUTTONDOWN:
		drawing_box = true;
		box = Rect(x, y, 0, 0);
		break;
	case CV_EVENT_LBUTTONUP:
		drawing_box = false;
		if (box.width < 0){
			box.x += box.width;
			box.width *= -1;
		}
		if (box.height < 0){
			box.y += box.height;
			box.height *= -1;
		}
		gotBB = true;
		break;
	}
}

void print_help(char** argv){
	printf("use:\n     %s -p /path/parameters.yml\n", argv[0]);
	printf("-s    source video\n-b        bounding box file\n-tl  track and learn\n-r     repeat\n");
}

void read_options(int argc, char** argv, VideoCapture& capture, FileStorage &fs){
	for (int i = 0; i<argc; i++){
		if (strcmp(argv[i], "-b") == 0){
			if (argc>i){
				readBB(argv[i + 1]);
				gotBB = true;
			}
			else
				print_help(argv);
		}
		if (strcmp(argv[i], "-s") == 0){
			if (argc > i){
				video = string(argv[i + 1]);
				capture.open(video);
				fromfile = true;
			}
			else
				print_help(argv);

		}
		if (strcmp(argv[i], "-p") == 0){
			if (argc > i){
				if (!fs.open(argv[i + 1], FileStorage::READ))
					printf("Couldn't open parameters file\n");
			}
			else
				print_help(argv);
		}
		if (strcmp(argv[i], "-no_tl") == 0){
			tl = false;
		}
		if (strcmp(argv[i], "-r") == 0){
			if (fromfile)
				rep = true;
			else
				printf("Cannot repeat live captures. Ignoring \"-r\" option.\n");
		}
	}
}

const char* cascade_name = "../haarcascade_frontalface_alt.xml";
static CvHaarClassifierCascade* cascade = 0;
static CvMemStorage* storage = 0;
void humanDetect(IplImage* img, std::vector<cv::Rect>& regions)
{
	//static CvScalar colors[] =
	//{
	//	{ { 0, 0, 255 } },
	//	{ { 0, 128, 255 } },
	//	{ { 0, 255, 255 } },
	//	{ { 0, 255, 0 } },
	//	{ { 255, 128, 0 } },
	//	{ { 255, 255, 0 } },
	//	{ { 255, 0, 0 } },
	//	{ { 255, 0, 255 } }
	//};

	double scale = 1;
	IplImage* gray = cvCreateImage(cvSize(img->width, img->height), 8, 1);
	IplImage* small_img = cvCreateImage(cvSize(cvRound(img->width / scale),
		cvRound(img->height / scale)),
		8, 1);
	int i;

	cvCvtColor(img, gray, CV_BGR2GRAY);
	cvResize(gray, small_img, CV_INTER_LINEAR);
	cvEqualizeHist(small_img, small_img);
	cvClearMemStorage(storage);

	if (cascade)
	{
		double t = (double)cvGetTickCount();
		CvSeq* faces = cvHaarDetectObjects(small_img, cascade, storage,
			1.1, 2, 0/*CV_HAAR_DO_CANNY_PRUNING*/,
			cvSize(10, 10), cvSize(100, 100));
		t = (double)cvGetTickCount() - t;
		//printf( "detection time = %gms\n", t/((double)cvGetTickFrequency()*1000.) );
		for (i = 0; i < (faces ? faces->total : 0); i++)
		{
			CvRect* r = (CvRect*)cvGetSeqElem(faces, i);
			//CvPoint center;
			if (r->x < 0 || r->x + r->width>img->width){
				continue;
			}
			regions.push_back(cv::Rect(r->x, r->y, r->width, 2*r->height));
			//int radius;
			//center.x = cvRound((r->x + r->width*0.5)*scale);
			//center.y = cvRound((r->y + r->height*0.5)*scale);
			//radius = cvRound((r->width + r->height)*0.25*scale);
			//cvCircle(img, center, radius, colors[i % 8], 3, 8, 0);
		}
	}




	cvReleaseImage(&gray);
	cvReleaseImage(&small_img);
}


HRESULT FindCaptureDevice(IBaseFilter ** ppSrcFilter)
{
	HRESULT hr;
	IBaseFilter * pSrc = NULL;
	IMoniker *pMoniker = NULL;
	ULONG cFetched;

	if (!ppSrcFilter)
		return E_POINTER;

	// Create the system device enumerator
	ICreateDevEnum *pDevEnum = NULL;

	hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC,
		IID_ICreateDevEnum, (void **)&pDevEnum);
	if (FAILED(hr))
	{
		return hr;
	}

	// Create an enumerator for the video capture devices
	IEnumMoniker *pClassEnum = NULL;

	hr = pDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pClassEnum, 0);
	if (FAILED(hr))
	{
		return hr;
	}

	// If there are no enumerators for the requested type, then 
	// CreateClassEnumerator will succeed, but pClassEnum will be NULL.
	if (pClassEnum == NULL)
	{
		return E_FAIL;
	}

	// Use the first video capture device on the device list.
	// Note that if the Next() call succeeds but there are no monikers,
	// it will return S_FALSE (which is not a failure).  Therefore, we
	// check that the return code is S_OK instead of using SUCCEEDED() macro.
	if (S_OK == (pClassEnum->Next(1, &pMoniker, &cFetched)))
	{
		IBindCtx *pbc = NULL;

		CreateBindCtx(0, &pbc);
		// Bind Moniker to a filter object
		hr = pMoniker->BindToObject(pbc, 0, IID_IBaseFilter, (void**)&pSrc);
		pbc->Release();
		if (FAILED(hr))
		{
			return hr;
		}
	}
	else
	{
		return E_FAIL;
	}

	// Copy the found filter pointer to the output parameter.
	// Do NOT Release() the reference, since it will still be used
	// by the calling function.
	*ppSrcFilter = pSrc;

	return hr;
}


int main(int argc, char * argv[]){
	cvReleaseHaarClassifierCascade(&cascade);
	cascade = (CvHaarClassifierCascade*)cvLoad(cascade_name, 0, 0, 0);
	storage = cvCreateMemStorage(0);
	//NSST init
	HBManager nManager;
	nManager.initHB();
	//create a videoInput object
	videoInput VI;

	//Prints out a list of available devices and returns num of devices found
	int numDevices = VI.listDevices();

	int device = 0;  //this could be any deviceID that shows up in listDevices

	VideoCapture capture;
	FileStorage fs;
	//Read options
	read_options(argc, argv, capture, fs);
	int width, height;
	unsigned char * framePixels = NULL;
	//Init camera
	if (!fromfile) {
		if (!VI.setupDevice(device, 320, 240)) {
			cout << "capture device failed to open!" << endl;
			return 1;
		}
		//As requested width and height can not always be accomodated
		//make sure to check the size once the device is setup

		width = VI.getWidth(device);
		height = VI.getHeight(device);
		int size = VI.getSize(device);

		framePixels = new unsigned char[size];
	}
	else if (!capture.isOpened()) {
		cout << "capture device failed to open!" << endl;
		return 1;
	}
	//Register mouse callback to draw the bounding box
	namedWindow("FG Mask MOG 2");
	cvNamedWindow("TLD", CV_WINDOW_AUTOSIZE);
	cvSetMouseCallback("TLD", mouseHandler, NULL);
	//MOG2
	BackgroundSubtractor *pMOG2 = new BackgroundSubtractorMOG2();
	Mat fgMaskMOG2;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	Rect r;
	int centerP = 2;
	//HOG
	Mat ROI;
	//cv::HOGDescriptor hog; // 采用默认参数
	//hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());  // 采用已经训练好的行人检测分类器
	std::vector<cv::Rect> regions;
	//TLD framework
	TLD tld;
	//Read parameters file
	tld.read(fs.getFirstTopLevelNode());
	Mat frame;
	Mat last_gray;
	Mat first;
	Size size;
	if (fromfile){
		capture >> frame;
		cvtColor(frame, last_gray, CV_RGB2GRAY);
		frame.copyTo(first);
	}
	else {
		while (!VI.isFrameNew(device));
		VI.getPixels(device, framePixels, false, true);
		first = cv::Mat(height, width, CV_8UC3, framePixels);
	}

	///Initialization
	size = Size(first.cols*(float)fs.getFirstTopLevelNode()["resize_width"], first.rows*(float)fs.getFirstTopLevelNode()["resize_height"]);

	Sleep(1000);

	//media stream
	nManager.initMediaStream();

#ifdef FROM_CAMERA
	while (decodeFrame.data == NULL){
		Sleep(1000);
		continue;
	}
#endif // FROM_CAMERA

#ifdef FROM_CAMERA
	while (decodeFrame.data != NULL){
		first = decodeFrame;
#else
	while (fromfile&&capture.read(first)){
#endif // fromCamera
		resize(first, first, size);
		imshow("TLD", first);
		////test control
		//NsstPTZParam param;
		//param.action = NS_PTZ_MOVE_LEFT;
		//param.speed = 50;
		//NSSTPTZControl(&nsst_channel_, &param);
		if (cvWaitKey(33) == ' '){
			break;
		}
	}


#ifdef FROM_CAMERA
	while (decodeFrame.data != NULL){
		first = decodeFrame;
#else
	while (fromfile&&capture.read(first)){
#endif // fromCamera
		resize(first, first, size);
		pMOG2->operator()(first, fgMaskMOG2, -0.1);
		erode(fgMaskMOG2, fgMaskMOG2, getStructuringElement(0, Size(2 * centerP + 1, 2 * centerP + 1), Point(centerP, centerP)));
		dilate(fgMaskMOG2, fgMaskMOG2, getStructuringElement(0, Size(2 * centerP + 1, 2 * centerP + 1), Point(centerP, centerP)));
		dilate(fgMaskMOG2, fgMaskMOG2, getStructuringElement(0, Size(2 * centerP + 1, 2 * centerP + 1), Point(centerP, centerP)));
		if (contours.size() > 0){
			contours.clear();
		}
		if (hierarchy.size() > 0){
			hierarchy.clear();
		}
		findContours(fgMaskMOG2, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
		for (int i = 0; i < contours.size(); i++){
			if (contourArea(contours[i]) < first.rows*first.cols / 40 || contourArea(contours[i]) > first.rows*first.cols*0.8){
				continue;
			}
			r = boundingRect(contours[i]);
			int temp = r.y>r.height / 3 ? r.y - r.height/3 : 0;
			r = Rect(cvPoint(r.x, temp), cvPoint(r.x + r.width, r.y + r.height));
			ROI = first(r);
			regions.clear();
			if (ROI.cols >= 32 && ROI.rows >= 32)
			{
				//hog.detectMultiScale(ROI, regions, 0, cv::Size(8, 8), cv::Size(32, 32), 1.05, 1);
				//for (int j = 0; j < regions.size(); j++){
				//	rectangle(first, cv::Point(r.x + regions[j].x, r.y + regions[j].y), cv::Point(r.x + regions[j].x + regions[j].width, r.y + regions[j].y + regions[j].height), cv::Scalar(255, 0, 0), 1);
				//}
				//rectangle(fgMaskMOG2, cv::Point(r.x, r.y), cv::Point(r.x + r.width, r.y + r.height), cv::Scalar(255, 255, 255), 1);
				IplImage* img = cvCreateImage(cvSize(fgMaskMOG2.cols, fgMaskMOG2.rows), IPL_DEPTH_8U, 3);
				*img = ROI;
				humanDetect(img, regions);
				rectangle(fgMaskMOG2, cv::Point(r.x, r.y), cv::Point(r.x + r.width, r.y + r.height), cv::Scalar(255, 255, 255), 1);
			}
		}
		if (regions.size() > 0){
			box = Rect(cv::Point(r.x + regions[0].x, r.y + regions[0].y), cv::Point(r.x + regions[0].x + regions[0].width, r.y + regions[0].y + regions[0].height));
			box = Rect(cv::Point(box.x + box.width / 5, box.y), cv::Point(box.x + box.width * 4 / 5, box.y + box.height));
			if (min(box.width, box.height) >= (int)fs.getFirstTopLevelNode()["min_win"]){
				first.copyTo(frame);
				cvtColor(frame, last_gray, CV_RGB2GRAY);
				drawBox(frame, box);
				imshow("TLD", frame);
				imshow("FG Mask MOG 2", fgMaskMOG2);
				cvWaitKey(33);
				gotBB = true;
				break;
			}
		}
		imshow("TLD", first);
		imshow("FG Mask MOG 2", fgMaskMOG2);
		if (cvWaitKey(33) == ' '){
			break;
		}
	}
GETBOUNDINGBOX:
	while (!gotBB)
	{
		resize(first, first, size);
		first.copyTo(frame);
		cvtColor(frame, last_gray, CV_RGB2GRAY);
		drawBox(frame, box);
		imshow("TLD", frame);
		if (cvWaitKey(33) == 'q')
			return 0;
	}
	if (min(box.width, box.height) < (int)fs.getFirstTopLevelNode()["min_win"]){
		cout << "Bounding box too small, try again." << endl;
		gotBB = false;
		goto GETBOUNDINGBOX;
	}
	//Remove callback
	cvSetMouseCallback("TLD", NULL, NULL);
	printf("Initial Bounding Box = x:%d y:%d h:%d w:%d\n", box.x, box.y, box.width, box.height);
	//Output file
	FILE  *bb_file = fopen("bounding_boxes.txt", "w");
	//TLD initialization
	tld.init(last_gray, box, bb_file, nManager);

	///Run-time
	Mat current_gray;
	BoundingBox pbox;
	vector<Point2f> pts1;
	vector<Point2f> pts2;
	bool status = true;
	int frames = 1;
	int detections = 1;
REPEAT:

#ifdef FROM_CAMERA
	while (decodeFrame.data != NULL){
		frame = decodeFrame;
#else
	while((fromfile && capture.read(frame)) || !fromfile){
#endif // fromCamera
		if (!fromfile) {
			while (!VI.isFrameNew(device));
			VI.getPixels(device, framePixels, false, true);
			frame = cv::Mat(height, width, CV_8UC3, framePixels);
		}

		//get frame
		resize(frame, frame, size);
		cvtColor(frame, current_gray, CV_RGB2GRAY);
		//Process Frame
		tld.processFrame(last_gray, current_gray, pts1, pts2, pbox, status, tl, bb_file);
		//Draw Points
		if (status){
			drawPoints(frame, pts1);
			drawPoints(frame, pts2, Scalar(0, 255, 0));
			drawBox(frame, pbox);
			detections++;
		}
		//Display
		imshow("TLD", frame);
		//swap points and images
		swap(last_gray, current_gray);
		pts1.clear();
		pts2.clear();
		frames++;
		printf("Detection rate: %d/%d\n", detections, frames);
		int key = cvWaitKey(33);
		if (key == 'q')
			return 0;
		else if (key == ' '){
			while (cvWaitKey(-1) != ' ')
				continue;
		}
	}
	if (rep){
		rep = false;
		tl = false;
		fclose(bb_file);
		bb_file = fopen("final_detector.txt", "w");
		//capture.set(CV_CAP_PROP_POS_AVI_RATIO,0);
		capture.release();
		capture.open(video);
		goto REPEAT;
	}
	fclose(bb_file);
	return 0;
}
