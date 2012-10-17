#include "SkypeWindow.h"

//(*InternalHeaders(SkypeWindow)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//(*IdInit(SkypeWindow)
const long SkypeWindow::ID_TEXTCTRL1 = wxNewId();
const long SkypeWindow::ID_TEXTCTRL2 = wxNewId();
const long SkypeWindow::ID_BUTTON1 = wxNewId();
const long SkypeWindow::ID_STATICBITMAP1 = wxNewId();
const long SkypeWindow::ID_BITMAPBUTTON1 = wxNewId();
const long SkypeWindow::ID_PANEL3 = wxNewId();
const long SkypeWindow::ID_BITMAPBUTTON3 = wxNewId();
const long SkypeWindow::ID_PANEL4 = wxNewId();
const long SkypeWindow::ID_BITMAPBUTTON2 = wxNewId();
const long SkypeWindow::ID_PANEL2 = wxNewId();
const long SkypeWindow::ID_STATICTEXT1 = wxNewId();
const long SkypeWindow::ID_STATICTEXT2 = wxNewId();
const long SkypeWindow::ID_PANEL1 = wxNewId();
const long SkypeWindow::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SkypeWindow,wxFrame)
	//(*EventTable(SkypeWindow)
	//*)
END_EVENT_TABLE()

SkypeWindow::SkypeWindow(wxWindow* parent, SkypeFunctions *sf, std::string un, wxTextCtrl *lb, wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	//(*Initialize(SkypeWindow)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(400,315));
	chat_log = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(8,112), wxSize(384,160), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	chat_send = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(8,280), wxSize(344,27), wxTE_PROCESS_ENTER|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	button_chat = new wxButton(this, ID_BUTTON1, _("<-"), wxPoint(360,280), wxSize(32,27), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(8,8), wxSize(384,96), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	img_avatar = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("./img/avatar_prueba.jpg")).Rescale(wxSize(89,89).GetWidth(),wxSize(89,89).GetHeight())), wxPoint(0,0), wxSize(89,89), 0, _T("ID_STATICBITMAP1"));
	panel_call = new wxPanel(Panel1, ID_PANEL3, wxPoint(104,0), wxSize(48,40), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	img_call = new wxBitmapButton(panel_call, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("./img/call_on.gif"))), wxPoint(0,0), wxSize(40,40), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	img_call->SetDefault();
	Panel2 = new wxPanel(Panel1, ID_PANEL4, wxPoint(152,0), wxSize(48,40), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
	img_sound = new wxBitmapButton(Panel2, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("./img/mute_on.png"))), wxPoint(0,0), wxSize(40,40), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
	img_sound->SetDefault();
	panel_mute = new wxPanel(Panel1, ID_PANEL2, wxPoint(200,0), wxSize(48,40), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	img_micro = new wxBitmapButton(panel_mute, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("./img/micro_on.png"))), wxPoint(0,0), wxSize(40,40), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
	img_micro->SetDefault();
	label_name = new wxStaticText(Panel1, ID_STATICTEXT1, _("Name"), wxPoint(104,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	label_location = new wxStaticText(Panel1, ID_STATICTEXT2, _("City, Country"), wxPoint(104,72), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	timer_messageEvents.SetOwner(this, ID_TIMER1);
	timer_messageEvents.Start(100, false);

	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&SkypeWindow::Onchat_sendTextEnter);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkypeWindow::Onbutton_chatClick);
	Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkypeWindow::callButton);
	Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkypeWindow::soundButton);
	Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SkypeWindow::muteButton);
	Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&SkypeWindow::Ontimer_messageEventsTrigger);
	//*)



    SF = sf;
    userName = un;
    log_box = lb;

    chat_log->AppendText(wxString("Now you can chat with ", wxConvUTF8));
    chat_log->AppendText(wxString(userName.c_str(), wxConvUTF8));
    chat_log->AppendText(wxString(" ...\n", wxConvUTF8));

    setUserInfo();

}

SkypeWindow::~SkypeWindow()
{
    if (SF->calling == true)
    {
        Sid::String user = userName.c_str();
        SF->stopCall(user);
    }

	//(*Destroy(SkypeWindow)
	//*)
}

