#include "roomba_500_series_gamepad/roomba_gamepad.hpp"
#include <ros/console.h>
#include "geometry_msgs/Twist.h"

RoombaGamepad::RoombaGamepad() : 
  node_handle_(),
  translation_speed_axis_(1),
  translational_speed_scaling_factor_(1),
  rotational_speed_axis_(2),
  rotational_speed_scaling_factor_(1),
  command_topic_name_("command_topic")
{
  if (!node_handle_.getParam("translational_speed_axis", translation_speed_axis_))
  {
    ROS_INFO_STREAM("[RoombaGamepad]: Parameter translational_speed_axis not found using default value:" << translation_speed_axis_);
  }

  if (!node_handle_.getParam("translational_speed_scaling_factor", translational_speed_scaling_factor_))
  {
    ROS_INFO_STREAM("[RoombaGamepad]: Parameter translational_speed_scaling_factor not found  using default value:" << translational_speed_scaling_factor_);
  }

  if (!node_handle_.getParam("rotational_speed_axis", rotational_speed_axis_))
  {
    ROS_INFO_STREAM("[RoombaGamepad]: Parameter rotational_speed_axis not found using default value:" << rotational_speed_axis_);
  }

  if (!node_handle_.getParam("rotational_speed_scaling_factor", rotational_speed_scaling_factor_))
  {
    ROS_INFO_STREAM("[RoombaGamepad]: Parameter rotational_speed_scaling_factor not found using default value:" << rotational_speed_scaling_factor_);
  }

  if (!node_handle_.getParam("command_topic_name", command_topic_name_))
  {
    ROS_INFO_STREAM("[RoombaGamepad]: Parameter command_topic_name not found using default value:" << command_topic_name_);
  }

  joy_subscriber_ = node_handle_.subscribe("joy", 1000, &RoombaGamepad::joyCallback, this);
  velocity_publisher_ = node_handle_.advertise<geometry_msgs::Twist>(command_topic_name_, 1000);
}


void RoombaGamepad::joyCallback(const sensor_msgs::Joy::ConstPtr& msg)
{
  geometry_msgs::Twist twist_msg; 

  twist_msg.linear.x =  translational_speed_scaling_factor_ * msg->axes[translation_speed_axis_];

  twist_msg.angular.z = rotational_speed_scaling_factor_ * msg->axes[rotational_speed_axis_];

  velocity_publisher_.publish(twist_msg);
}


