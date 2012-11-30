#include "RosInterface.h"

void *AuxControlThread(void *threadParam){
	RosInterface *ComponentThread = (RosInterface *)threadParam;
	ComponentThread->ControlThread();
    pthread_detach(pthread_self());
	return NULL;
}

RosInterface::RosInterface(){
    initializeVariables();
    initTopics();
    initServices();
    initActionServers();
    Start();
}

RosInterface::~RosInterface(){
    n.shutdown();
}

void RosInterface::ControlThread(){
    ros::spin();
}

void RosInterface::init(){
    int argc = 1;
    char *argv[1] = {(char*)"srs_ui_pro"};
    ros::init(argc, argv, "srs_ui_pro");
}

bool RosInterface::nodeExists(std::string n)
{
    ros::V_string nodes;
    ros::master::getNodes(nodes);
    for (int i=0; i<nodes.size(); i++)
        if (nodes[i].compare(n) == 0)
            return true;
    return false;
}

void RosInterface::killNode(std::string node)
{
    //Por alguna razón el programa casca cuando se mata un nodo.
    execlp("rosnode", "rosnode", "kill", node.c_str(), NULL);
}

int RosInterface::Start(){
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    if(pthread_create(&threadData.pthreadId, &attr, AuxControlThread, this) != 0)
    {
        ROS_ERROR("RosInterface::Start: Could not create ControlThread");

        pthread_attr_destroy(&attr);
        return -1;
    }
    pthread_attr_destroy(&attr);
    return 0;
}

void RosInterface::initializeVariables(){
    dm_exceptional_case_id = 0;
    dm_solution_required = dm_server_event = emergency_button_stop_state = scanner_stop_state = false;
    dm_current_task = dm_current_task_id = "";
}

void RosInterface::initServices(){
    detection_client = n.serviceClient<cob_object_detection_msgs::DetectObjects>("/object_detection/detect_object");
    gazebo_models_client = n.serviceClient<gazebo_msgs::GetWorldProperties>("/gazebo/get_world_properties");
    getgraspconfigurations_client = n.serviceClient<srs_grasping::GetDBGrasps>("/get_db_grasps");
    getgraspsfromposition_client = n.serviceClient<srs_grasping::GetFeasibleGrasps>("/get_feasible_grasps");
    ik_client = n.serviceClient<kinematics_msgs::GetConstraintAwarePositionIK>("/arm_kinematics/get_constraint_aware_ik");
    baseIsMoving_client = n.serviceClient<cob_srvs::Trigger>("/base_controller/is_moving");
    get_models_client = n.serviceClient<srs_object_database_msgs::GetObjectId>("/get_models");
    get_img_client = n.serviceClient<srs_object_database_msgs::GetImg>("/get_model_img");
    get_mesh_client = n.serviceClient<srs_object_database_msgs::GetMesh>("/get_model_mesh");
    simulator_client = n.serviceClient<srs_ui_pro::GraspSimulator>("/srs_ui_pro_grasp_simulator");
    getrequestevents_client = n.serviceClient<srs_ui_pro::RequestEvent>("/event_request_manager");
    ip_add_object_client = n.serviceClient<srs_interaction_primitives::AddBoundingBox>("/interaction_primitives/add_bounding_box");
    ip_get_all_primitives_names_client = n.serviceClient<srs_interaction_primitives::GetAllPrimitivesNames>("/interaction_primitives/get_all_primitives_names");
    ip_remove_object_client = n.serviceClient<srs_interaction_primitives::RemovePrimitive>("/interaction_primitives/remove_primitive");
    get_objects_on_map_client = n.serviceClient<srs_knowledge::GetObjectsOnMap>("/get_objects_on_map");
    get_objects_on_tray_client = n.serviceClient<srs_knowledge::GetObjectsOnTray>("/get_objects_on_tray");
    get_workspace_on_map_client = n.serviceClient<srs_knowledge::GetWorkspaceOnMap>("/get_workspace_on_map");
    get_rooms_on_map_client = n.serviceClient<srs_knowledge::GetRoomsOnMap>("/get_rooms_on_map");
    get_predefined_poses_client = n.serviceClient<srs_knowledge::GetPredefinedPoses>("/get_predefined_poses");
    get_workspace_for_object_client = n.serviceClient<srs_knowledge::GetWorkspaceForObject>("/get_workspace_for_object");
}

