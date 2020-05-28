// run method 
// g++ -o sender_LCM sender_LCM.cpp -llcm


#include "sender_LCM.h"


int main(int argc, char **argv)
{   
    lcm::LCM *lcm = new lcm::LCM("udpm://239.255.76.67:7667?ttl=255");
    spi_command_t IHMC_data;
    IHMC_data.q_des_abad[0] = 0.1;
    IHMC_data.q_des_abad[1] = 0.2;
    IHMC_data.q_des_abad[2] = 0.3;
    IHMC_data.q_des_abad[3] = 0.4;

    IHMC_data.q_des_hip[0] = 0.1;
    IHMC_data.q_des_hip[1] = 0.2;
    IHMC_data.q_des_hip[2] = 0.3;
    IHMC_data.q_des_hip[3] = 0.4;

    IHMC_data.q_des_knee[0] = 1;
    IHMC_data.q_des_knee[1] = 0;
    IHMC_data.q_des_knee[2] = 0;
    IHMC_data.q_des_knee[3] = 0;

    IHMC_data.qd_des_abad[0] = 0.2;
    IHMC_data.qd_des_abad[1] = 0.2;
    IHMC_data.qd_des_abad[2] = 0.3;
    IHMC_data.qd_des_abad[3] = 0.1;

    IHMC_data.qd_des_hip[0] = 0.2;
    IHMC_data.qd_des_hip[1] = 0.2;
    IHMC_data.qd_des_hip[2] = 0.3;
    IHMC_data.qd_des_hip[3] = 0.1;

    IHMC_data.qd_des_knee[0] = 0.2;
    IHMC_data.qd_des_knee[1] = 0.2;
    IHMC_data.qd_des_knee[2] = 0.3;
    IHMC_data.qd_des_knee[3] = 0.1;

    IHMC_data.kp_abad[0] = 0.2;
    IHMC_data.kp_abad[1] = 0.2;
    IHMC_data.kp_abad[2] = 0.3;
    IHMC_data.kp_abad[3] = 0.1;

    IHMC_data.kp_hip[0] = 0.2;
    IHMC_data.kp_hip[1] = 0.2;
    IHMC_data.kp_hip[2] = 0.3;
    IHMC_data.kp_hip[3] = 0.1;

    IHMC_data.kp_knee[0] = 0.2;
    IHMC_data.kp_knee[1] = 0.2;
    IHMC_data.kp_knee[2] = 0.3;
    IHMC_data.kp_knee[3] = 0.1;

    IHMC_data.kd_abad[0] = 0.2;
    IHMC_data.kd_abad[1] = 0.2;
    IHMC_data.kd_abad[2] = 0.3;
    IHMC_data.kd_abad[3] = 0.1;

    IHMC_data.kd_abad[0] = 0.2;
    IHMC_data.kd_abad[1] = 0.2;
    IHMC_data.kd_abad[2] = 0.3;
    IHMC_data.kd_abad[3] = 0.1;

    IHMC_data.kd_knee[0] = 0.2;
    IHMC_data.kd_knee[1] = 0.2;
    IHMC_data.kd_knee[2] = 0.3;
    IHMC_data.kd_knee[3] = 0.1;

    IHMC_data.tau_abad_ff[0] = 0.2;
    IHMC_data.tau_abad_ff[1] = 0.2;
    IHMC_data.tau_abad_ff[2] = 0.3;
    IHMC_data.tau_abad_ff[3] = 0.1;

    IHMC_data.tau_hip_ff[0] = 0.2;
    IHMC_data.tau_hip_ff[1] = 0.2;
    IHMC_data.tau_hip_ff[2] = 0.3;
    IHMC_data.tau_hip_ff[3] = 0.1;

    IHMC_data.tau_knee_ff[0] = 0.2;
    IHMC_data.tau_knee_ff[1] = 0.2;
    IHMC_data.tau_knee_ff[2] = 0.3;
    IHMC_data.tau_knee_ff[3] = 0.1;

    IHMC_data.flags[0] = 1;
    IHMC_data.flags[1] = 0;
    IHMC_data.flags[2] = 0;
    IHMC_data.flags[3] = 0;
    if (!lcm->good())
        return 1;


    lcm->publish("spi_command_IHMC", &IHMC_data);

    Handler handlerObject;
    lcm->subscribe("spi_data", &Handler::handleMessage, &handlerObject);

    lcm->handleTimeout(1200);

    return 0;
}


