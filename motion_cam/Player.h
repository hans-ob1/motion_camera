#ifndef PLAYER_H
#define PLAYER_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>

#include <string>
#include <ctime>

using namespace cv;
using namespace std;

class Player : public QThread
{    Q_OBJECT
 private:
    bool stop;
    QMutex mutex;
    QWaitCondition condition;
    Mat frame;
    int frameRate;
    int numFrames;
    VideoCapture capture;
    Mat RGBframe;
    QImage img;
 signals:
 //Signal to output frame to be displayed
      void processedImage(const QImage &image);
 protected:
     void run();
     void msleep(int ms);
 public:
    //Constructor
    Player(QObject *parent = 0);
    //Destructor
    ~Player();
    //Load a video from memory
    bool loadVideo(string filename);
    //Play the video
    void Play();
    //Stop the video
    void Stop();
    //check if the player has been stopped

    void Shuffle(int k);
    // check the playback

    int getMaxFrameCount();
    // return max number of frames

    double getFrameRate();
    // return max number of frames

    int getCurrentFrame();

    bool isStopped() const;
};
#endif // VIDEOPLAYER_H
