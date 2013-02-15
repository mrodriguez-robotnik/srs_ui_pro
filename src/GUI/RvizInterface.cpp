#include "RvizInterface.h"

RvizInterface::RvizInterface() : VisualizationFrame(NULL)
{
    ogre_tools::initializeOgre(TRUE);

    this->initialize(RVIZ_CONFIG, "/map", "/base_link");
    vManager = this->getManager();

}

RvizInterface::~RvizInterface()
{
    this->~VisualizationFrame();
    ogre_tools::cleanupOgre();
}

void RvizInterface::standardDevices()
{
    this->addDisplay("rviz", "rviz::GridDisplay", "Grid", true);
    this->addDisplay("rviz", "rviz::MapDisplay", "Map", true);
    this->addDisplay("rviz", "rviz::CameraDisplay", "Camera", true);
    this->addDisplay("srs_env_model_ui", "CButPointCloud", "Point Cloud2", true);
    this->addDisplay("rviz", "rviz::RobotModelDisplay", "Robot Model", true);
}

void RvizInterface::addDisplay(std::string package, std::string class_name, std::string name, bool enabled)
{
    rviz::DisplayWrapper *disp = vManager->createDisplay(package, class_name, name, enabled);
    this->setDisplayConfig(name, disp);

    displays_list.push_back(display_info(name, disp));
}

void RvizInterface::removeDisplay(std::string name)
{
    for (int i=0; i<displays_list.size(); i++)
    {
        if (name.compare(displays_list[i].name) == 0)
        {
            vManager->removeDisplay(displays_list[i].name);
            ROS_ERROR("%s BORRADO", displays_list[i].name.c_str());
            displays_list.erase(displays_list.begin()+i);
            break;
        }
    }
}

void RvizInterface::showRviz()
{
    this->Show();
}

void RvizInterface::loadConfig(std::string path)
{
    this->loadDisplayConfig(path);
}

void RvizInterface::setDisplayStatus(std::string name, bool status)
{
    //TODO:
}

void RvizInterface::setDisplayConfig(std::string name, rviz::DisplayWrapper *disp)
{
    rviz::Display *d = disp->getDisplay();

    if (name.compare("Grid") == 0)
    {
        ((rviz::GridDisplay*) d)->setFrame("/map");
        return;
    }

    if (name.compare("Map") == 0)
    {
        ((rviz::MapDisplay*) d)->setTopic("/map");
        return;
    }

    if (name.compare("Camera") == 0)
    {
        ((rviz::CameraDisplay*) d)->setTopic("/cam3d/rgb/image_color"); //TODO:
        return;
    }

    if (name.compare("Point Cloud2") == 0)
    {
        ((srs_env_model_ui::CButPointCloud*) d)->setTopic("/cam3d/depth_registered/points"); //TODO:
        //((rviz::PointCloud2Display*) d)->setColorTransformer("RGB8"); //TODO:
        return;
    }

    if (name.compare("Robot Model") == 0)
    {
        //((rviz::RobotModelDisplay*) d)->SOMETHING("/map");
        return;
    }




    //BUT DISPLAYS
    if (name.compare("Robot teleop marker") == 0)
    {
        ((rviz::InteractiveMarkerDisplay*) d)->setMarkerUpdateTopic("/cob_interactive_teleop/cob_interactive_teleop/update");
        return;
    }

    if (name.compare("Distance Linear Visualizer") == 0)
    {
        //((srs_ui_but::CButDistanceLinearVisualizer*) d)->setTopic("/point");
        //((srs_ui_but::CButDistanceLinearVisualizer*) d)->setLinkString("/sdh_palm_link");
        return;
    }

    if (name.compare("Distance Circular Indicator") == 0);
    {
        //((srs_ui_but::CButDistanceCircularIndicator*) d)->setLinkString("/sdh_palm_link");
        //((srs_ui_but::CButDistanceCircularIndicator*) d)->setLevels(5);
        //((srs_ui_but::CButDistanceCircularIndicator*) d)->setRadius(5.0);

        //((srs_ui_but::CButDistanceCircularIndicator*) d)->setLinkString("/base_link");
        //((srs_ui_but::CButDistanceCircularIndicator*) d)->setLevels(10);
        //((srs_ui_but::CButDistanceCircularIndicator*) d)->setRadius(10.0);
        return;
    }

    if (name.compare("Stretch Indicator") == 0) //TODO: Talk with BUT. The functions are protected.
    {
        //((srs_ui_but::CButCOBStretchIndicator*) d)->SOMETHING();
        return;
    }

    if (name.compare("Object Manager") == 0) //TODO: Talk with BUT. The functions are protected.
    {
        //((srs_ui_but::CButObjectManager*) d)->SOMETHING();
        return;
    }

    if (name.compare("CButCamDisplay") == 0) //TODO: Talk with BUT. The functions are protected.
    {
        //((srs_ui_but::CButCamDisplay*) d)->SOMETHING();
        return;
    }

    return;
}



