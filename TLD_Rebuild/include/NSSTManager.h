#include <nss_toolkit.h>
#include <nsst_define.h>
#include <nsstplayer_define.h>
#include <opencv2/opencv.hpp>
#include <ffmpegDecode.h>
#include <stdio.h>

#pragma once

struct callbackHandler
{
	ffmpegDecode *decoder = NULL;
	cv::Mat CBframe;
	callbackHandler(){
	}
	/*~callbackHandler(){
		delete decoder;
		}*/
};

class NSSTManager{
private:
	NsstChannel   nsst_channel_;
	cv::Mat frame;
	callbackHandler *cbHandler;
public:
	~NSSTManager();
	void initNSST();
	void initMediaStream();
	cv::Mat getFrame();
	void camHandle(int height, int width, bool ifMove, cv::Rect lastbox);
};
