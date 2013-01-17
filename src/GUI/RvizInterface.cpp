#include "RvizInterface.h"

RvizInterface::RvizInterface()
{
    ogre_tools::initializeOgre(TRUE);

    vFrame = new rviz::VisualizationFrame(NULL);
    vFrame->initialize(RVIZ_CONFIG_FILE, "/map", "/base_link");
    vManager = vFrame->getManager();


    //BUT pluggins
    //but_gDisplay = new srs_assisted_grasping_ui::CButGraspingDisplay("AAAAAAAAAAAAAAAAAAAAAAAAAAAAMIGO", vManager);



}

RvizInterface::~RvizInterface()
{
}

void RvizInterface::showRviz()
{
    vFrame->Show();
}


void RvizInterface::removeDisplay(std::string name)
{
    for (int i=0; i<displays_list.size(); i++)
    {
        if (name.compare(displays_list[i].name) == 0)
        {
            vManager->removeDisplay(displays_list[i].name);
            displays_list.erase(displays_list.begin()+i);
            break;
        }
    }
}

rviz::VisualizationFrame* RvizInterface::getFrame()
{
    return vFrame;
}

void RvizInterface::setDisplayStatus(std::string name, bool status)
{

}

void RvizInterface::setDisplayConfig(std::string name, rviz::DisplayWrapper *disp)
{
    if (name.compare("Grid") == 0)
        ((rviz::GridDisplay*) disp->getDisplay())->setFrame("/map");

}

void RvizInterface::addDisplay(std::string package, std::string class_name, std::string name, bool enabled)
{
    rviz::DisplayWrapper *disp = vManager->createDisplay(package, class_name, name, enabled);
    this->setDisplayConfig(name, disp);

    displays_list.push_back(display_info(name, disp));
}

