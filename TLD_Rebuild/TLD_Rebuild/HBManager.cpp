#include <HBManager.h>

//decoder
ffmpegDecode *decoder;
cv::Mat decodeFrame;
bool doing = false;

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

void HBManager::initMediaStream()
{

	HB_SDVR_CLIENTINFO strClientInfo = { 0 };

	strClientInfo.hPlayWnd = NULL;
	strClientInfo.lChannel = 0;
	m_lPlayHandle = HB_SDVR_RealPlay(m_UserID, NULL, &strClientInfo);

	// 设置回调函数
	HB_SDVR_SetRealDataCallBack(m_lPlayHandle, pfnSrcDataCB, (DWORD)this);

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

void HBManager::camHandle(int height, int width, bool ifMove, cv::Rect lastbox)
{
	//NsstPTZParam param;
	//param.speed = 20;
	DWORD dwPTZCommand;
	int speed = 50;
	if (!ifMove){
		HB_SDVR_PTZControlWithSpeed(m_lPlayHandle, NULL, 1, 0);
		return;
	}
	//zoom
	/*int imgArea = height*width;
	if (lastbox.area() < imgArea / 20){
		param.speed = 50;
		param.action = NS_PTZ_MOVE_ZOOM_WIDE;
		NSSTPTZControl(&nsst_channel_, &param);
		return;
	}
	else if (lastbox.area()>imgArea / 10){
		param.speed = 50;
		param.action = NS_PTZ_MOVE_ZOOM_TELE;
		NSSTPTZControl(&nsst_channel_, &param);
		return;
	}
	else{
		param.action = NS_PTZ_MOVE_STOP;
		NSSTPTZControl(&nsst_channel_, &param);
	}*/
	
	int cX = lastbox.x + lastbox.width / 2;
	int cY = lastbox.y + lastbox.height / 2;
	int xState = 0;
	int yState = 0;
	cv::Rect r = cv::Rect(width / 3, height / 3, width / 3, height / 3);
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
	switch (state)
	{
	case 0x00:
		dwPTZCommand = NULL;
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
		break;
	}
	HB_SDVR_PTZControlWithSpeed(m_lPlayHandle, dwPTZCommand, 0, speed);
}