#include "Player.h"
Player::Player(QObject *parent)
 : QThread(parent)
{
    stop = true;
}

bool Player::loadVideo(string filename) {   // load the video

    capture.open(filename);
    if (capture.isOpened())
    {
        frameRate = (int) capture.get(CV_CAP_PROP_FPS);
        numFrames = (int) capture.get(CV_CAP_PROP_FRAME_COUNT); // count frames

        return true;
    }
    else
        return false;
}

int Player::getMaxFrameCount(){

    return numFrames;
}

double Player::getFrameRate(){
    return frameRate;
}

int Player::getCurrentFrame(){

    return capture.get(CV_CAP_PROP_POS_FRAMES);;
}

void Player::Shuffle(int k){

    capture.set(CV_CAP_PROP_POS_FRAMES,k);

}

void Player::Play()
{
    if (!isRunning()) {       // if its not running
        if (isStopped()){
            stop = false;
        }
        start(LowPriority);
    }
}

void Player::run()
{
    int delay = (1200/frameRate);  //set timer

    while(!stop){
        if (!capture.read(frame))
        {
            stop = true;
        }

        if (frame.channels()== 3){  //colored
            cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
            img = QImage((const unsigned char*)(RGBframe.data),RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
        }
        else
        {   //grey
            img = QImage((const unsigned char*)(frame.data),frame.cols,frame.rows,QImage::Format_Indexed8);
        }

        emit processedImage(img);
        this->msleep(delay);
    }
}


Player::~Player()
{
    mutex.lock();
    stop = true;
    capture.release();
    condition.wakeOne();
    mutex.unlock();
    wait();
}
void Player::Stop()
{
    stop = true;
}

void Player::msleep(int ms){
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}
bool Player::isStopped() const{
    return this->stop;   //signal the player stopped
}

