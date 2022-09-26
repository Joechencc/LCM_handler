#ifndef SENDER_LCM_H
#define SENDER_LCM_H

#include <lcm/lcm-cpp.hpp>
#include "spi_command_t.hpp"
#include "spi_data_t.hpp"
#include "pcl_type.hpp"

class Handler {
  public:
    ~Handler() {}
    void handleMessage(const lcm::ReceiveBuffer *rbuf, const std::string &chan,
                       const image_data_t *msg)
    {
        printf("Received message on channel \"%s\":\n", chan.c_str());
        printf("  q_des_abad   = %f %f %f %f \n", (float) msg->data[0][0][0]);
    }
};



#endif  // FSM_STATE_BYPASS_H

