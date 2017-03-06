//---------------------------------��ͷ�ļ��������ռ�������֡�----------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;


//-----------------------------------��ȫ�ֱ����������֡�-----------------------------------
//		������ȫ�ֱ�������
//-----------------------------------------------------------------------------------------------
Mat g_srcImage_Morphology, g_dstImage_Morphology;//ԭʼͼ��Ч��ͼ
int g_nElementShape = MORPH_RECT;//Ԫ�ؽṹ����״

//�������յ�TrackBarλ�ò���
int g_nMaxIterationNum = 10;
int g_nOpenCloseNum = 0;
int g_nErodeDilateNum = 0;
int g_nTopBlackHatNum = 0;

//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//		������ȫ�ֺ�������
//-----------------------------------------------------------------------------------------------
static void on_OpenClose(int, void*);//�ص�����
static void on_ErodeDilate(int, void*);//�ص�����
static void on_TopBlackHat(int, void*);//�ص�����


//-----------------------------------��on_OpenClose( )������----------------------------------
//		��������������/�����㡿���ڵĻص�����
//-----------------------------------------------------------------------------------------------
static void on_OpenClose(int, void*)
{
	//ƫ�����Ķ���
	int offset = g_nOpenCloseNum - g_nMaxIterationNum;//ƫ����
	int Absolute_offset = offset > 0 ? offset : -offset;//ƫ��������ֵ
	//�Զ����
	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1), Point(Absolute_offset, Absolute_offset));
	//���в���
	if (offset < 0)
		morphologyEx(g_srcImage_Morphology, g_dstImage_Morphology, CV_MOP_OPEN, element);
	else
		morphologyEx(g_srcImage_Morphology, g_dstImage_Morphology, CV_MOP_CLOSE, element);
	//��ʾͼ��
	imshow("��������/�����㡿", g_dstImage_Morphology);
}


//-----------------------------------��on_ErodeDilate( )������----------------------------------
//		����������ʴ/���͡����ڵĻص�����
//-----------------------------------------------------------------------------------------------
static void on_ErodeDilate(int, void*)
{
	//ƫ�����Ķ���
	int offset = g_nErodeDilateNum - g_nMaxIterationNum;	//ƫ����
	int Absolute_offset = offset > 0 ? offset : -offset;//ƫ��������ֵ
	//�Զ����
	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1), Point(Absolute_offset, Absolute_offset));
	//���в���
	if (offset < 0)
		erode(g_srcImage_Morphology, g_dstImage_Morphology, element);
	else
		dilate(g_srcImage_Morphology, g_dstImage_Morphology, element);
	//��ʾͼ��
	imshow("����ʴ/���͡�", g_dstImage_Morphology);
}


//-----------------------------------��on_TopBlackHat( )������--------------------------------
//		����������ñ����/��ñ���㡿���ڵĻص�����
//----------------------------------------------------------------------------------------------
static void on_TopBlackHat(int, void*)
{
	//ƫ�����Ķ���
	int offset = g_nTopBlackHatNum - g_nMaxIterationNum;//ƫ����
	int Absolute_offset = offset > 0 ? offset : -offset;//ƫ��������ֵ
	//�Զ����
	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1), Point(Absolute_offset, Absolute_offset));
	//���в���
	if (offset < 0)
		morphologyEx(g_srcImage_Morphology, g_dstImage_Morphology, MORPH_TOPHAT, element);
	else
		morphologyEx(g_srcImage_Morphology, g_dstImage_Morphology, MORPH_BLACKHAT, element);
	//��ʾͼ��
	imshow("����ñ/��ñ��", g_dstImage_Morphology);
}