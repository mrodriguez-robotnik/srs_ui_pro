/***************************************************************
 * Name:      srs_ui_proMain.h
 * Purpose:   Defines Application Frame
 * Author:    Roman Navarro (rnavarro@robotnik.es)
 * Created:   2012-03-13
 * Copyright: Roman Navarro ()
 * License:
 **************************************************************/

#ifndef srs_ui_proMAIN_H
#define srs_ui_proMAIN_H

//(*Headers(srs_ui_proFrame)
#include <wx/gauge.h>
#include <wx/bmpbuttn.h>
#include <wx/grid.h>
#include <wx/spinctrl.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include <wx/statusbr.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/timer.h>
#include <wx/statbmp.h>
//*)

#include <wx/bmpbuttn.h>
#include <wx/menu.h>
#include <wx/log.h>

#include <pthread.h>
#include "ProcessManager.h"
#include "RosInterface.h"
//#include "RvizInterface.h"
#include "ObjectInfo.h"
#include "SkypeFunctions.h"
#include "SkypeWindow.h"
#include "SkypeWindow2.h"
#include "DM_window.h"


#define     BLUE                *wxBLUE
#define     RED                 *wxRED
#define     BLACK               *wxBLACK
#define     GREEN               *wxGREEN

#define     RVIZ_CONFIG    "/home/marodga/local_packages/srs_ui_pro/rviz_config/srs_config.vcg"

class srs_ui_proFrame: public wxFrame
{
    public:

        srs_ui_proFrame(wxWindow* parent, SkypeFunctions *sf, ProcessManager *pm, bool offline=false, wxWindowID id = -1);
        ~srs_ui_proFrame();

    private:

        SkypeFunctions *SF;
        RosInterface *Ri;
        //RvizInterface *RvI;
        ProcessManager *PM;
        DM_window *DM_W;

        std::string event_dm_log_str;
        bool event_dm_log, offline;
        wxColour event_dm_log_colour;


        std::vector<wxStaticBitmap*> ts_finger11, ts_finger12, ts_finger21, ts_finger22, ts_finger31, ts_finger32;
        int num_events;
        std::string last_chat_user;
        bool dm_working, dm_paused, dm_resumed, dm_stoped;
        bool run_notification;
        std::string last_state, current_task_id;
        std::vector<wxBitmapButton*> img_objects;
        std::vector<wxBitmapButton*> img_objects_on_tray;
        std::vector<wxBitmapButton*> img_db_objects;
        std::vector<cob_object_detection_msgs::Detection> detected_objects;
        std::vector<srs_msgs::FeasibleGrasp> generated_grasps;


        void writeInLog(std::string text="ERROR: Unknown error.\n", wxColour colour=RED);
        void writeInDMLog(std::string text="ERROR: Unknown error.\n", wxColour colour=RED);
        void writeInDMLog_(std::string text, wxTextCtrl *log, wxColour colour=RED);
        std::string toString(wxString wx);
        std::string toString(float f);
        std::string toStringN(wxString wx);
        wxString toWXString(std::string s);
        wxString toWXStringN(std::string s);
        wxString toWXString(float f);
        bool toFloat(std::string s, float &f);
        bool toFloat(wxString wx, float &f);
        void InitTactileSensorSimulator();
        void InitPredefinedPoses();
        void UpdateTactilSensorSimulator();
        void UpdateRobotStatus();
        void UpdateIMGs();
        void InitSkype(); //obsoleto
        void connectToSkype();
        void showSkypeWindow();
        void showSkypeWindow2();
        void Initialize();
        void stopTimers();
        void InitSkypeNotebooks();
        void LoadDBObjects();



        struct dm_thread_arg{
            srs_ui_proFrame *form;
            std::string action;
            std::string parameters;
            std::string json_parameters;
            wxTextCtrl *log;
        };

        void *_THREAD_StartAssistedArm(void);
        static void *THREAD_StartAssistedArm(void *arg){
            return ((srs_ui_proFrame*)arg)->_THREAD_StartAssistedArm();
        }

