#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

//-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
//		������ȫ�ֱ�������
//-----------------------------------------------------------------------------------------------
Mat g_srcImage_Morphology_Filter, g_dstImage_Morphology1_Filter, g_dstImage_Morphology2_Filter, g_dstImage_Morphology3_Filter, g_dstImage_Morphology4_Filter, g_dstImage_Morphology5_Filter;
int g_nBoxFilterValue = 6;  //�����˲��ں�ֵ
int g_nMeanBlurValue = 10;  //��ֵ�˲��ں�ֵ
int g_nGaussianBlurValue = 6;  //��˹�˲��ں�ֵ
int g_nMedianBlurValue = 10;  //��ֵ�˲�����ֵ
int g_nBilateralFilterValue = 10;  //˫���˲�����ֵ
// ---------------------------------- - ��ȫ�ֺ����������֡�--------------------------------------
//		������ȫ�ֺ�������
//-----------------------------------------------------------------------------------------------
//�켣���ص�����
static void on_BoxFilter(int, void *);		//�����˲�
static void on_MeanBlur(int, void *);		//��ֵ���˲���
static void on_GaussianBlur(int, void *);			//��˹�˲���
static void on_MedianBlur(int, void *);			//��ֵ�˲���
static void on_BilateralFilter(int, void *);			//˫���˲���

//-----------------------------��on_BoxFilter( )������------------------------------------
//		�����������˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_BoxFilter(int, void *)
{
	//�����˲�����
	boxFilter(g_srcImage_Morphology_Filter, g_dstImage_Morphology1_Filter, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
	//��ʾ����
	imshow("��<1>�����˲���", g_dstImage_Morphology1_Filter);
}

//-----------------------------��on_MeanBlur( )������------------------------------------
//		��������ֵ�˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_MeanBlur(int, void *)
{
	blur(g_srcImage_Morphology_Filter, g_dstImage_Morphology2_Filter, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1), Point(-1, -1));
	imshow("��<2>��ֵ�˲���", g_dstImage_Morphology2_Filter);

}

//-----------------------------��on_GaussianBlur( )������------------------------------------
//		��������˹�˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_GaussianBlur(int, void *)
{
	GaussianBlur(g_srcImage_Morphology_Filter, g_dstImage_Morphology3_Filter, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
	imshow("��<3>��˹�˲���", g_dstImage_Morphology3_Filter);
}


//-----------------------------��on_MedianBlur( )������------------------------------------
//		��������ֵ�˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_MedianBlur(int, void *)
{
	medianBlur(g_srcImage_Morphology_Filter, g_dstImage_Morphology4_Filter, g_nMedianBlurValue * 2 + 1);
	imshow("��<4>��ֵ�˲���", g_dstImage_Morphology4_Filter);
}


//-----------------------------��on_BilateralFilter( )������------------------------------------
//		������˫���˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_BilateralFilter(int, void *)
{
	bilateralFilter(g_srcImage_Morphology_Filter, g_dstImage_Morphology5_Filter, g_nBilateralFilterValue, g_nBilateralFilterValue * 2, g_nBilateralFilterValue / 2);
	imshow("��<5>˫���˲���", g_dstImage_Morphology5_Filter);
}