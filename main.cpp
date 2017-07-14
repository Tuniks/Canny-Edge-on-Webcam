#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    VideoCapture stream(0);   //Default camera

    if (!stream.isOpened()) { //check if video device has been initialised
        cout << "cannot open camera";
    }

    //unconditional loop
    while (true) {
        Mat cameraFrame, frameCanny;
        stream.read(cameraFrame);
        Canny(cameraFrame,frameCanny,50, 350, 3, false);

        imshow("Original Input", cameraFrame);
        imshow("Canny Output", frameCanny);
        if( waitKey(10) == 27 )
            break;
    }

    return 0;
}
