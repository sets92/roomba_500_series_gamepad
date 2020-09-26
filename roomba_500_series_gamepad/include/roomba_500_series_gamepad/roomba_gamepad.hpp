#include "ros/ros.h"
#include "sensor_msgs/Joy.h"


class RoombaGamepad
{
  public:
    RoombaGamepad();

  private:
    ros::NodeHandle node_handle_;
    ros::Publisher velocity_publisher_;
    ros::Subscriber joy_subscriber_;

    int translation_speed_axis_;
    int rotational_speed_axis_;

    double translational_speed_scaling_factor_;
    double rotational_speed_scaling_factor_;

    std::string command_topic_name_;

    void joyCallback(const sensor_msgs::Joy::ConstPtr& msg);
};