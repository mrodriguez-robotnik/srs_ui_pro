#ifndef RVIZINTERFACE_H
#define RVIZINTERFACE_H


#define     RVIZ_CONFIG    "/home/marodga/local_packages/srs_ui_pro/rviz_config/empty_config.vcg"


#include <ros/ros.h>
#include <ogre_tools/initialization.h>
#include <rviz/visualization_frame.h>
#include <rviz/visualization_manager.h>
#include <rviz/display_wrapper.h>

//Rviz default plugins
#include <rviz/default_plugin/camera_display.h>
#include <rviz/default_plugin/grid_cells_display.h>
#include <rviz/default_plugin/grid_display.h>
#include <rviz/default_plugin/interactive_marker_display.h>
#include <rviz/default_plugin/map_display.h>
#include <rviz/default_plugin/marker_display.h>
#include <rviz/default_plugin/point_cloud2_display.h>
#include <rviz/default_plugin/robot_model_display.h>


#include <srs_assisted_grasping_ui/grasping_display.h> //srs_assisted_grasping_ui
#include <srs_assisted_arm_navigation_ui/arm_navigation_display.h> //srs_assisted_arm_navigation_ui
#include <srs_ui_but/but_display/but_distance_linear_visualizer.h>
#include <srs_ui_but/but_display/but_distance_circular_indicator.h>
#include <srs_ui_but/but_display/but_cob_stretch_indicator.h>
#include <srs_env_model_ui/but_rviz_display/point_cloud_display.h>
#include <wx/aui/aui.h>


typedef struct display_info
{
    std::string name;
    rviz::DisplayWrapper *display;

    display_info(std::string n, rviz::DisplayWrapper *d=NULL) { name = n; display = d; }
};

class RvizInterface : public rviz::VisualizationFrame
{
    public:
        RvizInterface();
        virtual ~RvizInterface();

        void standardDevices();
        void addDisplay(std::string package, std::string class_name, std::string name, bool enabled);
        void removeDisplay(std::string name);
        void showRviz();
        void setDisplayStatus(std::string name, bool status);
        void setDisplayConfig(std::string name, rviz::DisplayWrapper *disp);
        void loadConfig(std::string config_path=RVIZ_CONFIG);

    protected:

    private:
        //rviz::VisualizationFrame *vFrame;
        rviz::VisualizationManager *vManager;

        std::vector<display_info> displays_list;

};

#endif // RVIZINTERFACE_H