void RosInterface::initTopics(){
    sub_arm_state = n.subscribe("/arm_controller/state", 1000, &RosInterface::callback_arm_joint_states, this);
    sub_joint_states = n.subscribe("/joint_states", 1000, &RosInterface::callback_joint_states, this);
    sub_diagnostic = n.subscribe("/diagnostics", 1000, &RosInterface::callback_diagnostic, this);
    sub_emergency_state_stop = n.subscribe("/emergency_stop_state", 1000, &RosInterface::callback_emergency_stop_state, this);
    sub_goto_status = n.subscribe("/move_base/status", 1000, &RosInterface::callback_MoveBase, this);
    sub_dm_fb = n.subscribe("/srs_decision_making_actions/feedback", 1000, &RosInterface::callback_dm_fb, this);
    sub_dm_result = n.subscribe("/srs_decision_making_actions/result", 1000, &RosInterface::callback_dm_result, this);
    sub_ts = n.subscribe("/sdh_controller/tactile_data", 1000, &RosInterface::callback_ts, this);
    sub_power_state = n.subscribe("/power_state", 1000, &RosInterface::callback_power_state, this);
    sub_wifi_state = n.subscribe("/ddwrt/accesspoint", 1000, &RosInterface::callback_wifi_state, this);
    sub_grabbed = n.subscribe("/sdh_controller/grabbed", 1000, &RosInterface::callback_grabbed, this);
    sub_grabbed2 = n.subscribe("/sdh_controller/cylindric_grabbed", 1000, &RosInterface::callback_grabbed2, this);
    sub_dm_server_feedback = n.subscribe("/ui_pro_server_for_dm/feedback", 1000, &RosInterface::callback_dm_server_fb, this);
}

void RosInterface::initActionServers(){
    dm_client = new actionlib::SimpleActionClient<srs_decision_making_interface::srs_actionAction>("srs_decision_making_actions", true);
}

void RosInterface::serviceAvailable(ros::ServiceClient sc){
    if (!sc.waitForExistence(ros::Duration(1.0)))
        throw ServiceUnavailable(sc.getService());
}

void RosInterface::serviceCall(ros::ServiceClient sc, bool response){
    if (!response)
    {
        std::string service = sc.getService();
        ROS_ERROR("%s service failed.", service.c_str());
        throw ServiceCallFailed(service);
    }
    ros::spinOnce();
}










cob_object_detection_msgs::Detection RosInterface::Detect(std::string object_name)
{
    serviceAvailable(detection_client);

    cob_object_detection_msgs::Detection response;
    cob_object_detection_msgs::DetectObjects detection_msg;
        detection_msg.request.object_name.data = object_name;

    serviceCall(detection_client, detection_client.call(detection_msg));

    if (detection_msg.response.object_list.detections.size() > 0)
        response = detection_msg.response.object_list.detections[0];
    else
        ROS_ERROR("/object_detection/detect_object has not found objects.");

    return response;
}

geometry_msgs::Pose RosInterface::transformPose(geometry_msgs::PoseStamped p, std::string frame)
{
    geometry_msgs::PoseStamped result;
    tf::TransformListener listener(ros::Duration(10));
        listener.waitForTransform(p.header.frame_id, frame, ros::Time::now(), ros::Duration(3.0));
        listener.transformPose(frame, p, result);
    return result.pose;
}

bool RosInterface::callIKSolver(std::vector<float> current_joint_configuration, const geometry_msgs::PoseStamped &pose, std::vector<float> &solution)
{
    serviceAvailable(ik_client);

    solution.resize(7);
    kinematics_msgs::GetConstraintAwarePositionIK callIKSolver_msg;
        callIKSolver_msg.request.ik_request.ik_link_name = "sdh_palm_link";
        callIKSolver_msg.request.ik_request.pose_stamped = pose;
        //callIKSolver_msg.request.timeout = ros::Duration(2.0);
        callIKSolver_msg.request.ik_request.ik_seed_state.joint_state.position.resize(7);

    for(int j = 0 ; j < 7; ++j)
        callIKSolver_msg.request.ik_request.ik_seed_state.joint_state.position.push_back(current_joint_configuration[j]);

    serviceCall(ik_client, ik_client.call(callIKSolver_msg));

    if(callIKSolver_msg.response.error_code.val == callIKSolver_msg.response.error_code.SUCCESS)
        for (int i=0; i < 7; i++)
            solution[i] = callIKSolver_msg.response.solution.joint_state.position[i];
    else
    {
      ROS_ERROR("/arm_kinematics/get_ik service failed for %s. (error code: %d)", callIKSolver_msg.request.ik_request.ik_link_name.c_str(), callIKSolver_msg.response.error_code.val);
      return false;
    }

    return true;
}

