#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/JointState.h>
#include <trajectory_msgs/JointTrajectory.h>

typedef struct joint_values
{
	std::string name;
	float position;
	float velocity;
	float effort;
};

class CobUIProTeleop
{
public:
	CobUIProTeleop();

private:
	//! Callback called when joystick values are received
	void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
	//! Callback called when joints values are received
	void jointCallback(const sensor_msgs::JointState::ConstPtr &msg);

	ros::NodeHandle nh_;

	int linear_x_, linear_y_, angular_;
	double l_scale_, a_scale_;
	//! Publishers
	ros::Publisher vel_pub_, head_pub_, torso_pub_;
	//! Subscribers
	ros::Subscriber joy_sub_, joint_sub_;
	//! Name of the topic where it will be publishing the velocity (BASE)
	std::string cmd_topic_vel_, cmd_topic_vel_def_;
	//! Name of the topic for the HEAD
	std::string cmd_topic_head_, cmd_topic_head_def_;
	//! Name of the topic for the TORSO
	std::string cmd_topic_torso_, cmd_topic_torso_def_;
	//! Name of the topic for reading the joints values
	std::string cmd_topic_joints_, cmd_topic_joints_def_;
	//! Number of the DEADMAN button
	int dead_man_button_base_, dead_man_button_torso_head_;
	//! 
	int axis_head_, axis_torso_lower_neck_tilt_joint_, axis_torso_pan_joint_, axis_torso_upper_neck_tilt_joint_;
		
	
        joint_values arm_joints[7];
        joint_values sdh_joints[7];
        joint_values torso_joints[3];
        joint_values tray_joints[1];
        joint_values head_joints[1];

};


CobUIProTeleop::CobUIProTeleop():
  linear_x_(1), linear_y_(0),  angular_(2), dead_man_button_base_(5), dead_man_button_torso_head_(7), axis_torso_lower_neck_tilt_joint_(1), 
  axis_torso_pan_joint_(0), axis_torso_upper_neck_tilt_joint_(3), axis_head_(2)
{
	cmd_topic_vel_def_.assign("/base_controller/command");
	cmd_topic_head_def_.assign("/head_controller/command");
	cmd_topic_torso_def_.assign("/torso_controller/command");
	cmd_topic_joints_def_.assign("/joint_states");

	nh_.param("axis_linear_x", linear_x_, linear_x_);
	nh_.param("axis_linear_y", linear_y_, linear_y_);
	nh_.param("axis_angular", angular_, angular_);
	nh_.param("axis_head", axis_head_, axis_head_);
	nh_.param("axis_torso_lower_neck_tilt_joint_", axis_torso_lower_neck_tilt_joint_, axis_torso_lower_neck_tilt_joint_);
	nh_.param("axis_torso_pan_joint", axis_torso_pan_joint_,axis_torso_pan_joint_);
	nh_.param("axis_torso_upper_neck_tilt_joint", axis_torso_upper_neck_tilt_joint_, axis_torso_upper_neck_tilt_joint_);
	nh_.param("scale_angular", a_scale_, 0.5);
	nh_.param("scale_linear", l_scale_, 0.5);
	nh_.param("cmd_topic_vel", cmd_topic_vel_, cmd_topic_vel_def_);
	nh_.param("dead_man_button_base", dead_man_button_base_, dead_man_button_base_);
	nh_.param("dead_man_button_torso_head", dead_man_button_torso_head_, dead_man_button_torso_head_);
	nh_.param("cmd_topic_head", cmd_topic_head_, cmd_topic_head_def_);
	nh_.param("cmd_topic_torso", cmd_topic_torso_, cmd_topic_torso_def_);
	nh_.param("cmd_topic_joints", cmd_topic_joints_, cmd_topic_joints_def_);

	vel_pub_ = nh_.advertise<geometry_msgs::Twist>(cmd_topic_vel_, 1);
	
	head_pub_ = nh_.advertise<trajectory_msgs::JointTrajectory>(cmd_topic_head_, 1, true);
	torso_pub_ = nh_.advertise<trajectory_msgs::JointTrajectory>(cmd_topic_torso_, 1, true);

	joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &CobUIProTeleop::joyCallback, this);
	joint_sub_ = nh_.subscribe(cmd_topic_joints_, 1000, &CobUIProTeleop::jointCallback, this);
			
}

