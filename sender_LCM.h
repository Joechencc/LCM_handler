#ifndef SENDER_LCM_H
#define SENDER_LCM_H

#include <lcm/lcm-cpp.hpp>
#include "spi_command_t.hpp"
#include "spi_data_t.hpp"

class Handler {
  public:
    ~Handler() {}
    void handleMessage(const lcm::ReceiveBuffer *rbuf, const std::string &chan,
                       const spi_data_t *msg)
    {
        printf("Received message on channel \"%s\":\n", chan.c_str());
        printf("  q_des_abad   = %f %f %f %f \n", (float) msg->q_abad[0],(float) msg->q_abad[1],(float) msg->q_abad[2],(float) msg->q_abad[3]);
        printf("  q_hip   = %f %f %f %f \n", (float) msg->q_hip[0],(float) msg->q_hip[1],(float) msg->q_hip[2],(float) msg->q_hip[3]);
        printf("  q_knee   = %f %f %f %f \n", (float) msg->q_knee[0],(float) msg->q_knee[1],(float) msg->q_knee[2],(float) msg->q_knee[3]);
        printf("  qd_abad   = %f %f %f %f \n", (float) msg->qd_abad[0],(float) msg->qd_abad[1],(float) msg->qd_abad[2],(float) msg->qd_abad[3]);
        printf("  qd_hip   = %f %f %f %f \n", (float) msg->qd_hip[0],(float) msg->qd_hip[1],(float) msg->qd_hip[2],(float) msg->qd_hip[3]);
        printf("  qd_knee   = %f %f %f %f \n", (float) msg->qd_knee[0],(float) msg->qd_knee[1],(float) msg->qd_knee[2],(float) msg->qd_knee[3]);
        printf("  flags   = %lf %lf %lf %lf \n", (float) msg->flags[0],(float) msg->flags[1],(float) msg->flags[2],(float) msg->flags[3]);
        printf("  spi_driver_status   = %lf \n", (float) msg->spi_driver_status);
    }
};



#endif  // FSM_STATE_BYPASS_H

