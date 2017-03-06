#include "ImgProc_Opencv.h"
#include "filter.h"
#include "Morphology.h"
#include "edgeDetection.h"
#include "faceDetect.h"

ImgProc_Opencv::ImgProc_Opencv(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::ImgProc_OpencvClass)
{
	ui->setupUi(this);

	connect(ui->pushButton_OpenCamera, SIGNAL(clicked()), this, SLOT(on_pushButton_OpenCamera_cliked()));
	connect(ui->pushButton_SnapShot, SIGNAL(clicked()), this, SLOT(on_pushButton_SnapShot_cliked()));
	connect(ui->radioButton_ToGrayImg, SIGNAL(pressed()), this, SLOT(on_radioButton_ToGrayImg_cliked()));
	connect(ui->radioButton_ToBlackWhiteImg, SIGNAL(pressed()), this, SLOT(on_radioButton_ToBlackWhiteImg_cliked()));
	//各种滤波操作
	connect(ui->radioButton_Filter, SIGNAL(pressed()), this, SLOT(on_radioButton_Filter_cliked()));
	//各种形态学操作
	connect(ui->radioButton_Morphology, SIGNAL(pressed()), this, SLOT(on_radioButton_Morphology_cliked()));
	connect(ui->radioButton_EdgeDetection, SIGNAL(pressed()), this, SLOT(on_radioButton_EdgeDetection_cliked()));

}
ImgProc_Opencv::~ImgProc_Opencv()
{
	delete ui;
}

void ImgProc_Opencv::on_pushButton_OpenCamera_cliked()
{
	if (!capture.isOpened())
	{
		//-- 1. 加载级联（cascades）
		if (!face_cascade.load(face_cascade_name))
		{ 
			m_VecStrErrorInfo.append(QString("--(!)Error loading\n"));
			return ; 
		};
		if (!eyes_cascade.load(eyes_cascade_name))
		{ 
			m_VecStrErrorInfo.append(QString("--(!)Error loading\n"));
			return; 
		};

		//开始启动相机
		if (!capture.open(0))
		{
			m_VecStrErrorInfo.append(QString("相机打开错误，请检查相机是否正确连接"));
			return;
		}
		//启动相机之后休眠1s，因为启动过程比较慢
		Sleep(1000);
		id1 = startTimer(50);//启动定时器，每xx毫秒会触发一次timerEvent函数
		update();
	}
	else
	{
		return;
	}
}
void ImgProc_Opencv::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == id1)
	{
		showImg();//将图像显示在窗口中
	}
}
void ImgProc_Opencv::on_pushButton_SnapShot_cliked()
{
	if (capture.isOpened())
	{
		Mat frame;
		capture >> frame;//读取当前帧	
		QImage image = MatToQImage(frame);
		QPixmap pixmap = QPixmap::fromImage(image);
		ui->label_ProcImg->setPixmap(pixmap);
	}
	else
	{
		on_pushButton_OpenCamera_cliked();

		Mat frame;
		capture >> frame;//读取当前帧	
		QImage image = MatToQImage(frame);
		QPixmap pixmap = QPixmap::fromImage(image);
		ui->label_ProcImg->setPixmap(pixmap);
	}
}

void ImgProc_Opencv::showImg()
{
	//Mat edges;
	Mat frame;
	capture >> frame;//读取当前帧	
	//cvtColor(frame, edges, CV_BGR2GRAY);
	//blur(edges, edges, Size(7, 7));
	//Canny(edges, edges, 0, 30, 3);
	if (!frame.empty())
	{
		detectAndDisplay(frame);
	}
	QImage image = MatToQImage(frame);
	QPixmap pixmap;
	//ui->label_ShowImg->move(0,0);
	//ui.label_ShowImg->resize(752, 480);
	pixmap = QPixmap::fromImage(image);
	//pixmap = pixmap.scaled(752, 480, Qt::KeepAspectRatio);

	ui->label_ShowImg->setPixmap(pixmap);
	update();
}

