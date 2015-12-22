////////////////////////////////////////////////////////////////////////////////
// ��Ȩ���У�2009-2012����������߿����ּ������޹�˾��
////////////////////////////////////////////////////////////////////////////////
// �ļ����� HBPlaySDK.h
// ���ߣ�   HBGK
// �汾��   3.4
// ���ڣ�   2012-08-09
// ������   ����߿ƽ����C/C++ͷ�ļ�
////////////////////////////////////////////////////////////////////////////////
#ifndef HBPLAYSDK_H
#define HBPLAYSDK_H

#ifdef __cplusplus
extern "C" {
#endif



////////////////////////////////////////////////////////////////////////////////
//����HB_PLAY2 API
////////////////////////////////////////////////////////////////////////////////


//ý�岥�Ŷ���
DECLARE_HANDLE(HHBPLAY2);

//�������
//����ʹ��SUCCEEDED()��FAILED()���жϴ�����롣
#define FACILITY_HBPLAY2            0xAB5
#define HBPLAY2_ERROR(code)         MAKE_HRESULT(1, FACILITY_HBPLAY2, code)

#define HBPLAY2_OK                  S_OK                    //�ɹ�
#define HBPLAY2_ERR_GENERIC         HBPLAY2_ERROR(0x1)      //һ�����
#define HBPLAY2_ERR_NOT_SUPPORTED   HBPLAY2_ERROR(0x2)      //��֧��
#define HBPLAY2_ERR_NOT_IMPLEMENTED HBPLAY2_ERROR(0x3)      //û��ʵ��
#define HBPLAY2_ERR_INVALID_PARAMETER HBPLAY2_ERROR(0x10)   //��Ч����
#define HBPLAY2_ERR_INVALID_HANDLE  HBPLAY2_ERROR(0x11)     //��Ч�ľ��
#define HBPLAY2_ERR_INVALID_POINTER HBPLAY2_ERROR(0x12)     //��Ч��ָ��
#define HBPLAY2_ERR_INVALID_SIZE    HBPLAY2_ERROR(0x13)     //��Ч�Ľṹ�峤��
#define HBPLAY2_ERR_INVALID_PIXEL_FORMAT HBPLAY2_ERROR(0x14)//��Ч�����ظ�ʽ
#define HBPLAY2_ERR_BUFFER_TOO_SMALL HBPLAY2_ERROR(0x20)    //������̫С
#define HBPLAY2_ERR_CANNOT_OPEN_FILE HBPLAY2_ERROR(0x21)    //���ܴ��ļ�
#define HBPLAY2_ERR_OUT_OF_MEMORY   HBPLAY2_ERROR(0x22)     //�ڴ治��
#define HBPLAY2_ERR_BUFFER_EMPTY    HBPLAY2_ERROR(0X23)     //���ݻ�������
#define HBPLAY2_ERR_BUFFER_FULL     HBPLAY2_ERROR(0X24)     //���ݻ�������
#define HBPLAY2_ERR_BUSY            HBPLAY2_ERROR(0x25)     //æ���Ժ�����
#define HBPLAY2_ERR_FILE_INDEX_INCOMPLETE HBPLAY2_ERROR(0x26)//�ļ�������δ���
#define HBPLAY2_ERR_NO_KEY_FRAME    HBPLAY2_ERROR(0x27)     //û�йؼ�֡
#define HBPLAY2_ERR_DISK_FULL       HBPLAY2_ERROR(0x28)     //������

//���ļ�
HRESULT WINAPI HB_PLAY2_OpenFileA( OUT HHBPLAY2* phPlay, IN LPCSTR lpszFileName );
HRESULT WINAPI HB_PLAY2_OpenFileW( OUT HHBPLAY2* phPlay, IN LPCWSTR lpszFileName );
#ifdef _UNICODE
#define HB_PLAY2_OpenFile HB_PLAY2_OpenFileW
#else
#define HB_PLAY2_OpenFile HB_PLAY2_OpenFileA
#endif

//�ļ�ͷ���ȷ�Χ
#define HBPLAY2_HEADER_LENGTH_MIN      64           //�ļ�ͷ������Сֵ
#define HBPLAY2_HEADER_LENGTH_MAX      (256*1024)   //�ļ�ͷ�������ֵ

//����
HRESULT WINAPI HB_PLAY2_OpenStream( OUT HHBPLAY2* phPlay, IN LPCVOID pFileHeader, 
    IN DWORD dwHeaderLength );

//�ر�ý�岥�Ŷ���
HRESULT WINAPI HB_PLAY2_Close( IN HHBPLAY2 hPlay );

//����/��ȡ����ʹ�ܱ�־
//��Щ��־λ������ȫ�������á�����֮���������ϵ���ο���־λ��ע�͡�

//ʹ������������־��
//�ù���ʼ��ʹ�ܣ����ܱ���ֹ��
#define HBPLAY2_ENABLE_STREAM_PARSE             0x00000000
#define HBPLAY2_ENABLE_NONE                     HBPLAY2_ENABLE_STREAM_PARSE

//ʹ����Ƶ��������־��
//ʹ�ܸñ�־���ܽ�����Ƶ���롣
//��ֹ�ñ�־ʱ��ͬʱҲ���ֹHBPLAY2_ENABLE_MULTITHREADING_VIDEO_CODEC��
//HBPLAY2_ENABLE_HARDWARE_VIDEO_CODEC��HBPLAY2_ENABLE_VIDEO_QUALITY_PRIORITY��
//HBPLAY2_ENABLE_VERIFY_CONTINUOUS_VIDEO��HBPLAY2_ENABLE_DISPLAY��־��
#define HBPLAY2_ENABLE_VIDEO_CODEC              0x00000001

//ʹ�ܶ��߳���Ƶ�����־��
//���߳̽����ܹ�������ö��CPU����Դ���ӿ�����ٶȣ������ڽ���·��Ƶͬʱ���롣
//��ֹ�ñ�־ʱ��һ��ý�岥�Ŷ���ֻ��ʹ��һ���߳̽�����Ƶ���룬�����ڽ϶�·
//��Ƶ���������16·��ͬʱ���롣
#define HBPLAY2_ENABLE_MULTITHREADING_VIDEO_CODEC 0x00000002

//ʹ��Ӳ����Ƶ��������־��
//ʹ�ܸñ�־ʱ�������Զ�̽����õ�Ӳ��������������ʹ��Ӳ����������Ӳ�������ܹ�
//��������Կ���Ӳ����Դ����ʡCPU��Դ����ǰ֧�ֵ�Ӳ���������У�NVIDIA CUDA��
//1. NVIDIA CUDA��
//  ʹ��NVIDIA CUDA������������ͬʱ��������������
//  [1] ��Ƶ�����㷨��H.264 Baseline, Main, High Profile Level 4.1��
//      ͼ��ߴ粻����1080P��������С������45mbps��
//  [2] ����NVIDIA G8x, G9x, MCP79, MCP89, G98, GT2xx, GF1xx����߰汾GPU��GPU��
//      ��������������v1.1����ʾ�ڴ治����128MB��
//  [3] �Կ���������汾������v286.19��CUDA��������İ汾������v4.1��
#define HBPLAY2_ENABLE_HARDWARE_VIDEO_CODEC     0x00000004

//ʹ����Ƶͼ���������ȱ�־��
//ʹ�ܸñ�־ʱ������Ƶ����ʱ�����ȱ�֤ͼ��������������ܻᵼ�½ϸߵ�CPUʹ���ʡ�
//����ֹ�ñ�־������Ƶ����ʱ�����ȱ�֤��Ƶ�������ԣ�����ά�ֽϵ͵�CPUʹ���ʣ�
//�����ܻή��ͼ���������
#define HBPLAY2_ENABLE_VIDEO_QUALITY_PRIORITY   0x00000008

//ʹ��У��������Ƶ��־��
//ʹ�ܸñ�־ʱ���ܹ������Ƶ�������ݵ������ԡ������ֲ���������Ƶ֡ʱ����ͣ���룬
//һֱ�ȵ���һ���ؼ�֡�ٻָ����롣ʹ�ܸñ�־�����Ա������ڶ�֡���µ���Ƶͼ���
//���������󣬵����ܵ�����Ƶ����ͣ�١�
#define HBPLAY2_ENABLE_VERIFY_CONTINUOUS_VIDEO  0x00000010

//ʹ����Ƶ��ʾ��־��
//ʹ�ܸñ�־������ʾ��Ƶͼ��
//ֻʹ�ܸñ�־��û��ʹ�ܾ����ͼ����ʾ��־ʱ�����Զ�ѡ��Ĭ�ϵ�ͼ����ʾ��ʽ��
//��ֹ�ñ�־��ͬʱҲ���ֹHBPLAY2_ENABLE_DRAWDIB��HBPLAY2_ENABLE_DIRECTDRAW_7��
//HBPLAY2_ENABLE_DIRECT3D_9��־��
#define HBPLAY2_ENABLE_DISPLAY                  0x00000100

//ʹ����������ͼ���־��
//�ñ�־�ṩ�˲�����ʾ�����Ƶ�ͼ��ˢ���ʣ������ܵ���ͼ��ġ�˺�ѡ�����
//��ֹ�ñ�־ʱ����Ƶͼ����ʾ֡�ʲ��ܳ�����ʾ����ˢ���ʣ�����΢���CPUʹ���ʣ�
//��������ʾ����������Ƶͼ��
//�ñ�־ֻ��Direct3D 9����ʾ��ʽ��Ч��
#define HBPLAY2_ENABLE_PRESENT_IMMEDIATE        0x00000200

//ʹ��Direct3D 9��ʾͼ��
//Windows Vista/2008/7���Ժ�汾��Ĭ��ʹ��Direct3D 9����ʾ��Ƶ��
//��ֹ�ñ�־��ͬʱҲ���ֹHBPLAY2_ENABLE_PRESENT_IMMEDIATE��־��
#define HBPLAY2_ENABLE_DIRECT3D_9               0x00000400

//ʹ��DirectDraw 7��ʾͼ��
//DirectDraw 7����ʾЧ�ʽϸߣ����Կ���Ҫ��ϵͣ������ܱ���ͼ��ġ�˺�ѡ�����
//Windows 2000/XP/2003��Ĭ��ʹ��DirectDraw 7����ʾ��Ƶ��
#define HBPLAY2_ENABLE_DIRECTDRAW_7             0x00000800

//ʹ��ֱ����ʾ���豸�޹�λͼ��
//�ñ�־�ṩ�ܺõļ����ԣ��ʺ���Զ���������ӣ���û�а�װ�Կ�����ʱʹ�á�
//����ʾЧ�ʵͣ�ͼ�������͡�
#define HBPLAY2_ENABLE_DRAWDIB                  0x00010000

//ʹ����Ƶ��������־��
//ʹ�ܸñ�־���ܽ�����Ƶ���롣
//��ֹ�ñ�־��ͬʱҲ���ֹHBPLAY2_ENABLE_SOUND��־��
#define HBPLAY2_ENABLE_AUDIO_CODEC              0x00001000

//ʹ����Ƶ���ű�־��
//ʹ�ܸñ�־���ܽ�����Ƶ���š�
//��ֹ�ñ�־��ͬʱҲ���ֹHBPLAY2_ENABLE_SOUND_PRIORITY��־��
#define HBPLAY2_ENABLE_SOUND                    0x00002000

//ʹ����Ƶ�������ȱ�־��
//һ������£�����Ƶ��ʱ�������Ʋ��ŵ��ٶȡ�ʹ�ܸñ�־������ʹ����Ƶ��ʱ��
//�����Ʋ��ŵ��ٶȡ�
//�������HBPLAY2_STREAM_NONE��Ϊ��������Ʋ��ԡ�
//�ñ�־һ�����ڲ��Ŵ���Ƶ����
#define HBPLAY2_ENABLE_SOUND_PRIORITY           0x00004000

//ʹ��HB_PLAY2_GetDecodeFrame������־��
//ʹ�ܸñ�־��ͬʱ���ֹHBPLAY2_ENABLE_DISPLAY��HBPLAY2_ENABLE_SOUND��־����ʹ��
//HBPLAY2_ENABLE_VIDEO_QUALITY_PRIORITY��־��
//ֻ��ͨ��HB_PLAY2_GetDecodeFrame������ȡ����������Ƶ���ݣ����Ҳ���ִ���κ�
//���Ŷ�����
//����߼��û���ʹ�øñ�־λ��
//������ϸ��Ϣ���ο�HB_PLAY2_GetDecodeFrame������
#define HBPLAY2_ENABLE_GET_DECODE_FRAME         0x10000000

//ʹ��Ĭ�����á�
#define HBPLAY2_ENABLE_DEFAULT      (HBPLAY2_ENABLE_STREAM_PARSE \
                                    | HBPLAY2_ENABLE_VIDEO_CODEC \
                                    | HBPLAY2_ENABLE_MULTITHREADING_VIDEO_CODEC \
                                    | HBPLAY2_ENABLE_VERIFY_CONTINUOUS_VIDEO \
                                    | HBPLAY2_ENABLE_DISPLAY \
                                    | HBPLAY2_ENABLE_AUDIO_CODEC \
                                    | HBPLAY2_ENABLE_SOUND)

