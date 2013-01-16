#ifndef RVIZINTERFACE_H
#define RVIZINTERFACE_H


#define     RVIZ_CONFIG_FILE    "~/local_packages/srs_ui_pro/rviz_config/config"

#include <rviz/visualization_frame.h>
#include <rviz/visualization_manager.h>
#include <rviz/display_wrapper.h>
#include <rviz/default_plugin/grid_display.h>
#include <rviz/window_manager_interface.h>
#include <ogre_tools/initialization.h>
//#include <srs_assisted_grasping_ui/grasping_display.h> //srs_assisted_grasping_ui
#include <srs_assisted_arm_navigation_ui/arm_navigation_display.h> //srs_assisted_arm_navigation_ui
//#include <rviz/default_plugin/grid_display.h>


typedef struct display_info
{
    std::string name;
    rviz::DisplayWrapper *display;

    display_info(std::string n, rviz::DisplayWrapper *d=NULL) { name = n; display = d; }
};

class RvizInterface
{
    public:
        RvizInterface();
        virtual ~RvizInterface();

        rviz::VisualizationFrame* getFrame();
        void showRviz();
        void removeDisplay(std::string name);
        void setDisplayStatus(std::string name, bool status);
        void setDisplayConfig(std::string name, rviz::DisplayWrapper *disp);
        void addDisplay(std::string package, std::string class_name, std::string name, bool enabled);


    protected:

    private:
        rviz::VisualizationFrame *vFrame;
        rviz::VisualizationManager *vManager;

        std::vector<display_info> displays_list;

};

#endif // RVIZINTERFACE_H
