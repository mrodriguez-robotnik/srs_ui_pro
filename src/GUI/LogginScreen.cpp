#include "LogginScreen.h"

//(*InternalHeaders(LogginScreen)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//(*IdInit(LogginScreen)
const long LogginScreen::ID_STATICBITMAP1 = wxNewId();
const long LogginScreen::ID_TEXTCTRL1 = wxNewId();
const long LogginScreen::ID_STATICTEXT1 = wxNewId();
const long LogginScreen::ID_TEXTCTRL2 = wxNewId();
const long LogginScreen::ID_STATICTEXT2 = wxNewId();
const long LogginScreen::ID_BUTTON1 = wxNewId();
const long LogginScreen::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LogginScreen,wxFrame)
	//(*EventTable(LogginScreen)
	//*)
END_EVENT_TABLE()

LogginScreen::LogginScreen(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(LogginScreen)
	Create(parent, wxID_ANY, _("SRS_UI_PRO"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(325,456));
	SetMinSize(wxSize(325,456));
	SetMaxSize(wxSize(325,456));
	SetForegroundColour(wxColour(0,0,0));
	img_background = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("./img/logscreen.jpeg"))), wxPoint(0,0), wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
	img_background->SetFocus();
	box_user = new wxTextCtrl(this, ID_TEXTCTRL1, _("srs_ui_pro"), wxPoint(8,26), wxSize(152,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	label_user = new wxStaticText(this, ID_STATICTEXT1, _("User:"), wxPoint(8,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	label_user->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	label_user->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	box_pass = new wxTextCtrl(this, ID_TEXTCTRL2, _("Robotnik2012"), wxPoint(8,83), wxSize(152,27), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	label_pass = new wxStaticText(this, ID_STATICTEXT2, _("Password:"), wxPoint(8,65), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	label_pass->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	label_pass->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	but_init = new wxButton(this, ID_BUTTON1, _("Init Session"), wxPoint(8,120), wxSize(88,25), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	but_offline = new wxButton(this, ID_BUTTON2, _("Offline"), wxPoint(96,120), wxSize(64,25), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Center();
	
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LogginScreen::Onbut_initClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LogginScreen::Onbut_offlineClick);
	//*)

	SF = new SkypeFunctions();
	PM = new ProcessManager();
	InitSkype();
}

LogginScreen::~LogginScreen()
{
	//(*Destroy(LogginScreen)
	//*)
}

void LogginScreen::Onbut_initClick(wxCommandEvent& event)
{
    SF->setAccountInfo(std::string(box_user->GetValue().mb_str()), std::string(box_pass->GetValue().mb_str()));
    srs_ui_proFrame* Frame = new srs_ui_proFrame(0, SF, PM, false);
    Frame->Show();
    Close();

}

void LogginScreen::InitSkype()
{
    if (PM->WaitSkypeRuntime() == -4)
        PM->KillSkypeRuntime();

    printf("----------------------------------------------------------------------------\n");
    fflush(stdout);

    try
    {
        std::string runtime_path = ros::package::getPath("srs_ui_pro") + "/skype_utils/skype-runtime";
        if (PM->ExecSkypeRuntime(runtime_path) == 0)
        {
            SF->initialize();
        }
        else
            ROS_ERROR("[SKYPE ERROR]: skype_runtime does't exist.\n");
    }
    catch(SkypeException &e) { ROS_ERROR("meeeec"); }
    printf("----------------------------------------------------------------------------\n");
    fflush(stdout);
}



void LogginScreen::Onbut_offlineClick(wxCommandEvent& event)
{
    srs_ui_proFrame* Frame = new srs_ui_proFrame(0, SF, PM, true);
    Frame->Show();
    Close();
}
