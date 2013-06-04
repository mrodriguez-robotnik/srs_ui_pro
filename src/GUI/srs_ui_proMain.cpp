/***************************************************************
 * Name:      srs_ui_proMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Roman Navarro (rnavarro@robotnik.es)
 * Created:   2012-03-13
 * Copyright: Roman Navarro ()
 * License:
 **************************************************************/

#include "srs_ui_proMain.h"
//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }
    return wxbuild;
}

//(*IdInit(srs_ui_proFrame)
const long srs_ui_proFrame::ID_GRID1 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT7 = wxNewId();
const long srs_ui_proFrame::ID_LISTCTRL1 = wxNewId();
const long srs_ui_proFrame::ID_PANEL10 = wxNewId();
const long srs_ui_proFrame::ID_LISTCTRL2 = wxNewId();
const long srs_ui_proFrame::ID_PANEL9 = wxNewId();
const long srs_ui_proFrame::ID_NOTEBOOK2 = wxNewId();
const long srs_ui_proFrame::ID_PANEL4 = wxNewId();
const long srs_ui_proFrame::ID_PANEL2 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON14 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL6 = wxNewId();
const long srs_ui_proFrame::ID_CHOICE3 = wxNewId();
const long srs_ui_proFrame::ID_PANEL46 = wxNewId();
const long srs_ui_proFrame::ID_PANEL20 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON13 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL3 = wxNewId();
const long srs_ui_proFrame::ID_CHOICE8 = wxNewId();
const long srs_ui_proFrame::ID_CHOICE4 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT5 = wxNewId();
const long srs_ui_proFrame::ID_PANEL19 = wxNewId();
const long srs_ui_proFrame::ID_PANEL18 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON19 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL9 = wxNewId();
const long srs_ui_proFrame::ID_CHOICE7 = wxNewId();
const long srs_ui_proFrame::ID_CHOICE5 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT11 = wxNewId();
const long srs_ui_proFrame::ID_PANEL37 = wxNewId();
const long srs_ui_proFrame::ID_PANEL21 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL5 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON1 = wxNewId();
const long srs_ui_proFrame::ID_CHOICE10 = wxNewId();
const long srs_ui_proFrame::ID_CHOICE9 = wxNewId();
const long srs_ui_proFrame::ID_CHOICE2 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT13 = wxNewId();
const long srs_ui_proFrame::ID_PANEL30 = wxNewId();
const long srs_ui_proFrame::ID_PANEL22 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON25 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL11 = wxNewId();
const long srs_ui_proFrame::ID_CHOICE12 = wxNewId();
const long srs_ui_proFrame::ID_CHOICE11 = wxNewId();
const long srs_ui_proFrame::ID_CHOICE6 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT25 = wxNewId();
const long srs_ui_proFrame::ID_PANEL49 = wxNewId();
const long srs_ui_proFrame::ID_PANEL47 = wxNewId();
const long srs_ui_proFrame::ID_NOTEBOOK4 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON16 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON17 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON15 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL17 = wxNewId();
const long srs_ui_proFrame::ID_PANEL11 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON11 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON36 = wxNewId();
const long srs_ui_proFrame::ID_STATICBITMAP9 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT15 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON9 = wxNewId();
const long srs_ui_proFrame::ID_PANEL32 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON37 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON38 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON40 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON39 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON41 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON42 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON44 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON43 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON46 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON47 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON45 = wxNewId();
const long srs_ui_proFrame::ID_STATICLINE7 = wxNewId();
const long srs_ui_proFrame::ID_STATICLINE6 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT17 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT22 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT23 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT36 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT37 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT46 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT47 = wxNewId();
const long srs_ui_proFrame::ID_PANEL13 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON5 = wxNewId();
const long srs_ui_proFrame::ID_PANEL27 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT12 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON33 = wxNewId();
const long srs_ui_proFrame::ID_COMBOBOX3 = wxNewId();
const long srs_ui_proFrame::ID_PANEL14 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON6 = wxNewId();
const long srs_ui_proFrame::ID_CHOICE1 = wxNewId();
const long srs_ui_proFrame::ID_SPINCTRL1 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON7 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL4 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT14 = wxNewId();
const long srs_ui_proFrame::ID_STATICBITMAP6 = wxNewId();
const long srs_ui_proFrame::ID_PANEL29 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON22 = wxNewId();
const long srs_ui_proFrame::ID_PANEL45 = wxNewId();
const long srs_ui_proFrame::ID_PANEL42 = wxNewId();
const long srs_ui_proFrame::ID_PANEL39 = wxNewId();
const long srs_ui_proFrame::ID_PANEL41 = wxNewId();
const long srs_ui_proFrame::ID_PANEL43 = wxNewId();
const long srs_ui_proFrame::ID_PANEL44 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT18 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT20 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT19 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT21 = wxNewId();
const long srs_ui_proFrame::ID_PANEL40 = wxNewId();
const long srs_ui_proFrame::ID_PANEL28 = wxNewId();
const long srs_ui_proFrame::ID_PANEL15 = wxNewId();
const long srs_ui_proFrame::ID_NOTEBOOK3 = wxNewId();
const long srs_ui_proFrame::ID_PANEL12 = wxNewId();
const long srs_ui_proFrame::ID_STATICBITMAP3 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT9 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON3 = wxNewId();
const long srs_ui_proFrame::ID_PANEL24 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON2 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON3 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON4 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON5 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON6 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON1 = wxNewId();
const long srs_ui_proFrame::ID_PANEL23 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON4 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON10 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT48 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT49 = wxNewId();
const long srs_ui_proFrame::ID_PANEL33 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON23 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON31 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON32 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT8 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT10 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT16 = wxNewId();
const long srs_ui_proFrame::ID_PANEL25 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT41 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON13 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON14 = wxNewId();
const long srs_ui_proFrame::ID_PANEL65 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT42 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON15 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON16 = wxNewId();
const long srs_ui_proFrame::ID_COMBOBOX5 = wxNewId();
const long srs_ui_proFrame::ID_PANEL66 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT43 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON17 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON18 = wxNewId();
const long srs_ui_proFrame::ID_COMBOBOX6 = wxNewId();
const long srs_ui_proFrame::ID_PANEL67 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT44 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON19 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON20 = wxNewId();
const long srs_ui_proFrame::ID_PANEL68 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT45 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON21 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON22 = wxNewId();
const long srs_ui_proFrame::ID_PANEL69 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT38 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON9 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON10 = wxNewId();
const long srs_ui_proFrame::ID_PANEL62 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT39 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON11 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON12 = wxNewId();
const long srs_ui_proFrame::ID_PANEL63 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT40 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON7 = wxNewId();
const long srs_ui_proFrame::ID_RADIOBUTTON8 = wxNewId();
const long srs_ui_proFrame::ID_PANEL64 = wxNewId();
const long srs_ui_proFrame::ID_PANEL60 = wxNewId();
const long srs_ui_proFrame::ID_NOTEBOOK5 = wxNewId();
const long srs_ui_proFrame::ID_PANEL17 = wxNewId();
const long srs_ui_proFrame::ID_NOTEBOOK1 = wxNewId();
const long srs_ui_proFrame::ID_PANEL7 = wxNewId();
const long srs_ui_proFrame::ID_PANEL6 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT3 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL1 = wxNewId();
const long srs_ui_proFrame::ID_GAUGE1 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT2 = wxNewId();
const long srs_ui_proFrame::ID_GAUGE2 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT4 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT1 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT24 = wxNewId();
const long srs_ui_proFrame::ID_PANEL52 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL2 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT6 = wxNewId();
const long srs_ui_proFrame::ID_PANEL53 = wxNewId();
const long srs_ui_proFrame::ID_PANEL51 = wxNewId();
const long srs_ui_proFrame::ID_PANEL5 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL13 = wxNewId();
const long srs_ui_proFrame::ID_PANEL57 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL15 = wxNewId();
const long srs_ui_proFrame::ID_PANEL56 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL16 = wxNewId();
const long srs_ui_proFrame::ID_PANEL58 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL18 = wxNewId();
const long srs_ui_proFrame::ID_PANEL59 = wxNewId();
const long srs_ui_proFrame::ID_NOTEBOOK7 = wxNewId();
const long srs_ui_proFrame::ID_BITMAPBUTTON2 = wxNewId();
const long srs_ui_proFrame::ID_PANEL55 = wxNewId();
const long srs_ui_proFrame::ID_SCROLLEDWINDOW2 = wxNewId();
const long srs_ui_proFrame::ID_PANEL61 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT28 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT29 = wxNewId();
const long srs_ui_proFrame::ID_COMBOBOX1 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT30 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON8 = wxNewId();
const long srs_ui_proFrame::ID_STATICLINE2 = wxNewId();
const long srs_ui_proFrame::ID_STATICLINE3 = wxNewId();
const long srs_ui_proFrame::ID_STATICLINE1 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT31 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT33 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT32 = wxNewId();
const long srs_ui_proFrame::ID_COMBOBOX2 = wxNewId();
const long srs_ui_proFrame::ID_TEXTCTRL19 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON21 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON20 = wxNewId();
const long srs_ui_proFrame::ID_PANEL8 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT34 = wxNewId();
const long srs_ui_proFrame::ID_STATICLINE4 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT35 = wxNewId();
const long srs_ui_proFrame::ID_STATICLINE5 = wxNewId();
const long srs_ui_proFrame::ID_COMBOBOX4 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON18 = wxNewId();
const long srs_ui_proFrame::ID_BUTTON2 = wxNewId();
const long srs_ui_proFrame::ID_PANEL26 = wxNewId();
const long srs_ui_proFrame::ID_NOTEBOOK6 = wxNewId();
const long srs_ui_proFrame::ID_PANEL16 = wxNewId();
const long srs_ui_proFrame::ID_PANEL54 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT26 = wxNewId();
const long srs_ui_proFrame::ID_STATICTEXT27 = wxNewId();
const long srs_ui_proFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long srs_ui_proFrame::ID_PANEL1 = wxNewId();
const long srs_ui_proFrame::ID_BITMAPBUTTON1 = wxNewId();
const long srs_ui_proFrame::ID_PANEL31 = wxNewId();
const long srs_ui_proFrame::ID_PANEL3 = wxNewId();
const long srs_ui_proFrame::idMenuQuit = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM10 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM11 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM13 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM1 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM3 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM6 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM17 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM18 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM19 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM21 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM22 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM20 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM16 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM2 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM9 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM5 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM7 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM4 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM12 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM15 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM14 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM23 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM24 = wxNewId();
const long srs_ui_proFrame::ID_MENUITEM8 = wxNewId();
const long srs_ui_proFrame::idMenuAbout = wxNewId();
const long srs_ui_proFrame::ID_TIMER1 = wxNewId();
const long srs_ui_proFrame::ID_TIMER2 = wxNewId();
const long srs_ui_proFrame::ID_TIMER3 = wxNewId();
const long srs_ui_proFrame::ID_STATUSBAR1 = wxNewId();
const long srs_ui_proFrame::ID_TIMER4 = wxNewId();
const long srs_ui_proFrame::ID_TIMER5 = wxNewId();
const long srs_ui_proFrame::ID_TIMER6 = wxNewId();
const long srs_ui_proFrame::ID_TIMER7 = wxNewId();
//*)


BEGIN_EVENT_TABLE(srs_ui_proFrame,wxFrame)
    //(*EventTable(srs_ui_proFrame)
    //*)
END_EVENT_TABLE()


