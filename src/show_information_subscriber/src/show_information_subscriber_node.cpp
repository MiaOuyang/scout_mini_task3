#include "ros/ros.h"
#include "show_information/status.h"
#include <std_msgs/String.h>

void callback(const show_information::status::ConstPtr& msg){
    std_msgs::String lmode;
    if(msg->light_mode == 1)
        lmode.data= "呼吸模式";
    else if(msg->light_mode == 2)
        lmode.data = "灯光打开";
    else if(msg->light_mode == 3)
        lmode.data = "灯光关闭";
    else if(msg->light_mode == 4)
        lmode.data = "灯光编程模式";
    
    ROS_INFO("灯光模式：%s\n",lmode.data.c_str());
    ROS_INFO("电池电压：%.2f\n",msg->battery_voltage);
    ROS_INFO("电机数量：%d\n",msg->motor_num);
    ROS_INFO("电机电流：%.2f\n",msg->motor_current);
    ROS_INFO("电机转速：%.2f\n",msg->motor_rpm);
    ROS_INFO("电机脉冲数：%d\n",msg->motor_pulses);
    ROS_INFO("电机温度：%.2f\n",msg->motor_temperature);
    ROS_INFO("驱动器电压：%.2f\n",msg->driver_voltage);
    ROS_INFO("驱动器状态：%d\n",msg->driver_state);
    ROS_INFO("驱动器温度：%.2f\n",msg->driver_temperature);
    ROS_INFO("线速度=%.2f,角速度=%.2f\n",
        msg->linear,msg->angular
    );
    ROS_INFO("------------------------------");
}

int main(int argc, char **argv)
{
    setlocale(LC_CTYPE, "zh_CN.utf8");

    ros::init(argc, argv, "car_status_node");    // 初始化节点

    ros::NodeHandle nh;
  
    ros::Subscriber sub = nh.subscribe<show_information::status>("/scout_status", 10, callback);   // 创建 Subscriber，订阅 /scout_status 主题

    ros::spin();    // 持续等待消息

    return 0;
}