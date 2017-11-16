#-------------------------------------------------
# MotionCam v1.0
# This program is a motion detection camera using common USB cameras
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MotionCam
TEMPLATE = app


SOURCES += main.cpp\
        firstprogram.cpp \
    Player.cpp \
    record.cpp \
    visionalgo.cpp \
    timedate.cpp

INCLUDEPATH += C:\cvdev\opencv-mingw\install\include
DEPENDPATH += C:\cvdev\opencv-mingw\install\include

LIBS += -L"C:\cvdev\opencv-mingw\install\x64\mingw\bin"
LIBS += -lopencv_core310 -lopencv_highgui310 -lopencv_imgproc310 -lopencv_imgcodecs310 -lopencv_videoio310 -lopencv_video310

HEADERS  += firstprogram.h \
    Player.h \
    record.h \
    visionalgo.h \
    timedate.h

FORMS    += firstprogram.ui
