// run method 
// g++ -o image_sender_LCM image_sender_LCM.cpp -llcm -I /usr/local/include/opencv4/ -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_videoio

#include "image_sender_LCM.h"
#include <iostream>
#include <typeinfo>
#include <unistd.h>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, char **argv)
{  
    int width=640, height=640;
    int sender_ID = 1;
    lcm::LCM *lcm = new lcm::LCM("udpm://239.255.76.67:7667?ttl=255");
        
    std::string arg1(argv[1]);
    
    cout << "Sending Image: " << arg1 << "\n" << endl;
        
        
    Mat img_color = imread(arg1, IMREAD_COLOR);
    Mat gray_image;
    cv::cvtColor(img_color, gray_image, cv::COLOR_BGR2GRAY );
    
    cout << gray_image.type() << endl;

     if (img_color.empty()) 
     {
      cout << "Could not open or find the image" << endl;
      cin.get(); //wait for any key press
      return -1;
     }
     
    int counter = 0;
     
    image_data_t FRST_data;
    
    int image[width][height] = {0};
    
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
                int8_t intensity = (int8_t)gray_image.at<uchar>(i, j);
                //cout << (int)gray_image.at<uchar>(i, j) << endl;
                
                //int32_t blue = intensity.val[0];
                //int32_t green = intensity.val[1];
                //int32_t red = intensity.val[2];
                
                FRST_data.data[i][j][0]= intensity;
                //FRST_data.data[i][j][1]= green;
                //FRST_data.data[i][j][2]= red;

        }
    }
    //cout<< FRST_data.data[0][10]<<endl;
    //FRST_data.data = image;
    FRST_data.ID = sender_ID;
    
    if (!lcm->good())
        return 1;


    lcm->publish("image_command_FRST", &FRST_data);
    counter = counter + 1;
    sleep(1);
    return 0;
}


