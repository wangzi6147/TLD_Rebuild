////////////////////////////////////////////////////////////////////////////////
// Copyright (C), 2009-2010, Beijing Hanbang Technology, Inc.
////////////////////////////////////////////////////////////////////////////////
//
// File Name:   NetSDK.h
// Author:      
// Version:     3.00
// Date:        
// Description: Header file of 7000SDK.dll and 7000SDK.lib.
// History:
//
////////////////////////////////////////////////////////////////////////////////

// ԭ����ӿ�
#ifndef HB_NETSDK_H
#define HB_NETSDK_H

#include "HBPlaySDK.h"

#define HB_SDVR_API  extern "C"/*__declspec(dllexport)*/

// #ifdef __cplusplus
// extern "C" {
// #endif

// �궨��
#define TILT_UP			            0x0001000c	/* ��̨��SS���ٶ����� */
#define TILT_DOWN		            0x0001000d	/* ��̨��SS���ٶ��¸� */
#define PAN_LEFT		            0x0001000e 	/* ��̨��SS���ٶ���ת */
#define PAN_RIGHT		            0x0001000f	/* ��̨��SS���ٶ���ת */
#define FOCUS_NEAR		            0x00010014  /* �������ٶ�SSǰ�� */
#define FOCUS_FAR		            0x00010015 	/* �������ٶ�SS��� */
#define ZOOM_IN			            0x00010016	/* �������ٶ�SS���(���ʱ��) */
#define ZOOM_OUT		            0x00010017 	/* �������ٶ�SS��С(���ʱ�С) */
#define IRIS_OPEN		            0x00010018 	/* ��Ȧ���ٶ�SS���� */
#define IRIS_CLOSE		            0x00010019	/* ��Ȧ���ٶ�SS��С */

#define SET_PRESET		            0x0001001a 	/* ����Ԥ�õ� */ 
#define GOTO_PRESET		            0x0001001b 	/* ����ת��Ԥ�õ� */
#define PAN_AUTO		            0x0001001c 	/* ��̨��SS���ٶ������Զ�ɨ�� */
#define LIGHT_PWRON		            0x00010024	/* ��ͨ�ƹ��Դ */
#define WIPER_PWRON		            0x00010025	/* ��ͨ��ˢ���� */
#define TM_COM_GUI_BRUSH            0x0001002e  /* ��ˢ */

//�������
#define TILT_LEFT_UP                0x00010010  /*��̨��dwSpeed���ٶ�����*/
#define TILT_LEFT_DOWN              0x00010011  /*��̨��dwSpeed���ٶ�����*/ 
#define TILT_RIGHT_UP               0x00010012  /*��̨��dwSpeed���ٶ�����*/
#define TILT_RIGHT_DOWN             0x00010013  /*��̨��dwSpeed���ٶ�����*/ 
#define CLR_PRESET		            0x0001001d  /*���Ԥ�õ�*/ 
#define ALL_STOP                    0x00010028  /*��̨����(��PAN_AUTO)���ͺ���Ҫ�ٷ��ͱ�������ֹͣǰһ����*/

#define VIDEO_FREEZE_ENABLE         0x00020001  /*Ԥ�õ���Ƶ����    -1-��֧�֣�0-�����ã�1-����*/
#define SCALE_TIMES_ENABLE          0x00020002  /*�����䱶            -1-��֧�֣�0-�����ã�1-����*/
#define POWER_OFF_MEM_TIME	        0x00020003	/*�ϵ����ʱ��        -1-��֧�֣�30�룬60�룬300�룬600��*/
#define LEN_TIMES_ENABLE		    0x00020004  /*��ͷ������ʾ	    -1-��֧�֣�0-�����ã�1-����*/
#define AZIMUTHS_ENABLE		        0x00020005  /*��λ����ʾ          -1-��֧�֣�0-�����ã�1-����*/
#define PRESET_CAPTION_ENABLE       0x00020006  /*Ԥ�õ������ʾ      -1-��֧�֣�0-�����ã�1-����*/

#define PRESET_POINT_ALL_CLEAR      0x00030001  /*������е�Ԥ�õ�*/       
#define CRUISE_ALL_CLEAR	        0x00030002  /*������Ե�Ԥ�õ�Ѳ��·�� */
#define PATTERN_ALL_CLEAR	        0x00030003  /*������ԵĻ���ɨ�� �켣����*/  
#define LIMIT_ALL_CLEAR		        0x00030004  /*������е���λ����*/ 
#define TIME_TASK_ALL_CLEAR	        0x00030005  /*������еĶ�ʱ����*/   
#define PARK_ALL_CLEAR	            0x00030006  /*������е�����*/ 

#define SET_PRE_SEQ 		        0x00040001  /*����Ѳ����*/
#define GET_PRE_SEQ 		        0x00040002  /*��ȡѲ����*/
#define RUN_SEQ 				    0x00040005  /*��ʼѲ��*/ 
#define STOP_SEQ                    0x00040006  /*ֹͣѲ��*/ 

#define GET_RECORD_TRACK_STATUS 	0x00050001  /*��ȡ�켣���䣨����ɨ�裩��״̬*/
#define START_RECORD_TRACK          0x00050002  /*��ʼ��¼�켣������ɨ�裩*/
#define STOP_RECORD_TRACK           0x00050003  /*ֹͣ��¼�켣������ɨ�裩*/
#define STORE_RECORD_TRACK          0x00050004  /*�����¼�켣������ɨ�裩*/
#define CLEAR_RECORD_TRACK          0x00050005  /*��ո���켣���䣨����ɨ�裩*/
#define START_TRACK                 0x00050006  /*��������ɨ��*/
#define STOP_TRACK                  0x00050007  /*ֹͣ����ɨ�� */   


//��ʾģʽ
#ifndef DISPLAY_MODE_defined
#define DISPLAY_MODE_defined
enum{NORMALMODE = 0,OVERLAYMODE};
#endif

//����ģʽ
#ifndef SEND_MODE_defined
#define SEND_MODE_defined
enum{PTOPTCPMODE,PTOPUDPMODE,MULTIMODE,RTPMODE,AUDIODETACH,NOUSEMODE};
#endif



#define HB_SDVR_SYSHEAD 	        64	//ϵͳͷ����
#define HB_SDVR_STREAMDATA 	        2	//������
#define HB_SDVR_BACKUPEND           3   //���ݽ���

//���ſ�������궨�� HB_SDVR_PlayBackControl,HB_SDVR_PlayControlLocDisplay,HB_SDVR_DecPlayBackCtrl�ĺ궨��
#define HB_SDVR_PLAYSTART		    1   //��ʼ����
#define HB_SDVR_PLAYSTOP		    2   //ֹͣ����
#define HB_SDVR_PLAYPAUSE		    3   //��ͣ����
#define HB_SDVR_PLAYRESTART		    4   //�ָ�����
#define HB_SDVR_PLAYFAST		    5   //���
#define HB_SDVR_PLAYSLOW		    6   //����
#define HB_SDVR_PLAYNORMAL		    7   //�����ٶ�
#define HB_SDVR_PLAYFRAME		    8   //��֡��
#define HB_SDVR_PLAYSTARTAUDIO		9   //������
#define HB_SDVR_PLAYSTOPAUDIO		10  //�ر�����
#define HB_SDVR_PLAYAUDIOVOLUME		11  //��������
#define HB_SDVR_PLAYGETPOS		    13  //��ȡ�ļ��طŵĽ���   ������100ʱ���ʾ����
#define HB_SDVR_PLAYBACK		    21  //����
#define HB_SDVR_PLAYBYSLIDER	    22  //������������

#define  HB_SDVR_SET_SERIALID       0x67
#define  HB_SDVR_GET_SERIALID       0x68
#define  HB_SDVR_GET_VLostStatus    0x69

//HB_SDVR_GetDVRConfig,HB_SDVR_GetDVRConfig�������
#define HB_SDVR_GET_DEVICECFG		100		//��ȡ�豸����
#define HB_SDVR_SET_DEVICECFG		101		//�����豸����
#define HB_SDVR_GET_NETCFG			102		//��ȡ�������
#define HB_SDVR_SET_NETCFG			103		//�����������
#define HB_SDVR_GET_PICCFG			104		//��ȡͼ�����
#define HB_SDVR_SET_PICCFG			105		//����ͼ�����
#define HB_SDVR_GET_COMPRESSCFG		106		//��ȡѹ������
#define HB_SDVR_SET_COMPRESSCFG		107		//����ѹ������
#define HB_SDVR_GET_RECORDCFG		108		//��ȡ¼��ʱ�����
#define HB_SDVR_SET_RECORDCFG		109		//����¼��ʱ�����
#define HB_SDVR_GET_DECODERCFG		110		//��ȡ����������
#define HB_SDVR_SET_DECODERCFG		111		//���ý���������
#define HB_SDVR_GET_RS232CFG 		112		//��ȡ232���ڲ���
#define HB_SDVR_SET_RS232CFG		113		//����232���ڲ���
#define HB_SDVR_GET_ALARMINCFG 		114		//��ȡ�����������
#define HB_SDVR_SET_ALARMINCFG		115		//���ñ����������
#define HB_SDVR_GET_ALARMOUTCFG 	116		//��ȡ�����������
#define HB_SDVR_SET_ALARMOUTCFG		117		//���ñ����������
#define HB_SDVR_GET_TIMECFG 		118		//��ȡDVRʱ��
#define HB_SDVR_SET_TIMECFG			119		//����DVRʱ��
#define HB_SDVR_GET_PREVIEWCFG 		120		//��ȡԤ������
#define HB_SDVR_SET_PREVIEWCFG		121		//����Ԥ������
#define HB_SDVR_GET_VIDEOOUTCFG 	122		//��ȡ��Ƶ�������
#define HB_SDVR_SET_VIDEOOUTCFG		123		//������Ƶ�������
#define HB_SDVR_GET_USERCFG 		124		//��ȡ�û�����
#define HB_SDVR_SET_USERCFG			125		//�����û�����
#define HB_SDVR_GET_EXCEPTIONCFG 	126		//��ȡ�쳣����
#define HB_SDVR_SET_EXCEPTIONCFG	127		//�����쳣����

//�������128·���� 
#define HB_SDVR_GET_ALARMINCFG_NVS	128		//��ȡ�����������
#define HB_SDVR_SET_ALARMINCFG_NVS	129		//���ñ����������

//�����ַ�
#define HB_SDVR_GET_SHOWSTRING		130		//��ȡ�����ַ�����
#define HB_SDVR_SET_SHOWSTRING		131		//���õ����ַ�����

//GE ODM
#define HB_SDVR_GET_EVENTCOMPCFG	132		//��ȡ�¼�����¼�����
#define HB_SDVR_SET_EVENTCOMPCFG	133		//�����¼�����¼�����

#define HB_SDVR_GET_FTPCFG			134		//��ȡץͼ��FTP����
#define HB_SDVR_SET_FTPCFG			135		//����ץͼ��FTP����
#define HB_SDVR_GET_JPEGCFG			136		//��ȡץͼ��JPEG����
#define HB_SDVR_SET_JPEGCFG			137		//����ץͼ��JPEG����

//������γѶ
#define HB_SDVR_GET_PPPOECFG		138		//��ȡPPPoE����
#define HB_SDVR_SET_PPPOECFG		139     //����PPPoE����

//HS�豸�������
#define HB_SDVR_GET_AUXOUTCFG		140		//��ȡ�������������������
#define HB_SDVR_SET_AUXOUTCFG		141		//���ñ������������������

#define HB_SDVR_GET_PICCFG_EX		200		//��ȡͼ���������չ��
#define HB_SDVR_SET_PICCFG_EX		201		//����ͼ���������չ��

#define HB_SDVR_GET_PICCFG_EX_NVS	204		//��ȡͼ���������չ���������128·����
#define HB_SDVR_SET_PICCFG_EX_NVS	205		//����ͼ���������չ���������128·����

//�������128·�������͵���չ����
#define HB_SDVR_GET_USERCFG_NVS		206		//��ȡ�û�����
#define HB_SDVR_SET_USERCFG_NVS		207		//�����û�����

//SDK_V15 ��չ����
#define HB_SDVR_GET_USERCFG_EX 		202		//��ȡ�û�����
#define HB_SDVR_SET_USERCFG_EX		203		//�����û�����
#define HB_SDVR_GET_DNS             301
#define HB_SDVR_SET_DNS             302
#define HB_SDVR_GET_DNS_NVS         305
#define HB_SDVR_SET_DNS_NVS         306
#define HB_SDVR_GET_PPPoE           303
#define HB_SDVR_SET_PPPoE           304

#define	HB_SDVR_SERVERCFG_GET		400	    //��ȡƽ̨����������
#define	HB_SDVR_SERVERCFG_SET		401	    //������ƽ̨����������

//��Ϣ��ʽ
//�쳣����
#define EXCEPTION_EXCHANGE			0x8000	//�û�����ʱ�쳣
#define EXCEPTION_AUDIOEXCHANGE		0x8001	//�����Խ��쳣
#define EXCEPTION_ALARM				0x8002	//�����쳣
#define EXCEPTION_PREVIEW			0x8003	//����Ԥ���쳣
#define EXCEPTION_SERIAL			0x8004	//͸��ͨ���쳣
#define EXCEPTION_RECONNECT			0x8005	//Ԥ��ʱ����

#define NAME_LEN 					32
#define SERIALNO_LEN 				48
#define MACADDR_LEN 				6
#define MAX_ETHERNET 				2
#define PATHNAME_LEN 				128
#define PASSWD_LEN 					16
#define MAX_CHANNUM 				16
#define MAX_CHANNUM_EX				128     /*Ϊ�˼���7024T��nvs��������*/
#define MAX_ALARMOUT 				4
#define MAX_ALARMOUT_EX 			128
#define MAX_TIMESEGMENT				2
#define MAX_PRESET					128
#define MAX_DAYS 					8
#define PHONENUMBER_LEN				32
#define MAX_DISKNUM 				16
#define MAX_WINDOW 					16
#define MAX_VGA 					1
#define MAX_USERNUM 				16
#define MAX_EXCEPTIONNUM			16
#define MAX_LINK 					32
#define MAX_ALARMIN 				16
#define MAX_ALARMIN_EX 				128
#define MAX_VIDEOOUT 				2
#define MAX_NAMELEN					16		/*DVR���ص�½��*/
#define MAX_RIGHT					32		/*Ȩ��*/
#define CARDNUM_LEN 				20
#define MAX_SHELTERNUM				4
#define MAX_DECPOOLNUM				4
#define MAX_DECNUM					4
#define MAX_TRANSPARENTNUM			2
#define MAX_STRINGNUM				4
#define MAX_AUXOUT					4

/* ����ӿڶ��� */
#define NET_IF_10M_HALF				1		/*10M ethernet*/
#define NET_IF_10M_FULL				2
#define NET_IF_100M_HALF			3		/*100M ethernet*/
#define NET_IF_100M_FULL			4
#define NET_IF_AUTO					5

//�豸����		
#define DVR                         1
#define ATMDVR                      2
#define DVS                         3
#define DEC                         4       /* 6001D */
#define ENC_DEC                     5       /* 6001F */
#define DVR_HC                      6
#define DVR_HT                      7
#define DVR_HF                      8
#define DVR_HS                      9
#define DVR_HTS                     10
#define DVR_HB                      11
#define DVR_HCS		                12
#define DVS_A		                13
#define MAX_LOG_NUM                100

#define MFS_REC_TYPE_MANUAL         1 
#define MFS_REC_TYPE_SCHEDULE       2 
#define MFS_REC_TYPE_MOTION         4 
#define MFS_REC_TYPE_ALARM          8 
#define MFS_REC_TYPE_ALL            0xff

#define MAX_REC_NUM 100

/*����ʽ*/
#define NOACTION			        0x0			/*����Ӧ*/
#define WARNONMONITOR		        0x1			/*�������Ͼ���*/
#define WARNONAUDIOOUT		        0x2			/*��������*/
#define UPTOCENTER			        0x4			/*�ϴ�����*/
#define TRIGGERALARMOUT		        0x8			/*�����������*/
 
/* PTZ type */
#define YOULI			0
#define LILIN_1016		1
#define LILIN_820		2
#define PELCO_P			3
#define DM_QUICKBALL	4
#define HD600			5
#define JC4116			6
#define PELCO_DWX		7
#define PELCO_D			8
#define VCOM_VC_2000	9
#define NETSTREAMER		10
#define SAE				11
#define SAMSUNG			12
#define KALATEL_KTD_312 13
#define CELOTEX			14
#define TLPELCO_P		15
#define TL_HHX2000		16
#define BBV				17
#define RM110			18
#define KC3360S			19
#define ACES			20
#define ALSON			21
#define INV3609HD		22
#define HOWELL			23
#define TC_PELCO_P		24
#define TC_PELCO_D		25
#define AUTO_M			26
#define AUTO_H			27
#define ANTEN			28
#define CHANGLIN		29
#define DELTADOME		30
#define XYM_12			31
#define ADR8060			32
#define EVI				33
#define Demo_Speed		34
#define DM_PELCO_D		35
#define ST_832			36
#define LC_D2104		37
#define HUNTER			38
#define A01				39
#define TECHWIN			40
#define WEIHAN			41
#define LG				42
#define D_MAX			43
#define PANASONIC		44
#define KTD_348			45
#define INFINOVA		46
#define PIH717			47
#define IDOME_IVIEW_LCU 48
#define DENNARD_DOME    49
#define PHLIPS			50
#define SAMPLE			51
#define PLD             52
#define PARCO           53
#define HY				54
#define NAIJIE			55
#define CAT_KING		56
#define YH_06			57
#define SP9096X			58
#define M_PANEL			59
#define M_MV2050		60
#define SAE_QUICKBALL	61
#define RED_APPLE		62
#define NKO8G			63
#define DH_CC440		64
///////////////////////////////////////
//DVR��־
/* ���� */
//������
#define MAJOR_ALARM				0x1
//������
#define MINOR_ALARM_IN			0x1		/* �������� */
#define MINOR_ALARM_OUT			0x2		/* ������� */
#define MINOR_MOTDET_START		0x3		/* �ƶ���ⱨ����ʼ */
#define MINOR_MOTDET_STOP		0x4		/* �ƶ���ⱨ������ */
#define MINOR_HIDE_ALARM_START	0x5		/* �ڵ�������ʼ */
#define MINOR_HIDE_ALARM_STOP	0x6		/* �ڵ��������� */

/* �쳣 */
//������
#define MAJOR_EXCEPTION			0x2
//������
#define MINOR_VI_LOST			0x21	/* �źŶ�ʧ */
#define MINOR_ILLEGAL_ACCESS	0x22	/* �Ƿ����� */
#define MINOR_HD_FULL			0x23	/* Ӳ���� */
#define MINOR_HD_ERROR			0x24	/* Ӳ�̴��� */
#define MINOR_DCD_LOST			0x25	/* MODEM ���� */
#define MINOR_IP_CONFLICT		0x26	/* IP��ַ��ͻ */
#define MINOR_NET_BROKEN		0x27	/* ���߶� */
/* ���� */
//������
#define MAJOR_OPERATION			0x3
//������
#define MINOR_START_DVR			0x41	/* ���� */
#define MINOR_STOP_DVR			0x42	/* �ػ� */
#define MINOR_STOP_ABNORMAL		0x43	/* �Ƿ��ػ� */

#define MINOR_LOCAL_LOGIN		0x50	/* ���ص�½ */
#define MINOR_LOCAL_LOGOUT		0x51	/* ����ע����½ */
#define MINOR_LOCAL_CFG_PARM	0x52	/* �������ò��� */
#define MINOR_LOCAL_PLAYBYFILE	0x53	/* ���ذ��ļ��ط� */
#define MINOR_LOCAL_PLAYBYTIME	0x54	/* ���ذ�ʱ��ط� */
#define MINOR_LOCAL_START_REC	0x55	/* ���ؿ�ʼ¼�� */
#define MINOR_LOCAL_STOP_REC	0x56	/* ����ֹͣ¼�� */
#define MINOR_LOCAL_PTZCTRL		0x57	/* ������̨���� */
#define MINOR_LOCAL_PREVIEW		0x58	/* ����Ԥ�� */
#define MINOR_LOCAL_MODIFY_TIME	0x59	/* �����޸�ʱ�� */
#define MINOR_LOCAL_UPGRADE		0x5a	/* �������� */
#define MINOR_LOCAL_COPYFILE	0x5b	/* ���ر����ļ� */

#define MINOR_REMOTE_LOGIN		0x70	/* Զ�̵�¼ */
#define MINOR_REMOTE_LOGOUT		0x71	/* Զ��ע����½ */
#define MINOR_REMOTE_START_REC	0x72	/* Զ�̿�ʼ¼�� */
#define MINOR_REMOTE_STOP_REC	0x73	/* Զ��ֹͣ¼�� */
#define MINOR_START_TRANS_CHAN	0x74	/* ��ʼ͸������ */
#define MINOR_STOP_TRANS_CHAN	0x75	/* ֹͣ͸������ */
#define MINOR_REMOTE_GET_PARM	0x76	/* Զ�̻�ò��� */
#define MINOR_REMOTE_CFG_PARM	0x77	/* Զ�����ò��� */
#define MINOR_REMOTE_GET_STATUS 0x78	/* Զ�̻��״̬ */
#define MINOR_REMOTE_ARM		0x79	/* Զ�̲��� */
#define MINOR_REMOTE_DISARM		0x7a	/* Զ�̳��� */
#define MINOR_REMOTE_REBOOT		0x7b	/* Զ������ */
#define MINOR_START_VT			0x7c	/* ��ʼ�����Խ� */
#define MINOR_STOP_VT			0x7d	/* ֹͣ�����Խ� */
#define MINOR_REMOTE_UPGRADE	0x7e	/* Զ������ */
#define MINOR_REMOTE_PLAYBYFILE	0x7f	/* Զ�̰��ļ��ط� */
#define MINOR_REMOTE_PLAYBYTIME	0x80	/* Զ�̰�ʱ��ط� */
#define MINOR_REMOTE_PTZCTRL	0x81	/* Զ����̨���� */
//////////////////////
enum BUSZZERSTATE
{
    BUZZER_CLOSE,
    BUZZER_OPEN
};
////////////////////////////////////////
#define	INFO_LEN		        32
#define	INFO_SEQ		        4
//////////////////////////////
#define COMM_ALARM				0x1100	//������Ϣ
#define COMM_CONNECT			0x1200	//��������Ͽ�
////////////////////////////
#define PRESETNUM               16
////////////////////////////
//DS-6001D/F 
/*�����豸�����붨��*/
#define NET_DEC_STARTDEC		1
#define NET_DEC_STOPDEC			2
#define NET_DEC_STOPCYCLE		3
#define NET_DEC_CONTINUECYCLE	4
//////////////////////////////////////////
//
#define MAX_KEYNUM              19
/////////////////////////////////
//ptzЭ��
#define MAXPTZNUM               100
///////////////////////////////////////////////////

////////////////////////////////////////////
#define MAX_SMTP_HOST           128
#define MAX_SMTP_ADDR           256
#define MAX_DOMAIN              64
#define MAX_STRING              32
///////////////////////////////////////////

#define PT_ATMI_MAX_ALARM_NUM 	            10      //���ʮ���������
// ������
#define HB_SDVR_NOERROR 			        0       //û�д���
#define HB_SDVR_PASSWORD_ERROR 				-1      //�û����������
#define HB_SDVR_NOENOUGHPRI 				-2      //Ȩ�޲���
#define HB_SDVR_NOINIT 					    -3      //û�г�ʼ��
#define HB_SDVR_CHANNEL_ERROR 				-4      //ͨ���Ŵ���
#define HB_SDVR_OVER_MAXLINK 				-5      //���ӵ�DVR�Ŀͻ��˸����������
#define HB_SDVR_VERSIONNOMATCH				-6      //�汾��ƥ��
#define HB_SDVR_NETWORK_FAIL_CONNECT	    -7      //���ӷ�����ʧ��
#define HB_SDVR_NETWORK_SEND_ERROR			-8      //�����������ʧ��
#define HB_SDVR_NETWORK_RECV_ERROR			-9      //�ӷ�������������ʧ��
#define HB_SDVR_NETWORK_RECV_TIMEOUT	    -10     //�ӷ������������ݳ�ʱ
#define HB_SDVR_NETWORK_ERRORDATA			-11     //���͵���������
#define HB_SDVR_ORDER_ERROR				    -12     //���ô������
#define HB_SDVR_OPERNOPERMIT				-13     //�޴�Ȩ��
#define HB_SDVR_COMMANDTIMEOUT				-14     //DVR����ִ�г�ʱ
#define HB_SDVR_ERRORSERIALPORT				-15     //���ںŴ���
#define HB_SDVR_ERRORALARMPORT				-16     //�����˿ڴ���
#define HB_SDVR_PARAMETER_ERROR 			-17     //��������
#define HB_SDVR_CHAN_EXCEPTION				-18	    //������ͨ�����ڴ���״̬
#define HB_SDVR_NODISK					    -19	    //û��Ӳ��
#define HB_SDVR_ERRORDISKNUM				-20	    //Ӳ�̺Ŵ���
#define HB_SDVR_DISK_FULL				    -21	    //������Ӳ����
#define HB_SDVR_DISK_ERROR				    -22	    //������Ӳ�̳���
#define HB_SDVR_NOSUPPORT				    -23	    //��������֧��
#define HB_SDVR_BUSY					    -24	    //������æ
#define HB_SDVR_MODIFY_FAIL				    -25	    //�������޸Ĳ��ɹ�
#define HB_SDVR_PASSWORD_FORMAT_ERROR	   	-26	    //���������ʽ����ȷ
#define HB_SDVR_DISK_FORMATING				-27	    //Ӳ�����ڸ�ʽ����������������
#define HB_SDVR_DVRNORESOURCE				-28	    //DVR��Դ����
#define	HB_SDVR_DVROPRATEFAILED				-29     //DVR����ʧ��
#define HB_SDVR_OPENHOSTSOUND_FAIL 			-30     //��PC����ʧ��
#define HB_SDVR_DVRVOICEOPENED 				-31     //�����������Խ���ռ��
#define	HB_SDVR_TIMEINPUTERROR				-32     //ʱ�����벻��ȷ
#define	HB_SDVR_NOSPECFILE				    -33     //�ط�ʱ������û��ָ�����ļ�
#define HB_SDVR_CREATEFILE_ERROR			-34	    //�����ļ�����
#define	HB_SDVR_FILEOPENFAIL				-35     //���ļ�����
#define	HB_SDVR_OPERNOTFINISH				-36     //�ϴεĲ�����û�����
#define	HB_SDVR_GETPLAYTIMEFAIL				-37     //��ȡ��ǰ���ŵ�ʱ�����
#define	HB_SDVR_PLAYFAIL				    -38     //���ų���
#define HB_SDVR_FILEFORMAT_ERROR			-39     //�ļ���ʽ����ȷ
#define HB_SDVR_DIR_ERROR				    -40	    //·������
#define HB_SDVR_ALLOC_RESOUCE_ERROR			-41     //��Դ�������
#define HB_SDVR_AUDIO_MODE_ERROR			-42	    //����ģʽ����
#define HB_SDVR_NOENOUGH_BUF				-43	    //������̫С
#define HB_SDVR_CREATESOCKET_ERROR		 	-44	    //����SOCKET����
#define HB_SDVR_SETSOCKET_ERROR				-45	    //����SOCKET����
#define HB_SDVR_MAX_NUM					    -46	    //�����ﵽ���
#define HB_SDVR_USERNOTEXIST				-47	    //�û�������
#define HB_SDVR_WRITEFLASHERROR				-48     //дFLASH����
#define HB_SDVR_UPGRADEFAIL				    -49     //DVR����ʧ��
#define HB_SDVR_CARDHAVEINIT				-50     //���뿨�Ѿ���ʼ����
#define HB_SDVR_PLAYERFAILED			    -51	    //�������д���
#define HB_SDVR_MAX_USERNUM				    -52     //�û����ﵽ���
#define HB_SDVR_GETLOCALIPANDMACFAIL	    -53     //��ÿͻ��˵�IP��ַ�������ַʧ��
#define HB_SDVR_NOENCODEING				    -54	    //��ͨ��û�б���
#define HB_SDVR_IPMISMATCH				    -55	    //IP��ַ��ƥ��
#define HB_SDVR_MACMISMATCH				    -56	    //MAC��ַ��ƥ��
#define HB_SDVR_UPGRADELANGMISMATCH			-57	    //�����ļ����Բ�ƥ��
#define HB_SDVR_USERISALIVE				    -58	    //�û��ѵ�½ 
#define HB_SDVR_UNKNOWNERROR				-59	    //δ֪����
#define HB_SDVR_KEYVERIFYFAIL               -60     // ��Կ��֤ʧ��
#define HB_SDVR_IPERR			        	-101    //IP��ַ��ƥ��
#define HB_SDVR_MACERR			    		-102    //MAC��ַ��ƥ��
#define HB_SDVR_PSWERR			    		-103    //�������
#define HB_SDVR_USERERR			    		-104    //�û�������
#define HB_SDVR_USERISFULL			    	-105    //��¼�û�����
#define NO_PERMISSION					    0xf0    //�û�û��Ȩ��

//�����ļ�����־��������ֵ
#define HB_SDVR_FILE_SUCCESS				1000	//����ļ���Ϣ
#define HB_SDVR_FILE_NOFIND				    1001	//û���ļ�
#define HB_SDVR_ISFINDING				    1002	//���ڲ����ļ�
#define	HB_SDVR_NOMOREFILE				    1003	//�����ļ�ʱû�и�����ļ�
#define	HB_SDVR_FILE_EXCEPTION				1004	//�����ļ�ʱ�쳣
// ��̨��������

// �طſ�������

// ������������

#pragma pack(1)
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
// �������ýṹ�嶨��
//Ϊ���������Ҫ��ϸ֡��Ϣ���
typedef struct
{
    int frame_type;			  //֡���� 1��I֡ 2��P֡ 8����Ƶ֡
    struct {
        short	year;
        short	month;
        short	day;
        short	hour;
        short	minute;
        short	second;
        short	milli;	
        short	res1;  //����
    }ets;                       //ʱ��
    unsigned int	frame_num;  //֡��
    unsigned int	width;	    //ͼ����
    unsigned int	height;	    //ͼ��߶�
    short			frame_rate; //֡��
    short			reserve1;	//����
    int				reserve2;	//����
}FRAMEINFO,*PFRAMEINFO;

//ͨ������
typedef struct
{
	DWORD	dwHandleType;				//��λ   2-��������   	5-���������	 	 
	WORD	wAlarmOut;					//�����������ͨ�� ��λ��Ӧͨ��
}HB_SDVR_HANDLEEXCEPTION;
typedef struct
{
	DWORD	dwHandleType;				//��λ 2-�������� 5-��������� 6-�ʼ��ϴ� 7-��Ƶ����
	BYTE	wAlarmOut[MAX_CHANNUM_EX];	//�����������ͨ�� ��λ��Ӧͨ��
}HB_SDVR_HANDLEEXCEPTION_EX;

typedef  struct  
{
	BYTE  wVodLost[MAX_CHANNUM_EX];     //��Ӧͨ�� 0����Ƶ��ʧ  1������Ƶ
	DWORD dwres;						//����
}HB_SDVR_VODLOST,*LPHB_SDVR_VODLOST;

//�ϴ�������Ϣ
typedef struct{
    BYTE byAlarm[MAX_CHANNUM];	//̽ͷ����
    BYTE byVlost[MAX_CHANNUM];	//�źŶ�ʧ
    BYTE byMotion[MAX_CHANNUM]; //�ƶ�����
    BYTE byHide[MAX_CHANNUM];	//�ڵ�����
    BYTE byDisk[MAX_DISKNUM];   //Ӳ��״̬
}HB_SDVR_ALARMINFO,*LPHB_SDVR_ALARMINFO;

typedef struct	{
    BYTE byAlarm[MAX_CHANNUM_EX];					//̽ͷ����  0-�ޱ���  1-�б���
    BYTE byVlost[MAX_CHANNUM_EX];					//��Ƶ��ʧ  ...
    BYTE byMotion[MAX_CHANNUM_EX];					//�ƶ�����	...
    BYTE byHide[MAX_CHANNUM_EX];					//�ڵ�����	...		
    BYTE byDisk[MAX_DISKNUM];						//Ӳ��״̬	
}HB_SDVR_ALARMINFO_EX,*LPHB_SDVR_ALARMINFO_EX;

typedef struct{
	DWORD dwYear;		//��
	DWORD dwMonth;		//��
	DWORD dwDay;		//��
	DWORD dwHour;		//ʱ
	DWORD dwMinute;		//��
	DWORD dwSecond;		//��
}HB_SDVR_TIME,*LPHB_SDVR_TIME;

typedef struct{
	BYTE byEnable;	    //����
    BYTE byStartHour;   //��ʼʱ��
	BYTE byStartMin;
    BYTE byStopHour;    //����ʱ��
	BYTE byStopMin;
}HB_SDVR_SCHEDTIME,*LPHB_SDVR_SCHEDTIME;

//  ����
typedef struct{
	BYTE Output[MAX_ALARMOUT];
}HB_SDVR_ALARMOUTSTATUS,*LPHB_SDVR_ALARMOUTSTATUS;

//ͼƬ���� ����
typedef struct
{
	WORD	wPicSize;				/* 0=CIF, 1=QCIF, 2=D1 */
	WORD	wPicQuality;			/* ͼƬ����ϵ�� 0-��� 1-�Ϻ� 2-һ�� */
}HB_SDVR_JPEGPARA, *LPHB_SDVR_JPEGPARA;

typedef struct  {
	BYTE sSerialNumber[SERIALNO_LEN];		//����
	BYTE byAlarmInPortNum;					//DVR�����������
	BYTE byAlarmOutPortNum;					//DVR�����������
	BYTE byDiskNum;		 					//DVR Ӳ�̸���
	BYTE byProtocol;						//�����Ͳ�Ʒ��ֵ��Ϊ0x20����Э�������
	BYTE byChanNum;							//DVR ͨ������
	BYTE byStartChan;						//����
	BYTE sDvrName[NAME_LEN];				//������
	BYTE sChanName[MAX_CHANNUM][NAME_LEN];  //ͨ������
}HB_SDVR_DEVICEINFO, *LPHB_SDVR_DEVICEINFO;

//for 7024 or nvs 100325
typedef struct  {
	BYTE sSerialNumber[SERIALNO_LEN];		//���кţ������˱��뷵�أ���ǰ���������ಹ��
	BYTE byAlarmInPortNum;					//DVR�����������
	BYTE byAlarmOutPortNum;					//DVR�����������
	BYTE byDiskNum;		 					//�洢�豸������Ӳ��/SD������
	BYTE byProtocol;						//Э��汾 0x20
	BYTE byChanNum;							//DVR ͨ������
	BYTE byEncodeType;						//���������ʽ��1ΪANSI�ַ��������Ĳ���GB2312���룻2ΪUTF8
	BYTE sDvrName[NAME_LEN];				//�����������ԡ�\0������,�����������ʽ�й�
	BYTE sChanName[MAX_CHANNUM_EX][NAME_LEN];  //ͨ�����ƣ����ԡ�\0������,�����������ʽ�й�
}HB_SDVR_DEVICEINFO_EX, *LPHB_SDVR_DEVICEINFO_EX;
//end add

//�豸Ӳ����Ϣ
typedef struct{
    DWORD dwSize;
    BYTE sDVRName[NAME_LEN];				//DVR����
    DWORD dwDVRID;							//����
    DWORD dwRecycleRecord;					//����
    //���²��ܸ���
    BYTE sSerialNumber[SERIALNO_LEN];		//����
    BYTE sSoftwareVersion[16];				//����汾��
    BYTE sSoftwareBuildDate[16];			//�����������
    DWORD dwDSPSoftwareVersion;				//DSP����汾
    //	BYTE sDSPSoftwareBuildDate[16];		// DSP�����������
    BYTE sPanelVersion[16];					// ǰ���汾
    BYTE sHardwareVersion[16];				//����
    BYTE byAlarmInPortNum;					//DVR�����������
    BYTE byAlarmOutPortNum;					//DVR�����������
    BYTE byRS232Num;						//����
    BYTE byRS485Num;						//����
    BYTE byNetworkPortNum;					//����
    BYTE byDiskCtrlNum;						//����
    BYTE byDiskNum;							//DVR Ӳ�̸���
    BYTE byDVRType;							//DVR����, 1:DVR 2:ATM DVR 3:DVS ����ʹ��HB_SDVR_GetDeviceType
    BYTE byChanNum;							//DVR ͨ������
    BYTE byStartChan;						//����
    BYTE byDecordChans;						//����
    BYTE byVGANum;							//����
    BYTE byUSBNum;							//����
    char reservedData[3];					//���� 
}HB_SDVR_DEVICECFG,*LPHB_SDVR_DEVICECFG;

//�豸������Ϣ
typedef struct {
    char sDVRIP[16];					//DVR IP��ַ
    char sDVRIPMask[16];				//DVR IP��ַ����
    DWORD dwNetInterface;				//����ӿ� 1-10MBase-T 2-10MBase-Tȫ˫�� 3-100MBase-TX 4-100Mȫ˫�� 5-10M/100M����Ӧ 6-100M��˫�� 7-1000M��˫��
                                        // 8-1000Mȫ˫�� 9-100M/1000M����Ӧ 10-10000M��˫�� 11-10000Mȫ˫�� 12-100M/1000M/10000M����Ӧ(��չ)
    WORD wDVRPort;						//�˿ں�
    BYTE byMACAddr[MACADDR_LEN];		//�������������ַ
}HB_SDVR_ETHERNET;

//�������ýṹ
typedef struct{
    DWORD dwSize;
    HB_SDVR_ETHERNET struEtherNet[MAX_ETHERNET];		/* ��̫���� */
    char sManageHostIP[16];				//Զ�̹���������ַ
    WORD wManageHostPort;				//����
    char sDNSIP[16];					//DNS��������ַ  
    char sMultiCastIP[16];				//�ಥ���ַ
    char sGatewayIP[16];       			//���ص�ַ 
    char sNFSIP[16];					//����	
    BYTE sNFSDirectory[PATHNAME_LEN];	//����
    DWORD dwPPPOE;						//0-������,1-����
    BYTE sPPPoEUser[NAME_LEN];			//PPPoE�û���
    char sPPPoEPassword[PASSWD_LEN];	// PPPoE����
    char sPPPoEIP[16];					//PPPoE IP��ַ 
    WORD wHttpPort;						//HTTP�˿ں�
}HB_SDVR_NETCFG,*LPHB_SDVR_NETCFG;

typedef struct{
	LONG lChannel;						//ͨ����
	LONG lLinkMode;						//���λ(31)Ϊ0��ʾ��������Ϊ1��ʾ��������0��30λ��ʾ�������ӷ�ʽ: 0��TCP��ʽ,1��UDP��ʽ,2���ಥ��ʽ 
	HWND hPlayWnd;						//���Ŵ��ڵľ��,ΪNULL��ʾ������ͼ��
	char sMultiCastIP[16];				//����
}HB_SDVR_CLIENTINFO,*LPHB_SDVR_CLIENTINFO;

typedef struct{
    LONG lChannel;						//ͨ����
    LONG lLinkMode;						//���λ(31)Ϊ0��ʾ��������Ϊ1��ʾ��������0��30λ��ʾ�������ӷ�ʽ: 0��TCP��ʽ,1��UDP��ʽ,2���ಥ��ʽ 
    HWND hPlayWnd;						//���Ŵ��ڵľ��,ΪNULL��ʾ������ͼ��
    char sMultiCastIP[16];				//����
    DWORD msgid;
}HB_SDVR_CLIENTINFO_EX,*LPHB_SDVR_CLIENTINFO_EX;

typedef struct {
	DWORD	dwBrightValue;		//����  1-127
	DWORD	dwContrastValue;	//�Աȶ�1-127
	DWORD	dwSaturationValue;	//���Ͷ�1-127
	DWORD	dwHueValue;			//ɫ��	1-127
}HB_SDVR_VIDEOPARAM;

typedef struct {
	WORD wStartTime;			//��8λ��ʾСʱ ��8λ��ʾ����
	WORD wEndTime;				//��8λ��ʾСʱ ��8λ��ʾ����
	HB_SDVR_VIDEOPARAM VideoParam;
}HB_SDVR_SCHEDULE_VIDEOPARAM;

typedef struct  {
	BYTE	byChannel;			//ͨ����
	char reservedData[3];
	HB_SDVR_SCHEDULE_VIDEOPARAM Schedule_VideoParam[2]; //һ�����2��ʱ���
	HB_SDVR_VIDEOPARAM Default_VideoParam;				//����ʱ����ھ�ʹ��Ĭ��
}HB_SDVR_VIDEOEFFECT,*LPHB_SDVR_VIDEOEFFECT; 

typedef struct {
	BYTE Channel[MAX_CHANNUM_EX];
}HB_SDVR_REMOTERECORDCHAN,*LPHB_SDVR_REMOTERECORDCHAN;

typedef  enum
{
    NET_DEVTYPE_7000T = 0, 
    NET_DEVTYPE_8000T,
    NET_DEVTYPE_8200T,
    NET_DEVTYPE_8000ATM,
    NET_DEVTYPE_8600T,		//8600T
    NET_DEVTYPE_6200T,
    NET_DEVTYPE_8004AH,
    NET_DEVTYPE_8004AI,
    NET_DEVTYPE_7000H,
    NET_DEVTYPE_7200H,
    NET_DEVTYPE_7000M = 12,
    NET_DEVTYPE_8000M,
    NET_DEVTYPE_8200M,
    NET_DEVTYPE_7000L,
    NET_DEVTYPE_2201TL = 16,
    NET_DEVTYPE_2600T,
    NET_DEVTYPE_2600TB,		//����ͳ�����ܷ�����
    NET_DEVTYPE_2600TC,		//����ʶ�����ܷ�����
    NET_DEVTYPE_9300,
    NET_DEVTYPE_9400,

    HB9824N16H = 1000,
    HB9832N16H,
    HB9904,
    HB9908,
    HB9912,
    HB9916,
    HB9932,
    HB7904,
    HB7908,
    HB7912,
    HB7916,
}HB_SDVR_TYPE_E;

typedef  enum
{
    NET_SIZE_8M = 0,		// 8M
    NET_SIZE_16M ,			// 16M
    NET_SIZE_32M ,			// 32M
    NET_SIZE_64M ,			// 64M
    NET_SIZE_128M ,			// 128M
    NET_SIZE_256M ,			// 256M
    NET_SIZE_512M ,			// 512M
    NET_SIZE_1024M,		    // 1024M
}HB_SDVR_MEMSIZE_E;

typedef struct {
	ULONG   dvrtype;        // 7004  8004  2004�����ͺ�
	WORD    dwDevice_type;  // HB_SDVR_TYPE_E
    WORD    memory_size;    // HB_SDVR_MEMSIZE_E
    DWORD   dwReserve;
}HB_SDVR_INFO,*LPHB_SDVR_INFO; 

// �ƶ�������򣬷�22*18��С���
#define     MOTION_SCOPE_WIDTH      22
#define     MOTION_SCOPE_HIGHT      18
//ͨ��ͼ��ṹ
//�ƶ����
typedef struct{
	BYTE byMotionScope[18][22];			//�������,����22*18��С���,Ϊ1��ʾ�ú�����ƶ��������,0-��ʾ���� 
	BYTE byMotionSensitive;				//�ƶ����������, 0 - 5,Խ��Խ����,0xff�ر�*/
	BYTE byEnableHandleMotion;			// �Ƿ����ƶ���� */ 
	HB_SDVR_HANDLEEXCEPTION struMotionHandleType;	// ����ʽ */
	HB_SDVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����ʱ��
	BYTE byRelRecordChan[MAX_CHANNUM]; //����������¼��ͨ��,Ϊ1��ʾ������ͨ��	
}HB_SDVR_MOTION,*LPHB_SDVR_MOTION;

//for 7024 or nvs 100329
typedef struct{
	BYTE byMotionScope[18][22];			//�������,����22*18��С���,Ϊ1��ʾ�ú�����ƶ��������,0-��ʾ���� 
	BYTE byMotionSensitive;				//�ƶ����������, 0 - 5,Խ��Խ����,0xff�ر�*/
	BYTE byEnableHandleMotion;			// �Ƿ����ƶ���� */ 
	HB_SDVR_HANDLEEXCEPTION_EX struMotionHandleType;	// ����ʽ */
	HB_SDVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����ʱ��
	BYTE byRelRecordChan[MAX_CHANNUM_EX]; //����������¼��ͨ��,Ϊ1��ʾ������ͨ��	
}HB_SDVR_MOTION_EX,*LPHB_SDVR_MOTION_EX;
//end add

//�ڵ���������Ϊ 
typedef struct{
	DWORD dwEnableHideAlarm;			//����
	WORD wHideAlarmAreaTopLeftX;		//����
	WORD wHideAlarmAreaTopLeftY;		//����
	WORD wHideAlarmAreaWidth;			//����
	WORD wHideAlarmAreaHeight;			//����
	HB_SDVR_HANDLEEXCEPTION struHideAlarmHandleType;	//����
	HB_SDVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����
}HB_SDVR_HIDEALARM,*LPHB_SDVR_HIDEALARM;

//�ڵ���������Ϊ 
typedef struct{
	DWORD dwEnableHideAlarm;			//����
	WORD wHideAlarmAreaTopLeftX;		//����
	WORD wHideAlarmAreaTopLeftY;		//����
	WORD wHideAlarmAreaWidth;			//����
	WORD wHideAlarmAreaHeight;			//����
	HB_SDVR_HANDLEEXCEPTION_EX struHideAlarmHandleType;	//����
	HB_SDVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����
}HB_SDVR_HIDEALARM_EX,*LPHB_SDVR_HIDEALARM_EX;

//�źŶ�ʧ����
typedef struct{
	BYTE byEnableHandleVILost;			// �Ƿ����źŶ�ʧ����  
	HB_SDVR_HANDLEEXCEPTION strVILostHandleType;	//����ʽ 	
	HB_SDVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����
}HB_SDVR_VILOST,*LPHB_SDVR_VILOST;

typedef struct{
	BYTE byEnableHandleVILost;			// �Ƿ����źŶ�ʧ����  
	HB_SDVR_HANDLEEXCEPTION_EX strVILostHandleType;	//����ʽ 	
	HB_SDVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����
}HB_SDVR_VILOST_EX,*LPHB_SDVR_VILOST_EX;

typedef struct{
	WORD wHideAreaTopLeftX;				// �ڸ������x����  
	WORD wHideAreaTopLeftY;				// �ڸ������y���� 
	WORD wHideAreaWidth;				// �ڸ�����Ŀ�  
	WORD wHideAreaHeight;				//�ڸ�����ĸ� 
}HB_SDVR_SHELTER,*LPHB_SDVR_SHELTER;

typedef struct
{	
	DWORD dwSize;
	BYTE sChanName[NAME_LEN];		// ͨ����
	DWORD dwVideoFormat;			// ����
	BYTE byBrightness;  			// ����
	BYTE byContrast;    			// ����
	BYTE bySaturation;  			// ����
	BYTE byHue;    					// ����	
	//��ʾͨ����
	DWORD dwShowChanName;			// ���� 
	WORD wShowNameTopLeftX;			// ͨ��������ʾλ�õ�x����  
	WORD wShowNameTopLeftY;			// ͨ��������ʾλ�õ�y����  
 	HB_SDVR_VILOST struVILost;		// �źŶ�ʧ���� 
 	HB_SDVR_MOTION struMotion;	    // �ƶ����
 	HB_SDVR_HIDEALARM struHideAlarm;// ����
 	DWORD dwEnableHide;				// �Ƿ������ڸ� ,0-��,1-��
	HB_SDVR_SHELTER struShelter[MAX_SHELTERNUM]; 
 	DWORD dwShowOsd;				// ����
	WORD wOSDTopLeftX;				// ����
	WORD wOSDTopLeftY;				// ����
	BYTE byOSDType;					// ����
 	BYTE byDispWeek;				/* �Ƿ���ʾ���� */	
	BYTE byOSDAttrib;				//ͨ���� 1-��͸�� 2-͸��
}HB_SDVR_PICCFG_EX,*LPHB_SDVR_PICCFG_EX;

//for 7024 or nvs 100329
typedef struct
{
	DWORD dwSize;
	BYTE sChanName[NAME_LEN];		// ͨ����
	DWORD dwVideoFormat;			// ����
	BYTE byBrightness;  			// ����
	BYTE byContrast;    			// ����
	BYTE bySaturation;  			// ����
	BYTE byHue;    					// ����	
	//��ʾͨ����
	DWORD dwShowChanName;			// ���� 
	WORD wShowNameTopLeftX;			// ͨ��������ʾλ�õ�x����  
	WORD wShowNameTopLeftY;			// ͨ��������ʾλ�õ�y����  
	HB_SDVR_VILOST_EX struVILost;		// �źŶ�ʧ����
	HB_SDVR_MOTION_EX struMotion;	    // �ƶ����
	HB_SDVR_HIDEALARM_EX struHideAlarm;// ����
	DWORD dwEnableHide;				// �Ƿ������ڸ� ,0-��,1-��
	HB_SDVR_SHELTER struShelter[MAX_SHELTERNUM]; 
	DWORD dwShowOsd;				// ����
	WORD wOSDTopLeftX;				// ����
	WORD wOSDTopLeftY;				// ����
	BYTE byOSDType;					// ��ʽ�����ԣ����λΪ0��ʾ�������ӣ�Ϊ1��ʾǰ�˵��ӣ�Ĭ��Ϊ0����Ϊ0x80ʱ��ʾ��osd��Ϊǰ�˵���
	BYTE byDispWeek;				/* �Ƿ���ʾ���� */	
	BYTE byOSDAttrib;				//ͨ���� 1-��͸�� 2-͸��	
}HB_SDVR_PICCFG_EX_EX,*LPHB_SDVR_PICCFG_EX_EX;
//end add

//����ֻ��һ���ڵ�����ͻ��˰汾 20100504
typedef struct
{
	DWORD dwSize;
	BYTE sChanName[NAME_LEN];		// ͨ����
	DWORD dwVideoFormat;			// ����
	BYTE byBrightness;  			// ����
	BYTE byContrast;    			// ����
	BYTE bySaturation;  			// ����
	BYTE byHue;    					// ����	
	//��ʾͨ����
	DWORD dwShowChanName;			// ���� 
	WORD wShowNameTopLeftX;			// ͨ��������ʾλ�õ�x����  
	WORD wShowNameTopLeftY;			// ͨ��������ʾλ�õ�y����  
	HB_SDVR_VILOST struVILost;		// �źŶ�ʧ����
	HB_SDVR_MOTION struMotion;	    // �ƶ����
	HB_SDVR_HIDEALARM struHideAlarm;// ����
	DWORD dwEnableHide;				// �Ƿ������ڸ� ,0-��,1-��
	HB_SDVR_SHELTER struShelter[1]; 
	DWORD dwShowOsd;				// ����
	WORD wOSDTopLeftX;				// ����
	WORD wOSDTopLeftY;				// ����
	BYTE byOSDType;					// ����
	BYTE byDispWeek;				/* �Ƿ���ʾ���� */	
	BYTE byOSDAttrib;				//ͨ���� 1-��͸�� 2-͸��	
}HB_SDVR_PICCFG_EX_TMP,*LPHB_SDVR_PICCFG_EX_TMP;

//����ѹ������
//ѹ������
typedef struct{
	BYTE byStreamType;				//��������0-����Ƶ,1-����Ƶ
	BYTE byResolution;  			//�ֱ���	0-CIF 1-HD1, 2-D1��Э���:���� 3-QCIF�� 4-720p��5-1080p��6-960H��7-Q960H��8-QQ960H
	BYTE byBitrateType;				//��������	0:�����ʣ�1:������ 2��������
	BYTE  byPicQuality;				//ͼ������	1-��� 2-�κ� 3-�Ϻ� 4-һ��5-�ϲ� 6-��	
    DWORD dwVideoBitrate; 			//Э��һ:��Ƶ���� 0-100K 1-128K��2-256K��3-512K��4-1M��5-2M��6-3M��7-4M��8-6M��9-8M��10-12M ,11-�Զ���
                                    //Э���:��Ƶ���� 0-100K��1-128K��2-256K��3-512K��4-1M��5-1.5M��6-2M��7-3M��8-4M ����:����ֵ(kbps)��Ч��Χ 30~2^32�����ڵ���32����KΪ��λ
	DWORD dwVideoFrameRate;			//֡��		2 �� 25
}HB_SDVR_COMPRESSION_INFO,*LPHB_SDVR_COMPRESSION_INFO;

typedef struct{
	DWORD dwSize;
	BYTE byRecordType;							//0x0:�ֶ�¼��0x1:��ʱ¼��0x2:�ƶ���⣬0x3:������0x0f:��������
	HB_SDVR_COMPRESSION_INFO struRecordPara;	//¼��������������
	HB_SDVR_COMPRESSION_INFO struNetPara;		//����������������
}HB_SDVR_COMPRESSIONCFG,*LPHB_SDVR_COMPRESSIONCFG;
 
//¼�����
typedef struct{
	HB_SDVR_SCHEDTIME struRecordTime;
	BYTE byRecordType;			//����
	char reservedData[3];		//����
}HB_SDVR_RECORDSCHED,*LPHB_SDVR_RECORDSCHED;

typedef struct {
	WORD wAllDayRecord;			//����
	BYTE byRecordType;			//����
	char reservedData;			//����
}HB_SDVR_RECORDDAY;

typedef struct {
	DWORD dwSize;
	DWORD dwRecord;					//�Ƿ�¼�� 0-�� 1-�� 
	HB_SDVR_RECORDDAY struRecAllDay[MAX_DAYS];//����
	HB_SDVR_RECORDSCHED struRecordSched[MAX_DAYS][MAX_TIMESEGMENT]; //ʱ���
	DWORD dwPreRecordTime;						//����
}HB_SDVR_RECORD,*LPHB_SDVR_RECORD;

//������
typedef struct{
	DWORD dwSize;
	DWORD dwBaudRate;				// ������(bps)
        // Э��һ��50 75 110 150 300 600 1200 2400 4800 9600 19200 38400 57600 76800 115.2k 
        // Э�����0-default,1-2400,2-4800,3-9600,4-19200,5-38400�� �Զ���ȡֵ��Χ[300��115200]
	BYTE byDataBit;					// ����λ 5 6 7 8
	BYTE byStopBit;					// ֹͣλ 1 2 
	BYTE byParity;                  // У��λ (0-NONE,1-ODD,2-EVEN,3-SPACE)
	BYTE byFlowcontrol;				// ����(0-��,1-Xon/Xoff,2-Ӳ��)
	WORD wDecoderType;              // ��̨Э��ֵ�������ͨ��HB_SDVR_GetPTZType��ȡ���б� 
 	    //	 0-unknow 1-RV800  2-TOTA120 3-S1601 4-CLT-168 5-TD-500  6-V1200 7-ZION 8-ANT 9-CBC 10-CS850A 
	    //	 11-CONCORD 12-HD600 13-SAMSUNG 14-YAAN 15-PIH 16-MG-CS160 17-WISDOM 18-PELCOD1 19-PELCOD2 20-PELCOD3 
	    //	 21-PELCOD4 22-PELCOP1 23-PELCOP2 24-PELCOP3 25-Philips 26-NEOCAM  27-ZHCD 28-DongTian 29-PELCOD5 30-PELCOD6
	    //	 31-Emerson 32-TOTA160 33-PELCOP5
	WORD wDecoderAddress;				// ��������ַ:0 - 255 
	BYTE bySetPreset[MAX_PRESET];		// ����
	BYTE bySetCruise[MAX_PRESET];		// ����
	BYTE bySetTrack[MAX_PRESET];		// ����
}HB_SDVR_DECODERCFG,*LPHB_SDVR_DECODERCFG;

//RS232 
typedef struct{
	char sRemoteIP[16];            //Զ��IP��ַ
	char sLocalIP[16];             //����IP��ַ
	char sLocalIPMask[16];         //����IP��ַ����
	BYTE sUsername[NAME_LEN];		/* �û��� */
	BYTE sPassword[PASSWD_LEN];		/* ���� */
	BYTE byPPPMode;					//PPPģʽ, 0��������1������	
	BYTE byRedial;					//�Ƿ�ز� ��0-��,1-��
	BYTE byRedialMode;				//�ز�ģʽ,0-�ɲ�����ָ��,1-Ԥ�ûز�����
	BYTE byDataEncrypt;				//���ݼ���,0-��,1-��
	DWORD dwMTU;					//MTU
	char sTelephoneNumber[PHONENUMBER_LEN];	//�绰����
}HB_SDVR_PPPCFG,*LPHB_SDVR_PPPCFG;

typedef struct{
	DWORD dwSize;
	DWORD dwBaudRate;				// ������(bps)  
	BYTE byDataBit;					// �����м�λ 5��8 
	BYTE byStopBit;					// ֹͣλ 1-2 
	BYTE byParity;					// У�� 0����У�飬1����У�飬2��żУ��;
	BYTE byFlowcontrol;				// 0���ޣ�1��������,2-Ӳ����
	DWORD dwWorkMode;				// ����
	HB_SDVR_PPPCFG struPPPConfig;   // ����
}HB_SDVR_RS232CFG,*LPHB_SDVR_RS232CFG;

//��������
typedef struct{
	DWORD dwSize;
	BYTE sAlarmInName[NAME_LEN];		// ����ͨ����
	BYTE byAlarmType;					// ����
	BYTE byAlarmInHandle;				// �Ƿ��� 0-1
	HB_SDVR_HANDLEEXCEPTION struAlarmHandleType;	//����ʽ 
	HB_SDVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����ʱ��
	BYTE byRelRecordChan[MAX_CHANNUM];		//����������¼��ͨ��,Ϊ1��ʾ������ͨ��
	BYTE byEnablePreset[MAX_CHANNUM];		// �Ƿ����Ԥ�õ� ����byEnablePreset[0]���ж�;
	BYTE byPresetNo[MAX_CHANNUM];			// ���õ���̨Ԥ�õ����,һ������������Ե��ö��ͨ������̨Ԥ�õ�, 0xff��ʾ������Ԥ�õ� 
	BYTE byEnableCruise[MAX_CHANNUM];		// ����
	BYTE byCruiseNo[MAX_CHANNUM];			// ����
	BYTE byEnablePtzTrack[MAX_CHANNUM];		// ���� 
	BYTE byPTZTrack[MAX_CHANNUM];			// ����
	BYTE byRecordTm;						// ����¼��ʱ�� 1-99�� 
}HB_SDVR_ALARMINCFG,*LPHB_SDVR_ALARMINCFG;

//for 7024 or nvs 100325
typedef struct{
	DWORD dwSize;
	BYTE sAlarmInName[NAME_LEN];		// ����ͨ����
	BYTE byAlarmType;					// ����
	BYTE byAlarmInHandle;				// �Ƿ��� 0-1
	HB_SDVR_HANDLEEXCEPTION_EX struAlarmHandleType;	//����ʽ 
	HB_SDVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//����ʱ��
	BYTE byRelRecordChan[MAX_CHANNUM_EX];		//����������¼��ͨ��,Ϊ1��ʾ������ͨ��
	BYTE byEnablePreset[MAX_CHANNUM_EX];		// �Ƿ����Ԥ�õ� ����byEnablePreset[0]���ж�;
	BYTE byPresetNo[MAX_CHANNUM_EX];			// ���õ���̨Ԥ�õ����,һ������������Ե��ö��ͨ������̨Ԥ�õ�, 0xff��ʾ������Ԥ�õ� 
	BYTE byEnableCruise[MAX_CHANNUM_EX];		// ����
	BYTE byCruiseNo[MAX_CHANNUM_EX];			// ����
	BYTE byEnablePtzTrack[MAX_CHANNUM_EX];		// ���� 
	BYTE byPTZTrack[MAX_CHANNUM_EX];			// ����
	BYTE byRecordTm;						// ����¼��ʱ�� 1-99�� 
}HB_SDVR_ALARMINCFG_EX,*LPHB_SDVR_ALARMINCFG_EX;
//end add

//DVR�������
typedef struct{
	DWORD dwSize;
	BYTE sAlarmOutName[NAME_LEN];			// ���� 
	DWORD dwAlarmOutDelay;					// �������ʱ�� ��λ��
	BYTE byEnSchedule;						// �����������ʱ�伤�� 0-���� 1-���� 
	HB_SDVR_SCHEDTIME struAlarmOutTime[MAX_DAYS][MAX_TIMESEGMENT];// �����������ʱ��� 			
}HB_SDVR_ALARMOUTCFG,*LPHB_SDVR_ALARMOUTCFG;
 
//�û�Ȩ��
typedef struct{
	BYTE sUserName[NAME_LEN];		/* �û��� */
	BYTE sPassword[PASSWD_LEN];		/* ���� */
	DWORD dwLocalRight[MAX_RIGHT];	/* ����Ȩ�� */
 	DWORD dwRemoteRight[MAX_RIGHT];	/* Զ��Ȩ�� */
	/*���� 0: ͨ��Ȩ��*/
	/*���� 1: ��ʾ����*/
	/*���� 2: ¼�����*/
	/*���� 3: ��ʱ¼��*/
	/*���� 4: �ƶ�¼��*/
	/*���� 5: ����¼��*/
	/*���� 6: �������*/
	/*���� 7: ��̨����*/
	/*���� 8: �洢����*/
	/*���� 9: ϵͳ����*/
	/*���� 10: ��Ϣ��ѯ*/
	/*���� 11: �ֶ�¼��*/
	/*���� 12: �ط�*/
	/*���� 13: ����*/
	/*���� 14: ��Ƶ����*/
	/*���� 15: �������*/
	/*���� 16: Զ��Ԥ��*/
	char sUserIP[16];					/* �û�IP��ַ(Ϊ0ʱ��ʾ�����κε�ַ) */	
	BYTE byMACAddr[MACADDR_LEN];		/* �����ַ */	
}HB_SDVR_USER_INFO,*LPHB_SDVR_USER_INFO;

typedef struct{
	BYTE sUserName[NAME_LEN];		    /* �û��� */
	BYTE sPassword[PASSWD_LEN];		    /* ���� */
	BYTE dwLocalRight[MAX_RIGHT];	    //����Ȩ�� 1.����0δʹ�ã�2.ȡֵ��0-��Ȩ�ޣ�1-��Ȩ��
    /*���� 1: ��������*/
    /*���� 2: ¼������*/
    /*���� 3: �������*/
    /*���� 4: ��������*/
    /*���� 5: ��������*/
    /*���� 6: ��������*/
    /*���� 7: ¼��ط�*/
    /*���� 8: ϵͳ����*/
    /*���� 9: ϵͳ��Ϣ*/
    /*���� 10: �������*/
    /*���� 11: ��̨����*/
    /*���� 12: �ػ�����*/
    /*���� 13: USB����*/
    /*���� 14������*/
	BYTE LocalChannel[MAX_CHANNUM_EX];	//�����û���ͨ���Ĳ���Ȩ�ޣ����128��ͨ����0-��Ȩ�ޣ�1-��Ȩ��
	BYTE dwRemoteRight[MAX_RIGHT];	    //Զ�̵�½�û����߱���Ȩ�� 1.����0δʹ�ã�2.ȡֵ��0-��Ȩ�ޣ�1-��Ȩ��
    /*���� 1: Զ��Ԥ��*/
    /*���� 2: ��������*/
    /*���� 3: Զ�̻ط�*/
    /*���� 4: Զ�̱���*/
    /*���� 5: �鿴��־*/
    /*���� 6: �����Խ�*/
    /*���� 7: Զ������*/
    /*���� 8��Զ������*/
	BYTE RemoteChannel[MAX_CHANNUM_EX];	/* Զ��ͨ��Ȩ��*/
	char sUserIP[16];				    /* �û�IP��ַ(Ϊ0ʱ��ʾ�����κε�ַ) */	
	BYTE byMACAddr[MACADDR_LEN];		/* �����ַ */	
}HB_SDVR_USER_INFO_EX,*LPHB_SDVR_USER_INFO_EX;

typedef struct{
	DWORD dwSize;
	HB_SDVR_USER_INFO struUser[MAX_USERNUM];
}HB_SDVR_USER,*LPHB_SDVR_USER;

typedef struct{
	DWORD dwSize;
	HB_SDVR_USER_INFO_EX struUser[MAX_USERNUM];
}HB_SDVR_USER_EX,*LPHB_SDVR_USER_EX;

//DNS
typedef struct	{
	DWORD dwSize;
	char sDNSUser[INFO_LEN];				// DNS�˺�
	char sDNSPassword[INFO_LEN];			// DNS����
	char sDNSAddress[INFO_SEQ][INFO_LEN];	// DNS������ַ
	BYTE sDNSALoginddress;					// DNS������ַ��sDNSAddress�����е�ָ��������ַ������
	BYTE sDNSAutoCon;						// DNS�Զ�����
	BYTE sDNSState;							// DNS��½  0-ע�� 1-��½
	BYTE sDNSSave;							// DNS��Ϣ����
	WORD sDNServer;                         // 0-- hanbang.org.cn 1--oray.net 2--dyndns.com
	WORD reserve;	                        // 1--��������,0--������
}HB_SDVR_DNS,*LPHB_SDVR_DNS;

typedef struct	{
	DWORD dwSize;
	char sDNSUser[INFO_LEN];				// DNS�˺� �ԡ�\0�������ַ���
	char sDNSPassword[INFO_LEN];			// DNS���� �ԡ�\0�������ַ���
	char sDNSAddress[INFO_SEQ][INFO_LEN];	// DNS������ַ �ԡ�\0�������ַ���
                                            // �����������ʽ�й�
	BYTE sDNSALoginddress;					// DNS������ַ��sDNSAddress�����е�ָ��������ַ������
	BYTE sDNSAutoCon;						// ���������Ƿ��Զ�������0-��������1-�Զ�����
	BYTE sDNSState;							// DNS��½  0-ע�� 1-��½
	BYTE sDNSSave;							// DNS��Ϣ���� ��ȡ��ʱ��������
	WORD sDNServer;                         // 0-- hanbang.org.cn 1--oray.net 2--dyndns.com ...
    BYTE sAutoRegist;                       // ���ڱ�ʾ DDNS �Զ�ע��ʱ�û����Ƿ�Ĭ�ϣ�0-��Ĭ�ϣ�1-Ĭ��
    BYTE reserve;                           // ����
    BYTE sDNSName[128];                     // ������������(hanbang.oray.net)
}HB_SDVR_DNS_EX,*LPHB_SDVR_DNS_EX;

//PPPoE
typedef struct	{
	DWORD dwSize;
	BYTE sPPPoEUser[INFO_LEN];				// PPPoE�û���
	char sPPPoEPassword[INFO_LEN];			// PPPoE����
	BYTE sPPPoEAutoCon;						// PPPoE�Զ�����
	BYTE sPPPoEState;						// PPPoE��½  0-ע�� 1-��½
	BYTE sPPPoESave;						// DNS��Ϣ����
	char reservedData;
}HB_SDVR_PPPoE,*LPHB_SDVR_PPPoE;

//ƽ̨��Ϣ
typedef struct  {
	char sServerIP[16];						// ���������IP��ַ
	ULONG nPort;							// ����������˿ں�
	char puId[NAME_LEN];					// �豸ע��ID��
	ULONG  nInternetIp ;					// ��������IP
    ULONG  nVideoPort;						// ��Ƶ�˿�
    ULONG  nTalkPort;						// �Խ��˿�
    ULONG  nCmdPort;						// ����˿�
    ULONG  nVodPort;						// �㲥�˿�
	ULONG	tran_mode;						// 1 ������  0 ������
   // ��������
    ULONG ftp_mode;       // ��FTP��ʽ�������Ĵ洢 1 ���� 0 �ر�
    ULONG max_link;       // ��������� 0 - 32
}HB_SDVR_SERVERCFG,*LPHB_SDVR_SERVERCFG;

typedef struct
{
	char sFileName[100];			//�ļ���
	HB_SDVR_TIME struStartTime;		//�ļ��Ŀ�ʼʱ��
	HB_SDVR_TIME struStopTime;		//�ļ��Ľ���ʱ��
	DWORD dwFileSize;				//�ļ��Ĵ�С
	unsigned char nCh;				//ͨ����
	unsigned char nType;			//¼������
}HB_SDVR_FIND_DATA,*LPHB_SDVR_FIND_DATA;		

typedef struct 
{
	BYTE byRecordStatic;				//ͨ���Ƿ���¼��,0-��¼��,1-¼��
	BYTE bySignalStatic;				//���ӵ��ź�״̬,0-����,1-�źŶ�ʧ, 2-����
	BYTE byHardwareStatic;				//����
	char reservedData;
	DWORD dwBitRate;					//ʵ������
	DWORD dwLinkNum;					//�ͻ������ӵĸ���
	DWORD dwClientIP[MAX_LINK];			//����
}HB_SDVR_CHANNELSTATE,*LPHB_SDVR_CHANNELSTATE;

typedef struct
{
    DWORD dwVolume;				//Ӳ�̵�������MB��
    DWORD dwFreeSpace;			//Ӳ�̵�ʣ��ռ䣨MB��
    DWORD dwHardDiskStatic;		//Ӳ��״̬��dwVolume��ֵʱ��Ч�� 0-���� 1-���̴��� 2-�ļ�ϵͳ����
}HB_SDVR_DISKSTATE,*LPHB_SDVR_DISKSTATE;

typedef struct
{
	DWORD dwDeviceStatic; 				//����
	HB_SDVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM]; //Ӳ��״̬
	HB_SDVR_CHANNELSTATE struChanStatic[MAX_CHANNUM];//ͨ����״̬
	DWORD  byAlarmInStatic ;			//�����˿ڵ�״̬ ��λ��ʾ
	DWORD  byAlarmOutStatic ;			//��������˿ڵ�״̬ ��λ��ʾ
	DWORD  dwLocalDisplay;				//����
}HB_SDVR_WORKSTATE,*LPHB_SDVR_WORKSTATE;

//7024 or nvs 100325
typedef struct
{
	DWORD dwDeviceStatic; 				//����
	HB_SDVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM]; //Ӳ��״̬
	HB_SDVR_CHANNELSTATE struChanStatic[MAX_CHANNUM_EX];//ͨ����״̬
	DWORD  byAlarmInStatic[MAX_ALARMIN_EX] ;			//�����˿ڵ�״̬ ��λ��ʾ
	DWORD  byAlarmOutStatic[MAX_ALARMOUT_EX] ;			//��������˿ڵ�״̬ ��λ��ʾ
	DWORD  dwLocalDisplay;				//����
}HB_SDVR_WORKSTATE_EX,*LPHB_SDVR_WORKSTATE_EX;
//end add

//�����
//���̸�ʽ��
#define SDVR_MAX_RSVDPART_NUM        2  //�û�����������

//��ʽ���ļ�ϵͳ����
typedef enum
{	
    ENUM_SDVR_FSTYPE_FAT32, 	
    ENUM_SDVR_FSTYPE_ISOFS,
    ENUM_SDVR_FSTYPE_EXT4,
    ENUM_SDVR_FSTYPE_EXT3,
    ENUM_SDVR_FSTYPE_XFS,
    ENUM_SDVR_FSTYPE_MAX
}ENUM_SDVR_FSTYPE;

typedef struct
{   
    ENUM_SDVR_FSTYPE  EnumFsType;       //��ʽ���ļ�ϵͳ����    
    BYTE  	byReformat;                 //�Ƿ��ʽ��   
    DWORD 	dwSize;   			        //������С����λMB��
}HB_SDVR_RSVDPART, *LPHB_SDVR_RSVDPART;
typedef struct
{
    BYTE    byDiskNum;				    //���̺�	
    HB_SDVR_RSVDPART  RsvdPart[SDVR_MAX_RSVDPART_NUM];//�û�������ʽ����Ϣ����
    char	reserve[4]; 				//����
}HB_SDVR_FORMAT_CUSTOM,*LPHB_SDVR_FORMAT_CUSTOM;

//�����豸����״̬
typedef struct
{   
    ENUM_SDVR_FSTYPE  EnumFsType;       //�ļ�ϵͳ����(dw_size��Ϊ0ʱ��Ч)  
    DWORD 	dwSize;   			        //������С����λMB,Ϊ0��ʾû��Ԥ����
}HB_SDVR_RSVDPART_INFO, *LPHB_SDVR_RSVDPART_INFO;
typedef struct
{
    DWORD   dwCapability;                    					//����������(��λMB)
    DWORD   dwFormatCapability;            						//�ļ�ϵͳ������(��λMB)
    DWORD   dwFormatFree;                   					//�ļ�ϵͳ��������(��λMB)
    HB_SDVR_RSVDPART_INFO RsvdPartInfo[SDVR_MAX_RSVDPART_NUM];  //�û�������Ϣ
    DWORD   dwHarddiskStatic;             						//Ӳ��״̬��dw_format_capability��ֵʱ��Ч�� 0-���� 1-���̴��� 2-�ļ�ϵͳ����
}HB_SDVR_DISKSTATE_CUSTOM,*LPHB_SDVR_DISKSTATE_CUSTOM;
typedef struct
{
    DWORD   dwSize;                  						    //�ṹ���С
    HB_SDVR_DISKSTATE_CUSTOM    HarddiskStatic[MAX_DISKNUM];    //Ӳ��״̬
    HB_SDVR_CHANNELSTATE 		ChanStatic[MAX_CHANNUM_EX];     //ͨ����״̬
    DWORD   dwAlarminStatus[MAX_ALARMIN_EX];                    //��������˿ڵ�״̬
    DWORD   dwAlarmoutStatus[MAX_ALARMOUT_EX];                  //��������˿ڵ�״̬
    DWORD   reserve[4];                 					    //����
}HB_SDVR_WORKSTATE_CUSTOM,*LPHB_SDVR_WORKSTATE_CUSTOM;
//end

typedef struct 
{
	DWORD   byChannel;			//����ͨ��
	WORD    Preset[PRESETNUM];
	WORD    PresetPoll;			//��Ԥ�õ���Ѳ������رձ�ʾ
	WORD    presettime;			//��Ԥ�õ���Ѳʱ��
}HB_SDVR_PRESETPOLL,*LPHB_SDVR_PRESETPOLL;

//Ԥ������
typedef struct
{
	long bToScreen;
	long bToVideoOut;
	long nLeft;
	long nTop;
	long nWidth;
	long nHeight;
	long nReserved;
}HB_SDVR_DISPLAY_PARA,*LPHB_SDVR_DISPLAY_PARA; 

typedef struct
{
	LONG lChannel;//ͨ����
	LONG lLinkMode; //���λ(31)Ϊ0��ʾ��������Ϊ1��ʾ��������0��30λ��ʾ�������ӷ�ʽ:0��TCP��ʽ,1��UDP��ʽ,2���ಥ��ʽ,3 - RTP��ʽ��4-�绰�ߣ�5��128k�����6��256k�����7��384k�����8��512k�����
	char* sMultiCastIP;
	HB_SDVR_DISPLAY_PARA struDisplayPara;
}HB_SDVR_CARDINFO,*LPHB_SDVR_CARDINFO;

/* �����豸͸��ͨ������ */
typedef struct {
	DWORD dwEnableTransPort;	/* �Ƿ�����͸��ͨ�� 0�������� 1������*/
	char sDecoderIP[16];		/* DVR IP��ַ */
	WORD wDecoderPort;			/* �˿ں� */
	WORD wDVRTransPort;			/* ����ǰ��DVR�Ǵ�485/232�����1��ʾ485����,2��ʾ232���� */		
	char cReserve[4];
}HB_SDVR_PORTINFO, *LPHB_SDVR_PORTINFO;

/*���ӵ�ͨ������*/
typedef struct {
	char sDVRIP[16];				/* DVR IP��ַ */
	WORD wDVRPort;			 		/* �˿ں� */
	BYTE sUserName[NAME_LEN];		/* �û��� */
	BYTE sPassword[PASSWD_LEN];		/* ���� */
	BYTE byChannel;					/* ͨ���� */
	BYTE byLinkMode;				/* ����ģʽ */	
	BYTE byLinkType;				/* �������� 0�������� 1�������� */
}HB_SDVR_DECCHANINFO, *LPHB_SDVR_DECCHANINFO;

/*ÿ������ͨ��������*/
typedef struct {	
	BYTE	byPoolChans;			/*ÿ·����ͨ���ϵ�ѭ��ͨ������, ���4ͨ��*/
	HB_SDVR_DECCHANINFO struchanConInfo[MAX_DECPOOLNUM];
	BYTE	byEnablePoll;			/*�Ƿ���Ѳ 0-�� 1-��*/
	BYTE	byPoolTime;				/*��Ѳʱ�� 0-���� 1-10�� 2-15�� 3-20�� 4-30�� 5-45�� 6-1���� 7-2���� 8-5���� */	
}HB_SDVR_DECINFO, *LPHB_SDVR_DECINFO;

/*�����豸��������*/
typedef struct {
	DWORD	dwSize;
	DWORD	dwDecChanNum; 		/*����ͨ��������*/
	HB_SDVR_DECINFO struDecInfo[MAX_DECNUM];
}HB_SDVR_DECCFG, *LPHB_SDVR_DECCFG;

typedef struct{
	USHORT m_Year;
	USHORT m_Month;
	USHORT m_Day;
	USHORT m_Hour;
	USHORT m_Minute;
	USHORT m_Second;
	BYTE DeviceName[24];	//�豸����
	DWORD dwChannelNumer;	//ͨ����
	BYTE CardNumber[32];	//����
	char cTradeType[12];	//��������
	DWORD dwCash;			//���׽��
}HB_SDVR_TRADEINFO,*LPHB_SDVR_TRADEINFO;

//����ΪATMר��
/*֡��ʽ*/
typedef struct{
	BYTE code[12];		/* ���� */
}HB_SDVR_FRAMETYPECODE;

typedef struct{
	DWORD dwSize;	
	char sATMIP[16];						/* ATM IP��ַ */
	DWORD dwATMType;						/* ATM���� */
	DWORD dwInputMode;						/* ���뷽ʽ	*/	
	DWORD dwFrameSignBeginPos;              /* ���ı�־λ����ʼλ��*/
	DWORD dwFrameSignLength;				/* ���ı�־λ�ĳ��� */
	BYTE  byFrameSignContent[12];			/* ���ı�־λ������ */
	DWORD dwCardLengthInfoBeginPos;			/* ���ų�����Ϣ����ʼλ�� */
	DWORD dwCardLengthInfoLength;			/* ���ų�����Ϣ�ĳ��� */
	DWORD dwCardNumberInfoBeginPos;			/* ������Ϣ����ʼλ�� */
	DWORD dwCardNumberInfoLength;			/* ������Ϣ�ĳ��� */
	DWORD dwBusinessTypeBeginPos;           /* �������͵���ʼλ�� */
	DWORD dwBusinessTypeLength;				/* �������͵ĳ��� */
	HB_SDVR_FRAMETYPECODE frameTypeCode[10];/* ���� */
}HB_SDVR_FRAMEFORMAT,*LPHB_SDVR_FRAMEFORMAT;

//�人���� 2005-06-29
typedef struct
{
	char sFileName[100];    //ͼƬ��
	HB_SDVR_TIME struTime;  //ͼƬ��ʱ��
	DWORD dwFileSize;       //ͼƬ�Ĵ�С
	char sCardNum[32];	    //����
}HB_SDVR_FIND_PICTURE,*LPHB_SDVR_FIND_PICTURE;

/* ���������ļ��ط� */
typedef struct {
	DWORD dwSize;
	char sDecoderIP[16];		/* DVR IP��ַ */
	WORD wDecoderPort;			/* �˿ں� */
	WORD wLoadMode;				/* �ط�����ģʽ 1�������� 2����ʱ�� */
	union
	{
		BYTE byFile[100];		/* �طŵ��ļ��� */
		struct 
		{
			DWORD dwChannel;
			BYTE sUserName[NAME_LEN];	/*������Ƶ�û���*/
			BYTE sPassword[PASSWD_LEN];	/* ���� */
			HB_SDVR_TIME struStartTime;	/* ��ʱ��طŵĿ�ʼʱ�� */
			HB_SDVR_TIME struStopTime;	/* ��ʱ��طŵĽ���ʱ�� */			
		}bytime;
	}mode_size;
}HB_SDVR_PLAYREMOTEFILE,*LPHB_SDVR_PLAYREMOTEFILE;

/*��ǰ�豸��������״̬*/
typedef struct {
	DWORD dwWorkType;		/*������ʽ��1����Ѳ��2����̬���ӽ��롢3�����ļ��ط� 4����ʱ��ط�*/
	char sDVRIP[16];		/*���ӵ��豸ip*/
	WORD wDVRPort;			/*���Ӷ˿ں�*/
	BYTE byChannel;			/* ͨ���� */
	BYTE byLinkMode;		/* ����ģʽ */
	DWORD	dwLinkType;		/*�������� 0�������� 1��������*/
	union
	{
		struct 
		{
			BYTE sUserName[NAME_LEN];	/*������Ƶ�û���*/
			BYTE sPassword[PASSWD_LEN];	/* ���� */
			char cReserve[52];
		}userInfo;
		struct 
		{			
			BYTE   fileName[100];		
		}fileInfo;
		struct 
		{
			DWORD	dwChannel;
			BYTE	sUserName[NAME_LEN];	/*������Ƶ�û���*/
			BYTE	sPassword[PASSWD_LEN];	/* ���� */
			HB_SDVR_TIME struStartTime;		/* ��ʱ��طŵĿ�ʼʱ�� */
			HB_SDVR_TIME struStopTime;		/* ��ʱ��طŵĽ���ʱ�� */	
		}timeInfo;
	}objectInfo;
}HB_SDVR_DECCHANSTATUS, *LPHB_SDVR_DECCHANSTATUS;

typedef struct {
	DWORD   dwSize;
	HB_SDVR_DECCHANSTATUS struDecState[MAX_DECNUM];	
}HB_SDVR_DECSTATUS, *LPHB_SDVR_DECSTATUS;

typedef struct {
	DWORD dwSize;
	HB_SDVR_PORTINFO struTransPortInfo[MAX_TRANSPARENTNUM]; /* ����0��ʾ485 ����1��ʾ232 */
}HB_SDVR_PORTCFG, *LPHB_SDVR_PORTCFG;	

//�Զ�����̨Э��
typedef struct {
    BYTE     CheckSum;      //Ч����λ��
    BYTE     PortNum;       //��ַ��λ��
    BYTE     PreSet;        //Ԥ�Ƶ�λ��
    BYTE     CheckSumMode;  //Ч�������ģʽ
    BYTE     KeyLen;        //�볤��
    BYTE     KeyNum;        //������
    BYTE     CommandKey[MAX_KEYNUM][24];
}STRUCT_SDVR_DECODERCUSTOMIZE,*LPSTRUCT_SDVR_DECODERCUSTOMIZE;

typedef struct {
	int ptznum;
	char ptztype[MAXPTZNUM][10];
}STRUCT_SDVR_PTZTYPE,*LPSTRUCT_SDVR_PTZTYPE;

typedef struct 
{
	WORD enable;    //ʹ��
	WORD time;      //�ӳ�ʱ��
}STRUCT_ALARMIN_WAIT, *LPSTRUCT_ALARMIN_WAIT;

//for ipc 
typedef struct
{
	BYTE  bVideoOut;		//��Ƶ���
	BYTE  bTemperature;		//�¶�̽��
	BYTE  bVoltage;			//��ѹ̽��
	BYTE  bSubStream;		//������
	DWORD Rserve1;			//����
	DWORD Rserve2;			//����

}STRUCT_SDVR_IPCCONFIG,*LPSTRUCT_SDVR_IPCCONFIG; 

typedef struct
{
	WORD selIndex;
	WORD Rserve;	
}STRUCT_SDVR_IPCPIC,*LPSTRUCT_SDVR_IPCPIC;

typedef struct
{
	WORD selIndex;
	WORD Rserve;	
}STRUCT_SDVR_IPCAGC,*LPSTRUCT_SDVR_IPCAGC;

//for ipc
typedef struct
{
    BYTE safeoption;    // ��ȫѡ�����ã�ȡֵ��Χ[0,2]  0:�Զ�ѡ��  1������ϵͳ   2��������Կ
    BYTE pswformat;     // ��Կ��ʽ���ã�ȡֵ��Χ[0,1]  0��16����   1��ASCII��
    BYTE pswtype;       // �� Կ �� �����ã�ȡֵ��Χ[0,3]   0������  1��64λ  2:128λ   3:152λ
    BYTE pswword[62];   // ���룬�ԡ�\0����β������62byte��Ϊ����STRUCT_SDVR_IPCWPAPSK�ȴ�С��
                        //����ע�����볤��˵����ѡ��64λ��Կ������16�������ַ�10��������ASCII���ַ�5����ѡ��128λ��Կ��
                        // ����16�������ַ�26��������ASCII���ַ�13����ѡ��152λ��Կ������16�������ַ�32��������ASCII
                        // ���ַ�16������
    BYTE reserve[3];	//����
}STRUCT_SDVR_IPCWEP,*LPSTRUCT_SDVR_IPCWEP;

typedef struct
{
    BYTE safeoption;    // ��ȫѡ�����ã�ȡֵ��Χ[0,2] 0���Զ�ѡ��   1��WPA-PSK    2:WPA2-PSK
    BYTE pswmod;        // ���ܷ�������,ȡֵ��Χ[0,2]  0���Զ�ѡ��   1��TKIP   2:AES
    BYTE pawword[64];   // psk���룬8��63���ַ����ԡ�\0����β
    BYTE reserve[2];	// ����
}STRUCT_SDVR_IPCWPAPSK,*LPSTRUCT_SDVR_IPCWPAPSK;

typedef struct
{
    DWORD   nSecCmdParaSize;    // ������ӣ��ṹ�峤�ȡ�
    BYTE    ssid[50];           // SSID���ԡ�\0����β
    BYTE    wirelessIP[16];     // ����ip�ԡ�\0����β
    BYTE    safetype;           // ��ȫ�������ã�ȡֵ��Χ[0,2]    0��WEB��1��WPA-PSK/WPA2-PSK��2���޼���
    BYTE    reserve[3];	        // ����  	
    union
    {                           // ��Ϊ���������ṹ�岻����ͬʱʹ�ã������������塣
        STRUCT_SDVR_IPCWEP      ipcwep;     // ��ȫ����ΪWEPʱ�����ṹ��
        STRUCT_SDVR_IPCWPAPSK   ipcwpapsk;  // ��ȫ����ΪWPA-PSK/WPA2-PSKʱ�����ṹ��
    }u;
}STRUCT_SDVR_IPCWIRELESS,*LPSTRUCT_SDVR_IPCWIRELESS;

typedef struct
{
	BYTE    channel; //ͨ����
	short   iframerate; //֡���
	BYTE    Reserve;//����	
}STRUCT_SDVR_IFRAMERATE,*LPSTRUCT_SDVR_IFRAMERATE;

typedef struct 
{
    char    server[32];		// ������
    DWORD   port;				// �˿�
    DWORD   auto_enbale;		// ����ntp����,0-��ʾ�ֶ�,1-��ʾ�Զ�
    DWORD   server_index;		// ������������
    DWORD   sync_period;		// ͬ�����ڣ�
    DWORD   sync_unit;		// ͬ�����ڣ�0-���� 1-Сʱ 2-�� 3-���� 4-��
    DWORD   sync_time;		//����
	DWORD   time_zone;   //ʱ��
    DWORD   reserve;			// ����
}HB_SDVR_NTPCONFIG,*LPHB_SDVR_NTPCONFIG;

typedef struct 
{
    char    host[MAX_SMTP_HOST];			//�����ʼ���SMTP�����������磺126�������smtp.126.com
    DWORD	port;						// �������˿ڣ������ʼ�(SMTP)�˿ڣ�Ĭ��ֵ25
    char	user[32];					// �ʼ��û���
    char	pwd[32];					// �ʼ��û�����
    char	send_addr[MAX_SMTP_HOST];	// FROM���ʼ���ַ
    char	recv_addr[MAX_SMTP_ADDR];	// TO���ʼ���ַ������Ƕ���ʼ���ַ����';'����
    DWORD   send_period;					// �ϴ�����,��λ(����)
    DWORD   snap_enable;					// �Ƿ�ץ���ϴ�
    char	reserve[MAX_STRING];		//
} HB_SDVR_SMTPCONFIG,*LPHB_SDVR_SMTPCONFIG;

typedef struct 
{
	DWORD  poll_type; //��ѵ���ͣ�0����ѵ��1��spot��Ѳ
    DWORD enable; // ���ã�0-���ã�1-����
    DWORD period; // ��ѵ�������λ��
    DWORD format; // �����ʽ��0-0ff, 1-1, 2-2, 4-2x2, 9-3x3, 16-4x4
    BYTE ch_list[MAX_CHANNUM];//
} HB_SDVR_POLLCONFIG,*LPHB_SDVR_POLLCONFIG;

typedef struct 
{
    DWORD  poll_type; //��ѵ���ͣ�0����ѵ��1��spot��Ѳ
    DWORD enable; // ���ã�0-���ã�1-����
    DWORD period; // ��ѵ�������λ��
    DWORD format; // �����ʽ��0-0ff, 1-1, 2-2, 4-2x2, 9-3x3, 16-4x4
    BYTE ch_list[MAX_CHANNUM_EX];//
} HB_SDVR_POLLCONFIG128,*LPHB_SDVR_POLLCONFIG128;

typedef struct 
{
    BYTE matrix_channel[MAX_CHANNUM];	// ��Ƶ�����Ӧͨ�� ��1��ʼ��0xff��ʾ�ر�
    BYTE reserve[32];						// ����λ
}HB_SDVR_VIDEOMATRIX,*LPHB_SDVR_VIDEOMATRIX;

typedef struct 
{
    BYTE matrix_channel[MAX_CHANNUM_EX];	// ��Ƶ�����Ӧͨ�� ��1��ʼ��0xff��ʾ�ر�
    BYTE reserve[32];						// ����λ
}HB_SDVR_VIDEOMATRIX128,*LPHB_SDVR_VIDEOMATRIX128;

// ϵͳʱ�䶨��
typedef struct {
	unsigned int sec : 6;
	unsigned int min : 6;
	unsigned int hour : 5;
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 6;
} ASYSTIME, *PASYSTIME;	

/*********************************************************************
// ����
********************************************************************/
//һ���������
typedef struct
{
    USHORT	x;          //������
    USHORT	y;          //������
}PT_ATMI_POINT_S, *PPT_ATMI_POINT_S;

// ����ͳ�Ʋ���
typedef struct PT_HDC_CTRLPARAM_ST
{
    DWORD           dwWidth;            // ������Ƶ�Ŀ�ȣ�Ĭ��ֵ352
    DWORD           dwHeight;           // ������Ƶ�߶ȣ�Ĭ��ֵ288
    DWORD           objWidth;           // ����Ŀ��Ŀ�ȣ���λΪ���أ�Ĭ��ֵ55
    PT_ATMI_POINT_S ptStart;            // �������㣬Ĭ��ֵ��5,216)
    PT_ATMI_POINT_S ptEnd;              // ������յ㣬Ĭ��ֵ(347,216)
    PT_ATMI_POINT_S ptDirection;        // ����ߵķ���Ĭ��ֵ(290, 205)
    DWORD           dwPassFrames;       // ��ʼ���ĵ�Ŀ���ںϳ�ͼ�еĸ߶ȣ���Ŀ��ͨ������ߵ�֡����Ĭ��ֵ15
    DWORD           dwMutiObjWidth;     // ��������Ŀ�겢��ʱ���ο�Ŀ�ȣ�Ĭ��ֵ110
    DWORD           dwMutiObjWidthEdge; // ��dwMutiObjWidth�йأ�dwMutiObjWidthEdge = ��dwMutiObjWidth / 2 - 5��/ 2��Ĭ��ֵ25
    DWORD           dwThreshBackDiff;   // �����ֵ��Ĭ��ֵ50���Ƚ�����
    DWORD           dwThreshFrameDiff;  // ֡��ֵ��Ĭ��ֵ20
    BYTE            byStartPtLabel;     // ������ǣ�0��ʾ�κ�Ŀ���������1��ʾС�ڷ�ֵ��Ŀ�겻������Ĭ��ֵΪ0
    BYTE            byEndPtLable;       // �յ����ǣ�0��ʾ�κ�Ŀ���������1��ʾС�ڷ�ֵ��Ŀ�겻������Ĭ��ֵΪ0
    BYTE            byReserve[2];      // �����ֶ�
    DWORD           dwHalfObjW;         // ��ֵ����ǰ������أ����С�ڸ÷�ֵ��������Ĭ��ֵΪ20
}PT_HDC_CTRLPARAM, *LPPT_HDC_CTRLPARAM;

/*****************************************************************
����Ϊ��·���ܵı���ͨ�Žṹ
*****************************************************************/
//��������
typedef struct
{
    int left;         //����������
    int top;         //����������
    int right;      //����������
    int bottom;  //����������
}PT_ATMI_RECT, *PPT_ATMI_RECT;

//�������ͼ�λ����Ϣ
typedef struct
{
    int alarm_type;         //����,GUI_ATMI_ALARM_TYPE_E
    PT_ATMI_RECT position;       //����λ��
}PT_ATMI_ALARM_POSITION_S, *PPT_ATMI_ALARM_POSITION_S;

// 1.����ͨ�������ṹ��
typedef struct
{
    int alarm_num;                                             //��������
    PT_ATMI_ALARM_POSITION_S alarm_area[10];       //��������ֵ,һ����alarm_num���������ȫΪ0
}PT_ATMI_FACE_ALARM_S, *PPT_ATMI_FACE_ALARM_S;

// 2.���ͨ�������ṹ��
typedef struct
{
    int alarm_num;                                             //��������
    PT_ATMI_ALARM_POSITION_S alarm_area[10];       //��������ֵ,һ����alarm_num���������ȫΪ0
}PT_ATMI_PANEL_ALARM_S, *PPT_ATMI_PANEL_ALARM_S;

// 3.�ӳ����������Ϣ
typedef struct
{
    int type; //�Ƿ����˴��룬0��ʾ�ޣ�1��ʾ��
}PT_ATMI_MONEY_ALARM_S, *PPT_ATMI_MONEY_ALARM_S;

// 4.���������ṹ��,alarm_num����Ӧ��������ǰ��track_num����Ӧ�����������alarm_num�����
typedef struct
{
    int alarm_num;  //����Ŀ������
    int track_num;   //����Ŀ������
    PT_ATMI_ALARM_POSITION_S envi_alarm_region[25];
}PT_ATMI_ENVI_ALARM_S, *PPT_ATMI_ENVI_ALARM_S;

typedef enum
{
    PT_ATMI_FACE_BLOCK = 0,					//�����ڵ�
    PT_ATMI_FACE_NOSIGNAL,					//����ͨ����Ƶ��ʧ
    PT_ATMI_FACE_UNUSUAL,					//�����쳣
    PT_ATMI_FACE_NORMAL,					//��������
    PT_ATMI_PANEL_BLOCK  = 40, 				//����ڵ�
    PT_ATMI_PANEL_NOSIGNAL,					//���ͨ����Ƶ��ʧ
    PT_ATMI_PANEL_PASTE,						//����
    PT_ATMI_PANEL_KEYBOARD,				//װ�ټ���
    PT_ATMI_PANEL_KEYMASK,					//�ƻ����������	
    PT_ATMI_PANEL_CARDREADER,				//�ƻ�������
    PT_ATMI_PANEL_TMIEOUT,					//��ʱ����
    PT_ATMI_ENTER,							//���˽���
    PT_ATMI_EXIT,								//�˳���
    PT_ATMI_MONEY_BLOCK = 80,				//�ӳ�����Ƶ�ڵ�
    PT_ATMI_MONEY_NOSIGNAL,				//�ӳ���ͨ����Ƶ��ʧ
    PT_ATMI_MONEY_UNUSUAL,					//�ӳ����쳣,�����˴���ӳ���
    PT_ATMI_ENVI_BLOCK = 120,					//����ͨ����Ƶ�ڵ�
    PT_ATMI_ENVI_NOSIGNAL,					//����ͨ����Ƶ��ʧ
    PT_ATMI_ENVI_GATHER,						//���˾ۼ�
    PT_ATMI_ENVI_MANYPEOPLEINREGION,		//Υ��ȡ��
    PT_ATMI_ENVI_LINGERING,					//��Ա�ǻ�
    PT_ATMI_ENVI_LIEDOWN,					//��Ա����
    PT_ATMI_ENVI_FORBIDREGION,				//�Ƿ����뾯����
    PT_ATMI_ENVI_LEAVEOBJECT,				//��Ʒ����
}PT_ATMI_ALARM_TYPE_E;

//����ͼƬ�ṹ��
typedef struct
{
	DWORD pic_alarm_type;                     // PT_ATMI_ALARM_TYPE_E; 
	DWORD pic_format;                         // ͼƬ��ʽCIF:0  D1:1
	DWORD pic_size;
}PT_ATMI_ALARM_PICINFO_S, *PPT_ATMI_ALARM_PICINFO_S;

typedef enum
{
    HBGK_HDCCOUNT_DIR1 = 0,	//���Ƿ�����ͬ
    HBGK_HDCCOUNT_DIR2		//���Ƿ����෴
}PT_HDCCOUNT_DIRECTION_E;

typedef struct PT_HDC_RESULT_ST
{
    DWORD dwResultType;     // ������������
    DWORD dwSubType;        // �����������ͣ���ʾ��Ա����ͳ�Ƶķ����PT_HDCCOUNT_DIRECTION_E
    DWORD dwTrackNum;       // ��ǰ���ͳ�Ƶ�ID���(��ͳ������)
    PT_ATMI_RECT    rcPos;  // ��ǰ�����ŵ���Ӿ��ο�
}PT_HDC_RESULT, *LPPT_HDC_RESULT;

//����ʱ���������ͻ��˵��ܽṹ��
typedef struct
{
    // int chn;    //ͨ����,ÿ�α����󣬸���ͨ���ţ�ȥ��ȡ�����ĸ��ṹ���ж�Ӧ����һ��
    BYTE byChn;
    BYTE byReserve1;
    BYTE byInfoType;        // �ϴ���Ϣ����
                            // 0, PT_ATMI_FACE_ALARM_S
                            // 1, PT_ATMI_PANEL_ALARM_S
                            // 2, PT_ATMI_MONEY_ALARM_S
                            // 3, PT_ATMI_ENVI_ALARM_S
                            // 4, PT_HDC_RESULT
    BYTE byReserve2;

    union
    {
        PT_ATMI_FACE_ALARM_S atmi_face_alarm;           // 1.����ͨ�������ṹ��
        PT_ATMI_PANEL_ALARM_S atmi_panel_alarm;         // 2.���ͨ�������ṹ��
        PT_ATMI_MONEY_ALARM_S atmi_money_alarm;         // 3.�ӳ���ͨ�������ṹ��
        PT_ATMI_ENVI_ALARM_S atmi_envi_alarm;           // 4.����ͨ�������ṹ��
        PT_HDC_RESULT           hdc;
    }info;

    PT_ATMI_ALARM_PICINFO_S alarm_picinfo;
    ASYSTIME alarmtime;  //����ʱ��
}PT_ATMI_ALARM_INFO_S, *PPT_ATMI_ALARM_INFO_S;
/*****************************************************************
����Ϊ��·���ܵ����û��ȡ�Ľ���ṹ
*****************************************************************/
//����α�ʾ�ṹ�壬����������
typedef struct
{
    PT_ATMI_POINT_S point[10];  //����ζ�������
    int 	   point_num;       //��ĸ���
    int      region_type;       //��������
}PT_ATMI_POLYGON_S, *PPT_ATMI_POLYGON_S;

//�������򣬴���������
typedef struct
{
    PT_ATMI_RECT region;    //������������
    int region_type;        //��������
}PT_ATMI_RECT_S, *PPT_ATMI_RECT_S;

//��������Ȥ�����Լ��������������Ĵ�С
typedef struct
{
    PT_ATMI_RECT_S roi; //����
    int min_face;       //��С�ߴ�
    int max_face;       //���ߴ�
}PT_ATMI_FACE_ROI_S, *PPT_ATMI_FACE_ROI_S;

// 1.����ͨ���������õ�����
typedef struct
{
    int num;
    PT_ATMI_FACE_ROI_S face_roi[10];
}PT_ATMI_FACEROI_ALL_S, *PPT_ATMI_FACEROI_ALL_S;

// 2.���ͨ���������õ�����
typedef struct
{
    int num;
    PT_ATMI_POLYGON_S atmi_panel_region[20];
}PT_ATMI_PANEL_REGION_S, *PPT_ATMI_PANEL_REGION_S;

// 3.�ӳ���ͨ���������õ����򼰲���
typedef struct
{
    PT_ATMI_POLYGON_S pol_proc_region;	    // ��������Ĭ��4���㣬����ȫͼ
    PT_ATMI_RECT_S no_process[10];	        // ����������
    int no_process_num;		                // ������������� (0)
    int warn_interval;	                    // ���α���ʱ������(100 ��)
}PT_ATMI_DISTRICTPARA_S, *PPT_ATMI_DISTRICTPARA_S;	

// 4.����ͨ���������õ�����
typedef	struct
{
    PT_ATMI_POLYGON_S pol_proc_region;		// ͼ���еĴ������򣬶���α�ʾ

    /*����ATM��ǰβ��ȡ����Ĳ�������ʶATMǰ��վ��������*/
    PT_ATMI_POLYGON_S tail_region[10];		// Region in polygon.
    int tail_num;						    // Region number. default: 0

    /*���ڽ�ֹ������뱨������ʶѡ���Ľ�ֹ���������*/
    PT_ATMI_POLYGON_S forbid_region[10];	// Region in polygon.
    int forbid_num;					        // Region number.	default: 0

    PT_ATMI_POLYGON_S obj_height;			// Ŀ�꣨�ˣ���ͼ���еĸ߶ȣ�Ĭ��85
}PT_ATMI_SCENE_COMMONPARA_S, *PPT_ATMI_SCENE_COMMONPARA_S;

// 5.����ͨ�����õĲ���,������֡Ϊ��λ�ģ������ڽ�������Ϊ�룬Ȼ�����ڲ���ת��Ϊ֡��
typedef struct
{
    /*��Ʒ�����㷨��ز���*/
    int objlv_frames_th;				    // ��Ʒ����ʱ����ֵ(֡) (30)

    /*��Ա�ǻ��㷨��ز���*/
    int mv_block_cnt;				        // �ƶ�����(20��0��ʾ�˹�����Ч)
    SHORT mv_stay_frames;			        // �����г���ʱ����ֵ(֡),������ʱ��(0��ʾ�˹�����Ч)
    SHORT mv_stay_valid_frames;		        // ATM����ͣ��ʱ����ֵ(֡),ATM����ǰͣ��ʱ��(200, 0��ʾ�˹�����Ч)

    /*���˾ۼ��㷨��ز���*/
    SHORT gather_cnt;				        // ���ۼ�����(4)
    SHORT gather_interval_frames;			// �������ʱ��(֡)(1000 frames,Լ100��)
    int gather_frame_cnt;				    // ���˾ۼ�ʱ����ֵ(֡) (100)

    /*��Ա�����㷨��ز���*/
    int liedown_frame_cnt;				    // ����ʱ����ֵ(֡).(20 frames)

    /*β��ȡ���㷨��ز���*/
    SHORT after_frame_cnt;				    // ������Ϊʱ����ֵ(֡)(20 frames)
    SHORT after_interval_frames;			// �������ʱ��(֡)(1000 frames,Լ100��)

    /*��ֹ�����㷨��ز���*/
    SHORT forbid_frame_cnt;				    // ��ֹվ��ʱ����ֵ(֡)(20 frames)
    SHORT reserve;                          // ����
}PT_ATMI_SCENE_WARN_PARAM_S, *PPT_ATMI_SCENE_WARN_PARAM_S;

// 1.����ͨ�����ýṹ��
typedef struct
{
    SHORT face_unusual;                     //�Ƿ���쳣�����������֡�����ȣ���⹦�ܣ�1 Ϊ�򿪣�0 Ϊ�رա�Ĭ��Ϊ 0  
    SHORT output_oneface;                   //��������ֻ���һ�����0Ϊ��1Ϊ�ǣ�Ĭ��Ϊ1
    int fd_rate;                            //�������������ټ��
    PT_ATMI_FACEROI_ALL_S face_roi;         //����ͨ����������������
    int abnormalface_alarmtime;             //��������ʱ�䷧ֵ���룩
}PT_ATMI_SET_FACE_S, *PPT_ATMI_SET_FACE_S;

//���澯�����ṹ��
typedef struct 
{
    int    AlphaVal;                        //����alphaֵ(5) 		
    int    BetaVal;                         //����Betaֵ(3)
    int    MetinThVal;                      //ǰ���ڱ�����ֵ(4500)
    int    LBTWTriggerVal;                  //ȡ������������ֵ(75)	

    int    AppearCntThdVal;                 //�������ֱ�������(40)
    int    AppearCntTriggerVal;             //�������ֱ�����ֵ(40)
    int    LBTWCntThdVal;                   //ȡ��������������(75)		  
    int    LBTWCntTriggerVal;               //ȡ������������ֵ(75)		  

    int    PanelTimeOutTriggerVal;          //��ʱ������ֵ(1500)

    int    OpenLightTriggerVal;             //���仯������ֵ(45)    
    int    CloseLightTriggerVal;            //���仯������ֵ(55)

    DWORD  AppearMinWidth;                  //����������СĿ����(10) 	
    DWORD  AppearMinHeight;                 //����������СĿ��߶�(10)  
    DWORD  AppearMaxWidth;                  //�����������Ŀ����(200)  		
    DWORD  AppearMaxHeight;                 //�����������Ŀ��߶�(200) 

    DWORD  LBTWMinWidth;                    //ȡ��������СĿ����(10) 			  
    DWORD  LBTWMinHeight;                   //ȡ��������СĿ��߶�(10)   
    DWORD  LBTWMaxWidth;                    //ȡ���������Ŀ����(200)  
    DWORD  LBTWMaxHeight;                   //ȡ���������Ŀ��߶�(200)
}STRUCT_SDVR_PANELALARMCFG, *PTSTRUCT_SDVR_PANELALARMCFG;

// 2.���ͨ�����ýṹ��
typedef struct
{
    int timeout_enable;                     //��ʱʱ��
    PT_ATMI_PANEL_REGION_S panel_region;    //���ͨ��������������
    STRUCT_SDVR_PANELALARMCFG panel_alarm_param;//���ͨ���������ò���
}PT_ATMI_SET_PANEL_S, *PPT_ATMI_SET_PANEL_S;

// 3.�ӳ���ͨ�����ýṹ��
typedef struct
{
    PT_ATMI_DISTRICTPARA_S money_para;      //�ӳ���ͨ��������������
}PT_ATMI_SET_MONEY_S, *PPT_ATMI_SET_MONEY_S;

// 4.����ͨ�����ýṹ��
typedef struct
{
    PT_ATMI_SCENE_WARN_PARAM_S envi_para;   //����ͨ������
    PT_ATMI_SCENE_COMMONPARA_S envi_region; //����ͨ������
}PT_ATMI_SET_ENVI_S, *PPT_ATMI_SET_ENVI_S;

//�ͻ������û��ȡ��������·�����ܵĽṹ��
typedef struct
{
    BYTE byChn;                                 // ͨ����
    BYTE byReserve1;                            // ����
    BYTE bySetInfoType;                         // ���ò������ͣ�
                                                // 0, PT_ATMI_SET_FACE_S;
                                                // 1, PT_ATMI_SET_PANEL_S;
                                                // 2, PT_ATMI_SET_MONEY_S;
                                                // 3, PT_ATMI_SET_ENVI_S;
                                                // 4, PT_HDC_CTRLPARAM;
    BYTE byReserve2;                            // ����  
    int chn_attri;                              // ͨ������(��������塢�ӳ�������)��Ŀǰδ�ã���ֹ�Ժ���
    SHORT channel_enable;                       // ͨ�����أ�0�رգ�1��
    SHORT if_pic;                               // �Ƿ���ҪץȡͼƬ
    SHORT enc_type;                             // ץȡͼƬ�ĸ�ʽ
    SHORT email_linkage;                        // ����email
    UINT sensor_num;                            // ̽ͷ���,λ��ʾ
    UINT rec_linkage;                           // ����¼��λ��ʾ
    union
    {
        PT_ATMI_SET_FACE_S  face_set_para;      // ����ͨ�����ýṹ��
        PT_ATMI_SET_PANEL_S panel_set_para;     // ���ͨ�����ýṹ��
        PT_ATMI_SET_MONEY_S money_set_para;     // �ӳ���ͨ�����ýṹ��
        PT_ATMI_SET_ENVI_S  envi_set_para;      // ����ͨ�����ýṹ��
        PT_HDC_CTRLPARAM    hdc;                // ����ͳ�Ʋ�������
    }setInfo;
}STRUCT_SDVR_INTELLECTCFG;
/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
// �ӿں�������
//3. ��½�Լ������豸��Ϣ

//SDK��ʼ�� 
HB_SDVR_API BOOL __stdcall HB_SDVR_Init();

//SDK�ͷ�
HB_SDVR_API BOOL __stdcall HB_SDVR_Cleanup();

//������Ϣ���մ���
/*
��  �ܣ����ý���������Ϣ�ľ���ͷ�ʽ ���ص��������̷߳���Ϣ��  
��  ����
nMessage��COMM_ALARM(������Ϣ)��COMM_CONNECT(����״̬) 
		hWnd�����(�����Ǵ��ڣ��������߳̾��������ʹ���߳��Է�ֹ����) 
		����ֵ��TRUE-�ɹ�	FASLE-ʧ��	*/
								
// ע��ʹ��HB_SDVR_SetDVRMessage��HB_SDVR_SetDVRMessage_Nvsʱ��ò�Ҫͬʱʹ�ã�ͬʱʹ��ʱע��ʹ�ò�ͬ�Ĵ��ھ���������޷�����
// ʹ��HB_SDVR_SetDVRMessageʱ����HB_SDVR_ALARMINFO��LPARAM���н���
// ʹ��HB_SDVR_SetDVRMessage_Nvsʱ����HB_SDVR_ALARMINFO_EX��LPARAM���н���
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDVRMessage(UINT nMessage,HWND hWnd);

//��չ�ӿڣ�Ϊ�˼������128·������by cui 10.05.20
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDVRMessage_Nvs(UINT nMessage,HWND hWnd);

//���ñ�����Ϣ�ص�-���ڴ�����Ϣ
/*
��  �ܣ����ý�����Ϣ�Ļص����� ��IP���֣� 
��  ����
#define COMM_ALARM				0x1100	//������Ϣ
#define COMM_CONNECT			0x1200	//��������Ͽ�
fMessCallBack�� ��Ϣ�ص�����
lCommand�� ��Ϣ������ ��COMM_ALARM
sDVRIP�� ip��ַ
pBuf�������Ϣ�Ļ�����
dwBufLen���������Ĵ�С
����ֵ��TRUE-�ɹ�	FASLE-ʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDVRMessCallBack(BOOL (CALLBACK *fMessCallBack)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen));

//����128·�ӿ�
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDVRMessCallBack_Nvs(BOOL (CALLBACK *fMessCallBack)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen));


//���ñ�����Ϣ�ص�-�����߳���Ϣ
/*
��  �ܣ����ý�����Ϣ�Ļص����� ��ID���֣� 
��  ����
#define COMM_ALARM				    0x1100	//������Ϣ
#define COMM_CONNECT				0x1200	//��������Ͽ�
fMessCallBack�� ��Ϣ�ص�����
lCommand�� ��Ϣ������ ��COMM_ALARM
lUserID ����HB_SDVR _Login ����
pBuf�������Ϣ�Ļ�����
dwBufLen���������Ĵ�С
����ֵ��TRUE-�ɹ�	FASLE-ʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDVRMessCallBack_EX(BOOL (CALLBACK *fMessCallBack_EX)(LONG lCommand,LONG lUserID,char *pBuf,DWORD dwBufLen));

//����128·�ӿ�
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDVRMessCallBack_EX_Nvs(BOOL (CALLBACK *fMessCallBack_EX)(LONG lCommand,LONG lUserID,char *pBuf,DWORD dwBufLen));

//����豸
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDEVMessCallBack(LONG lUserID, BOOL (CALLBACK *fMessCallBack)(LONG lCommand, char* sDVRIP, LONG lUserID,char *pBuf,DWORD dwBufLen, DWORD dwUser), DWORD dwUser);

//�������ӳ�ʱʱ��
//DWORD dwTryTimes����
HB_SDVR_API BOOL __stdcall HB_SDVR_SetConnectTime(DWORD dwWaitTime,DWORD dwTryTimes);

//SDK�汾
HB_SDVR_API DWORD __stdcall HB_SDVR_GetSDKVersion();

//ϵͳ�Ƿ�֧��
//���أ��ɹ�-0xFF   ʧ��-0 
HB_SDVR_API int __stdcall HB_SDVR_IsSupport();

HB_SDVR_API LONG __stdcall HB_SDVR_Login(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPHB_SDVR_DEVICEINFO lpDeviceInfo);
HB_SDVR_API LONG __stdcall HB_SDVR_LoginA(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPHB_SDVR_DEVICEINFO lpDeviceInfo);
HB_SDVR_API LONG __stdcall HB_SDVR_LoginW(TCHAR *sDVRIP,WORD wDVRPort,TCHAR *sUserName,TCHAR *sPassword,LPHB_SDVR_DEVICEINFO lpDeviceInfo);

//Ϊ�������128·�������͵���չ�ӿ� 10.05.25
HB_SDVR_API LONG __stdcall HB_SDVR_Login_Nvs(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPHB_SDVR_DEVICEINFO_EX lpDeviceInfo);

/**********************************************************************************
��������HB_SDVR_Login_Ex
��  ��:��¼��չ����������ʹ�û���ε�¼ͬһ��dvr��
��  �����÷�ͬHB_SDVR_Login
***********************************************************************************/
HB_SDVR_API LONG __stdcall HB_SDVR_Login_Ex(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPHB_SDVR_DEVICEINFO lpDeviceInfo);

//����ʹ�û���ε�¼���Ҽ������128·�������͵���չ�ӿ� 10.05.25
HB_SDVR_API LONG __stdcall HB_SDVR_Login_Ex_Nvs(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPHB_SDVR_DEVICEINFO_EX lpDeviceInfo);

//4. ע��
/*
��  �ܣ�ע��
��  ����
sDVRIP�� IP��ַ�û�ID ֵ����HB_SDVR _Login ����
����ֵ��TRUE-�ɹ�	FASLE-ʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_Logout(LONG lUserID);

//5. ʵʱ��Ƶ
/*
��  �ܣ�����Զ����Ƶ
��  ����
lDVRIP�� IP��ַ�û�ID ֵ����NET_DVR_Login ����
lWindows��ͨ����
lpClientInfo��ָ��HB_SDVR_CLIENTINFO�ṹ��ָ��
����ֵ��FASLE-ʧ�� ������ֵ��ʾ������Ƶ����IDֵ����IDֵ����SDK���䣬��ΪHB_SDVR _StopRealPlay�Ⱥ����Ĳ���*/
HB_SDVR_API LONG __stdcall HB_SDVR_RealPlay(LONG lUserID,LONG lWindows,LPHB_SDVR_CLIENTINFO lpClientInfo);
HB_SDVR_API BOOL __stdcall HB_SDVR_UpdataRealPlayWnd(LONG lRealHandle,HWND hPlayWnd);

//6. �ر���Ƶ
/*
��  �ܣ��ر�Զ����Ƶ
��  ����
lRealHandle�� ��Ƶ����IDֵ����HB_SDVR_RealPlay����
����ֵ��TRUE-�ɹ�	FASLE-ʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_StopRealPlay(LONG lRealHandle);
HB_SDVR_API BOOL __stdcall HB_SDVR_StopRealPlayEx(LONG lRealHandle);

//7. ��Ƶ����
/*
��  �ܣ�������Ƶ����
��  ����
lRealHandle�� ��Ƶ����IDֵ����HB_SDVR_RealPlay����
videoeff��ָ��HB_SDVR_VIDEOEFFECT�ṹ��ָ��
����ֵ��TRUE-�ɹ�	FASLE-ʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_ClientSetVideoEffect(LONG lRealHandle,LPHB_SDVR_VIDEOEFFECT videoeff);
HB_SDVR_API BOOL __stdcall HB_SDVR_ClientGetVideoEffect(LONG lRealHandle,LPHB_SDVR_VIDEOEFFECT videoeff);

/*
��  ����
lUserID�� sDVRIP�� IP��ַ�û�ID ֵ����HB_SDVR _Login ����
lChannel��ͨ����
����ֵ��TRUE-�ɹ�	FASLE-ʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_ClientSetVideoEffect_Ex(LONG lUserID, LONG lChannel,LPHB_SDVR_VIDEOEFFECT videoeff);
HB_SDVR_API BOOL __stdcall HB_SDVR_ClientGetVideoEffect_Ex(LONG lUserID, LONG lChannel,LPHB_SDVR_VIDEOEFFECT videoeff);

//8. ����ؼ�֡
/*
��  �ܣ�ʵʱ��Ƶ�в����ؼ�֡
��  ����
lUserID�� sDVRIP�� IP��ַ�û�ID ֵ����HB_SDVR _Login ����
lChannel��ͨ����
����ֵ��TRUE-�ɹ�	FASLE-ʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_MakeKeyFrame(LONG lUserID, LONG lChannel);

//9. ��̨����(͸����̨) 
//��  �ܣ���̨�������Ĭ���ٶȣ�������Ƶ��ID������
//��  ����
//lRealHandle�� ��Ƶ����IDֵ����HB_SDVR_RealPlay����
//dwPTZCommand����������
//#define TM_COM_GUI_BRUSH  0x0001002e   //��ˢ
//#define TILT_UP			0x0001000c	/* ��̨��SS���ٶ����� */
//#define TILT_DOWN		    0x0001000d	/* ��̨��SS���ٶ��¸� */
//#define PAN_LEFT		    0x0001000e 	/* ��̨��SS���ٶ���ת */
//#define PAN_RIGHT		    0x0001000f	/* ��̨��SS���ٶ���ת */
//#define ZOOM_IN			0x00010016	/* �������ٶ�SS���(���ʱ��) */
//#define ZOOM_OUT		    0x00010017 	/* �������ٶ�SS��С(���ʱ�С) */
//#define IRIS_OPEN		    0x00010018 	/* ��Ȧ���ٶ�SS���� */
//#define IRIS_CLOSE		0x00010019	/* ��Ȧ���ٶ�SS��С */
//#define FOCUS_FAR		    0x00010015 	/* �������ٶ�SS��� */
//#define FOCUS_NEAR		0x00010014  /* �������ٶ�SSǰ�� */
//#define LIGHT_PWRON		0x00010024	/* ��ͨ�ƹ��Դ */
//#define WIPER_PWRON		0x00010025	/* ��ͨ��ˢ���� */
//#define PAN_AUTO		    0x0001001c 	/* ��̨��SS���ٶ������Զ�ɨ�� */
//dwStop������ֹ̨ͣ���ǿ�ʼ
//����ֵ��TRUE-�ɹ�	FASLE-ʧ��
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZControl(LONG lRealHandle,DWORD dwPTZCommand,DWORD dwStop);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZControl_Other(LONG lUserID,LONG lChannel,DWORD dwPTZCommand,DWORD dwStop);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZControlWithSpeed(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZControlWithSpeed_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);

//͸����̨
HB_SDVR_API BOOL __stdcall HB_SDVR_TransPTZ(LONG lRealHandle,char *pPTZCodeBuf,DWORD dwBufSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_TransPTZ_Other(LONG lUserID,LONG lChannel,char *pPTZCodeBuf,DWORD dwBufSize);

//��̨��� 
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZPreset(LONG lRealHandle,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZPreset_Other(LONG lUserID,LONG lChannel,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZCruise(LONG lRealHandle,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZCruise_Other(LONG lUserID,LONG lChannel,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZTrack(LONG lRealHandle,DWORD dwPTZTrackCmd);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZTrack_Other(LONG lUserID,LONG lChannel,DWORD dwPTZTrackCmd);

//��չ
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZTrack_EX(LONG lRealHandle,DWORD dwPTZTrackCmd);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZCruise_EX(LONG lRealHandle,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZPreset_EX(LONG lRealHandle,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZControl_EX(LONG lRealHandle,DWORD dwPTZCommand,DWORD dwStop);
HB_SDVR_API BOOL __stdcall HB_SDVR_TransPTZ_EX(LONG lRealHandle,char *pPTZCodeBuf,DWORD dwBufSize);

//2013-10-22 �������
#define MAX_SCH_TASKS_NUM       10      //ÿ����� 10 ��ʱ���
#define MAX_CRUISE_POINT_NUM    64      //ÿ��Ѳ��·����� 64 ��Ԥ�õ�

typedef struct 
{
    DWORD   dwPresetIndex;    	//Ԥ�õ��(�������Чֵ��ΧӰ��)[1, 256] ��0��ʾ��ЧԤ�õ�
    BYTE    byPresetName[NAME_LEN]; 	//Ԥ�õ����ƣ���ִ������/����Ԥ�õ��ʱ��������壬����Ϊ��
    DWORD   dwDomeCommand;      //��������(���±�) Ϊ0x00010028��ֹͣ 
    DWORD   dwSpeed;         	//�����ٶ�[0, 255]��0���ٶ��������ġ� ���ٶ�Ϊ���������ٶȣ�
                                //���ٶȲ�ͬ��Ԥ�õ�Ѳ����Ԥ�õ���ٶ�
    BYTE	reserve[8];			//����
}HB_SDVR_PTZ_CTRL,*LPHB_SDVR_PTZ_CTRL;
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZControlWithNameByChannel(LONG lUserID,LONG lChannel,LPHB_SDVR_PTZ_CTRL lpPtzCtrl);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZControlWithNameByStream(LONG lRealHandle,LPHB_SDVR_PTZ_CTRL lpPtzCtrl);

typedef struct 
{
    BYTE    byChannel;       	//��̨��(��Ӧͨ����) 
    DWORD   dwDomeCommand;      //�������� 
    DWORD   dwValue; 	      	//�����������ֵ	
    BYTE    reserve[3];	      	//����
}HB_SDVR_PTZ_BASIC,*LPHB_SDVR_PTZ_BASIC;
// VIDEO_FREEZE_ENABLE   
// SCALE_TIMES_ENABLE    
// POWER_OFF_MEM_TIME	  
// LEN_TIMES_ENABLE		
// AZIMUTHS_ENABLE		  
// PRESET_CAPTION_ENABLE 
// PRESET_POINT_ALL_CLEAR
// CRUISE_ALL_CLEAR	  
// PATTERN_ALL_CLEAR	  
// LIMIT_ALL_CLEAR		  
// TIME_TASK_ALL_CLEAR	  
// PARK_ALL_CLEAR	      
HB_SDVR_API BOOL __stdcall HB_SDVR_GetPTZBasic(LONG lUserID,LPHB_SDVR_PTZ_BASIC lpPtzBasic);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetPTZBasic(LONG lUserID,LPHB_SDVR_PTZ_BASIC lpPtzBasic);

typedef struct
{
    DWORD   dwPresetIndex;		//Ԥ�õ�id[1-256],0��ʾ��ЧԤ�õ�
    BYTE    byPresetName[NAME_LEN];   //Ԥ�õ�����ƣ������������������ġ�����Ԥ�õ㡱������
    DWORD   dwSpeed;            //Ԥ�õ��ٶȣ���ʾ��ǰԤ�õ㵽��һ��Ԥ�õ��Ѳ���ٶȣ�[0-255]��
    DWORD	dwStopSecond;	    //Ԥ�õ��ͣ��ʱ�䣬[0-3600]�룬0��ʾ��ͣ��
}HB_SDVR_CRUISE_POINT;
//SET_PRE_SEQ 		      
//GET_PRE_SEQ 		      
//RUN_SEQ 				  
//STOP_SEQ                 
typedef struct
{
    DWORD   dwCrusieCommand;	//Ѳ����������
    DWORD   dwCruiseRoute;	    //Ѳ��·�������֧��32��·��[1-32]��Ŀǰֻ֧��8��  
                                //0��ʾ��Ч��Ѳ���飬��ȡѲ������Ϣ��ʱ��0��ʾѲ�������
    BYTE	reserve[4];		    //����			  
    HB_SDVR_CRUISE_POINT   dwCruisePoint[MAX_CRUISE_POINT_NUM];	//Ѳ�����ڵ�Ԥ�õ㣬0��ʾ����Ԥ�õ�Ľ�����־
}HB_SDVR_CRUISE,*LPHB_SDVR_CRUISE;
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZCruiseByChannel(LONG lUserID,LONG lChannel,LPHB_SDVR_CRUISE lpCruise);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZCruiseByStream(LONG lRealHandle,LPHB_SDVR_CRUISE lpCruise);

//GET_RECORD_TRACK_STATUS 	    
//START_RECORD_TRACK            
//STOP_RECORD_TRACK             
//STORE_RECORD_TRACK           
//CLEAR_RECORD_TRACK           
typedef	struct
{	
    BYTE	byGroup;            //�켣������ɨ�裩��ţ�[1-16]   0����ʾɨ���鲻����
    DWORD	dwTrackCommand;	    //�켣��������
    WORD	wRecordFlag;		//�켣������ɨ�裩���¼��״̬��0��ʾδ¼�� 1Ϊ��¼��(λ��¼)
    BYTE    reserve[4];			//����
}HB_SDVR_TRACK, *LPHB_SDVR_TRACK;
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZTrackByChannel(LONG lUserID,LONG lChannel, LPHB_SDVR_TRACK lpTrack);
HB_SDVR_API BOOL __stdcall HB_SDVR_PTZTrackByStream(LONG lRealHandle, LPHB_SDVR_TRACK lpTrack);

typedef struct 
{
    BYTE    byChannel;	        //ͨ����
    BYTE    byEnable;	        //ʹ�ܣ�0-�����ã�1-����
    DWORD   dwParkTime;	        //�����ȴ�ʱ�䣬��λs ȡֵ��Χ[5-3600]
    DWORD   dwActionType;	    //�����������ͣ�0-��Ч��1-Ԥ�õ㣬2-�Զ�ɨ�裬3-֡ɨ�裬4-���ɨ�裬
                                    //5-Ѳ��ɨ�裬6-����ɨ�裬7-ȫ��ɨ�� 8-��ֱɨ��
    DWORD   dwID;		        //��������������ѡ��Ԥ�õ㡢Ѳ��ɨ�衢����ɨ��ʱ��Ӧ�ĵ����ID��
                                    //Ԥ�õ�id�ķ�Χ[1-8];
                                    //Ѳ����id�ķ�Χ[1-8];
                                    //�켣���䣨����ɨ�裩��id [1-4]
    BYTE    reserve[2];			//����
}HB_SDVR_PARK, *LPHB_SDVR_PARK;
HB_SDVR_API BOOL __stdcall HB_SDVR_GetPTZPark(LONG lUserID,LPHB_SDVR_PARK lpPark);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetPTZPark(LONG lUserID,LPHB_SDVR_PARK lpPark);

typedef struct
{
    HB_SDVR_SCHEDTIME 	schedTime;  //��ʼ�ͽ���ʱ�� 
    DWORD	dwActionType;	        //��ʱ������嶯����0-��Ч��1-Ԥ�õ㣬
//2-�Զ�ɨ�裬3-֡ɨ�裬4-���ɨ�裬5-Ѳ��ɨ�裬6-����ɨ�裬7-ȫ��ɨ�� 8-��ֱɨ��
    DWORD	dwID;	                //��������������ѡ��Ԥ�õ㡢Ѳ��ɨ�衢����ɨ���ʱ�򣬶�Ӧ�ĵ����ID��
//��Ԥ�õ�id��Ѳ��ɨ����id���켣���䣨����ɨ�裩��id��
//Ԥ�õ�id�ķ�Χ[1-256];  Ѳ��ɨ����id�ķ�Χ[1-8];�켣���䣨����ɨ�裩��id [1-4]
    BYTE    reserve[4];// ����
}HB_SDVR_SCHEDTASK; 
typedef struct  

{
    BYTE    byChannel;	            //ͨ����	
    BYTE    byTaskEnable;	        //ʹ�� 0-�����ã�1-����
    BYTE    byEveryDayEnable;       //�Ƿ�����ÿ�� 0-���� 1-�� 
    HB_SDVR_SCHEDTASK  schedTask[MAX_DAYS][MAX_SCH_TASKS_NUM];    //8�죬0��ʾÿ�죬1~7��ʾ����һ�������գ�ÿ��10��ʱ��Σ���
//��ÿ��ʱ��ν���ʱ�������ʼʱ�䣬��һ��ʱ�����ʼʱ������϶εĽ���ʱ�䣬����֤������һ��24Сʱ֮�ڡ�
    DWORD	dwRestoreTime;	        //��ʱ����ָ�ʱ�䣬��λ��[5-3600]
    BYTE	reserve[1];	            //����
}HB_SDVR_TIME_TASK, *LPHB_SDVR_TIME_TASK;
HB_SDVR_API BOOL __stdcall HB_SDVR_GetPTZTask(LONG lUserID,LPHB_SDVR_TIME_TASK lpTimeTask);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetPTZTask(LONG lUserID,LPHB_SDVR_TIME_TASK lpTimeTask);

typedef struct  
{
    DWORD   dwLocateStartX;         //��ʼ��ˮƽ����
    DWORD   dwLocateStartY;         //��ʼ�㴹ֱ����
    DWORD   dwLocateEndX;           //������ˮƽ���� 
    DWORD   dwLocateEndY;           //�����㴹ֱ���� 
    DWORD   reserve;                //����
}HB_SDVR_3D_LOCATE_TYPE, *LPHB_SDVR_3D_LOCATE_TYPE;
HB_SDVR_API BOOL __stdcall HB_SDVR_3D_LocateByChannel(LONG lUserID,LONG lChannel,LPHB_SDVR_3D_LOCATE_TYPE lpLocateType);
HB_SDVR_API BOOL __stdcall HB_SDVR_3D_LocateByStream(LONG lRealHandle,LPHB_SDVR_3D_LOCATE_TYPE lpLocateType);


//10.��������
//����
/*
��  �ܣ�Զ���������� 
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
����ֵ�� FASLE-ʧ�� TRUE-�ɹ�*/
HB_SDVR_API BOOL __stdcall HB_SDVR_RebootDVR(LONG lUserID);

//�ر�DVR
/*
��  �ܣ�Զ�̹ر����� 
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
����ֵ�� FASLE-ʧ�� TRUE-�ɹ�*/
HB_SDVR_API BOOL __stdcall HB_SDVR_ShutDownDVR(LONG lUserID);
 
//11.��������
/*
��  �ܣ�Զ���������� 
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
sFileName���������ļ�����·��
����ֵ�� FASLE-ʧ��  ��������������ID*/
HB_SDVR_API LONG __stdcall HB_SDVR_Upgrade(LONG lUserID,char *sFileName);

/*
��  �ܣ�Զ����������״̬ 
��  ����
lUpgradeHandle�� ������ID����HB_SDVR_Upgrade����
����ֵ�� FASLE-ʧ�� 
����ֵ��
-1 �汾���ԣ�����ʧ��
100 ���ݴ�����ɣ��ȴ���������  
101 �������³ɹ�*/
HB_SDVR_API int __stdcall HB_SDVR_GetUpgradeState(LONG lUpgradeHandle);

//�����������ж� �˽ӿڱ���
HB_SDVR_API BOOL __stdcall HB_SDVR_CloseUpgradeHandle(LONG lUpgradeHandle);

//12.�Խ����� 
//�����Խ�
/*
���ܣ����������Խ������ݸ�ʽ
������
��  ����
lUserID��NET_DVR_Login ()�ķ���ֵ
dwEncode���Խ����ݸ�ʽ
NVR ������Ŀǰֻ֧�� PCM��G711��G722 ���ָ�ʽ*/
typedef enum
{
    NET_VOICE_DECODE_G711 = 0,
    NET_VOICE_DECODE_G722,
    NET_VOICE_DECODE_PCM,
    NET_VOICE_DECODE_ADPCM,
    NET_VOICE_DECODE_G726,
    NET_VOICE_DECODE_G721,
    NET_VOICE_DECODE_G723,
    NET_VOICE_DECODE_DPCM,
    NET_VOICE_DECODE_MAX
}NET_VOICE_DECODE_PARAM;

HB_SDVR_API LONG __stdcall HB_SDVR_SetVoiceEncode(LONG lUserID, DWORD dwEncode);

/*
��  �ܣ���ʼ�����Խ�
��  ����
lUserID��NET_DVR_Login ()�ķ���ֵ
fVoiceDataCallBack���ص��������ص���Ƶ����
dwUser���û�����
�ص�����˵����
lVoiceComHandle��HB_SDVR_StartVoiceCom ()�ķ���ֵ
pRecvDataBuffer��������ݵĻ�����ָ��
dwBufSize���������Ĵ�С
byAudioFlag���������� 
0- �ͻ��˲ɼ�����Ƶ����
1- �ͻ����յ��豸�˵���Ƶ����
dwUser���û����ݣ���������������û�����
����ֵ��-1��ʾʧ�ܣ�����ֵ��ΪHB_SDVR _SetVoiceComClientVolume ()�Ⱥ����Ĳ��� */
HB_SDVR_API LONG __stdcall HB_SDVR_StartVoiceCom(LONG lUserID, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle,char *pRecvDataBuffer,DWORD dwBufSize,BYTE byAudioFlag,DWORD dwUser), DWORD dwUser);

/*
��  �ܣ����������Խ�PC �˵�����
��  ����
lVoiceComHandle��HB_SDVR _StartVoiceCom �ķ���ֵ
wVolume�����ú����������0-0xffff
����ֵ��TRUE ��ʾ�ɹ���FALSE ��ʾʧ�ܡ�*/
HB_SDVR_API BOOL __stdcall HB_SDVR_SetVoiceComClientVolume(LONG lVoiceComHandle,WORD wVolume);

/*
��  �ܣ������Խ�
��  ����
lVoiceComHandle��HB_SDVR _StartVoiceCom �ķ���ֵ
����ֵ��TRUE ��ʾ�ɹ���FALSE ��ʾʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_StopVoiceCom(LONG lVoiceComHandle);

//���������㲥
HB_SDVR_API BOOL __stdcall HB_SDVR_ClientAudioStart();
HB_SDVR_API BOOL __stdcall HB_SDVR_ClientAudioStop();
HB_SDVR_API BOOL __stdcall HB_SDVR_AddDVR(LONG lUserID);
HB_SDVR_API BOOL __stdcall HB_SDVR_DelDVR(LONG lUserID);

//13.͸��ͨ��
/*//*�ر�ע�� ����485ͨ����ʱ��һ��Ҫ��232��channel=2����һ�²ſ���
��  �ܣ�����͸��ͨ��
��  ���� 
lUserID��NET_DVR_Login ()�ķ���ֵ
lSerialPort�����ںţ�1-232 ���ڣ�2-485 ����
dwUser���û�����
fSerialDataCallBack���ص�����
�ص�����˵����
lSerialHandle��NET_DVR_SerialStart()�ķ���ֵ
pRecvDataBuffer����Ž��յ����ݵĻ�����ָ��
dwBufSize���������Ĵ�С
dwUser��������û�����
����ֵ��-1��ʾʧ�ܣ�����ֵ��ΪHB_SDVR_SerialSend()�Ⱥ����Ĳ���*/
HB_SDVR_API LONG __stdcall HB_SDVR_SerialStart(LONG lUserID,LONG lSerialPort,void(CALLBACK *fSerialDataCallBack)(LONG lSerialHandle,char *pRecvDataBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);

/*
��  �ܣ�ͨ��͸��ͨ����DVR ���ڷ�������
��  ����lSerialHandle��NET_DVR_SerialStart �ķ���ֵ
lChannel��Ӳ��¼�����ͨ����, ��485 ����͸��ͨ��ʱ��Ч,ָ�����ĸ�ͨ��������,��232 ����͸��ͨ��ʱ���ó�0;
pSendBuf��Ҫ���͵Ļ�������ָ��
dwBufSize���������Ĵ�С
����ֵ��TRUE ��ʾ�ɹ���FALSE ��ʾʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_SerialSend(LONG lSerialHandle, LONG lChannel, char *pSendBuf,DWORD dwBufSize);

/*
���ܣ��Ͽ�͸��ͨ��
����˵����
lSerialHandle��NET_DVR_SerialStart �ķ���ֵ
����ֵ��TRUE ��ʾ�ɹ���FALSE ��ʾʧ�ܡ�*/
HB_SDVR_API BOOL __stdcall HB_SDVR_SerialStop(LONG lSerialHandle);
 
//14.�������
/*
��  �ܣ��������
��  ����
lUserID��  �û�ID ֵ����HB_SDVR _Login ����
lKeyIndex����ֵ*/
#define   TM_COM_GUI_LOGIN        0x00010000 //��¼
#define   TM_COM_GUI_RECORD       0x00010001 //¼��
#define   TM_COM_GUI_PLAYBACK     0x00010002 //�ط�
#define   TM_COM_GUI_SETUP        0x00010003 //����
#define   TM_COM_GUI_BACKUP       0x00010004 //����
#define   TM_COM_GUI_DN           0x00010007 //������
#define   TM_COM_GUI_CN           0x00010008 //����
#define   TM_COM_GUI_BKSPACE      0x0001000b //ɾ��
#define   TM_COM_GUI_UP           0x0001000c //��
#define   TM_COM_GUI_DOWN         0x0001000d //��
#define   TM_COM_GUI_LEFT         0x0001000e //��
#define   TM_COM_GUI_RIGHT        0x0001000f //��
#define   TM_COM_GUI_PAGEUP       0x00010010 //��ҳ
#define   TM_COM_GUI_PAGEDOWN     0x00010011 //��ҳ
#define   TM_COM_GUI_RETURN       0x00010012 //����
#define   TM_COM_GUI_ENTER        0x00010013 //ȷ��
#define   TM_COM_GUI_NEAR         0x00010014 //����ͷ��
#define   TM_COM_GUI_FAR          0x00010015 //����ͷԶ
#define   TM_COM_GUI_ZOOMIN       0x00010016 //����ͷ�佹����ZOOM+��
#define   TM_COM_GUI_ZOOMOUT      0x00010017 //����ͷ�佹Զ��ZOOM-��
#define   TM_COM_GUI_APER_INC     0x00010018 //����ͷ��Ȧ+
#define   TM_COM_GUI_APER_DEC     0x00010019 //����ͷ��Ȧ-
#define   TM_COM_GUI_PRESET_SET   0x0001001a //����ͷԤ��
#define   TM_COM_GUI_PRESET_GET   0x0001001b //����ͷ����
#define   TM_COM_GUI_AUTO         0x0001001c //����ͷ�Զ�
#define   TM_COM_GUI_MUTE         0x0001001d //����
#define   TM_COM_GUI_INFO         0x0001001e //��Ϣ
#define   TM_COM_GUI_STEP         0x0001001f //֡��
#define   TM_COM_GUI_PLAY         0x00010020 //����
#define   TM_COM_GUI_FASTF        0x00010021 //���
#define   TM_COM_GUI_FASTB        0x00010022 //����
#define   TM_COM_GUI_CLRALT       0x00010023 //�������
#define   TM_COM_GUI_F1           0x00010024
#define   TM_COM_GUI_F2           0x00010025
#define   TM_COM_GUI_IGEFORMAT    0x00010026 //�����ʽ
#define   TM_COM_GUI_IGESWITCH    0x00010027 //�����ֻ�
#define   TM_COM_GUI_STOP         0x00010028 
#define   TM_COM_GUI_SHUTDOWN     0x00010029 //�ػ�
#define   TM_COM_GUI_PWDRST       0x0001002a //���븴λ
#define   TM_COM_GUI_F1VGA2TV     0x0001002b //vga������л�
#define   TM_COM_GUI_MOUSESTATUS  0x0001002c //���
#define   TM_COM_GUI_VIDEOPARAM   0x0001002d //��Ƶ����
#define   TM_COM_GUI_VIDEORESTORE 0x0001002e //�ָ���һ�ε���Ļ״̬
#define   TM_COM_GUI_DIGIT        0x00011000 //���֣�����Ϊ0��1��2��3�� 4��5��6��7��8��9��
#define   TM_COM_GUI_CHAR         0x00012000 //�ַ�������ΪA��B��C..X��Y��Z��*��#)
#define   TM_COM_GUI_VIDEOFULL    0x00013000 //���֣�������ȫ��������Ϊ1��2��������9��10��������

/*
����ֵ����FALSE ��ʾʧ�ܣ�TRUE��ʾ�ɹ�*/
HB_SDVR_API BOOL __stdcall HB_SDVR_ClickKey(LONG lUserID,LONG lKeyIndex);

//15.�ֶ�¼��
/*
��  �ܣ���ȡԶ���ֶ�¼��
��  ����
lUserID��   �û�ID ֵ����HB_SDVR _Login ����
lChannel�����յ�λ����λ��˳���ʾͨ����
lRecordType������
����ֵ����FALSE ��ʾʧ�ܣ�TRUE��ʾ�ɹ�*/
HB_SDVR_API BOOL __stdcall HB_SDVR_GetDVRRecord(LONG lUserID,WORD* lChannel,LONG lRecordType);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetDVRRecord_Nvs(LONG lUserID,LPHB_SDVR_REMOTERECORDCHAN lChannel,LONG lRecordType);

/*
��  �ܣ�����Զ���ֶ�¼��
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
lChannel�����յ�λ����λ��˳���ʾͨ����
����ֵ����FALSE ��ʾʧ�ܣ�TRUE��ʾ�ɹ�*/
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDVRRecord(LONG lUserID,WORD  lChannel);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDVRRecord_Nvs(LONG lUserID,LPHB_SDVR_REMOTERECORDCHAN lChannel);

//16.�豸����
//���أ�7004  8004  2004�����ͺ�
 

 //����汾
HB_SDVR_API BOOL __stdcall  HB_SDVR_GetDeviceType(LONG lUserID,LPHB_SDVR_INFO device);
HB_SDVR_API BOOL __stdcall  HB_SDVR_SetDeviceType(LONG lUserID,LPHB_SDVR_INFO device);

/////////////////////////////////////////////////////////////////////////////////////
/*
��  �ܣ���ȡԶ����������
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
dwCommand������
HB_SDVR_GET_DEVICECFG:   �豸Ӳ����Ϣ
HB_SDVR_GET_NETCFG:		 �豸������Ϣ
HB_SDVR_GET_PICCFG:      (��֧��)
HB_SDVR_GET_PICCFG_EX:	 ͨ������(��������¼��,�ƶ�¼���)	 
HB_SDVR_GET_PICCFG_EX_NVS
HB_SDVR_GET_COMPRESSCFG: ����ѹ������
HB_SDVR_GET_RECORDCFG:	 ¼�����
HB_SDVR_GET_DECODERCFG:  ����������(��̨����)
HB_SDVR_GET_RS232CFG:    RS232
HB_SDVR_GET_ALARMINCFG:	 ��������
HB_SDVR_GET_ALARMINCFG_NVS:
HB_SDVR_GET_ALARMOUTCFG: �������	
HB_SDVR_GET_TIMECFG:     ʱ��
HB_SDVR_GET_PREVIEWCFG:  (��֧��)
HB_SDVR_GET_VIDEOOUTCFG:����֧�֣�
HB_SDVR_GET_USERCFG:	 �û�Ȩ��
HB_SDVR_GET_USERCFG_NVS: 
HB_SDVR_GET_USERCFG_EX: ����֧�֣�
HB_SDVR_GET_EXCEPTIONCFG:(��֧��)
HB_SDVR_GET_DNS:         DNS
HB_SDVR_GET_DNS_NVS:    
HB_SDVR_GET_PPPoE:		 PPPoE	
HB_SDVR_SERVERCFG_GET:   ƽ̨��Ϣ
lChannel��ͨ��
lpOutBuffer������������
dwInBufferSize�����������ݴ�С
lpBytesReturned������
type������
����ֵ����FALSE ��ʾʧ�ܣ�TRUE��ʾ�ɹ�*/
HB_SDVR_API BOOL __stdcall HB_SDVR_GetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned,DWORD type);

/*
��  �ܣ�Զ����������
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
dwCommand������
HB_SDVR_SET_DEVICECFG:  �豸Ӳ����Ϣ
.
.
.
HB_SDVR_GERVERCFG_SET:   ƽ̨��Ϣ
lChannel��ͨ��
lpInBuffer������������
dwInBufferSize�����������ݴ�С
����ֵ����FALSE ��ʾʧ�ܣ�TRUE��ʾ�ɹ�*/
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpInBuffer,DWORD dwInBufferSize);

//29.������Ϣ

//30.Զ��¼���ļ���ѯ�͵㲥  ����
/*
��  �ܣ�Զ���ļ��ط�
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
lChannel��ͨ����
dwPTZCommand����������
dwStop������ֹ̨ͣ���ǿ�ʼ
dwSpeed���ٶ�
����ֵ����FALSE ��ʾʧ�ܣ�����ֵ��ΪHB_SDVR _FindClose �Ⱥ����Ĳ���*/
HB_SDVR_API LONG __stdcall HB_SDVR_FindFile(LONG lUserID,LONG lChannel,DWORD dwFileType, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime);
HB_SDVR_API LONG __stdcall HB_SDVR_FindFile_ByCard(LONG lUserID,char * lpcard,DWORD dwFileType, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime);
HB_SDVR_API LONG __stdcall HB_SDVR_FindFileWithChl(LONG lUserID,LONG lChannel,DWORD dwFileType, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime);

/*
��  �ܣ���ȡԶ���ļ�����Ϣ
��  ����
lFindHandle�� �ļ�����IDֵ����HB_SDVR_FindFile���� 
lpFindData�� ָ��HB_SDVR_FIND_DATA�Ľṹ���ָ��
����ֵ����������ֵ
#define HB_SDVR_FILE_SUCCESS				1000	//����ļ���Ϣ
#define HB_SDVR_FILE_NOFIND					1001	//û���ļ�
#define HB_SDVR_ISFINDING					1002	//���ڲ����ļ�
#define	HB_SDVR_NOMOREFILE	                1003	//�����ļ�ʱû�и�����ļ�
#define	HB_SDVR_FILE_EXCEPTION				1004	//�����ļ�ʱ�쳣*/
//¼������
HB_SDVR_API LONG __stdcall HB_SDVR_FindNextFile(LONG lFindHandle,LPHB_SDVR_FIND_DATA lpFindData);
HB_SDVR_API LONG __stdcall HB_SDVR_FindNextFile_ByCard(LONG lFindHandle,LPHB_SDVR_FIND_DATA lpFindData);

/*
��  �ܣ�������ȡԶ���ļ�����Ϣ
��  ����
lFindHandle�� �ļ�����IDֵ����HB_SDVR_FindFile���� 
����ֵ��TRUE-�ɹ�	FASLE-ʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_FindClose(LONG lFindHandle);

/*
��  �ܣ������ļ����ط�
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
Channel��ͨ����
sPlayBackFileName�� Ҫ������ļ�����·��
hWnd����ʾ�Ĵ��ھ��
����ֵ��FASLE-ʧ�� ������ֵ��ʾ������Ƶ����IDֵ����IDֵ����SDK���� */
HB_SDVR_API LONG __stdcall HB_SDVR_PlayBackByName(LONG lUserID,char *sPlayBackFileName, HWND hWnd);

/*
��  �ܣ�����ʱ��λط�
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
Channel��ͨ����
lpStartTime�� ��ʼʱ��
lpStopTime������ʱ��
hWnd����ʾ�Ĵ��ھ��
����ֵ��FASLE-ʧ�� ������ֵ��ʾ������Ƶ����IDֵ����IDֵ����SDK���� */
HB_SDVR_API LONG __stdcall HB_SDVR_PlayBackByTime(LONG lUserID,LONG lChannel, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime, HWND hWnd);

//ʱ��ε㲥
HB_SDVR_API LONG __stdcall HB_SDVR_PlayBackByTime_ex(LONG lUserID,LONG lChannel, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime, HWND hWnd);

//ͨ���Ŵ�0��ʼ
HB_SDVR_API LONG __stdcall HB_SDVR_PlayBackByTime_Name(LONG lUserID,LONG lChannel, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime, HWND hWnd, LPVOID pName);
HB_SDVR_API LONG __stdcall HB_SDVR_PlayBackByTimeWithChl(LONG lUserID,LONG lChannel, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime, HWND hWnd);
HB_SDVR_API LONG __stdcall HB_SDVR_PlayBackByTimeWithChl_ex(LONG lUserID,LONG lChannel, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime, HWND hWnd);

/*
��  �ܣ��طſ���
��  ����
lRealHandle�� ��Ƶ����IDֵ����HB_SDVR_RealPlay���� 
dwControlCode����������
#define HB_SDVR_PLAYSTART		    1//��ʼ����
#define HB_SDVR_PLAYSTOP		    2//ֹͣ����
#define HB_SDVR_PLAYPAUSE		    3//��ͣ����
#define HB_SDVR_PLAYRESTART		    4//�ָ�����
#define HB_SDVR_PLAYFAST		    5//���
#define HB_SDVR_PLAYSLOW		    6//����
#define HB_SDVR_PLAYNORMAL		    7//�����ٶ�
#define HB_SDVR_PLAYFRAME		    8//��֡��
#define HB_SDVR_PLAYSTARTAUDIO		9//������
#define HB_SDVR_PLAYSTOPAUDIO		10//�ر�����
dwInValue��HB_SDVR_PLAYFAST��HB_SDVR_PLAYSLOW��Ҫ�ٶȱ���  ��Χ0-3
lpOutValue������
����ֵ��TRUE-�ɹ�	FASLE-ʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_PlayBackControl(LONG lPlayHandle,DWORD dwControlCode,DWORD dwInValue,DWORD *lpOutValue);

/*
��  �ܣ�ֹͣ�ط� 
��  ����
lRealHandle�� ��Ƶ����IDֵ����HB_SDVR_RealPlay���� 
����ֵ��TRUE-�ɹ�	FASLE-ʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_StopPlayBack(LONG lPlayHandle);

/*
��  �ܣ������ļ������� 
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
sDVRFileName��Զ���ļ����ļ���
sSavedFileName��Ҫ���汾�ص��ļ�����·��
����ֵ��FALSE ��ʾʧ�ܣ�����ֵ��ʾ���ر�������IDֵ����IDֵ����SDK����*/
HB_SDVR_API LONG __stdcall HB_SDVR_GetFileByName(LONG lUserID,char *sDVRFileName,char *sSavedFileName);

/*
��  �ܣ������ļ������� 
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
sDVRFileName��Զ���ļ����ļ���
sSavedFileName��Ҫ���汾�ص��ļ�����·��,���Ϊ�յĻ�,��ʾ�����ļ�������
����ֵ��FALSE ��ʾʧ�ܣ�����ֵ��ʾ���ر�������IDֵ����IDֵ����SDK����*/
HB_SDVR_API LONG __stdcall HB_SDVR_GetFileByName_EX(LONG lUserID,char *sDVRFileName,char *sSavedFileName);

/*
��  �ܣ�����ʱ��α���
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
lChannel��ͨ����
lpStartTime����ʼʱ��
lpStopTime������ʱ��
sSavedFileName��Ҫ���汾�ص��ļ���
����ֵ��FALSE ��ʾʧ�ܣ�����ֵ��ʾ���ر�������IDֵ����IDֵ����SDK����*/
HB_SDVR_API LONG __stdcall HB_SDVR_GetFileByTime(LONG lUserID, LONG lChannel, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime, char *sSavedFileName);
HB_SDVR_API LONG __stdcall HB_SDVR_GetFileByTimeEx(LONG lUserID, LONG lChannel, BYTE byType, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime, char *sSavedFileName);
HB_SDVR_API LONG __stdcall HB_SDVR_GetFileByTimeWithChl(LONG lUserID, LONG lChannel, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime, char *sSavedFileName);

typedef enum
{
    HB_SDVR_RECMANUAL = 1,                           // �ֶ�¼��/�ֶ�ץ��
    HB_SDVR_RECSCHEDULE = 2,                         // ��ʱ¼��/��ʱץ��
    HB_SDVR_RECMOTION = 4,                           // �ƶ����¼��/�ƶ�����ץ��
    HB_SDVR_RECALARM = 8,                            // ����¼��/̽ͷ����ץ��
    HB_SDVR_REC_ALL = 0xff,                          // ����¼��/ȫ��
}HB_SDVR_RECTYPE_E;

//ͼƬ����ʱ��DWORD dwDataType��Ӧֵ
#define HB_SDVR_SNAPSHOT_START 	        0	//���ݿ�ʼ
#define HB_SDVR_SNAPSHOT_FILEHEAD 	    1	//�����ļ�ͷ��ʾ
#define HB_SDVR_SNAPSHOT_DATA 	        2	//����
#define HB_SDVR_SNAPSHOT_END            3   //���ݽ���

typedef void (CALLBACK* PHB_SDVR_STREAMDATA_PROC)(long lRealHandle,DWORD dwDataType, 
                                                  BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser);

// ������ʱ��Ϊ0ʱ���ӿ�ʼʱ����������ط�
// ����ʱ����ڿ�ʼʱ�䣬�ط�ʱ�����¼��
// by name ---->���ļ���������time/channel
typedef struct
{
    DWORD   dwSize;
    DWORD   dwChannel;	            //ͨ���� 0��ʼ
    DWORD   dwRecordType;           //¼������ 
    DWORD   dwStreamType;			//�������� 0-������ 1-������
    HB_SDVR_TIME struStartTime;		//��ʼʱ��
    HB_SDVR_TIME struStopTime;		//����ʱ�� ��Ϊ��
    HWND    hWnd;                   //���ھ��
    PHB_SDVR_STREAMDATA_PROC    pfnDataProc;
    void*   pContext;
    DWORD   dwReserve[4];
}HB_SDVR_PLAYBACK_DATA, *LPHB_SDVR_PLAYBACK_DATA;	

HB_SDVR_API LONG __stdcall HB_SDVR_PlayBack(LONG lUserID, LPHB_SDVR_PLAYBACK_DATA lpPlayBack);

typedef struct ST_HB_SDVR_FILEGETCOND
{
    DWORD               dwSize;
    DWORD               dwChannel;      // ͨ����
    HB_SDVR_RECTYPE_E   dwFileType;     // �ļ�����
    HB_SDVR_TIME        struStartTime;  // ����ʱ��ο�ʼʱ��
    HB_SDVR_TIME        struStopTime;   // ����ʱ��
    PHB_SDVR_STREAMDATA_PROC    pfnDataProc;
    void*               pContext;
    char*               pSaveFilePath;  //����·��
    DWORD               dwResever[4];
}HB_SDVR_FILEGETCOND, *LPHB_SDVR_FILEGETCOND;

HB_SDVR_API LONG __stdcall HB_SDVR_GetFile(LONG lUserID, LPHB_SDVR_FILEGETCOND pGetFile);


typedef struct
{
    BYTE  byChannel;            //ͨ����[0, n��1]��n:ͨ����
    BYTE  byType;               //��ѯ��ͼƬ���ͣ��±���ֵ��ͼƬ���Ͷ�Ӧ��ϵ
    BYTE  byPicFormat;          //ͼƬ��ʽ��0--jpg��1-bmp��Ŀǰֻ���� jpg ��ʽ
    HB_SDVR_TIME  starttime;    //��ѯ�Ŀ�ʼʱ��
    HB_SDVR_TIME  endtime;      //��ѯ�Ľ���ʱ��
    BYTE  byReverse[7];          //����
}HB_SDVR_SNAPSHOTFIND,*LPHB_SDVR_SNAPSHOTFIND;

typedef struct
{
    HB_SDVR_TIME struTime;	    //ͼƬ��ץ��ʱ��
    UINT nSize;		            //ͼƬ�Ĵ�С
    BYTE byChannel;			    //ץ�ĵ�ͨ����
    BYTE byType;			    //ͼƬ���� 1--�ֶ���2--��ʱ��4--�ƶ���8--̽ͷ��0xff--ȫ��
    BYTE byPicFormat;			//ͼƬ��ʽ 0--jpg��1-bmp��Ŀǰֻ���� jpg ��ʽ
    char sFileName[100];	    //�ļ���
    BYTE byReserve[5];
}HB_SDVR_FIND_SNAPDATA,*LPHB_SDVR_FIND_SNAPDATA;		

/*
��  �ܣ�Զ��ͼƬ��ѯ
��  ����
lUserID��  IP��ַ�û�IDֵ����HB_SDVR _Login ����
lpFindSnapShot�� ָ��HB_SDVR_SNAPSHOTFIND�Ľṹ���ָ��
����ֵ��FASLE-ʧ�� ������ֵ��ʾ�����ļ�����IDֵ*/
HB_SDVR_API LONG __stdcall HB_SDVR_FindSnapShot(LONG lUserID,LPHB_SDVR_SNAPSHOTFIND lpFindSnapShot);

/*
��  �ܣ�Զ��ͼƬ��ѯ
��  ����
lFindHandle��  �ļ�����IDֵ����HB_SDVR_FindSnapShot ����
lpFindData�� ָ��HB_SDVR_FIND_SNAPDATA�Ľṹ���ָ��
����ֵ����������ֵ
#define HB_SDVR_FILE_SUCCESS				1000	//����ļ���Ϣ
#define HB_SDVR_FILE_NOFIND					1001	//û���ļ�
#define HB_SDVR_ISFINDING					1002	//���ڲ����ļ�
#define	HB_SDVR_NOMOREFILE	                1003	//�����ļ�ʱû�и�����ļ�
#define	HB_SDVR_FILE_EXCEPTION				1004	//�����ļ�ʱ�쳣*/
HB_SDVR_API LONG __stdcall HB_SDVR_FindNextSnapShot(LONG lFindHandle,LPHB_SDVR_FIND_SNAPDATA lpFindData);

/*
��  �ܣ�Զ��ͼƬ����
��  ����
lUserID��  IP��ַ�û�IDֵ����HB_SDVR _Login ����
pGetFile�� ָ��HB_SDVR_FILEGETCOND�Ľṹ���ָ��
����ֵ��FASLE-ʧ�� ������ֵ��ʾ�����ļ�����IDֵ*/
HB_SDVR_API LONG __stdcall HB_SDVR_GetSnapShot(LONG lUserID, LPHB_SDVR_FILEGETCOND pGetFile);

/*
��  �ܣ�ֹͣ���� 
��  ����
lFileHandle�� ��HB_SDVR_GetFileByTime��HB_SDVR_GetFileByName��HB_SDVR_GetSnapShot���� 
����ֵ��TRUE-�ɹ�	FASLE-ʧ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_StopGetFile(LONG lFileHandle);

/*
��  �ܣ������ܵ����ݴ�С  
��  ����
lFileHandle�� ��������IDֵ����HB_SDVR_GetFileByTime��HB_SDVR_GetFileByName���� 
����ֵ�� FASLE-ʧ�� ����ֵΪ������ ��λΪ K*/
HB_SDVR_API DWORD __stdcall HB_SDVR_GetDownloadTotalSize(LONG lFileHandle);

/*
��  �ܣ������Ѿ����ܵ�������  
��  ����
lFileHandle�� ��������IDֵ����HB_SDVR_GetFileByTime��HB_SDVR_GetFileByName���� 
����ֵ�� FASLE-ʧ�� ����ֵΪ������ ��λΪ K*/
HB_SDVR_API int __stdcall HB_SDVR_GetDownloadPos(LONG lFileHandle);

/*
��  �ܣ������Ѿ����ܵ�������  
��  ����
lFileHandle�� ��������IDֵ����HB_SDVR_GetFileByTime��HB_SDVR_GetFileByName���� 
����ֵ�� FASLE-ʧ�� ����ֵΪ������ ��λΪ B*/
HB_SDVR_API double __stdcall HB_SDVR_GetDownloadBytesSize(LONG lFileHandle);	//cwh 20080806

//31.Զ�̷���������״̬
/*
��  �ܣ�������״̬
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
lpWorkState��ָ��HB_SDVR_WORKSTATE�Ľṹ��ָ��
����ֵ����FALSE ��ʾʧ�ܣ�TRUE��ʾ�ɹ�*/
HB_SDVR_API BOOL __stdcall HB_SDVR_GetDVRWorkState(LONG lUserID,LPHB_SDVR_WORKSTATE lpWorkState);
//�������128·����չ�ӿ�
HB_SDVR_API BOOL __stdcall HB_SDVR_GetDVRWorkState_Nvs(LONG lUserID,LPHB_SDVR_WORKSTATE_EX lpWorkState);

//�����
HB_SDVR_API BOOL __stdcall HB_SDVR_GetDVRWorkState_RsvdPart(LONG lUserID,LPHB_SDVR_WORKSTATE_CUSTOM lpWorkState);
HB_SDVR_API LONG __stdcall HB_SDVR_FormatDisk_RsevPart(LONG lUserID,LPHB_SDVR_FORMAT_CUSTOM lpFormat);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetFormatProgress_RsevPart(LONG lFormatHandle,LONG *pCurrentFormatDisk,LONG *pCurrentDiskPos,LONG *pFormatStatic);
//end

//33.��־
/*
��  �ܣ���ѯ��־
��  ����
lUserID��  IP��ַ�û�ID ֵ����HB_SDVR _Login ����
lpStartTime����ʼʱ��
lpStopTime������ʱ��
����ֵ����FALSE ��ʾʧ�ܣ�����������־ID��
*/
HB_SDVR_API LONG __stdcall HB_SDVR_FindDVRLog(LONG lUserID, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime);

/*
��  �ܣ���һ����־
��  ����
lLogHandle��   ��־ID ֵ����HB_SDVR_FindDVRLog����
lpLogData��һ����־��Ϣ
nlanguage:���� 0�����ģ�1��Ӣ�ġ�
����ֵ����FALSE ��ʾʧ�ܣ�TRUE��ʾ�ɹ�*/
HB_SDVR_API LONG __stdcall HB_SDVR_FindNextLog(LONG lLogHandle,char *lpLogData,int nlanguage = 0);

/*
��  �ܣ�������������
��  ����
lLogHandle��   ��־ID ֵ����HB_SDVR_FindDVRLog����
����ֵ����FALSE ��ʾʧ�ܣ�TRUE��ʾ�ɹ�*/
HB_SDVR_API BOOL __stdcall HB_SDVR_FindLogClose(LONG lLogHandle);

//34.��Ԥ�õ���Ѳ
//#define   NET_SDVR_SET_PRESETPOLL   0x73
//#define   NET_SDVR_GET_PRESETPOLL   0x74
HB_SDVR_API BOOL __stdcall  HB_SDVR_GET_PRESETPOLL (LONG lUserID,  LPHB_SDVR_PRESETPOLL presetpoll);
HB_SDVR_API BOOL __stdcall  HB_SDVR_SET_PRESETPOLL  (LONG lUserID, LPHB_SDVR_PRESETPOLL presetpoll);
						
//35.N/P���л�
//#define   NET_SDVR_SET_VIDEOSYS       0x75
//#define   NET_SDVR_GET_VIDEOSYS       0x76
//ֻ��һ���ֽڴ�����Ƶ��ʽֵ��1---PAL��2---NTSC4.43  3--NTSC3.58
HB_SDVR_API BOOL __stdcall  HB_SDVR_GET_VIDEOSYS  (LONG lUserID,BYTE* videosys);
HB_SDVR_API BOOL __stdcall  HB_SDVR_SET_VIDEOSYS  (LONG lUserID,BYTE videosys);

//����
//ˢ��������������
HB_SDVR_API BOOL __stdcall HB_SDVR_REFRESH_FLASH(LONG lUserID);

//��������
HB_SDVR_API BOOL __stdcall HB_SDVR_OpenSound(LONG lRealHandle);

//�ر�����
HB_SDVR_API BOOL __stdcall HB_SDVR_CloseSound();

//��������
HB_SDVR_API BOOL __stdcall HB_SDVR_OpenSoundShare(LONG lRealHandle);

//�ر�����
HB_SDVR_API BOOL __stdcall HB_SDVR_CloseSoundShare(LONG lRealHandle);

//�������� 
HB_SDVR_API BOOL __stdcall HB_SDVR_Volume(LONG lRealHandle,WORD wVolume);

//����¼��
HB_SDVR_API BOOL __stdcall HB_SDVR_SaveRealData(LONG lRealHandle,char *sFileName);

//ֹͣ����¼��
HB_SDVR_API BOOL __stdcall HB_SDVR_StopSaveRealData(LONG lRealHandle);

//����ʵʱ�����ݻص�
HB_SDVR_API BOOL __stdcall HB_SDVR_SetRealDataCallBack(LONG lRealHandle,void(CALLBACK *fRealDataCallBack) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);

//����ʵʱԭʼ���ݴ�֡��Ϣ�ص�
HB_SDVR_API BOOL __stdcall HB_SDVR_SetRealDataCallBack_Ex(LONG lRealHandle,void(CALLBACK *fRealDataCallBack) (LONG lRealHandle,  PFRAMEINFO pFarmeInfo, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);

//ץͼ
HB_SDVR_API BOOL __stdcall HB_SDVR_CapturePicture(LONG lRealHandle,char *sPicFileName);

//������
HB_SDVR_API BOOL __stdcall  HB_SDVR_SetDecMode(BOOL bSDKDec ); //ȫ�֣���7000SDK�У���ʹ���ڲ����뺯��

//�������
HB_SDVR_API BOOL __stdcall  HB_SDVR_ClearAlarm(LONG lUserID);

//���û�ȡ���к�
HB_SDVR_API BOOL __stdcall  HB_SDVR_GetSEQ(LONG lUserID,char *buff,DWORD dwBufSize);
HB_SDVR_API BOOL __stdcall  HB_SDVR_SetSEQ(LONG lUserID,char *buff,DWORD dwBufSize);

//��Ƶ��ʧ״̬  ��λ
HB_SDVR_API USHORT __stdcall  HB_SDVR_GET_VideoLostStatus(LONG lUserID );

//�������128·���ͻ��� add by cui for 7024 or nvs 100325
HB_SDVR_API BOOL   __stdcall  HB_SDVR_GET_VideoLostStatus_Nvs(LONG lUserID ,LPHB_SDVR_VODLOST lpVodLost);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDownDataCallBack(LONG lFileHandle,void(CALLBACK *fRealDataCallBack) (LONG lFileHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
HB_SDVR_API BOOL __stdcall  HB_SDVR_GetPicFromDVR(LONG lUserID,USHORT channel,char *sPicFileName);
HB_SDVR_API BOOL __stdcall  HB_SDVR_GetDelayPicFromDVR(LONG lUserID,USHORT channel,char *sPicFileName);
HB_SDVR_API BOOL __stdcall  HB_SDVR_RegisterDrawDCFun(long lRealHandle,void (CALLBACK* DrawDCFun)(long nChl,HDC hDc,long nReserved),long nReserved);

//�ص�ʱָ�������ʽ
#define SDVR_OUT_FMT_YUV_420 0x00000601                  // YUV_420
#define SDVR_OUT_FMT_YUV_422 0x00000102                  // YUV_422

//�����ص� ��ȡ��������ݺ�ʱ�䣬֡
typedef HB_FRAME_INFO FRAME_INFO;

//ʵʱ���ݻص�  ���������� ֡��Ϣ����ʱ��
HB_SDVR_API BOOL __stdcall  HB_SDVR_SetRealDecCallBack(LONG lRealHandle,void(CALLBACK *DecCBFun) (long nChl, char * pBuf, long nSize, FRAME_INFO * pFrameInfo, long nReserved1, long nReserved2, long dwUser),long nOutFormat,long dwUser);

//�㲥���ݻص�
HB_SDVR_API BOOL __stdcall  HB_SDVR_SetPlayDecCallBack(LONG lRealHandle,void(CALLBACK *DecCBFun) (long nChl, char * pBuf, long nSize, FRAME_INFO * pFrameInfo, long nReserved1, long nReserved2, long dwUser),long nOutFormat,long dwUser);
typedef HB_VIDEO_TIME VIDEO_TIME;

//ԭʼ������ ��֡ �Ұ���֡��Ϣ
HB_SDVR_API BOOL __stdcall  HB_SDVR_SetParseCallBack(LONG lRealHandle,void (CALLBACK* SrcDataParseCBFun)(long nChl,char *SrcDataBuf,long nSize,long nFrameType,VIDEO_TIME ets,long user),long nRseserved);
HB_SDVR_API BOOL __stdcall  HB_SDVR_SetParseCallBack_Ex(LONG lRealHandle,void (CALLBACK* SrcDataParseCBFun)(long nChl, const HB_FRAME* pFrame, LPVOID pContext ),long dwUser);
 
//���ػص�
HB_SDVR_API BOOL __stdcall  HB_SDVR_SetDownloadCallBack(LONG lFileHandle,void (CALLBACK* SrcDataParseCBFun)(long nChl,char *SrcDataBuf,long nSize,long nFrameType, VIDEO_TIME ets,long user),long nReserved1);
HB_SDVR_API BOOL __stdcall  HB_SDVR_SetDownloadCallBackEx(LONG lFileHandle,void (CALLBACK* SrcDataParseCBFun)(long nChl, const HB_FRAME* pFrame, LPVOID pContext ),long dwUser);


////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*��ӿڱ���   20080702*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
HB_SDVR_API BOOL __stdcall HB_SDVR_RegisterDrawFun(LONG lRealHandle,void (CALLBACK* fDrawFun)(LONG lRealHandle,HDC hDc,LONG dwUser),DWORD dwUser);
HB_SDVR_API BOOL __stdcall HB_SDVR_RigisterDrawFun(LONG lRealHandle,void (CALLBACK* fDrawFun)(LONG lRealHandle,HDC hDc,LONG dwUser),DWORD dwUser);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetPlayerBufNumber(LONG lRealHandle,DWORD dwBufNum);
HB_SDVR_API BOOL __stdcall HB_SDVR_ThrowBFrame(LONG lRealHandle,DWORD dwNum);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetAudioMode(DWORD dwMode);

HB_SDVR_API BOOL __stdcall HB_SDVR_SetPlayDataCallBack(LONG lPlayHandle,void(CALLBACK *fPlayDataCallBack) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
HB_SDVR_API BOOL __stdcall HB_SDVR_PlayBackSaveData(LONG lPlayHandle,char *sFileName);
HB_SDVR_API BOOL __stdcall HB_SDVR_StopPlayBackSave(LONG lPlayHandle);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetPlayBackOsdTime(LONG lPlayHandle, LPHB_SDVR_TIME lpOsdTime);
HB_SDVR_API DWORD __stdcall HB_SDVR_GetPlayBackDTS(LONG lPlayHandle); 
HB_SDVR_API BOOL __stdcall HB_SDVR_PlayBackCaptureFile(LONG lPlayHandle,char *sFileName);
HB_SDVR_API BOOL __stdcall HB_SDVR_RestoreConfig(LONG lUserID);
HB_SDVR_API BOOL __stdcall HB_SDVR_SaveConfig(LONG lUserID);
HB_SDVR_API LONG __stdcall HB_SDVR_FormatDisk(LONG lUserID,LONG lDiskNumber);

// LONG *pCurrentFormatDisk,���ڸ�ʽ����Ӳ�̺�[0, 15]
// LONG *pCurrentDiskPos,���ڸ�ʽ����Ӳ�̽���[0, 100]
// LONG *pFormatStatic,��ʽ��״̬ 
/*0�����ڸ�ʽ����
1����ʽ����ɣ�
2����ʽ������
3��Ҫ��ʽ����Ӳ�̲����ڣ�
4��ʽ����;����
5���������ڱ�ʹ��*/
HB_SDVR_API BOOL __stdcall HB_SDVR_GetFormatProgress(LONG lFormatHandle,LONG *pCurrentFormatDisk,LONG *pCurrentDiskPos,LONG *pFormatStatic);
HB_SDVR_API BOOL __stdcall HB_SDVR_CloseFormatHandle(LONG lFormatHandle);
HB_SDVR_API LONG __stdcall HB_SDVR_SetupAlarmChan(LONG lUserID);
HB_SDVR_API BOOL __stdcall HB_SDVR_CloseAlarmChan(LONG lAlarmHandle);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetAlarmOut(LONG lUserID,LPHB_SDVR_ALARMOUTSTATUS lpAlarmOutState);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetAlarmOut(LONG lUserID,LONG lAlarmOutPort,LONG lAlarmOutStatic);
HB_SDVR_API void* __stdcall HB_SDVR_InitG722Decoder(int nBitrate);
HB_SDVR_API void __stdcall HB_SDVR_ReleaseG722Decoder(void *pDecHandle);
HB_SDVR_API BOOL __stdcall HB_SDVR_DecodeG722Frame(void *pDecHandle, unsigned char* pInBuffer, unsigned char* pOutBuffer);
HB_SDVR_API void* __stdcall HB_SDVR_InitG722Encoder();
HB_SDVR_API BOOL __stdcall HB_SDVR_EncodeG722Frame(void *pEncodeHandle,unsigned char* pInBuffer, unsigned char* pOutBuffer);
HB_SDVR_API void __stdcall HB_SDVR_ReleaseG722Encoder(void *pEncodeHandle);

HB_SDVR_API DWORD __stdcall HB_SDVR_GetLastError();

HB_SDVR_API BOOL __stdcall HB_SDVR_InitDevice_Card(long *pDeviceTotalChan);
HB_SDVR_API BOOL __stdcall HB_SDVR_ReleaseDevice_Card();
HB_SDVR_API BOOL __stdcall HB_SDVR_InitDDraw_Card(HWND hParent,COLORREF colorKey);
HB_SDVR_API BOOL __stdcall HB_SDVR_ReleaseDDraw_Card();
HB_SDVR_API LONG __stdcall HB_SDVR_RealPlay_Card(LONG lUserID,LPHB_SDVR_CARDINFO lpCardInfo,long lChannelNum);
HB_SDVR_API BOOL __stdcall HB_SDVR_ResetPara_Card(LONG lRealHandle,LPHB_SDVR_DISPLAY_PARA lpDisplayPara);
HB_SDVR_API BOOL __stdcall HB_SDVR_RefreshSurface_Card();
HB_SDVR_API BOOL __stdcall HB_SDVR_ClearSurface_Card();
HB_SDVR_API BOOL __stdcall HB_SDVR_RestoreSurface_Card();
HB_SDVR_API BOOL __stdcall HB_SDVR_OpenSound_Card(LONG lRealHandle);
HB_SDVR_API BOOL __stdcall HB_SDVR_CloseSound_Card(LONG lRealHandle);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetVolume_Card(LONG lRealHandle,WORD wVolume);
HB_SDVR_API BOOL __stdcall HB_SDVR_AudioPreview_Card(LONG lRealHandle,BOOL bEnable);
HB_SDVR_API BOOL __stdcall HB_SDVR_CapturePicture_Card(LONG lRealHandle, char *sPicFileName);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDspErrMsg_Card(UINT nMessage,HWND hWnd);
HB_SDVR_API BOOL __stdcall HB_SDVR_ResetDSP_Card(long lChannelNum);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetSerialNum_Card(long lChannelNum,DWORD *pDeviceSerialNo);
HB_SDVR_API HANDLE __stdcall HB_SDVR_GetChanHandle_Card(LONG lRealHandle);

HB_SDVR_API BOOL __stdcall HB_SDVR_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPHB_SDVR_JPEGPARA lpJpegPara, char *sPicFileName);

HB_SDVR_API BOOL __stdcall HB_SDVR_GetConfigFile(LONG lUserID, char *sFileName);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetConfigFile(LONG lUserID, char *sFileName);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetConfigFile_EX(LONG lUserID, char *sOutBuffer, DWORD dwOutSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetConfigFile_EX(LONG lUserID, char *sInBuffer, DWORD dwInSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_SetTrainInfo(LONG lUserID,LPVOID lpTrainInfoBuf,DWORD dwTrainInfolen);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetTrainInfo(LONG lUserID,LPVOID lpTainOutInfoBuf,DWORD dwTrainOutInfolen, LPDWORD lpBytesReturned);
HB_SDVR_API LONG __stdcall HB_SDVR_FindFileByTrainRunFlag(LONG lUserID, LONG lChannel, DWORD dwFileType, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime);

HB_SDVR_API BOOL __stdcall HB_SDVR_SetOEMInfo(LONG lUserID,LPVOID lpOEMInfoBuf,DWORD dwOEMInfolen);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetOEMInfo(LONG lUserID,LPVOID lpOEMOutInfoBuf,DWORD dwOEMOutInfolen, LPDWORD lpBytesReturned);

HB_SDVR_API LONG __stdcall HB_SDVR_StartVoiceCom_MR(LONG lUserID, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle,char *pRecvDataBuffer,DWORD dwBufSize,BYTE byAudioFlag,DWORD dwUser), DWORD dwUser);
HB_SDVR_API BOOL __stdcall HB_SDVR_VoiceComSendData(LONG lVoiceComHandle,char *pSendBuf,DWORD dwBufSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_SetDecInfo(LONG lUserID, LONG lChannel, LPHB_SDVR_DECCFG lpDecoderinfo);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetDecInfo(LONG lUserID, LONG lChannel, LPHB_SDVR_DECCFG lpDecoderinfo);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDecTransPort(LONG lUserID, LPHB_SDVR_PORTCFG lpTransPort);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetDecTransPort(LONG lUserID, LPHB_SDVR_PORTCFG lpTransPort); 
HB_SDVR_API BOOL __stdcall HB_SDVR_DecPlayBackCtrl(LONG lUserID, LONG lChannel, DWORD dwControlCode, DWORD dwInValue,DWORD *lpOutValue, LPHB_SDVR_PLAYREMOTEFILE lpRemoteFileInfo);
HB_SDVR_API BOOL __stdcall HB_SDVR_StartDecSpecialCon(LONG lUserID, LONG lChannel, LPHB_SDVR_DECCHANINFO lpDecChanInfo);
HB_SDVR_API BOOL __stdcall HB_SDVR_StopDecSpecialCon(LONG lUserID, LONG lChannel, LPHB_SDVR_DECCHANINFO lpDecChanInfo);
HB_SDVR_API BOOL __stdcall HB_SDVR_DecCtrlDec(LONG lUserID, LONG lChannel, DWORD dwControlCode);
HB_SDVR_API BOOL __stdcall HB_SDVR_DecCtrlScreen(LONG lUserID, LONG lChannel, DWORD dwControl);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetDecCurLinkStatus(LONG lUserID, LONG lChannel, LPHB_SDVR_DECSTATUS lpDecStatus);

HB_SDVR_API BOOL __stdcall HB_SDVR_ClientGetframeformat(LONG lUserID, LPHB_SDVR_FRAMEFORMAT lpFrameFormat);
HB_SDVR_API BOOL __stdcall HB_SDVR_ClientSetframeformat(LONG lUserID, LPHB_SDVR_FRAMEFORMAT lpFrameFormat);
HB_SDVR_API LONG __stdcall HB_SDVR_FindFileByCard(LONG lUserID,LONG lChannel,DWORD dwFileType, BOOL bNeedCardNum, BYTE *sCardNumber, LPHB_SDVR_TIME lpStartTime, LPHB_SDVR_TIME lpStopTime);

HB_SDVR_API BOOL __stdcall HB_SDVR_StartListen(char *sLocalIP,WORD wLocalPort);
HB_SDVR_API BOOL __stdcall HB_SDVR_StopListen();

HB_SDVR_API BOOL __stdcall HB_SDVR_SetShowMode(DWORD dwShowType,COLORREF colorKey);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetDVRIPByResolveSvr(char *sServerIP, WORD wServerPort, BYTE *sDVRName,WORD wDVRNameLen,BYTE *sDVRSerialNumber,WORD wDVRSerialLen,char* sGetIP);

HB_SDVR_API BOOL __stdcall HB_SDVR_RealPlayPause(LONG lRealHandle);
HB_SDVR_API BOOL __stdcall HB_SDVR_RealPlayRestart(LONG lRealHandle, HWND hPlayWnd);
HB_SDVR_API BOOL __stdcall HB_SDVR_SendTo232Port(LONG lUserID,char *pSendBuf,DWORD dwBufSize);

HB_SDVR_API BOOL __stdcall  HB_SDVR_GET_PRESETPOLL (LONG lUserID,  LPHB_SDVR_PRESETPOLL presetpoll) ;
HB_SDVR_API BOOL __stdcall  HB_SDVR_SET_PRESETPOLL  (LONG lUserID, LPHB_SDVR_PRESETPOLL presetpoll) ;
HB_SDVR_API BOOL __stdcall  HB_SDVR_GET_VIDEOSYS  (LONG lUserID,BYTE* videosys) ;
HB_SDVR_API BOOL __stdcall  HB_SDVR_SET_VIDEOSYS  (LONG lUserID,BYTE  videosys) ;
HB_SDVR_API BOOL __stdcall  HB_SDVR_RegisterEndPlayCallback
(void (CALLBACK* endplayCallBk)(DWORD playwnd,long nReserved1, long nReserved2),long nReserved);

/*
���ܣ�����ľֲ��Ŵ�
���룺lPlayHandle ���ž����nRegionNum ��ʾ������ţ�����1��3����pSrcRect Ҫ�Ŵ������
		hdestWnd ��ʾ��Ƶ�Ĵ��ھ����bEnable 1��ʾ 0����ʾ��
*/
HB_SDVR_API	BOOL __stdcall HB_SDVR_SetDisplayRegion(LONG lPlayHandle,DWORD nRegionNum,RECT *pSrcRect,HWND hdestWnd,BOOL bEnable);

HB_SDVR_API	BOOL __stdcall HB_SDVR_GetPictureSize(LONG lPlayHandle, long *pWidth, long *pHeight);

HB_SDVR_API	BOOL __stdcall HB_SDVR_SetPicQuality(LONG lPlayHandle,BOOL bHighQuality);
HB_SDVR_API	BOOL __stdcall HB_SDVR_GetPicQuality(LONG lPlayHandle,BOOL *bHighQuality);

HB_SDVR_API BOOL __stdcall HB_SDVR_SetPTZProtocol(LONG lUserID,
												  LPSTRUCT_SDVR_DECODERCUSTOMIZE lpStructPtzProtocol,
												  LONG lSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_GetPTZProtocol(LONG lUserID,
												  LPSTRUCT_SDVR_DECODERCUSTOMIZE lpStructPtzProtocol,
												  LONG lSize);
//�ָ�DVRȱʡ��������
//nType: 0:����ȱʡ;1:����ȱʡ.
HB_SDVR_API BOOL __stdcall  HB_SDVR_RecoverDefault(LONG lUserID,BYTE nType);

HB_SDVR_API BOOL __stdcall HB_SDVR_GetPTZType(LONG lUserID,
												  LPSTRUCT_SDVR_PTZTYPE lpStructPtzType,
												  LONG lSize);
//��ʱ����
/**********************************************************
������
	lUserID����½ID
	struParam��STRUCT_ALARMIN_WAIT�ṹ��
����ֵ��
	TRUE���ɹ���
	FALSE��ʧ�ܡ�
***********************************************************/
HB_SDVR_API BOOL __stdcall  HB_SDVR_SetDelayDefence(LONG lUserID,STRUCT_ALARMIN_WAIT struParam);

//��ȡ����״̬
/**********************************************************
������
	lUserID����½ID
	struParam��STRUCT_ALARMIN_WAIT�ṹ��
����ֵ��
	TRUE���ɹ���
	FALSE��ʧ�ܡ�
***********************************************************/
HB_SDVR_API BOOL __stdcall  HB_SDVR_GetDelayDefence(LONG lUserID,LPSTRUCT_ALARMIN_WAIT pStruParam);

//***********************����֧��
HB_SDVR_API BOOL __stdcall HB_SDVR_GetIpcConfig(LONG lUserID,LPSTRUCT_SDVR_IPCCONFIG pStruIpcParam);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetIpcConfig(LONG lUserID,LPSTRUCT_SDVR_IPCCONFIG pStruIpcParam);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetIpcPicConfig(LONG lUserID,LPSTRUCT_SDVR_IPCPIC pStruIpcPic);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetIpcPicConfig(LONG lUserID,LPSTRUCT_SDVR_IPCPIC pStruIpcPic);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetIpcAgcConfig(LONG lUserID,LPSTRUCT_SDVR_IPCAGC pStruIpcAgc);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetIpcAgcConfig(LONG lUserID,LPSTRUCT_SDVR_IPCAGC pStruIpcAgc);
//***********************

/*
���ܣ�����IPC���߲�������
STRUCT_SDVR_IPCWIRELESS
������ 
����ֵ���ɹ�ture ʧ��false
*/
HB_SDVR_API	BOOL __stdcall HB_SDVR_SetIPCWirelessSet(LONG lUserID, LPSTRUCT_SDVR_IPCWIRELESS pStruIpcWireless);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetIPCWirelessSet(LONG lUserID,LPSTRUCT_SDVR_IPCWIRELESS pStruIpcWireless);

//��7000sdk�ӿ�
HB_SDVR_API BOOL __stdcall HB_SDVR_SetIPCWirelessGet(LONG lUserID,LPSTRUCT_SDVR_IPCWIRELESS pStruIpcWireless);

/*********************************************************************************
���ܣ�����ouerlayģʽ��
����: bOverlayMode[In] : ΪTRUE ��ʾ����Overlay ģʽ, �������Overlay
		ƽ��ʧ��,���Զ�����������ʾģʽ.
		colorKey [In] : Ҫ���õ�͸��ɫ. ͸��ɫ�൱��һ��͸��Ĥ����ʾ��
		����ֻ�ܴ���������ɫ������������ɫ����ס��ʾ�Ļ���.�û�Ӧ������ʾ����
		��Ϳ��������ɫ���������ܿ�����ʾ����.һ��Ӧ��ʹ��һ�ֲ����õ���ɫ��Ϊ
		͸��ɫ.����һ��DWORD ֵ:0x00rrggbb,����ֽ�Ϊ0���������ֽڷֱ��ʾ
		r,g,b ��ֵ.

*********************************************************************************/
HB_SDVR_API	BOOL __stdcall HB_SDVR_SetOverlayMode(LONG lPlayHandle, BOOL bOverlayMode, COLORREF colorKey);

/*
���ܣ���ȡ�ײ�UserID
������
   lUserID ����HB_SDVR_Login����
����ֵ��
    �ɹ�:���صײ�UserID
	ʧ��:����false
*/
HB_SDVR_API LONG __stdcall HB_SDVR_GetUserID(LONG lUserID);

/*
 ���ܣ� ����7000T��֡���
 ������ lUserID ����¼id 
       iFrameRateΪSTRUCT_SDVR_IFRAMERATE�ṹ��
 */
HB_SDVR_API BOOL __stdcall  HB_SDVR_SetIFrameRate(LONG lUserID,LPSTRUCT_SDVR_IFRAMERATE pStruiFrameRate);
HB_SDVR_API BOOL __stdcall  HB_SDVR_GetIFrameRate(LONG lUserID, LONG lChannel, LPSTRUCT_SDVR_IFRAMERATE pStruiFrameRate);
HB_SDVR_API VOID __stdcall  HB_SDVR_SendAudio(char *pAuidoBuffer,int length);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////������8000TH����ӵ�Э��ӿ�////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*********************************************************************************
���ܣ�8000TH  NTP���ò��������úͲ�ѯ��
����: lUserID �û�ID���û���¼ʱ���صġ�pStruNtpPara NTP���ò�����
���أ�true �ɹ�   false ʧ�ܡ�
*********************************************************************************/
HB_SDVR_API BOOL __stdcall  HB_SDVR_NTPConfigSet(LONG lUserID,LPHB_SDVR_NTPCONFIG pStruNtpPara);
HB_SDVR_API BOOL __stdcall  HB_SDVR_NTPConfigGet(LONG lUserID,LPHB_SDVR_NTPCONFIG pStruNtpPara);

/*********************************************************************************
���ܣ�8000TH �ʼ�������������úͲ�ѯ��
����: lUserID �û�ID���û���¼ʱ���صġ�pStruSmtpPara �ʼ��������ò�����
���أ�true �ɹ�   false ʧ�ܡ�
*********************************************************************************/
HB_SDVR_API BOOL __stdcall  HB_SDVR_SMTPConfigSet(LONG lUserID,LPHB_SDVR_SMTPCONFIG pStruSmtpPara);
HB_SDVR_API BOOL __stdcall  HB_SDVR_SMTPConfigGet(LONG lUserID,LPHB_SDVR_SMTPCONFIG pStruSmtpPara);

/*********************************************************************************
���ܣ�8000TH ��Ѳ���ò��������úͲ�ѯ��
����: lUserID �û�ID���û���¼ʱ���صġ�pStruPollPara ��Ѳ���ò�����
���أ�true �ɹ�   false ʧ�ܡ�
*********************************************************************************/
HB_SDVR_API BOOL __stdcall  HB_SDVR_PollConfigSet(LONG lUserID,LPHB_SDVR_POLLCONFIG pStruPollPara);
HB_SDVR_API BOOL __stdcall  HB_SDVR_PollConfigGet(LONG lUserID,LPHB_SDVR_POLLCONFIG pStruPollPara);

HB_SDVR_API BOOL __stdcall  HB_SDVR_SetPollConfig(LONG lUserID, LPVOID lpBuf, DWORD dwSize);
HB_SDVR_API BOOL __stdcall  HB_SDVR_GetPollConfig(LONG lUserID, LPVOID lpBuf, DWORD* pSize);

/*********************************************************************************
���ܣ�8000TH ��Ƶ������������úͲ�ѯ��
����: lUserID �û�ID���û���¼ʱ���صġ�pStruVideoMatrixPara ��Ƶ�������ò�����
���أ�true �ɹ�   false ʧ�ܡ�
*********************************************************************************/
HB_SDVR_API BOOL __stdcall  HB_SDVR_VideoMatrixSet(LONG lUserID,LPHB_SDVR_VIDEOMATRIX pStruVideoMatrixPara);
HB_SDVR_API BOOL __stdcall  HB_SDVR_VideoMatrixGet(LONG lUserID,LPHB_SDVR_VIDEOMATRIX pStruVideoMatrixPara);

HB_SDVR_API BOOL __stdcall  HB_SDVR_SetVideoMatrixConfig(LONG lUserID, LPVOID lpBuf, DWORD dwSize);
HB_SDVR_API BOOL __stdcall  HB_SDVR_GetVideoMatrixConfig(LONG lUserID, LPVOID lpBuf, DWORD* lpSize);

/*********************************************************************************
���ܣ�ƽ̨��Ϣ�����úͲ�ѯ��
����: lUserID �û�ID���û���¼ʱ���صġ�
���أ�true �ɹ�   false ʧ�ܡ�
*********************************************************************************/
HB_SDVR_API BOOL __stdcall HB_SDVR_GETPLATPARAM(LONG lUserID, LPVOID lpBuffer,DWORD dwBufferSize,DWORD type);
HB_SDVR_API BOOL __stdcall HB_SDVR_SETPLATPARAM(LONG lUserID, LPVOID lpBuffer,DWORD dwBufferSize,DWORD type);

/*
���ܣ����÷�����״̬
    ������lUserID����HB_SDVR_Login����
����ֵ��
    �ɹ�������TRUE
    ʧ�ܣ�����FALSE
*/
typedef struct _STRUCT_BUZZER_CTRL
{
    int ctrl;			//1.��  0.��
}STRUCT_BUZZER_CTRL, *LPSTRUCT_BUZZER_CTRL;

HB_SDVR_API BOOL __stdcall HB_SDVR_SetBuzzerState( LONG lUserID, 
                                                  BUSZZERSTATE WorkState );

HB_SDVR_API BOOL __stdcall HB_SDVR_GetBuzzerState( LONG lUserID,
                                                  BUSZZERSTATE *pWorkState);

//����ͨ��
HB_SDVR_API LONG __stdcall HB_SDVR_AlarmStart(LONG lUserID,void(CALLBACK *fAlarmDataCallBack)(LONG lAlarmHandle,char *pRecvDataBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
HB_SDVR_API LONG __stdcall HB_SDVR_AlarmStop(LONG lUserID);

// ����ATM
HB_SDVR_API LONG __stdcall HB_SDVR_GetAlarmConfig(LONG lUserID, LPVOID lpOutBuffer, int channel);
HB_SDVR_API LONG __stdcall HB_SDVR_SetAlarmConfig(LONG lUserID, LPVOID lpInBuffer, int channel);
HB_SDVR_API BOOL __stdcall HB_SDVR_ResetAlarmEnvi(LONG lUserID);

// ��������
#define HB_MAX_AM_COUNT	16

typedef struct 
{
	WORD enable;        //0-������1-����
	WORD time;          //������ʱʱ�䣨�˱�����ʱ���ã�
	DWORD reserver[4];  // ����
}HB_SDVR_REAL_DEFENCE, *LPHB_SDVR_REAL_DEFENCE;

typedef struct     
{
    unsigned            second : 6;     // ��: 0~59
    unsigned            minute : 6;     // ��: 0~59
    unsigned            hour : 5;       // ʱ: 0~23
    unsigned            day : 5;        // ��: 1~31
    unsigned            month : 4;      // ��: 1~12
    unsigned            year : 6;       // ��: 2000~2063
}MFS_Field_Time;

typedef struct
{
	WORD alm_ch;                				//����ͨ��
	WORD alm_type;             					//��������0-�ޱ���1-̽ͷ����2-�ƶ����3-��Ƶ��ʧ
	MFS_Field_Time time;        				//��������ʱ���
}HB_SDVR_ALMINFO, *LPHB_SDVR_ALMINFO;

typedef struct
{
	DWORD alm_count;                         	//�����ڼ䱨������
	HB_SDVR_ALMINFO alminfo[HB_MAX_AM_COUNT];   //ÿ�α����������Ϣ��ֻ�洢���µ�16�α���
	DWORD reserver[4];                          // ����
}HB_SDVR_DISCONN_ALMSTAT, *LPHB_SDVR_DISCONN_ALMSTAT;

// ��ȡʵʱ����״̬
HB_SDVR_API BOOL __stdcall HB_SDVR_GetRealDefenceCfg(LONG lUserID, LPHB_SDVR_REAL_DEFENCE lpCfg, DWORD* pDataSize);

// ʵʱ����������
HB_SDVR_API BOOL __stdcall HB_SDVR_SetRealDefenceCfg(LONG lUserID, LPHB_SDVR_REAL_DEFENCE lpCfg, DWORD dwDataSize);

// ��ȡ���������ڼ�ı�����Ϣ
HB_SDVR_API BOOL __stdcall HB_SDVR_GetDisconAlarmInfo(LONG lUserID, LPHB_SDVR_DISCONN_ALMSTAT lpInfo, DWORD* pDataSize);

//Tϵ�л��������ڵ���������/��ȡ
#define NET_SDVR_GET_VCOVER_DETECT  0x98
#define NET_SDVR_SET_VCOVER_DETECT  0x99

typedef struct HB_SDVR_VCOVER_ALM_ST
{
    BYTE    byChannel;          // ͨ���� [0,n] 
    DWORD   dwVcover_Enable;    // �ڵ�����ʹ�ܣ� 1-���ã�0-�����ã�
    DWORD   dwSensor_Out;       // ������������� ��λ��ʾ�� 1-������0-��������
}HB_SDVR_VCOVER_ALM, *LPHB_SDVR_VCOVER_ALM;

HB_SDVR_API BOOL __stdcall HB_SDVR_GetVcoverAlarmCfg(LONG lUserID, LPHB_SDVR_VCOVER_ALM lpCfg, DWORD* pDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetVcoverAlarmCfg(LONG lUserID, LPHB_SDVR_VCOVER_ALM lpCfg, DWORD dwDataSize);

// 2011/09/21 IPC��ؽӿڱ䶯
// 1.���߲������� ������ṹ�䶯
// 2.����ģʽ����ȥ����ʹ�ù��������滻������ű��Ϊ0xB0/0xB1
// 3.ԭ0xB0-0xB6����

#define NET_SDVR_IPCWORKPARAM_GET   0xB0
#define NET_SDVR_IPCWORKPARAM_SET   0xB1

typedef struct HB_SDVR_REQIPCWORKPARAM_ST
{
    BYTE cbStreamType;  // �������� 0-������ 1-������ 2-��������
    BYTE cbReserve[3];
}HB_SDVR_REQIPCWORKPARAM, *LPHB_SDVR_REQIPCWORKPARAM;

typedef struct HB_SDVR_SCHEDTIME_V2_ST
{
    BYTE	byStartHour;  			//��ʼСʱ 0-23
    BYTE	byStartMin;  			//��ʼ���� 0-59
    BYTE	byStopHour; 			//����Сʱ  0-23
    BYTE	byStopMin;  			//��������  0-59
} HB_SDVR_SCHEDTIME_V2, *LPHB_SDVR_SCHEDTIME_V2;	

typedef struct HB_SDVR_ICRTIME_ST
{
    WORD 	wLightRange;		//ICR�����л��ٽ�ֵ��ȡֵ��Χ0 < wLightRange< 2^16;
    WORD 	wEnable;            // 0--����ֵ��Ч  1--ʱ�����Ч
    HB_SDVR_SCHEDTIME_V2 stSchedTime[2];
}HB_SDVR_ICRTIME, *LPHB_SDVR_ICRTIME;

typedef struct HB_SDVR_SHUTTERVAL_ST
{
    DWORD   dwShutterIndex;     //��ǰ����ʱ������ֵ,��ʾ����dwShutterVal�е�λ��
    DWORD   dwShutterVal[32];	//��ȡ����ʱ���֧�ֲ����б�,��dwShutterVal[1]=0,��ʾ��һ��ȡֵ��Χ��
                                //��dwShutterVal[0]= 4096,���ʾȡֵ��ΧΪ��1/[1,4096*2],
                                //��dwShutterVal[1] != 0ʱ����ʾ�ж�����������ֵ��
                                //���磺dwShutterVal[0]= 2048��dwShutterVal[1]=4096����dwShutterVal[x]=0���ʾ���ݹ���x����
}HB_SDVR_SHUTTERVAL, *LPHB_SDVR_SHUTTERVAL;

typedef struct HB_SDVR_SCENEVAL_ST
{
    DWORD   dwSceneIndex;	    //��ǰ��ͷ����ֵ����ʾ����cbSceneVal�е�λ��
    BYTE	cbSceneVal[8][32];	//�û���֧�ֵľ�ͷ����,
                                //0 - Full Maual lens,1 - DC Iris lens, //2 - JCD661 lens,
                                //3 - Ricom NL3XZD lens,4 - Tamron 18X lens��
}HB_SDVR_SCENEVAL, *LPHB_SDVR_SCENEVAL;

typedef struct HB_SDVR_RESOLUTION_ST
{
    DWORD	dwResoluIndex;	    //��ǰ�ֱ�������ֵ����ʾ����dwResolution�е�λ��
    DWORD	dwResolution[16];	//�û���֧�ֵķֱ��ʣ���DWORD����ʾ֧�ֵķֱ��ʣ����磺
                                //dwResolution[0]=0x07800438�������ֽڣ�0x0780=1920���������ֽڣ�0x0438=1080��
}HB_SDVR_RESOLUTION, *LPHB_SDVR_RESOLUTION;

typedef struct HB_SDVR_AGCVAL_ST
{
    DWORD   dwAgcIndex;         //��ǰAGC������ֵ����ʾ����cbAgcVal�е�λ��
    BYTE	cbAgcVal[32];	    //AGC���Զ����棩��֧�ֲ����б�,��cbAgcVal[1]= 0ʱ��ʾcbAgcVal[0]�д洢����
                                //һ��ȡֵ��Χ����cbAgcVal[0]= 128,���ʾȡֵ��ΧΪ��[1,128],��cbAgcVal[1]!=0
                                //ʱ�����ʾcbAgcVal�����д洢���Ǿ����ֵ������ cbAgcVal[0]= 32��//cbAgcVal[1]=64�ȣ���cbAgcVal [x] =0��ʾ�ܹ���x�������
}HB_SDVR_AGCVAL, *LPHB_SDVR_AGCVAL;

typedef struct HB_SDVR_FRAMERATE_ST
{
    BYTE	cbMinFrameRate;	//�û���֧�ֵ���С����֡��ֵ;��ȡֵ��ΧΪ��1��2^8����ͬ��
    BYTE	cbMaxFrameRate;	//�û���֧�ֵ�������֡��ֵ;
    BYTE	cbCurFrameRate;	//�û������õĵ�ǰ����֡��ֵ;
    BYTE    cbreserve;		//����
}HB_SDVR_FRAMERATE, *LPHB_SDVR_FRAMERATE;

typedef struct HB_SDVR_IPCWORKMODE_ST
{
    DWORD   dwLength;		    //�ṹ�峤��
    BYTE    cbStreamEnable;     //�Ƿ�����ǰ����
    BYTE    cbStreamType;       //�������� 0-����1-���� 2-��������
    BYTE    cbAudioEnable;      //��Ƶʹ�� 0-����Ƶ ,1-����Ƶ
    BYTE  	cbAntiFlicker;      //����˸���� 0-60HZ   1-50HZ
    HB_SDVR_FRAMERATE   stFrameRate;	//����֡������;
    HB_SDVR_SHUTTERVAL  stShutterVal;	//������ز�����ȡ
    HB_SDVR_SCENEVAL	stSceneVal;	    //��ͷ��ز�����ȡ
    HB_SDVR_RESOLUTION	stResolution;	//���������
    HB_SDVR_AGCVAL		stAgcVal;		//Agc���
    DWORD	dwBitRateVal;		//��Ƶ���� 0-100K 1-128K��2-256K��3-512K��4-1M��5-1.5M��6-2M��7-3M, 8-4M
                                //9-5M��10-6M��11-7M��12-8M, 13-9M��14-10M��15-11 M��16-12M
                                //����������ֵ��kbps����Ч��Χ 32~2^32,���ڵ���32����KΪ��λ��
    BYTE	cbFoucusSpeedVal;	//��ѧ�佹�ٶ�ֵ��0����֧��
    BYTE	cbDigitalFoucusVal; //���ֱ佹ֵ��0����֧��
    BYTE	cbImageTurnVal;	    //��ǰͼ��ת���� //1-����ת,2-ˮƽ��ת 3-��ֱ��ת, 4-ˮƽ&��ֱ,0-��֧��
    BYTE	cbBlackWhiteCtrlVal;//��ǰ�ڰ�ģʽ���� //1- Off, 2- On, 3�CAuto, 0-��֧��
    BYTE	cbIRISCtrl;		    //Iris control mode ��Ȧ����ģʽ���ã�1-Off,2-Basic, 3-Advanced,0-��֧��
    BYTE	cbAutoFoucusVal;	//�Ƿ�֧���Զ��Խ���//0-��֧��,1-֧��
    BYTE 	cbAWBVal;		    //��ƽ�ⳡ��ģʽ���ã�1-auto_wide, 2-auto_normal, 3-sunny, 4-shadow, 5-indoor,
                                //6-lamp, 7-FL1, 8-FL2,0-��֧��
    BYTE 	cbA3Ctrl;           //3A����0-off; 1-Auto Exposure; 2-Auto White Balance; 3-both, (Auto Focus no support)
    HB_SDVR_ICRTIME stICRTime;  //ircut(�˹�Ƭ�л�ģʽ����)����ģʽ4ʱ�����û�ȡ��ֵ
    BYTE	cbFNRSuppVal;	    //��ǰ֡�������ã�1-��,2-��,0-��֧��
    BYTE	cbStreamKindVal;	//��ǰ�������ͣ�1-������,2-������
    BYTE	cbVideoOutKindVal;	//vout��Ƶ������ã�0-disable, 1-CVBS, 2-HDMI,3-YPbPr�ȵ�
    BYTE	cbWDRVal;		    //�û����Ƿ�֧�ֿ�̬����,0-��֧��,1-֧��
    BYTE    cbColorMode;        //ɫ�ʷ������ 0-TV   1--PC
    BYTE    cbSharpNess;		//������ã�ȡֵ��ΧΪ��[1,255]
    BYTE	cbPlatformType;	    //ƽ̨���
    BYTE	cbReserve[17];		//����
} HB_SDVR_IPCWORKMODE, *LPHB_SDVR_IPCWORKMODE;

// �ӿں���
HB_SDVR_API BOOL __stdcall HB_SDVR_IpcGetWorkParam(LONG lUserID, LPHB_SDVR_IPCWORKMODE lpCfg, DWORD* pDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_IpcSetWorkParam(LONG lUserID, LPHB_SDVR_IPCWORKMODE lpCfg, DWORD dwDataSize);

// 2011/09/22 NVR����Э��
#define NET_SDVR_STREAM_TYPE_NVR                0xC0  // ����������(�ļ�ͷ)
#define NET_SDVR_WORK_STATE_EX                  0xC1  // ��ȡ�����豸����״̬��չ
#define NET_SDVR_GET_CH_CLIENT_IP               0xC2  // ��ȡ��Ӧͨ�����ӵĿͻ���IP�б�
#define NET_SDVR_LOG_QUERY_EX                   0xC3  // NVR��־��Ϣ��ѯ
#define NET_SDVR_SERIAL_START_NVR               0xC4  // ����NVR͸��ͨ��
#define NET_SDVR_SERIAL_STOP_NVR                0xC5  // �ر�NVR͸��ͨ��
#define NET_SDVR_DEVICECFG_GET_EX               0xC6  // ��ȡ�豸��Ϣ(��չ)
#define NET_SDVR_DEVICECFG_SET_EX               0xC7  // �����豸��Ϣ(��չ)
#define NET_SDVR_PTZLIST_GET_NVR                0xC8  // ��ȡNVR��̨Э���б�
#define NET_SDVR_ALRM_ATTR_NVR                  0xC9  // ��ȡNVR������������˿�����
#define NET_SDVR_ALRMIN_GET_NVR                 0xCA  // ��ȡNVR�����������
#define NET_SDVR_ALRMIN_SET_NVR                 0xCB  // ����NVR�����������
#define NET_SDVR_ALRMOUT_GET_NVR                0xCC  // ��ȡNVR�����������
#define NET_SDVR_ALRMOUT_SET_NVR                0xCD  // ����NVR�����������
#define NET_SDVR_ALRMIN_STATUS_GET_NVR          0xCE  // ��ȡNVR��������״̬
#define NET_SDVR_ALRMOUT_STATUS_GET_NVR         0xCF  // ��ȡNVR�������״̬
#define NET_SDVR_ALRMOUT_STATUS_SET_NVR         0xD1  // ����NVR�������״̬
#define NET_SDVR_PICCFG_GET_EX_NVR              0xD2  // ��ȡNVRͨ������
#define NET_SDVR_PICCFG_SET_EX_NVR              0xD3  // ����NVRͨ������
#define NET_SDVR_RECORD_GET_EX_NVR              0xD4  // ��ȡNVR¼�����
#define NET_SDVR_RECORD_SET_EX_NVR              0xD5  // ����NVR¼�����
#define NET_SDVR_MOTION_DETECT_GET_NVR          0xD6  // ��ȡNVR�ƶ�������
#define NET_SDVR_MOTION_DETECT_SET_NVR          0xD7  // ����NVR�ƶ�������
#define NET_SDVR_ABNORMAL_ALRM_GET_NVR          0xD8  // ��ȡNVR�쳣��������
#define NET_SDVR_ABNORMAL_ALRM_SET_NVR          0xD9  // ����NVR�쳣��������
#define NET_SDVR_PARAM_FILE_EXPORT              0xDA  // ���������ļ�����
#define NET_SDVR_PARAM_FILE_IMPORT              0xDB  // ���������ļ�����
#define NET_SDVR_RESOLUTION_GET_NVR             0xDC  // ��ȡNVR�����ֱ���
#define NET_SDVR_RESOLUTION_SET_NVR             0xDD  // ����NVR�����ֱ���
#define NET_SDVR_SET_VOICE_DECODE               0xDE  // ����NVR�Խ�ѹ����ʽ
#define NET_SDVR_GET_REMOTE_RESOLUTION          0xDF  // ��ȡNVRǰ���豸�ֱ����б�
#define NET_SDVR_QUERY_MONTH_RECFILE            0x47  // ���²�ѯ¼��


//��������������(ʵʱ��Ƶ���طš�����)
//#define NET_SDVR_STREAM_TYPE_NVR       0xC0  
typedef struct
{
    BYTE sBuff[64];         // �ļ�ͷ����
} HB_STREAM_TYPE;

typedef struct 
{
    BYTE byRecordStatic;			//ͨ���Ƿ���¼��,0-��¼��,1-¼��
    BYTE bySignalStatic;			//���ӵ��ź�״̬,0-����,1-�źŶ�ʧ
    BYTE byHardwareStatic;			//����
    BYTE byLinkNum; 				//�ͻ������ӵĸ�����ͬһͨ����ǰʱ���ʵʱ��������������������������ͬһIP���������������
    DWORD dwBitRate;				//ʵ������
} HB_SDVR_CHANNELSTATE_EX;

typedef struct	
{
    DWORD dwSize ; 									//�ṹ���С
    HB_SDVR_DISKSTATE  struHardDiskStatic[16];		//Ӳ��״̬
    HB_SDVR_CHANNELSTATE_EX struChanStatic[128];	//ͨ����״̬
    BYTE byAlarminStatusLocal[128];					//���ر�������˿ڵ�״̬
    BYTE byAlarmoutStatusLocal[128];				//���ر�������˿ڵ�״̬
    DWORD dwReserve[4];								//����
} HB_SDVR_WORKSTATE_V2, *LPHB_SDVR_WORKSTATE_V2;


//��ȡ��ͨ��ʵʱ��Ƶ�����ӵĿͻ���ip�б�
//#define NET_SDVR_GET_CH_CLIENT_IP       0xC2
typedef struct
{
    DWORD dwSize;						    //�ṹ���С
    BYTE  byChannel;					    //ͨ����[0, n-1],n:ͨ����
    BYTE  byClientIpNum;					//��ͨ�����ӿͻ���IP����
    BYTE  byReserve1[2];					//����
    DWORD dwDwClientIP[64];				    //�ͻ���IP�б�
    DWORD dwReserve2[4];					//����
} HB_CLIENT_IP_INFO, *LPHB_CLIENT_IP_INFO;


//��־����ṹ��
//#define NET_SDVR_LOG_QUERY_EX           0xC3
typedef struct
{
    WORD wYear;			    //��: 2000~2063
    BYTE byMonth;			//��: 1~12
    BYTE byDay;				//��: 1~31
    WORD wStart; 			//��ѯ�ӵڼ�����ʼ��һ��Ϊ0��
    WORD wnum;  			//һ�β�ѯ���������Ϊ100��
    BYTE byPriType;    		//������ ������չ���У�
    BYTE bySecType;  		//������
    BYTE byReserve[6];		//����
} HB_REQLOG_EX, *LPHB_REQLOG_EX;

typedef struct 
{
    DWORD  dwSize;					    //�ṹ���С
    DWORD  dwTotalLogNum;	    		//��־������
    DWORD  dwCurLogNum;				    //���β鵽������
    DWORD  dwStart; 				    //���β�ѯ������־����ʼ���
    BYTE   byEncType;					//�����ʽ 1- UTF-8  2-gb2312   
    BYTE   byReserve[3];				//����
    BYTE   sSigalLogData[100][128];     // ��־��Ϣ (ÿ�β�ѯ���֧��100����־����־����100��									//  ��Ҫ��ε��ã�ÿ��128�ֽڣ�ÿ���ԡ�\0������)
} HB_SDVR_LOGINFO_EX, *LPHB_SDVR_LOGINFO_EX;

typedef enum //������
{
    LOG_PRI_ALL = -1,   //ȫ��
    LOG_PRI_ERROR,      // �쳣
    LOG_PRI_ALARM,      // ����
    LOG_PRI_OPERATE,    // ����
    LOG_PRI_MAX
} LOG_PRI_TYPE;

typedef enum //����������
{
    LOG_OP_ALL = -1,
    LOG_OP_POWERON,     // ����
    LOG_OP_SHUTDOWN,    // �ػ�
    LOG_OP_EXC_SHUTDOWN,//�쳣�ػ�
    LOG_OP_REBOOT,      // ����
    LOG_OP_LOGIN,       // ��½
    LOG_OP_LOGOUT,      // ע��
    LOG_OP_SETCONFIG,   // ����
    LOG_OP_FRONTEND_SETCONFIG,  //ǰ���豸����
    LOG_OP_UPGRADE,             // ����
    LOG_OP_FRONTEND_UPGRADE,    //ǰ���豸����
    LOG_OP_RECORD_START,        // ���������ֶ�¼��
    LOG_OP_RECORD_STOP,         // ����ֹͣ�ֶ�¼��
    LOG_OP_PTZ,                 // ��̨����
    LOG_OP_MANUAL_ALARM,        //�����ֶ�����
    LOG_OP_FORMAT_DISK,         // ��ʽ��Ӳ��
    LOG_OP_FILE_PLAYBACK,       // ���ػط��ļ�
    LOG_OP_EXPORT_CONFIGFILE,   //�������������ļ�
    LOG_OP_LMPORT_CONFIGFILE,   //���뱾�������ļ�
    LOG_OP_FREXPORT_CONFIGFILE, //����ǰ���豸�����ļ�
    LOG_OP_FRLMPORT_CONFIGFILE, //����ǰ���豸�����ļ� 
    LOG_OP_BACKUP_REC,          //���ر���¼���ļ�
    LOG_OP_DEFAULT,             //���ػָ�ȱʡ
    LOG_OP_SETTIME,             // ��������ϵͳʱ��
    LOG_OP_TRANSCOM_OPEN,       // ����͸��ͨ��
    LOG_OP_TRANSCOM_CLOSE,      // �Ͽ�͸��ͨ��
    LOG_OP_TALKBACK_START,      // �Խ���ʼ
    LOG_OP_TALKBACK_STOP,       // �Խ�����

    LOG_OP_TYPE_NONE,           // ��¼��
    LOG_OP_TYPE_MANUAL,         // �ֶ�¼��
    LOG_OP_TYPE_TIME,           // ��ʱ¼��
    LOG_OP_TYPE_MOTION,         // �ƶ�¼��
    LOG_OP_TYPE_SENSOR,         // ̽ͷ����
    LOG_OP_TYPE_MOTION_OR_SENSOR,	// �ƶ��򱨾�¼��
    LOG_OP_TYPE_MOTION_AND_SENSOR,	// �ƶ���̽ͷ����
    LOG_OP_REMOTE_LOGIN,	    // ǰ���豸��½
    LOG_OP_REMOTE_LOGOUT,	    // ǰ���豸ע��

    LOG_OP_TYPE_MAX
} LOG_OPERATE_TYPE;

typedef enum //����������
{
    LOG_ALM_ALL = -1,
    LOG_ALM_LOCAL_SENSORIN,     // ���ر�������
    LOG_ALM_LOCAL_SENSOROUT,    // ���ر������
    LOG_ALM_FRONTEND_SENSORIN,  //ǰ���豸��������  
    LOG_ALM_FRONTEND_SENSOROUT, //ǰ���豸������� 
    LOG_ALM_MOTION_START,       // �ƶ���⿪ʼ
    LOG_ALM_MOTION_STOP,        // �ƶ�������
    LOG_ALM_MAIL_UPLOAD,        // �ʼ��ϴ�
    LOG_ALM_TYPE_MAX
} LOG_ALARM_TYPE;

typedef enum //���������
{
    LOG_ERR_ALL = -1,
    LOG_ERR_VIDEOLOST,      // ��Ƶ��ʧ
    LOG_ERR_HD_ERROR,       // ���̴���
    LOG_ERR_HD_FULL,        // ������
    LOG_ERR_LOGIN_FAIL,     // ��½ʧ��
    LOG_ERR_TEMP_HI,        // �¶ȹ���
    LOG_ERR_HD_PFILE_INDEX, // ��������������
    LOG_ERR_HD_DEV_FATAL,   // �����豸��������
    LOG_ERR_IP_CONFLICT,    //ip��ͻ
    LOG_ERR_NET_EXCEPTION,  //�����쳣
    LOG_ERR_REC_EXCEPTION,  //¼���쳣
    LOG_ERR_FRONTEND_EXCEPTION, //ǰ���豸�쳣
    LOG_ERR_TIME_EXCEPTION,     //ʱ���쳣
    LOG_ERR_FRONTBOARD_EXCEPTION, //ǰ����쳣
    LOG_ERR_TYPE_MAX
} LOG_ERROR_TYPE;

//����nvr͸��ͨ��
//#define NET_SDVR_SERIAL_START_NVR       0xC4
//�ر�NVR͸��ͨ��
//#define NET_SDVR_SERIAL_STOP_NVR        0xC5  
typedef struct
{
    BYTE  byOpType; 			//0-�����DVR,���ñ��أ���1-ǰ���豸������ (Ϊ1ʱbyChannel��Ч)
    BYTE  bySeriaType;		    //һ���ֽڵĴ������ͣ�1��232  2��485��
    BYTE  byChannel;   		    //[0, n-1],n:ͨ����
    BYTE  byReserve[5];		    //����
} HB_NVR_SERIAL_START, *LPHB_NVR_SERIAL_START;


//��ȡ�豸��Ϣ��չ
//#define NET_SDVR_DEVICECFG_GET_EX       0xC6
//�����豸��Ϣ(��չ)
//#define NET_SDVR_DEVICECFG_SET_EX       0xC7  
typedef struct	
{
    DWORD dwSize;						//�ṹ���С
    BYTE sDVRName[32];					//�豸, �ԡ�\0�������ַ���
    DWORD dwDVRID;						//����
    DWORD dwRecycleRecord;				//Э���: //¼�񸲸ǲ��� 0-ѭ������ 1-��ʾ����
    BYTE sSerialNumber[48];				//���к�
    BYTE sSoftwareVersion[64];			//����汾���ԡ�\0�������ַ���Э���: �������ͺ� ����汾�ţ�
    BYTE sSoftwareBuildDate[32];		//������������ԡ�\0�������ַ���Э���:��Build 100112��
    DWORD dwDSPSoftwareVersion;			//DSP����汾
    BYTE sPanelVersion[32];				//ǰ���汾���ԡ�\0�������ַ�����IPC��
    BYTE sHardWareVersion[32];	        //(����)Э���: ������汾�ų���16�ֽ�ʱ��ʹ����Ϊ�����ͺ���ʾ
    BYTE byAlarmInPortNum;		        //�����������, NVRֻȡ���ر�������
    BYTE byAlarmOutPortNum;	  	    	//�����������, NVRֻȡ���ر������
    BYTE byRS232Num;			        //����
    BYTE byRS485Num;					//����
    BYTE byNetworkPortNum;				//����
    BYTE byDiskCtrlNum;					//����
    BYTE byDiskNum;						//Ӳ�̸���
    BYTE byDVRType;						//DVR����, 1:NVR 2:ATM NVR 3:DVS 4:IPC 5:NVR ������ʹ��//NET_SDVR_GET_DVRTYPE���
    BYTE byChanNum;						//ͨ������[0, 128]
    BYTE byStartChan;					//����
    BYTE byDecordChans;					//����
    BYTE byVGANum;						//����
    BYTE byUSBNum;						//����
    BYTE byReserve[3];					//����
} HB_DEVICEINFO_V2, *LPHB_DEVICEINFO_V2;


//��ȡnvr��̨Э���б�
//#define NET_SDVR_PTZLIST_GET_NVR        0xC8
typedef struct
{
    BYTE  byType; 		    //0-NVR������̨��1-ǰ���豸��̨ (Ϊ1ʱbyChannel��Ч)
    BYTE  byChannel;   	    //[0, n-1],n:ͨ����
    BYTE  byReserve[2];	    //����
} HB_NVR_PTZLIST, *LPHB_NVR_PTZLIST;

typedef struct 
{
    DWORD 	dwPtznum;				//Э�����������Ϊ���100����
    BYTE	byReserve[4];		    //����
        BYTE   	sPtzType[100][10];	//Э�����б�D�D�D0��unknow;
} HB_NVR_PTZLIST_INFO, *LPHB_NVR_PTZLIST_INFO;

//��ȡNVR������������˿�����
//#define NET_SDVR_ALRM_ATTR_NVR                  0xC9 
typedef struct
{
    DWORD dwSize;                       // �ṹ���С
    BYTE byOpType;                      // 0-���� 1-ǰ�� (Ϊ1ʱ,byChannel��Ч)
    BYTE byChannel;                     // ����ǰ��ĳͨ���豸 [0, n-1], n:ͨ������
    BYTE byAlarmInNum;					// ���豸ӵ�б����������
    BYTE byAlarmOutNum;				    // ���豸ӵ�б����������
    BYTE sAlarmInPortName[128][32];		// ��������˿����� �ԡ�\0�������ַ���
    BYTE sAlarmOutPortName[16][32];		// ��������˿����� �ԡ�\0�������ַ���
    BYTE sDevName[32];					// ͨ����Ӧ�豸����
    DWORD dwIP;						    // �豸IP
    BYTE byReserve[4];			        // ����
} HB_NVR_ALRM_PORT_ATTR, *LPHB_NVR_ALRM_PORT_ATTR;


//��ȡnvr�����������
//#define NET_SDVR_ALRMIN_GET_NVR         0xCA
//����nvr�����������
//#define NET_SDVR_ALRMIN_SET_NVR         0xCB	

typedef struct
{
    DWORD dwSize;                      			//�ṹ���С
    BYTE  byOpType;                        		//0-���� 1-ǰ�� (Ϊ1ʱ,byChannel��Ч)
    BYTE  byChannel;                     		//����ǰ��ĳͨ���豸 [0, n-1], n:ͨ������
    BYTE  byAlarmInPort;				    	//��������˿ں�[0, n-1], n:�����������
    BYTE  sAlarmInName[32];			    		//��������˿����� �ԡ�\0�������ַ���
    BYTE  byAlarmType;				    		//̽ͷ���� 0-����1-����
    BYTE  byEnSchedule;							//�������벼��ʱ�伤�� 0-���� 1-���� 
    BYTE  byWeekEnable;               			//ÿ��ʹ��λ0-��ʹ�� 1-ʹ��(��ʹ��,ֻȡstruAlarmTime[0][0~7]������ÿһ��) 
    BYTE  byAllDayEnable[8];					//ȫ��ʹ�� ,0-��ʹ�� 1-ʹ��������ʹ��,���Ӧ����Ϊȫ�첼��,�����ж�ʱ���	
    HB_SDVR_SCHEDTIME_V2 struAlarmTime[8][8];   //����ʱ���
    DWORD dwHandleType;	            			//��λ 2-�������� 5-��������� //6-�ʼ��ϴ�

    // �����������
    BYTE  byAlarmOutLocal[16];		            //��������˿�(����)
    BYTE  byAlarmOutRemote[128][16];		    //��������˿�(ǰ���豸)

    // ����¼��
    BYTE  byRelRecordChan[128];		            //����������¼��ͨ��,Ϊ1��ʾ������ͨ�� 0Ϊ������

    // ��������
    BYTE  byEnablePreset[128];				    //�Ƿ����Ԥ�õ� ����byEnablePreset[0]���ж�
    BYTE  byPresetNo[128];					    //���õ���̨Ԥ�õ����,һ������������Ե��ö��ͨ������̨Ԥ�õ�, 0xff��ʾ������Ԥ�õ� [1, 254]
    BYTE  byReserve[32];			        	//����
} HB_NVR_ALRMININFO, *LPHB_NVR_ALRMININFO;


//��ȡnvr�����������
//#define NET_SDVR_ALRMOUT_GET_NVR        0xCC
//����nvr�����������
//#define NET_SDVR_ALRMOUT_SET_NVR        0xCD
typedef struct	
{
    DWORD dwSize;					            // �ṹ���С
    BYTE byOpType;                              // 0-���� 1-ǰ�� (Ϊ1ʱ,byChannel��Ч)
    BYTE byChannel;                             // ����ǰ��ĳͨ���豸 [0, n-1], n:ͨ������
    BYTE byALarmOutPort;			            // �������ͨ���� [0, n-1], n:��������˿���
    BYTE sAlarmOutName[32];			            // ���� �ԡ�\0�������ַ���
    DWORD dwAlarmOutDelay;			            // �������ʱ�� ��λ�� [2, 300]
    BYTE byAlarmType;				            // ̽ͷ���� 0-����1-���� (����)    
    BYTE byEnSchedule;				            // �����������ʱ�伤�� 0-���� 1-���� 
    BYTE byWeekEnable;                          // ÿ��ʹ��λ0-��ʹ�� 1-ʹ��(��ʹ��,ֻȡstruAlarmTime[0][0~7]��ÿ��������)  
    BYTE byFullDayEnable[8];     		        // ������¼�� 0-��ʹ��(ȱʡֵ) 1-ʹ��
    HB_SDVR_SCHEDTIME_V2 struAlarmTime[8][8];   //����ʱ���, 8��ʱ���

    BYTE  byReserve[32]; 				        // ����
} HB_NVR_ALARMOUTINFO, *LPHB_NVR_ALARMOUTINFO;


//��ȡnvr��������״̬
//#define NET_SDVR_ALRMIN_STATUS_GET_NVR  0xCE
typedef struct	
{
    BYTE  byOpType;                 //  0-���� 1-ǰ�� (Ϊ1ʱ,byChannel��Ч)
    BYTE  byChannel;                // ����ǰ��ĳͨ���豸 [0, n-1], n:ͨ������
    BYTE  byAlarm; 			        // ����
    BYTE  byReserve1;			    // ����
    BYTE  byAlarmIn[128];           // ��������״̬ 128����������, 0-������ 1-������
    BYTE  byRreserve2[32];		    // ����
} HB_NVR_ALRMIN_STATUS, *LPHB_NVR_ALRMIN_STATUS;

//��ȡnvr�������״̬
//#define NET_SDVR_ALRMOUT_STATUS_GET_NVR 0xCF
//����nvr�������״̬
//#define NET_SDVR_ALRMOUT_STATUS_SET_NVR 0xD1
typedef struct	
{
    BYTE    byOpType;           //  0-���� 1-ǰ�� (Ϊ1ʱ,byChannel��Ч)
    BYTE    byChannel;          // ����ǰ��ĳͨ���豸 [0, n-1], n:ͨ������
    BYTE	byAlarm; 		    // �������״̬ 0-������ 1-����
    BYTE	byReserve1;			// ����
    BYTE	byAlarmOut[16];  	// �������״̬ 16���������, ��ȡ����ʱ,byAlarm��Ч,byAlarmOut[16]��Ϊ1���������,0Ϊ���������������ʱbyAlarm��Ч��byAlarmOut[16]��0-״̬���� 1-ִ��byAlarm����
    BYTE 	byReserve2[32];
} HB_NVR_ALRMOUT_STATUS, *LPHB_NVR_ALRMOUT_STATUS;

typedef struct
{
    BYTE byBrightness;                // ����      ȡֵ��Χ[0��255] ȱʡֵ128
    BYTE byConstrast;                 // �Աȶ�    ȡֵ��Χ[0��255] ȱʡֵ128
    BYTE bySaturation;                // ���Ͷ�    ȡֵ��Χ[0��255] ȱʡֵ128
    BYTE byHue;                       // ɫ��      ȡֵ��Χ[0��255] ȱʡֵ128
    BYTE bySharp;                     // ���      0��ȱʡֵ����1    
    DWORD dwReserved;                 // Ԥ��
} VIDEO_INFO, *PVIDEO_INFO;

typedef struct	
{
    DWORD dwSize; 					// ����(�ṹ���С)

    // ͨ�������
    BYTE sChanName[32];				// ͨ���� �ԡ�\0�������ַ���
    BYTE byChannel; 					// ͨ���� [0, n��1] n:ͨ����
    DWORD dwShowChanName;		    // �Ƿ���ʾͨ���� 0-��ʾ 1-����ʾ
    BYTE byOSDAttrib;				// ͨ���� 1-��͸�� 2-͸����ֻ���PC����ʾ��
    WORD wShowNameTopLeftX;		    // ͨ��������ʾλ�õ�x���� ��->�� 0~��Ƶʵ�ʿ�ȣ�ͨ��������
    WORD wShowNameTopLeftY;		    // ͨ��������ʾλ�õ�y���� ��->�� 0~��Ƶʵ�ʸ߶ȣ�����߶�

    // �������
    DWORD dwShowTime;				// �Ƿ���ʾʱ�� 0-��ʾ 1-����ʾ
    WORD wOSDTopLeftX;				// ʱ��osd����X [0, ʵ�ʿ�ʱ�볤��]
    WORD wOSDTopLeftY;				// ʱ��osd����Y[0, ʵ�ʸߣ�����߶�]
    BYTE byDateFormat;				// ���ڸ�ʽ
    //  0 - YYYY-MM-DD    ��ȱʡֵ��
    //  1 - MM-DD-YYYY
    //  2 - YYYY��MM��DD��
    //  3 - MM��DD��YYYY��

    // �������
    BYTE byDispWeek;				// �Ƿ���ʾ���� 0-��ʾ 1-����ʾ
    BYTE byOSDLanguage;				// �������� 0-���� 1-Ӣ�� (����չ)

    // ����ɫ�����
    VIDEO_INFO  struVideoInfo;      // ��Ƶ��Ϣ

    // �ڵ��������
    DWORD dwEnableHide;		            // ��Ƶ�ڵ�ʹ�� ,0-���ڵ�,1-�ڵ�(�ڵ�����ȫ��) 2-�ڵ�(�ڵ�����������)  
    HB_SDVR_SHELTER	struShelter[16];	// ��Ƶ�ڵ�����	
    DWORD dwOsdOverType; 		        // osd�������� 0-������ 1-ǰ�˵��� 2-��˵���
    DWORD dwReserve[32];				// ����
} HB_NVR_CHN_ATTR_INFO, *LPHB_NVR_CHN_ATTR_INFO;


//��ȡnvrǰ���豸�ֱ���
//#define   NET_SDVR_GET_REMOTE_RESOLUTION  0xDF
//��ȡnvr¼�����
//#define   NET_SDVR_RECORD_GET_EX_NVR      0xD4
//����nvr¼�����
//#define   NET_SDVR_RECORD_SET_EX_NVR      0xD5
typedef struct
{
    DWORD dwChannel;            // ͨ���� [0, n��1] n:ͨ����
    DWORD dwLinkMode;           // ��ע�������� 0-��֧�� 1-������ 2-������ 3-��������
    DWORD dwResolution[16];     // �û���֧�ֵķֱ��ʣ���DWORD����ʾ֧�ֵķֱ���
                                // ���磺dwResolution[0]=0x07800438�������ֽ�(0x0780=1920)�������ֽ�(0x0438=1080)�� 
                                // �������Աȫ��Ϊ0����ʾ��֧��
} HB_SDVR_REMOTE_RESOLUTION,   *LPHB_SDVR_REMOTE_RESOLUTION;

typedef struct
{
    BYTE    byStreamtype;             // ������     0-��������ȱʡֵ�� 1-������
    BYTE    byQuality;                // ��Ƶ����   1-��� 2-�ϸ� 3-�ߣ�ȱʡֵ�� 4-�� 5-�� 6-���
    BYTE    byResolution;             // ������     0-CIF 1-D1��ȱʡֵ�� 2-720P 3-1080P ������     0-CIF 1-D1(ȱʡֵ)
                                      // 2013-05-08����Ϊ��̬ӳ��,����Э���Ȼ�ȡ
    BYTE    byFramerate;              // ֡��       ȡֵ��Χ[2,25] ȱʡֵ25 
                                      // 2013-05-08����Ϊ[2,60]
    BYTE    byMaxbitrate;             // ����(��)   0-100K 1-128K 2-256K 3-512K 4-1M 5-1.5M 6-2M��ȱʡֵ�� 
                                      // 7-3M 8-4M 9-6M 10-8M            
                                      // 2013-05-08����Ϊ0:��֧��
                                      // �������ӣ� 0-30K 1-45K 2-60K 3-75K 4-90K 5-100K 6-128K 7-256K 8-512K(ȱʡֵ) 9-1M 10-2M
    BYTE    byAudio;                  // ��Ƶ��ʶ   0-����Ƶ 1-����Ƶ��ȱʡֵ��
    DWORD   dwReserved;               // Ԥ��
} HB_RECORD_PARAM,  *LPHB_RECORD_PARAM;

typedef struct
{
    BYTE byStarth;                    // ��ʼʱ��-ʱ
    BYTE byStartm;                    // ��ʼʱ��-��
    BYTE byStoph;                     // ����ʱ��-ʱ
    BYTE byStopm;                     // ����ʱ��-��
    BYTE byRecType;                   // ¼������  0 - �� 1-�ֶ�(��Ч)  2-��ʱ  3-�ƶ�  4-���� 5-�ƶ� | ����  6 -�ƶ� & ����
    BYTE byReserve[3];				  // ����
}HB_REC_TIME_PERIOD, *LPHB_REC_TIME_PERIOD;

typedef struct
{
    BYTE byEnable;  	    // ������ʹ��  0-��ʹ��(ȱʡֵ) 1-ʹ��
    BYTE byRecType; 	    // �������Ӧ��¼������ 0 - �� 1-�ֶ�(��Ч)  2-��ʱ  3-�ƶ�  4-���� 5-�ƶ� | ����  6- �ƶ� & ����
    BYTE byReserve[2];	    // ����
} HB_FULL_DAY_S;

typedef struct
{
    BYTE byEnable;                                // ʹ��ʱ��� 0-��ʹ��(ȱʡֵ) 1-ʹ��    
    BYTE byWeekEnable;                            // ÿ��ʹ��λ 0-��ʹ�� 1-ʹ��(��ʹ��,ֻȡstruAlarmTime[0][0~7]��ÿ��������)  
    HB_FULL_DAY_S	struFullDayEnable[8];         // ������¼��
    HB_REC_TIME_PERIOD struAlarmTime[8][8];       // [0-7][0]����ȫ��ʹ�ܵ�������

    DWORD  dwReserved;                            // Ԥ��
} HB_REC_TIME_SCHEDULE, *LPHB_REC_TIME_SCHEDULE;

typedef struct
{
    DWORD   dwSize;                   			    // �ṹ���С
    BYTE	byChannel;							    // ͨ����
    WORD    wPreRecTime;            				// Ԥ¼ʱ��      ȡֵ��Χ[5��30]��  ȱʡֵ10
    DWORD   dwDelayRecTime;         				// ¼�����ʱ��  ȡֵ��Χ[0,180]��  ȱʡֵ30 (��3-�ƶ�¼�� 4-����¼�� 5-�ƶ� | ����  6-�ƶ� & ���� ��Ч)
    HB_REC_TIME_SCHEDULE struTimeSchedule;          // ¼��ʱ�����¼����������

    HB_RECORD_PARAM    struTimeRecord;      		// ��ʱ           ¼�����
    HB_RECORD_PARAM    struMoveRecord;      	    // �ƶ�           ¼�����
    HB_RECORD_PARAM    struAlarmRecord;     	    // ����           ¼�����
    HB_RECORD_PARAM    struMoveOrAlarmRecord;       // �ƶ� | ����    ¼����� 
    HB_RECORD_PARAM    struMoveAndAlarmRecord;      // �ƶ� & ����    ¼�����
    HB_RECORD_PARAM    struNetRecParam[4];     	    // ������         ¼����� (����)

    DWORD   byLinkMode;                             // ��������(0-�������� 1-��һ��������2-�ڶ�������....)
    DWORD   dwCopyOrSet;                            //��־�����ò������Ǹ�����һͨ������ 0xff��ʾ�Ǹ��ƹ��ܣ���ʱ����copychannel��Ч������ֵ����Ϊ�����ù���
    DWORD   dwCopyChannel;                          //��ʾ���ĸ�ͨ��������������ֵ��д����Դ��ͨ���ţ�ֻ����copyorsetΪ0xffʱ��Ч
    DWORD   dwReserved[29];              			// Ԥ��
} HB_RECORD_SET, *LPHB_RECORD_SET; 


//��ȡnvr�ƶ�������
//#define NET_SDVR_MOTION_DETECT_GET_NVR  0xD6
//����nvr�ƶ�������
//#define NET_SDVR_MOTION_DETECT_SET_NVR  0xD7
typedef struct	
{
    DWORD dwSize; 				                // ���ȣ��ṹ���С��
    BYTE byChannel; 			                // ͨ���� [0, n��1] n:ͨ����

    BYTE byMotionScope[18][22];                 // �������,����32*32��С���,Ϊ1��ʾ�ú�����ƶ��������,0-��ʾ���� 
    BYTE byMotionSensitive;		                // �ƶ����������, 0 - 5,Խ��Խ���� 

    // ʱ������
    BYTE byEnableHandleMotion;                  // �ƶ���Ⲽ��ʹ�� 0-���� 1-����	
    BYTE byWeekEnable;                          // ����ÿ��0-��ʹ�� 1-ʹ��(��ʹ��,ֻȡstruAlarmTime[0][0~7]��ÿ��������)  
    BYTE byFullDayEnable[8];                    // ������¼�� 0-��ʹ��(ȱʡֵ) 1-ʹ��,������ʹ��,���Ӧ����Ϊȫ�첼��,�����ж�ʱ���
    HB_SDVR_SCHEDTIME_V2 struAlarmTime[8][8];   // ����ʱ���, 8��ʱ���
    DWORD	dwHandleType;	                    // ��λ 2-��������5-��������� //6-�ʼ��ϴ�

    // �����������
    BYTE	byAlarmOutLocal[16];		        // ��������˿�(����)
    BYTE	byAlarmOutRemote[128][16];			// ��������˿�(ǰ���豸)

    // ����¼��    
    BYTE    byRecordChannel[128];		        // ������¼��ͨ����Ϊ0-������ 1-����

    // ��������  
    BYTE    byEnablePreset[128];			    // �Ƿ����Ԥ�õ� ����byEnablePreset[0]���ж�;
    BYTE    byPresetNo[128];				    // ���õ���̨Ԥ�õ����,һ������������Ե��ö��ͨ������̨Ԥ�õ�, 0xff��ʾ������Ԥ�õ� [1, 254]
    DWORD   dwReserve[32];			            // ����
} HB_NVR_MOTION, *LPHB_NVR_MOTION;


// ��ȡnvr�쳣��������
// #define NET_SDVR_ABNORMAL_ALRM_GET_NVR  0xD8
// ����nvr�쳣��������
// #define NET_SDVR_ABNORMAL_ALRM_SET_NVR  0xD9
// NVR ��֧���ڵ�����
// 0109 DVR֧�ִ�Э�� byEnableAbnormal�������5�����;�֧��
// 1������ʽ�У�����������������󻯡���Ƶ�����������ǹ��õģ������ֱ�������ͬʱ��Ч
//    ֻ���ʼ��ϴ���Ե����ı���������Ч��������Ͽ�����û���ʼ��ϴ��Ĵ���ʽ
// 2���������ֻ���ڵ�������Ч
// 3����������������������̴�������Ͽ����¶ȹ����ǹ��õ�
//    ��Ƶ��ʧ����Ƶ�ڵ��ǹ��õġ�
// 4��ͨ���Ŷ��ڵ���������Ƶ��ʧ��Ч
typedef struct	
{
    DWORD   dwSize; 				            // ���ȣ��ṹ���С��
    BYTE    byAbnormalAlarmType;                // 1-��Ƶ��ʧ 2-����Ͽ� 3-�¶ȹ��� 4-�ڵ����� 5-���̱���           
    BYTE    byChannel;                          // ͨ���� 

    BYTE    byEnableAbnormal;		            // �쳣����ʹ�� 0-��֧�� 1-���� 2-���������ڵ�����ʱ��Ч�� 
    WORD    wHideAlarmAreaTopLeftX;		        // [0, ʵ�ʿ�1]���ڵ�����ʱ��Ч��
    WORD    wHideAlarmAreaTopLeftY;		        // [0, ʵ�ʸߣ�1]���ڵ�����ʱ��Ч��
    WORD    wHideAlarmAreaWidth;			    // [16, ʵ�ʿ�] ���ڵ�����ʱ��Ч��
    WORD    wHideAlarmAreaHeight;			    // [16, ʵ�ʸ�] ���ڵ�����ʱ��Ч��

    // �����������
    BYTE    byAlarmOutLocal[16];			    // ��������˿�(����)
    BYTE	byAlarmOutRemote[128][16];	        // ��������˿�(ǰ���豸)

    BYTE    byWeekEnable;                       // ����ÿ��0-��ʹ�� 1-ʹ��(��ʹ��,ֻȡstruAlarmTime[0][0~7]��ÿ��������)  
    BYTE    byFullDayEnable[8];                 // ������¼�� 0-��ʹ��(ȱʡֵ) 1-ʹ��,������ʹ��,���Ӧ����Ϊȫ�첼��,�����ж�ʱ���
    HB_SDVR_SCHEDTIME_V2 struAlarmTime[8][8];   // ����ʱ���, 8��ʱ���
    DWORD	dwHandleType;	                    // ����ʽ ��λ  2-�������� 5-��������󻯣��ڵ�����ʱ��Ч��
                                                // 6-�ʼ��ϴ� 7-��Ƶ����
    DWORD   dwParam;                            // �¶ȹ��߱���ʱ��ʾ������¶�ֵ������������¶Ⱦͱ�����ȡֵ��Χ0-100
                                                // �ڵ�����ʱ��ʾ�����ȣ�ȡֵ��Χ1-5
    DWORD   dwReserve[31];                      // ����
} HB_NVR_ABNORMAL, *LPHB_NVR_ABNORMAL;


//���ļ�����
//#define NET_SDVR_PARAM_FILE_EXPORT      0xDA
typedef struct
{
    DWORD   dwFileSize;	    // �����ļ��Ĵ�С
    DWORD   dwReserve;		// ����
} HB_EXPT_REQ, *LPHB_EXPT_REQ;


//�����ļ�����
//#define NET_SDVR_PARAM_FILE_IMPORT      0xDB 
typedef struct
{
    DWORD   dwFileSize;	    // �����ļ��Ĵ�С
    DWORD   dwReserve;		// ����
} HB_IMPT_REQ, *LPHB_IMPT_REQ;

typedef struct 
{
    BYTE   bySupportResolution[32];   	// �ò�����ʾnvr����֧�ֵ�����ֱ��ʸ�ʽ��
                                        // �����±����ӳ������(ӳ�������)��1��ʾ֧�֣�0��ʾ��֧��
                                        // ӳ���б�
                                        //      0-HDMI 1080P X 60HZ
                                        // 		1-HDMI 1080P X 50HZ
                                        // 		2-HDMI 720P X 60HZ 
                                        // 		3-HDMI 720P X 50HZ
                                        // 		4-VGA  1024 X 768
    BYTE    byCurResolution;			// �����˵�ǰ����ֱ���
    BYTE    reserve[7];				    // ����
} HB_NVR_RESOLUTION, *LPHB_NVR_RESOLUTION;


HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetWorkStatus(LONG lUserID, LPHB_SDVR_WORKSTATE_V2 lpWorkStatus, DWORD* lpDataSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetChnClientIP(LONG lUserID, LPHB_CLIENT_IP_INFO lpClientIP, DWORD* lpDataSize);

typedef struct HB_LOG_REQ_PARAM_ST
{
    WORD    wBeginYear;
    BYTE    byBeginMon;
    BYTE    byBeginDay;

    WORD    wEndYear;
    BYTE    byEndMon;
    BYTE    byEndDay;

    BYTE    byPriType;
    BYTE    bySecType;
    DWORD   dwReserve[4];
}HB_LOG_REQ_PARAM, *LPHB_LOG_REQ_PARAM;

HB_SDVR_API LONG __stdcall HB_SDVR_NvrFindLog(LONG lUserID, LPHB_LOG_REQ_PARAM lpParam);
HB_SDVR_API LONG __stdcall HB_SDVR_NvrFindNextLog(LONG lLogHandle, char* pLogData, BYTE* pEncType);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrFindLogClose(LONG lLogHandle);

HB_SDVR_API LONG __stdcall HB_SDVR_NvrSerialStart(LONG lUserID, LPHB_NVR_SERIAL_START lpSerial, DWORD dwDataSize,
            void(CALLBACK *fSerialDataCallBack)(LONG lSerialHandle,char *pRecvDataBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrSerialSend(LONG lSerialHandle, char* pSendData, DWORD dwDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrSerialStop(LONG lSerialHandle);

HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetDevInfo(LONG lUserID, LPHB_DEVICEINFO_V2 lpDevInfo, DWORD* lpDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrSetDevInfo(LONG lUserID, LPHB_DEVICEINFO_V2 lpDevInfo, DWORD dwDataSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetPtzList(LONG lUserID, LPHB_NVR_PTZLIST lpPtz, DWORD dwDataSize, LPHB_NVR_PTZLIST_INFO lpPtzInfo, DWORD* lpDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetAlarmAttr(LONG lUserID, LPHB_NVR_ALRM_PORT_ATTR lpAlarmAttr, DWORD* lpDataSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetAlarmInCfg(LONG lUserID, LPHB_NVR_ALRMININFO lpAlarmIn, DWORD* lpDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrSetAlarmInCfg(LONG lUserID, LPHB_NVR_ALRMININFO lpAlarmIn, DWORD dwDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetAlarmOutCfg(LONG lUserID, LPHB_NVR_ALARMOUTINFO lpAlarmOut, DWORD* lpDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrSetAlarmOutCfg(LONG lUserID, LPHB_NVR_ALARMOUTINFO lpAlarmOut, DWORD dwDataSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetAlarmInStatus(LONG lUserID, LPHB_NVR_ALRMIN_STATUS lpAlarmInStat, DWORD* lpDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetAlarmOutStatus(LONG lUserID, LPHB_NVR_ALRMOUT_STATUS lpAlarmOutStat, DWORD* lpDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrSetAlarmOutStatus(LONG lUserID, LPHB_NVR_ALRMOUT_STATUS lpAlarmOutStat, DWORD dwDataSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetPicCfg(LONG lUserID, BYTE byChnl, LPHB_NVR_CHN_ATTR_INFO lpChlInfo, DWORD* lpDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrSetPicCfg(LONG lUserID, LPHB_NVR_CHN_ATTR_INFO lpChlInfo, DWORD dwDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetRemoteResolution(LONG lUserID, LPHB_SDVR_REMOTE_RESOLUTION lpSdvrResolution, DWORD* lpDataSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetRecordCfg(LONG lUserID, LPHB_RECORD_SET lpRecordSet, DWORD* lpDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrSetRecordCfg(LONG lUserID, LPHB_RECORD_SET lpRecordSet, DWORD dwDataSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetMotDetCfg(LONG lUserID, LPHB_NVR_MOTION lpMotion, DWORD* lpDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrSetMotDetCfg(LONG lUserID, LPHB_NVR_MOTION lpMotion, DWORD dwDataSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetAbnorAlarmCfg(LONG lUserID, LPHB_NVR_ABNORMAL lpAbnor, DWORD* lpDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrSetAbnorAlarmCfg(LONG lUserID, LPHB_NVR_ABNORMAL lpAbnor, DWORD dwDataSize);

HB_SDVR_API LONG __stdcall HB_SDVR_NvrExpParamFile(LONG lUserID, char* pSaveFile);

#define HB_IMPORT_OK           0x01     // ����ɹ�
#define HB_TRANS_FILE_ERR      0x02     // ���ݴ������
#define HB_FILE_VERSION_ERR    0x03     // �ļ��汾����

typedef struct HB_PARAMFILE_STATUS_ST
{
    DWORD dwFileSize;
    DWORD dwGotSize;
    DWORD dwStatus;     // ����״̬�룬������ʱ��Ч
    DWORD dwReserve[4];
}HB_PARAMFILE_STATUS, *LPHB_PARAMFILE_STATUS;

HB_SDVR_API BOOL __stdcall HB_SDVR_NvrExpParamFileStatus(LONG lExpHandle, LPHB_PARAMFILE_STATUS lpExpStatus);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrExpParamFileClose(LONG lExpHandle);

HB_SDVR_API LONG __stdcall HB_SDVR_NvrImpParamFile(LONG lUserID, char* pImpFileName);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrImpParamFileStatus(LONG lImpHandle, LPHB_PARAMFILE_STATUS lpImpStatus);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrImpParamFileClose(LONG lImpHandle);

HB_SDVR_API BOOL __stdcall HB_SDVR_NvrGetResolution(LONG lUserID, LPHB_NVR_RESOLUTION lpResolution, DWORD* lpDataSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_NvrSetResolution(LONG lUserID, LPHB_NVR_RESOLUTION lpResolution, DWORD dwDataSize);

#define NET_SDVR_GET_ZERO_VENCCONF					0xA8	//��ȡ����ͨ����Ƶ����
#define NET_SDVR_SET_ZERO_VENCCONF					0xA9	//���ø���ͨ����Ƶ����

// ����ͨ�������������
typedef enum
{
    NET_AUSTREAM_DISABLE, //��Ƶ��
    NET_AUSTREAM_ENABLE, //������
}NET_AUSTREAMADD_E;

typedef enum
{
    NET_QCIF,   //QCIF
    NET_QVGA,   //QVGA
    NET_CIF,    //CIF
    NET_DCIF,   //DCIF
    NET_HD1,    //HD1
    NET_VGA,    //VGA
    NET_FD1,    //FD1
    NET_SD,     //SD
    NET_HD      //HD
}NET_RESOLUTION_E;

typedef enum
{
    NET_BITRATE_CHANGE,     //������
    NET_BITRATE_NOCHANGE,   //������
}NET_BITRATETYPE_E;

typedef enum
{
    NET_VQUALITY_BEST=0,    //���
    NET_VQUALITY_BETTER,    //�ϸ�
    NET_VQUALITY_GOOD,      //��
    NET_VQUALITY_NORMAL,    //��
    NET_VQUALITY_BAD,       //��
    NETT_VQUALITY_WORSE     //���
}NET_VQUALITY_E;

typedef struct
{
    NET_AUSTREAMADD_E   byStreamType;       //��Ƶ������
    NET_RESOLUTION_E    byResolution;       //��Ƶ�ֱ���
    NET_BITRATETYPE_E   byBitrateType;      //��������
    NET_VQUALITY_E      byPicQuality;       //ͼ������
    DWORD   dwVideoBitrate;                 //��Ƶ���� ʵ������
    WORD    dwVideoFrameRate;               //֡�� PAL 2-30 N 2-30
    WORD    quant;                          //�������� 1-31
}HB_SDVR_VENC_CONFIG, *LPHB_SDVR_VENC;

typedef struct 
{
    DWORD 					enable;     // ��ͨ��ʹ�ܣ�1-���ã�0-������
    char 					chlist[MAX_CHANNUM_EX];// ��ͨ�������ʽ���, ��Ӧͨ���������±��0��ʼ��ʾ, 0-��ѡ��, 1-ѡ��
    HB_SDVR_VENC_CONFIG 	venc_conf;  //�������
    DWORD 					reserve;    //����
}HB_SDVR_ZERO_VENC_CONFIG, *LPHB_SDVR_ZERO_VENC_CONFIG;

HB_SDVR_API LONG __stdcall HB_SDVR_ZeroRealPlay(LONG lUserID, LPHB_SDVR_CLIENTINFO lpClientInfo);
HB_SDVR_API BOOL __stdcall HB_SDVR_ZeroStopRealPlay(LONG lRealHandle);

HB_SDVR_API BOOL __stdcall HB_SDVR_ZeroGetConfig(LONG lUserID, DWORD dwCommand, LPVOID lpOutBuffer, LPDWORD lpOutBufferSize, LPDWORD lpReturned);
HB_SDVR_API BOOL __stdcall HB_SDVR_ZeroSetConfig(LONG lUserID, DWORD dwCommand, LPVOID lpInBuffer, DWORD dwBufferSize, LPDWORD lpReturned);


typedef struct TAG_HB_SDVR_VOD_PARAM 
{
    BYTE        byChannel;                  // ͨ���� [0, n-1],n:ͨ����
    BYTE        byType;                     // ¼������:1-�ֶ���2-��ʱ��4-�ƶ���8-������0xFF-ȫ��
    WORD        wLoadMode;                  // �ط�����ģʽ 1-��ʱ�䣬 2-������
    union
    {
        struct
        {
            HB_SDVR_TIME struStartTime;     // ���һ����Ȼ��
            HB_SDVR_TIME struStopTime;      // ����ʱ����ൽ23:59:59,��ʾ�ӿ�ʼʱ�俪ʼһֱ����

            char cReserve[16];
        }byTime;

        BYTE    byFile[64];                 // �Ƿ񹻳���
    }mode;

    DWORD dwReserve[4];                    // ���� 
}HB_SDVR_VOD_PARAM, *LPHB_SDVR_VOD_PARAM;

HB_SDVR_API LONG __stdcall HB_SDVR_Vod(LONG lUserID, LPHB_SDVR_VOD_PARAM pVodParam, HWND hWnd);

#define HB_SDVR_VOD_PLAYSTART   1
#define HB_SDVR_VOD_PLAYPAUSE   2
#define HB_SDVR_VOD_PLAYFAST    3
#define HB_SDVR_VOD_PLAYSLOW    4
#define HB_SDVR_VOD_PLAYNORMAL  5
#define HB_SDVR_VOD_PLAYFRAME   6
#define HB_SDVR_VOD_PLAYSETPOS  7
#define HB_SDVR_VOD_PLAYGETPOS  8

HB_SDVR_API BOOL __stdcall HB_SDVR_VodControl(LONG lVodHandle, DWORD dwControlCode, DWORD dwInValue, DWORD *lpOutValue);
HB_SDVR_API BOOL __stdcall HB_SDVR_StopVod(LONG lVodHandle);

//////////////////////////////////////////
////////IPC��Э��
/////////////////////////////////////////
#define HB_IPCCFG_THERMAL_IMAGING   1
#define HB_IPCCFG_IP_FILTER         2       // ip��ַ����
#define HB_IPCCFG_BLC               3       // ���ⲹ��
#define HB_IPCCFG_PROTOCL           4       // Э��
#define HB_IPCCFG_COLOR_OSD         5       // ��ɫOSD
#define HB_IPCCFG_ICR_SENSITIVITY   6       // ������

typedef struct TAG_HB_SDVR_IPC_THERMAL_IMAGING
{
    DWORD   dwSize;                         // �ṹ�峤��                 
    char    shutter_correct;                // ����У�� 0:not support 1:close 2:open      
    char    electronic_enlarge;             // ���ӷŴ� 0:not support 1:normal_display 2:enlarge_display
    char    pseudo_colormode;               // α��ģʽ 0:not support 1:white hot 2:black hot 3:fusion 4:rainbow 5:globow
                                            // 6:ironbow1 7:ironbow2 8:sepia 9:color1 10:color2 11:icefire 12:rain
    char    auto_correct_switch;            // �Զ�У������ 0:not support 1:close 2:open
    char    auto_agcmode;                   // �Զ�����ģʽ 0:��֧�� 1:�Զ����� 2:����ֱ��ͼ 3:һ������ 4:�Զ����� 5:�ֶ�
    char    contrast;                       // �Աȶ� ��0��255��
    short   light;                          // ���� -1:��֧��
    short   light_bias;                     // ����ƫ�� -1:��֧��
    short   reserve[3];                     // ����
}HB_SDVR_IPC_THERMAL_IMAGING, *LPHB_SDVR_IPC_THERMAL_IMAGING;

typedef struct TAG_HB_SDVR_IPC_IP_FILTER
{
    DWORD   dwSize;                 // sizeof(HB_SDVR_IPC_IP_FILTER)
    char    cIPFilter;              // ������IP��ַ���� 0-��֧�� 1-�� 2-�ر�
    char    cIPRule;                // ���� 1-����ͨ�� 2-������ͨ��
    char    cPortFilter;            // �˿ڹ��� 0-��֧�� 1-�� 2-�ر�
    char    cPortRule;              // ���� 1-����ͨ�� 2-������ͨ��
    DWORD   dwIPBegin;              // ������IP��ʼ��ַ
    DWORD   dwIPEnd;                // ������IP������ַ��������ַ��ֵҪ������ʼ��ַ��
                                    // ���������ַΪ�գ�����Ϊֻ������ʼ��ַ
    DWORD   dwPortBegin;            // ���˶˿���ʼ
    DWORD   dwPortEnd;              // ���˶˿ڽ���
    DWORD   dwReserve[3];           // ����
}HB_SDVR_IPC_IP_FILTER, *LPHB_SDVR_IPC_IP_FILTER;

typedef struct TAG_HB_SDVR_IPC_BLC
{
    DWORD   dwSize;                 // sizeof(HB_SDVR_IPC_BLC)
    BYTE    byBLCEnable;            // ���ⲹ�� 0-��֧�� 1-�� 2-�ر�
    BYTE    byReserve[3];           // ����
}HB_SDVR_IPC_BLC, *LPHB_SDVR_IPC_BLC;

typedef struct TAG_HB_SDVR_IPC_PROTOCL
{
    DWORD   dwSize;
    BYTE    byProtocl;              // 0��֧�֣� 1-7000sdk, 2-ONVIF(������������֡ͷ)
    BYTE    byReserve[3];
}HB_SDVR_IPC_PROTOCL, *LPHB_SDVR_IPC_PROTOCL;

typedef struct TAG_HB_SDVR_COLOR_OSD
{
    int     nLen;
    char    cColorosd[8][16];       // ֧��8����ɫ��ÿ����ɫ�ַ�������
    char    cColorosdIndex;         // ��ɫ����
    char    cReserve[3];
}HB_SDVR_COLOR_OSD, *LPHB_SDVR_COLOR_OSD;

typedef struct TAG_HB_SDVR_ICR_SENSITIVITY
{
    int    len;                 
	short  minicr;         //��Сicr������ֵ,�ӵײ��ȡ����������;    
	short  maxicr;         //���icr������ֵ,�ӵײ��ȡ����������;   
	short  curicr;         //��ǰicr������ֵ;   
	short  reserve;
}HB_SDVR_ICR_SENSITIVITY, *LPHB_SDVR_ICR_SENSITIVITY;

typedef struct TAG_HB_SDVR_IPC_CFG
{
    DWORD	dwIPCCfgType;	        // 1:STRUCT_IPC_THERMAL_IMAGING 2:...
    DWORD	dwSize;		            // sizeof(STRUCT_IPC_THERMAL_IMAGING)...
    union
    {
        HB_SDVR_IPC_THERMAL_IMAGING thermal;
        HB_SDVR_IPC_IP_FILTER       IPFilter;
        HB_SDVR_IPC_BLC             blc;
        HB_SDVR_IPC_PROTOCL         protocl;
        HB_SDVR_COLOR_OSD           colorosd;
        HB_SDVR_ICR_SENSITIVITY     icrsentivity;
    }cfg;
}HB_SDVR_IPC_CFG, *LPHB_SDVR_IPC_CFG;

HB_SDVR_API BOOL __stdcall HB_SDVR_SetIPCCfg(LONG lUserID, LPHB_SDVR_IPC_CFG lpCfg, DWORD dwSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_GetIPCCfg(LONG lUserID, LPHB_SDVR_IPC_CFG lpCfg, DWORD* pSize);

typedef struct TAG_HB_SDVR_IPSERVER
{
    DWORD   dwSize;
    DWORD   dwIP;                   // IPServer IP��ַ
    DWORD   dwPort;                 // IPServer �˿�
    BYTE    byRegID[64];            // �豸ע����
    char    reserve[4];
}HB_SDVR_IPSERVER, *LPHB_SDVR_IPSERVER;

HB_SDVR_API BOOL __stdcall HB_SDVR_SetIPServer(LONG lUserID, LPHB_SDVR_IPSERVER lpIPServer);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetIPServer(LONG lUserID, LPHB_SDVR_IPSERVER lpIPServer);


//0103 by xiebb IPC3��Э�����ϣ���ʱע�Ͳ���δʵ�ֹ���
typedef enum                    //IPC�����������
{
    IPC_VIDEO_CMD = 0,      //IPC����Ƶ����
    IPC_NET_CMD,            //IPC��������
    IPC_STORE_CMD,          //IPC�洢����
    IPC_ALARM_CMD,          //IPC�������� 
    IPC_MANAGE_CMD,         //IPC��������
    IPC_SERIAL_CMD,         //IPC��������
    IPC_PRI_CMD_MAX
}HB_SDVR_IPC_PRI_CMD_TYPE_E;

//////////////////////////////////////////////////////////////////////////////
//����Ƶ����
//////////////////////////////////////////////////////////////////////////////
typedef enum                    
{
    IPC_IMAGE_PARAM = 0,      //IPCͼ����� 
    IPC_VIDEO_PARAM,          //IPC��Ƶ����  
    IPC_VIDEO_ENCODE,         //IPC��Ƶ�������  
    IPC_PICTURE_SNAP,         //IPCͼ��ץ�Ĳ��� 
    IPC_OSD_OVERLAY,          //IPC�ַ����Ӳ���
    IPC_MASK,                 //IPC�ڵ�����   
    IPC_ADVANCE_PARAM,        //IPC�߼�����  
    IPC_AUDIO_IN_PARAM,       //IPC��Ƶ�������
    IPC_AUDIO_OUT_PARAM,      //IPC��Ƶ�������
    IPC_VIDEO_CMD_MAX
}HB_SDVR_IPC_VIDEO_CMD_TYPE_E;

//////////////////////////////////////////////////////////////////////////////
//��������
//////////////////////////////////////////////////////////////////////////////
typedef enum                    
{
    IPC_IP_PARAM = 0,           //IPC �����������   
    IPC_PPPOE,                  //IPC PPPOE����   
    IPC_E_MAIL,                 //IPC E_MAIL����   
    IPC_UPNP,                   //IPC UPNP����  
    IPC_PLATFORM,               //IPC ƽ̨��������Ϣ    
//     IPC_NAS,                    //IPC NAS����        ����δʵ�֣�  
//     IPC_AUTO_REGIST,            //IPC �Զ�ע�����   ����δʵ�֣�
//     IPC_WIRELESS_NETWORK,       //IPC �����������   ��ԭ��Э�飩
//     IPC_FTP,                    //IPC FTP����        ����δʵ�֣�
//     IPC_IP_FILTER,              //IPC IP��ַ���˲��� ��ԭ��Э�飩  
//     IPC_DDNS,                   //IPC DDNS����       ��ԭ��Э�飩  
    IPC_NET_CMD_MAX
}HB_SDVR_IPC_NET_CMD_TYPE_E;

//////////////////////////////////////////////////////////////////////////////
//�洢����
//////////////////////////////////////////////////////////////////////////////
typedef enum 
{   
    IPC_TIME_RECORD = 0,    //IPC��ʱ¼�����
    IPC_RECORD_MODE,        //�洢��ʽ
    IPC_DISK_CFG,           //IPC�洢�豸״̬
    IPC_STORE_CMD_MAX       //�洢���������ֵ
}IPC_STORE_CMD_TYPE_E;

//////////////////////////////////////////////////////////////////////////////
//��������
//////////////////////////////////////////////////////////////////////////////
typedef enum
{
    IPC_MOTION = 0,     //IPC�ƶ�������
    IPC_ALARMIN,        //IPC�����������
    IPC_ALARMOUT,       //IPC�����������
//     IPC_NET_BUG,        //IPC������ϱ�������    ����δʵ�֣�
//     IPC_STORE_BUG,      //IPC�洢���ϱ�������    ����δʵ�֣�
    IPC_ALARM_CMD_MAX   //�������������ֵ
}IPC_ALARM_CMD_TYPE_E;


//////////////////////////////////////////////////////////////////////////////
//����������
//////////////////////////////////////////////////////////////////////////////
typedef enum  
{
    IPC_DEVICE_INFO = 0,    //IPC�豸��Ϣ    
    IPC_AUTO_MAINTAINING,   //IPC�Զ�ά������
    IPC_ABILITY,            //IPCҳ�����������
    IPC_DOME_ABILITY,       //IPC���ҳ�����������
    IPC_MANAGE_CMD_MAX      //�豸�������������ֵ
} IPC_MANAGE_CMD_TYPE_E;


//////////////////////////////////////////////////////////////////////////////
//����������
//////////////////////////////////////////////////////////////////////////////
typedef enum 
{
    IPC_SERIAL_INFO = 0,    //IPC�豸��Ϣ  
    IPC_SERIAL_CMD_MAX      //�������������ֵ
} IPC_SERIAL_CMD_TYPE_E;


/*ʱ���*/
typedef struct
{
    WORD    uYear;      //��
    BYTE    uMonth;     //��
    BYTE    uDay;       //��
    BYTE    uWeek;      //����
    BYTE    uHour;      //Сʱ
    BYTE    uMin;       //����
    BYTE    uSec;       //��
}HB_SDVR_IPC_SYS_TIME;

typedef struct
{
    BYTE    uStartHour; //��ʼ
    BYTE    uStartMin;
    BYTE    uEndHour;   //����
    BYTE    uEndMin;
}HB_SDVR_IPC_TIME_PERIOD;

typedef struct
{
    BYTE    uSelect[4]; //0-no   1-yes
    HB_SDVR_IPC_TIME_PERIOD Period[4];
}HB_SDVR_IPC_TIME_ITEM;

typedef struct
{
    int     nStatus;                    // 0-off, 1-on
    HB_SDVR_IPC_TIME_ITEM  Item[8];     // 0-7: everyday, monday...sunday
}HB_SDVR_IPC_TIME_SCHEDULE;

/*ͼ�����*/
typedef struct
{                                                                      
    HB_SDVR_IPC_TIME_PERIOD  Time;      //ʱ��� 
    short    sBrightValue;              //���ȣ�ȡֵ[0, 255] -1-��֧�� ȱʡֵ128
    short    sContrastValue;            //�Աȶȣ�ȡֵ[0, 255] -1-��֧�� ȱʡֵ128
    short    sSaturationValue;          //���Ͷȣ�ȡֵ[0, 255] -1-��֧�� ȱʡֵ128
    short    sHueValue;                 //ɫ�ȣ�ȡֵ[0, 255] -1-��֧�� ȱʡֵ128     
    short    sSharpness;                //������ã�ȡֵ��ΧΪ��[0,255] -1-��֧�� ȱʡֵ128
    short    sReserve;        
}HB_SDVR_IMAGE_PARAM_ITEM;
typedef struct
{                                                                     
    int     nLens;          
    int     nChannelid;
    HB_SDVR_IMAGE_PARAM_ITEM Item[3];   //0-Ĭ�� 1-ʱ���1 2-ʱ���2   
}HB_SDVR_IPC_IMAGE_PARAM;

/*��Ƶ����*/
typedef struct
{
    int   nLensIris;            //��Ȧ -1-��֧�� 0-�Զ� 1-�ֶ�
    int   nLensIndex;           //��ǰ����֧�ֵľ�ͷ��-1-��֧��-�ݲ�֧��
    BYTE  uLensVal[16][32];     //��ȡ��ͷ��֧���б�ֻ��-�ݲ�֧��              
}HB_SDVR_IPC_LENS;
typedef struct
{   
    int  nAeContrl;             //-1-��֧�� 0-�ֶ� 1-�Զ�
    int  nShutterIndex;         //shutter������-1-��֧�֣���AEΪ�ֶ�ʱ���ã���shutter_index=0;����ʱ��Ϊshutter_val[0]=1000�������ʱ��Ϊ1/1000
    int  nShutterVal[32];       //����ʱ���֧�ֲ����б�,ֻ��
    int  nAgcIndex;             //agc������-1-��֧�֣���AEΪ�ֶ�ʱ���ã���agc_index=0;agcֵΪagc_val[0] = 32;
    int  nAgcVal[32];           //AGC���Զ����棩��֧�ֲ����б�,ֻ����
}HB_SDVR_IPC_AE;
typedef struct
{
    int nMaxValue;              //���ֵ
    int nMinValue;              //��Сֵ
    int nCurValue;              //��ǰֵ
}HB_SDVR_IPC_ICR_ABILITY;
typedef struct
{
    int  nDaynightModel;                        //��ҹģʽ  -1-��֧�� 0-�Զ� 1-��ɫ 2-�ڰ�
    int  nIcrEnable;                            //ʹ�� -1--��֧��  0--����ֵ��Ч  1--ʱ�����Ч   
    int  nLightRange;                           //������ֵ 1-100
    HB_SDVR_IPC_ICR_ABILITY BlackwhiteValue;    //��ת�ڵķ�ֵ
    HB_SDVR_IPC_ICR_ABILITY ColorValue;         //��ת�ʵķ�ֵ
    int  nMinInterval;                          //�ڰ��л����ɫ�л�֮�����С����� ֻ��
    HB_SDVR_IPC_TIME_PERIOD TimeRange[2];       //ʱ���                                                                          
}HB_SDVR_IPC_DAY_NIGHT;
typedef struct
{
    int     nLens;
    int     nChannelid;              
    HB_SDVR_IPC_AE           AeModel;       //AEģʽ                    
    HB_SDVR_IPC_DAY_NIGHT    Daynight;      //��ҹģʽ                             
    int     nImageFlip;                     //ͼ��ת -1-��֧�� 0-����ת 1-ˮƽ��ת 2-��ֱ��ת 3-ˮƽ&��ֱ
    int     nImagSpin;                      //ͼ����ת -1-��֧�� 0-����ת 1-˳ʱ����ת90��2-˳ʱ����ת180��3-˳ʱ����ת270��  
    int     nSceneModel;                    //��ƽ�ⳡ��ģʽ -1-��֧�� 0-δ���� 1-�Զ�, 2-sunny, 3-shadow, 4-indoor,����     
}HB_SDVR_IPC_VIDEO_PARAM;

/*��Ƶ�������*/
typedef struct
{
    int nResolutionIndex;               //-1-��֧�֣�
    int nResolution[32][2];             //�û���֧�ֵķֱ������Ϊ32����ֻ��,�ֱ�Ϊ32���ߣ���resolution_index=1;resolution[1][0] = 1920;resolution[1][1] = 1080;��ǰ�ֱ���Ϊ1920*1080 
}HB_SDVR_IPC_RESOLUTION_PARAM;
typedef struct
{
    short sMinFramerate;
    short sMaxFramerate; 
    short sCurFramerate; 
    short sReserve;   
}HB_SDVR_IPC_FRAMERATE;

typedef struct
{
    char        cEnable;                    //ʹ�� -1-��֧�� 0-off, 1-on     
    char        cEncodeType;                //�������� 0-H264 1-MJPEG 
    char        cStreamControl;             //�������� 0-������ 1-������
    BYTE        bIFrame;                    //I֡���  1-255  
    WORD        uVideoBitrate;              //��Ƶ����  -1-��֧�� 0-128K��1-256K��2-384K��3-512K��4-1M��5-1.5M��6-2M��7-3M, 8-4M��9-5M��10-6M��11-7M��12-8M, 13-�Զ���,��KΪ��λ��128k-12M����
    short       sAudioEnable;               //��Ƶ -1-��֧�� 0-off, 1-on
    HB_SDVR_IPC_RESOLUTION_PARAM Resolution;//�ֱ���         
    HB_SDVR_IPC_FRAMERATE        Framerate; //����֡������          
}HB_SDVR_IPC_STREAM_PARAM;
typedef struct
{
    int     nLens;
    int     nChannelid;
    short   sComboIndex;                    //��ǰ�ײ�ֵ 0-�Զ��� 1-�ײ�һ 2-�ײͶ� 3-�ײ�������      
    short   sComboNum;                      //���ײ�����
    char    cCombo[256];                    //�ײ����� ֻ��(�ֱ���+����+֡��+���뷽ʽ)
    HB_SDVR_IPC_STREAM_PARAM Stream[4];     //0-������ 1-������1 2-������2 3-������3 ���ײ�ֵΪ�Զ���ʱ�������ã��������ֻ�� 
    int nReserved;      
}HB_SDVR_IPC_VIDEO_ENCODE;

/*�ַ�����*/
typedef struct
{
    int nPosx;      //x����
    int nPosy;      //y����
    int nReserved;
}HB_SDVR_IPC_OSD_POS;
typedef struct
{
    int  nEnable;                   //ʹ�� -1-��֧�� 0-�ر� 1-���� 
    HB_SDVR_IPC_OSD_POS OsdPos;            
    char cOsdStrings[128];          //�Զ���OSD���� 
    int  nReserved;                 //�Զ���OSD����
}HB_SDVR_IPC_OSD_USERDEF;
typedef struct
{
    int     nLens;
    int     nChannelid;
    int     nOsdEnable;                     //OSDʹ�� -1-��֧�� 0-off, 1-on                    
    short   sOsdAttribute;                  //OSD���� 0-��͸�� 1-͸�� 
    short   sOsdAddModel;                   //OSD���ӷ�ʽ 0-ǰ�˵��� 1-��˵���           
    short   sChNameEnable;                  //�Ƿ���ʾͨ����-1-��֧�� 0-����ʾ 1-��ʾ
    short   sTimeInfoEnable;                //�Ƿ���ʾʱ��  -1-��֧�� 0-off, 1-on      
    short   sWeekDisplay;                   //�Ƿ���ʾ����  -1-��֧�� 0-off, 1-on  
    short   sTimeFormat;                    //ʱ���ʽ   0- YYYY-MM-DD 1- DD-MM-YYYY 2- MM-DD-YYYY                     
    short   sInverseColor;                  //OSD��ɫ -1-��֧�� 0-off, 1-on 
    short   sColorIndex;                    //OSDǰ��������ɫ  -1-��֧��
    char    cColor[8][16];                  //OSDǰ��������ɫ�� 
    char    cChName[32];                    //ͨ���� �ַ�����               
    HB_SDVR_IPC_OSD_POS     ChNamePos;      //ͨ��������                    
    HB_SDVR_IPC_OSD_POS     TimePos;        //ʱ������                
    HB_SDVR_IPC_OSD_USERDEF OsdUserdef[8];  //OSD�û��Զ��� Ԥ�� ��δʹ��         
}HB_SDVR_IPC_OSD_OVERLAY;

/*��Ƶ�ڵ�����*/        //ͬD1�ֱ��ʵȱ�������
typedef struct
{
    int nStartx;        //�ڵ��������X���� 0~704         
    int nStarty;        //�ڵ��������Y���� 0~576      
    int nWidth;         //�ڵ������� 0~704        
    int nHeight;        //�ڵ�����߶� 0~576    
}HB_SDVR_IPC_MASK_AREA;
typedef struct
{
    int   nLens;
    int   nChannelid;
    int   nMaskEnable;                  //�ڵ���ʹ��  -1-��֧�� 0-off, 1-on
    HB_SDVR_IPC_MASK_AREA Maskarea[8];  //��Ƶ�ڵ��������֧���ڵ�8��
}HB_SDVR_IPC_MASK;

/*����*/
typedef struct
{
    BYTE   uIp[4];          //ip��ַ ��IPΪ192.168.9.31,ip[0]=192 ip[1]=168 ip[2]=9 ip[3]=31;
    BYTE   uMask[4];        //��������
    BYTE   uGateway[4];     //Ĭ������
    BYTE   uDns[4];         //��ѡDNS 
    BYTE   uDnsBak[4];      //��ѡDNS
}HB_SDVR_IPC_IPV4;

typedef struct
{
    WORD    uIp[8];
    BYTE    uGateway[16];       
    BYTE    uDns[16];           
    BYTE    uDnsBak[16];       
    DWORD   uSubnetPrefix;     //����ǰ׺����    
}HB_SDVR_IPC_IPV6;

typedef struct
{
    int    nLens;
    BYTE   uNetInterface;           //����ӿ� 1-10MBase-T 2-10MBase-Tȫ˫�� 3-100MBase-TX 4-100Mȫ˫�� 5-10M/100M����Ӧ   
    BYTE   uNetModel;               //����ģʽ 0-��̬ 1-DHCP  
    BYTE   uMacAddr[6];          
    HB_SDVR_IPC_IPV4     Ipv4;               
    HB_SDVR_IPC_IPV6     Ipv6;               
    int    nListenPort;        
    int    nHttpPort;          
    int    nMulticast;              // 1-multibroadcast   
}HB_SDVR_IPC_IP_PARAM;  

/*��ʱ¼�����*/
typedef struct
{
    int    nLens;
    int    nChannelid;
    HB_SDVR_IPC_TIME_SCHEDULE Schedule;
    int    nReserved;     
}HB_SDVR_IPC_TIME_RECORD;

/*¼��洢��ʽ*/
typedef struct
{
    int    nLens;               
    int    nChannelid;         
    int    nCoverDelete;        //�洢�豸��ʱ���Ƿ��Զ�ɾ�����ļ�  0-��ɾ�� 1-������                     
    char   cManualRcd[8];       //�ֶ�¼��洢��ʽ -1-��֧�� 0-δѡ�� 1-ѡ�У������±꣺0-SD/TF 1-FTP 2-NAS       
    char   cTimeRcd[8];         //��ʱ¼��洢��ʽ -1-��֧�� 0-δѡ�� 1-ѡ�У������±꣺0-SD/TF 1-FTP 2-NAS          
    char   cLinkageRcd[8];      //����¼��洢��ʽ -1-��֧�� 0-δѡ�� 1-ѡ�У������±꣺0-SD/TF 1-FTP 2-NAS      
}HB_SDVR_IPC_RECORD_MODE;

/*�洢�豸״̬*/
typedef struct
{
    char    cDevName[16];       //�豸����     
    char    cStatus[32];        //����״̬   
    float   fDiskcapacity;      //���̴洢���� ��λGB     
    float   fDiskFree;          //���̴洢����ʣ�� ��λGB       
    float   fPrerecTime;        //�洢��Ԥ�ƿ�¼ʱ�� ��λСʱ       
}HB_SDVR_IPC_DISK_PARAM;
typedef struct
{   
    int    nLens;             
    int    nDisknum;                        //��������                            
    HB_SDVR_IPC_DISK_PARAM Diskinfo[12];    //������Ϣ 
}HB_SDVR_IPC_DISK_CFG;

/*E-mail����*/
typedef struct 
{
    int     nLens;
    int     nEnable;            //ʹ��  -1-��֧�� 0-off, 1-on        
    int     nMd5Auth;           //֧��MD5���� -1-��֧�� 0-off, 1-on           
    int     nUseIpv6;           //ʹ��IPV6�����ʼ� -1-��֧�� 0-off, 1-on          
    int     nUseSsl;            //����SSL -1-��֧�� 0-δ���� 1-����      
    int     nUseStarttls;       //����STARTTLS -1-��֧�� 0-δ���� 1-����       
    short   sAccessoryEnable;   //����ʹ�� -1-��֧�� 0-off, 1-on     
    WORD    uPort;              //�������˿ڣ������ʼ�(SMTP)�˿ڣ�Ĭ��ֵ25         
    char    cSmtpServer[128];   //�����ʼ���SMTP�����������磺163�������smtp.163.com �ԡ�\0�������ַ���     
    char    cUserName[32];      //�ʼ��û����ԡ�\0�������ַ���        
    char    cPwd[32];           //�ʼ��û������ԡ�\0�������ַ���     
    char    cSendPerson[128];   //�����˵�ַ�ԡ�\0�������ַ���    
    char    cRecvPerson[256];   //�ռ��˵�ַ������Ƕ���ʼ���ַ����';'�����ԡ�\0�������ַ���   
    int     nSendPeriod;        //�ϴ�����,��λ(����)[1, 10]        
    int     nSnapEnable;        //�Ƿ�ץ���ϴ�  -1-��֧�� 0-off, 1-on     
    char    cMailTopic[32];     //�ʼ�����      
}HB_SDVR_IPC_E_MAIL; 

/*PPPOE����*/
typedef struct
{
    int     nLens;
    int     nAutoCon;           //PPPOE�Զ�������0-���Զ����� 1-�Զ�����
    int     nState;             //����״̬  0-�Ͽ� 1-����  
    char    cUserName[32];      //�û���
    char    cPwd[32];           //����
    int     nPpppoeSave;        //PPPOE��Ϣ����: 0-������ 1-���� 
    BYTE    uIpv4[4];           //ipv4 ip��ַ (ֻ��)
    BYTE    uGatewayv4[4];      //ipv4 ���� (ֻ��)     
    WORD    uIpv6[8];           //ipv6 ip��ַ ����       
    BYTE    uGatewayv6[16];     //ipv6 ����   ����
}HB_SDVR_IPC_PPPOE;

/*�ƶ�������*/
typedef struct 
{
    int  nRecord;       //¼��     -1-��֧�� 0-off, 1-on
    int  nDelayTime;    //¼���ӳ�ʱ�� 10-300��  �ݲ�֧��
    int  nRecordTime;   //¼��ʱ��  5-300��
    int  nReserved[2];  
}HB_SDVR_IPC_LINKAGE_RECORD;
typedef struct 
{
    int nPtz;           //��̨ʹ��    -1-��֧�� 0-off, 1-on
    int nPtzItem;       //��̨���÷�ʽ -1-��֧�� 0-Ԥ�õ� 1-���Ѳ��    
    int nPtzAddr;       //Ԥ�õ�      -1-��֧�� 1-16 ����ptz_itemΪ0ʱ ���ô��
    int nReserved;   
}HB_SDVR_IPC_LINKAGE_PTZ;
typedef struct
{
    int nAlarmOut;      //������� -1-��֧�� 0-off, 1-on  
    int nAlarm;         //���������� 0-������1 1-������2 2-������3 3-������4  
    int nDelayTime;     //�����ӳ�ʱ��  10-300��  �ݲ�֧��
    int nContinueTime;  //������ʱʱ�� ֻ��
}HB_SDVR_IPC_LINKAGE_ALARM;
typedef struct
{
    int     nSnap;      //ͼƬץ�� -1-��֧�� 0-off, 1-on
    short   sDelayTime; //�����ʼ��ӳ�ʱ�� 10-300�� �ݲ�֧��  �ݲ�֧��
    short   sPicNum;    //ץ������ 1-10  
    int     nReserved;       
}HB_SDVR_IPC_LINKAGE_SNAP;
typedef struct 
{
    int  nEmail;        //�����ʼ� -1-��֧�� 0-off, 1-on
    int  nDelayTime;    //�����ʼ��ӳ�ʱ�� 5-300�� 
    int  nReserved;   
}HB_SDVR_IPC_LINKAGE_MAIL;
typedef struct
{ 
    HB_SDVR_IPC_LINKAGE_MAIL   Mail;     
    HB_SDVR_IPC_LINKAGE_SNAP   Snap;     
    HB_SDVR_IPC_LINKAGE_ALARM  Alarm;   
    HB_SDVR_IPC_LINKAGE_PTZ    Ptz;      
    HB_SDVR_IPC_LINKAGE_RECORD Record;  
}HB_SDVR_IPC_LINKAGE;
typedef struct 
{
    int                         nLens;
    int                         nChannelid;
    int                         nMotionEnable;            
    DWORD                       dwMotionBlock[18];        
    int                         nSensitivity;             
    int                         nDebounce;                
    HB_SDVR_IPC_TIME_SCHEDULE   MonitorTime;            
    HB_SDVR_IPC_LINKAGE         LinkageOut;             
}HB_SDVR_IPC_MOTION;

/*��������*/
typedef struct
{
    int                     nLens;          
    HB_SDVR_IPC_TIME_SCHEDULE    MonitorTime;   //�������벼��ʱ�� 
    HB_SDVR_IPC_LINKAGE          LinkageOut;    //�������
    BYTE                    byAlarmInNum;       //���������ܸ��� ֻ��
    BYTE                    byAlarmInNo;        //��������ͨ���ţ� 0-��������1 1-��������2 2-��������3 3-��������4
    BYTE                    byAlarmInType;      // 0��������1������ 
    BYTE                    byReserve[5]; 
}HB_SDVR_IPC_ALARMIN;

/*�������*/
typedef struct 
{
    int                 nLens;       
    HB_SDVR_IPC_TIME_SCHEDULE  MonitorTime; //�����������ʱ��         
    BYTE                byAlarmOutNum;       //��������ܸ��� ֻ��
    BYTE                byAlarmOutNo;        //�������ͨ���ţ� 0-�������1 1-�������2 2-�������3 3-�������4
    WORD                wAlarmTime;        //�������ʱ�� 10-300��  
    BYTE                byReserve[4]; 
}HB_SDVR_IPC_ALARMOUT;

/*������ϱ�������*/
typedef struct 
{
    int  nLens;
    int  nEnable;           //ʹ�� -1-��֧�� 0-off, 1-on   
    short sRecordEnable;    //¼��ʹ�� -1-��֧�� 0-off, 1-on 
    short sAlarmEnable;     //����ʹ�� -1-��֧�� 0-off, 1-on                  
    short sRecordTime;      //¼��ʱ��  1-60����                     
    short sAlarmoutTime;    //�������ʱ��  ֻ��     
}HB_SDVR_IPC_NET_BUG;

/*�洢���ϱ�������*/
typedef struct
{
    short sEnable;          //ʹ�� -1-��֧�� 0-off, 1-on                         
    short sEmail;           //�����ʼ�  -1-��֧�� 0-off, 1-on  
    short sAlarmoutEnable;  //�������  -1-��֧�� 0-off, 1-on
    short sAlarmoutDelay;   //��������ӳ�ʱ��    10-300�� 
}HB_SDVR_IPC_SAVE_BUG_PROCESS;
typedef struct 
{
    int  nLens;
    HB_SDVR_IPC_SAVE_BUG_PROCESS NoSd;      //��SD��
    HB_SDVR_IPC_SAVE_BUG_PROCESS NoFreeSd;  //SD���ռ䲻��
    HB_SDVR_IPC_SAVE_BUG_PROCESS ErrorSd;	//SD������    
}HB_SDVR_IPC_STORE_BUG;

typedef union
{
    HB_SDVR_IPC_MOTION     Motion;
    HB_SDVR_IPC_ALARMIN    Alarmin;
    HB_SDVR_IPC_ALARMOUT   Alarmout;
//     HB_SDVR_IPC_NET_BUG    NetBug;
//     HB_SDVR_IPC_STORE_BUG  StoreBug;
}HB_SDVR_IPC_ALARM_CFG_U;

/*�豸��Ϣ��ȡ*/
typedef struct
{
    int     nLens;
    char    cDevName[32];       //��Ʒ����      
    char    cdDevType[32];      //��Ʒ�ͺ�    
    char    cSoftVersion[32];   //����汾 
//     char    cImprint[32];       //��Ȩ˵��       
//     BYTE    uSn[4];             //���к�       
//     BYTE    uMacAddr[6];        //�����ַ  
//     BYTE    uReserved[2];
    BYTE    byDevNo[4];         //�豸���
    char    cReserved[2];
}HB_SDVR_IPC_DEVICE_INFO;

/*�Զ�ά��������ȡ*/
typedef struct
{
    int     nLens;
    short   sAutoReboot;                //�Զ�����ʹ�� -1-��֧�� 0-off, 1-on
    short   sStyle;                     //�Զ�ά����ʽ 0-�� 1-����
    HB_SDVR_IPC_SYS_TIME RebootTime;    //����ʱ��      
}HB_SDVR_IPC_AUTO_MAINTAINING;

/*IPCҳ�������������ȡ*/
typedef struct
{
    BYTE    byImageParam;        //ͼ����� 0-��֧��, 1-֧��
    BYTE    byVideoParam;        //��Ƶ���� 0-��֧��, 1-֧��
    BYTE    byVideoEncode;       //��Ƶ���� 0-��֧��, 1-֧��
    BYTE    byPictureSnap;       //ͼ��ץ�� 0-��֧��, 1-֧��
    BYTE    byOsdOverlay;        //�ַ����� 0-��֧��, 1-֧�� 
    BYTE    byMask;              //��Ƶ�ڵ� 0-��֧��, 1-֧��
    BYTE    byAudioInParam;      //��Ƶ���� 0-��֧��, 1-֧��
    BYTE    byAudioOutParam;     //��Ƶ��� 0-��֧��, 1-֧��
    BYTE    byAdvanceParam;      //�߼����� 0-��֧��, ��0-֧�� 
    BYTE    byReserve[3];   
}HB_SDVR_IPC_AV_ABILITY;
typedef struct
{
    BYTE    byIpParam;       //��������  0-��֧��, 1-֧��
    BYTE    byPppoe;         //PPPOE     0-��֧��, 1-֧��
    BYTE    byEmail;         //E_mail    0-��֧��, 1-֧��
    BYTE    byReserve1;     
    BYTE    byPlatform;      //ƽ̨������ 0-��֧��, 1-֧��
    BYTE    byReserve2[2]; 
    BYTE    byUpnp;          //UPNP      0-��֧��, 1-֧��
    BYTE    byWireless;      //��������  0-��֧��, 1-֧��
    BYTE    byDdns;          //DDNS 0-��֧��, 1-֧��
    //     BYTE    byFtp;           //FTP       0-��֧��, 1-֧��
    //     BYTE    byNas;           //NAS       0-��֧��, 1-֧��
    //     BYTE    byAutoRegist;    //�Զ�ע��  0-��֧��, 1-֧��
    BYTE    byReserve[2]; 
}HB_SDVR_IPC_NET_ABILITY;
typedef struct
{
    BYTE    byMotion;        //�ƶ���� 0-��֧��, 1-֧��
    BYTE    byAlarmin;       //�������� 0-��֧��, 1-֧��
    BYTE    byAlarmout;      //������� 0-��֧��, 1-֧��
//     BYTE    byNetBug;        //������� 0-��֧��, 1-֧��
//     BYTE    byStoreBug;      //�洢���� 0-��֧��, 1-֧��
    BYTE    byReserve[5]; 
}HB_SDVR_IPC_ALARM_ABILITY;
typedef struct
{
    int                  nLens;      
    HB_SDVR_IPC_AV_ABILITY      Av;     //����Ƶ      
    HB_SDVR_IPC_NET_ABILITY     Net;    //����     
    HB_SDVR_IPC_ALARM_ABILITY   Alarm;  //���� 
    BYTE                  byStore;        //�洢���� 0-��֧��, 1-֧��   
    BYTE                  bySerial;       //�������� 0-��֧��, 1-֧��
    BYTE                  byManage;       //ϵͳ���� 0-��֧��, 1-֧��
    BYTE                  byReserve; 
}HB_SDVR_IPC_ABILITY;
typedef struct
{
    BYTE     byEnable;          //���ʹ�� 0-��֧��, 1-֧��
    BYTE     byAdvanceParam;    //�߼����� 0-��֧��, 1-֧��  
    BYTE     byLimit;   	    //��λ     0-��֧��, 1-֧��       
    BYTE     byZeroAngle;       //�㷽λ�� 0-��֧��, 1-֧��
    BYTE     byPark;            //����     0-��֧��, 1-֧��   
    BYTE     byTimeTask;        //��ʱ���� 0-��֧��, 1-֧��    
    BYTE     byClear; 	        //���ʹ�� 0-��֧��, 1-֧��      
    BYTE     reserve[32];
}HB_SDVR_IPC_DOME_ABILITY;
typedef union
{
    HB_SDVR_IPC_DEVICE_INFO        DevInfo;
    HB_SDVR_IPC_AUTO_MAINTAINING   AutoMaintaining;
    HB_SDVR_IPC_ABILITY            Ability;   
    HB_SDVR_IPC_DOME_ABILITY       DomeAbility;
    //HB_SDVR_IPC_NTP_PARAM          NtpParam;
}HB_SDVR_IPC_MANAGE_CFG_U;

/*ͼ��ץ�Ĳ�����ȡ*/
typedef struct
{
    int        nLens;    
    int        nChannelid;     
    char       cSnapEnable;             //ͼ��ץ��ʹ�� -1-��֧�� 0-off, 1-on                               
    BYTE       bySnapType;              //ץ������ 0-��ͨץͼ 1-����ץͼ    
    BYTE       byPictureQuality;        //ͼƬ���� 0-�� 1-�ϲ� 2-һ�� 3-�Ϻ� 4-��
    BYTE       bySnapSpeed;             //ץ���ٶ� ��λ����/�ţ� 1��/�� 2��/�š���     
    int        nSnapResIndex;           //ͼ��ץ�ĵ�ǰ�ֱ��ʣ�-1-��֧�֣�     
    int        nSnapRes[32][2];         //�û���֧�ֵķֱ������Ϊ32����ֻ�ܻ�ȡ,�ֱ�Ϊ32���ߣ���snapshot_res_index=1;snapshot_res[1][0] = 1920;snapshot_res[1][1] = 1080;��ǰ�ֱ���Ϊ1920*1080     
    int        nPictureFormatIndex;     //ͼƬ��ʽ -1-��֧��
    char       cPictureFormat[5][8];    //ͼƬ��ʽ�б� 
    HB_SDVR_IPC_TIME_SCHEDULE Schedule;    
}HB_SDVR_IPC_PICTURE_SNAP;

/*�߼�������ȡ*/
typedef struct
{
    HB_SDVR_IPC_LENS         IrisModel; //��Ȧ       
    char            cVoutType;          //ģ����Ƶ���-1-��֧�� 0-NTSC, 1-PAL
    char            cAntiFlicker;       //����˸  -1-��֧�� 0- 50Hz 1- 60Hz         
    char            cWdr;               //��̬  -1-��֧�� 0-off, 1-on         
    int   			nDenoise3dVal;      //3D����ֵ -1-��֧�� 0-255
    char            cDenoise2d;         //2D����   -1-��֧�� 0-off, 1-on         
    char            cBlc;               //���ⲹ�� -1-��֧�� 0-off, 1-on        
    char            cEncodeType;        //����ģʽ -1 ��֧�� 0-��ͨ 1-����ʱ
    char            cFocusSpeed;        //��ѧ�佹�ٶ�ֵ��-1-��֧�� 1-100  �ݲ�֧��    
    char            cDigitalFoucus;     //���ֱ佹ֵ��-1-��֧�� 1-100      �ݲ�֧��  
    char            cAutoDropframe;     //ҹ���Զ���֡  -1-��֧�� 0-off, 1-on     
    char            cStreamType;        //�������� 0-�޺���ͷ 1-�к���ͷ �ݲ�֧�� 
    char            cReserved[6];
}HB_SDVR_IPC_A5_ADVANCE;
typedef struct
{
    char            cAntiFlickerEnable; //����˸ʹ��  -1-��֧�� 0-off, 1-on        
    char            cAntiFlicker;       //����˸  0- 50Hz 1- 60Hz         
    char            cWdr;               //���ֿ�̬  -1-��֧�� 0-off, 1-on         
    char            cWdrType;           //��̬ģʽѡ�� -1-��֧�� 0-����ģʽ, 1-��̬ģʽ
    char            cTimeDomain;        //3D����ʱ����  -1-��֧�� 0-63        
    int   			nSpaceDomain;       //3D����ռ���  -1-��֧�� 0-255
    char            cDenoise2d;         //2Dȥ��   -1-��֧�� 0-off, 1-on         
    char            cDeFog;             //ȥ��     -1-��֧�� 0-off, 1-on
    char            cPseudoColor;       //ȥα��   -1-��֧�� 0-off, 1-on
    BYTE            byPseudoColorNum;   //ȥα��ֵ 0-255
    char            cEncodeType;        //����ģʽ 0-��ͨ 1-����ʱ
    char            cVoutType;          //ģ����Ƶ���-1-��֧�� 0-NTSC, 1-PAL
    char            cAutoDropframe;     //ҹ���Զ���֡  -1-��֧�� 0-off, 1-on       
    char            cStreamType;        //�������� 0-�޺���ͷ 1-�к���ͷ �ݲ�֧�� 
    char            cReserved[7];
}HB_SDVR_IPC_HISI_ADVANCE;
typedef struct
{
    int             nLens;    
    int             nChannelid;         //ͨ���� [0, n��1] n:ͨ����     
    int             nType;              //ͬ��ȡIPC������������advance_param��ֵһ��,1��A5��2��HISI      
    int             nSize;              //��Ӧunion cfg�нṹ��Ĵ�С    
    union
    {
        HB_SDVR_IPC_A5_ADVANCE    A5Advance;  
        HB_SDVR_IPC_HISI_ADVANCE  HisiAdvance; 
    }cfg;
}HB_SDVR_IPC_ADVANCE_PARAM;

/*��Ƶ���������ȡ*/
typedef struct
{
    int             nLens;    
    int             nChannelid; 
    short           nReserved;              
    short           cVolumeIn;              //����  0-100 
    int             cAudioInIndex;          //��Ƶ����Դ -1-��֧��   
    BYTE            cAudioIn[8][16];        //��Ƶ����Դ�б� (�ַ���)qudiao  
    int             cCompressFormatIndex;   //��Ƶѹ����ʽ -1-��֧��     
    BYTE            cCompressFormat[16][10];//��Ƶѹ����ʽ�� (�ַ���)   
    int             nBitrateIndex;          //��Ƶ���� -1-��֧��   
    DWORD           dwBitrate[16];          //��Ƶ���ʱ� (����)
    int             nSamplerateIndex;       //��Ƶ������ -1-��֧��   
    DWORD           dwSamplerate[16];       //��Ƶ�����ʱ� (����)    
}HB_SDVR_IPC_AUDIO_IN_PARAM;

/*��Ƶ���������ȡ*/
typedef struct
{
    int             nLens;    
    int             nChannelid; 
    short           nReserved;              
    short           cVolumeOut;             //����  0-100 
    int             cAudioOutIndex;         //��Ƶ���Դ -1-��֧��   
    BYTE            cAudioOut[8][16];       //��Ƶ���Դ�б�   
    int             cCompressFormatIndex;   //��Ƶѹ����ʽ -1-��֧��     
    BYTE            cCompressFormat[16][10]; //��Ƶѹ����ʽ��    
    int             nBitrateIndex;          //��Ƶ���� -1-��֧��   
    DWORD           dwBitrate[16];          //��Ƶ���ʱ�
    int             nSamplerateIndex;       //��Ƶ������ -1-��֧��   
    DWORD           dwSamplerate[16];       //��Ƶ�����ʱ�     
}HB_SDVR_IPC_AUDIO_OUT_PARAM;

/*FTP������ȡ*/
typedef struct
{
    int     nLens;                
    short   sEnable;                //ʹ��  -1-��֧�� 0-off, 1-on          
    WORD    uPort;                  //�˿ں�     
    char    cServerAddress[128];    //��������ַ 
    char    cUsername[32];          //�û���   
    char    cPwd[32];               //����
    char    cSavePath[128];         //Զ�̴洢·��
}HB_SDVR_IPC_FTP;

/*ƽ̨������ȡ*/
typedef struct 
{
    char    cDeviceId[32];          //�豸ID       
    int     nDevicePort;            //�豸����˿�      
    char    cDeviceDomainName[64];  //�豸���� 
    char    cDevicePwd[32];         //�豸ע������    Ĭ��ֵΪ12345678      
    int     nDeviceExpires;         //ע�����ʱ�� ��λΪ��   Ĭ��ֵΪ3600   
    int     nDeviceAlarminNum;      //�豸����������������Χ0-8   
    char    cDeviceAlarminId[8][32];   //�豸����ID
}HB_SDVR_IPC_GB28181_DEVICE_INFO;
typedef struct 
{
    char    cSmssvrIp[32];              //sms��ý�����������IP       
    int     nSmssvrPort;                //sms��ý����������ն˿�  Ĭ��ֵΪ6000
}HB_SDVR_IPC_GB28181_SMS_SERVER_INFO;
typedef struct 
{
    char    cSipsvrIp[32];              //sip������IP         
    char    cSipsvrId[32];              //sip������ID 
    int     nSipsvrPort;                //sip�������˿ں�   Ĭ��ֵΪ5060     
    char    cSipsvrDomainName[64];      //sip����������
}HB_SDVR_IPC_GB28181_SIP_SERVER_INFO;
typedef struct
{
    int     nEnable;            //ʹ�� -1-��֧�� 0-off, 1-on
    WORD    wProtocolPort;      //Э��˿ڣ����ں����IPCĬ��Ϊ8888
    WORD    wVideoPort;         //����Ƶ�˿ڣ�Ĭ��554
}HB_SDVR_IPC_PLATFORM_INFO;
typedef struct
{
    int                                     nEnable;        //ʹ�� -1-��֧�� 0-off, 1-on
    HB_SDVR_IPC_GB28181_DEVICE_INFO         DevInfo;        //GB28181�豸������Ϣ
    HB_SDVR_IPC_GB28181_SMS_SERVER_INFO     SmsserverInfo;  //GB28181��ý���������Ϣ
    HB_SDVR_IPC_GB28181_SIP_SERVER_INFO     SipserverInfo;  //GB28181sip��������Ϣ
}HB_SDVR_IPC_GB28181_INFO;
typedef struct
{
    int             nLens;                
    int             nProtocolType;              //ƽ̨����Э���ѡ�� 0-GB28181 1-onvif 2-PSIA           
    union
    {
        HB_SDVR_IPC_PLATFORM_INFO   Onvif;
        HB_SDVR_IPC_PLATFORM_INFO   Psia;
        HB_SDVR_IPC_GB28181_INFO    Gb28181;
    }PlatformCfg;
}HB_SDVR_IPC_PLATFORM;


/*Nas������ȡ*/
typedef struct
{
    int     nLens;                
    short   sEnable;            //NASʹ�� -1-��֧�� 0-off, 1-on
    WORD    wPort;              //�˿ں�
    int     nStyle;             //��ʽ
    DWORD   dwServerIp;         //������IP
    char    cUsername[32];      //�û���          
    char    cPassword[32];      //����
    char    cRemotePath[128];   //Զ�̴洢·��   
    int     nReserved[3];  
}HB_SDVR_IPC_NAS;

/*�Զ�ע�������ȡ*/
typedef struct
{
    int     nLens;                
    short   sEnable;            //�Զ�ע��ʹ�� -1-��֧�� 0-off, 1-on
    WORD    wPort;              //�˿ں�
    char    cServerAddress[64]; //��������ַ
    int     nSubDeviceID;       //���豸ID
}HB_SDVR_IPC_AUTO_REGIST;

/*Upnp������ȡ*/
typedef struct
{
    char    cWanIp[20];         //����·����WAN�ڵ�ַ      
    char    cLanIp[4][20];      //����·����LAN�ڵ�ַ
    BYTE    byLanIndex;         //LAN�ڵ�ַ����       
    char    reserve[7]; 
}HB_SDVR_IPC_UPNP_DEVICE;
typedef struct
{
    BYTE    byEnable;           //���ö˿�ӳ�� 0-off, 1-on       
    BYTE    byType;             //�˿�ӳ��״̬ 0-δ��Ч 1-����Ч
    WORD    wProto;             //Э�鼴TCP����UDP 0-UDP 1-TCP  
    char    cServiceName[32];   //��������  
    WORD    wIport;             //ӳ��˿�
    WORD    wEport;             //·�����˿�                 
    int     reserve[3];  
}HB_SDVR_IPC_PORT_MAP;
typedef struct
{
    int     nLens;                
    char    cEnable;            //����uPNPʹ�� 0-off, 1-on
    char    cOperate;           //������ʽ  0-���, 1-ɾ��, 2-�༭
    BYTE    byCurrIndex;        //�༭ʱ�������±�  
    BYTE    byCount;            //�˿�ӳ���б���� 
    HB_SDVR_IPC_UPNP_DEVICE routerip;       //����·������ַ       
    HB_SDVR_IPC_PORT_MAP    portmap[8];     //�˿�ӳ����Ϣ  
    int     reserve[3]; 
}HB_SDVR_IPC_UPNP;

/*�������������ȡ*/
typedef struct
{
    int     nLens;                
    char    cEnable;            //��������ʹ�� -1-��֧�� 0-off, 1-on
    BYTE    bySsid[50];         //ssid��      
    BYTE    byChannel;          //Ƶ��
    HB_SDVR_IPC_IPV4     Ipv4;  //ipv4 
    HB_SDVR_IPC_IPV6     Ipv6;  //ipv6   ��δʹ��
    BYTE    byMacAddr[6];       //mac��ַ          
    BYTE    byModel;            //ģʽ     0-11Mbps 1-54Mbps
    char    cKeyType;           //���ܷ�ʽ 0-WEP 1-WPA2 2-WPA2-TKIP 3-WPA2-AES   
    int     nKeyChoose;         //��Կѡ��       
    char    cKeyData[4][64];    //��Կ����
    char    cPassword[64];      //����         
}HB_SDVR_IPC_WIRELESS_NETWORK;

/*���ڲ�����ȡ*/
typedef struct
{
    int     nLens;               
    int     nInterTypeIndex;        //�ӿ�����  -1-��֧�� ��Ϊ��֧�֣����²�������Ч
    char    cInterType[8][10];      //�ӿ����ͱ�
    DWORD   dwBaudRate;             //������0-2400,1-2400,2-4800,3-9600,4-19200,5-38400,6-�Զ���,ȡֵ��Χ[300��115200]
    BYTE    byDataBit;              // ����λ5 6 7 8
    BYTE    byStopBit;              // ֹͣλ1 2
    BYTE    byParity;               //У��λ 0-��У�� 1-��У�� 2-żУ��
    BYTE    byFlowControl;          // ���� 0-�� 1-��� 2-Ӳ��
    int     nDecoderType;           // ��̨Э��ֵ��ͨ��NET_SDVR_PTZTYPE_GET ��ȡ���б�
    DWORD   dwDecoderAddress;        // ��������ַ:[0 �C 255]   
    int     nReserve;
}HB_SDVR_IPC_SERIAL_INFO;

typedef union
{
    HB_SDVR_IPC_IP_PARAM            IpParam;
    HB_SDVR_IPC_PPPOE               Pppoe;
    HB_SDVR_IPC_E_MAIL              Email;
    HB_SDVR_IPC_UPNP                Upnp;
    HB_SDVR_IPC_PLATFORM            Platform;
//     HB_SDVR_IPC_NAS                 Nas;
//     HB_SDVR_IPC_AUTO_REGIST         Auto_Regist;
//     HB_SDVR_IPC_WIRELESS_NETWORK    Wlan;
//     HB_SDVR_IPC_FTP                 Ftp;
//     HB_SDVR_IPC_DDNS               ddns;
//     HB_SDVR_IPC_IP_FILTER          ip_filter;
}HB_SDVR_IPC_NET_CFG_U;
typedef union
{    
    HB_SDVR_IPC_TIME_RECORD   TimeRecord;
    HB_SDVR_IPC_RECORD_MODE   RecordMode;
    HB_SDVR_IPC_DISK_CFG      DiskCfg;
}HB_SDVR_IPC_STORE_CFG_U;

typedef union
{
    HB_SDVR_IPC_IMAGE_PARAM           ImageParam;
    HB_SDVR_IPC_VIDEO_PARAM           VideoParam;
    HB_SDVR_IPC_VIDEO_ENCODE          VideoEncode;
    HB_SDVR_IPC_PICTURE_SNAP          PictureSnap;
    HB_SDVR_IPC_OSD_OVERLAY           OsdOverlay;
    HB_SDVR_IPC_MASK                  Mask;
    HB_SDVR_IPC_ADVANCE_PARAM         AdvanceParam;
    HB_SDVR_IPC_AUDIO_IN_PARAM        AudioInParam;
    HB_SDVR_IPC_AUDIO_OUT_PARAM       AudioOutParam;
}HB_SDVR_IPC_VIDEO_CFG_U;

typedef union
{
    HB_SDVR_IPC_SERIAL_INFO        SerialInfo;
}HB_SDVR_IPC_SERIAL_CFG_U;

typedef struct
{
    int   nPriCmdType; //��ӦHB_SDVR_IPC_PRI_CMD_TYPE_E
    int   nSecCmdType; //��ӦHB_SDVR_IPC_VIDEO_CMD_TYPE_E��������
    int   nChannelid;
}HB_SDVR_IPC_CMD, *PHB_SDVR_IPC_CMD;

typedef struct
{
    int   nPriCmdType; //��ӦHB_SDVR_IPC_PRI_CMD_TYPE_E
    int   nSecCmdType; //��ӦHB_SDVR_IPC_VIDEO_CMD_TYPE_E��������
    int   nSecCmdParaSize;  
    union
    {
        HB_SDVR_IPC_VIDEO_CFG_U     VideoCfg;
        HB_SDVR_IPC_NET_CFG_U       NetCfg;
        HB_SDVR_IPC_STORE_CFG_U     StoreCfg;
        HB_SDVR_IPC_ALARM_CFG_U     AlarmCfg;      
        HB_SDVR_IPC_MANAGE_CFG_U    ManageCfg;
        HB_SDVR_IPC_SERIAL_CFG_U    SerialCfg;
    }IpcCfg;
    int nReserved[2];
}HB_SDVR_IPC_CONFIG, *PHB_SDVR_IPC_CONFIG; 


HB_SDVR_API BOOL __stdcall HB_SDVR_SetIPCParameterConfig( IN LONG lUserID, IN const HB_SDVR_IPC_CONFIG* pIpcConfig);

// HB_SDVR_API BOOL __stdcall HB_SDVR_GetIPCParameterConfig( LONG lUserID, IN const HB_SDVR_IPC_CMD* pIpcCmd,
//                                                          OUT HB_SDVR_IPC_CONFIG* pIpcConfig );

HB_SDVR_API BOOL __stdcall HB_SDVR_GetIPCParameterConfig( LONG lUserID,IN OUT HB_SDVR_IPC_CONFIG* pIpcConfig );

//���/ɾ��/��ȡNVRǰ���豸
typedef struct       
{
    int    nChannel;                        //��������ͨ����
    int    nDevType;                        //�豸���ͣ�0-IPC��1-NVR
    int    nDevChNum;                       //�豸ͨ������Ŀǰ����������Ϊ 1����ʾ�� IP �豸ֻ��һ��ͨ��
    int    nDevCh;                          //�豸ͨ������ nDevChNum ���� 1 ʱ����ֵ��ʾѡ��� IP �豸���ĸ�ͨ����
    //���� IP �豸ͨ����ϵ�ж�����ʵʱ����ͨ�������ȶ������ IP �豸�Ĵ�ͨ�����Եġ�
    int    nProtoType;                      //�豸Э������ѡ��0-HB,1-ONVIF
    int    nPort;                           //�˿ںţ�HB Э���ʾ����˿ڣ�ONVIF ��ʾ HTTP �˿�
    char   cIp[128];                        //�豸 IP
    char   cUsrName[32];                    //�û���
    char   cPassWd[32];                     //����
    int    nStreamStatue;                   //IP �豸ͨ����״̬��0-�Ͽ���1-���ӡ���ȡʱ���ã����ʱ��ֵ��ʹ��
    char   cReserve[4];                     //����     
}HB_SDVR_IPDEV_INFO;

typedef struct       
{
    int    nDevNum;                         //����IP �豸����
    HB_SDVR_IPDEV_INFO DevInfo[64];         //���/��ȡ�� IP �豸��Ϣ
    char   cRreserve[4];                    //����   
}HB_SDVR_IPDEV, *LPHB_SDVR_IPDEV;

typedef struct       
{
    int    nDevNum;                         //����IP �豸����
    int    nLocalChannel[64];               //Ҫɾ���ĵ� IP �豸�ı���ͨ������Ϣ
    char   cReserve[4];                     //����   
}HB_SDVR_DEL_IPDEV, *LPHB_SDVR_DEL_IPDEV;

typedef struct
{
    int    nPort;                           //�˿ں�
    char   cIPAddress[128];                 //�豸��ַ
    char   cMacAddress[8];                  //MAC��ַ
    char   cVendorName[32];                 //������
    int    nProtocolType;                   //��ǰʹ�õ�Э�����ͣ�0-HB,1-ONVIF,2-HBGK_EXT,3-AVIPC,4-SAMSUNG,5-WAYULINK
    char   cReserve[16];                    //����
}HB_SDVR_DEV_SEACHCONTENT, *LPHB_SDVR_DEV_SEACHCONTENT;

typedef struct
{
    int                          nDeviceCounts;         //���������豸����
    HB_SDVR_DEV_SEACHCONTENT     struDeviceInfo[256];   //���������豸����
    char                         cResreve[16];          //����
}HB_SDVR_SEARCH_IPDEV, *LPHB_SDVR_SEARCH_IPDEV;

HB_SDVR_API LONG __stdcall HB_SDVR_GetAllIPDevInfo(LONG lUserID, LPHB_SDVR_IPDEV lpIPDev);
HB_SDVR_API LONG __stdcall HB_SDVR_AddIPDev(LONG lUserID, LPHB_SDVR_IPDEV lpIPDev);
HB_SDVR_API LONG __stdcall HB_SDVR_DelIPDev(LONG lUserID, LPHB_SDVR_DEL_IPDEV lpDelIPDev);

//add by sun lin, 2014.02.21
//����DVR����NVRǰ���豸
HB_SDVR_API LONG __stdcall HB_SDVR_SearchFrontEndDevice(LONG lUserID, LPHB_SDVR_SEARCH_IPDEV lpDevOnNet);

//��ȡָ��DDNS����������
typedef  struct
{
    DWORD   dwSize;             //���ݳ���
    char    cDDNSUser[32];      //DDNS �˺ţ��ԡ�\0�������ַ���
    char    cDDNSPassword[32];  //DDNS �˺ŵ�����  �ԡ�\0�������ַ���
    char    cDDNSAddress[4][32];//DDNS ������ IP ��ַ�ԡ�\0�������ַ��������������ʽ�й�
    BYTE    byDDNSAutoCon;      //���������Ƿ��Զ�������0-��������1-�Զ�����
    BYTE    byDDNSState;        //DDNS ��½״̬  0-δ��¼  1-�ѵ�¼
    BYTE    byAutoRegist;       //DDNS �Զ�ע��ʱ�û����Ƿ�Ĭ�ϣ�0-��Ĭ�ϣ�1-Ĭ��
    BYTE    byReverse[5];       //����
    BYTE    byDDNSName[128];    //������������(�磺hanbang.oray.net) 
}HB_SDVR_SPECIFIC_DDNS,*LPHB_SDVR_SPECIFIC_DDNS; 

typedef  struct
{
    DWORD   dwServer;           //DDNS��������Ӧ���� 0--hanbang.org.cn 1--oray.net 2--dyndns.com 3--no-ip.com 
                                //4--ddns.hbgk.net (��չ) 5--www.meibu.com 6--freedns.afraid.org    
                                //7--multi.super-ddns.com
    HB_SDVR_SPECIFIC_DDNS Param;
}HB_SDVR_DDNS_PARAM,*LPHB_SDVR_DDNS_PARAM; 

//��ȡ������֧�ֵ�DDNS�б�
typedef  struct
{
    char cDDNServerList[12][32]; //DDNS�����б�
}HB_SDVR_DDNS_LIST;

HB_SDVR_API LONG __stdcall HB_SDVR_GetDDNSParam(LONG lUserID, LPHB_SDVR_DDNS_PARAM lpDDNSParam);
HB_SDVR_API LONG __stdcall HB_SDVR_GetDDNSList(LONG lUserID, HB_SDVR_DDNS_LIST* pDDNSList);


HB_SDVR_API LONG __stdcall HB_SDVR_SetEndecryptPassword(LONG lUserID, char* pStrPwd);

typedef struct TAG_HB_SDVR_QUERY_MONTH
{
    BYTE    byChannel;          // ͨ����[0,n-1], n:ͨ����
    BYTE    byType;             // ��ѯ¼������  0x01:�ֶ� 0x02:��ʱ 0x04:�ƶ� 0x08:���� 0xFF����
    BYTE    byYear;             // ��ѯ���[0, 63], ʵ�����-2000 
    BYTE    byMonth;            // ��ѯ�·�[1, 12]
    BYTE    byReserver[32];
}HB_SDVR_QUERY_MONTH, *LPHB_SDVR_QUERY_MONTH;

typedef struct TAG_HB_SDVR_RECFILE_MONTHINFO
{
    BYTE    byDate[31];         // ������¼�����ݵ����ڣ� ����[n]����ĳ�µĵ�n+1��, 0:��¼�� 1:��
    BYTE    byReserver[9];      // ����
}HB_SDVR_RECFILE_MONTHINFO, *LPHB_SDVR_RECFILE_MONTHINFO;

HB_SDVR_API BOOL __stdcall HB_SDVR_QueryRecFileByMonth(LONG lUserID, LPHB_SDVR_QUERY_MONTH lpQuery, LPHB_SDVR_RECFILE_MONTHINFO lpInfo);


typedef  struct 
{ 
    DWORD  dwResolution;		//�ֱ���ֵ���磺0x07800438�������ֽ�(0x0780=1920)�������ֽ�(0x0438=1080)
    DWORD  dwVideoBitrate_support [32];	//�÷ֱ�����֧�ֵ����ʷ�Χ��ÿһ���������һ�����ʣ������ֵ
    //���Ϊ0����ʾ������δ�õ�����Ϊ0����ʾ֧�ֵ�����ֵ����λΪKbit/s
    WORD  wVideoFrameRate_min;		//�÷ֱ����µ���С֡��
    WORD  wVideoFrameRate_max;	//�÷ֱ����µ����֡��
    BYTE  byPicQuality_support[10];	//�÷ֱ�����֧�ֵ�ͼ�������ȼ�,ÿ���������һ��ͼ�������ȼ���
    //0��������ߣ� 1�����ǽϸߣ� 2�����Ǹߣ� 3�������У�4�����ǵͣ� 
    //5��������ͣ�������Ϊ1����ʾ֧�ָ���ͼ������
    BYTE  reserve[2]; 				//����
} STRUCT_SDVR_RESOLUTION;


//���͵�ʱ��ֻ��Ҫ��дbyChannel,dwSize,byCompressionType�������ֶ�)
typedef  struct 
{
    DWORD  dwSize;				//�ṹ���С
    BYTE  byChannel;			//ͨ����
    BYTE  byCompressionType;	//������0-��������1-������1��������2��
    BYTE  byCompression_support;	//֧�ֵ�������ÿλ����һ����������λΪ1��ʾ֧�ָ������� �ӵ�λ��ʼ��								//0λ��������������1λ����������1����2λ����������2...
    BYTE  byBitrateTypeIndex;		//��ǰ������������ֵ����ʾ����dwBitrateType�е�λ��,
    //����dwBitrateTypeIndex = 0����ǰ��������ΪdwBitrateType�ĵ�0λ
    //��ָ�����������ͣ�����������
    BYTE  byBitrateType_support;	//֧�ֵ��������ͣ�ÿһλ����һ���������ͣ���λΪ1��ʾ֧�ָ��������ͣ�
    //�ӵ�λ��ʼ����0λ�Ǳ���������1λ�Ƕ�����
    BYTE  byRecordType_index;	//��ǰ¼����������ֵ
    BYTE  byRecordType_support;	//֧�ֵ�¼�����ͣ�ÿλ����һ��¼�����ͣ���λΪ1��ʾ֧�ָ����ͣ�
    //�ӵ�λ��ʼ����0λ�ֶ�¼�񣬵�1λ��ʱ¼�񣬵�2λ�ƶ�¼��
    //��3λ����¼�񣬡�����15λ����¼��
    BYTE  byAudioflag;			//��ǰ�Ƿ�����Ƶ��0-����Ƶ��1-����Ƶ
    BYTE  byAudio_support;		//�Ƿ�֧����Ƶ��0-��֧�֣�1-֧�֣�����֧����Ƶʱ��byAudioflagֻ��Ϊ0
    BYTE  byPicQuality;			//��ǰͼ�������� 0--��ߣ� 1-�ϸߣ� 2-�ߣ� 3-�У�4-�ͣ� 5-���
    WORD  wVideoFrameRate;		//��ǰ֡��ֵ
    DWORD  dwVideoBitrate;		//��ǰ����ֵ����λΪKbit/s
    BYTE  reserve[3];				//����
    BYTE  byResoluIndex;			//��ǰ�ֱ�������ֵ����ʾ����byResolution_support�е�λ��
    STRUCT_SDVR_RESOLUTION  Resolution_support[16];		//֧�ֵķֱ��ʣ����16�ֱַ��ʣ�ÿ���ṹ
    //�����һ�ֱַ��ʼ��÷ֱ�����֧�ֵ����ʣ�֡�ʣ�ͼ��������Χ���ýṹ
    //���dwResolutionΪ0����ʾ�ýṹ��δ�õ�
} STRUCT_SDVR_COMPRESSINFO_SUPPORT,* LPSTRUCT_SDVR_COMPRESSINFO_SUPPORT;

HB_SDVR_API BOOL __stdcall HB_SDVR_GetChlParamSupport( IN LONG lUserID, IN OUT LPSTRUCT_SDVR_COMPRESSINFO_SUPPORT pCompressinfoSupport );

typedef struct 
{
    BYTE  sUserName[32];		//�û���
    BYTE  sPassword[32];			//����
    BYTE  byLocalRight[32];		//����Ȩ�� 1.����0δʹ�ã�2.ȡֵ��0-��Ȩ�ޣ�1-��Ȩ��
    //����1-�������á�����2-¼�����á�����3-������á�����4-�������á�
    //����5-�������á�����6-�������á�����7-¼��طš�����8-ϵͳ����
    //����9-ϵͳ��Ϣ������10-�������������11-��̨���ơ�����12-�ػ�������
    //����-13-USB����������14-����
    BYTE  byLocalChannel[128];	//�����û���ͨ���Ĳ���Ȩ�ޣ����128��ͨ����0-��Ȩ�ޣ�1-��Ȩ��
    BYTE  byRemoteRight[32];		//Զ�̵�¼�û����߱���Ȩ�� 1.����0δʹ�ã�2.ȡֵ��0-��Ȩ�ޣ�1-��Ȩ��
    //����1-��ʾ���á�����2-¼�����������3-��ʱ¼������4-�ƶ�¼��
    //����5-����¼������6-�������������7-��̨���á�����8-�洢����
    //����9-ϵͳ��������10-��Ϣ��ѯ������11-�ֶ�¼������12-�طš�
    //����-13-���ݡ�����14-��Ƶ����������-15-�������������16-Զ��Ԥ��
    BYTE  byRemoteChannel[128];	//Զ�̵�¼�û���ͨ���Ĳ���Ȩ�ޣ����128��ͨ����0-��Ȩ�ޣ�1-��Ȩ��
    DWORD  dwUserIP;			//�û�IP��ַ(Ϊ0ʱ��ʾ�����κε�ַ)
    BYTE  byMACAddr[8];		//�����ַ
}STRUCT_USERINFO;

typedef struct 
{
    BYTE  sUserName[32];		//�û������ԡ�\0�������ַ���
    BYTE  sPassword[32];			//���룬�ԡ�\0�������ַ���
    BYTE  byLocalRight[32];		//����Ȩ�� 1.����0δʹ�ã�2.ȡֵ��0-��Ȩ�ޣ�1-��Ȩ��
    //����1-�ֶ�¼������2-�ֶ�����������3-¼��طš�����4-���ݹ���
    //����5-���̹�������6-ϵͳ�ػ�������7-ϵͳ����������8-��̨���ơ�
    //����9-�������������10-�������á�����11-������á�����12-¼�����á�
    //����13-��ʱ¼������14-�������á�����15-�������á�����16-��̨���á�
    //����17-�������á�����18-ϵͳ��Ϣ������19-¼��״̬������20-����״̬��
    //����21-����״̬������22-��־��ѯ������23-�������á�����24-�û�����
    //����25-�ָ��������á�����26-����Ȩ�ޡ�����27-��ʱ������
    //����28-����¼��
    BYTE  byLocalChannel[128];	//�����û���ͨ���Ĳ���Ȩ�ޣ����128��ͨ����0-��Ȩ�ޣ�1-��Ȩ��
    BYTE  byRemoteRight[32];		//Զ�̵�½�û����߱���Ȩ�� 1.����0δʹ�ã�2.ȡֵ��0-��Ȩ�ޣ�1-��Ȩ��
    //���� 1-Զ��Ԥ�������� 2-�������á����� 3-Զ�̻طš����� 4-Զ�̱��ݡ�
    //���� 5-�鿴��־������ 6-�����Խ������� 7-Զ������������ 8-Զ������
    BYTE  byRemoteChannel[128];	//�û�Զ�̵�½ʱ��ͨ�����߱���Ȩ�ޣ����128��ͨ����0-��Ȩ�ޣ�1-��Ȩ��
    DWORD  dwUserIP;			//�û���¼ʱpc����ip��ַ��Ϊ0��ʾ�κ�PC��������ʹ�ø��û���½��
    //DVR�ϣ���Ϊ0��ʾֻ��ip��ַΪ�趨ֵ��pc���ſ���ʹ�ø��û���¼��
    //DVR��
    BYTE  byMACAddr[8];		//�û���¼ʱPC����MAC��ַ��Ϊ0��ʾ�κ�PC��������ʹ�ø��û���½
    //��DVR�ϣ���Ϊ0��ʾֻ��MAC��ַΪ�趨ֵ��PC���ſ���ʹ�ø��û�
    //��½��DVR��

}STRUCT_USERINFO_GUI;

typedef struct 
{
    BYTE  user [32];				//�û������ԡ�\0�������ַ���
    BYTE  pwd [32];				//���룬�ԡ�\0�������ַ���
    BYTE  grp_name[32];			//������
    LONG64  local_authority[64];		//�����û�ʹ��Ȩ�ޣ�ÿλ����һ��ͨ��,bit0~bit63��ʾ0~63ͨ����
    //ÿ���������һ��Ȩ�ޣ�����0-ʵʱԤ��������1-�ֶ�¼��
    //����2-¼���ѯ�طš�����3-���ݹ�������4-¼�����������5-��̨���á�
    //����6-��ͼ���á�����7-ͨ�����á�����8-��ʱ¼������9-�ƶ���⡢
    //����10-������������11-�������á�����12-�������á�����13-�������á�
    //����14-�������á�����15-��Ϣ�鿴������16-������������17-�������á�
    //����18-�������á�����19-ϵͳ�ػ�������20-����¼��
    LONG64  remote_authority[64]; 	//Զ��Ȩ�ޣ�ÿλ����һ��ͨ����bit0~bit63��ʾ0~63ͨ����
    //ÿ���������һ��Ȩ�ޣ�����0-Զ��Ԥ��������1-�������á�����2-Զ�̻�									//�š�����3-Զ�̱��ݡ�����4-�鿴��־������5-�����Խ�������6-Զ������
    DWORD  dwbind_ipaddr;		//�û���¼ʱpc����ip��ַ��Ϊ0��ʾ�κ�PC��������ʹ�ø��û���½��
    //DVR�ϣ���Ϊ0��ʾֻ��ip��ַΪ�趨ֵ��pc���ſ���ʹ�ø��û���¼��
    //DVR��
    BYTE  bybind_macaddr[8];		//�û���¼ʱPC����MAC��ַ��Ϊ0��ʾ�κ�PC��������ʹ�ø��û���½
    //��DVR�ϣ���Ϊ0��ʾֻ��MAC��ַΪ�趨ֵ��PC���ſ���ʹ�ø��û�
    //��½��DVR��
}STRUCT_USERINFO_9000;

typedef  struct 
{
    DWORD  dwSize;				//�ṹ���С
    WORD  wUserInfoMode;		//�û�Ȩ��ģʽ��1-�ϵ�Ȩ��ģʽ��2-��GUIȨ��ģʽ��3-9000��ĿȨ��ģʽ
    BYTE  reserve[2];			//����
    union
    {
        STRUCT_USERINFO  userInfo[16];				//��dwUserInfoMode=1ʱ��ʹ�øýṹ��
        STRUCT_USERINFO_GUI  userInfoGui[16];		//��dwUserInfoMode=2ʱ��ʹ�øýṹ��
        STRUCT_USERINFO_9000  userInfo9000[16];		//��dwUserInfoMode=3ʱ��ʹ�øýṹ��
    }info;
}STRUCT_SDVR_USER_INFO_EX1, *PSTRUCT_SDVR_USER_INFO_EX1;

HB_SDVR_API BOOL __stdcall HB_SDVR_GetUserInfo( IN LONG lUserID, OUT PSTRUCT_SDVR_USER_INFO_EX1 pUserInfoEx1 );
HB_SDVR_API BOOL __stdcall HB_SDVR_SetUserInfo( IN LONG lUserID, IN PSTRUCT_SDVR_USER_INFO_EX1 pUserInfoEx1 );

// ����ʱ��������ʱ��
typedef  struct
{
    BYTE  month;	//����ʱ�������ã���[1��12]
    BYTE  weeks;	//����ʱ�������ã���[1��5]
    BYTE  week;		//����ʱ�������ã�����[0��6]��
    BYTE  hour;		//����ʱ��������,  ʱ[0��23]
    BYTE  min;		//����ʱ�������ã���[0��59]
    BYTE  sec;		//����ʱ�������ã���[0��59]
} STRUCT_SDVR_DST_WEEK_TIME_S;
//˵�����������õ�ʱ�䣬��ʾ�ڼ��µĵڼ������ڼ��ļ�ʱ���ּ��룬��month=5��weeks=2��week=1��hour=10��min=0��sec=0����ʾ5�·ݵĵ�2������1��10��00��00


//ϵͳʱ�䶨��
typedef struct {
    unsigned int sec : 6;
    unsigned int min : 6;
    unsigned int hour : 5;
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 6;
} HSYSTIME;
//����ʱʱ������
typedef  struct
{
    BYTE  dst_en;			//����ʱʹ�ܼ���0-��ʹ�ܣ�1-ʹ��
    BYTE  dsttype_en;		//��������Ϊ0, ����������Ϊ1
    HSYSTIME  start_date;		//���������õĿ�ʼʱ��
    HSYSTIME  end_date;		//���������õĽ���ʱ��
    STRUCT_SDVR_DST_WEEK_TIME_S  start_time;	//�������õĿ�ʼʱ��
    STRUCT_SDVR_DST_WEEK_TIME_S  end_time;		//�������õĽ���ʱ��
    BYTE  reserve[4];			//����
}STRUCT_SDVR_DST_TIME_S;

HB_SDVR_API BOOL __stdcall HB_SDVR_GetDstTime( IN LONG lUserID, OUT STRUCT_SDVR_DST_TIME_S* pDstTime );
HB_SDVR_API BOOL __stdcall HB_SDVR_SetDstTime( IN LONG lUserID, IN STRUCT_SDVR_DST_TIME_S* pDstTime );

#define OSDINFONUM_MAX	        64	//OSD��Ϣ����������
#define OSDSTRSIZE_MAX	        100	//OSD�ַ���������

typedef  struct 
{ 
    BYTE  id;                 		// ͨ���ַ�������Ϣ�� [0, n��1] n: �����ַ���Ϣ����
    BYTE  byLinkMode;        		// 0-������  1-������  
    BYTE  byChanOSDStrSize;			// �����ַ���Ϣ���ַ������ݵĳ��ȣ������ַ���������'\0',[1, 100]
    BYTE  byOSDAttrib;				// ͨ���ַ�������Ϣ  1-��͸��  2-͸��(ֻ��� PC ����ʾ)
    BYTE  byOSDType; 				// ��ʽ�����ԣ����λΪ 0��ʾ�������ӣ�Ϊ 1��ʾǰ�˵���
    // ��Ϊ 0x80 ʱ��ʾ�� osd ��Ϊǰ�˵���
    char  reservedData[3];				// ����
    DWORD dwShowChanOSDInfo;	// �Ƿ���ʾͨ���ַ�������Ϣ  0-��ʾ  1-����ʾ 
    WORD  wShowOSDInfoTopLeftX;	// ͨ���ַ�������Ϣ��ʾλ�õ� x ����
    //  [0,  ʵ�ʿ������ַ����ݳ���]
    WORD  wShowOSDInfoTopLeftY;	// ͨ���ַ�������Ϣ��ʾλ�õ� y ���� 
    //  [0,  ʵ�ʸߣ�����߶�] 
    char  data[OSDSTRSIZE_MAX];						// �����ַ���Ϣ����ַ������ݣ������ַ���������'\0',����С��100��
} HB_SDVR_STRUCT_SDVR_OSDINFO; 

typedef  struct 
{ 
    BYTE   byChannel;				// ͨ���� [0, n��1] n:ͨ����
    BYTE   byOSDInfoNum; 			// �����ĵ����ַ���Ϣ����[1,64]��ÿ��ṹΪSTRUCT_SDVR_OSDINFO
    WORD   byChanOSDInfoSize;      // �����ַ���Ϣ�����ݰ���С,����
    HB_SDVR_STRUCT_SDVR_OSDINFO OsdInfo[OSDINFONUM_MAX];
} HB_SDVR_STRUCT_SDVR_OSDCFG; 


HB_SDVR_API BOOL __stdcall HB_SDVR_GetOsdCfg( IN LONG lUserID, IN OUT HB_SDVR_STRUCT_SDVR_OSDCFG* pOsdCfg );
HB_SDVR_API BOOL __stdcall HB_SDVR_SetOsdCfg( IN LONG lUserID, IN const HB_SDVR_STRUCT_SDVR_OSDCFG* pOsdCfg);

//ͼƬ��������
typedef struct
{
    DWORD   dwTimeSeg[3];       //ʱ��� 15 ����Ϊ 96 �Σ��� 3 �� uint ��ʾ
    BYTE    byEnable;           //һ��ʱ�俪�� 0-no 1-yes
    BYTE    byReserve[3];
}HB_SDVR__SCHE_ITEM_S;
typedef struct
{
    HB_SDVR__SCHE_ITEM_S    Item[8]; //  �������� 0-7: everyday, monday...Sunday
    BYTE                    byReserve[4];
}HB_SDVR_PAGE_SCHE_S;
typedef struct
{
    BYTE byChannel;             //ͨ����:[0��n-1]�� 0xff��0xff ��ʾ����ͨ�� 
    BYTE bySnapshotType;        //��ͼ����:1-�ֶ���2-��ʱ��4-�ƶ���8-̽ͷ������
    BYTE byPicFormat;           //ͼƬ��ʽ��0--jpg��1-bmp��Ŀǰֻ���� jpg ��ʽ
    BYTE bySnapshotResolution;  //������:0-CIF 1-HD1, 2-D1��3-QCIF 4-720p 5-1080p
    BYTE bySnapshotQuality;     //����:1~6��1-��� 2-�κ� 3-�Ϻ� 4-һ�� 5-�ϲ� 6-��
    BYTE bySnapshotPeriod;      //��ͼ���[1��5]����λ�룬����ͼƬ��ʱ����
    BYTE bySnapshotNum;         //��ͼ������snapshot_period=1 ʱ��Ч��ÿ���ͼ������
                                //Ŀǰ�����������ޣ�ֻ����ÿ��һ��
    BYTE bySnapshotLink[128];   //������ͼͨ��
    HB_SDVR_PAGE_SCHE_S Plan;   //��ʱ��ͼʱ��(��ͼ:ץ��),�� snapshot_type=2 ʱ��Ч��
    BYTE bySnapshotEnplan;      //��ͼ���ض�ʱ��0-�أ�1-������ʱ��ͼ���ܣ��� snapshot_type=2 ʱ��Ч��
    BYTE bySnapshotEnmotion;    //��ͼ�����ƶ���0-�أ�1-�����ƶ�������ͼ����---�� snapshot_type=4 ʱ��Ч��
    BYTE bySnapshotEnalm;       //��ͼ���ر�����0-�أ�1-����̽ͷ������ͼ����---�� snapshot_type=8 ʱ��Ч��
    BYTE byReserve[3];          //����
}HB_SDVR_SNAPSHOT_CONFIG_S, *PHB_SDVR_SNAPSHOT_CONFIG_S;

HB_SDVR_API BOOL __stdcall HB_SDVR_GetSnapShotCfg( IN LONG lUserID, IN OUT HB_SDVR_SNAPSHOT_CONFIG_S* pSnapShotCfg );
HB_SDVR_API BOOL __stdcall HB_SDVR_SetSnapShotCfg( IN LONG lUserID, IN const HB_SDVR_SNAPSHOT_CONFIG_S* pSnapShotCfg );

typedef struct ST_HB_SDVR_INITIATIVE_LOGIN
{ 
    char sDVRID[SERIALNO_LEN];          // ƽ̨�����DVR�ĵ�¼ID
    char sSerialNumber[SERIALNO_LEN];   // DVR�豸��������кţ������˱�����䣬��ǰ���������ಹ��
    BYTE byAlarmInPortNum;              // DVR�����������
    BYTE byAlarmOutPortNum;             // DVR�����������
    BYTE byDiskNum;                     // DVRӲ�̸���
    BYTE byProtocol;                    // �����Ͳ�Ʒ��ֵΪ0x20
    BYTE byChanNum;                     // DVRͨ������
    BYTE byEncodeType;                  // �������������1ΪANSI�ַ��� ���Ĳ���GB2312���룻2ΪUTF8
    BYTE reserve1[2];                   // ����
    DWORD sDVRIP;                       // 140212 �˴������豸IP
    BYTE reserve2[20];                  // ����
    char sDvrName[NAME_LEN];            // ������
    char sChanName[MAX_CHANNUM_EX][NAME_LEN];   //ͨ����
}HB_SDVR_INITIATIVE_LOGIN, *LPHB_SDVR_INITIATIVE_LOGIN;

typedef BOOL (CALLBACK *PInitiativeLoginCallBack)( LONG lUserID,
    char *sDVRIP,//����
    LPHB_SDVR_INITIATIVE_LOGIN pDeviceInfo, 
    PVOID pContext );

//����������¼�ص�����
//pLoginCallBack == NULL�ر�������¼��
HB_SDVR_API BOOL HB_SDVR_SetInitiativeLoginCallBack( WORD wDVRPort, PInitiativeLoginCallBack pLoginCallBack, PVOID pContext ); 

typedef struct ST_HB_SDVR_REALPLAYCON
{
    DWORD               dwSize;
    DWORD               dwChl;          // ͨ����
    HWND                hWnd;           // ���Ŵ��ھ��
    DWORD               dwStreamType;   // 0-������ 1-������
    DWORD               dwLinkMode;     // 0-TCP 1-UDP
    DWORD               dwMultiCast;    // �Ƿ�ಥ
    DWORD               dwOSDScheme;    // osd�ַ������ʽ 
    DWORD               dwMultiCastIP;  // �ಥIP��ַ
    DWORD               dwPort;         // �ಥ�˿�
    PHB_SDVR_STREAMDATA_PROC    pfnDataProc;
    void*               pContext;
    DWORD               dwReserver[4];
}HB_SDVR_REALPLAYCON, *LPHB_SDVR_REALPLAYCON;

//����Ƶ���� ����ģʽ
HB_SDVR_API LONG __stdcall HB_SDVR_InitiativeRealPlay(LONG lUserID, DWORD dwMsgID, LPHB_SDVR_REALPLAYCON pRealPlay);

typedef struct ST_HB_SDVR_PLAYBACKCON
{
    DWORD               dwSize;
    DWORD               dwChannel;      // ͨ����
    HB_SDVR_RECTYPE_E   dwFileType;     // �ļ�����
    HWND                hWnd;           // ���Ŵ��ھ��
    HB_SDVR_TIME        struStartTime;  // ����ʱ��ο�ʼʱ��
    HB_SDVR_TIME        struStopTime;   // ����ʱ��
    PHB_SDVR_STREAMDATA_PROC    pfnDataProc;
    void*               pContext;
    DWORD               dwResever[4];
}HB_SDVR_PLAYBACKCON, *LPHB_SDVR_PLAYBACKCON;

//Զ��¼��㲥��չ ����ģʽ
HB_SDVR_API LONG __stdcall HB_SDVR_InitiativePlayBack(LONG lUserID, DWORD dwMsgid, LPHB_SDVR_PLAYBACKCON pPlayBack);

//Զ��¼�񱸷���չ ����ģʽ
HB_SDVR_API LONG __stdcall HB_SDVR_InitiativeGetFile(LONG lUserID,  DWORD dwMsgid, LPHB_SDVR_FILEGETCOND pGetFile);

//�����Խ�Э����չ ����ģʽ
HB_SDVR_API LONG __stdcall HB_SDVR_InitiativeStartVoiceCom(LONG lUserID, DWORD dwMsgid, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle,
    char *pRecvDataBuffer,DWORD dwBufSize,BYTE byAudioFlag,DWORD dwUser), DWORD dwUser);

//������ץͼ��չ ����ģʽ
HB_SDVR_API BOOL __stdcall HB_SDVR_InitiativeGetPicFromDev(LONG lUserID, DWORD dwMsgid, USHORT channel,char *sPicFileName);

//�����˱�����չ ����ģʽ
typedef struct 
{ 
    BYTE    byAlarmStat;        //����״̬ 0������������1��������ʼ
    DWORD   dwAlarmType;        //��������
    HB_SDVR_TIME dwAlarmTime;   //����ʱ��
    BYTE    byChannel;          //����ͨ����    ��������0-6ʱ��Ч
    DWORD   dwAlarmDayNum;      //Ԥ�豨������  ��������7ʱ��Ч
    DWORD   dwCurDayNum;        //��ǰ����      ��������7ʱ��Ч
    DWORD   dwDeviceIP;         //�豸IP
    BYTE    reserve[10];
}HB_SDVR_ALARM_REQ, *LPHB_SDVR_ALARM_REQ;

typedef BOOL (CALLBACK *PInitiativeAlarmCallBack)( LONG lUserID, LPHB_SDVR_ALARM_REQ pAlarm, PVOID pContext );

//pAlarmCallBack == NULL�ر������ϴ�
typedef enum
{
    ALARM_TYPE_MOTION = 0,  //�ƶ�����
    ALARM_TYPE_DETECT,      //̽ͷ����
    ALARM_TYPE_VIDEOLOST,   //��Ƶ��ʧ
    ALARM_TYPE_DISKERROR,   //���̴���
    ALARM_TYPE_DISCONNECT,  //����Ͽ�
    ALARM_TYPE_OVERTEMP,    //�¶ȹ���
    ALARM_TYPE_VIDEOSHADE,  //��Ƶ�ڵ�
    ALARM_TYPE_LACKTIME,    //¼��ʱ�䲻��
}ALARM_TYPE_PARAM;

HB_SDVR_API BOOL __stdcall HB_SDVR_SetInitiativeAlarmCallBack(LONG lUserID, PInitiativeAlarmCallBack pAlarmCallBack, PVOID pContext);

//DDNS����
HB_SDVR_API BOOL HB_SDVR_TestDDNS(LONG lUserID);

//�ʼ�����
HB_SDVR_API BOOL HB_SDVR_TestEMAIL(LONG lUserID);


//add by sun lin, 2014-02-24
//��ȡ����֧�ֵĹ���
typedef  struct
{
    BYTE  functions[256];				//����Ĺ��ܣ������ÿ��Ԫ�ش���һ�ֹ��ܣ����ע�͡�
    BYTE  reserve[8] ;			        //����
}HB_SDVR_SUPPORT_FUNC, *LPHB_SDVR_SUPPORT_FUNC;

HB_SDVR_API BOOL __stdcall HB_SDVR_GetDVRSupprotFunc(LONG lUserID, LPHB_SDVR_SUPPORT_FUNC lpSupportFunc);

// add by wangzhen,2014-04-02
typedef struct
{
    char enable;    // ����һ��ͨʹ�ܣ�-1��֧�֣�0 off, 1 on;
    BYTE reserve[31];
}HB_SDVR_YDTSUPPORTCFG, *LPHB_SDVR_YDTSUPPORTCFG;

HB_SDVR_API BOOL __stdcall HB_SDVR_SetYDTCfg(LONG lUserID, LPHB_SDVR_YDTSUPPORTCFG lpYDTCfg, DWORD dwSize);

HB_SDVR_API BOOL __stdcall HB_SDVR_GetYDTCfg(LONG lUserID, LPHB_SDVR_YDTSUPPORTCFG lpYDTCfg, LPDWORD lpSize);

//add by sun lin, 2014-04-12
typedef enum
{
    ALARM_UPLOAD_MOTION,          // �ƶ���ⱨ��
    ALARM_UPLOAD_VIDEOLOST,       // ��Ƶ��ʧ����
    ALARM_UPLOAD_VIDEO_COVER,     // ��Ƶ�ڵ�����
    ALARM_UPLOAD_SENSOR,          // ̽ͷ����
    ALARM_UPLOAD_TEMP_HI,         // �¶ȹ��߱���
    ALARM_UPLOAD_HD_ERROR,        // ���̴��󱨾�
    ALARM_UPLOAD_HD_FULL,         // ����������
    ALARM_UPLOAD_TYPE_MAX,
} ALARM_UPLOAD_TYPE;

typedef struct
{
    DWORD AlarmType;    //���������б��������Ƿ�֧���ϴ�������������ӵ͵��߰�λ��ʾ����:STRUCT_SDVR_ALMUPLOADTYPE_E,λ����: 1-֧�֣� 0-��֧��
    BYTE reserve[16];   //����λ
} HB_SDVR_UPLOAD_ALARMTYPE, *LPHB_SDVR_UPLOAD_ALARMTYPE;

typedef struct
{
    WORD AlarmType;     //��������
    WORD UploadEnable;  //�����ϴ�ʹ�ܣ�������1-�����ϴ��� 0-���ϴ�
    HB_SDVR_SCHEDTIME UploadTime[8][4];     //�ϴ�����ʱ������ã�[0][i]��ʾÿ���ʱ���
    BYTE reserve[16];   //����λ
    
}HB_SDVR_UPLOAD_ALARMPARAM, *LPHB_SDVR_UPLOAD_ALARMPARAM;

HB_SDVR_API BOOL __stdcall HB_SDVR_GetUploadAlarmType(LONG lUserID, LPHB_SDVR_UPLOAD_ALARMTYPE lpAlarmType, LPDWORD lpSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_GetUploadAlarmParam(LONG lUserID, LPHB_SDVR_UPLOAD_ALARMPARAM lpAlarmParam, LPDWORD lpSize);
HB_SDVR_API BOOL __stdcall HB_SDVR_SetUploadAlarmParam(LONG lUserID, LPHB_SDVR_UPLOAD_ALARMPARAM lpAlarmParam, DWORD dwSize);

//���ڼ�����ؽӿ�
//��½
/*
��  �ܣ���½����
��  ����
sDVRIP�� IP��ַ
wDVRPort�� �˿�
sUserName���û���
sPassword������
lpDeviceInfo�� ָ��HB_SDVR_DEVICEINFO �ṹ��ָ��
����ֵ��-1 ��ʾʧ�ܣ�����ֵ��ʾ�����û���IDֵ����IDֵ����SDK���䣬ÿ���û�ID ֵ�ڿͻ�����Ψһ��*/
//ɽ�����ڼӽ���
#define MAX_IPC_CHANNUM 4
typedef struct
{
    BYTE  dongle_type[MAX_IPC_CHANNUM];		//0: δ���Ӽ��ܻ�ģ��, 1: ɽ������SATA���ܻ�
    BYTE  realtime_encrypt[MAX_IPC_CHANNUM];	//0: δ���ü���, 1: ���ü�����������
    BYTE  record_encrypt[MAX_IPC_CHANNUM];	//0: δ���ü���, 1: ���ü�����������
} STRUCT_SDVR_DONGLEINFO;

typedef struct 
{
    BYTE  channel;			// ͨ����
    BYTE  stream_mode;		// 0: ʵʱ��, 1: ��ʷ�ط�
    BYTE  stream_type;		// 0: ������, 1: ������
} STRUCT_SDVR_DONGLE_CHANNEL_INFO;

typedef struct  
{
    BYTE  realtime_enc_enable;
    BYTE  reserve;

}STRUCT_SDVR_DONGLE_ENABLE;

//
HB_SDVR_API BOOL __stdcall HB_SDVR_DONGLE_GetEncInfo(IN LONG lUserID, OUT STRUCT_SDVR_DONGLEINFO* pDongleInfo);
HB_SDVR_API BOOL __stdcall HB_SDVR_DONGLE_OpenKeyA(IN LPCSTR pKeyPath, OUT HANDLE& pHKey);
HB_SDVR_API BOOL __stdcall HB_SDVR_DONGLE_OpenKeyW(IN LPCWSTR pKeyPath, OUT HANDLE& pHKey);

#ifdef _UNICODE
#define HB_SDVR_DONGLE_OpenKey  HB_SDVR_DONGLE_OpenKeyW
#else
#define HB_SDVR_DONGLE_OpenKey  HB_SDVR_DONGLE_OpenKeyA
#endif

HB_SDVR_API BOOL __stdcall HB_SDVR_DONGLE_SetEncInfo(IN LONG lUserID, IN HANDLE hKey, IN STRUCT_SDVR_DONGLE_CHANNEL_INFO* pDongleInfo);


HB_SDVR_API BOOL __stdcall HB_SDVR_DONGLE_SetEncStatus(IN LONG lUserID, IN STRUCT_SDVR_DONGLE_ENABLE* pDonleEnable);
HB_SDVR_API BOOL __stdcall HB_SDVR_DONGLE_GetEncStatus(IN LONG lUserID, OUT STRUCT_SDVR_DONGLE_ENABLE* pDonleEnable);
HB_SDVR_API BOOL __stdcall HB_SDVR_DONGLE_CloseKey(IN HANDLE hKey);
 
//ɽ�����ڶ��μ��� add by yl
typedef struct struct_Work_Packet_ZF
{
    unsigned long     fixflag;
    unsigned long     WorkPacketflag;
    unsigned long     KeyID;
    unsigned long 	  Workdata [496/4];
    unsigned long     Crc;
} Work_Packet_ZF;

typedef struct struct_Device_Include
{
    char     DeviceType[64];
    char     DeviceIP[32];
    int      recordchecked;
    int      DeviceID;
    Work_Packet_ZF WorkPacket;
} Device_Include;

typedef struct struct_Device_Packet
{
    int DeviceNum;
    Device_Include  DeviceInclude[16];
} Device_Packet;

typedef struct 
{
    char  strDeviceInfo[160];
    char  strKeyID[4];
}ZFU_DeviceInfo;

//key�Ƿ��ڷ�����ע��
HB_SDVR_API BOOL __stdcall HB_SDVR_ZFU_KeyStatus(IN HANDLE hKeyHandle);

//��½������
HB_SDVR_API LONG __stdcall HB_SDVR_ZFU_LoginServer(IN char* strIP, IN DWORD dwPort, IN char* strUser, IN char* strPwd);

//�ڷ�������֤���û�
HB_SDVR_API BOOL __stdcall HB_SDVR_ZFU_KeyVertify(IN LONG lUserHandle, IN HANDLE hKeyHandle);

//��ȡ���û��ɷ��ʵ��豸�б�
HB_SDVR_API BOOL __stdcall HB_SDVR_ZFU_GetDeviceList(IN LONG lUserHandle, IN Device_Packet* pDeviceList);

//��ȡĳ���豸����ϸ��Ϣ
HB_SDVR_API BOOL __stdcall HB_SDVR_ZFU_GetDeviceInfo(IN LONG lUserHandle, IN HANDLE hKeyHandle, IN int deviceIndex, IN  ZFU_DeviceInfo* pDeviceInfo);

//ȡ����½������
HB_SDVR_API BOOL __stdcall HB_SDVR_ZFU_LogoutServer(IN LONG lUserHandle);

//��ȡ�û��ĵ�½Ȩ�ޣ��ڵ�½����ã��ɹ�����Ե���Ԥ���ӿ�
HB_SDVR_API BOOL __stdcall HB_SDVR_ZFU_GetOperate(IN LONG lUserID, IN ZFU_DeviceInfo* pDeviceInfo, OUT BOOL* bOperate);
#pragma pack()
// #ifdef __cplusplus
// };
// #endif


#endif  // HB_NETSDK_H