HRESULT WINAPI HB_PLAY2_SetEnableFlag( IN HHBPLAY2 hPlay, IN DWORD dwEnableFlag );
HRESULT WINAPI HB_PLAY2_GetEnableFlag( IN HHBPLAY2 hPlay, OUT DWORD* pdwEnableFlag );

//���Ŷ���
HRESULT WINAPI HB_PLAY2_Stop( IN HHBPLAY2 hPlay );
HRESULT WINAPI HB_PLAY2_Pause( IN HHBPLAY2 hPlay );
HRESULT WINAPI HB_PLAY2_Play( IN HHBPLAY2 hPlay );
HRESULT WINAPI HB_PLAY2_PlayBackward( IN HHBPLAY2 hPlay );

//�����ٶ�
#define HBPLAY2_SPEED_MIN           float(1.0/64.0) //��С�����ٶȣ�1/64X
#define HBPLAY2_SPEED_MAX           float(64.0)     //��󲥷��ٶȣ�64X
#define HBPLAY2_SPEED_1X            float(1.0)      //���������ٶȣ�1X
HRESULT WINAPI HB_PLAY2_SetSpeed( IN HHBPLAY2 hPlay, IN float fSpeed );
HRESULT WINAPI HB_PLAY2_GetSpeed( IN HHBPLAY2 hPlay, OUT float* pfSpeed );

//����
#define HBPLAY2_VOLUME_MIN          0x0             //������Сֵ��������
#define HBPLAY2_VOLUME_MAX          0xFFFF          //�������ֵ
HRESULT WINAPI HB_PLAY2_SetVolume( IN HHBPLAY2 hPlay, IN DWORD dwVolume );
HRESULT WINAPI HB_PLAY2_GetVolume( IN HHBPLAY2 hPlay, OUT DWORD* pdwVolume );


//��Ƶ��ɫ
#define HBPLAY2_VIDEO_COLOR_MIN     0               //��Ƶ��ɫ��Сֵ
#define HBPLAY2_VIDEO_COLOR_MAX     127             //��Ƶ��ɫ���ֵ
#define HBPLAY2_VIDEO_COLOR_DEFAULT 64              //��Ƶ��ɫĬ��ֵ
typedef struct HBPLAY2_COLOR_SPACE
{
    //�ṹ�峤�ȣ����ֽڣ�byte��Ϊ��λ��
    //�����߱������øó�Ա����sizeof(HBPLAY2_COLOR_SPACE)��
    DWORD                           dwSize;

    //���ȣ�ȡֵ��Χ[HBPLAY2_VIDEO_COLOR_MIN, HBPLAY2_VIDEO_COLOR_MAX]��
    //Ĭ��ֵHBPLAY2_VIDEO_COLOR_DEFAULT��
    DWORD                           dwBrightness;

    //�Աȶȣ�ȡֵ��Χ[HBPLAY2_VIDEO_COLOR_MIN, HBPLAY2_VIDEO_COLOR_MAX]��
    //Ĭ��ֵHBPLAY2_VIDEO_COLOR_DEFAULT��
    DWORD                           dwContrast;

    //���Ͷȣ�ȡֵ��Χ[HBPLAY2_VIDEO_COLOR_MIN, HBPLAY2_VIDEO_COLOR_MAX]��
    //Ĭ��ֵHBPLAY2_VIDEO_COLOR_DEFAULT��
    DWORD                           dwSaturation;

    //ɫ����ȡֵ��Χ[HBPLAY2_VIDEO_COLOR_MIN, HBPLAY2_VIDEO_COLOR_MAX]��
    //Ĭ��ֵHBPLAY2_VIDEO_COLOR_DEFAULT��
    DWORD                           dwHue;

    //������
    DWORD                           dwReserved;

} HBPLAY2_COLOR_SPACE, *PHBPLAY2_COLOR_SPACE;  
HRESULT WINAPI HB_PLAY2_SetVideoColor( IN HHBPLAY2 hPlay, IN const HBPLAY2_COLOR_SPACE* pColorSpace );
HRESULT WINAPI HB_PLAY2_GetVideoColor( IN HHBPLAY2 hPlay, OUT PHBPLAY2_COLOR_SPACE pColorSpace );

//CPUʹ����
#define HBPLAY2_CPU_LIMIT_MIN       50              //��СCPUʹ�������ƣ�50%
#define HBPLAY2_CPU_LIMIT_MAX       100             //���CPUʹ�������ƣ�100%
HRESULT WINAPI HB_PLAY2_SetCpuLimit( IN HHBPLAY2 hPlay, IN int nLimit );
HRESULT WINAPI HB_PLAY2_GetCpuLimit( IN HHBPLAY2 hPlay, OUT int* pnLimit );

//��������Ʋ���
enum HBPLAY2_STREAM
{
    HBPLAY2_STREAM_NONE              = 0,           //����������Ʋ���
    HBPLAY2_STREAM_REALTIME_PRIORITY = 10,          //ʵʱ������
    HBPLAY2_STREAM_BALANCED          = 20,          //����
    HBPLAY2_STREAM_FLUENCY_PRIORITY  = 30,          //����������
};
HRESULT WINAPI HB_PLAY2_SetStreamMode( IN HHBPLAY2 hPlay, IN HBPLAY2_STREAM StreamMode );
HRESULT WINAPI HB_PLAY2_GetStreamMode( IN HHBPLAY2 hPlay, OUT HBPLAY2_STREAM* pStreamMode );

//����ģʽ
enum HBPLAY2_MODE
{
    HBPLAY2_MODE_UNKNOWN = 0,                       //δ֪��ģʽ
    HBPLAY2_MODE_FILE,                              //�ļ�ģʽ
    HBPLAY2_MODE_STREAM,                            //��ģʽ
    HBPLAY2_MODE_COUNT,                             //����ģʽ����
};
HRESULT WINAPI HB_PLAY2_GetMode( IN HHBPLAY2 hPlay, OUT HBPLAY2_MODE* pMode );

//����״̬
enum HBPLAY2_STATE
{
    //ֹͣ��
    HBPLAY2_STATE_STOPPED = 0,

    //��ͣ��
    HBPLAY2_STATE_PAUSED,

    //�����С�
    //��HB_PLAY2_IsPlayBackward�������ڵĲ��ŷ���
    HBPLAY2_STATE_PLAYING,

    //������
    HBPLAY2_STATE_REQUIRE_TO_PAUSE,

    //������
    HBPLAY2_STATE_REQUIRE_TO_SEEK,

    //������
    HBPLAY2_STATE_SEEKING,

    //����״̬������
    HBPLAY2_STATE_COUNT,
};
HRESULT WINAPI HB_PLAY2_GetState( IN HHBPLAY2 hPlay, OUT HBPLAY2_STATE* pState );

//���ŷ���
HRESULT WINAPI HB_PLAY2_IsPlayBackward( IN HHBPLAY2 hPlay, OUT BOOL* pbBackward );

//�ļ��������
HRESULT WINAPI HB_PLAY2_IsFileIndexCompleted( IN HHBPLAY2 hPlay, OUT BOOL* pbIndexCompleted );

//�ļ����Ž���
HRESULT WINAPI HB_PLAY2_IsFileEnded( IN HHBPLAY2 hPlay, OUT BOOL* pbFileEnded );