void CobUIProTeleop::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
	geometry_msgs::Twist vel;
	
	vel.angular.x = vel.angular.y =vel.angular.z = 	vel.linear.x = vel.linear.y = vel.linear.z = 0.0;

	if (joy->buttons[dead_man_button_base_] == 1) {
		vel.angular.x = (a_scale_*joy->axes[angular_]);
		vel.angular.y = (a_scale_*joy->axes[angular_]);
		vel.angular.z = (a_scale_*joy->axes[angular_]);
		vel.linear.x = l_scale_*joy->axes[linear_x_];
		vel.linear.y = l_scale_*joy->axes[linear_y_];
		ROS_INFO("Moving base");
		//vel.linear.z = l_scale_*joy->axes[linear_];
	}else if (joy->buttons[dead_man_button_torso_head_] == 1) {
		trajectory_msgs::JointTrajectory traj;
		traj.header.stamp = ros::Time::now()+ros::Duration(0.01);
		traj.points.resize(1);
		traj.points[0].time_from_start = ros::Duration(3.0);
		traj.joint_names.push_back("head_axis_joint");
            	traj.points[0].positions.push_back(a_scale_*joy->axes[axis_head_]);
            	traj.points[0].velocities.push_back(0.0);		
		head_pub_.publish(traj);

		/*trajectory_msgs::JointTrajectory traj2;
		traj2.joint_names.push_back("torso_lower_neck_tilt_joint");
            	traj2.joint_names.push_back("torso_pan_joint");
            	traj2.joint_names.push_back("torso_upper_neck_tilt_joint");
		
		traj2.points[0].positions.push_back(a_scale_*joy->axes[axis_torso_lower_neck_tilt_joint_]);
		traj2.points[0].velocities.push_back(0.0);
		traj2.points[0].positions.push_back(a_scale_*joy->axes[axis_torso_pan_joint_]);
		traj2.points[0].velocities.push_back(0.0);
		traj2.points[0].positions.push_back(a_scale_*joy->axes[axis_torso_upper_neck_tilt_joint_]);
		traj2.points[0].velocities.push_back(0.0);
	
		torso_pub_.publish(traj2);*/
		ROS_INFO("Moving Torso/Head");
	}	
	vel_pub_.publish(vel);
}

void CobUIProTeleop::jointCallback(const sensor_msgs::JointState::ConstPtr &msg)
{
    if (msg->position.size() > 8)
    {
        joint_values *joints = new joint_values[msg->position.size()];
        int arm_count, sdh_count, torso_count;
        arm_count=sdh_count=torso_count=0;

        for (unsigned int i=0; i<msg->position.size(); i++)
        {
            std::string joint_name = msg->name[i];
            if ((joint_name.substr(0,3)).compare("arm")==0)
            {                arm_joints[arm_count].name = msg->name[i];
                arm_joints[arm_count].position = msg->position[i];
                arm_joints[arm_count].velocity = msg->velocity[i];
                arm_count++;
            }
            else if (joint_name.compare("sdh_finger_21_joint")==0)
            {
                //None
            }
            else if ((joint_name.substr(0,3)).compare("sdh")==0)
            {
                sdh_joints[sdh_count].name = msg->name[i];
                sdh_joints[sdh_count].position = msg->position[i];
                sdh_joints[sdh_count].velocity = msg->velocity[i];
                sdh_count++;
            }
            else if (joint_name.compare("torso_tray_joint")==0)
            {
                tray_joints[0].name = msg->name[i];
                tray_joints[0].position = msg->position[i];
                tray_joints[0].velocity = msg->velocity[i];
            }
            else if ((joint_name.substr(0,5)).compare("torso")==0)
            {
                torso_joints[torso_count].name = msg->name[i];
                torso_joints[torso_count].position = msg->position[i];
                torso_joints[torso_count].velocity = msg->velocity[i];
                torso_count++;
            }
            else if ((joint_name.substr(0,4)).compare("head")==0)
            {
                head_joints[0].name = msg->name[i];
                head_joints[0].position = msg->position[i];
                head_joints[0].velocity = msg->velocity[i];
            }
            else
            {
            //joints[i].name = msg->name[i];
            //joints[i].position = msg->position[i];
            //joints[i].velocity = msg->velocity[i];
            //joints.effort.push_back(msg->effort[i]);
            }
        }
        //sub.shutdown();
	delete joints;
    }
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "teleop_uipro");
	CobUIProTeleop teleop_turtle;

	ros::spin();
}
