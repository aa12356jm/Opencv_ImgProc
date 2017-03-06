/********************************************************************************
** Form generated from reading UI file 'ImgProc_Opencv.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGPROC_OPENCV_H
#define UI_IMGPROC_OPENCV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImgProc_OpencvClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_ImgProcBasicAlg;
    QGroupBox *groupBox;
    QRadioButton *radioButton_ToGrayImg;
    QRadioButton *radioButton_ToBlackWhiteImg;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QGroupBox *groupBox_6;
    QRadioButton *radioButton_13;
    QRadioButton *radioButton_14;
    QGroupBox *groupBox_10;
    QGroupBox *groupBox_7;
    QGroupBox *groupBox_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QGroupBox *groupBox_5;
    QLabel *label_10;
    QLabel *label_11;
    QGroupBox *groupBox_8;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QRadioButton *radioButton_Morphology;
    QRadioButton *radioButton_16;
    QRadioButton *radioButton_20;
    QRadioButton *radioButton_23;
    QRadioButton *radioButton_Filter;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_11;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QRadioButton *radioButton_EdgeDetection;
    QRadioButton *radioButton_36;
    QRadioButton *radioButton_37;
    QRadioButton *radioButton_38;
    QRadioButton *radioButton_39;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_24;
    QRadioButton *radioButton_29;
    QRadioButton *radioButton_25;
    QRadioButton *radioButton_26;
    QRadioButton *radioButton_27;
    QRadioButton *radioButton_28;
    QWidget *tab_ImgProcComplexAlg;
    QGroupBox *groupBox_12;
    QPushButton *pushButton;
    QLabel *label_19;
    QComboBox *comboBox;
    QLabel *label_20;
    QWidget *widget;
    QLabel *label_ProcImg;
    QLabel *label_ShowImg;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_OpenCamera;
    QPushButton *pushButton_SnapShot;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImgProc_OpencvClass)
    {
        if (ImgProc_OpencvClass->objectName().isEmpty())
            ImgProc_OpencvClass->setObjectName(QStringLiteral("ImgProc_OpencvClass"));
        ImgProc_OpencvClass->resize(1364, 940);
        centralWidget = new QWidget(ImgProc_OpencvClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 430, 1191, 401));
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tab_ImgProcBasicAlg = new QWidget();
        tab_ImgProcBasicAlg->setObjectName(QStringLiteral("tab_ImgProcBasicAlg"));
        groupBox = new QGroupBox(tab_ImgProcBasicAlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(930, 30, 131, 91));
        radioButton_ToGrayImg = new QRadioButton(groupBox);
        radioButton_ToGrayImg->setObjectName(QStringLiteral("radioButton_ToGrayImg"));
        radioButton_ToGrayImg->setGeometry(QRect(10, 20, 61, 16));
        radioButton_ToBlackWhiteImg = new QRadioButton(groupBox);
        radioButton_ToBlackWhiteImg->setObjectName(QStringLiteral("radioButton_ToBlackWhiteImg"));
        radioButton_ToBlackWhiteImg->setGeometry(QRect(10, 50, 61, 16));
        groupBox_3 = new QGroupBox(tab_ImgProcBasicAlg);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(1090, 50, 71, 81));
        radioButton_5 = new QRadioButton(groupBox_3);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 20, 61, 16));
        radioButton_6 = new QRadioButton(groupBox_3);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(10, 50, 61, 16));
        groupBox_6 = new QGroupBox(tab_ImgProcBasicAlg);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(930, 640, 111, 81));
        radioButton_13 = new QRadioButton(groupBox_6);
        radioButton_13->setObjectName(QStringLiteral("radioButton_13"));
        radioButton_13->setGeometry(QRect(10, 20, 91, 16));
        radioButton_14 = new QRadioButton(groupBox_6);
        radioButton_14->setObjectName(QStringLiteral("radioButton_14"));
        radioButton_14->setGeometry(QRect(10, 50, 81, 16));
        groupBox_10 = new QGroupBox(tab_ImgProcBasicAlg);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(220, 20, 671, 291));
        groupBox_7 = new QGroupBox(groupBox_10);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 30, 381, 261));
        groupBox_4 = new QGroupBox(groupBox_7);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 20, 81, 91));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 20, 71, 16));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 40, 71, 16));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 60, 71, 16));
        groupBox_5 = new QGroupBox(groupBox_7);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(100, 20, 81, 91));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 20, 71, 16));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 50, 71, 16));
        groupBox_8 = new QGroupBox(groupBox_7);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 140, 191, 91));
        label_12 = new QLabel(groupBox_8);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 20, 41, 16));
        label_13 = new QLabel(groupBox_8);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 40, 41, 16));
        label_14 = new QLabel(groupBox_8);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(60, 20, 54, 12));
        label_15 = new QLabel(groupBox_8);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(60, 40, 54, 12));
        label_16 = new QLabel(groupBox_8);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(120, 20, 54, 12));
        label_17 = new QLabel(groupBox_8);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(120, 40, 54, 12));
        label_18 = new QLabel(groupBox_8);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 60, 81, 16));
        radioButton_Morphology = new QRadioButton(groupBox_8);
        radioButton_Morphology->setObjectName(QStringLiteral("radioButton_Morphology"));
        radioButton_Morphology->setGeometry(QRect(100, 60, 71, 16));
        radioButton_16 = new QRadioButton(groupBox_7);
        radioButton_16->setObjectName(QStringLiteral("radioButton_16"));
        radioButton_16->setGeometry(QRect(210, 30, 71, 16));
        radioButton_20 = new QRadioButton(groupBox_7);
        radioButton_20->setObjectName(QStringLiteral("radioButton_20"));
        radioButton_20->setGeometry(QRect(210, 90, 171, 16));
        radioButton_23 = new QRadioButton(groupBox_7);
        radioButton_23->setObjectName(QStringLiteral("radioButton_23"));
        radioButton_23->setGeometry(QRect(210, 140, 71, 16));
        radioButton_Filter = new QRadioButton(groupBox_7);
        radioButton_Filter->setObjectName(QStringLiteral("radioButton_Filter"));
        radioButton_Filter->setGeometry(QRect(30, 110, 121, 16));
        groupBox_2 = new QGroupBox(groupBox_10);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(410, 30, 241, 161));
        groupBox_11 = new QGroupBox(groupBox_2);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setGeometry(QRect(10, 20, 91, 131));
        label_3 = new QLabel(groupBox_11);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 54, 12));
        label_4 = new QLabel(groupBox_11);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 40, 54, 12));
        label_5 = new QLabel(groupBox_11);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 60, 71, 16));
        label_6 = new QLabel(groupBox_11);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 80, 51, 16));
        radioButton_EdgeDetection = new QRadioButton(groupBox_11);
        radioButton_EdgeDetection->setObjectName(QStringLiteral("radioButton_EdgeDetection"));
        radioButton_EdgeDetection->setGeometry(QRect(0, 100, 81, 16));
        radioButton_36 = new QRadioButton(groupBox_2);
        radioButton_36->setObjectName(QStringLiteral("radioButton_36"));
        radioButton_36->setGeometry(QRect(130, 50, 61, 16));
        radioButton_37 = new QRadioButton(groupBox_2);
        radioButton_37->setObjectName(QStringLiteral("radioButton_37"));
        radioButton_37->setGeometry(QRect(130, 20, 71, 16));
        radioButton_38 = new QRadioButton(groupBox_2);
        radioButton_38->setObjectName(QStringLiteral("radioButton_38"));
        radioButton_38->setGeometry(QRect(130, 80, 81, 16));
        radioButton_39 = new QRadioButton(groupBox_2);
        radioButton_39->setObjectName(QStringLiteral("radioButton_39"));
        radioButton_39->setGeometry(QRect(130, 110, 91, 16));
        groupBox_9 = new QGroupBox(tab_ImgProcBasicAlg);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 10, 193, 311));
        gridLayout_2 = new QGridLayout(groupBox_9);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        radioButton_24 = new QRadioButton(groupBox_9);
        radioButton_24->setObjectName(QStringLiteral("radioButton_24"));

        gridLayout_2->addWidget(radioButton_24, 0, 0, 1, 1);

        radioButton_29 = new QRadioButton(groupBox_9);
        radioButton_29->setObjectName(QStringLiteral("radioButton_29"));

        gridLayout_2->addWidget(radioButton_29, 1, 0, 1, 1);

        radioButton_25 = new QRadioButton(groupBox_9);
        radioButton_25->setObjectName(QStringLiteral("radioButton_25"));

        gridLayout_2->addWidget(radioButton_25, 2, 0, 1, 1);

        radioButton_26 = new QRadioButton(groupBox_9);
        radioButton_26->setObjectName(QStringLiteral("radioButton_26"));

        gridLayout_2->addWidget(radioButton_26, 3, 0, 1, 1);

        radioButton_27 = new QRadioButton(groupBox_9);
        radioButton_27->setObjectName(QStringLiteral("radioButton_27"));

        gridLayout_2->addWidget(radioButton_27, 4, 0, 1, 1);

        radioButton_28 = new QRadioButton(groupBox_9);
        radioButton_28->setObjectName(QStringLiteral("radioButton_28"));

        gridLayout_2->addWidget(radioButton_28, 5, 0, 1, 1);

        tabWidget->addTab(tab_ImgProcBasicAlg, QString());
        tab_ImgProcComplexAlg = new QWidget();
        tab_ImgProcComplexAlg->setObjectName(QStringLiteral("tab_ImgProcComplexAlg"));
        groupBox_12 = new QGroupBox(tab_ImgProcComplexAlg);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        groupBox_12->setGeometry(QRect(20, 0, 291, 291));
        pushButton = new QPushButton(groupBox_12);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 100, 61, 23));
        label_19 = new QLabel(groupBox_12);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 50, 141, 121));
        label_19->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        comboBox = new QComboBox(groupBox_12);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 50, 111, 22));
        label_20 = new QLabel(groupBox_12);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 30, 41, 16));
        tabWidget->addTab(tab_ImgProcComplexAlg, QString());
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 10, 1251, 411));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_ProcImg = new QLabel(widget);
        label_ProcImg->setObjectName(QStringLiteral("label_ProcImg"));
        label_ProcImg->setGeometry(QRect(590, 30, 541, 361));
        label_ProcImg->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        label_ShowImg = new QLabel(widget);
        label_ShowImg->setObjectName(QStringLiteral("label_ShowImg"));
        label_ShowImg->setGeometry(QRect(10, 30, 561, 361));
        label_ShowImg->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 255);"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 54, 12));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(590, 10, 61, 20));
        pushButton_OpenCamera = new QPushButton(widget);
        pushButton_OpenCamera->setObjectName(QStringLiteral("pushButton_OpenCamera"));
        pushButton_OpenCamera->setGeometry(QRect(1160, 40, 75, 23));
        pushButton_SnapShot = new QPushButton(widget);
        pushButton_SnapShot->setObjectName(QStringLiteral("pushButton_SnapShot"));
        pushButton_SnapShot->setGeometry(QRect(1160, 100, 75, 23));
        ImgProc_OpencvClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImgProc_OpencvClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1364, 23));
        ImgProc_OpencvClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImgProc_OpencvClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImgProc_OpencvClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImgProc_OpencvClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImgProc_OpencvClass->setStatusBar(statusBar);

        retranslateUi(ImgProc_OpencvClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ImgProc_OpencvClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImgProc_OpencvClass)
    {
        ImgProc_OpencvClass->setWindowTitle(QApplication::translate("ImgProc_OpencvClass", "ImgProc_Opencv", 0));
        groupBox->setTitle(QApplication::translate("ImgProc_OpencvClass", "\345\233\276\345\203\217\345\244\204\347\220\206\345\237\272\346\234\254\346\223\215\344\275\234", 0));
        radioButton_ToGrayImg->setText(QApplication::translate("ImgProc_OpencvClass", "\347\201\260\345\272\246\345\233\276", 0));
        radioButton_ToBlackWhiteImg->setText(QApplication::translate("ImgProc_OpencvClass", "\344\272\214\345\200\274\345\214\226", 0));
        groupBox_3->setTitle(QApplication::translate("ImgProc_OpencvClass", "\351\242\234\350\211\262\347\251\272\351\227\264", 0));
        radioButton_5->setText(QApplication::translate("ImgProc_OpencvClass", "RGB", 0));
        radioButton_6->setText(QApplication::translate("ImgProc_OpencvClass", "HSV", 0));
        groupBox_6->setTitle(QApplication::translate("ImgProc_OpencvClass", "\347\233\264\346\226\271\345\233\276", 0));
        radioButton_13->setText(QApplication::translate("ImgProc_OpencvClass", "\347\201\260\345\272\246\347\233\264\346\226\271\345\233\276", 0));
        radioButton_14->setText(QApplication::translate("ImgProc_OpencvClass", "RGB\347\233\264\346\226\271\345\233\276", 0));
        groupBox_10->setTitle(QApplication::translate("ImgProc_OpencvClass", "2.imgpro\347\273\204\344\273\266\345\255\246\344\271\240", 0));
        groupBox_7->setTitle(QApplication::translate("ImgProc_OpencvClass", "\345\233\276\345\203\217\345\244\204\347\220\206", 0));
        groupBox_4->setTitle(QApplication::translate("ImgProc_OpencvClass", "\347\272\277\346\200\247\346\273\244\346\263\242", 0));
        label_7->setText(QApplication::translate("ImgProc_OpencvClass", "1.\346\226\271\346\241\206\346\273\244\346\263\242", 0));
        label_8->setText(QApplication::translate("ImgProc_OpencvClass", "2.\345\271\263\345\235\207\346\273\244\346\263\242", 0));
        label_9->setText(QApplication::translate("ImgProc_OpencvClass", "3.\351\253\230\346\226\257\346\273\244\346\263\242", 0));
        groupBox_5->setTitle(QApplication::translate("ImgProc_OpencvClass", "\351\235\236\347\272\277\346\200\247\346\273\244\346\263\242", 0));
        label_10->setText(QApplication::translate("ImgProc_OpencvClass", "4.\344\270\255\345\200\274\346\273\244\346\263\242", 0));
        label_11->setText(QApplication::translate("ImgProc_OpencvClass", "5.\345\217\214\350\276\271\346\273\244\346\263\242", 0));
        groupBox_8->setTitle(QApplication::translate("ImgProc_OpencvClass", "\345\275\242\346\200\201\345\255\246\346\273\244\346\263\242", 0));
        label_12->setText(QApplication::translate("ImgProc_OpencvClass", "1.\350\206\250\350\203\200", 0));
        label_13->setText(QApplication::translate("ImgProc_OpencvClass", "2.\350\205\220\350\232\200", 0));
        label_14->setText(QApplication::translate("ImgProc_OpencvClass", "3.\345\274\200\350\277\220\347\256\227", 0));
        label_15->setText(QApplication::translate("ImgProc_OpencvClass", "4.\351\227\255\350\277\220\347\256\227", 0));
        label_16->setText(QApplication::translate("ImgProc_OpencvClass", "5.\351\241\266\345\270\275", 0));
        label_17->setText(QApplication::translate("ImgProc_OpencvClass", "6.\351\273\221\345\270\275", 0));
        label_18->setText(QApplication::translate("ImgProc_OpencvClass", "7.\345\275\242\346\200\201\345\255\246\346\242\257\345\272\246", 0));
        radioButton_Morphology->setText(QApplication::translate("ImgProc_OpencvClass", "\347\273\274\345\220\210\347\244\272\344\276\213", 0));
        radioButton_16->setText(QApplication::translate("ImgProc_OpencvClass", "\346\274\253\346\260\264\345\241\253\345\205\205", 0));
        radioButton_20->setText(QApplication::translate("ImgProc_OpencvClass", "\345\233\276\345\203\217\351\207\221\345\255\227\345\241\224\344\270\216\345\233\276\347\211\207\345\260\272\345\257\270\347\274\251\346\224\276", 0));
        radioButton_23->setText(QApplication::translate("ImgProc_OpencvClass", "\351\230\210\345\200\274\345\214\226", 0));
        radioButton_Filter->setText(QApplication::translate("ImgProc_OpencvClass", "\344\272\224\347\247\215\346\273\244\346\263\242\347\273\274\345\220\210\347\244\272\344\276\213", 0));
        groupBox_2->setTitle(QApplication::translate("ImgProc_OpencvClass", "\345\233\276\345\203\217\345\217\230\346\215\242", 0));
        groupBox_11->setTitle(QApplication::translate("ImgProc_OpencvClass", "\350\276\271\347\274\230\346\243\200\346\265\213", 0));
        label_3->setText(QApplication::translate("ImgProc_OpencvClass", "1.canny", 0));
        label_4->setText(QApplication::translate("ImgProc_OpencvClass", "2.sobel", 0));
        label_5->setText(QApplication::translate("ImgProc_OpencvClass", "3.Laplacian", 0));
        label_6->setText(QApplication::translate("ImgProc_OpencvClass", "4.scharr", 0));
        radioButton_EdgeDetection->setText(QApplication::translate("ImgProc_OpencvClass", "\347\273\274\345\220\210\347\244\272\344\276\213", 0));
        radioButton_36->setText(QApplication::translate("ImgProc_OpencvClass", "\351\207\215\346\230\240\345\260\204", 0));
        radioButton_37->setText(QApplication::translate("ImgProc_OpencvClass", "\351\234\215\345\244\253\345\217\230\346\215\242", 0));
        radioButton_38->setText(QApplication::translate("ImgProc_OpencvClass", "\344\273\277\345\260\204\345\217\230\346\215\242", 0));
        radioButton_39->setText(QApplication::translate("ImgProc_OpencvClass", "\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226", 0));
        groupBox_9->setTitle(QApplication::translate("ImgProc_OpencvClass", "1.core\347\273\204\344\273\266\345\255\246\344\271\240", 0));
        radioButton_24->setText(QApplication::translate("ImgProc_OpencvClass", "\345\237\272\346\234\254\346\225\260\346\215\256\347\273\223\346\236\204\345\255\246\344\271\240\344\275\277\347\224\250", 0));
        radioButton_29->setText(QApplication::translate("ImgProc_OpencvClass", "\350\256\277\351\227\256\345\233\276\345\203\217\344\270\255\345\203\217\347\264\240\347\232\204\344\270\211\347\247\215\346\226\271\346\263\225", 0));
        radioButton_25->setText(QApplication::translate("ImgProc_OpencvClass", "ROI\345\214\272\345\237\237\345\233\276\345\203\217\345\217\240\345\212\240\345\222\214\345\233\276\345\203\217\346\267\267\345\220\210", 0));
        radioButton_26->setText(QApplication::translate("ImgProc_OpencvClass", "\345\257\271\346\257\224\345\272\246\345\222\214\344\272\256\345\272\246\345\200\274\350\260\203\346\225\264", 0));
        radioButton_27->setText(QApplication::translate("ImgProc_OpencvClass", "\345\202\205\351\207\214\345\217\266\345\217\230\346\215\242", 0));
        radioButton_28->setText(QApplication::translate("ImgProc_OpencvClass", "XML\345\222\214YAML\346\226\207\344\273\266\345\272\224\347\224\250", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_ImgProcBasicAlg), QApplication::translate("ImgProc_OpencvClass", "\345\233\276\345\203\217\345\244\204\347\220\206\345\237\272\346\234\254\347\256\227\346\263\225", 0));
        groupBox_12->setTitle(QApplication::translate("ImgProc_OpencvClass", "\346\250\241\346\235\277\345\214\271\351\205\215", 0));
        pushButton->setText(QApplication::translate("ImgProc_OpencvClass", "\346\211\223\345\274\200\346\250\241\346\235\277", 0));
        label_19->setText(QApplication::translate("ImgProc_OpencvClass", "TextLabel", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ImgProc_OpencvClass", "\345\271\263\346\226\271\345\267\256\345\214\271\351\205\215\346\263\225", 0)
         << QApplication::translate("ImgProc_OpencvClass", "\347\233\270\345\205\263\345\214\271\351\205\215\346\263\225", 0)
         << QApplication::translate("ImgProc_OpencvClass", "\347\233\270\345\205\263\347\263\273\346\225\260\345\214\271\351\205\215\346\263\225", 0)
         << QApplication::translate("ImgProc_OpencvClass", "\345\275\222\344\270\200\345\214\226\345\271\263\346\226\271\345\267\256\345\214\271\351\205\215\346\263\225", 0)
         << QApplication::translate("ImgProc_OpencvClass", "\345\275\222\344\270\200\345\214\226\347\233\270\345\205\263\345\214\271\351\205\215\346\263\225", 0)
         << QApplication::translate("ImgProc_OpencvClass", "\345\275\222\344\270\200\345\214\226\347\233\270\345\205\263\347\263\273\346\225\260\345\214\271\351\205\215\346\263\225", 0)
        );
        label_20->setText(QApplication::translate("ImgProc_OpencvClass", "\346\250\241\346\235\277\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_ImgProcComplexAlg), QApplication::translate("ImgProc_OpencvClass", "\345\233\276\345\203\217\345\244\204\347\220\206\345\244\215\346\235\202\347\256\227\346\263\225", 0));
        label_ProcImg->setText(QString());
        label_ShowImg->setText(QString());
        label->setText(QApplication::translate("ImgProc_OpencvClass", "\345\216\237\345\233\276\345\203\217", 0));
        label_2->setText(QApplication::translate("ImgProc_OpencvClass", "\345\244\204\347\220\206\345\220\216\345\233\276\345\203\217", 0));
        pushButton_OpenCamera->setText(QApplication::translate("ImgProc_OpencvClass", "\346\211\223\345\274\200\347\233\270\346\234\272", 0));
        pushButton_SnapShot->setText(QApplication::translate("ImgProc_OpencvClass", "\346\213\215\347\205\247", 0));
    } // retranslateUi

};

namespace Ui {
    class ImgProc_OpencvClass: public Ui_ImgProc_OpencvClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGPROC_OPENCV_H
