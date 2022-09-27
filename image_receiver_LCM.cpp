// Run code with the following command
// g++ -o image_receiver_LCM image_receiver_LCM.cpp -llcm
// g++ -o image_receiver_LCM image_receiver_LCM.cpp -llcm -I /usr/local/include/opencv4/ -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_videoio

#include <stdio.h>

#include <lcm/lcm-cpp.hpp>
#include "image_data_t.hpp"
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std::chrono;
using namespace std;


class Handler {
  public:
    ~Handler() {}
    void handleMessage(const lcm::ReceiveBuffer *rbuf, const std::string &chan,
                       const image_data_t *msg)
    {	
        printf("Received message on channel \"%s\":\n", chan.c_str());
        printf("  data[0][10][0]   = %d \n", msg->data[0][10][0]);
        int width=256, height=256;

        Mat img_color(width,height,CV_8UC3);;
        for(int i=0; i<width; i++)
        {
                for(int j=0; j<height; j++)
                {
                        img_color.at<Vec3b>(i, j).val[0] = msg->data[i][j][0];
                        img_color.at<Vec3b>(i, j).val[1] = msg->data[i][j][1];
                        img_color.at<Vec3b>(i, j).val[2] = msg->data[i][j][2];
                }
        }
    system_clock::time_point tp = system_clock::now();
    system_clock::duration dtn = tp.time_since_epoch();
    cout << dtn.count() << endl;
    bool check = imwrite("/home/prithvidevkv/received/Out_" + to_string(dtn.count()) + "_" + std::to_string(msg->ID)+".jpg", img_color);

    }
};

int main(int argc, char **argv)
{
    lcm::LCM lcm;

    if (!lcm.good())
        return 1;

    Handler handlerObject;
    lcm.subscribe("image_command_FRST", &Handler::handleMessage, &handlerObject);

    while (0 == lcm.handle()) {
	printf("test!\n");
        // Do nothing
    }

    return 0;
}
