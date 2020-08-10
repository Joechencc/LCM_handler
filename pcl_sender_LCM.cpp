// run method 
// g++ -o pcl_sender_LCM pcl_sender_LCM.cpp -llcm


#include "sender_LCM.h"


int main(int argc, char **argv)
{   
    lcm::LCM *lcm = new lcm::LCM("udpm://239.255.76.67:7667?ttl=255");
    pcl_type IHMC_data;
    
    for(int i=0; i<30; i++){
        IHMC_data.xarray[i] = 1.0;
        IHMC_data.yarray[i] = 1.0;
        IHMC_data.zarray[i] = 1.0;

    }

    
    if (!lcm->good())
        return 1;

    lcm->publish("pcl_topic", &IHMC_data);

    Handler handlerObject;
    lcm->handleTimeout(1200);

    return 0;
}


