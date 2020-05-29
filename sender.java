import java.io.*;
import java.util.*;

import lcm.lcm.*;
import lcmtypes.spi_command_t;
import lcmtypes.spi_data_t;
import lcmtypes.MySubscriber;

public class sender
{   

    public static void main(String args[])
    {
        try {
            LCM lcm = new LCM("udpm://239.255.76.67:7667?ttl=255");

            spi_command_t IHMC_data = new spi_command_t();

            IHMC_data.q_des_abad[0] = -0.7558937f;
            IHMC_data.q_des_abad[1] = 0.54036045f;
            IHMC_data.q_des_abad[2] = -0.77305984f;
            IHMC_data.q_des_abad[3] = 0.6322956f;
        
            IHMC_data.q_des_hip[0] = -0.9971062f;
            IHMC_data.q_des_hip[1] = -1.2061545f;
            IHMC_data.q_des_hip[2] = -1.010981f;
            IHMC_data.q_des_hip[3] = -1.123135f;

            IHMC_data.q_des_knee[0] = 2.7059948f;
            IHMC_data.q_des_knee[1] = 2.7457256f;
            IHMC_data.q_des_knee[2] = 2.675049f;
            IHMC_data.q_des_knee[3] = 2.6993284f;

            IHMC_data.qd_des_abad[0] = -0.04762268f;
            IHMC_data.qd_des_abad[1] = -0.04762268f;
            IHMC_data.qd_des_abad[2] = 0.1111145f;
            IHMC_data.qd_des_abad[3] = -0.01587677f;

            IHMC_data.qd_des_hip[0] = 0.01587677f;
            IHMC_data.qd_des_hip[1] = -0.01587677f;
            IHMC_data.qd_des_hip[2] = -0.1111145f;
            IHMC_data.qd_des_hip[3] = 0.04762268f;

            IHMC_data.qd_des_knee[0] = -0.03061662f;
            IHMC_data.qd_des_knee[1] = 0.07143551f;
            IHMC_data.qd_des_knee[2] = -0.03061662f;
            IHMC_data.qd_des_knee[3] = -0.010207175f;

            // q_des_abad     = [ -0.7558937, 0.54036045, -0.77305984, 0.6322956 ]
            // q_hip     = [ -0.9971062, -1.2061545, -1.010981, -1.123135 ]
            // q_knee     = [ 2.7059948, 2.7457256, 2.675049, 2.6993284 ]
            // qd_abad     = [ -0.04762268, -0.04762268, 0.1111145, -0.01587677 ]
            // qd_hip     = [ 0.01587677, -0.01587677, -0.1111145, 0.04762268 ]
            // qd_knee     = [ -0.03061662, 0.07143551, -0.03061662, -0.010207175 ]
            // flags     = [ 0, 0, 0, 0 ]
            // spi_driver_status  =  -2102722560


            IHMC_data.kp_abad[0] = 5f;
            IHMC_data.kp_abad[1] = 5f;
            IHMC_data.kp_abad[2] = 5f;
            IHMC_data.kp_abad[3] = 5f;

            IHMC_data.kp_hip[0] = 5f;
            IHMC_data.kp_hip[1] = 5f;
            IHMC_data.kp_hip[2] = 5f;
            IHMC_data.kp_hip[3] = 5f;

            IHMC_data.kp_knee[0] = 5f;
            IHMC_data.kp_knee[1] = 5f;
            IHMC_data.kp_knee[2] = 5f;
            IHMC_data.kp_knee[3] = 5f;

            IHMC_data.kd_abad[0] = 0.1f;
            IHMC_data.kd_abad[1] = 0.1f;
            IHMC_data.kd_abad[2] = 0.1f;
            IHMC_data.kd_abad[3] = 0.1f;

            IHMC_data.kd_hip[0] = 0.1f;
            IHMC_data.kd_hip[1] = 0.1f;
            IHMC_data.kd_hip[2] = 0.1f;
            IHMC_data.kd_hip[3] = 0.1f;

            IHMC_data.kd_knee[0] = 0.1f;
            IHMC_data.kd_knee[1] = 0.1f;
            IHMC_data.kd_knee[2] = 0.1f;
            IHMC_data.kd_knee[3] = 0.1f;

            IHMC_data.tau_abad_ff[0] = 0.2f;
            IHMC_data.tau_abad_ff[1] = 0.2f;
            IHMC_data.tau_abad_ff[2] = 0.3f;
            IHMC_data.tau_abad_ff[3] = 0.1f;

            IHMC_data.tau_hip_ff[0] = 0.2f;
            IHMC_data.tau_hip_ff[1] = 0.2f;
            IHMC_data.tau_hip_ff[2] = 0.3f;
            IHMC_data.tau_hip_ff[3] = 0.1f;

            IHMC_data.tau_knee_ff[0] = 0.2f;
            IHMC_data.tau_knee_ff[1] = 0.2f;
            IHMC_data.tau_knee_ff[2] = 0.3f;
            IHMC_data.tau_knee_ff[3] = 0.1f;

            IHMC_data.flags[0] = 1;
            IHMC_data.flags[1] = 0;
            IHMC_data.flags[2] = 0;
            IHMC_data.flags[3] = 0;

            lcm.publish ("spi_command_IHMC", IHMC_data);
            Thread.sleep(2000);
            MySubscriber m = new MySubscriber();
            while(true){
                System.out.println("After two seconds, do you want to resend the command(Y) or stop(N)");
                Scanner input = new Scanner( System.in );
                String s;
                s=input.nextLine();
                if (s.equals("Y") || s.equals("y")){
                    lcm.publish ("spi_command_IHMC", IHMC_data);
                    Thread.sleep(2000);
                    continue;
                }
                else if(s.equals("N") || s.equals("n")){
                    break;
                }
                else{
                    System.out.println("Wrong Output!");
                }
            }
            
        } catch (Exception ex) {
            System.out.println("Exception: " + ex);
        }
        
        
    }
}
