//---------------------------------��ͷ�ļ��������ռ�������֡�----------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//------------------------------------------------------------------------------------------------
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;


//-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
//		������ȫ�ֱ�������
//-----------------------------------------------------------------------------------------------
//ԭͼ��ԭͼ�ĻҶȰ棬Ŀ��ͼ
Mat g_srcImage_EdgeDetection, g_srcGrayImage_EdgeDetection, g_dstImage_EdgeDetection;

//Canny��Ե�����ر���
Mat g_cannyDetectedEdges;
int g_cannyLowThreshold = 1;//TrackBarλ�ò���  

//Sobel��Ե�����ر���
Mat g_sobelGradient_X, g_sobelGradient_Y;
Mat g_sobelAbsGradient_X, g_sobelAbsGradient_Y;
int g_sobelKernelSize = 1;//TrackBarλ�ò���  

//Scharr�˲�����ر���
Mat g_scharrGradient_X, g_scharrGradient_Y;
Mat g_scharrAbsGradient_X, g_scharrAbsGradient_Y;


//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//		������ȫ�ֺ�������
//-----------------------------------------------------------------------------------------------
static void on_Canny(int, void*);//Canny��Ե��ⴰ�ڹ������Ļص�����
static void on_Sobel(int, void*);//Sobel��Ե��ⴰ�ڹ������Ļص�����
void Scharr();//��װ��Scharr��Ե�����ش���ĺ���

//-----------------------------------��on_Canny( )������----------------------------------
//		������Canny��Ե��ⴰ�ڹ������Ļص�����
//-----------------------------------------------------------------------------------------------
void on_Canny(int, void*)
{
	// ��ʹ�� 3x3�ں�������
	blur(g_srcGrayImage_EdgeDetection, g_cannyDetectedEdges, Size(3, 3));

	// �������ǵ�Canny����
	Canny(g_cannyDetectedEdges, g_cannyDetectedEdges, g_cannyLowThreshold, g_cannyLowThreshold * 3, 3);

	//�Ƚ�g_dstImage_EdgeDetection�ڵ�����Ԫ������Ϊ0 
	g_dstImage_EdgeDetection = Scalar::all(0);

	//ʹ��Canny��������ı�Եͼg_cannyDetectedEdges��Ϊ���룬����ԭͼg_srcImage_EdgeDetection����Ŀ��ͼg_dstImage_EdgeDetection��
	g_srcImage_EdgeDetection.copyTo(g_dstImage_EdgeDetection, g_cannyDetectedEdges);

	//��ʾЧ��ͼ
	imshow("��Ч��ͼ��Canny��Ե���", g_dstImage_EdgeDetection);
}



//-----------------------------------��on_Sobel( )������----------------------------------
//		������Sobel��Ե��ⴰ�ڹ������Ļص�����
//-----------------------------------------------------------------------------------------
void on_Sobel(int, void*)
{
	// �� X�����ݶ�
	Sobel(g_srcImage_EdgeDetection, g_sobelGradient_X, CV_16S, 1, 0, (2 * g_sobelKernelSize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_X, g_sobelAbsGradient_X);//�������ֵ���������ת����8λ

	// ��Y�����ݶ�
	Sobel(g_srcImage_EdgeDetection, g_sobelGradient_Y, CV_16S, 0, 1, (2 * g_sobelKernelSize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_Y, g_sobelAbsGradient_Y);//�������ֵ���������ת����8λ

	// �ϲ��ݶ�
	addWeighted(g_sobelAbsGradient_X, 0.5, g_sobelAbsGradient_Y, 0.5, 0, g_dstImage_EdgeDetection);

	//��ʾЧ��ͼ
	imshow("��Ч��ͼ��Sobel��Ե���", g_dstImage_EdgeDetection);

}


//-----------------------------------��Scharr( )������----------------------------------
//		��������װ��Scharr��Ե�����ش���ĺ���
//-----------------------------------------------------------------------------------------
void Scharr()
{
	// �� X�����ݶ�
	Scharr(g_srcImage_EdgeDetection, g_scharrGradient_X, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(g_scharrGradient_X, g_scharrAbsGradient_X);//�������ֵ���������ת����8λ

	// ��Y�����ݶ�
	Scharr(g_srcImage_EdgeDetection, g_scharrGradient_Y, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(g_scharrGradient_Y, g_scharrAbsGradient_Y);//�������ֵ���������ת����8λ

	// �ϲ��ݶ�
	addWeighted(g_scharrAbsGradient_X, 0.5, g_scharrAbsGradient_Y, 0.5, 0, g_dstImage_EdgeDetection);

	//��ʾЧ��ͼ
	imshow("��Ч��ͼ��Scharr�˲���", g_dstImage_EdgeDetection);
}