//��ȡ������״̬
HRESULT WINAPI HB_PLAY2_IsStreamBuffering( IN HHBPLAY2 hPlay, OUT BOOL* pbBuffering );

//��Ƶͼ��ߴ�
HRESULT WINAPI HB_PLAY2_GetPictureSize( IN HHBPLAY2 hPlay, OUT int* pnWidth, OUT int* pnHeight );

//���������Ƶ֡��
HRESULT WINAPI HB_PLAY2_GetBufferedFrameCount( IN HHBPLAY2 hPlay, OUT DWORD* pdwBufferedFrameCount );

//�ļ��ܳ���
HRESULT WINAPI HB_PLAY2_GetFileSize( IN HHBPLAY2 hPlay, OUT LONGLONG* pllFileSize );

//�������ݳ���
HRESULT WINAPI HB_PLAY2_GetPlayDataSize( IN HHBPLAY2 hPlay, OUT LONGLONG* pllPlayDataSize );

//�ļ���ʱ��
HRESULT WINAPI HB_PLAY2_GetFileDuration( IN HHBPLAY2 hPlay, OUT DWORD* pdwFileDuration );

//���ŵ�ʱ��
HRESULT WINAPI HB_PLAY2_GetPlayDuration( IN HHBPLAY2 hPlay, OUT DWORD* pdwPlayDuration );

//�ļ�����Ƶ֡��
HRESULT WINAPI HB_PLAY2_GetFileVideoFrameCount( IN HHBPLAY2 hPlay, OUT DWORD* pdwFileVideoFrameCount );

//���ŵ���Ƶ֡���
HRESULT WINAPI HB_PLAY2_GetPlayVideoFrameIndex( IN HHBPLAY2 hPlay, OUT DWORD* pdwPlayVideoFrameIndex );

//��Ƶ�ؼ�֡������
HRESULT WINAPI HB_PLAY2_GetKeyFrameDistance( IN HHBPLAY2 hPlay, OUT DWORD* pdwKeyFrameDistance );

//��Ƶ�ؼ�֡ʱ����
HRESULT WINAPI HB_PLAY2_GetKeyFrameInterval( IN HHBPLAY2 hPlay, OUT DWORD* pdwKeyFrameInterval );

//��Ƶ֡��
HRESULT WINAPI HB_PLAY2_GetVideoFrameRate( IN HHBPLAY2 hPlay, OUT float* pfVideoFrameRate );

//��Ƶ����������
HRESULT WINAPI HB_PLAY2_GetVideoBitrate( IN HHBPLAY2 hPlay, OUT float* pfVideoBitrate );

//��Ƶ֡��
HRESULT WINAPI HB_PLAY2_GetAudioFrameRate( IN HHBPLAY2 hPlay, OUT float* pfAudioFrameRate );

//��Ƶ����������
HRESULT WINAPI HB_PLAY2_GetAudioBitrate( IN HHBPLAY2 hPlay, OUT float* pfAudioBiterate );

//��������������
enum HBPLAY2_DEMUX_STREAM_VERSION
{
    HBPLAY2_DEMUX_STREAM_UNKNOWN = 0,               //δ֪������
    HBPLAY2_DEMUX_STREAM_15      = 1,               //����������15����
    HBPLAY2_DEMUX_STREAM_6000    = 2,               //����������6000����
    HBPLAY2_DEMUX_STREAM_V10     = 10,              //��һ������
    HBPLAY2_DEMUX_STREAM_V20     = 20,              //�ڶ�������
    HBPLAY2_DEMUX_STREAM_V30     = 30,              //����������

    HBPLAY2_DEMUX_STREAM_HX      = 8000             //���Ż�ͨ��������
};
typedef struct HBPLAY2_DEMUX_PROPERTY
{
    //�ṹ�峤�ȣ����ֽڣ�byte��Ϊ��λ��
    //�����߱������øó�Ա����sizeof(HBPLAY2_DEMUX_PROPERTY)��
    DWORD                           dwSize;

    //�����汾��
    HBPLAY2_DEMUX_STREAM_VERSION    StreamVersion;

    //������
    DWORD                           dwReserved[2];

    //�ļ�ͷ��
    //ע�⣺ ����������������ļ�ͷ����HBPLAY2_DEMUX_STREAM_6000����û���ļ�ͷ��
    char                            szFileHeader[64];

} HBPLAY2_DEMUX_PROPERTY, *PHBPLAY2_DEMUX_PROPERTY;  
HRESULT WINAPI HB_PLAY2_GetDemuxProperty( IN HHBPLAY2 hPlay, OUT PHBPLAY2_DEMUX_PROPERTY pDemuxProperty );

//��������������
typedef struct HBPLAY2_DEMUX_STATUS
{
    //�ṹ�峤�ȣ����ֽڣ�byte��Ϊ��λ��
    //�����߱������øó�Ա����sizeof(HBPLAY2_DEMUX_STATUS)��
    DWORD                           dwSize;

    //��Ƶ֡����
    DWORD                           dwAudioFrameCount;

    //��ƵI֡����
    DWORD                           dwVideoIFrameCount;

    //��ƵP֡����
    DWORD                           dwVideoPFrameCount;

    //��ƵB֡����
    DWORD                           dwVideoBFrameCount;

    //��ƵE֡����
    DWORD                           dwVideoEFrameCount;

    //������ʱ�䣬�Ժ��루ms��Ϊ��λ��
    DWORD                           dwStreamDuration;

    //������
    DWORD                           dwReserved0;

    //����������ʱ�䣬��΢�루us��Ϊ��λ��
    LONGLONG                        llParseDuration;

    //������
    DWORD                           dwReserved1[2];

} HBPLAY2_DEMUX_STATUS, *PHBPLAY2_DEMUX_STATUS;  
HRESULT WINAPI HB_PLAY2_GetDemuxStatus( IN HHBPLAY2 hPlay, OUT PHBPLAY2_DEMUX_STATUS pDemuxStatus );

//��Ƶ����������
enum HBPLAY2_VDEC_CODEC_TYPE
{
    HBPLAY2_VDEC_CODEC_UNKNOWN = 0,                 //δ֪����������
    HBPLAY2_VDEC_CODEC_MPEG4,                       //MPEG4������
    HBPLAY2_VDEC_CODEC_MPEG4_ISO,                   //MPEG4 ISO������
    HBPLAY2_VDEC_CODEC_FFMPEG,                      //FFMPEG H.264������
    HBPLAY2_VDEC_CODEC_HISILICON,                   //Hisilicon H.264������
    HBPLAY2_VDEC_CODEC_NVIDIA_CUDA,                 //NVIDIA CUDA H.264������
    HBPLAY2_VDEC_CODEC_JPEG,                        //JPEG������
    HBPLAY2_VDEC_CODEC_AMD_OVD,                     //AMD OVD H.264������
	HBPLAY2_VDEC_CODEC_INTEL,                       //Intel H.264������
    HBPLAY2_VDEC_CODEC_COUNT,                       //��Ƶ����������
};
typedef struct HBPLAY2_VDEC_STATUS
{
    //�ṹ�峤�ȣ����ֽڣ�byte��Ϊ��λ��
    //�����߱������øó�Ա����sizeof(HBPLAY2_VDEC_STATUS)��
    DWORD                           dwSize;

    //��Ƶ�������֡����
    DWORD                           dwFrameCount;

    //��Ƶ�������ʱ�䣬��΢�루us��Ϊ��λ��
    LONGLONG                        llDecodeDuration;

    //ʵʱ�����ٶȣ���֡/��Ϊ��λ��
    DWORD                           dwRealtimeSpeed;

    //�����߳�������
    //��dwThreadCount == 0����ʾ��ǰû��ʹ��CPU���룬����ʹ��GPU���롣
    DWORD                           dwThreadCount;

    //��Ƶ���������͡�
    HBPLAY2_VDEC_CODEC_TYPE         CodecType;

    //������
    DWORD                           dwReserved;

} HBPLAY2_VDEC_STATUS, *PHBPLAY2_VDEC_STATUS;  
HRESULT WINAPI HB_PLAY2_GetVdecStatus( IN HHBPLAY2 hPlay, OUT PHBPLAY2_VDEC_STATUS pVdecStatus );

//��Ƶ��ʾ����
enum HBPLAY2_DISPLAY_TYPE
{
    HBPLAY2_DISPLAY_NONE         = 0,               //δʹ���ض�����ʾ��ʽ
    HBPLAY2_DISPLAY_DRAWDIB      = 1,               //ֱ����ʾ���豸�޹�λͼ
    HBPLAY2_DISPLAY_DIRECTDRAW_7 = 2,               //ͨ��DirectDraw 7��ʾͼ��
    HBPLAY2_DISPLAY_DIRECT_3D_9  = 4,               //ͨ��Direct3D 9��ʾͼ��
    HBPLAY2_DISPLAY_DIRECT_3D_11 = 8,               //ͨ��Direct3D 11��ʾͼ��
};
typedef struct HBPLAY2_DISPLAY_STATUS
{
    //�ṹ�峤�ȣ����ֽڣ�byte��Ϊ��λ��
    //�����߱������øó�Ա����sizeof(HBPLAY2_DISPLAY_STATUS)��
    DWORD                           dwSize;

    //��ǰ����ʾ��ʽ
    HBPLAY2_DISPLAY_TYPE            DisplayType;

    //��ʾ��֡����
    DWORD                           dwFrameCount;

    //ץͼ��֡����
    DWORD                           dwSnapshotCount;

    //�ƻ���ʾ��ʱ�䣬��΢�루us��Ϊ��λ��
    LONGLONG                        llPlannedDuration;

    //ʵ����ʾ��ʱ�䣬��΢�루us��Ϊ��λ��
    LONGLONG                        llActualDuration;

    //ץͼ��ʱ�䣬��΢�루us��Ϊ��λ��
    LONGLONG                        llSnapshotDuration;

    //������
    DWORD                           dwReserved[2];

} HBPLAY2_DISPLAY_STATUS, *PHBPLAY2_DISPLAY_STATUS;  
HRESULT WINAPI HB_PLAY2_GetDisplayStatus( IN HHBPLAY2 hPlay, OUT PHBPLAY2_DISPLAY_STATUS pDisplayStatus );

