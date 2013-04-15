#ifndef ROSINTERFACE_H
#define ROSINTERFACE_H

#define PROCESS_OK				 0
#define PROCESS_ERROR_FORK		-1
#define PROCESS_ERROR_EXEC		-2
#define PROCESS_ERROR_WAITING	-3
#define PROCESS_RUNNING			-4
#define PROCESS_ERRROR_KILL		-5


#include <ros/ros.h>
#include <ros/package.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Pose.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <sensor_msgs/JointState.h>
#include <kinematics_msgs/GetConstraintAwarePositionIK.h>
#include <diagnostic_msgs/DiagnosticArray.h>
#include <gazebo_msgs/GetWorldProperties.h>
#include <move_base_msgs/MoveBaseActionGoal.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib_msgs/GoalStatusArray.h>
#include <std_msgs/Bool.h>

#include <pr2_msgs/PowerState.h>
#include <pr2_msgs/AccessPoint.h>
#include <pr2_controllers_msgs/JointTrajectoryControllerState.h>
#include <cob_object_detection_msgs/DetectionArray.h>
#include <cob_object_detection_msgs/DetectObjects.h>
#include <cob_relayboard/EmergencyStopState.h>
#include <cob_srvs/Trigger.h>
#include <schunk_sdh/TactileSensor.h>

#include <srs_msgs/FeasibleGrasp.h>
#include <srs_decision_making_interface/srs_actionActionFeedback.h>     //#include <srs_decision_making/ExecutionActionFeedback.h>
#include <srs_decision_making_interface/srs_actionActionResult.h>
#include <srs_decision_making_interface/srs_actionAction.h>
#include <srs_grasping/GetDBGrasps.h>
#include <srs_grasping/GetFeasibleGrasps.h>
#include <srs_object_database_msgs/GetObjectId.h>
#include <srs_object_database_msgs/GetImg.h>
#include <srs_object_database_msgs/GetMesh.h>
#include <srs_ui_pro/GraspSimulator.h>
#include <srs_ui_pro/RequestEventMSG.h>
#include <srs_ui_pro/RequestEvent.h>
#include <srs_ui_pro/dm_serverActionFeedback.h>
#include <srs_ui_pro/dm_serverActionGoal.h>
#include <srs_ui_pro/srs_ui_proEcho.h>
#include <srs_ui_pro/ui_butAction.h>
#include <srs_ui_pro/ui_butGoal.h>
#include <srs_ui_pro/srs_ui_proEcho.h>
#include <srs_interaction_primitives/AddBoundingBox.h>
#include <srs_interaction_primitives/GetAllPrimitivesNames.h>
#include <srs_interaction_primitives/RemovePrimitive.h>
#include <srs_knowledge/GetObjectsOnMap.h>
#include <srs_knowledge/GetObjectsOnTray.h>
#include <srs_knowledge/GetWorkspaceOnMap.h>
#include <srs_knowledge/GetRoomsOnMap.h>
#include <srs_knowledge/GetPredefinedPoses.h>
#include <srs_knowledge/GetWorkspaceForObject.h>
#include <srs_msgs/SRSSpatialInfo.h>
#include <srs_assisted_arm_navigation_msgs/ManualArmManipAction.h>


#include <exception>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <wx/image.h>
#include <wx/mstream.h>
#include <wx/msgdlg.h>


//! Struct used for real time thread
struct thread_param{
	int prio;			// Thread priority level 0[min]-80[max]
	int clock;  		// CLOCK_MONOTONIC or CLOCK_REALTIME
};

//! struct to store main data for a thread
 struct thread_data{
    //! Priority and clock
    struct thread_param pthreadPar;
    //! Contains the desired frequency of the thread
    double dDesiredHz;
    //! Contains the real frequency of the thread
    double dRealHz;
    //! Contains the id of the control thread
    pthread_t pthreadId;
};

class ServiceUnavailable : public std::exception{
    protected:
        std::string messageM;

    public:
        ServiceUnavailable(std::string message) throw(){ setMessage(message); };
        virtual ~ServiceUnavailable() throw (){};

        virtual std::string getMessage(void) throw() { return messageM; }
        virtual void setMessage(std::string message) throw() { messageM = "[ROS ERROR]: Service " + std::string(message) + " unavailable.\n"; }
};

class ServiceCallFailed : public std::exception{
    protected:
        std::string messageM;

    public:
        ServiceCallFailed(std::string message) throw(){ setMessage(message); };
        virtual ~ServiceCallFailed() throw (){};

