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
	//�����˲�����
	connect(ui->radioButton_Filter, SIGNAL(pressed()), this, SLOT(on_radioButton_Filter_cliked()));
	//������̬ѧ����
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
		//-- 1. ���ؼ�����cascades��
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

		//��ʼ�������
		if (!capture.open(0))
		{
			m_VecStrErrorInfo.append(QString("����򿪴�����������Ƿ���ȷ����"));
			return;
		}
		//�������֮������1s����Ϊ�������̱Ƚ���
		Sleep(1000);
		id1 = startTimer(50);//������ʱ����ÿxx����ᴥ��һ��timerEvent����
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
		showImg();//��ͼ����ʾ�ڴ�����
	}
}
void ImgProc_Opencv::on_pushButton_SnapShot_cliked()
{
	if (capture.isOpened())
	{
		Mat frame;
		capture >> frame;//��ȡ��ǰ֡	
		QImage image = MatToQImage(frame);
		QPixmap pixmap = QPixmap::fromImage(image);
		ui->label_ProcImg->setPixmap(pixmap);
	}
	else
	{
		on_pushButton_OpenCamera_cliked();

		Mat frame;
		capture >> frame;//��ȡ��ǰ֡	
		QImage image = MatToQImage(frame);
		QPixmap pixmap = QPixmap::fromImage(image);
		ui->label_ProcImg->setPixmap(pixmap);
	}
}

void ImgProc_Opencv::showImg()
{
	//Mat edges;
	Mat frame;
	capture >> frame;//��ȡ��ǰ֡	
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
	capture >> frame;//��ȡ��ǰ֡	
	cvtColor(frame, edges, CV_BGR2GRAY);
	QImage image = MatToQImage(edges);
	QPixmap pixmap = QPixmap::fromImage(image);
	ui->label_ProcImg->setPixmap(pixmap);
}

void ImgProc_Opencv::on_radioButton_ToBlackWhiteImg_cliked()
{
	Mat edges;
	Mat frame;
	capture >> frame;//��ȡ��ǰ֡	
	cvtColor(frame, edges, CV_BGR2GRAY);
	threshold(edges, edges, 0.00001, 255, THRESH_OTSU|| THRESH_BINARY);
	QImage image = MatToQImage(edges);
	QPixmap pixmap = QPixmap::fromImage(image);
	ui->label_ProcImg->setPixmap(pixmap);
}

void ImgProc_Opencv::on_radioButton_Filter_cliked()
{
	capture >> g_srcImage_Morphology_Filter;//��ȡ��ǰ֡
	//g_srcImage_Morphology = imread("1.jpg", 1);
	if (!g_srcImage_Morphology_Filter.data)
	{
		m_VecStrErrorInfo.append(QString("��ȡsrcImage����~�� \n")); 
		return;
	}
	//��¡ԭͼ���ĸ�Mat������
	g_dstImage_Morphology1_Filter = g_srcImage_Morphology_Filter.clone();
	g_dstImage_Morphology2_Filter = g_srcImage_Morphology_Filter.clone();
	g_dstImage_Morphology3_Filter = g_srcImage_Morphology_Filter.clone();
	g_dstImage_Morphology4_Filter = g_srcImage_Morphology_Filter.clone();
	g_dstImage_Morphology5_Filter = g_srcImage_Morphology_Filter.clone();

	//��ʾԭͼ
	namedWindow("��<0>ԭͼ���ڡ�", 1);
	imshow("��<0>ԭͼ���ڡ�", g_srcImage_Morphology_Filter);

	//=================��<1>�����˲���=========================
	namedWindow("��<1>�����˲���", 1);
	createTrackbar("�ں�ֵ��", "��<1>�����˲���", &g_nBoxFilterValue, 50, on_BoxFilter);
	on_MeanBlur(g_nBoxFilterValue, 0);
	imshow("��<1>�����˲���", g_dstImage_Morphology1_Filter);
	//=====================================================

	//=================��<2>��ֵ�˲���==========================
	namedWindow("��<2>��ֵ�˲���", 1);
	createTrackbar("�ں�ֵ��", "��<2>��ֵ�˲���", &g_nMeanBlurValue, 50, on_MeanBlur);
	on_MeanBlur(g_nMeanBlurValue, 0);
	//======================================================

	//=================��<3>��˹�˲���===========================
	namedWindow("��<3>��˹�˲���", 1);
	createTrackbar("�ں�ֵ��", "��<3>��˹�˲���", &g_nGaussianBlurValue, 50, on_GaussianBlur);
	on_GaussianBlur(g_nGaussianBlurValue, 0);
	//=======================================================

	//=================��<4>��ֵ�˲���===========================
	namedWindow("��<4>��ֵ�˲���", 1);
	createTrackbar("����ֵ��", "��<4>��ֵ�˲���", &g_nMedianBlurValue, 50, on_MedianBlur);
	on_MedianBlur(g_nMedianBlurValue, 0);
	//=======================================================

	//=================��<5>˫���˲���===========================
	namedWindow("��<5>˫���˲���", 1);
	createTrackbar("����ֵ��", "��<5>˫���˲���", &g_nBilateralFilterValue, 50, on_BilateralFilter);
	on_BilateralFilter(g_nBilateralFilterValue, 0);
}

