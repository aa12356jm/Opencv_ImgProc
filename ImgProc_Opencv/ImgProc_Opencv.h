#pragma once

#include <windows.h>
#include <QtWidgets/QMainWindow>
#include <QImage>
#include "ui_ImgProc_Opencv.h"
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

class ImgProc_Opencv : public QMainWindow
{
    Q_OBJECT

public:
    ImgProc_Opencv(QWidget *parent = Q_NULLPTR);
	~ImgProc_Opencv();
	
	//定时器函数
	void timerEvent(QTimerEvent *event);
	//在界面中显示图像
	void showImg();
	QImage MatToQImage(const cv::Mat& mat);//将mat图像转换为QImage

private slots:
	void on_pushButton_OpenCamera_cliked();//启动相机
	void on_pushButton_SnapShot_cliked();//拍照

	void on_radioButton_ToGrayImg_cliked();
	void on_radioButton_ToBlackWhiteImg_cliked();
	void on_radioButton_Filter_cliked();//各种滤波操作
	void on_radioButton_Morphology_cliked();//各种形态学操作
	void on_radioButton_EdgeDetection_cliked();//各种边缘检测算法
private:
    Ui::ImgProc_OpencvClass *ui;
	VideoCapture capture;//启动相机
	QVector<QString> m_VecStrErrorInfo;
	
	int id1;//定时器

};