        virtual std::string getMessage(void) throw() { return messageM; }
        virtual void setMessage(std::string message) throw() { messageM = "[ROS ERROR]: The " + std::string(message) + " call has failed.\n"; }
};



class RosInterface
{
    friend void *AuxControlThread(void *threadParam);

    public:
        struct joint_values
        {
            std::string name;
            float position;
            float velocity;
            float effort;
        };

        struct tactil_data
        {
            std::vector<short int> m1;
            std::vector<short int> m2;
            std::vector<short int> m3;
            std::vector<short int> m4;
            std::vector<short int> m5;
            std::vector<short int> m6;
        };

        RosInterface();
        virtual ~RosInterface();
        static void init();

        void publish_status(int status, std::string fb);
        bool nodeExists(std::string node);
        void killNode(std::string node);
        int decision_making_actions(std::string action, std::string parameters, std::string json_parameters="NULL");
        std::string ui_but_server_actions(int action);
        std::vector<srs_msgs::DBGrasp> getGraspConfigurations(int object_id);
        std::vector<srs_msgs::FeasibleGrasp> getGraspsFromPosition(int object_id, geometry_msgs::Pose object_pose);
        bool GraspSimulator(int object_id, srs_msgs::FeasibleGrasp grasp_configuration, geometry_msgs::Pose object_pose);
        std::vector<srs_ui_pro::RequestEventMSG> getRequestEvents();
        std::vector<std::string> getGazeboModels();
        std::vector<std::string> get_objects_on_map();
        std::vector<std::string> get_objects_on_tray();
        std::vector<std::string> get_workspace_on_map();
        std::vector<srs_msgs::SRSSpatialInfo> get_workspace_on_map_info();
        std::vector<std::string> get_rooms_on_map();
        std::vector<std::string> get_predefined_poses();
        std::vector<std::string> get_workspace_for_object(std::string objectType);
        tactil_data getTactilSensorData();
        std::string getDiagnosticsMessage();
        std::string getMoveBaseStatus();
        std::string getDMStatusText();
        std::string getDMCurrentState();
        std::string getDMCurrentTask();
        std::string getDMCurrentTaskID();
        bool DM_ExcepcionalCase();
	std::string DM_ExcepcionalCaseInfo();
        int getDMCurrentStatus();
        int DM_InterventionRequired();
        std::string getMesh(int object_id);
        int getObjectId(std::string object_name);
        pr2_msgs::PowerState getPowerState();
        pr2_msgs::AccessPoint getWifiState();
        std::string getObjectName(int object_id);
        wxImage getObjectIMG(int object_id);
        wxImage getObjectIMG(std::string object_name);
        std::vector<wxImage> getAllDBImages();
        bool getEmergencyState();
        bool getScannerState();
        std::string toStringAll(RosInterface::joint_values *jv);
        joint_values * getJointValues(std::string component);
        geometry_msgs::Pose transformPose(geometry_msgs::PoseStamped p, std::string frame="/base_link");
        cob_object_detection_msgs::Detection Detect(std::string object_name);
        bool GraspIt(srs_msgs::FeasibleGrasp grasp);
        bool isGrasped();
        int howManyFingersHasTheGrasp();
        bool callIKSolver(std::vector<float> jnt_pos, const geometry_msgs::PoseStamped &pose, std::vector<float> &solution);
        bool baseIsMoving();
        void move(std::string component,std::vector<float> values);
        void IP_AddObject(std::string object_name, geometry_msgs::PoseStamped pose, geometry_msgs::Point point);
        std::vector<std::string> IP_GetNames();
        void IP_RemoveAllObjects();
        void IP_RemoveObject(std::string object_name);
        void startAssistedArm();
        std::string getLastGoalAssistedMsg();
        bool assistedFinished();


