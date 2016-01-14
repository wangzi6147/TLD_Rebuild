#include <HBManager.h>

//decoder
ffmpegDecode *decoder;
cv::Mat decodeFrame;
bool doing = false;

using namespace std;

//void CALLBACK message_callback(int event_type, NsstEventCommonParam* event_param){
//	switch (event_type){
//		case NSSTEV_LOGIN:
//			if (NSST_SUCCESS == event_param->result){
//				printf("login");
//			}else{
//				printf("login failed");
//			}
//			break;
//		case NSSTEV_MEDIA_CONNECTED:
//			printf("NSSTEV_MEDIA_CONNECTED");
//			break;
//		case NSSTEV_MEDIA_RECONNECTING:
//			printf("NSSTEV_MEDIA_RECONNECTING");
//			break;
//		case NSSTEV_MEDIA_ERROR:
//			printf("NSSTEV_MEDIA_ERROR");
//			break;
//	}
//}
//
//int CALLBACK MediaStreamCallBack(NsstChannel* nsst_channel,
//	int data_type,
//	char* buffer,
//	int buffer_size,
//	int user_data)
//{
//	if (decoder == NULL)
//		decoder = new ffmpegDecode("rtsp://admin:admin@192.168.1.50/1/1080p");//rtsp://admin:123456@192.168.1.252:554/mpeg4cif
//	cv::Mat temp;
//	while (temp.data == NULL){
//		if (decoder->readOneFrame() < 0)
//			break;
//		temp = decoder->getDecodedFrame();
//	}
//	if (temp.data != NULL){
//		decodeFrame = temp;
//	}
//	return 0;
//}


//回调函数 每次捕捉新的画面
void CALLBACK pfnSrcDataCB(LONG  lRealHandle,DWORD   dwDataType,BYTE   *pBuffer,DWORD  dwBufSize,DWORD  dwUser){
	if (doing)
	{
		return;
	}
	if (decoder == NULL){
		doing = true;
		decoder = new ffmpegDecode("rtsp://admin:admin@192.168.1.50:554/1/1080p");//rtsp://admin:123456@192.168.1.252:554/mpeg4cif
		doing = false;
	}
	cv::Mat temp;
	while (temp.data == NULL){
		if (decoder->readOneFrame() < 0){
			break;
		}
		temp = decoder->getDecodedFrame();
	}
	if (temp.data != NULL){
		decodeFrame = temp;
	}
}




HBManager::~HBManager(){
}

//初始化摄像头
void HBManager::initHB(){
	BOOL res = HB_SDVR_Init();
	m_UserID = HB_SDVR_Login_Ex_Nvs("192.168.1.50", 8101, "admin", "admin", &m_strDeviceInfoEx);

	if (m_UserID > 0)
	{
		printf("登陆成功");
	}
	else
	{
		printf("登录失败");
	}
	/*NSSTSetUserCallback(message_callback, NULL);
	NsstDevice NSSTdevice;
	DEVICE_ID device_id_;
	strcpy(NSSTdevice.host, "192.168.1.50");
	strcpy(NSSTdevice.username, "admin");
	strcpy(NSSTdevice.password, "admin");
	NSSTdevice.protocol_port = 80;
	NSSTdevice.rtsp_port = 554;
	NSSTdevice.dev_type = (NSST_DEVICE_TYPE)0;
	device_id_ = NSSTCreateDevice(&NSSTdevice, NULL);
	NSSTLogin(device_id_);
	nsst_channel_.dev_id = device_id_;
	nsst_channel_.channel = 0;
	nsst_channel_.stream = 0;*/
}

//初始化视频
void HBManager::initMediaStream()
{

	HB_SDVR_CLIENTINFO strClientInfo = { 0 };

	strClientInfo.hPlayWnd = NULL;
	strClientInfo.lChannel = 0;
	m_lPlayHandle = HB_SDVR_RealPlay(m_UserID, NULL, &strClientInfo);

	// 设置回调函数
	HB_SDVR_SetRealDataCallBack(m_lPlayHandle, pfnSrcDataCB, (DWORD)this);
	HB_SDVR_PTZPreset(m_lPlayHandle, GOTO_PRESET, 65);	

	//开启控制线程
	ifMove = false;
	imgHeight = 0;
	imgWidth = 0;

	//DrawParams params;
	//params.draw_wnd = 0;
	//params.width = 0;
	//params.height = 0;
	//NSSTStartTransport(&nsst_channel_, NSST_TCP, &params, 0);
	//NSSTStartPlay(&nsst_channel_);
	////ffmpegDecode decoder = ffmpegDecode("rtsp://admin:12345@192.168.0.99/");//rtsp://admin:123456@192.168.1.252:554/mpeg4cif
	////cbHandler.decoder = decoder;
	//NSSTSetMediaStreamCallback(&nsst_channel_, MediaStreamCallBack, 0);
}

