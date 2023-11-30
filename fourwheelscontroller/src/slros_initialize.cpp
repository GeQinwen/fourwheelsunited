#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "fourwheelscontroller";

// For Block fourwheelscontroller/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_fourwheelscontroller_std_msgs_Float64> Sub_fourwheelscontroller_11;

// For Block fourwheelscontroller/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_fourwheelscontroller_std_msgs_Float64> Sub_fourwheelscontroller_12;

// For Block fourwheelscontroller/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_fourwheelscontroller_std_msgs_Float64> Pub_fourwheelscontroller_10;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

