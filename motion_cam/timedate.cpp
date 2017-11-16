#include "timedate.h"

string getStringCurrentDate(){
    QString date = QDate::currentDate().toString("yyyy-MM-dd"); //get current date
    string currDate = date.toStdString();
    return currDate;
}

string getStringCurrentTime(){
    QString time = QTime::currentTime().toString("hh:mm:ss");  //get current time
    string currTime = time.toStdString();
    return currTime;
}

QString getQCurrentTime(){
    QString time = QTime::currentTime().toString("hh:mm:ss");  //get current time in QString
    return time;
}

QString getQCurrentDate(){
    QString date = QDate::currentDate().toString("yyyy-MM-dd");  //get current date in QString
    return date;
}

string getStringCurrentTimeFileFormat(){
    QString time = QTime::currentTime().toString("hh_mm_ss");  //get current time for filename format friendly
    string currTime = time.toStdString();
    return currTime;
}
