#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <sstream>
#include <turtlesim/Spawn.h>
#include <turtlesim/Kill.h>
#include <string>
#include <sstream>

using namespace::std;

void test(const turtlesim::Pose::ConstPtr& msg){
	ROS_INFO("X: %f,  Y: %f", msg->x, msg->y);
}

int main(int argc, char **argv){

   ros::init(argc,argv,"hw4");

   ros::NodeHandle n;

   // <turtlesim::Spawn> <= Container type--  Has float32 x, float32 y, name
   // Topic: "spawn"
   // ros::ServiceClient client = n.serviceClient<turtlesim::Spawn>("spawn");

	turtlesim::Pose msg;	//  Defines the message obj
/*
	ros::Publisher turtle1pub = n.advertise<turtlesim::Pose>("/turtle1/pose", 100);
	while(true){
		msg.x = 0.0;
		msg.y = 0.0;
		msg.linear_velocity = 1.0;
		msg.angular_velocity = 0.0;

		turtle1pub.publish(msg);
		loop_rate.sleep();
	}
*/
	stringstream tname;
	
	ros::Rate loop_rate(2);
	// ros::Subscriber turtSub = n.subscribe<turtlesim::Pose>(tname.str(), 100, &test);

	int turts = 10;
	ros::Subscriber Tturts[turts];

	for(int i = 0; i < turts; i ++ ){
		tname.clear();
		tname.str("");
		tname << "/T" << i+1 << "/pose";
		//Tturts[i] = n.subscribe<turtlesim::Pose>(tname.str(), 100, &test);
		string name = tname.str();
		turtlesim::Pose msg;
		try{
			msg = *(ros::topic::waitForMessage<turtlesim::Pose>(name, ros::Duration(2)));
		}
		catch (int e){
			ROS_INFO("COULDNT FIND THAT TURT");

		}
		ROS_INFO("X: %f,  Y: %f", msg.x, msg.y);
	}

   return 0;
}
