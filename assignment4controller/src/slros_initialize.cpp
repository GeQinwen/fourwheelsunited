#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "assignment4controller";

// For Block assignment4controller/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_assignment4controller_std_msgs_Float64> Sub_assignment4controller_207;

// For Block assignment4controller/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_assignment4controller_std_msgs_Float64> Sub_assignment4controller_208;

// For Block assignment4controller/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_assignment4controller_std_msgs_Float64> Sub_assignment4controller_209;

// For Block assignment4controller/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_assignment4controller_std_msgs_Float64> Pub_assignment4controller_212;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

