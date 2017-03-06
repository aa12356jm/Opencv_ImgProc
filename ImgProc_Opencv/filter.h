#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

//-----------------------------------【全局变量声明部分】--------------------------------------
//		描述：全局变量声明
//-----------------------------------------------------------------------------------------------
Mat g_srcImage_Morphology_Filter, g_dstImage_Morphology1_Filter, g_dstImage_Morphology2_Filter, g_dstImage_Morphology3_Filter, g_dstImage_Morphology4_Filter, g_dstImage_Morphology5_Filter;
int g_nBoxFilterValue = 6;  //方框滤波内核值
int g_nMeanBlurValue = 10;  //均值滤波内核值
int g_nGaussianBlurValue = 6;  //高斯滤波内核值
int g_nMedianBlurValue = 10;  //中值滤波参数值
int g_nBilateralFilterValue = 10;  //双边滤波参数值
// ---------------------------------- - 【全局函数声明部分】--------------------------------------
//		描述：全局函数声明
//-----------------------------------------------------------------------------------------------
//轨迹条回调函数
static void on_BoxFilter(int, void *);		//方框滤波
static void on_MeanBlur(int, void *);		//均值块滤波器
static void on_GaussianBlur(int, void *);			//高斯滤波器
static void on_MedianBlur(int, void *);			//中值滤波器
static void on_BilateralFilter(int, void *);			//双边滤波器

//-----------------------------【on_BoxFilter( )函数】------------------------------------
//		描述：方框滤波操作的回调函数
//-----------------------------------------------------------------------------------------------
static void on_BoxFilter(int, void *)
{
	//方框滤波操作
	boxFilter(g_srcImage_Morphology_Filter, g_dstImage_Morphology1_Filter, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
	//显示窗口
	imshow("【<1>方框滤波】", g_dstImage_Morphology1_Filter);
}

//-----------------------------【on_MeanBlur( )函数】------------------------------------
//		描述：均值滤波操作的回调函数
//-----------------------------------------------------------------------------------------------
static void on_MeanBlur(int, void *)
{
	blur(g_srcImage_Morphology_Filter, g_dstImage_Morphology2_Filter, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1), Point(-1, -1));
	imshow("【<2>均值滤波】", g_dstImage_Morphology2_Filter);

}

//-----------------------------【on_GaussianBlur( )函数】------------------------------------
//		描述：高斯滤波操作的回调函数
//-----------------------------------------------------------------------------------------------
static void on_GaussianBlur(int, void *)
{
	GaussianBlur(g_srcImage_Morphology_Filter, g_dstImage_Morphology3_Filter, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
	imshow("【<3>高斯滤波】", g_dstImage_Morphology3_Filter);
}


//-----------------------------【on_MedianBlur( )函数】------------------------------------
//		描述：中值滤波操作的回调函数
//-----------------------------------------------------------------------------------------------
static void on_MedianBlur(int, void *)
{
	medianBlur(g_srcImage_Morphology_Filter, g_dstImage_Morphology4_Filter, g_nMedianBlurValue * 2 + 1);
	imshow("【<4>中值滤波】", g_dstImage_Morphology4_Filter);
}


//-----------------------------【on_BilateralFilter( )函数】------------------------------------
//		描述：双边滤波操作的回调函数
//-----------------------------------------------------------------------------------------------
static void on_BilateralFilter(int, void *)
{
	bilateralFilter(g_srcImage_Morphology_Filter, g_dstImage_Morphology5_Filter, g_nBilateralFilterValue, g_nBilateralFilterValue * 2, g_nBilateralFilterValue / 2);
	imshow("【<5>双边滤波】", g_dstImage_Morphology5_Filter);
}