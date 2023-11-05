#include <iostream>
#include <unistd.h>
#include <ros/ros.h>

# include "show_information/status.h"

#include "ugv_sdk/scout/scout_base.hpp" //使用小车上的sdk版本

using namespace westonrobot;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "scout_publisher");
    ros::NodeHandle nh;

    int32_t baud_rate = 0;

    ScoutBase scout;
    scout.Connect("can0", baud_rate);
    
    ros::Publisher status_pub = nh.advertise<show_information::status>("scout_status", 1);
    ros::Rate loop_rate(10);

    while(ros::ok()) 
     {

        auto state = scout.GetScoutState(); //获取小车状态
        show_information::status status_msg; //自定义的结构体

        // 灯光
        if(state.front_light_state.mode == LIGHT_MODE_BREATH){
            status_msg.light_mode = 1;
        }
        else if(state.front_light_state.mode == LIGHT_MODE_CONST_ON){
            status_msg.light_mode = 2;
        }
        else if(state.front_light_state.mode == LIGHT_MODE_CONST_OFF){
            status_msg.light_mode = 3;
        }
        else if(state.front_light_state.mode == LIGHT_MODE_CUSTOM){
            status_msg.light_mode = 4;
        }
        
        status_msg.battery_voltage = state.battery_voltage;            

        //电机
        status_msg.motor_num = state.motor_num;
        status_msg.driver_state=state.actuator_states->driver_state;
        status_msg.driver_temperature=state.actuator_states->driver_temperature;
        status_msg.motor_current=state.actuator_states->motor_current;
        status_msg.motor_rpm = state.actuator_states->motor_rpm;
        status_msg.motor_pulses = state.actuator_states->motor_pulses;
        status_msg.driver_voltage = state.actuator_states->driver_voltage;
        status_msg.motor_temperature = state.actuator_states->motor_temperature;

        //运动状态
        status_msg.linear = state.linear_velocity;
        status_msg.angular = state.angular_velocity;
        status_pub.publish(status_msg);
        ros::spinOnce();
        loop_rate.sleep();

    }

    return 0;
}
