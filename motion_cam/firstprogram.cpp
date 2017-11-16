/*
This file handles UI call player/recorder

*/

#include "firstprogram.h"
#include "ui_firstprogram.h"

#include <opencv2/opencv.hpp>


// UI Control
using namespace cv;

//constructor
firstprogram::firstprogram(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::firstprogram)
{
    myPlayer = new Player();
    QObject::connect(myPlayer, SIGNAL(processedImage(QImage)),this, SLOT(updatePlayerUI(QImage)));

    myRecord = new Record();
    QObject::connect(myRecord, SIGNAL(processedImage(QImage)),this, SLOT(updateRecordUI(QImage)));

    ui->setupUi(this);
}

//destructor
firstprogram::~firstprogram()
{
    delete ui;
    delete myPlayer;
    delete myRecord;
}

void firstprogram::reset_screen(){

    ui->playbackslider->setSliderPosition(0); //reset slider
    QPixmap pxr(ui->display_image->size());
    pxr.fill(Qt::black);
    ui->display_image->setPixmap(pxr);
}

void firstprogram::button_state(int state){
    //state 1: load | n/a | n/a
    //state 2: load | play | n/a
    //state 3: n/a | pause | stop
    //state 4: load | play | stop

    switch (state){
       case 1: // video is not loaded
            ui->load_button->setEnabled(true);
            ui->play_pause_button->setText(tr("Play"));
            ui->play_pause_button->setEnabled(false);
            ui->stop_button->setEnabled(false);
            break;
       case 2: // transit from pause state to play state
            ui->load_button->setEnabled(true);
            ui->play_pause_button->setText(tr("Play"));
            ui->play_pause_button->setEnabled(true);
            ui->stop_button->setEnabled(false);
            break;
       case 3: // transit from playing state to pause state
            ui->load_button->setEnabled(false);
            ui->play_pause_button->setText(tr("Pause"));
            ui->play_pause_button->setEnabled(true);
            ui->stop_button->setEnabled(true);
            break;
       case 4: // after video is loaded
            ui->load_button->setEnabled(true);
            ui->play_pause_button->setText(tr("Play"));
            ui->play_pause_button->setEnabled(true);
            ui->stop_button->setEnabled(false);
            break;
       default:
            break;
    }
}

QString firstprogram::getFormattedTime(int timeInSeconds){

    int seconds = (int) (timeInSeconds) % 60;
    int minutes = (int) ((timeInSeconds / 60) % 60);
    int hours = (int) ((timeInSeconds / (60*60)) % 24);

    QTime t(hours, minutes, seconds);

    if(hours == 0)
        return t.toString("mm:ss");
    else
        return t.toString("h:mm:ss");
}


void firstprogram::on_playbackslider_sliderPressed(){

    // time stop insert here
    // pause the slider
    myPlayer->Stop();  //pause
}

void firstprogram::on_playbackslider_sliderReleased(){

   // time start insert here
    myPlayer->Play();   //play
}

void firstprogram::on_playbackslider_sliderMoved(int position){

    myPlayer->Shuffle(position);
    ui->time_start_label->setText( getFormattedTime( position/(int)myPlayer->getFrameRate()) );
}

void firstprogram::updatePlayerUI(QImage img){

    if (!img.isNull())
    {
        ui->display_image->setAlignment(Qt::AlignCenter);
        ui->display_image->setPixmap(QPixmap::fromImage(img).scaled(ui->display_image->size(),Qt::KeepAspectRatio, Qt::FastTransformation));

        int currentFramePos = myPlayer->getCurrentFrame();
        ui->time_start_label->setText( getFormattedTime( currentFramePos/(int)myPlayer->getFrameRate()) );   //update timer
        ui->playbackslider->setSliderPosition(currentFramePos);
    }
}

void firstprogram::on_load_button_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Video"), ".",tr("Video Files (*.avi *.mpg *.mp4)"));

    if (!filename.isEmpty()){
        if (!myPlayer->loadVideo(filename.toLocal8Bit().constData()))
        {
            QMessageBox msgBox;
            msgBox.setText("The selected video could not be opened!");
            msgBox.exec();
        }else{
            ui->playbackslider->setEnabled(true);  //enable slider bar

            this->button_state(4);
            this->reset_screen();

            //set timer and label
            ui->playbackslider->setMaximum(myPlayer->getMaxFrameCount()); //set the framecount of the sliding bar
            ui->time_end_label->setText( getFormattedTime( (int)myPlayer->getMaxFrameCount()/(int)myPlayer->getFrameRate()) );
        }
    }
}

void firstprogram::on_play_pause_button_clicked()
{
    if (myPlayer->isStopped())
    {
        myPlayer->Play();
       // ui->play_pause_button->setText(tr("Pause"));
        this->button_state(3);

    }else{
        myPlayer->Stop();
        this->button_state(2);
        // ui->play_pause_button->setText(tr("Play"));
    }
}

//on stop button clicked while playing
void firstprogram::on_stop_button_clicked()
{
       // stop player
       myPlayer->Stop();
       myPlayer->Shuffle(0);  //reset back to first frame
       ui->playbackslider->setSliderPosition(0); //reset slider

       // set ui status
       this->button_state(2);
       this->reset_screen();

       ui->time_start_label->setText( getFormattedTime( 0 /(int)myPlayer->getFrameRate()) );   //update timer
}

//***** ***** ***** ***** ***** ***** ***** ***** ***** *****
//***** ***** ***** Record UI PART! ***** ***** ***** *****
//***** ***** ***** ***** ***** ***** ***** ***** ***** *****

//on stop button clicked while playing
void firstprogram::on_stop_record_button_clicked()
{
    if (!myRecord->isStopped())  //if is playing
    {
        myRecord->startRecording();
        ui->stop_record_button->setText(tr("Stop"));
    }else{
        myRecord->stopRecording();
        ui->stop_record_button->setText(tr("Record"));
    }

  //  QString s = QDate::currentDate().toString();
  //  QString c = QTime::currentTime().toString();



 //   QDateTime dateTime = dateTime.currentDateTime();
 //   QString dateTimeString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
 //   ui->record_label->setText(dateTimeString);   //update timer

}

void firstprogram::on_loadcam_button_clicked()
{
    myRecord->loadCam(0);

    if(!myRecord->getCamStatus()){
        ui->camstatus_label->setText("Cam Loaded!");
        ui->loadcam_button->setEnabled(false);
        ui->stop_record_button->setEnabled(true);
        myRecord->runit();
    }else{
        QMessageBox msgBox;
        msgBox.setText("Cam Loading Failed!");
        msgBox.exec();
    }
}


void firstprogram::updateRecordUI(QImage img){

    if (!img.isNull())
    {
        ui->display_record->setAlignment(Qt::AlignCenter);
        ui->display_record->setPixmap(QPixmap::fromImage(img).scaled(ui->display_record->size(),Qt::KeepAspectRatio, Qt::FastTransformation));
    }
}