//��Ƶ����������
enum HBPLAY2_ADEC_CODEC_TYPE
{
    HBPLAY2_ADEC_CODEC_UNKNOWN = 0,                 //δ֪����������
    HBPLAY2_ADEC_CODEC_PCM_16_BIT,                  //δѹ����16λPCM
    HBPLAY2_ADEC_CODEC_PCM_LINEAR_8_BIT,            //8λ����PCM����Ҫ��չ��16λ
    HBPLAY2_ADEC_CODEC_G711_ALAW,                   //G.711 A��
    HBPLAY2_ADEC_CODEC_G722,                        //G.722
    HBPLAY2_ADEC_CODEC_G726,                        //Hisilicon G.726 16kbps
    HBPLAY2_ADEC_CODEC_COUNT,                       //��Ƶ����������
};
typedef struct HBPLAY2_ADEC_STATUS
{
    //�ṹ�峤�ȣ����ֽڣ�byte��Ϊ��λ��
    //�����߱������øó�Ա����sizeof(HBPLAY2_ADEC_STATUS)��
    DWORD                           dwSize;

    //��Ƶ�������֡����
    DWORD                           dwFrameCount;

    //��Ƶ�������ʱ�䣬��΢�루us��Ϊ��λ��
    LONGLONG                        llDecodeDuration;

    //��Ƶ���������͡�
    HBPLAY2_ADEC_CODEC_TYPE         CodecType;

    //������
    DWORD                           dwReserved;

} HBPLAY2_ADEC_STATUS, *PHBPLAY2_ADEC_STATUS;  
HRESULT WINAPI HB_PLAY2_GetAdecStatus( IN HHBPLAY2 hPlay, OUT PHBPLAY2_ADEC_STATUS pAdecStatus );

//��Ƶ��������
typedef struct HBPLAY2_SOUND_STATUS
{
    //�ṹ�峤�ȣ����ֽڣ�byte��Ϊ��λ��
    //�����߱������øó�Ա��С��sizeof(HBPLAY2_SOUND_STATUS)��
    DWORD                           dwSize;

    //���ű�־��
    //��־ΪFLASEʱ��ֹͣ�����������������ڲ���������
    BOOL                            bPlaying;

    //�������ݵĳ��ȣ����ֽ�Ϊ��λ��
    DWORD                           dwBufferedDataLength;

    //�������ݵ�ʱ�䣬�Ժ���Ϊ��λ��
    DWORD                           dwBufferedTime;

    //������
    DWORD                           dwReserved[2];

} HBPLAY2_SOUND_STATUS, *PHBPLAY2_SOUND_STATUS; 
HRESULT WINAPI HB_PLAY2_GetSoundStatus( IN HHBPLAY2 hPlay, OUT PHBPLAY2_SOUND_STATUS pSoundStatus );

//���ӻ��޸��ӿ�
typedef struct HBPLAY2_VIEWPORT
{
    //�ṹ�峤�ȣ����ֽڣ�byte��Ϊ��λ��
    //�����߱������øó�Ա����sizeof(HBPLAY2_VIEWPORT)��
    DWORD                           dwSize;

    //�ӿڱ�ʶ����
    //�ɵ�����ָ����Ψһ��־���������ֶ���ӿڡ�
    DWORD                           dwID;

    //��ʾ���ھ����
    //��������Ч�Ĵ��ھ����
    HWND                            hDestWnd;

    //������
    DWORD                           dwReserved[3];

    //ԭʼ���ݾ��Σ��þ��β��ܴ���ԭʼͼ��ĳߴ硣
    //������Ϊ��ʱ����ͨ��IsRectEmpty�����жϷ���ֵ��TRUE������ʾ����ԭʼͼ��
    //������Ϊ�ǿ�ʱ����ʾָ�����ֵ�ͼ��һ�����ھֲ��Ŵ���ʾ��
    RECT                            rcSrc;

    //��������ʾλ�á�
    //������Ϊ��ʱ����ͨ��IsRectEmpty�����жϷ���ֵ��TRUE����ͼ����ʾ�ڴ��ڵ������ͻ�����
    //������Ϊ�ǿ�ʱ��ͼ����ʾ�ڴ�����ָ����λ�á�һ��������һ����������ʾ���ͼ��
    RECT                            rcDest;

} HBPLAY2_VIEWPORT, *PHBPLAY2_VIEWPORT;   
HRESULT WINAPI HB_PLAY2_AddViewport( IN HHBPLAY2 hPlay, IN const HBPLAY2_VIEWPORT* pViewport );

//�Ƴ��ӿ�
HRESULT WINAPI HB_PLAY2_RemoveViewport( IN HHBPLAY2 hPlay, IN DWORD dwViewportID );

//��ȡ�ӿ�
HRESULT WINAPI HB_PLAY2_GetViewport( IN HHBPLAY2 hPlay, 
    OUT OPTIONAL PHBPLAY2_VIEWPORT pViewportArray, IN OUT DWORD* pViewportCount );

//ץͼ
typedef struct HBPLAY2_SNAP_PICTURE
{
    //�ṹ�峤�ȣ����ֽڣ�byte��Ϊ��λ��
    //�����߱������øó�Ա����sizeof(HBPLAY2_SNAP_PICTURE)��
    DWORD                           dwSize;

    //DIB���ݻ��������ȣ����ֽ�Ϊ��λ��
    DWORD                           dwBitsLength;

    //DIB���ݻ�����ָ�롣
    //����ͼ��ĳߴ磬�ȷ����㹻����ڴ档
    PVOID                           pBits;

    //������
    DWORD                           dwReserved;

    //����DIB�ߴ����ɫ��Ϣ��
    BITMAPINFOHEADER                bmiHeader;

} HBPLAY2_SNAP_PICTURE, *PHBPLAY2_SNAP_PICTURE;
#define HBPLAY2_JPEG_QUALITY_MIN    1               //JPEGͼ��������Сֵ
#define HBPLAY2_JPEG_QUALITY_MAX    100             //JPEGͼ���������ֵ
HRESULT WINAPI HB_PLAY2_SnapshotToMemory( IN HHBPLAY2 hPlay, IN OUT PHBPLAY2_SNAP_PICTURE pSnapPicture );
HRESULT WINAPI HB_PLAY2_SnapshotToBmpFileA( IN HHBPLAY2 hPlay, IN LPCSTR lpszFileName );
HRESULT WINAPI HB_PLAY2_SnapshotToBmpFileW( IN HHBPLAY2 hPlay, IN LPCWSTR lpszFileName );
HRESULT WINAPI HB_PLAY2_SnapshotToJpegFileA( IN HHBPLAY2 hPlay, IN LPCSTR lpszFileName, IN int nQuality );
HRESULT WINAPI HB_PLAY2_SnapshotToJpegFileW( IN HHBPLAY2 hPlay, IN LPCWSTR lpszFileName, IN int nQuality );
#ifdef _UNICODE
#define HB_PLAY2_SnapshotToBmpFile HB_PLAY2_SnapshotToBmpFileW
#define HB_PLAY2_SnapshotToJpegFile HB_PLAY2_SnapshotToJpegFileW
#else
#define HB_PLAY2_SnapshotToBmpFile HB_PLAY2_SnapshotToBmpFileA
#define HB_PLAY2_SnapshotToJpegFile HB_PLAY2_SnapshotToJpegFileA
#endif

//����������
HRESULT WINAPI HB_PLAY2_InputData( IN HHBPLAY2 hPlay, IN LPCVOID pBuffer, IN DWORD dwBufferLength );

//���ظ�ʽ
//�� http://www.fourcc.org/yuv.php �鿴FOURCC�����YUV���ڴ����С�
#ifndef MAKEFOURCC
#define MAKEFOURCC(ch0, ch1, ch2, ch3)                  \
    ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
    ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))
#endif //defined(MAKEFOURCC)

#define HBPLAY2_PIXEL_UNCHANGE      0                               //���ı����ظ�ʽ
#define HBPLAY2_PIXEL_RGB24         2                               //���24λ��RGBRGB...
#define HBPLAY2_PIXEL_BGR24         3                               //���24λ����õ�RGB��ʽ����BGRBGR...
#define HBPLAY2_PIXEL_UYVY          MAKEFOURCC('U', 'Y', 'V', 'Y')  //���16λ��ͬY422��UYNV��HDYC
#define HBPLAY2_PIXEL_YUY2          MAKEFOURCC('Y', 'U', 'Y', '2')  //���16λ��ͬYUNV��V422��YUYV
#define HBPLAY2_PIXEL_YV12          MAKEFOURCC('Y', 'V', '1', '2')  //ƽ��12λ
#define HBPLAY2_PIXEL_I420          MAKEFOURCC('I', '4', '2', '0')  //ƽ��12λ��ͬIYUV
#define HBPLAY2_PIXEL_NV12          MAKEFOURCC('N', 'V', '1', '2')  //ƽ��12λ
#define HBPLAY2_PIXEL_NV21          MAKEFOURCC('N', 'V', '2', '1')  //ƽ��12λ

//֡����
enum HBPLAY2_FRAME_TYPE
{
    HBPLAY2_FRAME_UNKNOWN,                          //δ֪֡����
    HBPLAY2_FRAME_AUDIO,                            //��Ƶ֡
    HBPLAY2_FRAME_VIDEO_I,                          //��ƵI֡
    HBPLAY2_FRAME_VIDEO_P,                          //��ƵP֡
    HBPLAY2_FRAME_VIDEO_B,                          //��ƵB֡
    HBPLAY2_FRAME_VIDEO_E,                          //��ƵE֡
    HBPLAY2_FRAME_COUNT,                            //֡��������
};

//�ж�֡����
#define HB_PLAY2_IsAudioFrame(FrameType) (HBPLAY2_FRAME_AUDIO == (FrameType))
#define HB_PLAY2_IsVideoFrame(FrameType) ((FrameType) >= HBPLAY2_FRAME_VIDEO_I\
                                    && (FrameType) <= HBPLAY2_FRAME_VIDEO_E)

