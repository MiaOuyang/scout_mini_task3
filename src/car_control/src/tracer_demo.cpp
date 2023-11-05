/*
 * demo_tracer_can.cpp
 *
 * Created on: Jun 12, 2019 05:03
 * Description:
 *
 * Copyright (c) 2019 Ruixiang Du (rdu)
 */

#include "ugv_sdk/tracer/tracer_base.hpp"
#include <string>

using namespace westonrobot;

int main(int argc, char **argv) {
  std::string device_name;
  int32_t baud_rate = 0;

  if (argc == 2) {
    device_name = {argv[1]};
    std::cout << "Specified CAN: " << device_name << std::endl;
  } else {
    std::cout << "Usage: app_tracer_demo <interface>" << std::endl
              << "Example 1: ./app_tracer_demo can0" << std::endl;
    return -1;
  }

  TracerBase tracer;
  tracer.Connect(device_name);

  tracer.EnableCommandedMode();
  //   tracer.DisableTimeout();

  while (true) {

    auto state = tracer.GetTracerState(); //获取小车状态

    std::string lmode;
    // 灯光
    if(state.front_light_state.mode == LIGHT_MODE_BREATH){
        lmode= "呼吸模式";
    }
    else if(state.front_light_state.mode == LIGHT_MODE_CONST_ON){
        lmode = "灯光打开";
    }
    else if(state.front_light_state.mode == LIGHT_MODE_CONST_OFF){
        lmode = "灯光关闭";
    }
    else if(state.front_light_state.mode == LIGHT_MODE_CUSTOM){
        lmode = "灯光编程模式";
    }

    std::cout << "-------------------------------" << std::endl;
    std::cout << "灯光模式： " << lmode << std::endl;
    std::cout << "电池电压： " << state.battery_voltage << std::endl;
    std::cout << "电机电流： " << state.actuator_states->motor_current << std::endl;
    std::cout << "电机转速： " << state.actuator_states->motor_rpm << std::endl;
    std::cout << "电机脉冲数： " << state.actuator_states->motor_pulses << std::endl;
    std::cout << "电机温度： " << state.actuator_states->motor_temperature << std::endl;
    std::cout << "驱动器电压： " << state.actuator_states->driver_voltage << std::endl;
    // std::cout << "驱动器状态： " << state.actuator_states->driver_state << std::endl;
    std::cout << "驱动器温度： " << state.actuator_states->driver_temperature << std::endl;
    std::cout << "线速度= " << state.linear_velocity << "角速度= " << state.angular_velocity << std::endl;
    std::cout << "-------------------------------" << std::endl;

    // usleep(20000);
    sleep(1);
  }

  return 0;
}
