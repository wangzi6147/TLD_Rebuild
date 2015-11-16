#include <NSSTManager.h>

void CALLBACK message_callback(int event_type, NsstEventCommonParam* event_param){
	switch (event_type){
		case NSSTEV_LOGIN:
			if (NSST_SUCCESS == event_param->result){
				printf("login");
			}else{
				printf("login failed");
			}
			break;
		case NSSTEV_MEDIA_CONNECTED:
			printf("NSSTEV_MEDIA_CONNECTED");
			break;
		case NSSTEV_MEDIA_RECONNECTING:
			printf("NSSTEV_MEDIA_RECONNECTING");
			break;
		case NSSTEV_MEDIA_ERROR:
			printf("NSSTEV_MEDIA_ERROR");
			break;
	}
}

int CALLBACK MediaStreamCallBack(NsstChannel* nsst_channel,
	int data_type,
	char* buffer,
	int buffer_size,
	int user_data)
{
	callbackHandler *cbHandler = (callbackHandler *)user_data;
	cv::Mat temp;
	if (cbHandler->decoder == NULL)
		cbHandler->decoder = new ffmpegDecode("rtsp://admin:12345@192.168.0.99/");//rtsp://admin:123456@192.168.1.252:554/mpeg4cif
	while (temp.data == NULL){
		if (cbHandler->decoder->readOneFrame() < 0)
			break;
		temp = cbHandler->decoder->getDecodedFrame();
	}
	if (temp.data != NULL){
		cbHandler->CBframe = temp;
	}
	return 0;
}

NSSTManager::~NSSTManager(){
	delete cbHandler;
}

void NSSTManager::initNSST(){
	NSSTStartup();
	NSSTSetUserCallback(message_callback, NULL);
	NsstDevice NSSTdevice;
	DEVICE_ID device_id_;
	strcpy(NSSTdevice.host, "192.168.0.99");
	strcpy(NSSTdevice.username, "admin");
	strcpy(NSSTdevice.password, "admin");
	NSSTdevice.protocol_port = 80;
	NSSTdevice.rtsp_port = 554;
	NSSTdevice.dev_type = (NSST_DEVICE_TYPE)0;
	device_id_ = NSSTCreateDevice(&NSSTdevice, NULL);
	NSSTLogin(device_id_);
	nsst_channel_.dev_id = device_id_;
	nsst_channel_.channel = 0;
	nsst_channel_.stream = 0;
}

void NSSTManager::initMediaStream()
{
	DrawParams params;
	params.draw_wnd = 0;
	params.width = 0;
	params.height = 0;
	NSSTStartTransport(&nsst_channel_, NSST_TCP, &params, 0);
	NSSTStartPlay(&nsst_channel_);
	cbHandler = new callbackHandler();
	//ffmpegDecode decoder = ffmpegDecode("rtsp://admin:12345@192.168.0.99/");//rtsp://admin:123456@192.168.1.252:554/mpeg4cif
	//cbHandler.decoder = decoder;
	NSSTSetMediaStreamCallback(&nsst_channel_, MediaStreamCallBack, (int)cbHandler);
}


cv::Mat NSSTManager::getFrame()
{
	return cbHandler->CBframe;
}

void NSSTManager::camHandle(int height, int width, bool ifMove, cv::Rect lastbox)
{
	NsstPTZParam param;
	param.speed = 40;
	if (!ifMove){
		param.action = NS_PTZ_MOVE_STOP;
		NSSTPTZControl(&nsst_channel_, &param);
		return;
	}
	int cX = lastbox.x + lastbox.width / 2;
	int cY = lastbox.y + lastbox.height / 2;
	int xState = 0;
	int yState = 0;
	cv::Rect r = cv::Rect(width / 3, height / 3, width / 3, height / 3);

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
		param.action = NS_PTZ_MOVE_STOP;
		NSSTPTZControl(&nsst_channel_, &param);
		break;
	case 0x0A:
		param.action = NS_PTZ_MOVE_RIGHT_DOWN;
		NSSTPTZControl(&nsst_channel_, &param);
		break;
	case 0x02:
		param.action = NS_PTZ_MOVE_DOWN;
		NSSTPTZControl(&nsst_channel_, &param);
		break;
	case 0x08:
		param.action = NS_PTZ_MOVE_RIGHT;
		NSSTPTZControl(&nsst_channel_, &param);
		break;
	case 0x04:
		param.action = NS_PTZ_MOVE_LEFT;
		NSSTPTZControl(&nsst_channel_, &param);
		break;
	case 0x09:
		param.action = NS_PTZ_MOVE_RIGHT_UP;
		NSSTPTZControl(&nsst_channel_, &param);
		break;
	case 0x06:
		param.action = NS_PTZ_MOVE_LEFT_DOWN;
		NSSTPTZControl(&nsst_channel_, &param);
		break;
	case 0x01:
		param.action = NS_PTZ_MOVE_UP;
		NSSTPTZControl(&nsst_channel_, &param);
		break;
	case 0x05:
		param.action = NS_PTZ_MOVE_LEFT_UP;
		NSSTPTZControl(&nsst_channel_, &param);
		break;
	default:
		break;
	}
}