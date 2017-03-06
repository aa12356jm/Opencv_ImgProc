//---------------------------------【头文件、命名空间包含部分】----------------------------
//		描述：包含程序所使用的头文件和命名空间
//------------------------------------------------------------------------------------------------
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;


//-----------------------------------【全局变量声明部分】--------------------------------------
//		描述：全局变量声明
//-----------------------------------------------------------------------------------------------
//原图，原图的灰度版，目标图
Mat g_srcImage_EdgeDetection, g_srcGrayImage_EdgeDetection, g_dstImage_EdgeDetection;

//Canny边缘检测相关变量
Mat g_cannyDetectedEdges;
int g_cannyLowThreshold = 1;//TrackBar位置参数  

//Sobel边缘检测相关变量
Mat g_sobelGradient_X, g_sobelGradient_Y;
Mat g_sobelAbsGradient_X, g_sobelAbsGradient_Y;
int g_sobelKernelSize = 1;//TrackBar位置参数  

//Scharr滤波器相关变量
Mat g_scharrGradient_X, g_scharrGradient_Y;
Mat g_scharrAbsGradient_X, g_scharrAbsGradient_Y;


//-----------------------------------【全局函数声明部分】--------------------------------------
//		描述：全局函数声明
//-----------------------------------------------------------------------------------------------
static void on_Canny(int, void*);//Canny边缘检测窗口滚动条的回调函数
static void on_Sobel(int, void*);//Sobel边缘检测窗口滚动条的回调函数
void Scharr();//封装了Scharr边缘检测相关代码的函数

//-----------------------------------【on_Canny( )函数】----------------------------------
//		描述：Canny边缘检测窗口滚动条的回调函数
//-----------------------------------------------------------------------------------------------
void on_Canny(int, void*)
{
	// 先使用 3x3内核来降噪
	blur(g_srcGrayImage_EdgeDetection, g_cannyDetectedEdges, Size(3, 3));

	// 运行我们的Canny算子
	Canny(g_cannyDetectedEdges, g_cannyDetectedEdges, g_cannyLowThreshold, g_cannyLowThreshold * 3, 3);

	//先将g_dstImage_EdgeDetection内的所有元素设置为0 
	g_dstImage_EdgeDetection = Scalar::all(0);

	//使用Canny算子输出的边缘图g_cannyDetectedEdges作为掩码，来将原图g_srcImage_EdgeDetection拷到目标图g_dstImage_EdgeDetection中
	g_srcImage_EdgeDetection.copyTo(g_dstImage_EdgeDetection, g_cannyDetectedEdges);

	//显示效果图
	imshow("【效果图】Canny边缘检测", g_dstImage_EdgeDetection);
}



//-----------------------------------【on_Sobel( )函数】----------------------------------
//		描述：Sobel边缘检测窗口滚动条的回调函数
//-----------------------------------------------------------------------------------------
void on_Sobel(int, void*)
{
	// 求 X方向梯度
	Sobel(g_srcImage_EdgeDetection, g_sobelGradient_X, CV_16S, 1, 0, (2 * g_sobelKernelSize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_X, g_sobelAbsGradient_X);//计算绝对值，并将结果转换成8位

	// 求Y方向梯度
	Sobel(g_srcImage_EdgeDetection, g_sobelGradient_Y, CV_16S, 0, 1, (2 * g_sobelKernelSize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_Y, g_sobelAbsGradient_Y);//计算绝对值，并将结果转换成8位

	// 合并梯度
	addWeighted(g_sobelAbsGradient_X, 0.5, g_sobelAbsGradient_Y, 0.5, 0, g_dstImage_EdgeDetection);

	//显示效果图
	imshow("【效果图】Sobel边缘检测", g_dstImage_EdgeDetection);

}


//-----------------------------------【Scharr( )函数】----------------------------------
//		描述：封装了Scharr边缘检测相关代码的函数
//-----------------------------------------------------------------------------------------
void Scharr()
{
	// 求 X方向梯度
	Scharr(g_srcImage_EdgeDetection, g_scharrGradient_X, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(g_scharrGradient_X, g_scharrAbsGradient_X);//计算绝对值，并将结果转换成8位

	// 求Y方向梯度
	Scharr(g_srcImage_EdgeDetection, g_scharrGradient_Y, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(g_scharrGradient_Y, g_scharrAbsGradient_Y);//计算绝对值，并将结果转换成8位

	// 合并梯度
	addWeighted(g_scharrAbsGradient_X, 0.5, g_scharrAbsGradient_Y, 0.5, 0, g_dstImage_EdgeDetection);

	//显示效果图
	imshow("【效果图】Scharr滤波器", g_dstImage_EdgeDetection);
}