void RosInterface::move(std::string component, std::vector<float> values)
{
    if (component.compare("base") == 0)
    {
        actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> move_base_client("move_base", true);

        ROS_INFO("Waiting for the move_base action server to come up.");
        if (!move_base_client.waitForServer(ros::Duration(5.0)))
            throw ServiceUnavailable("/move_base");

        move_base_msgs::MoveBaseGoal goal;
            goal.target_pose.header.frame_id = "map";
            goal.target_pose.header.stamp = ros::Time::now();
            goal.target_pose.pose.position.x = values[0];
            goal.target_pose.pose.position.y = values[1];
            goal.target_pose.pose.orientation.w = 1.0;

        ROS_INFO("Sending goal");
        move_base_client.sendGoal(goal);
    }
    else
    {

        std::string topic_name = "/"+component+"_controller/command";
        ros::Publisher pub = n.advertise<trajectory_msgs::JointTrajectory>(topic_name, 1, true);
        ros::Rate d(10);

        trajectory_msgs::JointTrajectory traj;
            traj.header.stamp = ros::Time::now()+ros::Duration(0.01);
            traj.points.resize(1);
            traj.points[0].time_from_start = ros::Duration(3.0);

        if (component.compare("arm") == 0)
        {

            traj.joint_names.push_back("arm_1_joint");
            traj.joint_names.push_back("arm_2_joint");
            traj.joint_names.push_back("arm_3_joint");
            traj.joint_names.push_back("arm_4_joint");
            traj.joint_names.push_back("arm_5_joint");
            traj.joint_names.push_back("arm_6_joint");
            traj.joint_names.push_back("arm_7_joint");

            for(int i = 0; i < 7; i++)
            {
                traj.points[0].positions.push_back(values[i]);
                traj.points[0].velocities.push_back(0.0);
            }

        }
        else if (component.compare("sdh") == 0)
        {
            traj.joint_names.push_back("sdh_knuckle_joint");
            traj.joint_names.push_back("sdh_finger_12_joint");
            traj.joint_names.push_back("sdh_finger_13_joint");
            traj.joint_names.push_back("sdh_finger_22_joint");
            traj.joint_names.push_back("sdh_finger_23_joint");
            traj.joint_names.push_back("sdh_thumb_2_joint");
            traj.joint_names.push_back("sdh_thumb_3_joint");

            for(int i = 0; i < 7; i++)
            {
                traj.points[0].positions.push_back(values[i]);
                traj.points[0].velocities.push_back(0.0);
            }
        }
        else if (component.compare("torso") == 0)
        {
            traj.joint_names.push_back("torso_lower_neck_tilt_joint");
            traj.joint_names.push_back("torso_pan_joint");
            traj.joint_names.push_back("torso_upper_neck_tilt_joint");

            for(int i = 0; i < 7; i++)
            {
                traj.points[0].positions.push_back(values[i]);
                traj.points[0].velocities.push_back(0.0);
            }
        }
        else if (component.compare("head") == 0)
        {
            traj.joint_names.push_back("head_axis_joint");
            traj.points[0].positions.push_back(values[0]);
            traj.points[0].velocities.push_back(0.0);
        }
        else //tray
        {
            traj.joint_names.push_back("torso_tray_joint");
            traj.points[0].positions.push_back(values[0]);
            traj.points[0].velocities.push_back(0.0);
        }

        pub.publish(traj);
        ros::spinOnce();
        d.sleep();
    }//if-else
}

void RosInterface::IP_AddObject(std::string object_name, geometry_msgs::PoseStamped pose, geometry_msgs::Point point)
{
    serviceAvailable(ip_add_object_client);

    srs_interaction_primitives::AddBoundingBox AddObject_msg;
        AddObject_msg.request.name = object_name;
        AddObject_msg.request.object_name = object_name;
        AddObject_msg.request.frame_id = "/base_link";
        AddObject_msg.request.description = object_name;
        AddObject_msg.request.pose = transformPose(pose);
        //AddObject_msg.request.pose.position.z += 0.1; //MILKBOX
        AddObject_msg.request.scale.x = point.x;
        AddObject_msg.request.scale.y = point.y;
        AddObject_msg.request.scale.z = point.z;
        AddObject_msg.request.color.r = 0.0;
        AddObject_msg.request.color.g = 1.0;
        AddObject_msg.request.color.b = 0.0;
        AddObject_msg.request.color.a = 1.0;

    serviceCall(ip_add_object_client, ip_add_object_client.call(AddObject_msg));
}