QImage ImgProc_Opencv::MatToQImage(const cv::Mat& mat)
{
	// 8-bits unsigned, NO. OF CHANNELS = 1    
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)    
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat    
		uchar *pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3    
	else if (mat.type() == CV_8UC3)
	{
		// Copy input Mat    
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat    
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		//qDebug() << "CV_8UC4";
		// Copy input Mat    
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat    
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		//qDebug() << "ERROR: Mat could not be converted to QImage.";
		return QImage();
	}
}

void ImgProc_Opencv::on_radioButton_ToGrayImg_cliked()
{
	Mat edges;
	Mat frame;
	capture >> frame;//读取当前帧	
	cvtColor(frame, edges, CV_BGR2GRAY);
	QImage image = MatToQImage(edges);
	QPixmap pixmap = QPixmap::fromImage(image);
	ui->label_ProcImg->setPixmap(pixmap);
}

void ImgProc_Opencv::on_radioButton_ToBlackWhiteImg_cliked()
{
	Mat edges;
	Mat frame;
	capture >> frame;//读取当前帧	
	cvtColor(frame, edges, CV_BGR2GRAY);
	threshold(edges, edges, 0.00001, 255, THRESH_OTSU|| THRESH_BINARY);
	QImage image = MatToQImage(edges);
	QPixmap pixmap = QPixmap::fromImage(image);
	ui->label_ProcImg->setPixmap(pixmap);
}

void ImgProc_Opencv::on_radioButton_Filter_cliked()
{
	capture >> g_srcImage_Morphology_Filter;//读取当前帧
	//g_srcImage_Morphology = imread("1.jpg", 1);
	if (!g_srcImage_Morphology_Filter.data)
	{
		m_VecStrErrorInfo.append(QString("读取srcImage错误~！ \n")); 
		return;
	}
	//克隆原图到四个Mat类型中
	g_dstImage_Morphology1_Filter = g_srcImage_Morphology_Filter.clone();
	g_dstImage_Morphology2_Filter = g_srcImage_Morphology_Filter.clone();
	g_dstImage_Morphology3_Filter = g_srcImage_Morphology_Filter.clone();
	g_dstImage_Morphology4_Filter = g_srcImage_Morphology_Filter.clone();
	g_dstImage_Morphology5_Filter = g_srcImage_Morphology_Filter.clone();

	//显示原图
	namedWindow("【<0>原图窗口】", 1);
	imshow("【<0>原图窗口】", g_srcImage_Morphology_Filter);

	//=================【<1>方框滤波】=========================
	namedWindow("【<1>方框滤波】", 1);
	createTrackbar("内核值：", "【<1>方框滤波】", &g_nBoxFilterValue, 50, on_BoxFilter);
	on_MeanBlur(g_nBoxFilterValue, 0);
	imshow("【<1>方框滤波】", g_dstImage_Morphology1_Filter);
	//=====================================================

	//=================【<2>均值滤波】==========================
	namedWindow("【<2>均值滤波】", 1);
	createTrackbar("内核值：", "【<2>均值滤波】", &g_nMeanBlurValue, 50, on_MeanBlur);
	on_MeanBlur(g_nMeanBlurValue, 0);
	//======================================================

	//=================【<3>高斯滤波】===========================
	namedWindow("【<3>高斯滤波】", 1);
	createTrackbar("内核值：", "【<3>高斯滤波】", &g_nGaussianBlurValue, 50, on_GaussianBlur);
	on_GaussianBlur(g_nGaussianBlurValue, 0);
	//=======================================================

	//=================【<4>中值滤波】===========================
	namedWindow("【<4>中值滤波】", 1);
	createTrackbar("参数值：", "【<4>中值滤波】", &g_nMedianBlurValue, 50, on_MedianBlur);
	on_MedianBlur(g_nMedianBlurValue, 0);
	//=======================================================

	//=================【<5>双边滤波】===========================
	namedWindow("【<5>双边滤波】", 1);
	createTrackbar("参数值：", "【<5>双边滤波】", &g_nBilateralFilterValue, 50, on_BilateralFilter);
	on_BilateralFilter(g_nBilateralFilterValue, 0);
}

