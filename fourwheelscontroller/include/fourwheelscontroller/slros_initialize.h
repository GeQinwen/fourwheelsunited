#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "fourwheelscontroller_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block fourwheelscontroller/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_fourwheelscontroller_std_msgs_Float64> Sub_fourwheelscontroller_11;

// For Block fourwheelscontroller/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_fourwheelscontroller_std_msgs_Float64> Sub_fourwheelscontroller_12;

// For Block fourwheelscontroller/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_fourwheelscontroller_std_msgs_Float64> Pub_fourwheelscontroller_10;

void slros_node_init(int argc, char** argv);

#endif