std::vector<std::string> RosInterface::IP_GetNames()
{
    serviceAvailable(ip_get_all_primitives_names_client);
    srs_interaction_primitives::GetAllPrimitivesNames primitives_msg;
    serviceCall(ip_get_all_primitives_names_client, ip_get_all_primitives_names_client.call(primitives_msg));
    return primitives_msg.response.primitives_names;
}

void RosInterface::IP_RemoveAllObjects()
{
    std::vector<std::string> primitives = IP_GetNames();

    for (unsigned int i=0; i<primitives.size(); i++)
        IP_RemoveObject(primitives[i]);
}

void RosInterface::IP_RemoveObject(std::string object_name)
{
    serviceAvailable(ip_remove_object_client);
    srs_interaction_primitives::RemovePrimitive RemoveObject_msg;
        RemoveObject_msg.request.name = object_name.c_str();
    serviceCall(ip_remove_object_client, ip_remove_object_client.call(RemoveObject_msg));
}

bool RosInterface::GraspIt(srs_msgs::FeasibleGrasp grasp)
{
    std::vector<float> pre_grasp_conf, grasp_conf;
    std::vector<float> current;
    current.resize(7);

    joint_values *jv = getJointValues("arm");
    for (int i=0; i<7; i++)
        current[i] = jv[i].position;


    geometry_msgs::PoseStamped pre, g;
        pre.pose = grasp.pre_grasp.pose;
        g.pose = grasp.grasp.pose;
        pre.header.frame_id = g.header.frame_id = "/base_link";
    bool found = false;
    for (int i=0; i<3; i++)
    {
        if (callIKSolver(current, pre, pre_grasp_conf))
        {
            for (int j=0; j<3; j++)
            {
                if (callIKSolver(pre_grasp_conf, g, grasp_conf))
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                float cylopen[] = {-0.01, -0.9854, 0.9472, -0.9854, 0.9472, -0.9854, 0.94672};
                std::vector<float> sdh_cylopen(cylopen, cylopen+sizeof(cylopen)/sizeof(float));

                move("arm", pre_grasp_conf);
                move("sdh", sdh_cylopen);
                sleep(2);
                move("arm", grasp_conf);
                sleep(4);
                std::vector<float> aux(grasp.sdh_joint_values.begin(), grasp.sdh_joint_values.end());
                std::vector<float> sdh_joint_values;
                sdh_joint_values.resize(7);

                sdh_joint_values[0] = aux[0];
                sdh_joint_values[1] = aux[3];
                sdh_joint_values[2] = aux[4];
                sdh_joint_values[3] = aux[5];
                sdh_joint_values[4] = aux[6];
                sdh_joint_values[5] = aux[1];
                sdh_joint_values[6] = aux[2];

                move("sdh", sdh_joint_values);

                break;
            }
        }
    }

    return isGrasped();
}

int RosInterface::howManyFingersHasTheGrasp()
{
    sleep(3);
    tactil_data td = getTactilSensorData();

    int fingers_touching = 0;
    bool touch1=false, touch2=false, touch3=false;

    //Finger1
    for (int i=0; i<(14*6); i++)
    {
        if (td.m1[i] > 0)
        {
            touch1 = true;
            fingers_touching++;
            break;
        }
    }

    if (!touch1)
    {
        for (int i=0; i<(14*6); i++)
        {
            if (td.m2[i] > 0)
            {
                fingers_touching++;
                break;
            }
        }
    }

    //Finger2 (center)
    for (int i=0; i<(14*6); i++)
    {
        if (td.m3[i] > 0)
        {
            touch2 = true;
            fingers_touching++;
            break;
        }
    }

    if (!touch2)
    {
        for (int i=0; i<(14*6); i++)
        {
            if (td.m4[i] > 0)
            {
                fingers_touching++;
                break;
            }
        }
    }

    //Finger3
    for (int i=0; i<(14*6); i++)
    {
        if (td.m5[i] > 0)
        {
            touch3 = true;
            fingers_touching++;
            break;
        }
    }

    if (!touch3)
    {
        for (int i=0; i<(14*6); i++)
        {
            if (td.m6[i] > 0)
            {
                fingers_touching++;
                break;
            }
        }
    }

    return fingers_touching;
}

bool RosInterface::isGrasped()
{
    /*
    if (howManyFingersHasTheGrasp() >= 2)
        return true;
    else
        return false;
        */
    sleep(1);
    if (grabbed || cylinder_grabbed)
        return true;
    else
        return false;
}

