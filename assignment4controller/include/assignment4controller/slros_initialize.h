#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "assignment4controller_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block assignment4controller/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_assignment4controller_std_msgs_Float64> Sub_assignment4controller_50;

// For Block assignment4controller/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_assignment4controller_std_msgs_Float64> Sub_assignment4controller_51;

// For Block assignment4controller/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_assignment4controller_std_msgs_Float64> Sub_assignment4controller_52;

// For Block assignment4controller/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_assignment4controller_std_msgs_Float64> Pub_assignment4controller_55;

void slros_node_init(int argc, char** argv);

#endif
