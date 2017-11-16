#ifndef FIRSTPROGRAM_H
#define FIRSTPROGRAM_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <player.h>
#include <record.h>

#include <iostream>

namespace Ui {
class firstprogram;
}
class firstprogram : public QMainWindow
{
    Q_OBJECT

public:
    explicit firstprogram(QWidget *parent = 0);
    ~firstprogram();

private slots:

    //**** Player ui controls ****
    //Display video frame in player UI
    void updatePlayerUI(QImage img);
    //Slot for the load video push button.
    void on_load_button_clicked();
    // Slot for the play push button.
    void on_play_pause_button_clicked();

    void on_stop_button_clicked();

    QString getFormattedTime(int timeInSeconds);
    void on_playbackslider_sliderPressed();
    void on_playbackslider_sliderReleased();
    void on_playbackslider_sliderMoved(int position);

    void button_state(int state);
    void reset_screen();
    //**** Player ui controls ****


    //**** Record ui controls ****
    void updateRecordUI(QImage img);
    void on_stop_record_button_clicked();
    void on_loadcam_button_clicked();


private:
    Ui::firstprogram *ui;
    Player* myPlayer;
    Record* myRecord;
};
#endif // FIRSTPROGRAM_H