bool RosInterface::baseIsMoving()
{
    serviceAvailable(baseIsMoving_client);
    cob_srvs::Trigger baseIsMoving_msg;
    serviceCall(baseIsMoving_client, baseIsMoving_client.call(baseIsMoving_msg));
    return baseIsMoving_msg.response.success.data;;
}

int RosInterface::decision_making_actions(std::string action, std::string parameters, std::string json_parameters)
{
    ROS_INFO("Waiting for the srs_decision_making_actions action server to come up.");
    if (!dm_client->waitForServer(ros::Duration(5.0)))
        throw ServiceUnavailable("/srs_decision_making_actions");


    srs_decision_making_interface::srs_actionGoal goal;
    if (json_parameters != "NULL")
    {
        goal.json_parameters = json_parameters;
        dm_client->sendGoalAndWait(goal);
        return dm_client->getResult()->return_value;
    }

    if (action == "move" || action == "search" || action == "check" || action == "get" || action == "fetch" || action == "deliver" || action == "stop" || action == "pause" || action == "resume")
    {
        goal.action = action.c_str();
        //goal.json_parameters = parameters;
        goal.parameter = parameters;
        goal.priority = 0;
    }
    else
    {
        ROS_ERROR("srs_decision_making::ExecutionActionResult: An error has occurred.");
        return -1;
    }

    dm_client->sendGoalAndWait(goal);
    return dm_client->getResult()->return_value;
}

void RosInterface::startAssistedArm()
{
    //TODO:
    actionlib::SimpleActionClient<srs_assisted_arm_navigation_msgs::ManualArmManipAction> client("/but_arm_manip/manual_arm_manip_action", true);
    client.waitForServer();
    srs_assisted_arm_navigation_msgs::ManualArmManipActionGoal goal;
    goal.goal.allow_repeat = true;//goal.goal.away = true;
    goal.goal.action = "Move arm to safe position!";//goal.goal.away = true;
    goal.goal.object_name = "";//goal.goal.away = true;

    client.sendGoal(goal.goal);
    client.waitForResult();
}


//GETS
std::vector<srs_ui_pro::RequestEventMSG> RosInterface::getRequestEvents()
{
    serviceAvailable(getrequestevents_client);
    //std::vector<srs_ui_pro::RequestEventMSG> response;
    srs_ui_pro::RequestEvent requestevent_msg;
        requestevent_msg.request.event.id = -1;
    serviceCall(getrequestevents_client, getrequestevents_client.call(requestevent_msg));
    return requestevent_msg.response.events;
}

std::vector<std::string> RosInterface::getGazeboModels()
{
    serviceAvailable(gazebo_models_client);
    //std::vector<std::string> response;
    gazebo_msgs::GetWorldProperties gazebo_msg;
    serviceCall(gazebo_models_client, gazebo_models_client.call(gazebo_msg));
    return gazebo_msg.response.model_names;
}

std::vector<std::string> RosInterface::get_objects_on_map()
{
    serviceAvailable(get_objects_on_map_client);
    //std::vector<std::string> response;
    srs_knowledge::GetObjectsOnMap objects_msg;
    serviceCall(get_objects_on_map_client, get_objects_on_map_client.call(objects_msg));
    return objects_msg.response.classesOfObjects;
}

std::vector<std::string> RosInterface::get_objects_on_tray()
{
    serviceAvailable(get_objects_on_tray_client);
    //std::vector<std::string> response;
    srs_knowledge::GetObjectsOnTray objects_msg;
    serviceCall(get_objects_on_tray_client, get_objects_on_tray_client.call(objects_msg));
    return objects_msg.response.classesOfObjects;
}

std::vector<std::string> RosInterface::get_workspace_on_map()
{
    serviceAvailable(get_workspace_on_map_client);
    //std::vector<std::string> response;
    srs_knowledge::GetWorkspaceOnMap workspace_msg;
    serviceCall(get_workspace_on_map_client, get_workspace_on_map_client.call(workspace_msg));
    return workspace_msg.response.objects;
}

std::vector<srs_msgs::SRSSpatialInfo> RosInterface::get_workspace_on_map_info()
{
    serviceAvailable(get_workspace_on_map_client);
    //std::vector<srs_knowledge::SRSSpatialInfo> response;
    srs_knowledge::GetWorkspaceOnMap workspace_msg;
        workspace_msg.request.ifGeometryInfo = true;
    serviceCall(get_workspace_on_map_client, get_workspace_on_map_client.call(workspace_msg));
    return workspace_msg.response.objectsInfo;
}

