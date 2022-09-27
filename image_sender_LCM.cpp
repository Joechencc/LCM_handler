// run method 
// g++ -o image_sender_LCM image_sender_LCM.cpp -llcm -I /usr/local/include/opencv4/ -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_videoio

#include "image_sender_LCM.h"
#include <iostream>
#include <typeinfo>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, char **argv)
{  

    lcm::LCM *lcm = new lcm::LCM("udpm://239.255.76.67:7667?ttl=255");
        
    Mat img_color = imread("/home/prithvidevkv/image_test_2.jpg", IMREAD_COLOR);
    cout<< img_color.type()<< endl;

     if (img_color.empty()) 
     {
      cout << "Could not open or find the image" << endl;
      cin.get(); //wait for any key press
      return -1;
     }
    image_data_t FRST_data;
    int width=256, height=256;
    int image[width][height] = {0};
    
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
                Vec3b intensity = img_color.at<Vec3b>(i, j);
                int32_t blue = intensity.val[0];
                int32_t green = intensity.val[1];
                int32_t red = intensity.val[2];
                
                FRST_data.data[i][j][0]= blue;
                FRST_data.data[i][j][1]= green;
                FRST_data.data[i][j][2]= red;

        }
    }
    cout<< FRST_data.data[0][10]<<endl;
   //FRST_data.data = image;

    if (!lcm->good())
        return 1;


    lcm->publish("image_command_FRST", &FRST_data);


    return 0;
}