void ImgProc_Opencv::on_radioButton_Morphology_cliked()
{
	//载入原图
	//g_srcImage_Morphology = imread("1.jpg");
	capture >> g_srcImage_Morphology;//读取当前帧
	if (!g_srcImage_Morphology.data) 
	{ 
		m_VecStrErrorInfo.append(QString("读取srcImage错误~！ \n")); 
		return ; 
	}

	//显示原始图
	namedWindow("【原始图】");
	imshow("【原始图】", g_srcImage_Morphology);

	//创建三个窗口
	namedWindow("【开运算/闭运算】", 1);
	namedWindow("【腐蚀/膨胀】", 1);
	namedWindow("【顶帽/黑帽】", 1);

	//参数赋值
	g_nOpenCloseNum = 9;
	g_nErodeDilateNum = 9;
	g_nTopBlackHatNum = 2;

	//分别为三个窗口创建滚动条
	createTrackbar("迭代值", "【开运算/闭运算】", &g_nOpenCloseNum, g_nMaxIterationNum * 2 + 1, on_OpenClose);
	createTrackbar("迭代值", "【腐蚀/膨胀】", &g_nErodeDilateNum, g_nMaxIterationNum * 2 + 1, on_ErodeDilate);
	createTrackbar("迭代值", "【顶帽/黑帽】", &g_nTopBlackHatNum, g_nMaxIterationNum * 2 + 1, on_TopBlackHat);

	//轮询获取按键信息
	while (1)
	{
		int c;

		//执行回调函数
		on_OpenClose(g_nOpenCloseNum, 0);
		on_ErodeDilate(g_nErodeDilateNum, 0);
		on_TopBlackHat(g_nTopBlackHatNum, 0);

		//获取按键
		c = waitKey(0);

		//按下键盘按键Q或者ESC，程序退出
		if ((char)c == 'q' || (char)c == 27)
			break;
		//按下键盘按键1，使用椭圆(Elliptic)结构元素结构元素MORPH_ELLIPSE
		if ((char)c == 49)//键盘按键1的ASII码为49
			g_nElementShape = MORPH_ELLIPSE;
		//按下键盘按键2，使用矩形(Rectangle)结构元素MORPH_RECT
		else if ((char)c == 50)//键盘按键2的ASII码为50
			g_nElementShape = MORPH_RECT;
		//按下键盘按键3，使用十字形(Cross-shaped)结构元素MORPH_CROSS
		else if ((char)c == 51)//键盘按键3的ASII码为51
			g_nElementShape = MORPH_CROSS;
		//按下键盘按键space，在矩形、椭圆、十字形结构元素中循环
		else if ((char)c == ' ')
			g_nElementShape = (g_nElementShape + 1) % 3;
	}
}

void ImgProc_Opencv::on_radioButton_EdgeDetection_cliked()
{
	capture >> g_srcImage_EdgeDetection;//读取当前帧
	if (!g_srcImage_EdgeDetection.data) 
	{
		m_VecStrErrorInfo.append(QString("读取srcImage错误~！ \n")); 
		return;
	}

	//显示原始图
	namedWindow("【原始图】");
	imshow("【原始图】", g_srcImage_EdgeDetection);

	// 创建与src同类型和大小的矩阵(dst)
	g_dstImage_EdgeDetection.create(g_srcImage_EdgeDetection.size(), g_srcImage_EdgeDetection.type());

	// 将原图像转换为灰度图像
	cvtColor(g_srcImage_EdgeDetection, g_srcGrayImage_EdgeDetection, CV_BGR2GRAY);

	// 创建显示窗口
	namedWindow("【效果图】Canny边缘检测", CV_WINDOW_AUTOSIZE);
	namedWindow("【效果图】Sobel边缘检测", CV_WINDOW_AUTOSIZE);

	// 创建trackbar
	createTrackbar("参数值：", "【效果图】Canny边缘检测", &g_cannyLowThreshold, 120, on_Canny);
	createTrackbar("参数值：", "【效果图】Sobel边缘检测", &g_sobelKernelSize, 3, on_Sobel);

	// 调用回调函数
	on_Canny(0, 0);
	on_Sobel(0, 0);

	//调用封装了Scharr边缘检测代码的函数
	Scharr();
}

