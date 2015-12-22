
#include "stdafx.h"
#include "HBSDVRSDK.h"
#include "HBPlaySDK.h"
#include <opencv2/opencv.hpp>
#include <ffmpegDecode.h>

#pragma once

class HBManager{
private:
	long m_UserID;
	HB_SDVR_DEVICEINFO_EX m_strDeviceInfoEx;
	long m_lPlayHandle;
public:
	~HBManager();
	void initHB();
	void initMediaStream();
	void camHandle(int height, int width, bool ifMove, cv::Rect lastbox);
};