//֡��Ϣ
typedef struct HBPLAY2_FRAME
{
    //����
    PVOID                           Reserved0;

    //����
    DWORD                           dwReserved1[2];

    //֡����
    //֡����ΪHBPLAY2_FRAME_AUDIOʱ��u.Audio��Ч��
    //֡����ΪHBPLAY2_FRAME_VIDEO_*ʱ��u.Video��Ч��
    HBPLAY2_FRAME_TYPE              FrameType;

    union FRAME
    {
        struct FRAME_AUDIO
        {
            //֡ͷ���ȣ����ֽ�Ϊ��λ��
            DWORD                   dwHeaderSize;

            //֡ͷ��ַ��
            PVOID                   pHeader;

            //�������ݳ��ȣ����ֽ�Ϊ��λ��
            DWORD                   dwDataSize;

            //�������ݵ�ַ��
            PVOID                   pData;

            //��Ƶͨ������
            WORD                    wChannels;

            //�������ȡ�
            WORD                    wBitsPerSample; 

            //�����ʣ��Ժ��ȣ�Hz��Ϊ��λ��
            DWORD                   dwSampleRate; 

            //���뻺������
            PVOID                   pBuffer;

            //���뻺�����ĳ��ȣ����ֽ�Ϊ��λ��
            //����ʱ��˵�����������ܳ��ȡ�
            //���ʱ��˵����������ʵ��ʹ�ó��ȡ�
            DWORD                   dwBufferLength;

            //������
            DWORD                   dwReserved[4];

        } Audio;

        struct FRAME_VIDEO
        {
            //֡ͷ���ȣ����ֽ�Ϊ��λ��
            DWORD                   dwHeaderSize;

            //֡ͷ��ַ��
            PVOID                   pHeader;

            //�������ݳ��ȣ����ֽ�Ϊ��λ��
            DWORD                   dwDataSize;

            //�������ݵ�ַ��
            PVOID                   pData;

            //ͼ���ȣ�������Ϊ��λ��
            int                     nWidth;

            //ͼ��߶ȣ�������Ϊ��λ��
            int                     nHeight;

            //���ļ���ʼ��ַ��ƫ�����������ļ�������
            LONGLONG                llOffset;

            //��Ƶ֡����ʱ�䡣
            SYSTEMTIME              TimeStamp;

            //֡��š�
            //֡������𽥵����ģ������ж���Ƶ֡�������ԡ�
            DWORD                   dwIndex;

            //��Ƶ֡���ʱ�䣬�Ժ���Ϊ��λ��
            //������֮֡��Ĳ�ֵ����������֮֡���ʱ������
            DWORD                   dwTickCount;

            //ʵ����������ظ�ʽ������Ƶ���������øø�ʽ��HBPLAY2_PIXEL_*�꣩��
            DWORD                   dwPixelFormat;

            //���뻺������
            PVOID                   pBuffer;

            //���뻺�����ĳ��ȣ����ֽ�Ϊ��λ��
            DWORD                   dwBufferLength;

            //������
            DWORD                   dwReserved[3];

        } Video;
    } u;

} HBPLAY2_FRAME, *PHBPLAY2_FRAME;

//��ȡ/�ͷŽ�������
HRESULT WINAPI HB_PLAY2_GetDecodeFrame( IN HHBPLAY2 hPlay, IN DWORD dwPixelFormat,
    OUT PHBPLAY2_FRAME pFrame );
HRESULT WINAPI HB_PLAY2_FreeDecodeFrame( IN HHBPLAY2 hPlay, IN OUT PHBPLAY2_FRAME pFrame );

//�����ļ��Ĳ���λ��
HRESULT WINAPI HB_PLAY2_SeekByRatio( IN HHBPLAY2 hPlay, IN float fRatio );
HRESULT WINAPI HB_PLAY2_SeekByTime( IN HHBPLAY2 hPlay, IN DWORD dwTime );
HRESULT WINAPI HB_PLAY2_SeekByIndex( IN HHBPLAY2 hPlay, IN DWORD dwIndex );
HRESULT WINAPI HB_PLAY2_SeekNextIndex( IN HHBPLAY2 hPlay );
HRESULT WINAPI HB_PLAY2_SeekPreviousIndex( IN HHBPLAY2 hPlay );

//ע���ļ�������ɻص�����
typedef void (CALLBACK* PHB_PLAY2_FILE_INDEX_COMPLETED_PROC)(
    IN HHBPLAY2 hPlay, IN PVOID pContext );
HRESULT WINAPI HB_PLAY2_RegisterFileIndexCompletedCallback( IN HHBPLAY2 hPlay, 
    IN PHB_PLAY2_FILE_INDEX_COMPLETED_PROC pfnCallback, IN PVOID pContext );

//ע���ļ������ص�����
typedef void (CALLBACK* PHB_PLAY2_FILE_ENDED_PROC)(
    IN HHBPLAY2 hPlay, IN PVOID pContext );
HRESULT WINAPI HB_PLAY2_RegisterFileEndedCallback( IN HHBPLAY2 hPlay, 
    IN PHB_PLAY2_FILE_ENDED_PROC pfnCallback, IN PVOID pContext );

//ע�Ỻ�����ӽ��ջص�����
#define HBPLAY2_BUFFER_EMPTY_THRESHOLD_MIN  0
#define HBPLAY2_BUFFER_EMPTY_THRESHOLD_MAX  150
typedef void (CALLBACK* PHB_PLAY2_BUFFER_ALMOST_EMPTY_PROC)( 
    IN HHBPLAY2 hPlay, IN DWORD dwBufferedFrameCount, IN PVOID pContext );
HRESULT WINAPI HB_PLAY2_RegisterBufferAlmostEmptyCallback( IN HHBPLAY2 hPlay, 
    IN DWORD dwThreshold, IN PHB_PLAY2_BUFFER_ALMOST_EMPTY_PROC pfnCallback, 
    IN PVOID pContext );

//ע�����������ص�����
typedef void (CALLBACK* PHB_PLAY2_STREAM_PARSE_PROC)( 
    IN HHBPLAY2 hPlay, IN const HBPLAY2_FRAME* pFrame, IN PVOID pContext );
HRESULT WINAPI HB_PLAY2_RegisterStreamParseCallback( IN HHBPLAY2 hPlay, 
    IN PHB_PLAY2_STREAM_PARSE_PROC pfnCallback, IN PVOID pContext );

//ע�����ص�����
typedef void (CALLBACK* PHB_PLAY2_DECODE_PROC)( 
    IN HHBPLAY2 hPlay, IN const HBPLAY2_FRAME* pFrame, IN PVOID pContext );
HRESULT WINAPI HB_PLAY2_RegisterDecodeCallback( IN HHBPLAY2 hPlay, 
    IN DWORD dwPixelFormat, IN PHB_PLAY2_DECODE_PROC pfnCallback, IN PVOID pContext );

//ע��DC��ͼ�ص�����
typedef void (CALLBACK* PHB_PLAY2_DC_RENDER_PROC)( 
    IN HHBPLAY2 hPlay, IN HDC hDC, IN const HBPLAY2_VIEWPORT* pViewport,
    IN PVOID pContext );
HRESULT WINAPI HB_PLAY2_RegisterDcRenderCallback( IN HHBPLAY2 hPlay, 
    IN PHB_PLAY2_DC_RENDER_PROC pfnCallback, IN PVOID pContext );

//�ϲ�¼���ļ�
HRESULT WINAPI HB_PLAY2_MergeFileA( IN LPCSTR lpszDestFile,
    IN LPCSTR* lpSrcFileArray, IN DWORD dwSrcFileCount );
HRESULT WINAPI HB_PLAY2_MergeFileW( IN LPCWSTR lpszDestFile,
    IN LPCWSTR* lpSrcFileArray, IN DWORD dwSrcFileCount );
#ifdef _UNICODE
#define HB_PLAY2_MergeFile HB_PLAY2_MergeFileW
#else
#define HB_PLAY2_MergeFile HB_PLAY2_MergeFileA
#endif


////////////////////////////////////////////////////////////////////////////////
//����HB_PLAY2 API
////////////////////////////////////////////////////////////////////////////////








////////////////////////////////////////////////////////////////////////////////
//Define HB_PLAY API
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Macro definition.
////////////////////////////////////////////////////////////////////////////////


// the message sent when the index has been created
#define MSG_INDEX_OK            (WM_USER+154)

// the maximum number of regions for display in a channel.
#define MAX_DISPLAY_WND         4 

// frame type
#define UNKOWN_FRAME_TYPE       0x0000      // unknown frame type
#define VIDEO_FRAME_I           0x2000      // video I-frame
#define VIDEO_FRAME_P           0x2001      // video P-frame
#define VIDEO_FRAME_B           0x2002      // video B-frame
#define VIDEO_FRAME_E           0x2003      // video E-frame
#define AUDIO_FRAME_ALAW        0x1000      // audio A-law
#define AUDIO_FRAME_G722        0x1001      // audio G722
#define AUDIO_FRAME_G726        0x1002      // audio G726
#define AUDIO_FRAME_PCM8_16     0x1003      // audio compressed 8-bit linear PCM

// the decoding formats for the output
#define OUT_FMT_YUV_420         0x00000601  // YUV420, equal to OUT_FMT_I420
#define OUT_FMT_YUV_422         0x00000102  // YUV422, equal to OUT_FMT_YUY2
#define OUT_FMT_AUDIO           0x00000602  // audio, PCM 8000Hz, 16-bit sampling, 1 channel

// pixel format
// see http://www.fourcc.org/yuv.php for more information
#ifndef MAKEFOURCC
#define MAKEFOURCC(ch0, ch1, ch2, ch3)                  \
    ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
    ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))
#endif //defined(MAKEFOURCC)

#define OUT_FMT_UYVY             MAKEFOURCC('U', 'Y', 'V', 'Y')  // packet 16-bit YUV, equal to Y422, UYNV, HDYC
#define OUT_FMT_YUY2             MAKEFOURCC('Y', 'U', 'Y', '2')  // packet 16-bit YUV, equal to YUNV, V422, YUYV
#define OUT_FMT_YV12             MAKEFOURCC('Y', 'V', '1', '2')  // planner 12-bit YUV
#define OUT_FMT_I420             MAKEFOURCC('I', '4', '2', '0')  // planner 12-bit YUV, equal to IYUV
#define OUT_FMT_NV12             MAKEFOURCC('N', 'V', '1', '2')  // planner 12-bit YUV
#define OUT_FMT_NV21             MAKEFOURCC('N', 'V', '2', '1')  // planner 12-bit YUV
#define OUT_FMT_RGB24            2                               // packet 24-bit, RGBRGB...
#define OUT_FMT_BGR24            3                               // packet 24-bit (the most common RGB format), BGRBGR...