void ImgProc_Opencv::on_radioButton_Morphology_cliked()
{
	//����ԭͼ
	//g_srcImage_Morphology = imread("1.jpg");
	capture >> g_srcImage_Morphology;//��ȡ��ǰ֡
	if (!g_srcImage_Morphology.data) 
	{ 
		m_VecStrErrorInfo.append(QString("��ȡsrcImage����~�� \n")); 
		return ; 
	}

	//��ʾԭʼͼ
	namedWindow("��ԭʼͼ��");
	imshow("��ԭʼͼ��", g_srcImage_Morphology);

	//������������
	namedWindow("��������/�����㡿", 1);
	namedWindow("����ʴ/���͡�", 1);
	namedWindow("����ñ/��ñ��", 1);

	//������ֵ
	g_nOpenCloseNum = 9;
	g_nErodeDilateNum = 9;
	g_nTopBlackHatNum = 2;

	//�ֱ�Ϊ�������ڴ���������
	createTrackbar("����ֵ", "��������/�����㡿", &g_nOpenCloseNum, g_nMaxIterationNum * 2 + 1, on_OpenClose);
	createTrackbar("����ֵ", "����ʴ/���͡�", &g_nErodeDilateNum, g_nMaxIterationNum * 2 + 1, on_ErodeDilate);
	createTrackbar("����ֵ", "����ñ/��ñ��", &g_nTopBlackHatNum, g_nMaxIterationNum * 2 + 1, on_TopBlackHat);

	//��ѯ��ȡ������Ϣ
	while (1)
	{
		int c;

		//ִ�лص�����
		on_OpenClose(g_nOpenCloseNum, 0);
		on_ErodeDilate(g_nErodeDilateNum, 0);
		on_TopBlackHat(g_nTopBlackHatNum, 0);

		//��ȡ����
		c = waitKey(0);

		//���¼��̰���Q����ESC�������˳�
		if ((char)c == 'q' || (char)c == 27)
			break;
		//���¼��̰���1��ʹ����Բ(Elliptic)�ṹԪ�ؽṹԪ��MORPH_ELLIPSE
		if ((char)c == 49)//���̰���1��ASII��Ϊ49
			g_nElementShape = MORPH_ELLIPSE;
		//���¼��̰���2��ʹ�þ���(Rectangle)�ṹԪ��MORPH_RECT
		else if ((char)c == 50)//���̰���2��ASII��Ϊ50
			g_nElementShape = MORPH_RECT;
		//���¼��̰���3��ʹ��ʮ����(Cross-shaped)�ṹԪ��MORPH_CROSS
		else if ((char)c == 51)//���̰���3��ASII��Ϊ51
			g_nElementShape = MORPH_CROSS;
		//���¼��̰���space���ھ��Ρ���Բ��ʮ���νṹԪ����ѭ��
		else if ((char)c == ' ')
			g_nElementShape = (g_nElementShape + 1) % 3;
	}
}

void ImgProc_Opencv::on_radioButton_EdgeDetection_cliked()
{
	capture >> g_srcImage_EdgeDetection;//��ȡ��ǰ֡
	if (!g_srcImage_EdgeDetection.data) 
	{
		m_VecStrErrorInfo.append(QString("��ȡsrcImage����~�� \n")); 
		return;
	}

	//��ʾԭʼͼ
	namedWindow("��ԭʼͼ��");
	imshow("��ԭʼͼ��", g_srcImage_EdgeDetection);

	// ������srcͬ���ͺʹ�С�ľ���(dst)
	g_dstImage_EdgeDetection.create(g_srcImage_EdgeDetection.size(), g_srcImage_EdgeDetection.type());

	// ��ԭͼ��ת��Ϊ�Ҷ�ͼ��
	cvtColor(g_srcImage_EdgeDetection, g_srcGrayImage_EdgeDetection, CV_BGR2GRAY);

	// ������ʾ����
	namedWindow("��Ч��ͼ��Canny��Ե���", CV_WINDOW_AUTOSIZE);
	namedWindow("��Ч��ͼ��Sobel��Ե���", CV_WINDOW_AUTOSIZE);

	// ����trackbar
	createTrackbar("����ֵ��", "��Ч��ͼ��Canny��Ե���", &g_cannyLowThreshold, 120, on_Canny);
	createTrackbar("����ֵ��", "��Ч��ͼ��Sobel��Ե���", &g_sobelKernelSize, 3, on_Sobel);

	// ���ûص�����
	on_Canny(0, 0);
	on_Sobel(0, 0);

	//���÷�װ��Scharr��Ե������ĺ���
	Scharr();
}

