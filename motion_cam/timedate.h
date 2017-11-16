/*
This class handles the centralized date and time requirement

Methods:

getDate
setDate

getTime
setTime

*/

#ifndef TIMEDATE_H
#define TIMEDATE_H

#include <QTime>
#include <QDate>

#include <iostream>

using namespace std;

string getStringCurrentDate();
string getStringCurrentTime();

QString getQCurrentTime();
QString getQCurrentDate();

string getStringCurrentTimeFileFormat();

#endif // TIMEDATE_H
