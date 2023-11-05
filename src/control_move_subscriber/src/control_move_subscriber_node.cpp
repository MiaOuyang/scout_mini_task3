#include "ros/ros.h"
#include "ugv_sdk/scout/scout_base.hpp"
#include <geometry_msgs/Twist.h>

using namespace westonrobot;

ScoutBase scout;

void callback(const geometry_msgs::Twist::ConstPtr& msg){
        scout.SetMotionCommand(msg->linear.x, msg->angular.z ); 
}

int main(int argc, char **argv)
{
    int32_t baud_rate = 0;

    scout.Connect("can0", baud_rate);
    scout.EnableCommandedMode();
    
    ros::init(argc, argv, "turtle_receive_node");    // 初始化节点
    ros::NodeHandle nh;
  
    ros::Subscriber sub = nh.subscribe<geometry_msgs::Twist>("/cmd_vel", 10, callback);   // 创建 Subscriber，订阅 /cmd_vel 主题

    ros::spin();    // 持续等待消息

    return 0;
}
