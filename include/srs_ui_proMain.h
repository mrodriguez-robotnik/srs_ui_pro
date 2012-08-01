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
#include "ObjectInfo.h"
#include "SkypeFunctions.h"
#include "SkypeWindow.h"
#include "SkypeWindow2.h"


#define     RVIZ_CONFIG_FILE    "~/local_packages/srs_ui_pro/rviz_config/config"
#define     BLUE                *wxBLUE
#define     RED                 *wxRED
#define     BLACK               *wxBLACK

class srs_ui_proFrame: public wxFrame
{
    public:

        srs_ui_proFrame(wxWindow* parent,wxWindowID id = -1);
        ~srs_ui_proFrame();

    private:

        SkypeFunctions *SF;
        RosInterface *Ri;
        ProcessManager *PM;

        std::vector<wxStaticBitmap*> ts_finger11, ts_finger12, ts_finger21, ts_finger22, ts_finger31, ts_finger32;
        int num_events;
        std::string last_chat_user;
        bool dm_working, dm_move_working, dm_get_working, dm_search_working, dm_fetch_working, dm_deliver_working;
        bool run_notification;
        std::string last_state;
        std::vector<wxBitmapButton*> img_objects;
        std::vector<wxBitmapButton*> img_objects_on_tray;
        std::vector<wxBitmapButton*> img_db_objects;
        std::vector<cob_object_detection_msgs::Detection> detected_objects;
        std::vector<srs_msgs::FeasibleGrasp> generated_grasps;



