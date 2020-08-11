// Run code with the following command
// g++ -o pcl_receiver_LCM pcl_receiver_LCM.cpp -llcm

#include <stdio.h>

#include <lcm/lcm-cpp.hpp>
#include "pcl_type.hpp"
#include <unistd.h>

class Handler {
  public:
    ~Handler() {}
    void handleMessage(const lcm::ReceiveBuffer *rbuf, const std::string &chan,
                       const pcl_type *msg)
    {	
        printf("Received message on channel \"%s\":\n", chan.c_str());
        printf("  xarray   = %f %f %f %f \n", (float) msg->xarray[0],(float) msg->xarray[1],(float) msg->xarray[2],(float) msg->xarray[3]);
	printf("  yarray   = %f %f %f %f \n", (float) msg->yarray[0],(float) msg->yarray[1],(float) msg->yarray[2],(float) msg->yarray[3]);
	printf("  zarray   = %f %f %f %f \n", (float) msg->zarray[0],(float) msg->zarray[1],(float) msg->zarray[2],(float) msg->zarray[3]);
    }
};

int main(int argc, char **argv)
{
    lcm::LCM lcm;

    if (!lcm.good())
        return 1;

    Handler handlerObject;
    lcm.subscribe("pcl_topic", &Handler::handleMessage, &handlerObject);

    while (0 == lcm.handle()) {
	printf("test!\n");
        // Do nothing
    }

    return 0;
}