        void *_THREAD_GenerateGrasps(void);
        static void *THREAD_GenerateGrasps(void *arg){
            return ((srs_ui_proFrame*)arg)->_THREAD_GenerateGrasps();
        }

        void *_THREAD_DMAction(std::string actions, std::string parameters, std::string json_parameters, wxTextCtrl *log);
        static void *THREAD_DMAction(void *argumento){
            dm_thread_arg *arg = (dm_thread_arg*)argumento;
            return (srs_ui_proFrame*)(arg->form)->_THREAD_DMAction((arg->action).c_str(), arg->parameters, arg->json_parameters, arg->log);
        }

        void *_THREAD_GraspSimulator(void);
        static void *THREAD_GraspSimulator(void *arg){
            return ((srs_ui_proFrame*)arg)->_THREAD_GraspSimulator();
        }

        void *_THREAD_Skype(void);
        static void *THREAD_Skype(void *arg){
            return ((srs_ui_proFrame*)arg)->_THREAD_Skype();
        }

        void *_THREAD_SpawnObjects(void);
        static void *THREAD_SpawnObjects(void *arg){
            return ((srs_ui_proFrame*)arg)->_THREAD_SpawnObjects();
        }





        //(*Handlers(srs_ui_proFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Ontimer_updatesTrigger(wxTimerEvent& event);
        void Onbutton_GenerateGraspsClick(wxCommandEvent& event);
        void Onbutton_GraspItClick(wxCommandEvent& event);
        void Ontimer_URITrigger(wxTimerEvent& event);
        void Onbutton_kitchen1Click(wxCommandEvent& event);
        void Onbutton_kitchen2Click(wxCommandEvent& event);
        void Onbutton_DMStopClick(wxCommandEvent& event);
        void Onbutton_GetMilkStartClick(wxCommandEvent& event);
        void runRviz(wxCommandEvent& event);
        void semi_goToButton(wxCommandEvent& event);
        void manual_moveBaseButton(wxCommandEvent& event);
        void manual_joystickButton(wxCommandEvent& event);
        void DetectObjects(wxCommandEvent& event);
        void object_info(wxCommandEvent& event);
        void Onbutton_simulateGraspClick(wxCommandEvent& event);
        void Onbutton_DMPauseClick(wxCommandEvent& event);
        void Onbutton_DMResumeClick(wxCommandEvent& event);
        void Onbutton_GetMilkPauseClick(wxCommandEvent& event);
        void Onbutton_homeClick(wxCommandEvent& event);
        void Onbutton_im_distanceClick(wxCommandEvent& event);
        void Onbutton_im_camClick(wxCommandEvent& event);
        void Onbutton_im_gotoClick(wxCommandEvent& event);
        void Ontimer_RequestsEventTrigger(wxTimerEvent& event);
        void Ontimer_RequestsEventTrigger1(wxTimerEvent& event);
        void StartClick(wxCommandEvent& event);
        void Onbutton_im_assistedarmClick(wxCommandEvent& event);
        void OnMenuSkypeStart(wxCommandEvent& event);
        void OnMenuSkypeCloseCall(wxCommandEvent& event);
        void Ongrid_request_eventsCellLeftClick(wxGridEvent& event);
        void Onbutton_GoToStartClick(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnButton9Click(wxCommandEvent& event);
        void Onskype_timerTrigger(wxTimerEvent& event);
        void Onskype_timerTrigger1(wxTimerEvent& event);
        void Onchat_sendText(wxCommandEvent& event);
        void showContextualMenu(wxListEvent& event);
        void acceptCall(wxListEvent& event);
        void Ontimer_ROSTrigger(wxTimerEvent& event);
        void Onbutton_move_STARTClick(wxCommandEvent& event);
        void Onbutton_search_STARTClick(wxCommandEvent& event);
        void Onbutton_get_STARTClick(wxCommandEvent& event);
        void Onbutton_fetch_STARTClick(wxCommandEvent& event);
        void Onbutton_deliver_STARTClick(wxCommandEvent& event);
        void Onbutton_ROS_updateClick(wxCommandEvent& event);
        void Onbutton_spawn_objectsClick(wxCommandEvent& event);
        void Onbutton_PAUSEClick(wxCommandEvent& event);
        void ReinitializeSkype(wxCommandEvent& event);
        void OnMenuItem12Selected(wxCommandEvent& event);
        void spawnobjects(wxCommandEvent& event);
        void Onchoice_automatic_getSelect(wxCommandEvent& event);
        void Onchoice_automatic_searchSelect(wxCommandEvent& event);
        void Onchoice_automatic_fetchSelect(wxCommandEvent& event);
        void Onchoice_automatic_deliverSelect(wxCommandEvent& event);
        void Ontimer_choiceTrigger(wxTimerEvent& event);
        void removeObjects(wxCommandEvent& event);
        void removeDetectedObjects(wxCommandEvent& event);
        void spawnDetectedObjects(wxCommandEvent& event);
        void Ongrid_requestsCellLeftDClick(wxGridEvent& event);
        void Onchoice_automatic_moveSelect(wxCommandEvent& event);
        void Onimg_update_ontrayClick(wxCommandEvent& event);
        void Onimg_update_rosinfoClick(wxCommandEvent& event);
        void Onbut_navigation_dashboardClick(wxCommandEvent& event);
        void Onmenu_status_rxgraphSelected(wxCommandEvent& event);
        void Onmenu_status_runtimeMonitorSelected(wxCommandEvent& event);
        void runDashboard(wxCommandEvent& event);
        void Onbut_head_frontClick(wxCommandEvent& event);
        void Onbut_head_backClick(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void Onbut_RvizTools_AssistedArm_LaunchClick(wxCommandEvent& event);
        void Ontimer_dmServerTrigger(wxTimerEvent& event);
        void assistedArmNavigationOn(wxCommandEvent& event);
        void assistedArmNavigationOff(wxCommandEvent& event);
        void assistedGraspOn(wxCommandEvent& event);
        void assistedGraspOff(wxCommandEvent& event);
        void baseTeleopOn(wxCommandEvent& event);
        void baseTeleopOff(wxCommandEvent& event);
        void distanceLinuarOn(wxCommandEvent& event);
        void distanceLinuarOff(wxCommandEvent& event);
        void distanceCircularOn(wxCommandEvent& event);
        void distanceCircularOff(wxCommandEvent& event);
        void stretchIndicatorOn(wxCommandEvent& event);
        void stretchIndicatorOff(wxCommandEvent& event);
        void objectManagerOn(wxCommandEvent& event);
        void objectManagerOff(wxCommandEvent& event);
        void dataFusionOn(wxCommandEvent& event);
        void dataFusionOff(wxCommandEvent& event);
        void OnButton1Click2(wxCommandEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void Onbut_navigation_dashboardClick1(wxCommandEvent& event);
        void OnButton17Click(wxCommandEvent& event);
        void OnButton18Click(wxCommandEvent& event);
        void OnButton19Click(wxCommandEvent& event);
        void OnButton20Click(wxCommandEvent& event);
        void OnButton22Click(wxCommandEvent& event);
        void OnButton12Click(wxCommandEvent& event);
        void OnButton12Click1(wxCommandEvent& event);
        void OnButton23Click(wxCommandEvent& event);
        void OnButton21Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        //*)


        //(*Identifiers(srs_ui_proFrame)
        static const long ID_GRID1;
        static const long ID_STATICTEXT7;
        static const long ID_LISTCTRL1;
        static const long ID_PANEL10;
        static const long ID_LISTCTRL2;
        static const long ID_PANEL9;
        static const long ID_NOTEBOOK2;
        static const long ID_PANEL4;
        static const long ID_PANEL2;
        static const long ID_BUTTON14;
        static const long ID_TEXTCTRL6;
        static const long ID_CHOICE3;
        static const long ID_PANEL46;
        static const long ID_PANEL20;
        static const long ID_BUTTON13;
        static const long ID_TEXTCTRL3;
        static const long ID_CHOICE8;
        static const long ID_CHOICE4;
        static const long ID_STATICTEXT5;
        static const long ID_PANEL19;
        static const long ID_PANEL18;
        static const long ID_BUTTON19;
        static const long ID_TEXTCTRL9;
        static const long ID_CHOICE7;
        static const long ID_CHOICE5;
        static const long ID_STATICTEXT11;
        static const long ID_PANEL37;
        static const long ID_PANEL21;
        static const long ID_TEXTCTRL5;
        static const long ID_BUTTON1;
        static const long ID_CHOICE10;
        static const long ID_CHOICE9;
        static const long ID_CHOICE2;
        static const long ID_STATICTEXT13;
        static const long ID_PANEL30;
        static const long ID_PANEL22;
        static const long ID_BUTTON25;
        static const long ID_TEXTCTRL11;
        static const long ID_CHOICE12;
        static const long ID_CHOICE11;
        static const long ID_CHOICE6;
        static const long ID_STATICTEXT25;
        static const long ID_PANEL49;
        static const long ID_PANEL47;
        static const long ID_NOTEBOOK4;
        static const long ID_BUTTON16;
        static const long ID_BUTTON17;
        static const long ID_BUTTON15;
        static const long ID_TEXTCTRL17;
        static const long ID_PANEL11;
        static const long ID_BUTTON36;
        static const long ID_STATICBITMAP9;
        static const long ID_STATICTEXT15;
        static const long ID_BUTTON9;
        static const long ID_PANEL32;
        static const long ID_BUTTON37;
        static const long ID_BUTTON38;
        static const long ID_BUTTON40;
        static const long ID_BUTTON39;
        static const long ID_BUTTON41;
        static const long ID_BUTTON42;
        static const long ID_BUTTON44;
        static const long ID_BUTTON43;
        static const long ID_BUTTON46;
        static const long ID_BUTTON47;
        static const long ID_BUTTON45;
        static const long ID_STATICLINE7;
        static const long ID_STATICLINE6;
        static const long ID_STATICTEXT17;
        static const long ID_STATICTEXT22;
        static const long ID_STATICTEXT23;
        static const long ID_STATICTEXT36;
        static const long ID_STATICTEXT37;
        static const long ID_STATICTEXT46;
        static const long ID_STATICTEXT47;
        static const long ID_PANEL13;
        static const long ID_BUTTON5;
        static const long ID_PANEL27;
        static const long ID_STATICTEXT12;
        static const long ID_BUTTON33;
        static const long ID_COMBOBOX3;
        static const long ID_PANEL14;
        static const long ID_BUTTON6;
        static const long ID_CHOICE1;
        static const long ID_SPINCTRL1;
        static const long ID_BUTTON7;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT14;
        static const long ID_STATICBITMAP6;
        static const long ID_PANEL29;
        static const long ID_BUTTON22;
        static const long ID_PANEL45;
        static const long ID_PANEL42;
        static const long ID_PANEL39;
        static const long ID_PANEL41;
        static const long ID_PANEL43;
        static const long ID_PANEL44;
        static const long ID_STATICTEXT18;
        static const long ID_STATICTEXT20;
        static const long ID_STATICTEXT19;
        static const long ID_STATICTEXT21;
        static const long ID_PANEL40;
        static const long ID_PANEL28;
        static const long ID_PANEL15;
        static const long ID_NOTEBOOK3;
        static const long ID_PANEL12;
        static const long ID_STATICBITMAP3;
        static const long ID_STATICTEXT9;
        static const long ID_BUTTON3;
        static const long ID_PANEL24;
        static const long ID_RADIOBUTTON2;
        static const long ID_RADIOBUTTON3;
        static const long ID_RADIOBUTTON4;
        static const long ID_RADIOBUTTON5;
        static const long ID_RADIOBUTTON6;
        static const long ID_RADIOBUTTON1;
        static const long ID_PANEL23;
        static const long ID_BUTTON4;
        static const long ID_BUTTON10;
        static const long ID_STATICTEXT48;
        static const long ID_STATICTEXT49;
        static const long ID_PANEL33;
        static const long ID_BUTTON23;
        static const long ID_BUTTON31;
        static const long ID_BUTTON32;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT16;
        static const long ID_PANEL25;
        static const long ID_STATICTEXT41;
        static const long ID_RADIOBUTTON13;
        static const long ID_RADIOBUTTON14;
        static const long ID_PANEL65;
        static const long ID_STATICTEXT42;
        static const long ID_RADIOBUTTON15;
        static const long ID_RADIOBUTTON16;
        static const long ID_COMBOBOX5;
        static const long ID_PANEL66;
        static const long ID_STATICTEXT43;
        static const long ID_RADIOBUTTON17;
        static const long ID_RADIOBUTTON18;
        static const long ID_COMBOBOX6;
        static const long ID_PANEL67;
        static const long ID_STATICTEXT44;
        static const long ID_RADIOBUTTON19;
        static const long ID_RADIOBUTTON20;
        static const long ID_PANEL68;
        static const long ID_STATICTEXT45;
        static const long ID_RADIOBUTTON21;
        static const long ID_RADIOBUTTON22;
        static const long ID_PANEL69;
        static const long ID_STATICTEXT38;
        static const long ID_RADIOBUTTON9;
        static const long ID_RADIOBUTTON10;
        static const long ID_PANEL62;
        static const long ID_STATICTEXT39;
        static const long ID_RADIOBUTTON11;
        static const long ID_RADIOBUTTON12;
        static const long ID_PANEL63;
        static const long ID_STATICTEXT40;
        static const long ID_RADIOBUTTON7;
        static const long ID_RADIOBUTTON8;
        static const long ID_PANEL64;
        static const long ID_PANEL60;
        static const long ID_NOTEBOOK5;
        static const long ID_PANEL17;
        static const long ID_NOTEBOOK1;
        static const long ID_PANEL7;
        static const long ID_PANEL6;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL1;
        static const long ID_GAUGE1;
        static const long ID_STATICTEXT2;
        static const long ID_GAUGE2;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT24;
        static const long ID_PANEL52;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT6;
        static const long ID_PANEL53;
        static const long ID_PANEL51;
        static const long ID_PANEL5;
        static const long ID_TEXTCTRL13;
        static const long ID_PANEL57;
        static const long ID_TEXTCTRL15;
        static const long ID_PANEL56;
        static const long ID_TEXTCTRL16;
        static const long ID_PANEL58;
        static const long ID_TEXTCTRL18;
        static const long ID_PANEL59;
        static const long ID_NOTEBOOK7;
        static const long ID_BITMAPBUTTON2;
        static const long ID_PANEL55;
        static const long ID_SCROLLEDWINDOW2;
        static const long ID_PANEL61;
        static const long ID_STATICTEXT28;
        static const long ID_STATICTEXT29;
        static const long ID_COMBOBOX1;
        static const long ID_STATICTEXT30;
        static const long ID_BUTTON8;
        static const long ID_STATICLINE2;
        static const long ID_STATICLINE3;
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT31;
        static const long ID_STATICTEXT33;
        static const long ID_STATICTEXT32;
        static const long ID_COMBOBOX2;
        static const long ID_TEXTCTRL19;
        static const long ID_BUTTON21;
        static const long ID_BUTTON20;
        static const long ID_PANEL8;
        static const long ID_STATICTEXT34;
        static const long ID_STATICLINE4;
        static const long ID_STATICTEXT35;
        static const long ID_STATICLINE5;
        static const long ID_COMBOBOX4;
        static const long ID_BUTTON18;
        static const long ID_BUTTON2;
        static const long ID_PANEL26;
        static const long ID_NOTEBOOK6;
        static const long ID_PANEL16;
        static const long ID_PANEL54;
        static const long ID_STATICTEXT26;
        static const long ID_STATICTEXT27;
        static const long ID_SCROLLEDWINDOW1;
        static const long ID_PANEL1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_PANEL31;
        static const long ID_PANEL3;
        static const long idMenuQuit;
        static const long ID_MENUITEM10;
        static const long ID_MENUITEM11;
        static const long ID_MENUITEM13;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM6;
        static const long ID_MENUITEM17;
        static const long ID_MENUITEM18;
        static const long ID_MENUITEM19;
        static const long ID_MENUITEM21;
        static const long ID_MENUITEM22;
        static const long ID_MENUITEM20;
        static const long ID_MENUITEM16;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM9;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM7;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM12;
        static const long ID_MENUITEM15;
        static const long ID_MENUITEM14;
        static const long ID_MENUITEM23;
        static const long ID_MENUITEM24;
        static const long ID_MENUITEM8;
        static const long idMenuAbout;
        static const long ID_TIMER1;
        static const long ID_TIMER2;
        static const long ID_TIMER3;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER4;
        static const long ID_TIMER5;
        static const long ID_TIMER6;
        static const long ID_TIMER7;
        //*)


        //(*Declarations(srs_ui_proFrame)
        wxStaticText* label_Category;
        wxButton* but_SimulateGrasp;
        wxRadioButton* option_joystick_Base;
        wxComboBox* choice_objectstodetect;
        wxPanel* tab_assisted;
        wxChoice* choice_selected_grasp_object;
        wxPanel* panel_ts22;
        wxPanel* tab_services;
        wxStaticText* StaticText1;
        wxMenu* menu_rviz_vis;
        wxStaticText* label_TeachNewTask;
        wxMenuItem* MenuItem8;
        wxPanel* tab_topics;
        wxPanel* Panel2;
        wxComboBox* choice_TasksList;
        wxPanel* panel_ts32;
        wxRadioButton* RadioButton14;
        wxTimer timer_RequestsEvent;
        wxTextCtrl* box_ObjectName;
        wxPanel* panel_automatic_get;
        wxPanel* tab_automatic_search;
        wxGauge* bar_status_battery;
        wxStaticText* StaticText13;
        wxStaticLine* separador4;
        wxStaticText* label_ObjectsOnTray;
        wxTextCtrl* box_ROS_services;
        wxStaticText* label_Result;
        wxTimer timer_choice;
        wxPanel* tab_semi_detection;
        wxTimer timer_ROS;
        wxPanel* tab_manual;
        wxStatusBar* StatusBar1;
        wxStaticText* StaticText20;
        wxPanel* Panel7;
        wxStaticText* label_TS_TactilSensors;
        wxButton* Button22;
        wxStaticText* label_status_TimeRemaining;
        wxStaticBitmap* img_navigation_dashboard;
        wxStaticLine* StaticLine2;
        wxMenuItem* option_skype_restart;
        wxTextCtrl* box_status_RobotURI;
        wxStaticText* StaticText6;
        wxPanel* tab_Rviz;
        wxComboBox* ComboBox2;
        wxTextCtrl* box_dm_log;
        wxMenuItem* menu_status_rxgraph;
        wxPanel* tab_semi_navigation;
        wxStaticText* StaticText18;
        wxNotebook* tabs_decisionmaking;
        wxStaticText* StaticText17;
        wxNotebook* tabs_subROS;
        wxPanel* panel_ts31;
        wxTimer timer_URI;
        wxPanel* panel_grasping;
        wxPanel* tab_joystick;
        wxButton* but_move_Start;
        wxStaticText* StaticText15;
        wxButton* Button13;
        wxStaticText* label_search_Optional;
        wxButton* but_DetectObjects;
        wxStaticLine* StaticLine1;
        wxButton* but_Cancel;
        wxPanel* panel_ts21;
        wxStaticText* label_status_TimeBattery;
        wxStaticText* label_get_Optional;
        wxButton* Button18;
        wxButton* but_RESUME;
        wxComboBox* choice_category;
        wxStaticText* label_status_RobotUri;
        wxRadioButton* RadioButton9;
        wxPanel* panel_detected_objects;
        wxPanel* panel_automatic_deliver;
        wxMenu* menu_skype;
        wxButton* but_TeachNewObjectStart;
        wxPanel* tab_skype_contacts;
        wxStaticText* label_TS_F2;
        wxPanel* panel_status;
        wxStaticText* label_DatabaseObjectsList;
        wxButton* but_get_Start;
        wxRadioButton* RadioButton1;
        wxButton* but_fetch_Start;
        wxPanel* tab_tasks;
        wxStaticBitmap* img_joystick_unused1;
        wxStaticText* label_TeachNewObjectBy;
        wxMenu* menu_rviz_manip;
        wxChoice* choice_automatic_get;
        wxStaticText* StaticText3;
        wxPanel* panel_options_main;
        wxPanel* Panel5;
        wxButton* Button20;
        wxButton* but_STOP;
        wxMenu* Menu6;
        wxStaticText* label_deliver_Optional;
        wxBitmapButton* img_update_rosinfo;
        wxStaticText* StaticText2;
        wxButton* Button14;
        wxRadioButton* option_joystick_Tray;
        wxPanel* tab_skype_IncomingCalls;
        wxTextCtrl* box_automatic_move_small;
        wxPanel* panel_db_objects;
        wxStaticLine* separador3;
        wxRadioButton* option_joystick_Torso;
        wxBitmapButton* img_update_ontray;
        wxPanel* panel_automatic_search;
        wxStaticText* label_fetch_Optional;
        wxPanel* tab_automatic_deliver;
        wxPanel* panel_joystick_unused1;
        wxPanel* panel_status_log;
        wxTextCtrl* box_automatic_search_small;
        wxStaticText* label_ontray;
        wxStaticLine* separador1;
        wxRadioButton* RadioButton15;
        wxButton* but_joystick_unused1;
        wxMenu* menu_rviz;
        wxStaticText* label_ObjectName;
        wxStaticText* label_joystick_unnused1;
        wxButton* but_GraspIt;
        wxPanel* Panel3;
        wxPanel* Panel6;
        wxTextCtrl* box_ROS_params;
        wxGrid* grid_requests;
        wxNotebook* tabs_subsemi;
        wxStaticText* label_TasksList;
        wxButton* but_PAUSE;
        wxScrolledWindow* scrollablewindow_dbobjects;
        wxStaticText* StaticText16;
        wxPanel* panel_TactilSensors;
        wxButton* Button17;
        wxRadioButton* RadioButton2;
        wxMenu* menu_status;
        wxRadioButton* RadioButton7;
        wxPanel* panel_ts12;
        wxStaticText* label_TeachNewObject;
        wxPanel* panel_options;
        wxChoice* choice_automatic_move;
        wxButton* Button2;
        wxRadioButton* RadioButton3;
        wxButton* Button1;
        wxPanel* tab_RvizTools;
        wxMenuItem* MenuItem16;
        wxStaticText* label_Requests;
        wxStaticText* label_DefineTheObject;
        wxPanel* panel_comunications;
        wxStaticLine* separador2;
        wxButton* but_search_Start;
        wxPanel* panel_comunications_main;
        wxStaticText* label_TS_F1;
        wxButton* Button16;
        wxPanel* panel_actions_main;
        wxMenuItem* option_skype_start;
        wxPanel* panel_automatic_fetch;
        wxButton* Button5;
        wxMenuItem* MenuItem15;
        wxListCtrl* grid_skype_contactList;
        wxTimer timer_skype_contacts;
        wxRadioButton* RadioButton16;
        wxPanel* panel_ts11;
        wxMenuItem* MenuItem19;
        wxStaticText* label_DetectedObjects;
        wxGauge* bar_status_wifi;
        wxNotebook* tabs_submanual;
        wxStaticText* StaticText14;
        wxStaticText* StaticText4;
        wxRadioButton* option_joystick_Arm;
        wxPanel* panel_objects_on_tray;
        wxPanel* panel_status_main;
        wxStaticText* StaticText8;
        wxRadioButton* option_joystick_Hand;
        wxTimer timer_updates;
        wxTextCtrl* box_ROS_nodes;
        wxStaticText* label_navigation_dashboard;
        wxChoice* choice_automatic_fetch_order;
        wxPanel* panel_main;
        wxPanel* Panel8;
        wxTextCtrl* box_status_log;
        wxNotebook* tabs_actions;
        wxRadioButton* RadioButton6;
        wxButton* Button19;
        wxPanel* tab_automatic_move;
        wxPanel* tab_semi_grasping;
        wxStaticText* StaticText9;
        wxButton* but_GenerateGrasps;
        wxPanel* tab_ROS;
        wxScrolledWindow* scrollablewindow_ontray;
        wxMenu* MenuItem17;
        wxRadioButton* RadioButton10;
        wxPanel* tab_automatic_get;
        wxTextCtrl* box_automatic_deliver_small;
        wxButton* but_StopTask;
        wxStaticText* StaticText19;
        wxRadioButton* RadioButton12;
        wxButton* Button3;
        wxStaticLine* separador5;
        wxPanel* tab_params;
        wxPanel* panel_navigation_dashboard;
        wxStaticText* label_status_log;
        wxTextCtrl* box_automatic_fetch_small;
        wxRadioButton* RadioButton11;
        wxRadioButton* RadioButton5;
        wxMenu* MenuItem18;
        wxRadioButton* RadioButton13;
        wxNotebook* tabs_options;
        wxStaticBitmap* img_graspResult;
        wxButton* Button15;
        wxSpinCtrl* choice_grasp_conf;
        wxPanel* panel_actions;
        wxChoice* choice_automatic_fetch;
        wxChoice* choice_automatic_search_search;
        wxPanel* Panel1;
        wxStaticText* label_status_Battery;
        wxNotebook* tabs_skype;
        wxMenuItem* MenuItem9;
        wxMenuItem* menu_rviz_run;
        wxPanel* panel_automatic_move;
        wxMenuItem* MenuItem5;
        wxStaticText* label_status_WifiSignal;
        wxTextCtrl* box_ROS_topics;
        wxChoice* choice_automatic_get_search;
        wxPanel* panel_grasp_result;
        wxButton* but_SpawnObjectsInRviz;
        wxButton* but_navigation_dashboard;
        wxChoice* choice_automatic_search;
        wxButton* Button23;
        wxPanel* tab_automatic_fetch;
        wxMenuItem* MenuItem7;
        wxMenu* menu_dashboard;
        wxChoice* choice_automatic_deliver_search;
        wxStaticText* label_TS_F3;
        wxStaticText* StaticText7;
        wxRadioButton* option_joystick_Head;
        wxPanel* tab_nodes;
        wxStaticText* StaticText11;
        wxMenuItem* MenuItem11;
        wxComboBox* choice_TeachNewObject;
        wxTimer timer_dmServer;
        wxPanel* tab_objects;
        wxMenuItem* menu_dashboard_run;
        wxStaticText* StaticText12;
        wxButton* but_StartTask;
        wxRadioButton* RadioButton4;
        wxPanel* tab_automatic;
        wxChoice* choice_automatic_fetch_search;
        wxPanel* panel_ontray_main;
        wxTextCtrl* box_automatic_get_small;
        wxStaticText* StaticText10;
        wxChoice* choice_automatic_deliver;
        wxButton* but_Save;
        wxStaticText* StaticText5;
        wxComboBox* ComboBox1;
        wxPanel* tab_semi;
        wxButton* but_deliver_Start;
        wxButton* Button21;
        wxTextCtrl* box_graspResult;
        wxListCtrl* grid_skype_IncomingCalls;
        wxPanel* Panel4;
        wxButton* Button12;
        wxButton* Button4;
        wxPanel* panel_status_RobotInfo;
        wxChoice* choice_automatic_deliver_deliver_position;
        wxRadioButton* RadioButton8;
        //*)

        bool DM_W_launched;

        DECLARE_EVENT_TABLE()
};
#endif // srs_ui_proMAIN_H
