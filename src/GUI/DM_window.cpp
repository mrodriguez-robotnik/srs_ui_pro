#include "DM_window.h"

//(*InternalHeaders(DM_window)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

//(*IdInit(DM_window)
const long DM_window::ID_TEXTCTRL1 = wxNewId();
const long DM_window::ID_STATICTEXT1 = wxNewId();
const long DM_window::ID_TEXTCTRL2 = wxNewId();
const long DM_window::ID_STATICTEXT2 = wxNewId();
const long DM_window::ID_BUTTON1 = wxNewId();
const long DM_window::ID_BUTTON2 = wxNewId();
const long DM_window::ID_BUTTON3 = wxNewId();
const long DM_window::ID_STATICLINE1 = wxNewId();
const long DM_window::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DM_window,wxFrame)
	//(*EventTable(DM_window)
	//*)
END_EVENT_TABLE()

DM_window::DM_window(wxWindow* parent, std::string msg, wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DM_window)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxCAPTION|wxCLOSE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(410,376));
	user_intervention_window = new wxPanel(this, ID_PANEL1, wxPoint(8,16), wxSize(410,352), 0, _T("ID_PANEL1"));
	box_message = new wxTextCtrl(user_intervention_window, ID_TEXTCTRL1, _("Aquí va el mensaje de ayuda que recibimos"), wxPoint(16,24), wxSize(376,104), wxTE_MULTILINE|wxTE_READONLY|wxHSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	label_title = new wxStaticText(user_intervention_window, ID_STATICTEXT1, _("USER INTERVENTION MESSAGE"), wxPoint(16,8), wxSize(216,17), 0, _T("ID_STATICTEXT1"));
	wxFont label_titleFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	label_title->SetFont(label_titleFont);
	box_feedback = new wxTextCtrl(user_intervention_window, ID_TEXTCTRL2, _("Aquí el feedback que queremos enviar\n"), wxPoint(16,192), wxSize(288,72), wxTE_MULTILINE|wxHSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	label_feedback = new wxStaticText(user_intervention_window, ID_STATICTEXT2, _("Feedback"), wxPoint(16,176), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	but_feedback = new wxButton(user_intervention_window, ID_BUTTON1, _("     Send \nfeedback"), wxPoint(312,192), wxSize(80,72), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	but_suc = new wxButton(user_intervention_window, ID_BUTTON2, _("Succeeded"), wxPoint(16,312), wxSize(184,29), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	but_fail = new wxButton(user_intervention_window, ID_BUTTON3, _("Failed"), wxPoint(208,312), wxSize(184,29), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	line_separator = new wxStaticLine(user_intervention_window, ID_STATICLINE1, wxPoint(16,296), wxSize(376,16), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DM_window::sendFeedback);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DM_window::sendSucceeded);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DM_window::sendFailed);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&DM_window::OnClose);
	//*)

	box_message->SetValue(wxString(getMsgInformation(msg).c_str(), wxConvUTF8));
        srs_ui_pro_pub = n.advertise<srs_ui_pro::srs_ui_proEcho>("/srs_ui_pro/gui/status", 30);
}

DM_window::~DM_window()
{
	//(*Destroy(DM_window)
	//*)
}

std::string DM_window::getMsgInformation(std::string msg)
{
    std::string search = "new_event:";
    int init = msg.find(search.c_str())+search.size();

    if (msg.size()>2)
        return msg.substr(init, msg.size()-init-2); //-2 for delete the string }"
    else return msg;
}

void DM_window::sendFeedback(wxCommandEvent& event)
{
    srs_ui_pro::srs_ui_proEcho srs_echo;
    srs_echo.status = 42;
    srs_echo.feedback = std::string(box_feedback->GetValue().mb_str());

    srs_ui_pro_pub.publish(srs_echo);
}

void DM_window::sendSucceeded(wxCommandEvent& event)
{
    wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Are you sure?"), wxT("srs_ui_pro: The task will end with the FAILED value!"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
    int res = dial->ShowModal();

    if (res == wxID_YES)
    {
        srs_ui_pro::srs_ui_proEcho srs_echo;
        srs_echo.status = 1;
        srs_echo.feedback = "Task finished with the result: succeeded";
        srs_ui_pro_pub.publish(srs_echo);
        Destroy();
    }
}

void DM_window::sendFailed(wxCommandEvent& event)
{
    wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Are you sure?"), wxT("srs_ui_pro: The task will end with the SUCCEEDED value!"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
    int res = dial->ShowModal();

    if (res == wxID_YES)
    {
        srs_ui_pro::srs_ui_proEcho srs_echo;
        srs_echo.status = -1;
        srs_echo.feedback = "Task finished with the result: failed";
        srs_ui_pro_pub.publish(srs_echo);
        Destroy();
    }
}

void DM_window::OnClose(wxCloseEvent& event)
{
    wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Are you sure?"), wxT("srs_ui_pro: If you close the window, the task will end with the FAILED value!"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
    int res = dial->ShowModal();

    if (res == wxID_YES)
    {
        srs_ui_pro::srs_ui_proEcho srs_echo;
        srs_echo.status = -1;
        srs_echo.feedback = "Task finished with the result: failed (closed window)";

        srs_ui_pro_pub.publish(srs_echo);
        Destroy();
    }
}