std::vector<std::string> RosInterface::get_rooms_on_map()
{
    serviceAvailable(get_rooms_on_map_client);
    //std::vector<std::string> response;
    srs_knowledge::GetRoomsOnMap rooms_msg;
    serviceCall(get_rooms_on_map_client, get_rooms_on_map_client.call(rooms_msg));
    return rooms_msg.response.rooms;
}

std::vector<std::string> RosInterface::get_predefined_poses()
{
    serviceAvailable(get_predefined_poses_client);
    //std::vector<std::string> response;
    srs_knowledge::GetPredefinedPoses poses_msg;
    serviceCall(get_predefined_poses_client, get_predefined_poses_client.call(poses_msg));
    return poses_msg.response.locations;
}

std::vector<std::string> RosInterface::get_workspace_for_object(std::string objectType)
{
    serviceAvailable(get_workspace_for_object_client);
    //std::vector<std::string> response;
    srs_knowledge::GetWorkspaceForObject workspace_msg;
        workspace_msg.request.objectType = objectType;
        workspace_msg.request.config = 0;
    serviceCall(get_workspace_for_object_client, get_workspace_for_object_client.call(workspace_msg));
    return workspace_msg.response.workspaces;
}

std::string RosInterface::getObjectName(int object_id)
{
    serviceAvailable(get_models_client);
    std::stringstream obj_id;
    obj_id << object_id;
    //std::string response;
    srs_object_database_msgs::GetObjectId getObjectName_msg;
        getObjectName_msg.request.item = obj_id.str();
        getObjectName_msg.request.type = "id";
    serviceCall(get_models_client, get_models_client.call(getObjectName_msg));
    return getObjectName_msg.response.model_desc[0];
}

int RosInterface::getObjectId(std::string object_name)
{
    serviceAvailable(get_models_client);
    if (object_name == "milk" ) object_name = "Milkbox";
    //int response;
    srs_object_database_msgs::GetObjectId geObjectId_msg;
        geObjectId_msg.request.item = object_name.c_str();
        geObjectId_msg.request.type = "name";
    serviceCall(get_models_client, get_models_client.call(geObjectId_msg));
    return geObjectId_msg.response.model_ids[0];
}

wxImage RosInterface::getObjectIMG(int object_id)
{
    serviceAvailable(get_img_client);

    wxImage response;
    srs_object_database_msgs::GetImg getIMG_msg;
        getIMG_msg.request.model_ids.resize(1);
        getIMG_msg.request.model_ids[0] = object_id;

    if (get_img_client.call(getIMG_msg))
    {
        if (getIMG_msg.response.msg.size()>0)
        {
            int size = (getIMG_msg.response.msg[0].image.data).size();
            unsigned char puntero[size];

            for (int i=0; i<size; i++)
                puntero[i] = (char)getIMG_msg.response.msg[0].image.data[i];

            wxMemoryInputStream pngStream(puntero, size);
            response.LoadFile(pngStream, wxBITMAP_TYPE_PNG);
        }
        else
            response.LoadFile(wxString("./img/error.png", wxConvUTF8), wxBITMAP_TYPE_PNG);
    }
    else
    {
        ROS_ERROR("/get_model_img service failed.");
        response.LoadFile(wxString("./img/error.png", wxConvUTF8), wxBITMAP_TYPE_PNG);
        throw ServiceCallFailed("/get_model_img");
    }

    return response;
}

wxImage RosInterface::getObjectIMG(std::string object_name)
{
    return getObjectIMG(getObjectId(object_name));
}

std::vector<wxImage> RosInterface::getAllDBImages()
{
    serviceAvailable(get_models_client);
    srs_object_database_msgs::GetObjectId getObjectName_msg;
    serviceCall(get_models_client, get_models_client.call(getObjectName_msg));
    std::vector<wxImage> response;

    if (get_models_client.call(getObjectName_msg))
        for (unsigned int i=0; i<getObjectName_msg.response.model_ids.size(); i++)
            response.push_back(getObjectIMG(getObjectName_msg.response.model_ids[i]));
    else
    {
        ROS_ERROR("/get_models_client service failed.");
        throw ServiceCallFailed("/get_model_img");
    }

    return response;
}


std::string RosInterface::getMesh(int object_id)
{
    serviceAvailable(get_mesh_client);
    //std::string response;
    srs_object_database_msgs::GetMesh getMesh_msg;
        getMesh_msg.request.model_ids.resize(1);
        getMesh_msg.request.model_ids[0] = object_id;
    serviceCall(get_mesh_client, get_mesh_client.call(getMesh_msg));
    std::string mesh_data = array_to_string(getMesh_msg.response.msg[0].data);
    std::string response = "/tmp/mesh_data.dae";
    std::ofstream myfile;
        myfile.open(response.c_str());
        myfile << mesh_data.c_str();
        myfile.close();
    return response;
}

