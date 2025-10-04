//
//  main.cpp
//  opencv
//
//  Created by Andrei Lukashevich on 04-10-2025.
//
//#include "header.h"
#include <iostream>
//#include <opencv2/opencv.hpp>
//###2
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;


int main(int argc, const char * argv[]) {
  
//#if 0
    // open the first webcam plugged in the computer
       cv::VideoCapture camera(0); // in linux check $ ls /dev/video0
       if (!camera.isOpened()) {
           std::cerr << "ERROR: Could not open camera" << std::endl;
           return 1;
       }

       // create a window to display the images from the webcam
       cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE);

       // array to hold image
    cv::Mat image;
       
       // display the frame until you press a key
       while (1) {
           // capture the next frame from the webcam
           camera >> image;
           // show the image on the window
           
           cv::imwrite("./first.png", image);
           //cv::haveImageWriter("first.jpg");
           //cv::imwrite("image_name.jpg", image);
           
           //bool isSaved = cv::imwrite("./first.png", image);
           cv::imshow("Webcam", image);
           // wait (10ms) for esc key to be pressed to stop
           
           
               cv::waitKey(0);
               cv::destroyAllWindows();
           
           
           //if (cv::waitKey(10) == 27)    break;
           //waitKey(10);
           
       }
    
    //#endif

#if 0
    // capture from web camera init

      VideoCapture cap(0);
      cap.open(0);

      Mat img;

      // Initialize the inbuilt Harr Cascade frontal face detection
      // Below mention the path of where your haarcascade_frontalface_alt2.xml     file is located

      CascadeClassifier face_cascade;
      //face_cascade.load("C:/OpenCV/sources/data/haarcascades/haarcascade_frontalface_alt2.xml");
      // i tried changing this line to match my folder in C Drive

      for (;;)
      {

          // Image from camera to Mat

          cap >> img;

          // Just resize input image if you want  CV_HAAR_SCALE_IMAGE
          resize(img, img, Size(1000, 640));

          // Container of faces
          vector<Rect> faces;

          // Detect faces
          face_cascade.detectMultiScale(img, faces, 1.1, 2, 0 | CV_HAL_DFT_SCALE, Size(140, 140));
          // error message appears here

          //Show the results
          // Draw circles on the detected faces
          for (int i = 0; i < faces.size(); i++)
          {
              Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
              ellipse(img, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
          }

          // To draw rectangles around detected faces
          /* for (unsigned i = 0; i<faces.size(); i++)
          rectangle(img,faces[i], Scalar(255, 0, 0), 2, 1);*/
          
          cv::imwrite("image_name.jpg", img);
          
          imshow("wooohooo", img);
          int key2 = waitKey(20);
          // wait (10ms) for esc key to be pressed to stop
          if (cv::waitKey(10) == 27)
              break;

      }
#endif
    
    
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
