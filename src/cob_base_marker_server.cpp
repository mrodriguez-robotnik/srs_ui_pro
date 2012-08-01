/*
	Interactive Marker Server to move the COB base controller
*/
#include <ros/ros.h>
#include <interactive_markers/interactive_marker_server.h>
//#include <string.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <srs_ui_pro/BaseMarkerScale.h>
#include <tf/tf.h>

using namespace visualization_msgs;

class CobBaseMarkerServer
{
  public:
    	CobBaseMarkerServer(): nh("~"), server("srs_ui_pro/base_im"){
		std::string cmd_vel_topic;

		nh.param<std::string>("cmd_vel_topic", cmd_vel_topic, "/base_controller/command");
		nh.param<double>("linear_scale", linear_scale, 0.1);
		nh.param<double>("angular_scale", angular_scale, 0.1);

		vel_pub = nh.advertise<geometry_msgs::Twist>(cmd_vel_topic, 1);
		scale_sub = nh.subscribe("/srs_ui_pro/base_im/scale", 1000, &CobBaseMarkerServer::scaleCallback, this);
		scale_pub = nh.advertise<srs_ui_pro::BaseMarkerScale>("/srs_ui_pro/base_im/scale_state", 1);
		createInteractiveMarkers();
	}
    
    	void processFeedback(const InteractiveMarkerFeedbackConstPtr &feedback );			// callback for interactive feedback 
	void scaleCallback(const srs_ui_pro::BaseMarkerScale::ConstPtr& msg);	// Callback for receiving new scale value
  	srs_ui_pro::BaseMarkerScale GetScale();				// Returns the current scale 
	void PublishScale();										// Publish the current Scale
  private:
	void createInteractiveMarkers();

	ros::NodeHandle nh;
	ros::Publisher vel_pub;	// Publisher -> base motion
	interactive_markers::InteractiveMarkerServer server;
	ros::Subscriber scale_sub;	// Suscriber -> velocity scale
	ros::Publisher	scale_pub;	// Publisher -> current scale
	double linear_scale;
	double angular_scale;
};


void CobBaseMarkerServer::scaleCallback(const srs_ui_pro::BaseMarkerScale::ConstPtr& msg)
{
	// New values
	this->linear_scale = msg->linear_scale;
	this->angular_scale = msg->angular_scale;
}

//! Returns the current scale
srs_ui_pro::BaseMarkerScale CobBaseMarkerServer::GetScale(){
	srs_ui_pro::BaseMarkerScale bms;
	bms.linear_scale = this->linear_scale;
	bms.angular_scale = this->angular_scale;

	return bms;
}

void CobBaseMarkerServer::processFeedback(
    const InteractiveMarkerFeedbackConstPtr &feedback )
{
	// Handle angular change (yaw is the only direction in which you can rotate)
	double yaw = tf::getYaw(feedback->pose.orientation);

	geometry_msgs::Twist vel;
	vel.angular.z = angular_scale*yaw;
	vel.linear.x = linear_scale*feedback->pose.position.x;
	vel.linear.y = linear_scale*feedback->pose.position.y;
	//ROS_DEBUG(" CobBaseMarkerServer::processFeedback: Sending vel angular %.3lf, vel linear x = %.3lf, y = %.3lf", vel.angular.z, vel.linear.x, vel.linear.y);
	vel_pub.publish(vel);    

	// Make the marker snap back to turtlebot
	server.setPose("cob_base_marker", geometry_msgs::Pose());

	server.applyChanges();
}

void CobBaseMarkerServer::createInteractiveMarkers()
{ 
	// create an interactive marker for our server
	InteractiveMarker int_marker;
	int_marker.header.frame_id = "/base_link";
	int_marker.name = "base_im";
	int_marker.description = "Move the COB-base";

	InteractiveMarkerControl control;

	control.orientation_mode = InteractiveMarkerControl::FIXED;
	control.orientation.w = 1;
	control.orientation.x = 1;
	control.orientation.y = 0;
	control.orientation.z = 0;
	control.name = "move_x";
	control.interaction_mode = InteractiveMarkerControl::MOVE_AXIS;
	int_marker.controls.push_back(control);

	control.orientation.w = 1;
	control.orientation.x = 0;
	control.orientation.y = 1;
	control.orientation.z = 0;
	control.name = "rotate_z";
	control.interaction_mode = InteractiveMarkerControl::MOVE_ROTATE;
	int_marker.controls.push_back(control);

	control.orientation.w = 1;
	control.orientation.x = 0;
	control.orientation.y = 0;
	control.orientation.z = 1;
	control.name = "move_y";
	control.interaction_mode = InteractiveMarkerControl::MOVE_AXIS;
	int_marker.controls.push_back(control);

  
	server.insert(int_marker, boost::bind( &CobBaseMarkerServer::processFeedback, this, _1 ));

	server.applyChanges();
}

//! publishes the current scale through the publisher
void CobBaseMarkerServer::PublishScale(){
	srs_ui_pro::BaseMarkerScale bms;
	bms.linear_scale = this->linear_scale;
	bms.angular_scale = this->angular_scale;
	// Publishes the current scale
	scale_pub.publish(bms); 
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "srs_ui_pro_base_im");
	CobBaseMarkerServer cob_base_marker_server;
	ros::Rate loop_rate(10);
	
	while (ros::ok())
  	{	
		// publishes the current scale
		cob_base_marker_server.PublishScale();
		ros::spinOnce();

    		loop_rate.sleep();
	}
}