////////////////////////////////////////////////////////////////////////////////
// Structure definition.
////////////////////////////////////////////////////////////////////////////////

// The data type of input.
enum HB_PLAY_MODE
{
    HB_FILE_MODE,                       // Read data from a file.
    HB_STREAM_REALTIME_MODE,            // Receive real-time data.
    HB_STREAM_FILE_MODE                 // Input data from a file as stream.
};

// The type of hardware accelerated decoder.
enum HB_HD_TYPE
{
    HB_HD_NOT_SUPPORTED=1,
    HB_HD_AUTO,            // Determines the decoder according to graphics type.
    HB_HD_NVIDIA_CUDA,     // NVIDIA graphics solution.
    HB_HD_MS_DXVA          // Microsoft solution.
};

// detailed information of the frame
typedef struct _HB_FRAME
{
    DWORD           dwFrameNumber;      // frame number, incremental

    WORD            wFrameType;         // frame type
    BYTE            cbAlgorithm;        // algorithm
    BYTE            cbVersion;          // version

    WORD            wWidth;             // picture width in pixels
    WORD            wHeight;            // picture height in pixels

    DWORD           dwDTS;              // the time stamp of the frame, in milliseconds
    SYSTEMTIME      ETS;                // the system time when encoded

    DWORD           dwEncryptFlag;      // encrypt flag
    DWORD           dwEncryptKey;       // encrypt key
    DWORD           dwEncryptText;      // encrypt text

    WORD            wOsdFlag;           // OSD flag, valid only for video frame
    WORD            wOsdLines;          // Represents the OSD lines if the wOsdFlag 
                                        // parameter is not null, otherwise null. 
    LPVOID          pOsd;               // the long pointer to the OSD information
    DWORD           dwReserved;         // reserved for  alignment 

    ULARGE_INTEGER  ulOffset;           // the offset of bytes from the beginning of file
                                        // to the current position

    DWORD           dwHeaderSize;       // the size of the frame header 
    PVOID           pHeader;            // the pointer to the frame header

    DWORD           dwDataSize;         // the size of the frame data
    PVOID           pData;              // the pointer to the frame data

    DWORD           Reserved[8];        // reserved
}HB_FRAME, *PHB_FRAME;

// brief information of the frame
typedef struct	_HB_FRAME_INFO
{
    long            nWidth;             // picture width in pixels, 0 if audio
    long            nHeight;            // picture height in pixels, 0 if audio
    long            nStamp;             // the time stamp of the frame in milliseconds
    long            nType;              // the decoding format for the output
    long            nFrameRate;         // frame rate
}HB_FRAME_INFO, *PHB_FRAME_INFO;

// time information of the frame
typedef	struct _HB_VIDEO_TIME
{
    short           year;               // year
    short           month;              // month
    short           day;                // day
    short           hour;               // hour
    short           minute;	            // minute
    short           second;             // second
    short           milli;              // millisecond
    short           week;               // week
}HB_VIDEO_TIME, *PHB_VIDEO_TIME;

// position information of the frame
typedef struct _HB_FRAME_POS
{
    // the offset of bytes from the beginning of file to the current position
    ULARGE_INTEGER  nFilePos;
    long            nFrameNum;          // frame number
    long            nFrameTime;         // the time stamp of the frame in milliseconds
}HB_FRAME_POS, *PHB_FRAME_POS;

// single frame information
typedef struct _HB_FRAME_INFO_EX
{
    DWORD           dwFrameType;        // frame type, OUT_FMT_AUDIO or pixel format
    DWORD           dwFrameSize;        // the frame size, in bytes
    PVOID           pFrame;             // the pointer to the frame buffer

    // Only for video frame.
    DWORD           dwWidth;            // picture width in pixels
    DWORD           dwHeight;           // picture height in pixels
    DWORD           dwDTS;              // the time stamp of the frame in milliseconds

    // Only for audio frame.
    DWORD           dwSampleRate;       // audio sampling rate
    DWORD           dwSampleBit;        // audio sampling bits

    DWORD           dwReserved[4];      // reserved
}HB_FRAME_INFO_EX, *PHB_FRAME_INFO_EX;

//��������Ʋ���
enum HB_PLAY_STREAM
{
    HB_PLAY_STREAM_NONE              = 0,           //����������Ʋ���
    HB_PLAY_STREAM_REALTIME_PRIORITY = 10,          //ʵʱ������
    HB_PLAY_STREAM_BALANCED          = 20,          //����
    HB_PLAY_STREAM_FLUENCY_PRIORITY  = 30,          //����������
};

////////////////////////////////////////////////////////////////////////////////
// Callback functions definition.
////////////////////////////////////////////////////////////////////////////////

// For HB_PLAY_SetParseCallBackEx.
typedef void (CALLBACK* LPSRCDATAPARSECBFUNEX)(long nChl, const HB_FRAME* pFrame, LPVOID pContext);

// For HB_PLAY_SetParseCallBack.
typedef void (CALLBACK* LPSRCDATAPARSECBFUN)(long nChl, char* SrcDataBuf,
            long nFrameType, long nReserved1, long nReserved2, HB_VIDEO_TIME ets);

// For HB_PLAY_SetDecCallBackEx.
typedef void (CALLBACK* LPDECCBFUN)(long nChl, char* pBuf, long nSize,
            HB_FRAME_INFO* pFrameInfo, LPVOID pContext, HB_VIDEO_TIME* pVideoTime);

// For HB_PLAY_RegisterDrawDCFun
typedef void (CALLBACK* LPDRAWDCFUN)(long nChl, HDC hDC, long nUserData);

// For HB_PLAY_SetSnapShotCallBack
typedef void (CALLBACK* LPSNAPSHOTCBFUN)(long nChl, DWORD nSize, char* pBuf,
            long nWidth, long hHeight, long nType);

// For HB_PLAY_SetIndexInfoCallBack
typedef void (CALLBACK* LPINDEXCBFUN)(long nChl, long nUserData);

// For HB_PLAY_SetSourceBufferCB.
typedef void (CALLBACK* LPSOURCEBUFCALLBACK)(long nChl, DWORD dwBufSize,
            void* pUser, void* pResvered);

// For HB_PLAY_SetDisplayCallBack.
typedef void (CALLBACK* LPDISPLAYCBFUN)(long nChl, char* pBuf, long nSize, long nWidth, 
    long hHeight, long nStamp, long nType, long nReserved);


