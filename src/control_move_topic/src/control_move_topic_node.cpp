#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <termios.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "scout_control");
    ros::NodeHandle nh;

    // 创建一个Publisher，用于发布运动指令给Scout机器人
    ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    geometry_msgs::Twist twist_msg;

    ros::Rate loop_rate(50); // 发布频率为50Hz

    char ch;
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // 修改终端设置，禁用标准输入的缓存和回显

    while (ros::ok())
    {
        ros::spinOnce(); // 处理所有的回调函数，包括订阅消息的回调函数

        twist_msg.linear.x = 0.0;
        twist_msg.angular.z = 0.0;

        ch = getchar(); // 获取按键信息
        if (ch == 'w')
            twist_msg.linear.x = 0.2;
        else if (ch == 's')
            twist_msg.linear.x = -0.2;
        else if (ch == 'a')
            twist_msg.angular.z = 0.2;
        else if (ch == 'd')
            twist_msg.angular.z = -0.2;

        cmd_vel_pub.publish(twist_msg);
        loop_rate.sleep();
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // 恢复终端设置

    return 0;
}

