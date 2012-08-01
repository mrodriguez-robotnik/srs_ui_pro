/*
	Interactive Marker Server to move the COB base controller
*/

#include <ros/ros.h>
#include <interactive_markers/interactive_marker_server.h>
#include <interactive_markers/menu_handler.h>
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <string.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <tf/tf.h>

using namespace visualization_msgs;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class CobGotoMarkerServer
{
  public:
    	CobGotoMarkerServer(): nh("~"), server("srs_ui_pro/goto_im"),  ac("/move_base", true){
		
		
		createInteractiveMarkers();
	}
    
    	void processFeedback(const InteractiveMarkerFeedbackConstPtr &feedback );			// callback for interactive feedback 
  private:
	void createInteractiveMarkers();
	void SendGoal(move_base_msgs::MoveBaseGoal order);
	void ResultCB(const actionlib::SimpleClientGoalState& state, const move_base_msgs::MoveBaseResultConstPtr& result);
	void FeedBackCB(const move_base_msgs::MoveBaseFeedbackConstPtr& feedback);
	void SimpleActiveCB();
	Marker MakeBox( InteractiveMarker &msg );

	ros::NodeHandle nh;
	ros::Publisher vel_pub;					// Publisher -> base motion
	interactive_markers::InteractiveMarkerServer server;	// IM SERVER
	interactive_markers::MenuHandler menu_handler;		
	interactive_markers::MenuHandler::EntryHandle sub_menu_handle;		
	MoveBaseClient ac;					//ACTIONCLIENT TO MOVE THE BASE
};


void CobGotoMarkerServer::SendGoal(move_base_msgs::MoveBaseGoal order)
{
	move_base_msgs::MoveBaseGoal goal;
	goal = order;
	
	while(!ac.waitForServer(ros::Duration(5.0))){
		ROS_INFO("CobGotoMarkerServer:: Waiting for the move_base action server to come up");
	}

	// Need boost::bind to pass in the 'this' pointer
	ac.sendGoal(goal,
		boost::bind(&CobGotoMarkerServer::ResultCB, this, _1, _2),

		boost::bind(&CobGotoMarkerServer::SimpleActiveCB, this),
		boost::bind(&CobGotoMarkerServer::FeedBackCB, this, _1));
	ROS_INFO("CobGotoMarkerServer::SendGoal: Goal sent");

}

void CobGotoMarkerServer::ResultCB(const actionlib::SimpleClientGoalState& state, const move_base_msgs::MoveBaseResultConstPtr& result)
{
	ROS_INFO("CobGotoMarkerServer::ResultCB: Finished in state [%s]", state.toString().c_str());
	//ROS_INFO("Answer: %i", result->sequence.back());
	//ros::shutdown();
}

void CobGotoMarkerServer::FeedBackCB(const move_base_msgs::MoveBaseFeedbackConstPtr& feedback)
{
	//ROS_INFO("CobGotoMarkerServer::FeedBackCB: Feedback received: (x,y,z, w) = (%.2lf, %.2lf, %.2lf, %.2lf)", feedback->base_position.pose.position.x, 
	//	feedback->base_position.pose.position.y, feedback->base_position.pose.position.z, feedback->base_position.pose.orientation.w);
	//ROS_INFO("Answer: %i", result->sequence.back());
}

void CobGotoMarkerServer::SimpleActiveCB()
{
	ROS_INFO("CobGotoMarkerServer::SimpleActiveCB: Simple callback");
}

