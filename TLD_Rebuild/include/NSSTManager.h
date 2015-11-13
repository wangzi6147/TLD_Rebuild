#include <nss_toolkit.h>
#include <nsst_define.h>
#include <nsstplayer_define.h>
#include <opencv2/opencv.hpp>
#include <ffmpegDecode.h>
#include <stdio.h>

#pragma once

struct callbackHandler
{
	ffmpegDecode decoder = ffmpegDecode("rtsp://admin:12345@192.168.0.99/");
	cv::Mat CBframe;
	callbackHandler(){
	}
};

class NSSTManager{
private:
	NsstChannel   nsst_channel_;
	cv::Mat frame;
	callbackHandler cbHandler;
public:
	void initNSST();
	void initMediaStream();
	cv::Mat getFrame();
	void camHandle(int height, int width, bool ifMove, cv::Rect lastbox);
};
