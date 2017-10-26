#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <sstream>
#include <turtlesim/Spawn.h>
#include <turtlesim/Kill.h>
int main(int argc, char **argv){

   ros::init(argc,argv,"hw4");

   ros::NodeHandle n;

   // <turtlesim::Spawn> <= Container type--  Has float32 x, float32 y, name
   // Topic: "spawn"
   ros::ServiceClient client = n.serviceClient<turtlesim::Spawn>("spawn");

/*
   // Service object
   turtlesim::Spawn srv;

   srv.request.x= 0;
   srv.request.y= 0;

   if (client.call(srv)){
   	ROS_INFO_STREAM(srv.response);
   }

   else{
	   //ROS_ERROR("Failed to call");
	   return 1;
   }    
*/

	turtlesim::Pose msg;	//  Defines the message obj
	ros::Publisher turtle1pub = n.advertise<turtlesim::Pose>("/turtle1/pose", 100);
	while(true){
	ros::Rate loop_rate(2);
	msg.x = 0.0;
	msg.y = 0.0;
	msg.theta = 0.0;
	msg.linear_velocity = 0.0;
	msg.angular_velocity = 0.0;

	turtle1pub.publish(msg);
	loop_rate.sleep();
}

   return 0;
}
