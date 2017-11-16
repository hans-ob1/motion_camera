#include "record.h"

Record::Record(QObject *parent)
 : QThread(parent)
{
    camfail = true;
    startrecord = false;

    myAlgo = new visionalgo();
}

Record::~Record()
{
    mutex.lock();
    capture.release();
    output.release();
    condition.wakeOne();

    delete myAlgo;
    mutex.unlock();
    camfail = true;
    startrecord = false;
    wait();
}

void Record::loadCam(int dev_num) {   // load the video

    if(!capture.open(CAP_ANY))
        cout << "Fail to grab frame!" <<endl;

    if (capture.isOpened())
    {
        frameRate = (int) capture.get(CV_CAP_PROP_FPS);
        numFrames = (int) capture.get(CV_CAP_PROP_FRAME_COUNT); // count frames

        capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
        capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
        camfail = false;
    }
}

// set framerate duration
void Record::msleep(int ms){
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}


// run live camera upon invoked
void Record::run()
{
    int delay = 100/30;  //set timer

    //background subtraction frame container
    Mat frame_filtered;
    Mat frame_masked;

    //check if need to be recorded
    bool rec_flag = false;

    for(;;){
        if (!capture.read(frame)){
            camfail = true;
            break;
        }

        //time and date label
        string datetime = "Date: " + getStringCurrentDate() + " Time: "+ getStringCurrentTime();
        myAlgo->paintFrame(frame, datetime);

        //display on gui interface
        if (frame.channels()== 3){
            //colored
            cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
            img_record = QImage((const unsigned char*)(RGBframe.data),RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
        }
        else
        {   //grey
            img_record = QImage((const unsigned char*)(frame.data),frame.cols,frame.rows,QImage::Format_Indexed8);
        }

        //check if frame need to be saved
        if(startrecord){

         //background subtraction
         frame_filtered = frame.clone();
         myAlgo->medianFilter(frame_filtered);
         myAlgo->bg_subtract(frame_filtered,frame_masked);
         myAlgo->gaussianFilter(frame_masked);
         myAlgo->thresholdMask(frame_masked);

         //pre processing (getting the pixel ratio number)
         int num_white = myAlgo->nonZeroPixelCount(frame_masked);
         double ratio = ((double)num_white / (640*480))*100;

         //evalution
         bool motionObserved = false;
         if(ratio > 1) //movement threshold
            motionObserved = true;

         // evaluate if there is motion
         if(myAlgo->bayesianClassifer(motionObserved) > 0.5){  //get bayes probabiliy
            cout << "Movement Observed!" << endl;
            rec_flag = true;
         }

         //check if video need to recorded
         if(rec_flag){

             int codec = CV_FOURCC('M', 'J', 'P', 'G');  // select desired codec (must be available at runtime)
             double fps = 15.0;// framerate of the created video stream
             string filename =  "./video/" + getStringCurrentDate();

             //check if the path exist
             QDir dir("video/"+ getQCurrentDate());
             if (!dir.exists()) {

                 dir.mkpath(".");
                 filename = filename + "/"+ startRecordTime +".avi";  //stamped with current starting time

                 if(output.isOpened()){
                    output.release();
                 }

                 output.open(filename, codec, fps, Size(640,480), 1);  //reopen
                 startRecordTimeOld = startRecordTime;
             }else{
                 if (!output.isOpened()){
                     cout << "output not opened" <<endl;
                     filename = filename + "/"+ startRecordTime +".avi";  //stamped with current starting time
                     output.open(filename, codec, fps, Size(640,480), 1);

                     startRecordTimeOld = startRecordTime;
                 }else{

                     if(startRecordTimeOld != startRecordTime ){ //check if the record start stop
                         if(output.isOpened()){
                            output.release();
                         }

                         filename = filename + "/"+ startRecordTime +".avi";
                         output.open(filename, codec, fps, Size(640,480), 1);  //reopen
                         startRecordTimeOld = startRecordTime;
                     }
                 }
             }


             if(output.isOpened())
                 output.write(frame);  //write out
             else
                 cout << "writer error" <<endl;

             rec_flag = false;  //reset the flag for next round
         }

        }

        //display frame
        emit processedImage(img_record);

        //delay time
        this->msleep(delay);
    }

}

void Record::startRecording()
{
/*
    int codec = CV_FOURCC('M', 'J', 'P', 'G');  // select desired codec (must be available at runtime)
    double fps = 15.0;                          // framerate of the created video stream

    QString date_f = QDate::currentDate().toString("yyyy_MM_dd"); //set date today
    QString time_f = QTime::currentTime().toString("hh-mm-ss");  //set start time

    //check if the path exist
    QDir dir("video/"+date_f);
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    //date_f.toStdString() <----- convert QString to std::string
    string filename = "./video/" + date_f.toStdString() + "/"+ time_f.toStdString() +".avi";             // name of the output video file
    output.open(filename, codec, fps, Size(640,480), 1);

    if (!output.isOpened()) {
        cerr << "Could not open the output video file for write\n";
    }else{
        startrecord = true;
    }
*/

    startrecord = true;

    //starting time
    startRecordTime = getStringCurrentTimeFileFormat();
}

void Record::stopRecording()
{
    startrecord = false;
}

bool Record::getCamStatus(){
    return camfail;
}

bool Record::isStopped() const{
    return this->startrecord;   //signal the player stopped
}

void Record::runit(){
     start(LowPriority);
}