srs_ui_proFrame::srs_ui_proFrame(wxWindow* parent, SkypeFunctions *sf, ProcessManager *pm, bool offline, wxWindowID id)
{
    //(*Initialize(srs_ui_proFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* menu_status_runtimeMonitor;
    wxMenuItem* MenuItem1;
    wxMenu* Menu5;
    wxMenu* Menu1;
    wxBoxSizer* sizer_comunications;
    wxMenuItem* MenuItem20;
    wxBoxSizer* sizer_automatic_deliver;
    wxBoxSizer* sizer_automatic_search;
    wxBoxSizer* sizer_options;
    wxBoxSizer* sizer_actions;
    wxMenuBar* MenuBar1;
    wxBoxSizer* sizer_status;
    wxBoxSizer* sizer_automatic_fetch;
    wxBoxSizer* sizer_automatic_move;
    wxMenu* Menu2;
    wxBoxSizer* sizer_automatic_get;

    Create(parent, wxID_ANY, _("GUI-PRO"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxFULL_REPAINT_ON_RESIZE, _T("wxID_ANY"));
    SetClientSize(wxSize(1357,654));
    panel_main = new wxPanel(this, ID_PANEL3, wxPoint(0,0), wxSize(1360,400), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    panel_comunications_main = new wxPanel(panel_main, ID_PANEL2, wxPoint(8,0), wxSize(391,688), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    sizer_comunications = new wxBoxSizer(wxHORIZONTAL);
    panel_comunications = new wxPanel(panel_comunications_main, ID_PANEL4, wxPoint(0,0), wxSize(360,600), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    grid_requests = new wxGrid(panel_comunications, ID_GRID1, wxPoint(0,32), wxSize(345,176), 0, _T("ID_GRID1"));
    grid_requests->CreateGrid(6,3);
    grid_requests->SetMinSize(wxSize(-1,-1));
    grid_requests->EnableEditing(false);
    grid_requests->EnableGridLines(true);
    grid_requests->SetRowLabelSize(1);
    grid_requests->SetDefaultColSize(115, true);
    grid_requests->SetColLabelValue(0, _("ID"));
    grid_requests->SetColLabelValue(1, _("URI"));
    grid_requests->SetColLabelValue(2, _("Problem"));
    grid_requests->SetCellValue(0, 0, _("4815162342"));
    grid_requests->SetCellValue(0, 1, _("http://localhost:11311"));
    grid_requests->SetCellValue(0, 2, _("Can\'t grasp an object"));
    grid_requests->SetDefaultCellFont( grid_requests->GetFont() );
    grid_requests->SetDefaultCellTextColour( grid_requests->GetForegroundColour() );
    label_Requests = new wxStaticText(panel_comunications, ID_STATICTEXT7, _("Requests"), wxPoint(0,8), wxSize(72,24), 0, _T("ID_STATICTEXT7"));
    tabs_skype = new wxNotebook(panel_comunications, ID_NOTEBOOK2, wxPoint(0,232), wxSize(360,240), wxNB_MULTILINE, _T("ID_NOTEBOOK2"));
    tab_skype_contacts = new wxPanel(tabs_skype, ID_PANEL10, wxPoint(4,381), wxSize(352,243), wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    grid_skype_contactList = new wxListCtrl(tab_skype_contacts, ID_LISTCTRL1, wxPoint(16,16), wxSize(320,168), wxLC_REPORT|wxSIMPLE_BORDER, wxDefaultValidator, _T("ID_LISTCTRL1"));
    tab_skype_IncomingCalls = new wxPanel(tabs_skype, ID_PANEL9, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    grid_skype_IncomingCalls = new wxListCtrl(tab_skype_IncomingCalls, ID_LISTCTRL2, wxPoint(16,16), wxSize(320,168), wxLC_REPORT|wxSIMPLE_BORDER, wxDefaultValidator, _T("ID_LISTCTRL2"));
    tabs_skype->AddPage(tab_skype_contacts, _("Contacts"), false);
    tabs_skype->AddPage(tab_skype_IncomingCalls, _("Incoming Calls"), false);
    sizer_comunications->Add(panel_comunications, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    panel_comunications_main->SetSizer(sizer_comunications);
    sizer_comunications->SetSizeHints(panel_comunications_main);
    panel_actions_main = new wxPanel(panel_main, ID_PANEL6, wxPoint(376,0), wxSize(674,482), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    panel_actions_main->Disable();
    sizer_actions = new wxBoxSizer(wxHORIZONTAL);
    panel_actions = new wxPanel(panel_actions_main, ID_PANEL7, wxPoint(360,0), wxSize(800,500), wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    tabs_actions = new wxNotebook(panel_actions, ID_NOTEBOOK1, wxPoint(0,0), wxSize(656,472), 0, _T("ID_NOTEBOOK1"));
    tab_automatic = new wxPanel(tabs_actions, ID_PANEL11, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL11"));
    tabs_decisionmaking = new wxNotebook(tab_automatic, ID_NOTEBOOK4, wxPoint(0,0), wxSize(648,100), 0, _T("ID_NOTEBOOK4"));
    tab_automatic_move = new wxPanel(tabs_decisionmaking, ID_PANEL20, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL20"));
    sizer_automatic_move = new wxBoxSizer(wxHORIZONTAL);
    panel_automatic_move = new wxPanel(tab_automatic_move, ID_PANEL46, wxDefaultPosition, wxSize(968,392), wxTAB_TRAVERSAL, _T("ID_PANEL46"));
    but_move_Start = new wxButton(panel_automatic_move, ID_BUTTON14, _("Start"), wxPoint(128,16), wxSize(48,29), 0, wxDefaultValidator, _T("ID_BUTTON14"));
    box_automatic_move_small = new wxTextCtrl(panel_automatic_move, ID_TEXTCTRL6, wxEmptyString, wxPoint(184,16), wxSize(448,29), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    choice_automatic_move = new wxChoice(panel_automatic_move, ID_CHOICE3, wxPoint(8,16), wxSize(112,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    sizer_automatic_move->Add(panel_automatic_move, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    tab_automatic_move->SetSizer(sizer_automatic_move);
    sizer_automatic_move->Fit(tab_automatic_move);
    sizer_automatic_move->SetSizeHints(tab_automatic_move);
    tab_automatic_get = new wxPanel(tabs_decisionmaking, ID_PANEL18, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL18"));
    sizer_automatic_get = new wxBoxSizer(wxHORIZONTAL);
    panel_automatic_get = new wxPanel(tab_automatic_get, ID_PANEL19, wxDefaultPosition, wxSize(968,392), wxTAB_TRAVERSAL, _T("ID_PANEL19"));
    but_get_Start = new wxButton(panel_automatic_get, ID_BUTTON13, _("Start"), wxPoint(248,16), wxSize(48,29), 0, wxDefaultValidator, _T("ID_BUTTON13"));
    box_automatic_get_small = new wxTextCtrl(panel_automatic_get, ID_TEXTCTRL3, wxEmptyString, wxPoint(304,16), wxSize(328,29), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    choice_automatic_get_search = new wxChoice(panel_automatic_get, ID_CHOICE8, wxPoint(128,16), wxSize(112,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE8"));
    choice_automatic_get = new wxChoice(panel_automatic_get, ID_CHOICE4, wxPoint(8,16), wxSize(112,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    label_get_Optional = new wxStaticText(panel_automatic_get, ID_STATICTEXT5, _("Optional:"), wxPoint(128,0), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    sizer_automatic_get->Add(panel_automatic_get, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    tab_automatic_get->SetSizer(sizer_automatic_get);
    sizer_automatic_get->Fit(tab_automatic_get);
    sizer_automatic_get->SetSizeHints(tab_automatic_get);
    tab_automatic_search = new wxPanel(tabs_decisionmaking, ID_PANEL21, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL21"));
    sizer_automatic_search = new wxBoxSizer(wxHORIZONTAL);
    panel_automatic_search = new wxPanel(tab_automatic_search, ID_PANEL37, wxDefaultPosition, wxSize(968,392), wxTAB_TRAVERSAL, _T("ID_PANEL37"));
    but_search_Start = new wxButton(panel_automatic_search, ID_BUTTON19, _("Start"), wxPoint(248,16), wxSize(48,29), 0, wxDefaultValidator, _T("ID_BUTTON19"));
    box_automatic_search_small = new wxTextCtrl(panel_automatic_search, ID_TEXTCTRL9, wxEmptyString, wxPoint(304,16), wxSize(328,29), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    choice_automatic_search_search = new wxChoice(panel_automatic_search, ID_CHOICE7, wxPoint(128,16), wxSize(112,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE7"));
    choice_automatic_search = new wxChoice(panel_automatic_search, ID_CHOICE5, wxPoint(8,16), wxSize(112,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
    label_search_Optional = new wxStaticText(panel_automatic_search, ID_STATICTEXT11, _("Optional:"), wxPoint(128,0), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    sizer_automatic_search->Add(panel_automatic_search, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    tab_automatic_search->SetSizer(sizer_automatic_search);
    sizer_automatic_search->Fit(tab_automatic_search);
    sizer_automatic_search->SetSizeHints(tab_automatic_search);
    tab_automatic_fetch = new wxPanel(tabs_decisionmaking, ID_PANEL22, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL22"));
    sizer_automatic_fetch = new wxBoxSizer(wxHORIZONTAL);
    panel_automatic_fetch = new wxPanel(tab_automatic_fetch, ID_PANEL30, wxDefaultPosition, wxSize(968,392), wxTAB_TRAVERSAL, _T("ID_PANEL30"));
    box_automatic_fetch_small = new wxTextCtrl(panel_automatic_fetch, ID_TEXTCTRL5, wxEmptyString, wxPoint(424,16), wxSize(208,29), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    but_fetch_Start = new wxButton(panel_automatic_fetch, ID_BUTTON1, _("Start"), wxPoint(368,16), wxSize(48,29), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    choice_automatic_fetch_order = new wxChoice(panel_automatic_fetch, ID_CHOICE10, wxPoint(128,16), wxSize(112,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE10"));
    choice_automatic_fetch_search = new wxChoice(panel_automatic_fetch, ID_CHOICE9, wxPoint(248,16), wxSize(112,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE9"));
    choice_automatic_fetch_search->Append(_("kitchen"));
    choice_automatic_fetch_search->Append(_("home"));
    choice_automatic_fetch = new wxChoice(panel_automatic_fetch, ID_CHOICE2, wxPoint(8,16), wxSize(112,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    label_fetch_Optional = new wxStaticText(panel_automatic_fetch, ID_STATICTEXT13, _("Optional:"), wxPoint(248,0), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    sizer_automatic_fetch->Add(panel_automatic_fetch, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    tab_automatic_fetch->SetSizer(sizer_automatic_fetch);
    sizer_automatic_fetch->Fit(tab_automatic_fetch);
    sizer_automatic_fetch->SetSizeHints(tab_automatic_fetch);
    tab_automatic_deliver = new wxPanel(tabs_decisionmaking, ID_PANEL47, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL47"));
    sizer_automatic_deliver = new wxBoxSizer(wxHORIZONTAL);
    panel_automatic_deliver = new wxPanel(tab_automatic_deliver, ID_PANEL49, wxDefaultPosition, wxSize(968,392), wxTAB_TRAVERSAL, _T("ID_PANEL49"));
    but_deliver_Start = new wxButton(panel_automatic_deliver, ID_BUTTON25, _("Start"), wxPoint(368,16), wxSize(48,29), 0, wxDefaultValidator, _T("ID_BUTTON25"));
    box_automatic_deliver_small = new wxTextCtrl(panel_automatic_deliver, ID_TEXTCTRL11, wxEmptyString, wxPoint(424,16), wxSize(208,29), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    choice_automatic_deliver_deliver_position = new wxChoice(panel_automatic_deliver, ID_CHOICE12, wxPoint(128,16), wxSize(112,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE12"));
    choice_automatic_deliver_search = new wxChoice(panel_automatic_deliver, ID_CHOICE11, wxPoint(248,16), wxSize(112,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE11"));
    choice_automatic_deliver = new wxChoice(panel_automatic_deliver, ID_CHOICE6, wxPoint(8,16), wxSize(112,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE6"));
    label_deliver_Optional = new wxStaticText(panel_automatic_deliver, ID_STATICTEXT25, _("Optional:"), wxPoint(248,0), wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    sizer_automatic_deliver->Add(panel_automatic_deliver, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    tab_automatic_deliver->SetSizer(sizer_automatic_deliver);
    sizer_automatic_deliver->Fit(tab_automatic_deliver);
    sizer_automatic_deliver->SetSizeHints(tab_automatic_deliver);
    tabs_decisionmaking->AddPage(tab_automatic_move, _("move"), false);
    tabs_decisionmaking->AddPage(tab_automatic_get, _("get"), false);
    tabs_decisionmaking->AddPage(tab_automatic_search, _("search"), false);
    tabs_decisionmaking->AddPage(tab_automatic_fetch, _("fetch"), false);
    tabs_decisionmaking->AddPage(tab_automatic_deliver, _("deliver"), false);
    but_PAUSE = new wxButton(tab_automatic, ID_BUTTON16, _("PAUSE"), wxPoint(12,400), wxSize(200,29), 0, wxDefaultValidator, _T("ID_BUTTON16"));
    but_PAUSE->Disable();
    but_RESUME = new wxButton(tab_automatic, ID_BUTTON17, _("RESUME"), wxPoint(224,400), wxSize(200,29), 0, wxDefaultValidator, _T("ID_BUTTON17"));
    but_RESUME->Disable();
    but_STOP = new wxButton(tab_automatic, ID_BUTTON15, _("STOP"), wxPoint(436,400), wxSize(200,29), 0, wxDefaultValidator, _T("ID_BUTTON15"));
    but_STOP->Disable();
    box_dm_log = new wxTextCtrl(tab_automatic, ID_TEXTCTRL17, wxEmptyString, wxPoint(16,112), wxSize(624,280), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    tab_semi = new wxPanel(tabs_actions, ID_PANEL12, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL12"));
    tabs_subsemi = new wxNotebook(tab_semi, ID_NOTEBOOK3, wxPoint(0,0), wxSize(648,400), 0, _T("ID_NOTEBOOK3"));
    tab_semi_navigation = new wxPanel(tabs_subsemi, ID_PANEL13, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL13"));
    Button6 = new wxButton(tab_semi_navigation, ID_BUTTON11, _("Folded"), wxPoint(368,184), wxSize(80,29), 0, wxDefaultValidator, _T("ID_BUTTON11"));
    Button12 = new wxButton(tab_semi_navigation, ID_BUTTON36, _("Tray to folder"), wxPoint(360,216), wxSize(102,29), 0, wxDefaultValidator, _T("ID_BUTTON36"));
    panel_navigation_dashboard = new wxPanel(tab_semi_navigation, ID_PANEL32, wxPoint(16,16), wxSize(296,40), wxTAB_TRAVERSAL, _T("ID_PANEL32"));
    img_navigation_dashboard = new wxStaticBitmap(panel_navigation_dashboard, ID_STATICBITMAP9, wxBitmap(wxImage(_T("./img/off.gif"))), wxPoint(8,8), wxDefaultSize, 0, _T("ID_STATICBITMAP9"));
    label_navigation_dashboard = new wxStaticText(panel_navigation_dashboard, ID_STATICTEXT15, _("Dashboard"), wxPoint(48,16), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    but_navigation_dashboard = new wxButton(panel_navigation_dashboard, ID_BUTTON9, _("On/Off"), wxPoint(224,8), wxSize(64,29), 0, wxDefaultValidator, _T("ID_BUTTON9"));
    Button13 = new wxButton(tab_semi_navigation, ID_BUTTON37, _("Front"), wxPoint(16,152), wxSize(80,29), 0, wxDefaultValidator, _T("ID_BUTTON37"));
    Button14 = new wxButton(tab_semi_navigation, ID_BUTTON38, _("Back"), wxPoint(16,184), wxSize(80,29), 0, wxDefaultValidator, _T("ID_BUTTON38"));
    Button16 = new wxButton(tab_semi_navigation, ID_BUTTON40, _("Open"), wxPoint(104,152), wxSize(80,29), 0, wxDefaultValidator, _T("ID_BUTTON40"));
    Button15 = new wxButton(tab_semi_navigation, ID_BUTTON39, _("Close"), wxPoint(104,184), wxSize(80,29), 0, wxDefaultValidator, _T("ID_BUTTON39"));
    Button17 = new wxButton(tab_semi_navigation, ID_BUTTON41, _("Front"), wxPoint(192,152), wxSize(80,29), 0, wxDefaultValidator, _T("ID_BUTTON41"));
    Button18 = new wxButton(tab_semi_navigation, ID_BUTTON42, _("Back"), wxPoint(192,184), wxSize(80,29), 0, wxDefaultValidator, _T("ID_BUTTON42"));
    Button20 = new wxButton(tab_semi_navigation, ID_BUTTON44, _("Down"), wxPoint(280,184), wxSize(80,29), 0, wxDefaultValidator, _T("ID_BUTTON44"));
    Button19 = new wxButton(tab_semi_navigation, ID_BUTTON43, _("Up"), wxPoint(280,152), wxSize(80,29), 0, wxDefaultValidator, _T("ID_BUTTON43"));
    Button22 = new wxButton(tab_semi_navigation, ID_BUTTON46, _("Home"), wxPoint(368,152), wxSize(80,29), 0, wxDefaultValidator, _T("ID_BUTTON46"));
    Button23 = new wxButton(tab_semi_navigation, ID_BUTTON47, _("Home"), wxPoint(456,152), wxSize(80,29), 0, wxDefaultValidator, _T("ID_BUTTON47"));
    Button21 = new wxButton(tab_semi_navigation, ID_BUTTON45, _("Kitchen"), wxPoint(456,184), wxSize(80,29), 0, wxDefaultValidator, _T("ID_BUTTON45"));
    StaticLine2 = new wxStaticLine(tab_semi_navigation, ID_STATICLINE7, wxPoint(16,120), wxSize(520,16), wxLI_HORIZONTAL, _T("ID_STATICLINE7"));
    StaticLine1 = new wxStaticLine(tab_semi_navigation, ID_STATICLINE6, wxPoint(16,256), wxSize(520,16), wxLI_HORIZONTAL, _T("ID_STATICLINE6"));
    StaticText12 = new wxStaticText(tab_semi_navigation, ID_STATICTEXT17, _("Fast commands"), wxPoint(16,106), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    StaticText12->Disable();
    StaticText13 = new wxStaticText(tab_semi_navigation, ID_STATICTEXT22, _("Head"), wxPoint(16,136), wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    StaticText14 = new wxStaticText(tab_semi_navigation, ID_STATICTEXT23, _("Hand"), wxPoint(104,136), wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    StaticText15 = new wxStaticText(tab_semi_navigation, ID_STATICTEXT36, _("Torso"), wxPoint(192,136), wxDefaultSize, 0, _T("ID_STATICTEXT36"));
    StaticText16 = new wxStaticText(tab_semi_navigation, ID_STATICTEXT37, _("Tray"), wxPoint(280,136), wxDefaultSize, 0, _T("ID_STATICTEXT37"));
    StaticText17 = new wxStaticText(tab_semi_navigation, ID_STATICTEXT46, _("Arm"), wxPoint(368,136), wxDefaultSize, 0, _T("ID_STATICTEXT46"));
    StaticText18 = new wxStaticText(tab_semi_navigation, ID_STATICTEXT47, _("Base"), wxPoint(456,136), wxDefaultSize, 0, _T("ID_STATICTEXT47"));
    tab_semi_detection = new wxPanel(tabs_subsemi, ID_PANEL14, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL14"));
    but_DetectObjects = new wxButton(tab_semi_detection, ID_BUTTON5, _("Detect object"), wxPoint(176,16), wxSize(120,29), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    panel_detected_objects = new wxPanel(tab_semi_detection, ID_PANEL27, wxPoint(16,96), wxSize(616,216), wxTAB_TRAVERSAL, _T("ID_PANEL27"));
    label_DetectedObjects = new wxStaticText(tab_semi_detection, ID_STATICTEXT12, _("Detected objects"), wxPoint(16,72), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    but_SpawnObjectsInRviz = new wxButton(tab_semi_detection, ID_BUTTON33, _("Spawn objects in RVIZ"), wxPoint(16,320), wxSize(168,29), 0, wxDefaultValidator, _T("ID_BUTTON33"));
    but_SpawnObjectsInRviz->Disable();
    choice_objectstodetect = new wxComboBox(tab_semi_detection, ID_COMBOBOX3, wxEmptyString, wxPoint(16,16), wxSize(152,29), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
    tab_semi_grasping = new wxPanel(tabs_subsemi, ID_PANEL15, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL15"));
    tab_semi_grasping->Disable();
    panel_grasping = new wxPanel(tab_semi_grasping, ID_PANEL28, wxPoint(8,8), wxSize(957,367), wxTAB_TRAVERSAL, _T("ID_PANEL28"));
    but_GenerateGrasps = new wxButton(panel_grasping, ID_BUTTON6, _("Generate grasps"), wxPoint(152,74), wxSize(184,29), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    choice_selected_grasp_object = new wxChoice(panel_grasping, ID_CHOICE1, wxPoint(16,74), wxSize(128,29), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    choice_selected_grasp_object->Append(wxEmptyString);
    choice_grasp_conf = new wxSpinCtrl(panel_grasping, ID_SPINCTRL1, _T("0"), wxPoint(16,162), wxSize(47,29), 0, 0, 0, 0, _T("ID_SPINCTRL1"));
    choice_grasp_conf->SetValue(_T("0"));
    choice_grasp_conf->Disable();
    but_GraspIt = new wxButton(panel_grasping, ID_BUTTON7, _("Grasp it!"), wxPoint(200,162), wxSize(136,29), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    but_GraspIt->Disable();
    box_graspResult = new wxTextCtrl(panel_grasping, ID_TEXTCTRL4, _("Text"), wxPoint(72,202), wxSize(224,31), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    label_Result = new wxStaticText(panel_grasping, ID_STATICTEXT14, _("Result:"), wxPoint(16,210), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    panel_grasp_result = new wxPanel(panel_grasping, ID_PANEL29, wxPoint(304,202), wxSize(37,42), wxTAB_TRAVERSAL, _T("ID_PANEL29"));
    img_graspResult = new wxStaticBitmap(panel_grasp_result, ID_STATICBITMAP6, wxBitmap(wxImage(_T("./img/off.gif"))), wxPoint(0,0), wxDefaultSize, 0, _T("ID_STATICBITMAP6"));
    but_SimulateGrasp = new wxButton(panel_grasping, ID_BUTTON22, _("Simulate grasp"), wxPoint(72,162), wxSize(120,29), 0, wxDefaultValidator, _T("ID_BUTTON22"));
    but_SimulateGrasp->Disable();
    panel_TactilSensors = new wxPanel(panel_grasping, ID_PANEL40, wxPoint(368,0), wxSize(216,320), wxTAB_TRAVERSAL, _T("ID_PANEL40"));
    panel_ts11 = new wxPanel(panel_TactilSensors, ID_PANEL45, wxPoint(16,16), wxSize(60,140), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL45"));
    panel_ts21 = new wxPanel(panel_TactilSensors, ID_PANEL42, wxPoint(80,16), wxSize(60,140), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL42"));
    panel_ts31 = new wxPanel(panel_TactilSensors, ID_PANEL39, wxPoint(144,16), wxSize(60,140), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL39"));
    panel_ts12 = new wxPanel(panel_TactilSensors, ID_PANEL41, wxPoint(16,160), wxSize(60,140), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL41"));
    panel_ts22 = new wxPanel(panel_TactilSensors, ID_PANEL43, wxPoint(80,160), wxSize(60,140), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL43"));
    panel_ts32 = new wxPanel(panel_TactilSensors, ID_PANEL44, wxPoint(144,160), wxSize(60,140), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL44"));
    label_TS_F2 = new wxStaticText(panel_TactilSensors, ID_STATICTEXT18, _("F2"), wxPoint(104,304), wxSize(23,17), 0, _T("ID_STATICTEXT18"));
    label_TS_F3 = new wxStaticText(panel_TactilSensors, ID_STATICTEXT20, _("F3"), wxPoint(168,304), wxSize(16,19), 0, _T("ID_STATICTEXT20"));
    label_TS_F1 = new wxStaticText(panel_TactilSensors, ID_STATICTEXT19, _("F1"), wxPoint(40,304), wxSize(23,17), 0, _T("ID_STATICTEXT19"));
    label_TS_TactilSensors = new wxStaticText(panel_TactilSensors, ID_STATICTEXT21, _("TACTIL SENSORS"), wxPoint(32,0), wxSize(148,28), wxSIMPLE_BORDER, _T("ID_STATICTEXT21"));
    wxFont label_TS_TactilSensorsFont(13,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    label_TS_TactilSensors->SetFont(label_TS_TactilSensorsFont);
    tabs_subsemi->AddPage(tab_semi_navigation, _("Dashboard"), false);
    tabs_subsemi->AddPage(tab_semi_detection, _("Detection"), false);
    tabs_subsemi->AddPage(tab_semi_grasping, _("Grasping"), false);
    tab_manual = new wxPanel(tabs_actions, ID_PANEL17, wxDefaultPosition, wxSize(1066,324), wxTAB_TRAVERSAL, _T("ID_PANEL17"));
    tabs_submanual = new wxNotebook(tab_manual, ID_NOTEBOOK5, wxPoint(0,0), wxSize(648,400), 0, _T("ID_NOTEBOOK5"));
    tab_joystick = new wxPanel(tabs_submanual, ID_PANEL23, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL23"));
    tab_joystick->Disable();
    panel_joystick_unused1 = new wxPanel(tab_joystick, ID_PANEL24, wxPoint(16,16), wxSize(296,40), wxTAB_TRAVERSAL, _T("ID_PANEL24"));
    panel_joystick_unused1->Disable();
    img_joystick_unused1 = new wxStaticBitmap(panel_joystick_unused1, ID_STATICBITMAP3, wxBitmap(wxImage(_T("./img/off.gif"))), wxPoint(8,8), wxDefaultSize, 0, _T("ID_STATICBITMAP3"));
    label_joystick_unnused1 = new wxStaticText(panel_joystick_unused1, ID_STATICTEXT9, _("Joystick"), wxPoint(48,16), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    but_joystick_unused1 = new wxButton(panel_joystick_unused1, ID_BUTTON3, _("On/Off"), wxPoint(224,8), wxSize(64,29), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    option_joystick_Head = new wxRadioButton(tab_joystick, ID_RADIOBUTTON2, _("Head"), wxPoint(16,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    option_joystick_Torso = new wxRadioButton(tab_joystick, ID_RADIOBUTTON3, _("Torso"), wxPoint(208,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    option_joystick_Tray = new wxRadioButton(tab_joystick, ID_RADIOBUTTON4, _("Tray"), wxPoint(304,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
    option_joystick_Arm = new wxRadioButton(tab_joystick, ID_RADIOBUTTON5, _("Arm"), wxPoint(400,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON5"));
    option_joystick_Hand = new wxRadioButton(tab_joystick, ID_RADIOBUTTON6, _("Hand"), wxPoint(112,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON6"));
    option_joystick_Base = new wxRadioButton(tab_joystick, ID_RADIOBUTTON1, _("Base"), wxPoint(496,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    tab_assisted = new wxPanel(tabs_submanual, ID_PANEL33, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL33"));
    Button4 = new wxButton(tab_assisted, ID_BUTTON4, _("Assisted arm navigation"), wxPoint(8,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button5 = new wxButton(tab_assisted, ID_BUTTON10, _("Assisted grasping"), wxPoint(8,120), wxSize(176,29), 0, wxDefaultValidator, _T("ID_BUTTON10"));
    StaticText19 = new wxStaticText(tab_assisted, ID_STATICTEXT48, _("Allows to move the hand to a desired position."), wxPoint(8,40), wxSize(456,17), 0, _T("ID_STATICTEXT48"));
    StaticText20 = new wxStaticText(tab_assisted, ID_STATICTEXT49, _("Allows to manage the hand closure. This state includes the assisted detection."), wxPoint(8,152), wxDefaultSize, 0, _T("ID_STATICTEXT49"));
    tab_RvizTools = new wxPanel(tabs_submanual, ID_PANEL25, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL25"));
    tab_RvizTools->Disable();
    Button1 = new wxButton(tab_RvizTools, ID_BUTTON23, _("Basic configurations"), wxPoint(8,8), wxSize(160,29), 0, wxDefaultValidator, _T("ID_BUTTON23"));
    Button2 = new wxButton(tab_RvizTools, ID_BUTTON31, _("Assisted navigation"), wxPoint(8,78), wxSize(160,29), 0, wxDefaultValidator, _T("ID_BUTTON31"));
    Button3 = new wxButton(tab_RvizTools, ID_BUTTON32, _("Assisted manipulation"), wxPoint(8,148), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON32"));
    StaticText9 = new wxStaticText(tab_RvizTools, ID_STATICTEXT8, _("Basic displays to see the robot in the current map."), wxPoint(8,40), wxSize(544,17), 0, _T("ID_STATICTEXT8"));
    StaticText10 = new wxStaticText(tab_RvizTools, ID_STATICTEXT10, _("Basic displays to move the robot arround the map."), wxPoint(8,110), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    StaticText11 = new wxStaticText(tab_RvizTools, ID_STATICTEXT16, _("Basic displays to move the robot and use assisted tasks."), wxPoint(8,180), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    tab_Rviz = new wxPanel(tabs_submanual, ID_PANEL60, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL60"));
    tab_Rviz->Disable();
    Panel4 = new wxPanel(tab_Rviz, ID_PANEL65, wxPoint(8,88), wxSize(312,32), wxTAB_TRAVERSAL, _T("ID_PANEL65"));
    StaticText4 = new wxStaticText(Panel4, ID_STATICTEXT41, _("Base teleoperation"), wxPoint(8,8), wxSize(184,17), 0, _T("ID_STATICTEXT41"));
    RadioButton7 = new wxRadioButton(Panel4, ID_RADIOBUTTON13, _("On"), wxPoint(200,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON13"));
    RadioButton8 = new wxRadioButton(Panel4, ID_RADIOBUTTON14, _("Off"), wxPoint(256,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON14"));
    RadioButton8->SetValue(true);
    Panel5 = new wxPanel(tab_Rviz, ID_PANEL66, wxPoint(8,128), wxSize(456,32), wxTAB_TRAVERSAL, _T("ID_PANEL66"));
    StaticText5 = new wxStaticText(Panel5, ID_STATICTEXT42, _("Distance linear visualizer"), wxPoint(8,8), wxSize(184,17), 0, _T("ID_STATICTEXT42"));
    RadioButton9 = new wxRadioButton(Panel5, ID_RADIOBUTTON15, _("On"), wxPoint(200,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON15"));
    RadioButton10 = new wxRadioButton(Panel5, ID_RADIOBUTTON16, _("Off"), wxPoint(256,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON16"));
    RadioButton10->SetValue(true);
    ComboBox1 = new wxComboBox(Panel5, ID_COMBOBOX5, wxEmptyString, wxPoint(320,4), wxSize(128,29), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX5"));
    ComboBox1->Append(_("base"));
    ComboBox1->Append(_("body"));
    ComboBox1->Append(_("hand"));
    Panel6 = new wxPanel(tab_Rviz, ID_PANEL67, wxPoint(8,168), wxSize(456,32), wxTAB_TRAVERSAL, _T("ID_PANEL67"));
    StaticText6 = new wxStaticText(Panel6, ID_STATICTEXT43, _("Distance circular indicator"), wxPoint(8,8), wxSize(184,17), 0, _T("ID_STATICTEXT43"));
    RadioButton11 = new wxRadioButton(Panel6, ID_RADIOBUTTON17, _("On"), wxPoint(200,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON17"));
    RadioButton12 = new wxRadioButton(Panel6, ID_RADIOBUTTON18, _("Off"), wxPoint(256,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON18"));
    RadioButton12->SetValue(true);
    ComboBox2 = new wxComboBox(Panel6, ID_COMBOBOX6, wxEmptyString, wxPoint(320,4), wxSize(128,29), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX6"));
    ComboBox2->Append(_("base"));
    ComboBox2->Append(_("body"));
    ComboBox2->Append(_("hand"));
    Panel7 = new wxPanel(tab_Rviz, ID_PANEL68, wxPoint(8,208), wxSize(312,32), wxTAB_TRAVERSAL, _T("ID_PANEL68"));
    StaticText7 = new wxStaticText(Panel7, ID_STATICTEXT44, _("Stretch indicator"), wxPoint(8,8), wxSize(184,17), 0, _T("ID_STATICTEXT44"));
    RadioButton13 = new wxRadioButton(Panel7, ID_RADIOBUTTON19, _("On"), wxPoint(200,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON19"));
    RadioButton14 = new wxRadioButton(Panel7, ID_RADIOBUTTON20, _("Off"), wxPoint(256,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON20"));
    RadioButton14->SetValue(true);
    Panel8 = new wxPanel(tab_Rviz, ID_PANEL69, wxPoint(8,248), wxSize(312,32), wxTAB_TRAVERSAL, _T("ID_PANEL69"));
    StaticText8 = new wxStaticText(Panel8, ID_STATICTEXT45, _("Object manager"), wxPoint(8,8), wxSize(184,17), 0, _T("ID_STATICTEXT45"));
    RadioButton15 = new wxRadioButton(Panel8, ID_RADIOBUTTON21, _("On"), wxPoint(200,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON21"));
    RadioButton16 = new wxRadioButton(Panel8, ID_RADIOBUTTON22, _("Off"), wxPoint(256,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON22"));
    RadioButton16->SetValue(true);
    Panel1 = new wxPanel(tab_Rviz, ID_PANEL62, wxPoint(8,288), wxSize(312,32), wxTAB_TRAVERSAL, _T("ID_PANEL62"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT38, _("Data fusion"), wxPoint(8,8), wxSize(184,17), 0, _T("ID_STATICTEXT38"));
    RadioButton3 = new wxRadioButton(Panel1, ID_RADIOBUTTON9, _("On"), wxPoint(200,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON9"));
    RadioButton4 = new wxRadioButton(Panel1, ID_RADIOBUTTON10, _("Off"), wxPoint(256,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON10"));
    RadioButton4->SetValue(true);
    Panel3 = new wxPanel(tab_Rviz, ID_PANEL63, wxPoint(8,8), wxSize(312,32), wxTAB_TRAVERSAL, _T("ID_PANEL63"));
    StaticText2 = new wxStaticText(Panel3, ID_STATICTEXT39, _("Assisted arm navigation"), wxPoint(8,8), wxSize(184,17), 0, _T("ID_STATICTEXT39"));
    RadioButton5 = new wxRadioButton(Panel3, ID_RADIOBUTTON11, _("On"), wxPoint(200,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON11"));
    RadioButton6 = new wxRadioButton(Panel3, ID_RADIOBUTTON12, _("Off"), wxPoint(256,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON12"));
    RadioButton6->SetValue(true);
    Panel2 = new wxPanel(tab_Rviz, ID_PANEL64, wxPoint(8,48), wxSize(312,32), wxTAB_TRAVERSAL, _T("ID_PANEL64"));
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT40, _("Assisted grasp"), wxPoint(8,8), wxSize(184,17), 0, _T("ID_STATICTEXT40"));
    RadioButton1 = new wxRadioButton(Panel2, ID_RADIOBUTTON7, _("On"), wxPoint(200,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON7"));
    RadioButton2 = new wxRadioButton(Panel2, ID_RADIOBUTTON8, _("Off"), wxPoint(256,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON8"));
    RadioButton2->SetValue(true);
    tabs_submanual->AddPage(tab_joystick, _("Joystick"), false);
    tabs_submanual->AddPage(tab_assisted, _("Assisted actions"), false);
    tabs_submanual->AddPage(tab_RvizTools, _("Rviz configs"), false);
    tabs_submanual->AddPage(tab_Rviz, _("Rviz displays"), false);
    tabs_actions->AddPage(tab_automatic, _("Automatic"), false);
    tabs_actions->AddPage(tab_semi, _("Semi"), false);
    tabs_actions->AddPage(tab_manual, _("Manual"), false);
    sizer_actions->Add(panel_actions, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    panel_actions_main->SetSizer(sizer_actions);
    sizer_actions->SetSizeHints(panel_actions_main);
    panel_status_main = new wxPanel(panel_main, ID_PANEL5, wxPoint(8,480), wxSize(1253,164), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    sizer_status = new wxBoxSizer(wxHORIZONTAL);
    panel_status = new wxPanel(panel_status_main, ID_PANEL51, wxDefaultPosition, wxSize(811,152), wxRAISED_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL51"));
    panel_status_RobotInfo = new wxPanel(panel_status, ID_PANEL52, wxPoint(8,8), wxSize(198,140), wxTAB_TRAVERSAL, _T("ID_PANEL52"));
    label_status_RobotUri = new wxStaticText(panel_status_RobotInfo, ID_STATICTEXT3, _("Robot URI"), wxPoint(8,0), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont label_status_RobotUriFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    label_status_RobotUri->SetFont(label_status_RobotUriFont);
    box_status_RobotURI = new wxTextCtrl(panel_status_RobotInfo, ID_TEXTCTRL1, _("Not connected"), wxPoint(8,16), wxSize(184,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    bar_status_battery = new wxGauge(panel_status_RobotInfo, ID_GAUGE1, 100, wxPoint(8,68), wxSize(90,25), 0, wxDefaultValidator, _T("ID_GAUGE1"));
    bar_status_battery->SetValue(55);
    label_status_Battery = new wxStaticText(panel_status_RobotInfo, ID_STATICTEXT2, _("Battery"), wxPoint(8,52), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont label_status_BatteryFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    label_status_Battery->SetFont(label_status_BatteryFont);
    bar_status_wifi = new wxGauge(panel_status_RobotInfo, ID_GAUGE2, 100, wxPoint(102,68), wxSize(90,25), 0, wxDefaultValidator, _T("ID_GAUGE2"));
    bar_status_wifi->SetValue(80);
    bar_status_wifi->Disable();
    label_status_WifiSignal = new wxStaticText(panel_status_RobotInfo, ID_STATICTEXT4, _("Wifi Signal"), wxPoint(102,52), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont label_status_WifiSignalFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    label_status_WifiSignal->SetFont(label_status_WifiSignalFont);
    label_status_TimeBattery = new wxStaticText(panel_status_RobotInfo, ID_STATICTEXT1, wxEmptyString, wxPoint(120,104), wxSize(80,16), 0, _T("ID_STATICTEXT1"));
    label_status_TimeRemaining = new wxStaticText(panel_status_RobotInfo, ID_STATICTEXT24, _("Time remaining:"), wxPoint(8,104), wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    panel_status_log = new wxPanel(panel_status, ID_PANEL53, wxPoint(272,8), wxSize(748,140), wxTAB_TRAVERSAL, _T("ID_PANEL53"));
    box_status_log = new wxTextCtrl(panel_status_log, ID_TEXTCTRL2, wxEmptyString, wxPoint(0,24), wxSize(528,111), wxTE_AUTO_SCROLL|wxTE_MULTILINE|wxVSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    label_status_log = new wxStaticText(panel_status_log, ID_STATICTEXT6, _("Status log"), wxPoint(0,8), wxSize(78,9), 0, _T("ID_STATICTEXT6"));
    wxFont label_status_logFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    label_status_log->SetFont(label_status_logFont);
    sizer_status->Add(panel_status, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    panel_status_main->SetSizer(sizer_status);
    sizer_status->SetSizeHints(panel_status_main);
    panel_options_main = new wxPanel(panel_main, ID_PANEL54, wxPoint(1042,0), wxSize(306,472), wxTAB_TRAVERSAL, _T("ID_PANEL54"));
    panel_options_main->Disable();
    sizer_options = new wxBoxSizer(wxHORIZONTAL);
    panel_options = new wxPanel(panel_options_main, ID_PANEL16, wxDefaultPosition, wxSize(296,469), wxTAB_TRAVERSAL, _T("ID_PANEL16"));
    tabs_options = new wxNotebook(panel_options, ID_NOTEBOOK6, wxPoint(0,0), wxSize(296,472), 0, _T("ID_NOTEBOOK6"));
    tab_ROS = new wxPanel(tabs_options, ID_PANEL55, wxDefaultPosition, wxSize(292,437), wxTAB_TRAVERSAL, _T("ID_PANEL55"));
    tabs_subROS = new wxNotebook(tab_ROS, ID_NOTEBOOK7, wxPoint(0,0), wxSize(288,408), 0, _T("ID_NOTEBOOK7"));
    tab_nodes = new wxPanel(tabs_subROS, ID_PANEL57, wxDefaultPosition, wxSize(284,361), wxTAB_TRAVERSAL, _T("ID_PANEL57"));
    box_ROS_nodes = new wxTextCtrl(tab_nodes, ID_TEXTCTRL13, wxEmptyString, wxPoint(4,8), wxSize(276,360), wxTE_MULTILINE|wxHSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    tab_topics = new wxPanel(tabs_subROS, ID_PANEL56, wxDefaultPosition, wxSize(284,336), wxTAB_TRAVERSAL, _T("ID_PANEL56"));
    box_ROS_topics = new wxTextCtrl(tab_topics, ID_TEXTCTRL15, wxEmptyString, wxPoint(4,8), wxSize(276,360), wxTE_MULTILINE|wxHSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    tab_services = new wxPanel(tabs_subROS, ID_PANEL58, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL, _T("ID_PANEL58"));
    box_ROS_services = new wxTextCtrl(tab_services, ID_TEXTCTRL16, wxEmptyString, wxPoint(4,8), wxSize(276,360), wxTE_MULTILINE|wxHSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    tab_params = new wxPanel(tabs_subROS, ID_PANEL59, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL59"));
    box_ROS_params = new wxTextCtrl(tab_params, ID_TEXTCTRL18, wxEmptyString, wxPoint(4,8), wxSize(276,360), wxTE_MULTILINE|wxHSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    tabs_subROS->AddPage(tab_nodes, _("nodes"), false);
    tabs_subROS->AddPage(tab_topics, _("topics"), false);
    tabs_subROS->AddPage(tab_services, _("services"), false);
    tabs_subROS->AddPage(tab_params, _("params"), false);
    img_update_rosinfo = new wxBitmapButton(tab_ROS, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("./img/update.png"))), wxPoint(262,408), wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    img_update_rosinfo->SetFocus();
    tab_objects = new wxPanel(tabs_options, ID_PANEL8, wxDefaultPosition, wxSize(292,436), wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    panel_db_objects = new wxPanel(tab_objects, ID_PANEL61, wxPoint(0,256), wxSize(292,184), wxRAISED_BORDER, _T("ID_PANEL61"));
    scrollablewindow_dbobjects = new wxScrolledWindow(panel_db_objects, ID_SCROLLEDWINDOW2, wxPoint(0,0), wxSize(292,184), wxHSCROLL|wxVSCROLL, _T("ID_SCROLLEDWINDOW2"));
    label_DatabaseObjectsList = new wxStaticText(tab_objects, ID_STATICTEXT28, _("Database object list"), wxPoint(4,236), wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    wxFont label_DatabaseObjectsListFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    label_DatabaseObjectsList->SetFont(label_DatabaseObjectsListFont);
    label_TeachNewObject = new wxStaticText(tab_objects, ID_STATICTEXT29, _("Teach new object"), wxPoint(4,0), wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    wxFont label_TeachNewObjectFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    label_TeachNewObject->SetFont(label_TeachNewObjectFont);
    choice_TeachNewObject = new wxComboBox(tab_objects, ID_COMBOBOX1, wxEmptyString, wxPoint(4,48), wxSize(240,29), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    choice_TeachNewObject->Append(_("Rotate-on-Gripper"));
    label_TeachNewObjectBy = new wxStaticText(tab_objects, ID_STATICTEXT30, _("Teach new object by"), wxPoint(4,32), wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    but_TeachNewObjectStart = new wxButton(tab_objects, ID_BUTTON8, _("Start"), wxPoint(244,48), wxSize(44,29), 0, wxDefaultValidator, _T("ID_BUTTON8"));
    but_TeachNewObjectStart->Disable();
    separador1 = new wxStaticLine(tab_objects, ID_STATICLINE2, wxPoint(4,240), wxSize(284,24), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    separador2 = new wxStaticLine(tab_objects, ID_STATICLINE3, wxPoint(4,4), wxSize(284,24), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    separador3 = new wxStaticLine(tab_objects, ID_STATICLINE1, wxPoint(4,100), wxSize(284,24), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    label_DefineTheObject = new wxStaticText(tab_objects, ID_STATICTEXT31, _("Define the object"), wxPoint(4,96), wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    wxFont label_DefineTheObjectFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    label_DefineTheObject->SetFont(label_DefineTheObjectFont);
    label_ObjectName = new wxStaticText(tab_objects, ID_STATICTEXT33, _("Object name"), wxPoint(4,128), wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    label_Category = new wxStaticText(tab_objects, ID_STATICTEXT32, _("Category"), wxPoint(144,128), wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    choice_category = new wxComboBox(tab_objects, ID_COMBOBOX2, wxEmptyString, wxPoint(144,144), wxSize(144,24), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
    choice_category->Append(_("bottles"));
    choice_category->Append(_("cups"));
    choice_category->Append(_("drugs"));
    box_ObjectName = new wxTextCtrl(tab_objects, ID_TEXTCTRL19, wxEmptyString, wxPoint(4,144), wxSize(140,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
    but_Save = new wxButton(tab_objects, ID_BUTTON21, _("Save"), wxPoint(88,168), wxSize(56,29), 0, wxDefaultValidator, _T("ID_BUTTON21"));
    but_Save->Disable();
    but_Cancel = new wxButton(tab_objects, ID_BUTTON20, _("Cancel"), wxPoint(144,168), wxSize(56,29), 0, wxDefaultValidator, _T("ID_BUTTON20"));
    but_Cancel->Disable();
    tab_tasks = new wxPanel(tabs_options, ID_PANEL26, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL26"));
    tab_tasks->Disable();
    label_TeachNewTask = new wxStaticText(tab_tasks, ID_STATICTEXT34, _("Teach new task"), wxPoint(4,0), wxDefaultSize, 0, _T("ID_STATICTEXT34"));
    wxFont label_TeachNewTaskFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    label_TeachNewTask->SetFont(label_TeachNewTaskFont);
    separador4 = new wxStaticLine(tab_tasks, ID_STATICLINE4, wxPoint(4,4), wxSize(284,24), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
    label_TasksList = new wxStaticText(tab_tasks, ID_STATICTEXT35, _("Tasks list"), wxPoint(4,328), wxDefaultSize, 0, _T("ID_STATICTEXT35"));
    wxFont label_TasksListFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    label_TasksList->SetFont(label_TasksListFont);
    separador5 = new wxStaticLine(tab_tasks, ID_STATICLINE5, wxPoint(8,332), wxSize(284,24), wxLI_HORIZONTAL, _T("ID_STATICLINE5"));
    choice_TasksList = new wxComboBox(tab_tasks, ID_COMBOBOX4, wxEmptyString, wxPoint(4,352), wxSize(284,29), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX4"));
    but_StartTask = new wxButton(tab_tasks, ID_BUTTON18, _("Start task"), wxPoint(4,400), wxSize(140,29), 0, wxDefaultValidator, _T("ID_BUTTON18"));
    but_StartTask->Disable();
    but_StopTask = new wxButton(tab_tasks, ID_BUTTON2, _("Stop task"), wxPoint(148,400), wxSize(140,29), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    but_StopTask->Disable();
    tabs_options->AddPage(tab_ROS, _("ROS"), false);
    tabs_options->AddPage(tab_objects, _("Objects"), false);
    tabs_options->AddPage(tab_tasks, _("Tasks"), false);
    sizer_options->Add(panel_options, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    panel_options_main->SetSizer(sizer_options);
    sizer_options->SetSizeHints(panel_options_main);
    panel_ontray_main = new wxPanel(panel_main, ID_PANEL31, wxPoint(1048,488), wxSize(292,148), wxRAISED_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL31"));
    panel_ontray_main->Disable();
    label_ObjectsOnTray = new wxStaticText(panel_ontray_main, ID_STATICTEXT26, _("Objects on tray"), wxPoint(4,4), wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    label_ontray = new wxStaticText(panel_ontray_main, ID_STATICTEXT27, _("(0)"), wxPoint(116,4), wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    wxFont label_ontrayFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    label_ontray->SetFont(label_ontrayFont);
    panel_objects_on_tray = new wxPanel(panel_ontray_main, ID_PANEL1, wxPoint(2,32), wxSize(284,110), wxRAISED_BORDER, _T("ID_PANEL1"));
    scrollablewindow_ontray = new wxScrolledWindow(panel_objects_on_tray, ID_SCROLLEDWINDOW1, wxPoint(0,0), wxSize(292,144), wxHSCROLL|wxVSCROLL, _T("ID_SCROLLEDWINDOW1"));
    img_update_ontray = new wxBitmapButton(panel_ontray_main, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("./img/update.png"))), wxPoint(260,0), wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu6 = new wxMenu();
    menu_skype = new wxMenu();
    option_skype_start = new wxMenuItem(menu_skype, ID_MENUITEM10, _("Start"), wxEmptyString, wxITEM_NORMAL);
    menu_skype->Append(option_skype_start);
    option_skype_start->Enable(false);
    menu_skype->AppendSeparator();
    option_skype_restart = new wxMenuItem(menu_skype, ID_MENUITEM11, _("Reinitialize"), wxEmptyString, wxITEM_NORMAL);
    menu_skype->Append(option_skype_restart);
    Menu6->Append(ID_MENUITEM13, _("Skype"), menu_skype, wxEmptyString);
    menu_rviz = new wxMenu();
    menu_rviz_run = new wxMenuItem(menu_rviz, ID_MENUITEM1, _("Run"), _("Run run run!"), wxITEM_NORMAL);
    menu_rviz->Append(menu_rviz_run);
    menu_rviz_run->Enable(false);
    menu_rviz->AppendSeparator();
    menu_rviz_vis = new wxMenu();
    MenuItem5 = new wxMenuItem(menu_rviz_vis, ID_MENUITEM3, _("Distance"), wxEmptyString, wxITEM_NORMAL);
    menu_rviz_vis->Append(MenuItem5);
    MenuItem8 = new wxMenuItem(menu_rviz_vis, ID_MENUITEM6, _("Cam display"), wxEmptyString, wxITEM_NORMAL);
    menu_rviz_vis->Append(MenuItem8);
    Menu5 = new wxMenu();
    MenuItem17 = new wxMenu();
    MenuItem15 = new wxMenuItem(MenuItem17, ID_MENUITEM17, _("Movable objects"), wxEmptyString, wxITEM_NORMAL);
    MenuItem17->Append(MenuItem15);
    MenuItem16 = new wxMenuItem(MenuItem17, ID_MENUITEM18, _("Furniture objects"), wxEmptyString, wxITEM_NORMAL);
    MenuItem17->Append(MenuItem16);
    Menu5->Append(ID_MENUITEM19, _("Add"), MenuItem17, wxEmptyString);
    MenuItem18 = new wxMenu();
    MenuItem19 = new wxMenuItem(MenuItem18, ID_MENUITEM21, _("Movable objects"), wxEmptyString, wxITEM_NORMAL);
    MenuItem18->Append(MenuItem19);
    MenuItem20 = new wxMenuItem(MenuItem18, ID_MENUITEM22, _("Furniture objects"), wxEmptyString, wxITEM_NORMAL);
    MenuItem18->Append(MenuItem20);
    Menu5->Append(ID_MENUITEM20, _("Remove"), MenuItem18, wxEmptyString);
    menu_rviz_vis->Append(ID_MENUITEM16, _("Spawn objects"), Menu5, wxEmptyString);
    menu_rviz->Append(ID_MENUITEM2, _("Visualization"), menu_rviz_vis, wxEmptyString);
    menu_rviz_manip = new wxMenu();
    MenuItem11 = new wxMenuItem(menu_rviz_manip, ID_MENUITEM9, _("Assisted arm navigation"), wxEmptyString, wxITEM_NORMAL);
    menu_rviz_manip->Append(MenuItem11);
    MenuItem7 = new wxMenuItem(menu_rviz_manip, ID_MENUITEM5, _("Move base"), wxEmptyString, wxITEM_NORMAL);
    menu_rviz_manip->Append(MenuItem7);
    MenuItem9 = new wxMenuItem(menu_rviz_manip, ID_MENUITEM7, _("Go to..."), wxEmptyString, wxITEM_NORMAL);
    menu_rviz_manip->Append(MenuItem9);
    menu_rviz->Append(ID_MENUITEM4, _("Manipulation"), menu_rviz_manip, wxEmptyString);
    Menu6->Append(ID_MENUITEM12, _("Rviz"), menu_rviz, wxEmptyString);
    menu_dashboard = new wxMenu();
    menu_dashboard_run = new wxMenuItem(menu_dashboard, ID_MENUITEM15, _("Run"), wxEmptyString, wxITEM_NORMAL);
    menu_dashboard->Append(menu_dashboard_run);
    menu_dashboard_run->Enable(false);
    Menu6->Append(ID_MENUITEM14, _("Dashboard"), menu_dashboard, wxEmptyString);
    menu_status = new wxMenu();
    menu_status_rxgraph = new wxMenuItem(menu_status, ID_MENUITEM23, _("rxgraph"), wxEmptyString, wxITEM_NORMAL);
    menu_status->Append(menu_status_rxgraph);
    menu_status_runtimeMonitor = new wxMenuItem(menu_status, ID_MENUITEM24, _("Runtime monitor"), wxEmptyString, wxITEM_NORMAL);
    menu_status->Append(menu_status_runtimeMonitor);
    Menu6->Append(ID_MENUITEM8, _("Status"), menu_status, wxEmptyString);
    MenuBar1->Append(Menu6, _("Tools"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    timer_updates.SetOwner(this, ID_TIMER1);
    timer_URI.SetOwner(this, ID_TIMER2);
    timer_RequestsEvent.SetOwner(this, ID_TIMER3);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -10 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    timer_skype_contacts.SetOwner(this, ID_TIMER4);
    timer_ROS.SetOwner(this, ID_TIMER5);
    timer_choice.SetOwner(this, ID_TIMER6);
    timer_dmServer.SetOwner(this, ID_TIMER7);

    Connect(ID_GRID1,wxEVT_GRID_CELL_LEFT_DCLICK,(wxObjectEventFunction)&srs_ui_proFrame::Ongrid_requestsCellLeftDClick);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::showContextualMenu);
    Connect(ID_LISTCTRL2,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&srs_ui_proFrame::acceptCall);
    Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_move_STARTClick);
    Connect(ID_CHOICE3,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onchoice_automatic_moveSelect);
    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_get_STARTClick);
    Connect(ID_CHOICE8,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onchoice_automatic_getSelect);
    Connect(ID_CHOICE4,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onchoice_automatic_getSelect);
    Connect(ID_BUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_search_STARTClick);
    Connect(ID_CHOICE7,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onchoice_automatic_searchSelect);
    Connect(ID_CHOICE5,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onchoice_automatic_searchSelect);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_fetch_STARTClick);
    Connect(ID_CHOICE10,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onchoice_automatic_fetchSelect);
    Connect(ID_CHOICE9,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onchoice_automatic_fetchSelect);
    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onchoice_automatic_fetchSelect);
    Connect(ID_BUTTON25,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_deliver_STARTClick);
    Connect(ID_CHOICE12,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onchoice_automatic_deliverSelect);
    Connect(ID_CHOICE11,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onchoice_automatic_deliverSelect);
    Connect(ID_CHOICE6,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onchoice_automatic_deliverSelect);
    Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_DMPauseClick);
    Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_DMResumeClick);
    Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_DMStopClick);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton12Click1);
    Connect(ID_BUTTON36,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton12Click2);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbut_navigation_dashboardClick1);
    Connect(ID_BUTTON37,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbut_head_frontClick);
    Connect(ID_BUTTON38,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbut_head_backClick);
    Connect(ID_BUTTON40,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton2Click);
    Connect(ID_BUTTON39,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton1Click);
    Connect(ID_BUTTON41,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton17Click);
    Connect(ID_BUTTON42,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton18Click);
    Connect(ID_BUTTON44,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton20Click);
    Connect(ID_BUTTON43,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton19Click);
    Connect(ID_BUTTON46,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton22Click);
    Connect(ID_BUTTON47,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton23Click);
    Connect(ID_BUTTON45,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton23Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::DetectObjects);
    Connect(ID_BUTTON33,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_spawn_objectsClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_GenerateGraspsClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_GraspItClick);
    Connect(ID_BUTTON22,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_simulateGraspClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::manual_joystickButton);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton4Click);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton5Click);
    Connect(ID_BUTTON23,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton1Click2);
    Connect(ID_BUTTON31,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton2Click1);
    Connect(ID_BUTTON32,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::OnButton3Click);
    Connect(ID_RADIOBUTTON13,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::baseTeleopOn);
    Connect(ID_RADIOBUTTON14,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::baseTeleopOff);
    Connect(ID_RADIOBUTTON15,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::distanceLinuarOn);
    Connect(ID_RADIOBUTTON16,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::distanceLinuarOff);
    Connect(ID_RADIOBUTTON17,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::distanceCircularOn);
    Connect(ID_RADIOBUTTON18,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::distanceCircularOff);
    Connect(ID_RADIOBUTTON19,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::stretchIndicatorOn);
    Connect(ID_RADIOBUTTON20,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::stretchIndicatorOff);
    Connect(ID_RADIOBUTTON21,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::objectManagerOn);
    Connect(ID_RADIOBUTTON22,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::objectManagerOff);
    Connect(ID_RADIOBUTTON9,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::dataFusionOn);
    Connect(ID_RADIOBUTTON10,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::dataFusionOff);
    Connect(ID_RADIOBUTTON11,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::assistedArmNavigationOn);
    Connect(ID_RADIOBUTTON12,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::assistedArmNavigationOff);
    Connect(ID_RADIOBUTTON7,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::assistedGraspOn);
    Connect(ID_RADIOBUTTON8,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::assistedGraspOff);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onimg_update_rosinfoClick);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::Onimg_update_ontrayClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::OnQuit);
    Connect(ID_MENUITEM10,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::OnMenuSkypeStart);
    Connect(ID_MENUITEM11,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::ReinitializeSkype);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::runRviz);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_im_distanceClick);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_im_camClick);
    Connect(ID_MENUITEM17,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::spawnDetectedObjects);
    Connect(ID_MENUITEM18,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::spawnobjects);
    Connect(ID_MENUITEM21,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::removeDetectedObjects);
    Connect(ID_MENUITEM22,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::removeObjects);
    Connect(ID_MENUITEM9,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_im_assistedarmClick);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::manual_moveBaseButton);
    Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onbutton_im_gotoClick);
    Connect(ID_MENUITEM15,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::runDashboard);
    Connect(ID_MENUITEM23,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onmenu_status_rxgraphSelected);
    Connect(ID_MENUITEM24,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::Onmenu_status_runtimeMonitorSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&srs_ui_proFrame::Ontimer_updatesTrigger);
    Connect(ID_TIMER2,wxEVT_TIMER,(wxObjectEventFunction)&srs_ui_proFrame::Ontimer_URITrigger);
    Connect(ID_TIMER3,wxEVT_TIMER,(wxObjectEventFunction)&srs_ui_proFrame::Ontimer_RequestsEventTrigger1);
    Connect(ID_TIMER4,wxEVT_TIMER,(wxObjectEventFunction)&srs_ui_proFrame::Onskype_timerTrigger1);
    Connect(ID_TIMER5,wxEVT_TIMER,(wxObjectEventFunction)&srs_ui_proFrame::Ontimer_ROSTrigger);
    Connect(ID_TIMER6,wxEVT_TIMER,(wxObjectEventFunction)&srs_ui_proFrame::Ontimer_choiceTrigger);
    Connect(ID_TIMER7,wxEVT_TIMER,(wxObjectEventFunction)&srs_ui_proFrame::Ontimer_dmServerTrigger);
    //*)

    SF = sf;
    PM = pm;
    offline = offline;
    stopTimers();
    Initialize();
    connectToSkype();
    option_skype_start->Enable();
    DM_W_launched = false;
    //InitSkype();
}

srs_ui_proFrame::~srs_ui_proFrame()
{
    delete SF;
    delete PM;
    delete Ri;
    //delete RvI;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void srs_ui_proFrame::Initialize()
{
    RosInterface::init();
    //RvI = new RvizInterface();

    //SF = new SkypeFunctions();
    //PM = new ProcessManager();
    num_events = 0;
    dm_working = false;
    dm_paused = dm_resumed = dm_stoped = false;
    run_notification = false;
    last_chat_user = "None";
    current_task_id = "None";

    InitTactileSensorSimulator();
    InitSkypeNotebooks();
}

void srs_ui_proFrame::InitTactileSensorSimulator()
{
    int x,y;
    x = 0;
    y = 0;

    for (unsigned int i=0; i<14; i++)
    {
        for (unsigned int j=0; j<6; j++)
        {
            ts_finger11.push_back(new wxStaticBitmap(panel_ts11, wxNewId(), wxBitmap(wxImage(_T("./img/ts_off.png"))), wxPoint(x,y), wxDefaultSize, 0, _T("ID_STATICBITMAP12")));
            ts_finger12.push_back(new wxStaticBitmap(panel_ts12, wxNewId(), wxBitmap(wxImage(_T("./img/ts_off.png"))), wxPoint(x,y), wxDefaultSize, 0, _T("ID_STATICBITMAP12")));
            ts_finger21.push_back(new wxStaticBitmap(panel_ts21, wxNewId(), wxBitmap(wxImage(_T("./img/ts_off.png"))), wxPoint(x,y), wxDefaultSize, 0, _T("ID_STATICBITMAP12")));
            ts_finger22.push_back(new wxStaticBitmap(panel_ts22, wxNewId(), wxBitmap(wxImage(_T("./img/ts_off.png"))), wxPoint(x,y), wxDefaultSize, 0, _T("ID_STATICBITMAP12")));
            ts_finger31.push_back(new wxStaticBitmap(panel_ts31, wxNewId(), wxBitmap(wxImage(_T("./img/ts_off.png"))), wxPoint(x,y), wxDefaultSize, 0, _T("ID_STATICBITMAP12")));
            ts_finger32.push_back(new wxStaticBitmap(panel_ts32, wxNewId(), wxBitmap(wxImage(_T("./img/ts_off.png"))), wxPoint(x,y), wxDefaultSize, 0, _T("ID_STATICBITMAP12")));
            x+=10;
        }
        x=0;
        y+=10;
    }
}

void srs_ui_proFrame::LoadDBObjects()
{
    try
    {
        scrollablewindow_dbobjects->Scroll(0,0);
        std::vector<wxImage> oot = Ri->getAllDBImages();


        for (unsigned int i=0; i<img_db_objects.size(); i++)
            delete img_db_objects[i];
        img_db_objects.resize(0);

        int x=8, y=0;
        for (unsigned int i=0; i<oot.size(); i++)
        {
            if (i>0 && i%3==0)
            {
                x=8; y+=96;
            }
            std::string img_name = "img_auto_"+i;
            oot[i].Rescale(82, 82);
            wxBitmapButton *img = new wxBitmapButton(scrollablewindow_dbobjects, wxNewId(), wxBitmap(oot[i]), wxPoint(x,y), wxSize(82,82), wxBU_AUTODRAW, wxDefaultValidator, toWXString(img_name));
            img_db_objects.push_back(img);
            x+=94;
        }
        scrollablewindow_dbobjects->SetScrollbars(0, 5, 0, (y+94+8)/5);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e) {writeInLog(); }
}

void srs_ui_proFrame::stopTimers()
{
    timer_ROS.Stop();
    timer_URI.Stop();
    timer_RequestsEvent.Stop();
    timer_updates.Stop();
    timer_skype_contacts.Stop();
    timer_choice.Stop();
}

std::string srs_ui_proFrame::toString(wxString wx)
{
    return std::string(wx.mb_str());
}

std::string srs_ui_proFrame::toString(float f)
{
    std::stringstream aux;
    aux << f;
    return aux.str().c_str();
}

std::string srs_ui_proFrame::toStringN(wxString wx)
{
    return toString(wx)+"\n";
}

wxString srs_ui_proFrame::toWXString(std::string s)
{
    return wxString(s.c_str(), wxConvUTF8);
}

wxString srs_ui_proFrame::toWXString(float f)
{
    std::stringstream aux;
    aux << f;
    return toWXString(aux.str().c_str());
}

wxString srs_ui_proFrame::toWXStringN(std::string s)
{
    s+="\n";
    return toWXString(s);
}

bool srs_ui_proFrame::toFloat(std::string str, float &f)
{
    if (str.size() == 0)
        return false;

    char *s = new char[str.length() + 1];
    strcpy(s, str.c_str());

    int num_separators = 0;

    for (unsigned int i=0; i<str.size(); i++)
    {
        if (s[i] == ',' || s[i] == '.')
        {
            s[i] = '.';
            num_separators++;
            if (i == 0 || num_separators>1)
                return false;
        }
        else if (s[i] < '0' || s[i] > '9')
            return false;

    }

    f = atof(s);
    return true;
}

bool srs_ui_proFrame::toFloat(wxString wx, float &f)
{
    return toFloat(toString(wx), f);
}

void srs_ui_proFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void srs_ui_proFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void srs_ui_proFrame::InitPredefinedPoses()
{
    bool throw_timer = true;
    try
    {
        std::vector<std::string> poses = Ri->get_predefined_poses();
        std::vector<std::string> objects = Ri->get_objects_on_map();
        std::vector<std::string> workspaces = Ri->get_workspace_on_map();

        for (unsigned int i=0; i<poses.size(); i++)
        {
            choice_automatic_move->Append(toWXString(poses[i]));
            choice_automatic_fetch_order->Append(toWXString(poses[i]));
            choice_automatic_deliver_deliver_position->Append(toWXString(poses[i]));
        }

        for (unsigned int i=0; i<objects.size(); i++)
        {
            choice_automatic_get->Append(toWXString(objects[i]));
            choice_automatic_search->Append(toWXString(objects[i]));
            choice_automatic_fetch->Append(toWXString(objects[i]));
            choice_automatic_deliver->Append(toWXString(objects[i]));
            choice_objectstodetect->Append(toWXString(objects[i]));
        }

        for (unsigned int i=0; i<workspaces.size(); i++)
        {
            choice_automatic_get_search->Append(toWXString(workspaces[i]));
            choice_automatic_search_search->Append(toWXString(workspaces[i]));
            choice_automatic_fetch_search->Append(toWXString(workspaces[i]));
            choice_automatic_deliver_search->Append(toWXString(workspaces[i]));
        }


        throw_timer = false;
        if (timer_choice.IsRunning())
            timer_choice.Stop();
    }
    catch(ServiceUnavailable &e){  if (!timer_choice.IsRunning()) writeInLog(e.getMessage());   }
    catch(ServiceCallFailed &e) {  if (!timer_choice.IsRunning()) writeInLog(e.getMessage());   }
    catch(std::exception &e)    {  if (!timer_choice.IsRunning()) writeInLog();                 }

    if (throw_timer && !timer_choice.IsRunning())
        timer_choice.Start(30000, false);
}

void srs_ui_proFrame::UpdateTactilSensorSimulator()
{
    RosInterface::tactil_data tactil_data = Ri->getTactilSensorData();

    wxBitmap off(wxImage(_T("./img/ts_off.png")));
    wxBitmap on_red(wxImage(_T("./img/ts_on_red.png")));
    wxBitmap on_orange(wxImage(_T("./img/ts_on_orange.png")));
    wxBitmap on_yellow(wxImage(_T("./img/ts_on_yellow.png")));
    wxBitmap on_yellow2(wxImage(_T("./img/ts_on_yellow2.png")));
    wxBitmap on_white(wxImage(_T("./img/ts_on_white.png")));


    for (unsigned int i=0; i<tactil_data.m1.size(); i++)
    {
        //m1
        if (tactil_data.m1[i]>3500)
            ts_finger11[i]->SetBitmap(on_red);
        else if (tactil_data.m1[i]>2500)
            ts_finger11[i]->SetBitmap(on_orange);
        else if (tactil_data.m1[i]>1500)
            ts_finger11[i]->SetBitmap(on_yellow);
        else if (tactil_data.m1[i]>500)
            ts_finger11[i]->SetBitmap(on_yellow2);
        else if (tactil_data.m1[i]>0)
            ts_finger11[i]->SetBitmap(on_white);
        else
            ts_finger11[i]->SetBitmap(off);

        //m2
        if (tactil_data.m2[i]>3500)
            ts_finger12[i]->SetBitmap(on_red);
        else if (tactil_data.m2[i]>2500)
            ts_finger12[i]->SetBitmap(on_orange);
        else if (tactil_data.m2[i]>1500)
            ts_finger12[i]->SetBitmap(on_yellow);
        else if (tactil_data.m2[i]>500)
            ts_finger12[i]->SetBitmap(on_yellow2);
        else if (tactil_data.m2[i]>0)
            ts_finger12[i]->SetBitmap(on_white);
        else
            ts_finger12[i]->SetBitmap(off);

        //m3
        if (tactil_data.m3[i]>3500)
            ts_finger21[i]->SetBitmap(on_red);
        else if (tactil_data.m3[i]>2500)
            ts_finger21[i]->SetBitmap(on_orange);
        else if (tactil_data.m3[i]>1500)
            ts_finger21[i]->SetBitmap(on_yellow);
        else if (tactil_data.m3[i]>500)
            ts_finger21[i]->SetBitmap(on_yellow2);
        else if (tactil_data.m3[i]>0)
            ts_finger21[i]->SetBitmap(on_white);
        else
            ts_finger21[i]->SetBitmap(off);

        //m4
        if (tactil_data.m4[i]>3500)
            ts_finger22[i]->SetBitmap(on_red);
        else if (tactil_data.m4[i]>2500)
            ts_finger22[i]->SetBitmap(on_orange);
        else if (tactil_data.m4[i]>1500)
            ts_finger22[i]->SetBitmap(on_yellow);
        else if (tactil_data.m4[i]>500)
            ts_finger22[i]->SetBitmap(on_yellow2);
        else if (tactil_data.m4[i]>0)
            ts_finger22[i]->SetBitmap(on_white);
        else
            ts_finger22[i]->SetBitmap(off);

        //m5
        if (tactil_data.m5[i]>3500)
            ts_finger31[i]->SetBitmap(on_red);
        else if (tactil_data.m5[i]>2500)
            ts_finger31[i]->SetBitmap(on_orange);
        else if (tactil_data.m5[i]>1500)
            ts_finger31[i]->SetBitmap(on_yellow);
        else if (tactil_data.m5[i]>500)
            ts_finger31[i]->SetBitmap(on_yellow2);
        else if (tactil_data.m5[i]>0)
            ts_finger31[i]->SetBitmap(on_white);
        else
            ts_finger31[i]->SetBitmap(off);

        //m6
        if (tactil_data.m6[i]>3500)
            ts_finger32[i]->SetBitmap(on_red);
        else if (tactil_data.m6[i]>2500)
            ts_finger32[i]->SetBitmap(on_orange);
        else if (tactil_data.m6[i]>1500)
            ts_finger32[i]->SetBitmap(on_yellow);
        else if (tactil_data.m6[i]>500)
            ts_finger32[i]->SetBitmap(on_yellow2);
        else if (tactil_data.m6[i]>0)
            ts_finger32[i]->SetBitmap(on_white);
        else
            ts_finger32[i]->SetBitmap(off);
    }
}

void srs_ui_proFrame::UpdateRobotStatus()
{
    pr2_msgs::PowerState ps = Ri->getPowerState();
    bar_status_battery->SetValue(ps.relative_capacity);

    int time = ps.time_remaining.sec;
    std::stringstream aux;
    aux << time;
    label_status_TimeBattery->SetLabel(toWXString(aux.str()));

    //pr2_msgs::AccessPoint ws = Ri->getWifiState();
    //bar_wifi_signal->SetValue(ws.signal);
}

void srs_ui_proFrame::UpdateIMGs()
{
    wxBitmap img_on(wxImage(_T("./img/on.gif")));
    wxBitmap img_off(wxImage(_T("./img/off.gif")));

    if (PM->WaitDashboard() == -4)
        img_navigation_dashboard->SetBitmap(img_on);
    else
        img_navigation_dashboard->SetBitmap(img_off);

/*
    if (PM->WaitIM_goTo() == -4)
        img_RvizTools_GoTo->SetBitmap(img_on);
    else
        img_RvizTools_GoTo->SetBitmap(img_off);

    if (PM->WaitIM_moveBase() == -4)
        img_RvizTools_InteractiveTeleop->SetBitmap(img_on);
    else
        img_RvizTools_InteractiveTeleop->SetBitmap(img_off);

    if (PM->WaitIM_distanceViewer() == -4)
        img_RvizTools_DistanceVisualizer->SetBitmap(img_on);
    else
        img_RvizTools_DistanceVisualizer->SetBitmap(img_off);

    if (PM->WaitIM_camDisplay() == -4)
        img_RvizTools_CamDisplay->SetBitmap(img_on);
    else
        img_RvizTools_CamDisplay->SetBitmap(img_off);
    if (PM->WaitIM_AssistedArmNavigation() == -4)
        img_RvizTools_AssistedArmNavigation->SetBitmap(img_on);
    else
        img_RvizTools_AssistedArmNavigation->SetBitmap(img_off);
*/
    /* Node control */
/*
    if (Ri->nodeExists("/cob_interactive_teleop"))
    {
        img_RvizTools_InteractiveTeleop->SetBitmap(img_on);
        but_RvizTools_InteractiveTeleop->Enable(false);
    }
    else
    {
        img_RvizTools_InteractiveTeleop->SetBitmap(img_off);
        but_RvizTools_InteractiveTeleop->Enable(true);
        but_RvizTools_InteractiveTeleop->SetLabel(toWXString("Launch it"));
    }

    if (Ri->nodeExists("/but_service_server"))
    {
        img_RvizTools_DistanceVisualizer->SetBitmap(img_on);
        but_RvizTools_DistanceVisualizer->Enable(false);
    }
    else
    {
        img_RvizTools_DistanceVisualizer->SetBitmap(img_off);
        but_RvizTools_DistanceVisualizer->Enable(true);
        but_RvizTools_DistanceVisualizer->SetLabel(toWXString("Launch it"));
    }

    if (Ri->nodeExists("/view"))
    {
        img_RvizTools_CamDisplay->SetBitmap(img_on);
        but_RvizTools_CamDisplay->Enable(false);
    }
    else
    {
        img_RvizTools_CamDisplay->SetBitmap(img_off);
        but_RvizTools_CamDisplay->Enable(true);
        but_RvizTools_CamDisplay->SetLabel(toWXString("Launch it"));
    }

    if (Ri->nodeExists("/assisted_arm_navigation"))
    {
        img_RvizTools_AssistedArmNavigation->SetBitmap(img_on);
        but_RvizTools_AssistedArm_Launch->Enable(false);
        but_RvizTools_AssistedArmNavigation->Enable(true);
    }
    else
    {
        img_RvizTools_AssistedArmNavigation->SetBitmap(img_off);
        but_RvizTools_AssistedArm_Launch->Enable(true);
        but_RvizTools_AssistedArm_Launch->SetLabel(toWXString("Launch it"));
        but_RvizTools_AssistedArmNavigation->Enable(false);
    }
*/
}


void srs_ui_proFrame::runRviz(wxCommandEvent& event)
{
    //RvI->showRviz();
    PM->ExecRviz(RVIZ_CONFIG);
    but_SpawnObjectsInRviz->Enable();
}

void srs_ui_proFrame::Onbutton_GenerateGraspsClick(wxCommandEvent& event)
{
    wxMessageBox( wxT("The graspings will be generated in second plane. When the process finish, you will be notified."), wxT("SRS_UI_PRO: Grasp generation."), wxICON_INFORMATION);
    pthread_t thread1;
    pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_GenerateGrasps, (void*)this);
}

void srs_ui_proFrame::Onbutton_GraspItClick(wxCommandEvent& event)
{
    bool res = Ri->GraspIt(generated_grasps[choice_grasp_conf->GetValue()]);

    if (res)
    {
        int number_of_fingers = Ri->howManyFingersHasTheGrasp();
        std::stringstream aux;
        aux << number_of_fingers;

        std::string aux2 = "The hand is grasping the object with " + aux.str() + " fingers.";
        box_graspResult->SetValue(toWXString(aux2));
        wxBitmap img_on(wxImage(_T("./img/on.gif")));
        img_graspResult->SetBitmap(img_on);
    }
    else
    {
        box_graspResult->SetValue(_T("Failed grasp."));
        wxBitmap img_off(wxImage(_T("./img/off.gif")));
        img_graspResult->SetBitmap(img_off);
    }
}

void srs_ui_proFrame::Onbutton_simulateGraspClick(wxCommandEvent& event)
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_GraspSimulator, (void*)this);
}

void srs_ui_proFrame::Onbutton_DMPauseClick(wxCommandEvent& event)
{
    pthread_t thread1;

    dm_thread_arg *arg = new dm_thread_arg;
        arg->form = this;
        arg->action = "pause";
        arg->log = box_dm_log;
        arg->json_parameters = "NULL";
        dm_resumed = dm_stoped = false;
        dm_paused = true;

        but_RESUME->Enable();
        but_PAUSE->Disable();
        but_STOP->Enable();

    pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
}

void srs_ui_proFrame::Onbutton_DMResumeClick(wxCommandEvent& event)
{
    pthread_t thread1;

    dm_thread_arg *arg = new dm_thread_arg;
        arg->form = this;
        arg->action = "resume";
        arg->log = box_dm_log;
        arg->json_parameters = "NULL";

        dm_paused = dm_stoped = false;
        dm_resumed = true;

        but_RESUME->Disable();
        but_PAUSE->Enable();
        but_STOP->Enable();


    pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
}

void srs_ui_proFrame::Onbutton_DMStopClick(wxCommandEvent& event)
{
    pthread_t thread1;

    dm_thread_arg *arg = new dm_thread_arg;
        arg->form = this;
        arg->action = "stop";
        arg->log = box_dm_log;
        arg->json_parameters = "NULL";
        dm_resumed = dm_paused = false;
        dm_stoped = true;

        but_RESUME->Disable();
        but_PAUSE->Disable();
        but_STOP->Disable();

    pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
}

void srs_ui_proFrame::Onbutton_im_distanceClick(wxCommandEvent& event)
{
    PM->ExecIM_distanceViewer();

    /*
    if (PM->WaitIM_distanceViewer() == -4)
        PM->ExitIM_distanceViewer();
    else
        PM->ExecIM_distanceViewer();
    */
}

void srs_ui_proFrame::Onbutton_im_camClick(wxCommandEvent& event)
{
    PM->ExecIM_camDisplay();

    /*
    if (PM->WaitIM_camDisplay() == -4)
        PM->ExitIM_camDisplay();
    else
        PM->ExecIM_camDisplay();
    */
}

void srs_ui_proFrame::Onbutton_im_gotoClick(wxCommandEvent& event)
{
    if (PM->WaitIM_goTo() == -4)
        PM->ExitIM_goTo();
    else
        PM->ExecIM_goTo();
}

void srs_ui_proFrame::semi_goToButton(wxCommandEvent& event)
{
    if (PM->WaitIM_goTo() == -4)
        PM->ExitIM_goTo();

    else
        PM->ExecIM_goTo();
}

void srs_ui_proFrame::manual_moveBaseButton(wxCommandEvent& event)
{
    PM->ExecIM_moveBase();

    /*
    if (PM->WaitIM_moveBase() == -4)
        PM->ExitIM_moveBase();
    else
        PM->ExecIM_moveBase();
    */
}

void srs_ui_proFrame::manual_joystickButton(wxCommandEvent& event)
{
    //TODO
}


void srs_ui_proFrame::DetectObjects(wxCommandEvent& event)
{
    //std::vector<std::string> objet_models = Ri->getGazeboModels();
    long id = -1;
    if (choice_objectstodetect->GetCurrentSelection() == -1)
        wxMessageBox(wxT("You must select a target value!\t"), wxT("srs_ui_pro"), wxICON_INFORMATION);
    else
    {
        std::vector<std::string> objet_models;
        std::string object_to_detect = toString(choice_objectstodetect->GetStringSelection());
        objet_models.push_back(object_to_detect);

        for (unsigned int i=0; i<img_objects.size(); i++)
            delete img_objects[i];

        choice_selected_grasp_object->Clear();
        img_objects.clear();
        detected_objects.clear();

        img_objects.resize(objet_models.size());
        int x = 8;

        for (unsigned int i=0; i<objet_models.size(); i++)
        {
            //std::string object_name = (std::string((wxString(objet_models[i].c_str(), wxConvUTF8)).mb_str(wxConvUTF8)));
            std::string object_name = objet_models[i].c_str();
            try
            {
                cob_object_detection_msgs::Detection obj_info = Ri->Detect(object_name);
                if (obj_info.label != "")
                {
                    detected_objects.push_back(obj_info);
                    int object_id = Ri->getObjectId(objet_models[i].c_str());
                    std::string path = "./img/" + objet_models[i] + ".jpg";
                    wxImage objectIMG = Ri->getObjectIMG(object_id);
                    objectIMG.Rescale(95, 95);

                    wxString final_path = toWXString(path);
                    wxBitmapButton *img = new wxBitmapButton(panel_detected_objects, id, wxBitmap(objectIMG), wxPoint(x,16), wxSize(125,125), wxBU_AUTODRAW, wxDefaultValidator, toWXString(objet_models[i]));
                    img_objects.push_back(img);
                    x+=260;

                    choice_selected_grasp_object->Append(toWXString(objet_models[i]));
                    id = wxNewId();
                    Connect(id ,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&srs_ui_proFrame::object_info);
                }
                else
                {
                    std::string aux_msg = "[INFO] Can't detect the " + object_name + " object.\n";
                    writeInLog(aux_msg);
                }

            }
            catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
            catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
            catch(std::exception &e) { writeInLog(); }
        }

        if (id != -1)
            tab_semi_grasping->Enable();
        else
            tab_semi_grasping->Disable();
    }

}

void srs_ui_proFrame::object_info(wxCommandEvent& event)
{
    wxBitmapButton *r = (wxBitmapButton *)event.GetEventObject();
    ObjectInfo *Frame = new ObjectInfo(0, Ri, detected_objects[r->GetId()]);
    Frame->Show(TRUE);
}

void srs_ui_proFrame::StartClick(wxCommandEvent& event)
{
    //Connect to URI
    timer_URI.Start(1000, false);
    //timer_ROS.Start(500, false);
    //timer_RequestsEvent.Start(5000,false);
}

void srs_ui_proFrame::Onbutton_im_assistedarmClick(wxCommandEvent& event)
{
    try
    {
        pthread_t thread1;
        pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_StartAssistedArm, (void*)this);
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }

/*
    if (PM->WaitIM_AssistedArmNavigation() == -4)
        PM->ExitIM_AssistedArmNavigation();
    else
    {
        //PM->ExecIM_AssistedArmNavigation(); //Asumimos que está lanzado.
        pthread_t thread1;
        pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_StartAssistedArm, (void*)this);
    }
*/
}

void srs_ui_proFrame::Onbut_navigation_dashboardClick(wxCommandEvent& event)
{
    if (PM->WaitDashboard() == -4)
        PM->ExitDashboard();
    else
        PM->ExecDashboard();
}

void srs_ui_proFrame::Onmenu_status_rxgraphSelected(wxCommandEvent& event)
{
    if (PM->WaitRxgraph() == -4)
        PM->ExitRxgraph();
    else
        PM->ExecRxgraph();
}

void srs_ui_proFrame::Onmenu_status_runtimeMonitorSelected(wxCommandEvent& event)
{
    if (PM->WaitRuntimeMonitor() == -4)
        PM->ExitRuntimeMonitor();
    else
        PM->ExecRuntimeMonitor();
}

void srs_ui_proFrame::Onbutton_move_STARTClick(wxCommandEvent& event)
{
    if (choice_automatic_move->GetCurrentSelection() == -1)
        wxMessageBox(wxT("You must select a target value!\t"), wxT("SRS_DECISION_MAKING"), wxICON_INFORMATION);
    else
    {
        //-----------------------------------------
        if (but_RESUME->IsEnabled() || but_PAUSE->IsEnabled())
        {
            wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Do you want continue?"), wxT("srs_ui_pro: The current action will be stopped!"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
            int res = dial->ShowModal();

            if (res == wxID_YES)
            {
                pthread_t thread1;

                dm_thread_arg *arg = new dm_thread_arg;
                    arg->form = this;
                    arg->action = "stop";
                    arg->log = box_dm_log;

                    dm_resumed = dm_paused = false;
                    dm_stoped = true;

                    but_RESUME->Disable();
                    but_PAUSE->Disable();
                    but_STOP->Disable();

                pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
            }
            else return;
        }
        //-------------------------------------

        pthread_t thread1;

        dm_thread_arg *arg = new dm_thread_arg;
            arg->form = this;
            arg->action = "move";
            arg->parameters = toString(choice_automatic_move->GetStringSelection());
            arg->log = box_dm_log;


            arg->json_parameters = "{\"tasks\":[{\"task\":\"move\",\"destination\":{\"predefined_pose\":\""+toString(choice_automatic_move->GetStringSelection())+"\"}}],\"initializer\":{\"device_type\":\"srs_ui_pro\",\"device_id\":\"srs_ui_pro_0001\"}}";

        but_RESUME->Disable();
        but_PAUSE->Enable();
        but_STOP->Enable();

        pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
        writeInDMLog(toString(box_automatic_move_small->GetValue()), BLUE);
    }
}

void srs_ui_proFrame::Onbutton_search_STARTClick(wxCommandEvent& event)
{
    if (choice_automatic_search->GetCurrentSelection() == -1)
        wxMessageBox(wxT("You must select a target value!\t"), wxT("SRS_DECISION_MAKING"), wxICON_INFORMATION);
    else
    {
        //-----------------------------------------
        if (but_RESUME->IsEnabled() || but_PAUSE->IsEnabled())
        {
            wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Do you want continue?"), wxT("srs_ui_pro: The current action will be stopped!"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
            int res = dial->ShowModal();

            if (res == wxID_YES)
            {
                pthread_t thread1;

                dm_thread_arg *arg = new dm_thread_arg;
                    arg->form = this;
                    arg->action = "stop";
                    arg->log = box_dm_log;

                    dm_resumed = dm_paused = false;
                    dm_stoped = true;

                    but_RESUME->Disable();
                    but_PAUSE->Disable();
                    but_STOP->Disable();

                pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
            }
            else return;
        }
        //-------------------------------------

        pthread_t thread1;

        dm_thread_arg *arg = new dm_thread_arg;
            arg->form = this;
            arg->action = "search";
            std::string aux, aux2;
            aux2 = (choice_automatic_search_search->GetCurrentSelection() == -1)?"":"%" + toString(choice_automatic_search_search->GetStringSelection());
            aux = toString(choice_automatic_search->GetStringSelection())+aux2;
            arg->parameters = aux;
            arg->log = box_dm_log;

            std::string json_aux = (choice_automatic_search_search->GetCurrentSelection() == -1)?"":toString(choice_automatic_search_search->GetStringSelection());
            arg->json_parameters = "{\"tasks\":[{\"task\":\"search\",\"workspaces\":[\""+json_aux+"\"],\"object\":{\"object_type\":\""+toString(choice_automatic_search->GetStringSelection())+"\"}}],\"initializer\":{\"device_type\":\"srs_ui_pro\",\"device_id\":\"srs_ui_pro_0001\"}}";


        but_RESUME->Disable();
        but_PAUSE->Enable();
        but_STOP->Enable();

        pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
        writeInDMLog(toString(box_automatic_search_small->GetValue()), BLUE);
    }
}

void srs_ui_proFrame::Onbutton_get_STARTClick(wxCommandEvent& event)
{
    if (choice_automatic_get->GetCurrentSelection() == -1)
        wxMessageBox(wxT("You must select a target value!\t"), wxT("SRS_DECISION_MAKING"), wxICON_INFORMATION);
    else
    {
        //-----------------------------------------
        if (but_RESUME->IsEnabled() || but_PAUSE->IsEnabled())
        {
            wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Do you want continue?"), wxT("srs_ui_pro: The current action will be stopped!"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
            int res = dial->ShowModal();

            if (res == wxID_YES)
            {
                pthread_t thread1;

                dm_thread_arg *arg = new dm_thread_arg;
                    arg->form = this;
                    arg->action = "stop";
                    arg->log = box_dm_log;

                    dm_resumed = dm_paused = false;
                    dm_stoped = true;

                    but_RESUME->Disable();
                    but_PAUSE->Disable();
                    but_STOP->Disable();

                pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
            }
            else return;
        }
        //-------------------------------------

        pthread_t thread1;

        dm_thread_arg *arg = new dm_thread_arg;
            arg->form = this;
            arg->action = "get";
            std::string aux, aux2;
            aux2 = (choice_automatic_get_search->GetCurrentSelection() == -1)?"":"%" + toString(choice_automatic_get_search->GetStringSelection());
            aux = toString(choice_automatic_get->GetStringSelection())+aux2;
            arg->parameters = aux;
            arg->log = box_dm_log;

            std::string json_aux = (choice_automatic_get_search->GetCurrentSelection() == -1)?"":toString(choice_automatic_get_search->GetStringSelection());
            arg->json_parameters = "{\"tasks\":[{\"task\":\"get\",\"workspaces\":[\""+json_aux+"\"],\"object\":{\"object_type\":\""+toString(choice_automatic_get->GetStringSelection())+"\"}}],\"initializer\":{\"device_type\":\"srs_ui_pro\",\"device_id\":\"srs_ui_pro_0001\"}}";


        but_RESUME->Disable();
        but_PAUSE->Enable();
        but_STOP->Enable();

        pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
        writeInDMLog(toString(box_automatic_get_small->GetValue()), BLUE);
    }
}

void srs_ui_proFrame::Onbutton_fetch_STARTClick(wxCommandEvent& event)
{
    if (choice_automatic_fetch->GetCurrentSelection() == -1 || choice_automatic_fetch_order->GetCurrentSelection() == -1)
        wxMessageBox(wxT("You must select a target name and order position value!\t"), wxT("SRS_DECISION_MAKING"), wxICON_INFORMATION);
    else
    {

        //-----------------------------------------
        if (but_RESUME->IsEnabled() || but_PAUSE->IsEnabled())
        {
            wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Do you want continue?"), wxT("srs_ui_pro: The current action will be stopped!"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
            int res = dial->ShowModal();

            if (res == wxID_YES)
            {
                pthread_t thread1;

                dm_thread_arg *arg = new dm_thread_arg;
                    arg->form = this;
                    arg->action = "stop";
                    arg->log = box_dm_log;

                    dm_resumed = dm_paused = false;
                    dm_stoped = true;

                    but_RESUME->Disable();
                    but_PAUSE->Disable();
                    but_STOP->Disable();

                pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
            }
            else return;
        }
        //-------------------------------------

        pthread_t thread1;

        dm_thread_arg *arg = new dm_thread_arg;
            arg->form = this;
            arg->action = "fetch";
            std::string aux, aux2;
            aux2 = (choice_automatic_fetch_search->GetCurrentSelection() == -1)?"":"%"+toString(choice_automatic_fetch_search->GetStringSelection());
            aux = toString(choice_automatic_fetch->GetStringSelection()) + "%" + toString(choice_automatic_fetch_order->GetStringSelection()) + aux2;
            arg->parameters = aux;
            arg->log = box_dm_log;

            std::string json_aux = (choice_automatic_fetch_search->GetCurrentSelection() == -1)?"":toString(choice_automatic_fetch_search->GetStringSelection());
            arg->json_parameters = "{\"tasks\":[{\"task\":\"fetch\",\"workspaces\":[\""+json_aux+"\"],\"deliver_destination\":{\"predefined_pose\":\""+toString(choice_automatic_fetch_order->GetStringSelection())+"\"},\"object\":{\"object_type\":\""+toString(choice_automatic_fetch->GetStringSelection())+"\"}}],\"initializer\":{\"device_type\":\"srs_ui_pro\",\"device_id\":\"srs_ui_pro_0001\"}}";

        but_RESUME->Disable();
        but_PAUSE->Enable();
        but_STOP->Enable();

        pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
        writeInDMLog(toString(box_automatic_fetch_small->GetValue()), BLUE);
    }
}

void srs_ui_proFrame::Onbutton_deliver_STARTClick(wxCommandEvent& event)
{

    if (choice_automatic_deliver->GetCurrentSelection() == -1 || choice_automatic_deliver_deliver_position->GetCurrentSelection() == -1 || choice_automatic_deliver_search->GetCurrentSelection() == -1)
        wxMessageBox(wxT("You must select a target value!\t"), wxT("SRS_DECISION_MAKING"), wxICON_INFORMATION);
    else
    {
        //-----------------------------------------
        if (but_RESUME->IsEnabled() || but_PAUSE->IsEnabled())
        {
            wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Do you want continue?"), wxT("srs_ui_pro: The current action will be stopped!"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
            int res = dial->ShowModal();

            if (res == wxID_YES)
            {
                pthread_t thread1;

                dm_thread_arg *arg = new dm_thread_arg;
                    arg->form = this;
                    arg->action = "stop";
                    arg->log = box_dm_log;

                    dm_resumed = dm_paused = false;
                    dm_stoped = true;

                    but_RESUME->Disable();
                    but_PAUSE->Disable();
                    but_STOP->Disable();

                pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
            }
            else return;
        }
        //-------------------------------------

        pthread_t thread1;

        dm_thread_arg *arg = new dm_thread_arg;
            arg->form = this;
            arg->action = "deliver";
            std::string aux, aux2;
            aux2 = (choice_automatic_deliver_search->GetCurrentSelection() == -1)?"":"%"+toString(choice_automatic_deliver_search->GetStringSelection());
            aux = toString(choice_automatic_deliver->GetStringSelection()) + "%" + toString(choice_automatic_deliver_deliver_position->GetStringSelection())+aux2;
            arg->parameters = aux;
            arg->log = box_dm_log;

            std::string json_aux = (choice_automatic_deliver_search->GetCurrentSelection() == -1)?"":toString(choice_automatic_deliver_search->GetStringSelection());
            arg->json_parameters = "{\"tasks\":[{\"task\":\"deliver\",\"workspaces\":[\""+json_aux+"\"],\"deliver_destination\":{\"predefined_pose\":\""+toString(choice_automatic_deliver_deliver_position->GetStringSelection())+"\"},\"object\":{\"object_type\":\""+toString(choice_automatic_deliver->GetStringSelection())+"\"}}],\"initializer\":{\"device_type\":\"srs_ui_pro\",\"device_id\":\"srs_ui_pro_0001\"}}";

        but_RESUME->Disable();
        but_PAUSE->Enable();
        but_STOP->Enable();

        pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_DMAction, (void*)arg);
        writeInDMLog(toString(box_automatic_deliver_small->GetValue()), BLUE);
    }
}

void srs_ui_proFrame::Onbutton_spawn_objectsClick(wxCommandEvent& event)
{
    if (PM->WaitInteractionPrimitives() != -4)
        PM->ExecInteractionPrimitives();

    try
    {
        //Ri->IP_RemoveAllObjects();
        if (img_objects.size() > 0)
            for (unsigned int i=0; i<detected_objects.size(); i++)
                Ri->IP_RemoveObject(detected_objects[i].label.c_str());
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }

   try
    {
        for (unsigned int i=0; i<detected_objects.size(); i++)
            Ri->IP_AddObject(detected_objects[i].label.c_str(), detected_objects[i].pose, detected_objects[i].bounding_box_lwh);
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void srs_ui_proFrame::writeInLog(std::string text, wxColour colour)
{
    box_status_log->SetDefaultStyle(wxTextAttr(colour));
    box_status_log->AppendText(toWXString(text));
    box_status_log->SetDefaultStyle(wxTextAttr(BLACK));
}

void srs_ui_proFrame::writeInDMLog(std::string text, wxColour colour)
{
    box_dm_log->SetDefaultStyle(wxTextAttr(colour));
    box_dm_log->AppendText(toWXStringN(text));
    box_dm_log->SetDefaultStyle(wxTextAttr(BLACK));
}

void srs_ui_proFrame::writeInDMLog_(std::string text, wxTextCtrl *log, wxColour colour)
{
    while (event_dm_log){usleep(100000);};

    event_dm_log_str = text;
    event_dm_log_colour = colour;
    event_dm_log = true;

    while (event_dm_log){usleep(100000);};
}

void srs_ui_proFrame::spawnobjects(wxCommandEvent& event)
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, &srs_ui_proFrame::THREAD_SpawnObjects, (void*)this);
}

void srs_ui_proFrame::removeObjects(wxCommandEvent& event)
{
    try
    {
        std::vector<std::string> names = Ri->get_workspace_on_map();
        for (unsigned int i=0; i<names.size(); i++)
            Ri->IP_RemoveObject(names[i].c_str());
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void srs_ui_proFrame::removeDetectedObjects(wxCommandEvent& event)
{
    try
    {
        for (unsigned int i=0; i<detected_objects.size(); i++)
            Ri->IP_RemoveObject(detected_objects[i].label);
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void srs_ui_proFrame::spawnDetectedObjects(wxCommandEvent& event)
{
    try
    {
        //Ri->IP_RemoveAllObjects();
        if (detected_objects.size() > 0)
            for (unsigned int i=0; i<detected_objects.size(); i++)
                Ri->IP_RemoveObject(detected_objects[i].label);

        for (unsigned int i=0; i<detected_objects.size(); i++)
            Ri->IP_AddObject(detected_objects[i].label.c_str(), detected_objects[i].pose, detected_objects[i].bounding_box_lwh);
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void srs_ui_proFrame::Ongrid_requestsCellLeftDClick(wxGridEvent& event)
{
    int row = event.GetRow();
    std::string ros_uri = toString(grid_requests->GetCellValue(row,1));
    ROS_ERROR("Fake connection to %s", ros_uri.c_str());

    //TODO: Connect to this URI
    timer_URI.Start(1000, false);
}

void srs_ui_proFrame::Onchoice_automatic_moveSelect(wxCommandEvent& event)
{
    std::string status = "move";
    std::string current_selection = toString(choice_automatic_move->GetStringSelection());
    status += " " + current_selection;

    box_automatic_move_small->Clear();
    box_automatic_move_small->SetValue(toWXString(status));
}

void srs_ui_proFrame::Onchoice_automatic_getSelect(wxCommandEvent& event)
{
    std::string status = "get";
    std::string current_selection = toString(choice_automatic_get->GetStringSelection());
    std::string current_selection2 = toString(choice_automatic_get_search->GetStringSelection());

    status += " " + current_selection + " "+ current_selection2;

    box_automatic_get_small->Clear();
    box_automatic_get_small->SetValue(toWXString(status));
}

void srs_ui_proFrame::Onchoice_automatic_searchSelect(wxCommandEvent& event)
{
    std::string status = "search";
    std::string current_selection = toString(choice_automatic_search->GetStringSelection());
    std::string current_selection2 = toString(choice_automatic_search_search->GetStringSelection());

    status += " " + current_selection + " "+ current_selection2;

    box_automatic_search_small->Clear();
    box_automatic_search_small->SetValue(toWXString(status));
}

void srs_ui_proFrame::Onchoice_automatic_fetchSelect(wxCommandEvent& event)
{
    std::string status = "fetch";
    std::string current_selection = toString(choice_automatic_fetch->GetStringSelection());
    std::string current_selection2 = toString(choice_automatic_fetch_order->GetStringSelection());
    std::string current_selection3 = toString(choice_automatic_fetch_search->GetStringSelection());

    status += " " + current_selection + " " + current_selection2 + " " + current_selection3;

    box_automatic_fetch_small->Clear();
    box_automatic_fetch_small->SetValue(toWXString(status));
}

void srs_ui_proFrame::Onchoice_automatic_deliverSelect(wxCommandEvent& event)
{
    std::string status = "deliver";
    std::string current_selection = toString(choice_automatic_deliver->GetStringSelection());
    std::string current_selection2 = toString(choice_automatic_deliver_deliver_position->GetStringSelection());
    std::string current_selection3 = toString(choice_automatic_deliver_search->GetStringSelection());

    status += " " + current_selection + " " + current_selection2 + " " + current_selection3;

    box_automatic_deliver_small->Clear();
    box_automatic_deliver_small->SetValue(toWXString(status));
}

void srs_ui_proFrame::Onimg_update_ontrayClick(wxCommandEvent& event)
{
    try
    {
        scrollablewindow_ontray->Scroll(0,0);
        std::vector<std::string> oot = Ri->get_objects_on_tray();

        std::string aux = "(" + toString(oot.size()) + ")";
        label_ontray->SetLabel(toWXString(aux));

        for (unsigned int i=0; i<img_objects_on_tray.size(); i++)
            delete img_objects_on_tray[i];
        img_objects_on_tray.resize(0);

        int x=8, y=0;
        for (unsigned int i=0; i<oot.size(); i++)
        {
            if (i>0 && i%4==0)
            {
                x=8; y+=56;
            }

            wxImage objectIMG = Ri->getObjectIMG(oot[i]);
            objectIMG.Rescale(54, 54);
            wxBitmapButton *img = new wxBitmapButton(scrollablewindow_ontray, wxNewId(), wxBitmap(objectIMG), wxPoint(x,y), wxSize(54,54), wxBU_AUTODRAW, wxDefaultValidator, toWXString(oot[i]));
            img_objects_on_tray.push_back(img);
            x+=72;
        }
        scrollablewindow_ontray->SetScrollbars(0, 5, 0, (y+56+8)/5);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e)  {writeInLog();}
}

void srs_ui_proFrame::Onimg_update_rosinfoClick(wxCommandEvent& event)
{
    ros::V_string nodes;
    ros::master::getNodes(nodes);
    box_ROS_nodes->Clear();
    for (unsigned int i=0; i<nodes.size(); i++)
        box_ROS_nodes->AppendText(toWXStringN(nodes[i]));

    ros::master::V_TopicInfo topics;
    ros::master::getTopics(topics);
    box_ROS_topics->Clear();
    for (unsigned int i=0; i<topics.size(); i++)
        box_ROS_topics->AppendText(toWXStringN(topics[i].name));

    wxArrayString output;
    wxExecute (toWXString("rosservice list"), output);
     box_ROS_services->Clear();
    for (unsigned int i=0; i<output.GetCount(); i++)
        box_ROS_services->AppendText(toWXStringN(toString(output[i])));

    wxArrayString output2;
    wxExecute (toWXString("rosparam list"), output2);
    box_ROS_params->Clear();
    for (unsigned int i=0; i<output2.GetCount(); i++)
        box_ROS_params->AppendText(toWXStringN(toString(output2[i])));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////// THREADS ///////////////////////////////////////////////////////////////
void *srs_ui_proFrame::_THREAD_StartAssistedArm(void)
{
    try
    {
        Ri->startAssistedArm();
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void *srs_ui_proFrame::_THREAD_GenerateGrasps(void)
{
    try
    {
        int object_id = Ri->getObjectId(toString(choice_selected_grasp_object->GetStringSelection()));
        geometry_msgs::Pose target_pose = Ri->transformPose(detected_objects[choice_selected_grasp_object->GetSelection()].pose);

        generated_grasps = Ri->getGraspsFromPosition(object_id, target_pose);

        choice_grasp_conf->SetRange(0, generated_grasps.size()-1);

        if (generated_grasps.size()>0)
        {
            choice_grasp_conf->Enable();
            but_SimulateGrasp->Enable();
            but_GraspIt->Enable();
        }
        run_notification = true;
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void *srs_ui_proFrame::_THREAD_DMAction(std::string action, std::string parameters, std::string json_parameters, wxTextCtrl *log)
{
    try
    {
        dm_working = true;

        int res = Ri->decision_making_actions(action, parameters, json_parameters);

        if (res>=0)
        {

            if (action != "pause" && action != "resume" && action != "stop")
            {
                if (!dm_paused && !dm_stoped)
                {
                    if (res == 2)       writeInDMLog_("\tRESULT: preempted", log);
                    else if (res == 3)  writeInDMLog_("\tRESULT: succeeded", log, GREEN);
                    else if (res == 4)  writeInDMLog_("\tRESULT: failed", log);
                    else                writeInDMLog_("\tRESULT: unknown", log);

                    writeInDMLog_("Reached the end of the task.\n", log, BLUE);

                    but_RESUME->Disable();
                    but_PAUSE->Disable();
                    but_STOP->Disable();

                    dm_working = false;
                }
            }

            else
            {
                if (action == "pause")
                    writeInDMLog_("\tthe task has been paused", log, BLUE);
                else if (action == "resume")
                {
                    current_task_id = Ri->getDMCurrentTaskID();
                    writeInDMLog_("\tthe task has been resumed", log, BLUE);
                    dm_paused = false;
                }
                else
                {
                    writeInDMLog_("\tthe task has been stopped", log);
                    writeInDMLog_("Reached the end of the task.\n", log, BLUE);

                    but_RESUME->Disable();
                    but_PAUSE->Disable();
                    but_STOP->Disable();

                    dm_working = dm_paused = false;
                }

            }

        }
        else
            writeInDMLog_("[ERROR]: srs_decision_making fails.\n", log);


    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void *srs_ui_proFrame::_THREAD_GraspSimulator(void)
{
    if (PM->WaitGraspSimulator() == -4)
    {
        PM->ExitGraspSimulator();
        sleep(1);
    }

    PM->ExecGraspSimulator();
    try
    {
        int object_id = Ri->getObjectId(toString(choice_selected_grasp_object->GetStringSelection()));
        srs_msgs::FeasibleGrasp grasp_configuration = generated_grasps[choice_grasp_conf->GetValue()];
        geometry_msgs::Pose object_pose = Ri->transformPose(detected_objects[choice_selected_grasp_object->GetSelection()].pose);
        Ri->GraspSimulator(object_id, grasp_configuration, object_pose);
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }

    PM->ExitGraspSimulator();
}

void *srs_ui_proFrame::_THREAD_SpawnObjects(void)
{
    try
    {
        std::vector<std::string> names = Ri->get_workspace_on_map();
        std::vector<srs_msgs::SRSSpatialInfo> places = Ri->get_workspace_on_map_info();

        //Ri->IP_RemoveAllObjects();

        for (unsigned int i=0; i<places.size(); i++)
        {
            geometry_msgs::PoseStamped ps;
                ps.header.frame_id = "/map";
                ps.pose = places[i].pose;

            geometry_msgs::Point point;
                point.x = places[i].l;
                point.y = places[i].w;
                point.z = places[i].h;

            Ri->IP_AddObject(names[i], ps, point);
        }
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////// TIMER ////////////////////////////////////////////////////////////////
void srs_ui_proFrame::Ontimer_updatesTrigger(wxTimerEvent& event)
{
    UpdateRobotStatus();
    UpdateTactilSensorSimulator();
    UpdateIMGs();

    if (dm_working)
    {
        if (event_dm_log)
        {
            writeInDMLog(event_dm_log_str, event_dm_log_colour);
            event_dm_log = false;
        }


        //std::string status = Ri->getDMStatusText();
        std::string current_state = Ri->getDMCurrentState() + "\n";
        std::string current_state_aux = "\t"+current_state;

        /*
        if (Ri->DM_InterventionRequired() != 0)
        {
            wxMessageBox(wxT("User intervention is needed!\t"), wxT("srs_decision_making: User intervention is needed."), wxICON_INFORMATION);
        }
        */
        if (current_state.compare(last_state)!=0 && current_state.compare("the task has been paused\n")!=0 && current_state.compare("the task has been stopped\n")!=0)
            box_dm_log->AppendText(toWXString(current_state_aux));
        last_state = current_state;


        if (current_task_id.compare(Ri->getDMCurrentTaskID())!=0 && current_task_id.compare("None")!=0 && dm_resumed)
        {
            int res = Ri->getDMCurrentStatus();

            if (res == 2)       writeInDMLog("\tRESULT: preempted");
            else if (res == 3)  writeInDMLog("\tRESULT: succeeded",GREEN);
            else if (res == 4)  writeInDMLog("\tRESULT: failed");
            else                writeInDMLog("\tRESULT: unknown");

            writeInDMLog("Reached the end of the task.\n", BLUE);
            dm_working = dm_resumed = false;
        }
    }

    if (run_notification)
    {
        wxMessageBox(wxT("Grasp generation has finished!\t"), wxT("SRS_UI_PRO: Grasp generation."), wxICON_INFORMATION);
        run_notification = false;
    }

    if (DM_W_launched)
    {
            if(Ri->assistedFinished())
            {
                DM_W_launched = false;
                tab_automatic->Enable();
            }
    }
}

void srs_ui_proFrame::Ontimer_RequestsEventTrigger1(wxTimerEvent& event)
{
    try
    {
        std::vector<srs_ui_pro::RequestEventMSG> events = Ri->getRequestEvents();
        int current_num_events = events.size();

        if (current_num_events > num_events)
        {
            int new_events = current_num_events - num_events;
            //grid_request_events->DeleteRows(0, num_events, true);
            grid_requests->InsertRows(num_events, new_events, true);

            for (int i=num_events; i<current_num_events; i++)
            {
                grid_requests->SetCellValue(i,0, toWXString(events[i].id));
                grid_requests->SetCellValue(i,1, toWXString(events[i].uri));
                grid_requests->SetCellValue(i,2, toWXString(events[i].problem));
            }
            num_events = current_num_events;
            grid_requests->AutoSizeColumns(true);
        }
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void srs_ui_proFrame::Ontimer_ROSTrigger(wxTimerEvent& event)
{
    if (!ros::master::check())
    {
        timer_updates.Stop();
        timer_RequestsEvent.Stop();
        box_status_RobotURI->SetValue(wxString(_("Disconnected.")));

        box_status_log->SetDefaultStyle(wxTextAttr(RED));
        std::string aux;
        aux = "[ERROR] Disconnected from " + ros::master::getURI() + "\n";
        writeInLog(aux);

        timer_URI.Start(1000, false);
        timer_ROS.Stop();
        timer_choice.Stop();
        timer_dmServer.Stop();
        panel_actions_main->Disable();
        panel_options_main->Disable();
        panel_ontray_main->Disable();

        menu_rviz_run->Enable(false);
        menu_dashboard_run->Enable(false);
    }
}

void srs_ui_proFrame::Ontimer_choiceTrigger(wxTimerEvent& event)
{
    InitPredefinedPoses();
}

void srs_ui_proFrame::Ontimer_URITrigger(wxTimerEvent& event)
{
    if (ros::master::check())
    {
        box_status_log->SetDefaultStyle(wxTextAttr(BLUE));
        std::string aux;
        aux = "[INFO] Connected to " + ros::master::getURI() + "\n";
        writeInLog(aux, BLUE);

        Ri = new RosInterface();

        InitPredefinedPoses();
        LoadDBObjects();

        box_status_RobotURI->SetValue(toWXString(ros::master::getURI()));
        timer_URI.Stop();
        timer_ROS.Start(500, false);
        timer_dmServer.Start(500, false);
        timer_updates.Start(1000, false);
        panel_actions_main->Enable();
        panel_options_main->Enable();
        panel_ontray_main->Enable();

        menu_rviz_run->Enable(true);
        menu_dashboard_run->Enable(true);

        Ri->publish_status(0, "Inactive");

    }
}

void srs_ui_proFrame::Onskype_timerTrigger1(wxTimerEvent& event)
{
    if (SF->connected == true)
    {
        try
        {
            SF->showContactList(grid_skype_contactList);
        }
        catch(SkypeException &e)
        {
            SF->connected = false;
            writeInLog(e.getMessage());
            writeInLog("[SKYPE ERROR] Try to reinitialize skype.\n");
            timer_skype_contacts.Stop();
            option_skype_start->Enable(false);
        }
    }


    if (SF->incomingCallEvent())
    {
        long itemIndex = grid_skype_IncomingCalls->InsertItem(0, toWXString(SF->incomingCallMessageEvent()));
        //grid_skype_IncomingCalls->SetItem(itemIndex, 1, toWXString(SF->incomingCallMessageEvent()));
        //grid_skype_IncomingCalls->SetItem(itemIndex, 2, toWXString(SF->incomingCallMessageEvent()));
        wxMessageBox( wxT("New incoming call event!"), wxT("srs_ui_pro: SKYPE EVENT"), wxICON_INFORMATION);

        SF->allowNewIncomingCallEvent();
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////// SKYPE ////////////////////////////////////////////////////////////////
void srs_ui_proFrame::InitSkypeNotebooks()
{
    grid_skype_contactList->InsertColumn(0, wxT("Skype ID"),wxLIST_FORMAT_LEFT, 77);
    grid_skype_contactList->InsertColumn(1, wxT("Status"),wxLIST_FORMAT_LEFT, 77);
    grid_skype_contactList->InsertColumn(2, wxT("User Name"),wxLIST_FORMAT_LEFT, 154);
    grid_skype_IncomingCalls->InsertColumn(0, wxT("Call info"),wxLIST_FORMAT_LEFT, 308);
    //grid_skype_IncomingCalls->InsertColumn(1, wxT("Status"),wxLIST_FORMAT_LEFT, 82);
    //grid_skype_IncomingCalls->InsertColumn(2, wxT("Date"),wxLIST_FORMAT_LEFT, 160);
}

void srs_ui_proFrame::InitSkype()
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
            //PM->ExecSkypeRuntimeVideo();
            SF->initialize();
            SF->setEventOutput(grid_skype_IncomingCalls);//SF->setEventOutput(grid_skype_contactList);
            writeInLog("[INFO] You can now initialize Skype.\n", BLUE);
            option_skype_start->Enable();
        }
        else
            writeInLog("[SKYPE ERROR]: skype_runtime does't exist.\n");
    }
    catch(SkypeException &e) { writeInLog(e.getMessage()); }
    printf("----------------------------------------------------------------------------\n");
    fflush(stdout);
}

void srs_ui_proFrame::OnMenuSkypeStart(wxCommandEvent& event)
{
    connectToSkype();
}

void srs_ui_proFrame::connectToSkype()
{
    try
    {
        int res = SF->connect(grid_skype_contactList);
        if (res == 1) writeInLog("[SKYPE]: Connected!\n", BLUE);
        else if (offline)
        {
            writeInLog("Working offline!\n", RED);
            option_skype_start->Enable(false);
            option_skype_restart->Enable(false);
        }
        else
        {
            wxMessageBox( wxT("INVALID USER/PASS.\t\t"), wxT("SKYPE: The Skype user/pass is invalid."), wxICON_INFORMATION);
            Close();
        }
        timer_skype_contacts.Start(5000, false);
    }
    catch(SkypeException &e)
    {
        writeInLog(e.getMessage());
        wxMessageBox( wxT("INVALID USER/PASS.\t\t"), wxT("SKYPE: Unknown exception."), wxICON_INFORMATION);
        Close();
    }
}

void srs_ui_proFrame::showSkypeWindow()
{
    long index = -1;
    long aux = 0;
    for (;;)
    {
        index = grid_skype_contactList->GetNextItem(index, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

        if ( index == -1 )
            break;

        aux = index;
    }

    wxListItem li;
    li.SetId(aux);
    grid_skype_contactList->GetItem(li);

    std::string userName = toString(li.GetText());

    SkypeWindow *Frame = new SkypeWindow(0, SF, userName, box_status_log);
    Frame->Show(TRUE);
}

void srs_ui_proFrame::showSkypeWindow2()
{
    long index = -1;
    long aux = 0;
    for (;;)
    {
        index = grid_skype_contactList->GetNextItem(index, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

        if ( index == -1 )
            break;

        aux = index;
    }

    wxListItem li;
    li.SetId(aux);
    grid_skype_contactList->GetItem(li);

    std::string userName = toString(li.GetText());

    SkypeWindow2 *Frame = new SkypeWindow2(0, SF, userName);
    Frame->Show(TRUE);
}

void srs_ui_proFrame::showContextualMenu(wxListEvent& event)
{
    long ID_CM1 = wxNewId();
    long ID_CM2 = wxNewId();

    wxMenu menu(0);
    menu.Append(ID_CM1, wxString(_("User info")));
    Connect(ID_CM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::showSkypeWindow2);
    menu.Append(ID_CM2, wxString(_("Open conversation")));
    Connect(ID_CM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&srs_ui_proFrame::showSkypeWindow);

    wxPoint cursor_pos;
    cursor_pos = wxGetMousePosition();
    int mx = cursor_pos.x - this->GetScreenPosition().x;
    int my = cursor_pos.y - 75; //TOTALMENTE EMPÍRICO

    PopupMenu(&menu, mx, my);
}

void srs_ui_proFrame::acceptCall(wxListEvent& event)
{
    long index = -1;
    long aux = 0;
    for (;;)
    {
        index = grid_skype_IncomingCalls->GetNextItem(index, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

        if ( index == -1 )
            break;

        aux = index;
    }

    wxListItem li;
    li.SetId(aux);
    grid_skype_IncomingCalls->GetItem(li);
    std::string userName = toString(li.GetText());

    int aux_index = userName.find_first_of(" - ");
    userName = userName.substr(0,aux_index);

    try
    {
        SF->acceptCall(userName);
    }
    catch(SkypeException &e){ writeInLog(e.getMessage()); }

    SkypeWindow *Frame = new SkypeWindow(0, SF, userName, box_status_log);
    Frame->Show(TRUE);

}

void srs_ui_proFrame::ReinitializeSkype(wxCommandEvent& event)
{
    InitSkype();
    option_skype_start->Enable();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void srs_ui_proFrame::runDashboard(wxCommandEvent& event)
{
    if (PM->WaitDashboard() == -4)
        PM->ExitDashboard();
    else
        PM->ExecDashboard();
}

void srs_ui_proFrame::Onbut_head_frontClick(wxCommandEvent& event)
{
    try
    {
        float aux[] = {-3.14};
        std::vector<float> front(aux, aux+sizeof(aux)/sizeof(float));
        Ri->move("head", front);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e) {writeInLog(); }
}

void srs_ui_proFrame::Onbut_head_backClick(wxCommandEvent& event)
{
    try
    {
        float aux[] = {0.0};
        std::vector<float> back(aux, aux+sizeof(aux)/sizeof(float));
        Ri->move("head", back);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e) {writeInLog(); }
}

void srs_ui_proFrame::OnButton1Click(wxCommandEvent& event)
{
        try
    {
        float aux[] = {0.0, 0.0, 1.0472, 0.0, 1.0472, 0.0, 1.0472};

        std::vector<float> front(aux, aux+sizeof(aux)/sizeof(float));
        Ri->move("sdh", front);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e) {writeInLog(); }
}


void srs_ui_proFrame::OnButton2Click(wxCommandEvent& event)
{
    try
    {
        float aux[] = {0.0, -0.9854, 0.9472, -0.9854, 0.9472, -0.9854, 0.9472};

        std::vector<float> front(aux, aux+sizeof(aux)/sizeof(float));
        Ri->move("sdh", front);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e) {writeInLog(); }
}

void srs_ui_proFrame::Onbut_RvizTools_AssistedArm_LaunchClick(wxCommandEvent& event)
{
    if (PM->WaitIM_AssistedArmNavigation() == -4)
        PM->ExitIM_AssistedArmNavigation();
    else
        PM->ExecIM_AssistedArmNavigation();
}

void srs_ui_proFrame::Ontimer_dmServerTrigger(wxTimerEvent& event)
{
    //TODO: Esperar evento de feedback
    if (Ri->DM_ExcepcionalCase())
    {
        //wxMessageBox(wxT("Intervention!\t"), wxT("srs_decision_making: User intervention is needed."), wxICON_INFORMATION);
        wxMessageDialog *dial = new wxMessageDialog(NULL, wxT("Can you attend the call?"), wxT("srs_ui_pro: Your help is needed!"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
        int res = dial->ShowModal();

        if (res == wxID_YES)
        {
            Ri->publish_status(42, "I will try to solve your problem!");
            //DM_window *dm_w = new DM_window(this, Ri->getLastGoalAssistedMsg());
            DM_W = new DM_window(this, Ri->DM_ExcepcionalCaseInfo());
            DM_W->Show(TRUE);
            //TODO: Desactivar botones
            tab_automatic->Disable();
            DM_W_launched = true;
        }
        else
            Ri->publish_status(-42, "Sorry, I can't help you now. Try later...");
    }
}


//BUT Rviz displays
void srs_ui_proFrame::assistedArmNavigationOn(wxCommandEvent& event)
{
    //RvI->addDisplay("srs_assisted_arm_navigation_ui", "CButArmNavDisplay", "Assisted arm navigation", true);
}

void srs_ui_proFrame::assistedArmNavigationOff(wxCommandEvent& event)
{
    //RvI->removeDisplay("Assisted arm navigation");
}

void srs_ui_proFrame::assistedGraspOn(wxCommandEvent& event)
{
    //RvI->addDisplay("srs_assisted_grasping_ui", "CButGraspingDisplay", "Assisted grasping", true);
}

void srs_ui_proFrame::assistedGraspOff(wxCommandEvent& event)
{
    //RvI->removeDisplay("Assisted grasping");
}

void srs_ui_proFrame::baseTeleopOn(wxCommandEvent& event)
{
    //RvI->addDisplay("rviz", "rviz::InteractiveMarkerDisplay", "Robot teleop marker", true);
}

void srs_ui_proFrame::baseTeleopOff(wxCommandEvent& event)
{
    //RvI->removeDisplay("Robot teleop marker");
}

void srs_ui_proFrame::distanceLinuarOn(wxCommandEvent& event)
{
    //RvI->addDisplay("srs_ui_but", "CButDistanceLinearVisualizer", "Distance Linear Visualizer", true);
}

void srs_ui_proFrame::distanceLinuarOff(wxCommandEvent& event)
{
    //RvI->removeDisplay("Distance Linear Visualizer");
}

void srs_ui_proFrame::distanceCircularOn(wxCommandEvent& event)
{
    //RvI->addDisplay("srs_ui_but", "CButDistanceCircularIndicator", "Distance Circular Indicator", true);
}

void srs_ui_proFrame::distanceCircularOff(wxCommandEvent& event)
{
    //RvI->removeDisplay("Distance Circular Indicator");
}

void srs_ui_proFrame::stretchIndicatorOn(wxCommandEvent& event)
{
    //RvI->addDisplay("srs_ui_but", "CButCOBStretchIndicator", "Stretch Indicator", true);
}

void srs_ui_proFrame::stretchIndicatorOff(wxCommandEvent& event)
{
    //RvI->removeDisplay("Stretch Indicator");
}

void srs_ui_proFrame::objectManagerOn(wxCommandEvent& event)
{
    //RvI->addDisplay("srs_ui_but", "CButObjectManager", "Object Manager", true);
}

void srs_ui_proFrame::objectManagerOff(wxCommandEvent& event)
{
    //RvI->removeDisplay("Object Manager");
}

void srs_ui_proFrame::dataFusionOn(wxCommandEvent& event)
{
    //RvI->addDisplay("srs_ui_but", "CButCamDisplay", "CButCamDisplayName", true);
}

void srs_ui_proFrame::dataFusionOff(wxCommandEvent& event)
{
    //RvI->removeDisplay("CButCamDisplayName");
}

void srs_ui_proFrame::OnButton1Click2(wxCommandEvent& event)
{
    //RvI->loadConfig("BASIC");
}

void srs_ui_proFrame::OnButton2Click1(wxCommandEvent& event)
{
    //RvI->loadConfig("NAVIGATION");
}

void srs_ui_proFrame::OnButton3Click(wxCommandEvent& event)
{
    //RvI->loadConfig("MANIPULATION");
}

void srs_ui_proFrame::Onbut_navigation_dashboardClick1(wxCommandEvent& event)
{
    if (PM->WaitDashboard() == -4)
        PM->ExitDashboard();
    else
        PM->ExecDashboard();
}

void srs_ui_proFrame::OnButton17Click(wxCommandEvent& event)
{
    /*
    try
    {
        float aux[] = {-0.1, 0.0, -0.15};
        std::vector<float> front(aux, aux+sizeof(aux)/sizeof(float));
        Ri->move("torso", front);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e) {writeInLog(); }
    */
    std::vector<float> aux;
    aux.push_back(-0.1);
    aux.push_back(0.0);
    aux.push_back(-0.15);
     //= {-0.1, 0.0, -0.15};
    try
    {
        Ri->to_server_actions(aux);
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void srs_ui_proFrame::OnButton18Click(wxCommandEvent& event)
{
    /*
    try
    {
        float aux[] = {0.1, 0.0, 0.15};
        std::vector<float> back(aux, aux+sizeof(aux)/sizeof(float));
        Ri->move("torso", back);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e) {writeInLog(); }
    */

    std::vector<float> aux;
    aux.push_back(0.1);
    aux.push_back(0.0);
    aux.push_back(0.15);
     //= {-0.1, 0.0, -0.15};
    try
    {
        Ri->to_server_actions(aux);
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void srs_ui_proFrame::OnButton19Click(wxCommandEvent& event)
{
    /*
    try
    {
        float aux[] = {0};
        std::vector<float> up(aux, aux+sizeof(aux)/sizeof(float));
        Ri->move("tray", up);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e) {writeInLog(); }
    */
    try
    {
        Ri->tt_server_actions(0.0);
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void srs_ui_proFrame::OnButton20Click(wxCommandEvent& event)
{
    /*
    try
    {
        float aux[] = {-3.14};
        std::vector<float> down(aux, aux+sizeof(aux)/sizeof(float));
        Ri->move("tray", down);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e) {writeInLog(); }
    */
    try
    {
        Ri->tt_server_actions(-3.14);
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void srs_ui_proFrame::OnButton22Click(wxCommandEvent& event)
{
    try
    {
        float aux[] = {0,0,0,0,0,0,0};
        std::vector<float> home(aux, aux+sizeof(aux)/sizeof(float));
        Ri->move("arm", home);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e) {writeInLog(); }
}

void srs_ui_proFrame::OnButton12Click1(wxCommandEvent& event)
{
    try
    {
        float aux[] = {-1.1572567240035734, -1.9104664691761568, -2.5334780195730255, -1.7853311980377056, -0.07279873939024305, 0.9176793492327278, -1.8876618005378798};
        std::vector<float> folded(aux, aux+sizeof(aux)/sizeof(float));
        Ri->move("arm", folded);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e) {writeInLog(); }

}

void srs_ui_proFrame::OnButton23Click(wxCommandEvent& event)
{
    try
    {
        float aux[] = {-2.14,0,0};
        std::vector<float> new_kit(aux, aux+sizeof(aux)/sizeof(float));
        Ri->move("base", new_kit);
    }
    catch(ServiceUnavailable &e) {writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {writeInLog(e.getMessage()); }
    catch(std::exception &e) {writeInLog(); }
}

void srs_ui_proFrame::OnButton4Click(wxCommandEvent& event)
{
    try
    {
        Ri->ui_but_server_actions(1);
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void srs_ui_proFrame::OnButton5Click(wxCommandEvent& event)
{
    try
    {
        Ri->ui_but_server_actions(2);
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}

void srs_ui_proFrame::OnButton12Click2(wxCommandEvent& event)
{
    try
    {
        Ri->at_server_actions();
    }
    catch(ServiceUnavailable &e) { writeInLog(e.getMessage()); }
    catch(ServiceCallFailed &e) {  writeInLog(e.getMessage()); }
    catch(std::exception &e) { writeInLog(); }
}
