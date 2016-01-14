
#include "stdafx.h"
#include "HBSDVRSDK.h"
#include "HBPlaySDK.h"
#include <opencv2/opencv.hpp>
#include <ffmpegDecode.h>
#include <fstream>
#include <thread>

#pragma once

class HBManager{
private:
	long m_UserID;
	HB_SDVR_DEVICEINFO_EX m_strDeviceInfoEx;
	long m_lPlayHandle;
	int count = 0;
	void thread_run();
public:
	~HBManager();
	void initHB();
	void initMediaStream();
	void camHandle(int height, int width, bool ifMove, cv::Rect lastbox);
	void reset();


	bool ifMove;
	int imgWidth;
	int imgHeight;
	cv::Rect lastBox;
};
