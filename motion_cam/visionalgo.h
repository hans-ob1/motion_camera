#ifndef VISIONALGO_H
#define VISIONALGO_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video.hpp>

#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

class visionalgo
{
private:
    Ptr<BackgroundSubtractor> pMOG2;
    double prob;
    bool firstobservation;

public:
    visionalgo();
    //Destructor
    ~visionalgo();

    void gaussianFilter(Mat& input);
    void medianFilter(Mat& input);
    void thresholdMask(Mat& input);
    void bg_subtract(Mat& input, Mat& output);

    //count pixels
    int nonZeroPixelCount(Mat& input);

    //math algos
    double bayesianClassifer(bool observed);

    //put Text function
    void paintFrame(Mat& input, string& text);
};

#endif // VISIONALGO_H
