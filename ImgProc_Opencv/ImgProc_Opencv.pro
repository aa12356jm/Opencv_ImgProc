# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = ImgProc_Opencv
DESTDIR = ../Win32/Debug
QT += core multimedia network widgets gui multimediawidgets
CONFIG += debug
DEFINES += WIN64 QT_DLL QT_MULTIMEDIA_LIB QT_MULTIMEDIAWIDGETS_LIB QT_NETWORK_LIB QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(ImgProc_Opencv.pri)
win32:RC_FILE = ImgProc_Opencv.rc