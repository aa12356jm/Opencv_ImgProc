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
	
	//��ʱ������
	void timerEvent(QTimerEvent *event);
	//�ڽ�������ʾͼ��
	void showImg();
	QImage MatToQImage(const cv::Mat& mat);//��matͼ��ת��ΪQImage

private slots:
	void on_pushButton_OpenCamera_cliked();//�������
	void on_pushButton_SnapShot_cliked();//����

	void on_radioButton_ToGrayImg_cliked();
	void on_radioButton_ToBlackWhiteImg_cliked();
	void on_radioButton_Filter_cliked();//�����˲�����
	void on_radioButton_Morphology_cliked();//������̬ѧ����
	void on_radioButton_EdgeDetection_cliked();//���ֱ�Ե����㷨
private:
    Ui::ImgProc_OpencvClass *ui;
	VideoCapture capture;//�������
	QVector<QString> m_VecStrErrorInfo;
	
	int id1;//��ʱ��

};