////////////////////////////////////////////////////////////////////////////////
// Functions definition.
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_OpenFile.
// Description:
//      Opens a Hangban video file.
// Parameters:
//      [in] nChl - Channel number.
//      [in] sFile - File name.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      Must call this function before operating a channel. When the channel is
//      no longer needed, close it by HB_PLAY_CloseFile.
//      There are two versions of the function, ANSI and Unicode:
//      HB_PLAY_OpenFileA, ANSI version.
//      HB_PLAY_OpenFileW, Unicode version.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_OpenFile(long nChl, LPCSTR sFile);
BOOL __stdcall HB_PLAY_OpenFileA(long nChl, LPCSTR sFile);
BOOL __stdcall HB_PLAY_OpenFileW(long nChl, LPCWSTR sFile);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_OpenFileEx.
// Description:
//      Opens a Hangban video file.
// Parameters:
//      [in] sFile - File name.
// Return:
//      If the channel is opened successfully, this function returns a valid channel
//      number, which can also be considered as channel handle; otherwise returns 0.
// Remarks:
//      Must call this function before operating a channel. When the channel is
//      no longer needed, close it by HB_PLAY_CloseFile.
//      There are two versions of the function, ANSI and Unicode:
//      HB_PLAY_OpenFileExA, ANSI version.
//      HB_PLAY_OpenFileExW, Unicode version.
////////////////////////////////////////////////////////////////////////////////
long __stdcall HB_PLAY_OpenFileEx(LPCSTR sFile);
long __stdcall HB_PLAY_OpenFileExA(LPCSTR sFile);
long __stdcall HB_PLAY_OpenFileExW(LPCWSTR sFile);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_CloseFile.
// Description:
//      Closes the channel, which was opened by HB_PLAY_OpenFile or HB_PLAY_OpenFileEx.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_CloseFile(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function:
//      HB_PLAY_Play.
// Description:
//      Start to play a file or stream.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] hWnd - Handle to the window for displaying video.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_Play(long nChl, HWND hWnd);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_Pause.
// Description:
//      Pauses the play of the file.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_Pause(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_Stop.
// Description:
//      Stops the play of the file.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      Valid when the channel is opened by HB_PLAY_OpenFile or HB_PLAY_OpenFileEx.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_Stop(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_Fast.
// Description:
//      Speeds up the play rate.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      For each call, the play rate speeds up to the twice of the original rate.
//      Maintains the maximum rate if it has already speeded up to the 16 times
//      of the normal rate.
//      Call HB_PLAY_Play to resume the normal rate from current frame.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_Fast(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_Slow.
// Description:
//      Slows down the play rate.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      For each call, the play rate slows down to the half of the original rate.
//      Maintains the minimum rate if it has already slowed down to 1/16 of the normal rate.
//      Call HB_PLAY_Play to resume the normal rate from current frame.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_Slow(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_OneByOne.
// Description:
//      Plays one single frame forward.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      For each call, plays one frame forward.
//      HB_PLAY_PlayBySingleFrame is the same as HB_PLAY_OneByOne.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_OneByOne(long nChl);
BOOL __stdcall HB_PLAY_PlayBySingleFrame(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_OneByOneBack.
// Description:
//      Plays one single frame backwards.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      For each call, plays one frame backwards.
//      Valid when the index has been created.
//      HB_PLAY_PlayBySingleFrameBack is the same as HB_PLAY_OneByOneBack.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_OneByOneBack(long nChl);
BOOL __stdcall HB_PLAY_PlayBySingleFrameBack(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_PlayBack.
// Description:
//      Plays backwards continuously from current frame.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      Valid when the index has been created.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_PlayBack(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetFileTime.
// Description:
//      Gets the total time for playing the opened file.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      The total time for playing the opened file in seconds.
// Remarks:
//      Valid when the index has been created.
////////////////////////////////////////////////////////////////////////////////
DWORD __stdcall HB_PLAY_GetFileTime(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetFileTimeMilliSec.
// Description:
//      Gets the total time for playing the opened file.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      The total time for playing the opened file in milliseconds.
// Remarks:
//      Valid when the index has been created.
////////////////////////////////////////////////////////////////////////////////
DWORD __stdcall HB_PLAY_GetFileTimeMilliSec(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetFileFrames.
// Description:
//      Gets the total frames of the opened file.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      The total frames of the opened file.
// Remarks:
//      Valid when the index has been created.
//      HB_PLAY_GetFileTotalFrames is the same as HB_PLAY_GetFileFrames.
////////////////////////////////////////////////////////////////////////////////
DWORD __stdcall HB_PLAY_GetFileFrames(long nChl);
DWORD __stdcall HB_PLAY_GetFileTotalFrames(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetPlayedFrames.
// Description:
//      Gets the frames already decoded.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      The frames already decoded.
// Remarks:
//      HB_PLAY_GetPlayedFrameNum is the same as HB_PLAY_GetPlayedFrames.
////////////////////////////////////////////////////////////////////////////////
long __stdcall HB_PLAY_GetPlayedFrames(long nChl);
long __stdcall HB_PLAY_GetPlayedFrameNum(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetCurrentFrameRate.
// Description:
//      Gets the current frame rate.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      The current frame rate.
// Remarks:
//      HB_PLAY_GetCurrFrameRate is the same as HB_PLAY_GetCurrentFrameRate.
////////////////////////////////////////////////////////////////////////////////
DWORD __stdcall HB_PLAY_GetCurrentFrameRate(long nChl);
DWORD __stdcall HB_PLAY_GetCurrFrameRate(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetPlaySpeed.
// Description:
//      Sets play rate for speeding up or slowing down.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] dwSpeed - Effective values: 2, 4, 8 and 16.
//      [in] bSlow - If TRUE, slow down; otherwise speed up.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      Call HB_PLAY_Play to play normally.
//      If bSlow is FALSE, the play rate equals the value of dwSpeed.
//      If bSlow is TRUE, the play rate equals the reciprocal of the value of dwSpeed.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetPlaySpeed(long nChl, long dwSpeed, BOOL bSlow);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetCurrentFrameNum.
// Description:
//      Gets current frame number.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Current frame number.
// Remarks:
//      HB_PLAY_GetCurrFrameNum is the same as HB_PLAY_GetCurrentFrameNum.
////////////////////////////////////////////////////////////////////////////////
DWORD __stdcall HB_PLAY_GetCurrentFrameNum(long nChl);
long __stdcall HB_PLAY_GetCurrFrameNum(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetCurrentFrameNum.
// Description:
//      Sets current frame number.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] dwFrameNum - Current frame number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      Valid when the index has been created.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetCurrentFrameNum(long nChl, DWORD dwFrameNum);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetPlayedTimeEx.
// Description:
//      Gets current playing time.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      HB_PLAY_GetPlayTime is the same as HB_PLAY_GetPlayedTimeEx.
////////////////////////////////////////////////////////////////////////////////
DWORD __stdcall HB_PLAY_GetPlayedTimeEx(long nChl);
DWORD __stdcall HB_PLAY_GetPlayTime(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetPlayedTimeEx.
// Description:
//      Sets current playing time.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] dwTime - Current playing time in milliseconds.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      Both HB_PLAY_GetCurrentFrameNum and HB_PLAY_SetPlayTime are the same
//      as HB_PLAY_SetPlayedTimeEx.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetPlayedTimeEx(long nChl, DWORD dwTime);
BOOL __stdcall HB_PLAY_SetPlayedTime(long nChl, DWORD dwTime);
BOOL __stdcall HB_PLAY_SetPlayTime(long nChl, DWORD dwTime);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetPlayPos.
// Description:
//      Gets play position.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Play position in percentage.
// Remarks:
//      Valid when the index has been created.
////////////////////////////////////////////////////////////////////////////////
float __stdcall HB_PLAY_GetPlayPos(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetPlayPos.
// Description:
//      Sets play position.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] dPos - Play position in percentage.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      Valid when the index has been created.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetPlayPos(long nChl, float dPos);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetFileEndMsg.
// Description:
//      Sets the window specified by hWnd to receive the message specified by nMsg
//      when the file is played to the end.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] hWnd - The handle of the window.
//      [in] nMsg - The message ID.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetFileEndMsg(long nChl, HWND hWnd, UINT nMsg);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_OpenSound.
// Description:
//      Opens sound.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      HB_PLAY_PlaySound is the same as HB_PLAY_OpenSound.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_OpenSound(long nChl);
BOOL __stdcall HB_PLAY_PlaySound(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_CloseSound.
// Description:
//      Closes sound.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      If the sound has been opened by HB_PLAY_OpenSound or HB_PLAY_PlaySound,
//      call this function to stop playing audio. 
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_CloseSound(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetVolume.
// Description:
//      Gets the volume of the sound.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      The volume of the sound.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
WORD __stdcall HB_PLAY_GetVolume(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetVolume.
// Description:
//      Sets the volume of the sound.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] nVolume - The volume of the sound, ranging from 0 to 65535.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetVolume(long nChl, WORD nVolume);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetPictureSize.
// Description:
//      Gets the original size of the picture.
// Parameters: 
//      [in] nChl - Channel number.
//      [out] pWidth - The pointer to the original picture width .
//      [out] pHeight - The pointer to the original picture height.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      Couldn't get correct value until a frame is decoded successfully.
//      If the picture size changes, call this function to get the new value.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_GetPictureSize(long nChl, long* pWidth, long* pHeight);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_RegisterDrawDCFun.
// Description: 
//      Sets callback function.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] DrawDCFun - Callback function pointer.
//           void CALLBACK DrawDCFun(long nChl, HDC hDC, long nUserData);
//              - [in] nChl - Channel number.
//              - [in] hDC - The handle of DC.
//              - [in] nUserData - User data.
//      [in] nUserData - User data.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      This function would be called when the index has been created.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_RegisterDrawDCFun(long nChl, LPDRAWDCFUN DrawDCFun, long nUserData);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetDecCallBackEx.
// Description:
//      Sets callback function after decoding.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] DecCBFun - The callback function pointer.
//           void CALLBACK DecCBFun(long nChl, char* pBuf, long nSize, 
//              FRAME_INFO* pFrameInfo, long nReserved1, long nReserved2);
//              - [in] nChl - Channel number.
//              - [in] pBuf - The pointer to the output YUV data.
//              - [in] nSize - The size of the output YUV data.
//              - [in] pFrameInfo - The pointer to the frame information.
//              - [in] pContext - Pointer to a user defined variable.
//              - [in] nReserved - Reserved.
//      [in] pContext - Pointer to a user defined variable.
//      [in] nReserved - Reserved.
//      [in] nOutFormat - The formats of output YUV data. For format details, refer
//           to the decoding formats for the output in Macro definition.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetDecCallBackEx(long nChl, LPDECCBFUN DecCBFun,
    LPVOID pContext, long nReserved, long nOutFormat);

BOOL __stdcall HB_PLAY_SetDecCallBack(long nChl, LPDECCBFUN DecCBFun,long nOutFormat);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetParseCallBackEx.
// Description:
//      Sets callback function.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] pfnParse - Callback function pointer.
//           void CALLBACK SrcDataParseCBFun(long nChl, const HB_FRAME* pFrame, LPVOID pContext);
//              - [in] nChl - Channel number.
//              - [in] pFrame - The pointer to the original data of a frame.
//              - [in] pContext - Reserved.
//      [in] pContext - Reserved.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetParseCallBackEx(long nChl,
    LPSRCDATAPARSECBFUNEX pfnParse, LPVOID pContext );


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetParseOnly.
// Description:
//      Sets whether to decode or not.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] bParseOnly - Decode or not.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      If bParseOnly is TRUE, the SDK does not execute decoding.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetParseOnly(long nChl, BOOL bParseOnly);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetPlayOption.
// Description:
//      Sets play options, including displaying or not, and playing audio or not.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] bEnableDisplay - Display or not.
//      [in] bEnableSound - Play audio or not.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetPlayOption(long nChl, BOOL bEnableDisplay, BOOL bEnableSound);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetDisplayRegion.
// Description:
//      Sets display region.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] nRegionNum - Display region number from 1 to (MAX_DISPLAY_WND-1).
//      [in] pSrcRect - The pointer to the original picture region.
//      [in] hDestWnd - Handle of the destination window.
//      [in] bEnable - Enable or disable the display region.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetDisplayRegion(long nChl, DWORD nRegionNum,
    RECT* pSrcRect, HWND hDestWnd, BOOL bEnable);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_OpenStream.
// Description:
//      Opens stream.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] pFileHeadBuf - The pointer to the header buffer of the stream data.
//      [in] dwSize - The size of the header buffer of the stream data.
//      [in] dwReserved - Reserved.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      When the channel is no longer needed, close it by HB_PLAY_CloseStream.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_OpenStream(long nChl, char* pFileHeadBuf, DWORD dwSize, DWORD dwReserved);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_OpenStreamEx.
// Description:
//      Searches for an unoccupied channel to open stream.
// Parameters: 
//      [in] pFileHeadBuf - The pointer to the header buffer of the stream data.
//      [in] dwSize - The size of the header buffer of the stream data.
//      [in] dwReserved - Reserved.
// Return:
//      If the channel is opened successfully, this function returns a valid channel
//      number, which can also be considered as channel handle; otherwise returns 0.
// Remarks:
//      When the channel is no longer needed, close it by HB_PLAY_CloseStream.
////////////////////////////////////////////////////////////////////////////////
long __stdcall HB_PLAY_OpenStreamEx(char* pFileHeadBuf, DWORD dwSize, DWORD dwReserved);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_InputData.
// Description:
//      Inputs stream data.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] pBuf - Stream data.
//      [in] dwnSize - Stream data size.
//      [in] dwReserved - Reserved, must be zero.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      Valid when HB_PLAY_OpenStream or HB_PLAY_OpenStreamEx is called.
//      This function would return FALSE if the stream data is input too fast.
//      In this case, the stream data should be input once more.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_InputData(long nChl, char* pBuf, DWORD dwSize, DWORD dwReserved);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_CloseStream.
// Description:
//      Closes the stream, which is opened by HB_PLAY_OpenStream or HB_PLAY_OpenStreamEx..
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_CloseStream(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetMsgWnd.
// Description:
//      Sets the window to receive the message when the index has been created.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] hWnd - Handle to the window to receive the MSG_INDEX_OK message.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetMsgWnd(long nChl, HWND hWnd);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SnapShot.
// Description:
//      Catches a picture, and saves it to an assigned file.
// Parameters:
//      [in] nChl - Channel number.
//      [in] sFile - File name.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      There are two versions of the function, ANSI and Unicode:
//      HB_PLAY_SnapshotA, ANSI version.
//      HB_PLAY_SnapshotW, Unicode version.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SnapShot(long nChl, LPCSTR sFile);
BOOL __stdcall HB_PLAY_SnapshotA(long nChl, LPCSTR sFile);
BOOL __stdcall HB_PLAY_SnapshotW(long nChl, LPCWSTR sFile);

#ifdef _UNICODE
#define HB_PLAY_Snapshot HB_PLAY_SnapshotW
#else
#define HB_PLAY_Snapshot HB_PLAY_SnapshotA
#endif


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetDynamicBPS.
// Description:
//      Gets the real-time bit rate of the stream.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      The real-time bit rate of the stream in kbps(kilobits per second).
// Remarks:
//      Returns nonzero values when played for a while.
////////////////////////////////////////////////////////////////////////////////
double __stdcall HB_PLAY_GetDynamicBPS(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetAverageBPS.
// Description:
//      Gets the average bit rate of the stream.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      The average bit rate of the stream in kbps.
// Remarks:
//      Returns nonzero values when played for a while.
////////////////////////////////////////////////////////////////////////////////
double __stdcall HB_PLAY_GetAverageBPS(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetVideoColor.
// Description: 
//      Sets video color.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] nBrightness - Brightness, ranging from 0 to 127, 64 by default.
//      [in] nContrast - Contrast, ranging from 0 to 127, 64 by default.
//      [in] nSaturation - Saturation, ranging from 0 to 127, 64 by default4.
//      [in] nHue - Hue, ranging from 0 to 127, 64 by default.
//      [in] nReserved - Reserved.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetVideoColor(long nChl, long nBrightness,
    long nContrast, long nSaturation , long nHue, long nReserved);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetVideoColor.
// Description: 
//      Gets video color.
// Parameters: 
//      [in] nChl - Channel number.
//      [out] pBrightness - Pointer to brightness.
//      [out] pContrast - Pointer to contrast.
//      [out] pSaturation - Pointer to saturation.
//      [out] pHue - Pointer to hue.
//      [in] nReserved - Reserved.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_GetVideoColor(long nChl, long* pBrightness,
    long *pContrast, long *pSaturation , long *pHue, long nReserved);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetIndexInfoCallBack.
// Description: 
//      Sets callback function.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] IndexCBFunc - Callback function pointer.
//           void CALLBACK IndexCBFunc(long nChl, long nReserved);
//              - [in] nChl - Channel number.
//              - [in] nUserData - User data.
//      [in] nUserData - User data.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//	    This function would be called when the index has been creation.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetIndexInfoCallBack(long nChl, LPINDEXCBFUN IndexCBFun, long nUserData);


////////////////////////////////////////////////////////////////////////////////
// Function:
//      HB_PLAY_GetFileHead.
// Description:
//      Retrieves file header size and file header information.
// Parameters: 
//      [in] nChl - Channel number.
//      [out] pBuffer - The pointer to the file header information.
//      [in/out] pSize - The pointer to the size of the file header.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      Call this function for twice. Retrives the file header size for the 
//      first call, and the file header information for the second call.
//      The second call would be valid only when the return value of the 
//      first call is nonzero.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_GetFileHead(long nChl, BYTE* pBuffer, DWORD* pSize);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetCPULimitEx.
// Description: 
//      Retrieves CPU limitation.
// Parameters: 
//      [in] nChl - Channel number.
//      [out] pCpuUse - Pointer to CPU usage limitation.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_GetCPULimitEx(long nChl, int* pCpuUse);


////////////////////////////////////////////////////////////////////////////////
// Function:
//      HB_PLAY_SetCPULimitEx.
// Description:
//      Limits CPU usage. If the CPU usage is larger than the limitation,
//      decoding will be delayed.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] nCpuUse - CPU usage limitation, from 50 to 100.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      The default limitation is 100, which means that CPU usage is unlimited.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetCPULimitEx(long nChl, int nCpuUse);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_DecodeOneFrame.
// Description: 
//      Decode an audio or video frame.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] pInputFrame - Stream data, including audio or video.
//      [in] dwInputSize - Stream size, in bytes.
//      [in] nOutFormat - The formats of output YUV data. For format details, refer
//           to the decoding formats for the output in Macro definition.
// Return:
//      Nonzero if successful; otherwise 0.
//      This function would return FALSE if the stream data is input too fast.
//      In this case, the stream data should be input once more.
// Remarks:
//      
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_DecodeOneFrame(long nChl, LPCVOID pInputFrame,
    DWORD dwInputSize, long nOutFormat, PHB_FRAME_INFO_EX pFrameInfo, long* pRemainderCount);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_ResetSourceBuffer.
// Description: 
//      Clear the data in the source buffer.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_ResetSourceBuffer(long nChl);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_SetSourceBufferCB.
// Description: 
//      Sets callback function.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] dwThreshold - Buffered frame threshold.
//      [in] pfnSourceBufCallback - Callback function pointer.
//           void CALLBACK pfnSourceBufCallback(long nChl, DWORD dwBufSize,
//              void* pUser, void* pResvered);
//              - [in] nChl - Channel number.
//              - [in] dwBufSize - The number of frames remains in the source buffer.
//              - [in] pUser - User context.
//              - [in] pResvered - Reserved.
//      [in] pUser - User context.
//      [in] pReserved - Reserved.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//	    This function would be called when the source buffer data is less than the
//      threshold value.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetSourceBufferCB(long nChl, DWORD dwThreshold,
    LPSOURCEBUFCALLBACK pfnSourceBufCallback, void* pUser, void* pReserved);


////////////////////////////////////////////////////////////////////////////////
// Function:
//      HB_PLAY_SetDecodeMode.
// Description:
//      Sets the type of hardware accelerated decoder.
// Parameters: 
//      [in] nChl - Channel number.
//      [in] nMode - The type of hardware accelerated decoder. For more details,
//           refer to enum type HB_HD_TYPE.
// Return:
//      Nonzero if successful; otherwise 0.
// Remarks:
//      Currently only HB_HD_NVIDIA_CUDA is supported.
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetDecodeMode(long nChl, HB_HD_TYPE nMode);


////////////////////////////////////////////////////////////////////////////////
// Function: 
//      HB_PLAY_GetDecodeMode.
// Description: 
//      Retrieves the type of hardware accelerated decoder.
// Parameters: 
//      [in] nChl - Channel number.
// Return:
//      The type of hardware accelerated decoder.
// Remarks:
//      For more details of the return value, refer to enum type HB_HD_TYPE.
////////////////////////////////////////////////////////////////////////////////
HB_HD_TYPE __stdcall HB_PLAY_GetDecodeMode(long nChl);


BOOL __stdcall HB_PLAY_SetStreamMode(long nChl, HB_PLAY_STREAM StreamMode);
HB_PLAY_STREAM __stdcall HB_PLAY_GetStreamMode(long nChl);


////////////////////////////////////////////////////////////////////////////////
//Obsolete Functions
////////////////////////////////////////////////////////////////////////////////
BOOL __stdcall HB_PLAY_SetStreamOpenMode(long nChl, DWORD nMode);
DWORD __stdcall HB_PLAY_GetStreamOpenMode(long nChl);
BOOL __stdcall HB_PLAY_ConvertToBMPFile(long nChl, char* pBuf, long nSize,
    long nWidth, long nHeight, long nType, char* sFileName);
BOOL __stdcall HB_PLAY_ConvertToBMPFileEx(long nChl, char* pBuf,
    long nSize, long nWidth, long nHeight, long nType,
    unsigned char* pBufDestination, int* len, int* pBMPHeadLen);
BOOL __stdcall HB_PLAY_SetParseCallBack(long nChl, LPSRCDATAPARSECBFUN SrcDataParseCBFun, 
    long nReserved1,long nReserved2);
BOOL __stdcall HB_PLAY_SetPicQuality(long nChl, BOOL bHighQuality);
BOOL __stdcall HB_PLAY_GetPicQuality(long nChl, BOOL* bHighQuality);
BOOL __stdcall HB_PLAY_SetOverlayMode(long nChl, BOOL bOverlayMode, COLORREF colorKey);
BOOL __stdcall HB_PLAY_SetSnapShotCallBack(long nChl, LPSNAPSHOTCBFUN SnapshotCBFun);
void __stdcall HB_PLAY_EnableIndexThread(BOOL bEnable);
BOOL __stdcall HB_PLAY_GetIndexInfo(long nChl, HB_FRAME_POS* pBuffer, DWORD* pSize);
BOOL __stdcall HB_PLAY_SetCPULimit(int nCpuUse);
BOOL __stdcall HB_PLAY_GetCPULimit(int* pCpuUse);
DWORD __stdcall HB_PLAY_GetColorKey(long nChl);
DWORD __stdcall HB_PLAY_GetLastError(long nChl);
DWORD __stdcall HB_PLAY_GetSourceBufferRemain(long nChl);
BOOL __stdcall HB_PLAY_RefreshPlay(long nChl);
BOOL __stdcall HB_PLAY_InputVideoData(long nChl,char* pBuf,DWORD nSize);
BOOL __stdcall HB_PLAY_InputAudioData(long nChl,char* pBuf,DWORD nSize);
DWORD __stdcall HB_PLAY_GetCurrentFrameTime(long nChl);
BOOL __stdcall HB_PLAY_SetDisplayCallBack(long nChl, LPDISPLAYCBFUN DisplayCBFun);
BOOL __stdcall HB_PLAY_InitDDraw(HWND hWnd);
BOOL __stdcall HB_PLAY_RealeseDDraw();


////////////////////////////////////////////////////////////////////////////////
//End HB_PLAY API
////////////////////////////////////////////////////////////////////////////////


#ifdef __cplusplus
}
#endif


#endif  // HBPLAYSDK_H