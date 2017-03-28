
#include <iostream> 
#include "core/core.hpp"  
#include "highgui/highgui.hpp"  
#include "imgproc/imgproc.hpp" 

using namespace std;
using namespace cv;

#define IN_RANG_FILTER

void in_rang_filter();
void Allocate_imgs();


Mat img, test, imgHsv, imgResult;
int mR_val = 19, mG_val = 13, mB_val = 18, MAR_val = 154, MAG_val = 256, MAB_val = 79;//default green .ctrl BLUE to find color

static void set_RGB(int pos, void*)
{
#ifdef IN_RANG_FILTER
	in_rang_filter();
#endif
}
int main()
{
	CvSeq* find_contour = NULL;
	bool isStop = false;
	img = cvLoadImage("images/test.png");
	if (img.data == NULL)
	{
		printf("capture device not found!!");
		return -1; 
	}


	Allocate_imgs();

	// creat windows
	namedWindow("Capture", CV_WINDOW_AUTOSIZE);
	namedWindow("Result", CV_WINDOW_AUTOSIZE);


	//To in_rang_filter() MIN , MAX RGB value set
	createTrackbar("minR", "Result", &mR_val, 256, set_RGB);
	createTrackbar("minG", "Result", &mG_val, 256, set_RGB);
	createTrackbar("minB", "Result", &mB_val, 256, set_RGB);

	createTrackbar("maxR", "Result", &MAR_val, 256, set_RGB);
	createTrackbar("maxG", "Result", &MAG_val, 256, set_RGB);
	createTrackbar("maxB", "Result", &MAB_val, 256, set_RGB);
	//


	cvtColor(img, imgHsv, CV_BGR2HSV);//convert the color space
	in_rang_filter();


	imshow("Capture", img);
	//imshow("Result", test);
	cvWaitKey(0);
	cvDestroyAllWindows();

}

void in_rang_filter()
{
	Mat test = cvCreateImage(img.size(), IPL_DEPTH_8U, 3);
	CvScalar min_color = CV_RGB(mR_val, mG_val, mB_val);
	CvScalar max_color = CV_RGB(MAR_val, MAG_val, MAB_val);
	cvInRangeS(&(CvMat)imgHsv, min_color, max_color, &(CvMat)imgResult);//search for the color in image

	cvtColor(imgResult, test, CV_GRAY2RGB);
	imshow("Result", test);
}

void Allocate_imgs()
{
	const int w = img.cols;
	const int h = img.rows;
	imgResult = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 1);
	imgHsv = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 3);
}


// IplImage imageTemporaire = cvlib.cvCreateImage(cvlib.cvGetSize(_image.IplImage), 8, 3);
// cvlib.cvCvtColor(_image.IplImage, imageTemporaire, cvlib.CV_BGR2HSV);
// IplImage imageH = cvlib.cvCreateImage(cvlib.cvGetSize(imageTemporaire), 8, 1);
// 
// cvlib.cvSplit(imageTemporaire, imageH, null, null, null);
// IplImage imageVerte = cvlib.cvCreateImage(cvlib.cvGetSize(_image.IplImage), 8, 1);
// 
// On sort ce qui est dans le range
// CvScalar min_color = cvlib.CV_RGB(0, 0, Hmin);
// CvScalar max_color = cvlib.CV_RGB(0, 0, Hmax);
// 
// cvlib.cvInRangeS(imageH, min_color, max_color, imageVerte);
// cvlib.cvShowImage("Vert", imageVerte);
// cvlib.cvReleaseImage(imageTemporaire);
// cvlib.cvReleaseImage(imageVerte);