void HBManager::thread_run(){
	Sleep(100);
	DWORD dwPTZCommand;
	int speed = 30;
	if (!ifMove){
		HB_SDVR_PTZControlWithSpeed(m_lPlayHandle, NULL, 1, 0);
		count++;
		std::cout << count << std::endl;
		return;
	}
	count = 0;
	int cX = lastBox.x + lastBox.width / 2;
	int cY = lastBox.y + lastBox.height / 2;
	int xState = 0;
	int yState = 0;
	cv::Rect r = cv::Rect(imgWidth / 3, imgHeight / 3, imgWidth / 3, imgHeight / 3);
	//cv::Rect r = cv::Rect(width  / 5, height / 5, width *3/ 5, height*3 / 5);
	//Rect r = Rect(width * 2 / 5, height * 2 / 5, width / 5, height / 5);
	if (cX < r.x){
		xState = 1;
	}
	else if (cX>r.br().x){
		xState = 2;
	}
	if (cY < r.y){
		yState = 1;
	}
	else if (cY>r.br().y){
		yState = 2;
	}
	int state = (xState << 2) + yState;
	float area = lastBox.width*lastBox.height;
	switch (state)
	{
	case 0x00:
		dwPTZCommand = NULL;
		HB_SDVR_PTZControlWithSpeed(m_lPlayHandle, dwPTZCommand, 1, speed);
		if (area < 320 * 240 * 0.01)
		{
			dwPTZCommand = FOCUS_NEAR;
			HB_SDVR_PTZControl_Other(m_lPlayHandle, 0, dwPTZCommand, 0);
		}
		else if (area > 320 * 240 * 0.1)
		{
			dwPTZCommand = FOCUS_FAR;
			HB_SDVR_PTZControl_Other(m_lPlayHandle, 0, dwPTZCommand, 0);
		}
		else
		{
			HB_SDVR_PTZControlWithSpeed_Other(m_lPlayHandle, 0, NULL, 1, speed);
		}
		break;
	case 0x0A:
		dwPTZCommand = TILT_RIGHT_DOWN;
		break;
	case 0x02:
		dwPTZCommand = TILT_DOWN;
		break;
	case 0x08:
		dwPTZCommand = PAN_RIGHT;
		break;
	case 0x04:
		dwPTZCommand = PAN_LEFT;
		break;
	case 0x09:
		dwPTZCommand = TILT_RIGHT_UP;
		break;
	case 0x06:
		dwPTZCommand = TILT_LEFT_DOWN;
		break;
	case 0x01:
		dwPTZCommand = TILT_UP;
		break;
	case 0x05:
		dwPTZCommand = TILT_LEFT_UP;
		break;
	default:
		//dwPTZCommand = FOCUS_FAR;
		//HB_SDVR_PTZControl_Other(m_lPlayHandle, 0, dwPTZCommand, 0);
		break;
	}
	HB_SDVR_PTZControlWithSpeed(m_lPlayHandle, dwPTZCommand, 0, speed);

}

//控制摄像头
void HBManager::camHandle(int height, int width, bool ifMove, cv::Rect lastbox)
{
	this->ifMove = ifMove;
	this->imgWidth = width;
	this->imgHeight = height;
	this->lastBox = lastbox;
	std::thread t(&HBManager::thread_run, this);
	t.detach();
}

//控制摄像头到预置位
void HBManager::reset(){
	if (count > 20){
		count = 0;
		std::ifstream infile("../../../one_cam/one_cam/one_cam/output.txt");
		int pos = -1;
		infile >> pos;
		std::cout << pos << std::endl << std::endl;
		if (pos > 0){
			switch (pos)
			{
			case 1:
			case 4:
			case 7:
				HB_SDVR_PTZPreset(m_lPlayHandle, GOTO_PRESET, 64);
				break;
			case 2:
			case 5:
			case 8:
				HB_SDVR_PTZPreset(m_lPlayHandle, GOTO_PRESET, 65);
				break;
			case 3:
			case 6:
			case 9:
				HB_SDVR_PTZPreset(m_lPlayHandle, GOTO_PRESET, 66);
				break;
			default:
				break;
			}
		}
		infile.close();
	}
}