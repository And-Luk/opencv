//
//  main.cpp
//  opencv
//
//  Created by Andrei Lukashevich on 04-10-2025.
//
#include "header.h"
#include <opencv2/opencv.hpp>
//#include <>

int main(int argc, const char * argv[]) {
    
    // open the first webcam plugged in the computer
       cv::VideoCapture camera(0); // in linux check $ ls /dev/video0
       if (!camera.isOpened()) {
           std::cerr << "ERROR: Could not open camera" << std::endl;
           return 1;
       }

       // create a window to display the images from the webcam
       cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE);

       // array to hold image
       cv::Mat frame;
       
       // display the frame until you press a key
       while (1) {
           // capture the next frame from the webcam
           camera >> frame;
           // show the image on the window
           cv::imshow("Webcam", frame);
           // wait (10ms) for esc key to be pressed to stop
           if (cv::waitKey(10) == 27)
               break;
       }
    
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
