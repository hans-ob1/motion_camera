#include "firstprogram.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

/*
ToDo:
1. record video with name time stamp
2. multiview camera screen
3. add in core 1 tech
4. add in core 2 tech
4b. standalone test
5. beta test
6. build installer
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    firstprogram* w = new firstprogram();
    w->setAttribute(Qt::WA_DeleteOnClose, true);

    w->show();

    return a.exec();
}