void CobGotoMarkerServer::processFeedback(
    const InteractiveMarkerFeedbackConstPtr &feedback )
{
	// Handle angular change (yaw is the only direction in which you can rotate)
	double yaw = tf::getYaw(feedback->pose.orientation);

	geometry_msgs::Twist vel;
	
	// Make the marker snap back to turtlebot
	//server.setPose("cob_base_marker", geometry_msgs::Pose());

	std::ostringstream s;
	/*s << "Feedback from marker '" << feedback->marker_name << "' "
	<< " / control '" << feedback->control_name << "'";

	std::ostringstream mouse_point_ss;
	if( feedback->mouse_point_valid )
	{
		mouse_point_ss << " at " << feedback->mouse_point.x
			   << ", " << feedback->mouse_point.y
			   << ", " << feedback->mouse_point.z
			   << " in frame " << feedback->header.frame_id;
	}*/

	switch ( feedback->event_type )
	{
		case visualization_msgs::InteractiveMarkerFeedback::BUTTON_CLICK:
			//ROS_INFO_STREAM( s.str() << ": button click" << mouse_point_ss.str() << "." );
		break;

		case visualization_msgs::InteractiveMarkerFeedback::MENU_SELECT:
			//ROS_INFO_STREAM( s.str() << ": menu item " << feedback->menu_entry_id << " clicked" << mouse_point_ss.str() << "." );
			if(feedback->menu_entry_id == 1){
				ROS_INFO_STREAM( s.str() << ": pose changed"
				<< "\nNext position = "
				<< feedback->pose.position.x
				<< ", " << feedback->pose.position.y
				<< ", " << feedback->pose.position.z
				<< "\norientation = "
				<< feedback->pose.orientation.w
				<< ", " << feedback->pose.orientation.x
				<< ", " << feedback->pose.orientation.y
				<< ", " << feedback->pose.orientation.z);
				/*<< "\nframe: " << feedback->header.frame_id
				<< " time: " << feedback->header.stamp.sec << "sec, "
				<< feedback->header.stamp.nsec << " nsec" );*/

				move_base_msgs::MoveBaseGoal goal;

				//we'll send a goal to the robot to go to the interactive marker pose
				goal.target_pose.header.frame_id = "/base_link";
				goal.target_pose.header.stamp = ros::Time::now();
				goal.target_pose.pose.position = feedback->pose.position;
				goal.target_pose.pose.orientation.x =  goal.target_pose.pose.orientation.y = goal.target_pose.pose.orientation.z = 0;
				goal.target_pose.pose.orientation.w = 0.0;

				//goal.target_pose.pose.position.y = feedback->pose.position.y;
				//goal.target_pose.pose.orientation.w = feedback->pose.orientation.w;
	
				
				SendGoal(goal);
			
			}
		break;

		case visualization_msgs::InteractiveMarkerFeedback::POSE_UPDATE:
			/*ROS_INFO_STREAM( s.str() << ": pose changed"
			  << "\nposition = "
			  << feedback->pose.position.x
			  << ", " << feedback->pose.position.y
			  << ", " << feedback->pose.position.z
			  << "\norientation = "
			  << feedback->pose.orientation.w
			  << ", " << feedback->pose.orientation.x
			  << ", " << feedback->pose.orientation.y
			  << ", " << feedback->pose.orientation.z
			  << "\nframe: " << feedback->header.frame_id
			  << " time: " << feedback->header.stamp.sec << "sec, "
			  << feedback->header.stamp.nsec << " nsec" );*/
		break;

		case visualization_msgs::InteractiveMarkerFeedback::MOUSE_DOWN:
			//ROS_INFO_STREAM( s.str() << ": mouse down" << mouse_point_ss.str() << "." );
		break;

		case visualization_msgs::InteractiveMarkerFeedback::MOUSE_UP:
			//ROS_INFO_STREAM( s.str() << ": mouse up" << mouse_point_ss.str() << "." );
		break;
	}

	server.applyChanges();
}

Marker CobGotoMarkerServer::MakeBox( InteractiveMarker &msg )
{
	Marker marker;

	marker.type = Marker::CUBE;
	marker.scale.x = 1.0;
	marker.scale.y = 1.0;
	marker.scale.z = 1.0;
	marker.color.r = 0.5;
	marker.color.g = 0.5;
	marker.color.b = 0.5;
	marker.color.a = 1.0;

	return marker;
}

void CobGotoMarkerServer::createInteractiveMarkers()
{ 
	// create an interactive marker for our server
	InteractiveMarker int_marker;
	int_marker.header.frame_id = "/map";
	int_marker.name = "goto_im";
	int_marker.description = "Move the COB-base (GOTO)";
	
	// Entry number 1
	menu_handler.insert( "Let's go!", boost::bind( &CobGotoMarkerServer::processFeedback, this, _1 ) );
	// Entry number 2	
	menu_handler.insert( "To be continued...", boost::bind( &CobGotoMarkerServer::processFeedback, this, _1 ) );
	/*sub_menu_handle = menu_handler.insert( "Submenu" );
	menu_handler.insert( sub_menu_handle, "First Entry", boost::bind( &CobGotoMarkerServer::processFeedback, this, _1 ) );
	menu_handler.insert( sub_menu_handle, "Second Entry", boost::bind( &CobGotoMarkerServer::processFeedback, this, _1 ) );
*/
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

	// make one control using default visuals
	control.interaction_mode = InteractiveMarkerControl::MENU;
	control.description="Go to there";
	control.name = "GoTo";
	int_marker.controls.push_back(control);

	// make one control showing a box
	Marker marker = MakeBox( int_marker );
	control.markers.push_back( marker );
	control.always_visible = true;
	int_marker.controls.push_back(control);

  
	server.insert(int_marker, boost::bind( &CobGotoMarkerServer::processFeedback, this, _1 ));

	server.applyChanges();
	menu_handler.apply( server, int_marker.name );
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "srs_ui_pro_goto_im");
	CobGotoMarkerServer cob_base_marker_server;
	ros::Rate loop_rate(10);
	
	while (ros::ok())
  	{	
		ros::spinOnce();

    		loop_rate.sleep();
	}
}
