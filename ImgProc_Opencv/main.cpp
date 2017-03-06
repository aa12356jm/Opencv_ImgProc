#include "ImgProc_Opencv.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImgProc_Opencv w;
    w.show();
    return a.exec();
}