        void writeInLog(std::string text="ERROR: Unknown error.\n", wxColour colour=RED);
        void writeInDMLog(std::string text="ERROR: Unknown error.\n", wxColour colour=RED);
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
        void InitSkype();
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
            std::vector<int> prueba;
        };

        void *_THREAD_StartAssistedArm(void);
        static void *THREAD_StartAssistedArm(void *arg){
            return ((srs_ui_proFrame*)arg)->_THREAD_StartAssistedArm();
        }

        void *_THREAD_GenerateGrasps(void);
        static void *THREAD_GenerateGrasps(void *arg){
            return ((srs_ui_proFrame*)arg)->_THREAD_GenerateGrasps();
        }

        void *_THREAD_DMAction(std::string actions, std::string parameters);
        static void *THREAD_DMAction(void *argumento){
            dm_thread_arg *arg = (dm_thread_arg*)argumento;
            return (srs_ui_proFrame*)(arg->form)->_THREAD_DMAction((arg->action).c_str(), arg->parameters);
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
        void OnTimer1Trigger(wxTimerEvent& event);
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
        void manual_phantomHapticButton(wxCommandEvent& event);
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
        void Ongrid_request_eventsLabelLeftDClick(wxGridEvent& event);
        void Ongrid_request_eventsCellLeftClick(wxGridEvent& event);
        void Onbutton_GoToStartClick(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnButton9Click(wxCommandEvent& event);
        void Onskype_timerTrigger(wxTimerEvent& event);
        void Onskype_timerTrigger1(wxTimerEvent& event);
        void runDashboard(wxCommandEvent& event);
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
        static const long ID_TEXTCTRL7;
        static const long ID_CHOICE3;
        static const long ID_PANEL46;
        static const long ID_PANEL20;
        static const long ID_BUTTON13;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL8;
        static const long ID_CHOICE8;
        static const long ID_CHOICE4;
        static const long ID_STATICTEXT5;
        static const long ID_PANEL19;
        static const long ID_PANEL18;
        static const long ID_BUTTON19;
        static const long ID_TEXTCTRL9;
        static const long ID_TEXTCTRL10;
        static const long ID_CHOICE7;
        static const long ID_CHOICE5;
        static const long ID_STATICTEXT11;
        static const long ID_PANEL37;
        static const long ID_PANEL21;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL14;
        static const long ID_BUTTON1;
        static const long ID_CHOICE10;
        static const long ID_CHOICE9;
        static const long ID_CHOICE2;
        static const long ID_STATICTEXT13;
        static const long ID_PANEL30;
        static const long ID_PANEL22;
        static const long ID_BUTTON25;
        static const long ID_TEXTCTRL11;
        static const long ID_TEXTCTRL12;
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
        static const long ID_STATICBITMAP9;
        static const long ID_STATICTEXT15;
        static const long ID_BUTTON9;
        static const long ID_PANEL32;
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
        static const long ID_STATICBITMAP10;
        static const long ID_STATICTEXT16;
        static const long ID_BUTTON10;
        static const long ID_PANEL33;
        static const long ID_STATICBITMAP11;
        static const long ID_STATICTEXT17;
        static const long ID_BUTTON11;
        static const long ID_PANEL34;
        static const long ID_STATICBITMAP13;
        static const long ID_STATICTEXT23;
        static const long ID_BUTTON30;
        static const long ID_PANEL36;
        static const long ID_STATICBITMAP12;
        static const long ID_STATICTEXT22;
        static const long ID_BUTTON12;
        static const long ID_PANEL35;
        static const long ID_STATICBITMAP1;
        static const long ID_STATICTEXT8;
        static const long ID_BUTTON4;
        static const long ID_PANEL38;
        static const long ID_PANEL25;
        static const long ID_STATICBITMAP5;
        static const long ID_STATICTEXT10;
        static const long ID_BUTTON23;
        static const long ID_PANEL50;
        static const long ID_PANEL48;
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
        static const long idMenuAbout;
        static const long ID_TIMER1;
        static const long ID_TIMER2;
        static const long ID_TIMER3;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER4;
        static const long ID_TIMER5;
        static const long ID_TIMER6;
        //*)


        //(*Declarations(srs_ui_proFrame)
        wxPanel* panel_tasks;
        wxButton* button_simulateGrasp;
        wxComboBox* choice_objectstodetect;
        wxChoice* choice_selected_grasp_object;
        wxPanel* panel_ts22;
        wxPanel* tab_services;
        wxStaticText* StaticText1;
        wxMenu* menu_rviz_vis;
        wxStaticText* StaticText23;
        wxMenuItem* MenuItem8;
        wxPanel* tab_topics;
        wxButton* button_im_distance;
        wxPanel* panel_ts32;
        wxTimer timer_RequestsEvent;
        wxPanel* tab_automatic_search;
        wxStaticText* StaticText13;
        wxButton* button_PAUSE;
        wxTextCtrl* box_ROS_services;
        wxPanel* panel_tactil;
        wxTimer Timer1;
        wxStaticBitmap* img_assisted_arm;
        wxTimer timer_choice;
        wxPanel* tab_semi_detection;
        wxTimer timer_ROS;
        wxPanel* tab_manual;
        wxStatusBar* StatusBar1;
        wxStaticText* StaticText20;
        wxPanel* Panel7;
        wxStaticLine* StaticLine2;
        wxPanel* PanelConnectionInf;
        wxStaticText* StaticText6;
        wxComboBox* ComboBox2;
        wxPanel* Panel13;
        wxPanel* tab_semi_navigation;
        wxStaticText* StaticText18;
        wxButton* Button8;
        wxStaticText* StaticText17;
        wxStaticText* StaticText24;
        wxPanel* panel_ts31;
        wxTimer timer_URI;
        wxNotebook* chat;
        wxStaticText* StaticText15;
        wxPanel* panel_GetMilk_sub;
        wxMenuItem* MenuItem12;
        wxStaticLine* StaticLine1;
        wxPanel* panel_ts21;
        wxPanel* Panel30;
        wxStaticBitmap* img_goto;
        wxButton* button_GoToStart;
        wxTextCtrl* box_automatic_move_big;
        wxPanel* panel_detected_objects;
        wxMenu* menu_skype;
        wxButton* button_im_assistedarm;
        wxStaticText* StaticText22;
        wxPanel* panel_objects;
        wxRadioButton* RadioButton1;
        wxPanel* PanelStatus;
        wxMenu* menu_rviz_manip;
        wxChoice* choice_automatic_get;
        wxStaticText* StaticText3;
        wxPanel* panel_options_main;
        wxNotebook* tab_options;
        wxTextCtrl* box_automatic_fetch_big;
        wxMenu* Menu6;
        wxPanel* PanelIncomingCalls;
        wxStaticText* StaticText2;
        wxBitmapButton* img_update_rosinfo;
        wxTextCtrl* box_automatic_move_small;
        wxNotebook* PanelSemi_sub;
        wxPanel* panel_db_objects;
        wxButton* button_im_goto;
        wxTextCtrl* box_automatic_search_big;
        wxBitmapButton* img_update_ontray;
        wxStaticText* StaticText27;
        wxPanel* tab_automatic_deliver;
        wxTextCtrl* box_automatic_search_small;
        wxTextCtrl* box_automatic_get_big;
        wxStaticText* label_ontray;
        wxStaticText* label;
        wxNotebook* NotebookFull;
        wxStaticText* label_result;
        wxMenu* menu_rviz;
        wxListCtrl* notebook_skype_contacts_contactList;
        wxPanel* Panel6;
        wxTextCtrl* box_ROS_params;
        wxGrid* grid_requests;
        wxButton* button_STOP;
        wxPanel* panel_ROS;
        wxPanel* Panel28;
        wxScrolledWindow* scrollablewindow_dbobjects;
        wxStaticText* StaticText16;
        wxRadioButton* RadioButton2;
        wxPanel* panel_ts12;
        wxPanel* panel_options;
        wxChoice* choice_automatic_move;
        wxButton* Button2;
        wxRadioButton* RadioButton3;
        wxButton* Button1;
        wxPanel* Panel24;
        wxMenuItem* MenuItem16;
        wxPanel* PanelCommunications;
        wxPanel* panel_comunications_main;
        wxButton* Button16;
        wxButton* button_generate_grasps;
        wxStaticBitmap* StaticBitmap3;
        wxPanel* panel_actions_main;
        wxTextCtrl* box_robot_URI;
        wxMenuItem* option_skype_start;
        wxButton* Button5;
        wxStaticBitmap* img_distanceVisualizer;
        wxMenuItem* MenuItem15;
        wxStaticText* StaticText25;
        wxPanel* panel_GoTo_sub;
        wxStaticText* StaticText26;
        wxTimer timer_skype_contacts;
        wxPanel* Panel14;
        wxPanel* panel_ts11;
        wxMenuItem* MenuItem19;
        wxPanel* Panel12;
        wxStaticBitmap* img_movebase;
        wxStaticText* StaticText14;
        wxStaticText* StaticText4;
        wxPanel* panel_objects_on_tray;
        wxStaticText* StaticText8;
        wxPanel* panel_status_main;
        wxTextCtrl* box_ROS_nodes;
        wxChoice* choice_automatic_fetch_order;
        wxPanel* panel_main;
        wxPanel* Panel8;
        wxRadioButton* RadioButton6;
        wxPanel* tab_automatic_move;
        wxButton* button_RESUME;
        wxPanel* tab_semi_grasping;
        wxStaticText* StaticText9;
        wxPanel* Panel10;
        wxStaticText* StaticText21;
        wxTextCtrl* TextCtrl1;
        wxButton* button_im_cam;
        wxScrolledWindow* scrollablewindow_ontray;
        wxMenu* MenuItem17;
        wxTextCtrl* box_automatic_deliver_big;
        wxTextCtrl* box_automatic_log;
        wxPanel* tab_automatic_get;
        wxStaticText* StaticText29;
        wxTextCtrl* box_automatic_deliver_small;
        wxPanel* Panel9;
        wxStaticText* StaticText19;
        wxPanel* Panel21;
        wxButton* Button7;
        wxButton* Button3;
        wxPanel* Panel19;
        wxButton* button_detect_objects;
        wxPanel* tab_params;
        wxTextCtrl* box_automatic_fetch_small;
        wxRadioButton* RadioButton5;
        wxPanel* Panel11;
        wxMenu* MenuItem18;
        wxButton* button_GraspIt;
        wxStaticBitmap* img_graspResult;
        wxButton* button_GetMilkStart;
        wxStaticLine* StaticLine3;
        wxNotebook* tab_actions;
        wxSpinCtrl* choice_grasp_conf;
        wxPanel* panel_actions;
        wxChoice* choice_automatic_fetch;
        wxPanel* Panel20;
        wxChoice* choice_automatic_search_search;
        wxStaticText* StaticText28;
        wxListCtrl* notebook_skype_incoming_calls_incomingList;
        wxMenuItem* MenuItem9;
        wxMenuItem* menu_rviz_run;
        wxPanel* Panel26;
        wxMenuItem* MenuItem5;
        wxTextCtrl* box_ROS_topics;
        wxChoice* choice_automatic_get_search;
        wxStaticBitmap* StaticBitmap6;
        wxPanel* panel_grasp_result;
        wxGauge* bar_wifi_signal;
        wxChoice* choice_automatic_search;
        wxButton* button_spawn_objects;
        wxPanel* tab_automatic_fetch;
        wxMenuItem* MenuItem7;
        wxPanel* panelrandom;
        wxMenu* menu_dashboard;
        wxChoice* choice_automatic_deliver_search;
        wxStaticText* StaticText7;
        wxPanel* tab_nodes;
        wxStaticText* StaticText11;
        wxMenuItem* MenuItem11;
        wxStaticBitmap* img_camDisplay;
        wxGauge* bar_battery;
        wxButton* button_im_mb;
        wxMenuItem* menu_dashboard_run;
        wxStaticText* StaticText12;
        wxRadioButton* RadioButton4;
        wxPanel* tab_automatic;
        wxStaticBitmap* StaticBitmap2;
        wxChoice* choice_automatic_fetch_search;
        wxPanel* panel_ontray_main;
        wxTextCtrl* box_automatic_get_small;
        wxTextCtrl* log_box;
        wxNotebook* PanelManual_sub;
        wxStaticText* StaticText10;
        wxChoice* choice_automatic_deliver;
        wxStaticText* StaticText5;
        wxComboBox* ComboBox1;
        wxNotebook* Notebook1;
        wxPanel* tab_semi;
        wxStaticText* label_time_battery;
        wxTextCtrl* box_graspResult;
        wxButton* Button12;
        wxButton* Button4;
        wxChoice* choice_automatic_deliver_deliver_position;
        //*)



        DECLARE_EVENT_TABLE()
};
#endif // srs_ui_proMAIN_H
