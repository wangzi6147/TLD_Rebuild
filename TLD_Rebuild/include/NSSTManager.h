#include <nss_toolkit.h>
#include <nsst_define.h>
#include <nsstplayer_define.h>
#include <opencv2/opencv.hpp>
#include <ffmpegDecode.h>
#include <stdio.h>

#pragma once

class NSSTManager{
private:
	NsstChannel   nsst_channel_;
public:
	~NSSTManager();
	void initNSST();
	void initMediaStream();
	void camHandle(int height, int width, bool ifMove, cv::Rect lastbox);
};
