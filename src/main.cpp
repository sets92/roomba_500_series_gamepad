#include "ros/ros.h"
#include "roomba_500_series_gamepad/roomba_gamepad.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "roomba_500_series_gamepad_node");
  
  RoombaGamepad test;

  ros::spin();
}
