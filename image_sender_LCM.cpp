// run method 
// g++ -o sender_LCM sender_LCM.cpp -llcm


#include "sender_LCM.h"
#include <opencv2/opencv.hpp>



int main(int argc, char **argv)
{   
    lcm::LCM *lcm = new lcm::LCM("udpm://239.255.76.67:7667?ttl=255");
    
    Mat image = imread("/home/prithvidevkv/image0000.jpg");
    // Check for failure
     if (image.empty()) 
     {
      cout << "Could not open or find the image" << endl;
      cin.get(); //wait for any key press
      return -1;
     }
    
    image_data_t FRST_data;
    FRST_data.data = image;

    if (!lcm->good())
        return 1;


    lcm->publish("image_command_IHMC", &FRST_data);

    //Handler handlerObject;
    //lcm->subscribe("image_data", &Handler::handleMessage, &handlerObject);

    //lcm->handleTimeout(1200);

    return 0;
}


