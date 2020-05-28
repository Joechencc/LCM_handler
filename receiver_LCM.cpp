// Run code with the following command
// g++ -o receiver_LCM receiver_LCM.cpp -llcm

#include <stdio.h>

#include <lcm/lcm-cpp.hpp>
#include "spi_data_t.hpp"
#include "spi_command_t.hpp"
#include <unistd.h>

class Handler {
  public:
    ~Handler() {}
    void handleMessage(const lcm::ReceiveBuffer *rbuf, const std::string &chan,
                       const spi_command_t *msg)
    {	
        printf("Received message on channel \"%s\":\n", chan.c_str());
        printf("  q_des_abad   = %f %f %f %f \n", (float) msg->q_des_abad[0],(float) msg->q_des_abad[1],(float) msg->q_des_abad[2],(float) msg->q_des_abad[3]);
        printf("  q_des_hip   = %f %f %f %f \n", (float) msg->q_des_hip[0],(float) msg->q_des_hip[1],(float) msg->q_des_hip[2],(float) msg->q_des_hip[3]);
        printf("  q_des_knee   = %f %f %f %f \n", (float) msg->q_des_knee[0],(float) msg->q_des_knee[1],(float) msg->q_des_knee[2],(float) msg->q_des_knee[3]);
        printf("  qd_des_abad   = %f %f %f %f \n", (float) msg->qd_des_abad[0],(float) msg->qd_des_abad[1],(float) msg->qd_des_abad[2],(float) msg->qd_des_abad[3]);
        printf("  qd_des_hip   = %f %f %f %f \n", (float) msg->qd_des_hip[0],(float) msg->qd_des_hip[1],(float) msg->qd_des_hip[2],(float) msg->qd_des_hip[3]);
        printf("  qd_des_knee   = %f %f %f %f \n", (float) msg->qd_des_knee[0],(float) msg->qd_des_knee[1],(float) msg->qd_des_knee[2],(float) msg->qd_des_knee[3]);
        printf("  kp_abad   = %f %f %f %f \n", (float) msg->kp_abad[0],(float) msg->kp_abad[1],(float) msg->kp_abad[2],(float) msg->kp_abad[3]);
        printf("  kp_hip   = %f %f %f %f \n", (float) msg->kp_hip[0],(float) msg->kp_hip[1],(float) msg->kp_hip[2],(float) msg->kp_hip[3]);
        printf("  kp_knee   = %f %f %f %f \n", (float) msg->kp_knee[0],(float) msg->kp_knee[1],(float) msg->kp_knee[2],(float) msg->kp_knee[3]);
        printf("  kd_abad   = %f %f %f %f \n", (float) msg->kd_abad[0],(float) msg->kd_abad[1],(float) msg->kd_abad[2],(float) msg->kd_abad[3]);
        printf("  kd_hip   = %f %f %f %f \n", (float) msg->kd_hip[0],(float) msg->kd_hip[1],(float) msg->kd_hip[2],(float) msg->kd_hip[3]);
        printf("  kd_knee   = %f %f %f %f \n", (float) msg->kd_knee[0],(float) msg->kd_knee[1],(float) msg->kd_knee[2],(float) msg->kd_knee[3]);
        printf("  tau_abad_ff   = %f %f %f %f \n", (float) msg->tau_abad_ff[0],(float) msg->tau_abad_ff[1],(float) msg->tau_abad_ff[2],(float) msg->tau_abad_ff[3]);
        printf("  tau_hip_ff   = %f %f %f %f \n", (float) msg->tau_hip_ff[0],(float) msg->tau_hip_ff[1],(float) msg->tau_hip_ff[2],(float) msg->tau_hip_ff[3]);
        printf("  tau_knee_ff   = %f %f %f %f \n", (float) msg->tau_knee_ff[0],(float) msg->tau_knee_ff[1],(float) msg->tau_knee_ff[2],(float) msg->tau_knee_ff[3]);
        printf("  flags   = %lf %lf %lf %lf \n", (float) msg->flags[0],(float) msg->flags[1],(float) msg->flags[2],(float) msg->flags[3]);

        spi_data_t my_data;
        my_data.q_abad[0] = 0.1;
        my_data.q_abad[1] = 0.2;
        my_data.q_abad[2] = 0.3;
        my_data.q_abad[3] = 0.4;

        my_data.q_hip[0] = 0.1;
        my_data.q_hip[1] = 0.2;
        my_data.q_hip[2] = 0.3;
        my_data.q_hip[3] = 0.4;

        my_data.q_knee[0] = 1;
        my_data.q_knee[1] = 0;
        my_data.q_knee[2] = 0;
        my_data.q_knee[3] = 0;

        my_data.qd_abad[0] = 0.2;
        my_data.qd_abad[1] = 0.2;
        my_data.qd_abad[2] = 0.3;
        my_data.qd_abad[3] = 0.1;

        my_data.qd_hip[0] = 0.2;
        my_data.qd_hip[1] = 0.2;
        my_data.qd_hip[2] = 0.3;
        my_data.qd_hip[3] = 0.1;

        my_data.qd_knee[0] = 0.2;
        my_data.qd_knee[1] = 0.2;
        my_data.qd_knee[2] = 0.3;
        my_data.qd_knee[3] = 0.1;
        
        my_data.flags[0] = 1;
        my_data.flags[1] = 1;
        my_data.flags[2] = 1;
        my_data.flags[3] = 1;
        
        lcm::LCM lcm;

        if (!lcm.good()){
            return;
        }

        my_data.spi_driver_status = 1;
        sleep(1);
        lcm.publish("spi_data", &my_data);

    }
};

int main(int argc, char **argv)
{
    lcm::LCM lcm;

    if (!lcm.good())
        return 1;

    Handler handlerObject;
    lcm.subscribe("spi_command_IHMC", &Handler::handleMessage, &handlerObject);

    while (0 == lcm.handle()) {
	printf("test!\n");
        // Do nothing
    }

    return 0;
}
