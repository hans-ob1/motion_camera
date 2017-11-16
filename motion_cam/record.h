#ifndef RECORD_H
#define RECORD_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <QString>
#include <QTime>
#include <QDate>
#include <QDir>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>

#include <visionalgo.h>
#include <timedate.h>

#include <ctime>
#include <iostream>

using namespace cv;
using namespace std;

class Record : public QThread
{ Q_OBJECT
private:
    VideoCapture capture;
    VideoWriter output;

    Mat frame;
    QImage img_record;
    QMutex mutex;
    QWaitCondition condition;

    bool camfail;
    bool startrecord;

    int frameRate;
    int numFrames;
    Mat RGBframe;

    string startRecordTime;
    string startRecordTimeOld;

    visionalgo* myAlgo;

signals:
     //Signal to output frame to be displayed
     void processedImage(const QImage &image);

protected:
    void run();
    void msleep(int ms);

public:
    Record(QObject *parent = 0);

   //Destructor
   ~Record();

   //start recording
   void startRecording();

   //stop recording
   void stopRecording();

   void loadCam(int dev_num);

   bool getCamStatus();

   bool isStopped() const;

   void runit();

   QString getDate();
   QString getTime();
};

#endif // RECORD_H