std::string RosInterface::array_to_string(std::vector<unsigned char> int_array)
{
    std::string returnstring = "";
    for (int temp = 0; temp < int_array.size(); temp++)
        returnstring += int_array[temp];

    return returnstring;
}

RosInterface::joint_values * RosInterface::getJointValues(std::string component)
{
    if (component.compare("arm")==0)
        return arm_joints;
    else if (component.compare("sdh")==0)
        return sdh_joints;
    else if (component.compare("torso")==0)
        return torso_joints;
    else if (component.compare("tray")==0)
        return tray_joints;
    else if (component.compare("head")==0)
        return head_joints;
    else
        return joints;
}

std::string RosInterface::getMoveBaseStatus()
{
    return move_base_status_message;
}

std::string RosInterface::getDiagnosticsMessage()
{
    return diagnostics_message;
}

RosInterface::tactil_data RosInterface::getTactilSensorData()
{
    return ts_values;
}

bool RosInterface::getEmergencyState()
{
    return emergency_button_stop_state;
}

bool RosInterface::getScannerState()
{
    return scanner_stop_state;
}

std::string RosInterface::getDMStatusText()
{
    return dm_status_text;
}

std::string RosInterface::getDMCurrentState()
{
    return dm_current_state;
}

std::string RosInterface::getDMCurrentTask()
{
    return dm_current_task;
}

int RosInterface::getDMCurrentStatus()
{
    return dm_current_status;
}


std::string RosInterface::getDMCurrentTaskID()
{
    return dm_current_task_id;
}


int RosInterface::DM_InterventionRequired()
{

    return dm_exceptional_case_id;
}

bool RosInterface::DM_ExcepcionalCase()
{
    return dm_server_event;
}

std::vector<srs_msgs::DBGrasp> RosInterface::getGraspConfigurations(int object_id)
{
    serviceAvailable(getgraspconfigurations_client);

    std::vector<srs_msgs::DBGrasp> response;
    srs_grasping::GetDBGrasps getgraspconfigurations_msg;
    getgraspconfigurations_msg.request.object_id = object_id;

    if (getgraspconfigurations_client.call(getgraspconfigurations_msg))
        response = getgraspconfigurations_msg.response.grasp_configuration;
    else
    {
        ROS_ERROR("/get_db_grasps service failed.");
        throw ServiceCallFailed("/get_db_grasps");
    }
    return response;
}

std::vector<srs_msgs::FeasibleGrasp> RosInterface::getGraspsFromPosition(int object_id, geometry_msgs::Pose object_pose)
{
    serviceAvailable(getgraspsfromposition_client);

    std::vector<srs_msgs::FeasibleGrasp> response;
    srs_grasping::GetFeasibleGrasps getgraspsfromposition_msg;
    getgraspsfromposition_msg.request.object_id = object_id;
    getgraspsfromposition_msg.request.object_pose = object_pose;

    if (getgraspsfromposition_client.call(getgraspsfromposition_msg))
        response = getgraspsfromposition_msg.response.grasp_configuration;
    else
    {
        ROS_ERROR("/get_feasible_grasps service failed.");
        throw ServiceCallFailed("/get_feasible_grasps");
    }
    return response;
}

pr2_msgs::PowerState RosInterface::getPowerState()
{
    return power_state;
}

pr2_msgs::AccessPoint RosInterface::getWifiState()
{
    return wifi_state;
}
















//CALLBACKS
void RosInterface::callback_arm_joint_states(const pr2_controllers_msgs::JointTrajectoryControllerState::ConstPtr &msg)
{
    for (int i=0; i<7; i++)
        arm_joints[i].position = msg->desired.positions[i];
}