void SkypeWindow::callButton(wxCommandEvent& event)
{
    wxBitmap on(wxImage(_T("./img/call_on.gif")));
    wxBitmap off(wxImage(_T("./img/call_off.gif")));

    if(SF->calling == false)
    {
        SF->calling = true;
        SF->initCall(userName);
        img_call->SetBitmapFocus(off);
        img_call->SetBitmapHover(off);
        img_call->SetBitmapDisabled(off);
        img_call->SetBitmapLabel(off);
    }
    else
    {
        SF->calling = false;
        Sid::String user = userName.c_str();
        SF->stopCall(user);
        img_call->SetBitmapFocus(on);
        img_call->SetBitmapHover(on);
        img_call->SetBitmapDisabled(on);
        img_call->SetBitmapLabel(on);

    }
}


void SkypeWindow::Onbutton_chatClick(wxCommandEvent& event)
{
    std::string text = std::string((chat_send->GetValue()).mb_str());

    std::string aux;
    aux = "me: "+ text + "\n";

    chat_log->SetDefaultStyle(wxTextAttr(*wxBLUE));
    chat_log->AppendText(wxString(aux.c_str(), wxConvUTF8));

    SF->sendText(userName.c_str(), text);
    chat_send->Clear();
}

void SkypeWindow::Onchat_sendTextEnter(wxCommandEvent& event)
{
    std::string text = std::string((chat_send->GetValue()).mb_str());

    std::string aux;
    aux = "me: "+ text + "\n";

    chat_log->SetDefaultStyle(wxTextAttr(*wxBLUE));
    chat_log->AppendText(wxString(aux.c_str(), wxConvUTF8));

    SF->sendText(userName.c_str(), text);
    chat_send->Clear();
}

void SkypeWindow::muteMicro()
{
    wxBitmap on(wxImage(_T("./img/micro_on.png")));
    wxBitmap off(wxImage(_T("./img/micro_off.png")));

    if (SF->isMicroMuted() == true)
    {
        SF->muteMicro(false);
        img_micro->SetBitmapFocus(on);
        img_micro->SetBitmapHover(on);
        img_micro->SetBitmapDisabled(on);
        img_micro->SetBitmapLabel(on);

    }
    else
    {
        SF->muteMicro(true);
        img_micro->SetBitmapFocus(off);
        img_micro->SetBitmapHover(off);
        img_micro->SetBitmapDisabled(off);
        img_micro->SetBitmapLabel(off);
    }
}


void SkypeWindow::muteSound()
{
    wxBitmap on(wxImage(_T("./img/mute_on.png")));
    wxBitmap off(wxImage(_T("./img/mute_off.png")));

    if (SF->isSoundMuted() == true)
    {
        SF->muteSound(false);
        img_sound->SetBitmapFocus(on);
        img_sound->SetBitmapHover(on);
        img_sound->SetBitmapDisabled(on);
        img_sound->SetBitmapLabel(on);
    }
    else
    {
        SF->muteSound(true);
        img_sound->SetBitmapFocus(off);
        img_sound->SetBitmapHover(off);
        img_sound->SetBitmapDisabled(off);
        img_sound->SetBitmapLabel(off);

    }
}

void SkypeWindow::soundButton(wxCommandEvent& event)
{
    muteSound();
}

void SkypeWindow::muteButton(wxCommandEvent& event)
{
    //TODO: mute micro
    muteMicro();
}

void SkypeWindow::setUserInfo()
{
    SEString username = userName.c_str();
    SkypeFunctions::user_info user_info = SF->getUserInfo(username);
    img_avatar->SetBitmap(user_info.avatar);

    label_name->SetLabel(wxString(user_info.name.c_str(), wxConvUTF8));
    label_location->SetLabel(wxString(user_info.location.c_str(), wxConvUTF8));

}

void SkypeWindow::Ontimer_messageEventsTrigger(wxTimerEvent& event)
{
    if (SF->messageEvent() && userName.compare(SF->contact_event) == 0)
    {
        chat_log->SetDefaultStyle(wxTextAttr(*wxRED));
        chat_log->AppendText(wxString(SF->textEvent().c_str(), wxConvUTF8));
        SF->allowNewMessageEvent();
    }
}
