#include "visionalgo.h"

visionalgo::visionalgo()
{
    pMOG2 = createBackgroundSubtractorMOG2(); //MOG2 approach
    prob = 0;
    firstobservation = true;
}

visionalgo::~visionalgo()
{
}

//drawing methods
void visionalgo::paintFrame(Mat& input, string& text){

    Point textPos(5,15);
    double fontScale = 1;
    int thickness=1.2;

    //put date and time
    putText(input,text,textPos,FONT_HERSHEY_PLAIN,fontScale,Scalar(255,255,255),thickness);
}


//filter methods
void visionalgo::gaussianFilter(Mat& input){
    GaussianBlur(input, input, Size(15, 15), 0);
}

void visionalgo::medianFilter(Mat& input){
    medianBlur (input, input, 15 );
}

void visionalgo::thresholdMask(Mat& input){
    threshold(input, input, 10, 255, THRESH_BINARY);
}

//pixel operation methods
int visionalgo::nonZeroPixelCount(Mat& input){

    vector<Point> nonzero_pixels;   // output, locations of non-zero pixels
    findNonZero(input, nonzero_pixels);


    int non_zero = nonzero_pixels.size();

    return non_zero;
}

//bayesian algorithm
double visionalgo::bayesianClassifer(bool observed){
   //probability of motion: 0.5
   //probability of observed motion given there is motion: 0.8
   //probability of observed motion given there is no motion: 0.1

   //probability of no observed motion given there is motion 0.1
   //probability of no observed motion given there is no motion 0.8

   if(firstobservation){
      if(observed)
        prob = (0.8*0.5)/0.9;
      else
        prob = (0.1*0.5)/0.9;

      firstobservation = false;
   }else{
       if(observed)
         prob = (0.8*prob)/((0.8*prob)+0.1*(1-prob));
       else
         prob = (0.1*prob)/((0.1*prob)+0.8*(1-prob));
   }

   if(prob > 0.6)
      prob = 0.6;

   if(prob < 0.1)
      prob = 0.1;

   return prob;
}

//background subtraction for movement detection
void visionalgo::bg_subtract(Mat& input,Mat& output){
    //update the background model
    pMOG2->apply(input, output, true ?-1:0);
}