void RosInterface::callback_joint_states(const sensor_msgs::JointState::ConstPtr &msg)
{
    if (msg->position.size() > 8)
    {
        joints = new joint_values[msg->position.size()];
        int arm_count, sdh_count, torso_count;
        arm_count=sdh_count=torso_count=0;

        for (unsigned int i=0; i<msg->position.size(); i++)
        {
            std::string joint_name = msg->name[i];
            if ((joint_name.substr(0,3)).compare("arm")==0)
            {
                arm_joints[arm_count].name = msg->name[i];
                //arm_joints[arm_count].position = msg->position[i];
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
    }
}

void RosInterface::callback_diagnostic(const diagnostic_msgs::DiagnosticArray::ConstPtr &msg)
{
    if (msg->status.size() > 0)
        diagnostics_message = msg->status[0].message;
}

void RosInterface::callback_emergency_stop_state(const cob_relayboard::EmergencyStopState::ConstPtr &msg)
{
    emergency_button_stop_state = msg->emergency_button_stop;
    scanner_stop_state = msg->scanner_stop;
}

void RosInterface::callback_MoveBase(const actionlib_msgs::GoalStatusArray::ConstPtr &msg)
{
    if (msg->status_list.size() > 0)
    {
        std::string status_msg;
        switch(msg->status_list[0].status)
        {
            case 0:
                status_msg = "PENDING";
                break;
            case 1:
                status_msg = "ACTIVE";
                break;
            case 2:
                status_msg = "PREEMPTED";
                break;
            case 3:
                status_msg = "SUCCEEDED";
                break;
            case 4:
                status_msg = "ABORTED";
                break;
            case 5:
                status_msg = "REJECTED";
                break;
            case 6:
                status_msg = "PREEMPTING";
                break;
            case 7:
                status_msg = "RECALLING";
                break;
            case 8:
                status_msg = "RECALLED";
                break;
            case 9:
                status_msg = "LOST";
                break;
            default:
                status_msg = "";
                break;
        }
        move_base_status_message = status_msg+": "+msg->status_list[0].text;
    }
    else
        move_base_status_message = "Waiting goal...";
}

void RosInterface::callback_dm_fb(const srs_decision_making_interface::srs_actionActionFeedback::ConstPtr &msg)
{
    std::string status;

    switch(msg->status.status)
    {
        case 0:
            status = "PENDING";
            break;
        case 1:
            status = "ACTIVE";
            break;
        case 2:
            status = "PREEMPTED";
            break;
        case 3:
            status = "SUCCEEDED";
            break;
        case 4:
            status = "ABORTED";
            break;
        case 5:
            status = "REJECTED";
            break;
        case 6:
            status = "PREEMPTING";
            break;
        case 7:
            status = "RECALLING";
            break;
        case 8:
            status = "RECALLED";
            break;
        case 9:
            status = "LOST";
            break;
        default:
            status = "UNKNOWN";
            break;
    }

    dm_status_text = status+": "+msg->status.text;
    dm_current_state = msg->feedback.current_state;
    dm_solution_required = msg->feedback.solution_required;
    dm_exceptional_case_id = msg->feedback.exceptional_case_id;
    dm_goal_id = msg->status.goal_id.id;
}

void RosInterface::callback_dm_result(const srs_decision_making_interface::srs_actionActionResult::ConstPtr &msg)
{
    dm_current_task = msg->status.text;
    dm_current_status = msg->status.status;
    dm_current_task_id = msg->status.goal_id.id;
}

void RosInterface::callback_ts(const schunk_sdh::TactileSensor::ConstPtr &msg)
{
    ts_values.m1 = msg->tactile_matrix[0].tactile_array;
    ts_values.m2 = msg->tactile_matrix[1].tactile_array;
    ts_values.m3 = msg->tactile_matrix[2].tactile_array;
    ts_values.m4 = msg->tactile_matrix[3].tactile_array;
    ts_values.m5 = msg->tactile_matrix[4].tactile_array;
    ts_values.m6 = msg->tactile_matrix[5].tactile_array;
}

void RosInterface::callback_power_state(const pr2_msgs::PowerState &msg)
{
    power_state = msg;
}

void RosInterface::callback_wifi_state(const pr2_msgs::AccessPoint &msg)
{
    wifi_state = msg;
}

bool RosInterface::GraspSimulator(int object_id, srs_msgs::FeasibleGrasp grasp_configuration, geometry_msgs::Pose object_pose)
{
    serviceAvailable(simulator_client);
    srs_ui_pro::GraspSimulator simulator_msg;
        simulator_msg.request.object_id = object_id;
        simulator_msg.request.grasp_configuration = grasp_configuration;
        simulator_msg.request.object_pose = object_pose;
    serviceCall(simulator_client, simulator_client.call(simulator_msg));
    return simulator_msg.response.result;

}

void RosInterface::callback_grabbed(const std_msgs::Bool &msg)
{
    grabbed = msg.data;
}

void RosInterface::callback_grabbed2(const std_msgs::Bool &msg)
{
    cylinder_grabbed = msg.data;
}

void RosInterface::callback_dm_server_fb(const srs_ui_pro::dm_serverActionFeedback::ConstPtr &msg)
{
    if ((msg->feedback.current_status).compare("new_event") == 0)
        dm_server_event = true;
    else
        dm_server_event = false;

}
