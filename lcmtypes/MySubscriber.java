package lcmtypes;
import java.io.*;
import java.util.*;

import lcm.lcm.*;
import lcmtypes.spi_command_t;
import lcmtypes.spi_data_t;

public class MySubscriber implements LCMSubscriber
{
    LCM lcm;
    MessageAggregator message;

    public MySubscriber()
        throws IOException
    {
        this.lcm = new LCM("udpm://239.255.76.67:7667?ttl=255");
        this.message = new MessageAggregator();
        this.message.setMaxMessages(0);
        this.lcm.subscribe("spi_data", this);
    }

    public void messageReceived(LCM lcm, String channel, LCMDataInputStream ins)
    {
        System.out.println("Received message on channel " + channel);

        try {
            if (channel.equals("spi_data")) {
                spi_data_t msg = new spi_data_t(ins);

                System.out.println("  q_des_abad     = [ " + msg.q_abad[0] + ", " + msg.q_abad[1] + ", " + msg.q_abad[2] + ", " + msg.q_abad[3]+ " ]");
                System.out.println("  q_hip     = [ " + msg.q_hip[0] + ", " + msg.q_hip[1] + ", " + msg.q_hip[2] + ", " + msg.q_hip[3]+ " ]");
                System.out.println("  q_knee     = [ " + msg.q_knee[0] + ", " + msg.q_knee[1] + ", " + msg.q_knee[2] + ", " + msg.q_knee[3]+ " ]");
                System.out.println("  qd_abad     = [ " + msg.qd_abad[0] + ", " + msg.qd_abad[1] + ", " + msg.qd_abad[2] + ", " + msg.qd_abad[3]+ " ]");
                System.out.println("  qd_hip     = [ " + msg.qd_hip[0] + ", " + msg.qd_hip[1] + ", " + msg.qd_hip[2] + ", " + msg.qd_hip[3]+ " ]");
                System.out.println("  qd_knee     = [ " + msg.qd_knee[0] +  ", " + msg.qd_knee[1] + ", " + msg.qd_knee[2] + ", " + msg.qd_knee[3]+ " ]");
                System.out.println("  flags     = [ " + msg.flags[0] + ", " + msg.flags[1] + ", " + msg.flags[2] + ", " + msg.flags[3]+ " ]");
                System.out.println("  spi_driver_status  =  " + msg.spi_driver_status);       
                System.out.println("Do you want to resend the command(Y) or stop(N)!!  ");            
                // Scanner input = new Scanner( System.in );
                // String s;
                // s=input.nextLine();
                // if(s.equals("Y")){
                //     System.out.println(" Continue ");
                // }
                Thread.sleep(4000);
              
            }

        } catch (Exception ex) {
            System.out.println("Exception: " + ex);
        }
    }

}