        void callback_gui_status(const srs_ui_pro::srs_ui_proEcho::ConstPtr &msg);
        void callback_arm_joint_states(const pr2_controllers_msgs::JointTrajectoryControllerState::ConstPtr &msg);
        void callback_joint_states(const sensor_msgs::JointState::ConstPtr &msg);
        void callback_diagnostic(const diagnostic_msgs::DiagnosticArray::ConstPtr &msg);
        void callback_emergency_stop_state(const cob_relayboard::EmergencyStopState::ConstPtr &msg);
        void callback_MoveBase(const actionlib_msgs::GoalStatusArray::ConstPtr &msg);
        void callback_dm_fb(const srs_decision_making_interface::srs_actionActionFeedback::ConstPtr &msg);
        void callback_dm_result(const srs_decision_making_interface::srs_actionActionResult::ConstPtr &msg);
        void callback_ts(const schunk_sdh::TactileSensor::ConstPtr &msg);
        void callback_power_state(const pr2_msgs::PowerState &msg);
        void callback_wifi_state(const pr2_msgs::AccessPoint &msg);
        void callback_grabbed(const std_msgs::Bool &msg);
        void callback_grabbed2(const std_msgs::Bool &msg);
        void callback_dm_server_fb(const srs_ui_pro::dm_serverActionFeedback::ConstPtr &msg);
        void callback_dm_server_goal(const srs_ui_pro::dm_serverActionGoal::ConstPtr &msg);



    protected:
        //! Contains data for the main thread
		thread_data threadData;

        ros::NodeHandle n;
        ros::ServiceClient detection_client;
        ros::ServiceClient gazebo_models_client;
        ros::ServiceClient getgraspconfigurations_client;
        ros::ServiceClient getgraspsfromposition_client;
        ros::ServiceClient ik_client;
        ros::ServiceClient baseIsMoving_client;
        ros::ServiceClient get_models_client;
        ros::ServiceClient get_img_client;
        ros::ServiceClient get_mesh_client;
        ros::ServiceClient simulator_client;
        ros::ServiceClient getrequestevents_client;
        ros::ServiceClient ip_add_object_client;
        ros::ServiceClient ip_get_all_primitives_names_client;
        ros::ServiceClient ip_remove_object_client;
        ros::ServiceClient get_objects_on_map_client;
        ros::ServiceClient get_objects_on_tray_client;
        ros::ServiceClient get_workspace_on_map_client;
        ros::ServiceClient get_rooms_on_map_client;
        ros::ServiceClient get_predefined_poses_client;
        ros::ServiceClient get_workspace_for_object_client;

        ros::Subscriber sub_arm_state;
        ros::Subscriber sub_joint_states;
        ros::Subscriber sub_odom;
        ros::Subscriber sub_diagnostic;
        ros::Subscriber sub_emergency_state_stop;
        ros::Subscriber sub_goto_status;
        ros::Subscriber sub_dm_fb;
        ros::Subscriber sub_dm_result;
        ros::Subscriber sub_ts;
        ros::Subscriber sub_power_state;
        ros::Subscriber sub_wifi_state;
        ros::Subscriber sub_grabbed;
        ros::Subscriber sub_grabbed2;
        ros::Subscriber sub_dm_server_feedback;
        ros::Subscriber sub_dm_server_goal;
        ros::Subscriber sub_ui_pro;

        actionlib::SimpleActionClient<srs_decision_making_interface::srs_actionAction>* dm_client;
        actionlib::SimpleActionClient<srs_ui_pro::ui_butAction>* ui_but_client;

        //ros::Subscriber sub_sdh_controller;    // Suscriber
        //ros::Publisher pub_sdh_controller;     // publisher
        ros::Publisher srs_ui_pro_pub;

    private:

        void ControlThread();
        int Start();
        void initializeVariables();
        void initTopics();
        void initServices();
        void initActionServers();
        void serviceAvailable(ros::ServiceClient sc);
        void serviceCall(ros::ServiceClient sc, bool response);


        std::string array_to_string(std::vector<unsigned char> int_array);
        joint_values *joints;

        //float odom_position[3];
        //float odom_orientation[4];

        joint_values arm_joints[7];
        joint_values sdh_joints[7];
        joint_values torso_joints[3];
        joint_values tray_joints[1];
        joint_values head_joints[1];

        tactil_data ts_values;
        bool grabbed, cylinder_grabbed;
        pr2_msgs::PowerState power_state;
        pr2_msgs::AccessPoint wifi_state;

        std::vector<std::string> gazebo_models;
        std::string diagnostics_message;
        std::string move_base_status_message;
        std::string dm_status_text;
        std::string dm_current_state;
        int dm_current_status;
        bool dm_solution_required;
        int dm_exceptional_case_id;
        std::string dm_goal_id;
        bool emergency_button_stop_state;
        bool scanner_stop_state;
        std::string dm_current_task, dm_current_task_id;
        std::string last_goal;
        bool dm_server_event;
        std::string dm_server_event_info;
        bool gui_assisted_finish;
};

#endif // ROSINTERFACE_H
