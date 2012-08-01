#include "SkypeWindow2.h"

//(*InternalHeaders(SkypeWindow2)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//(*IdInit(SkypeWindow2)
const long SkypeWindow2::ID_STATICBITMAP1 = wxNewId();
const long SkypeWindow2::ID_STATICTEXT1 = wxNewId();
const long SkypeWindow2::ID_STATICTEXT2 = wxNewId();
const long SkypeWindow2::ID_STATICTEXT3 = wxNewId();
const long SkypeWindow2::ID_PANEL2 = wxNewId();
const long SkypeWindow2::ID_TEXTCTRL2 = wxNewId();
const long SkypeWindow2::ID_TEXTCTRL3 = wxNewId();
const long SkypeWindow2::ID_TEXTCTRL1 = wxNewId();
const long SkypeWindow2::ID_STATICTEXT5 = wxNewId();
const long SkypeWindow2::ID_STATICTEXT4 = wxNewId();
const long SkypeWindow2::ID_STATICTEXT6 = wxNewId();
const long SkypeWindow2::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SkypeWindow2,wxFrame)
	//(*EventTable(SkypeWindow2)
	//*)
END_EVENT_TABLE()

SkypeWindow2::SkypeWindow2(wxWindow* parent, SkypeFunctions *sf, std::string un, wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SkypeWindow2)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(400,542));
	Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(8,8), wxSize(384,96), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	img_avatar = new wxStaticBitmap(Panel2, ID_STATICBITMAP1, wxBitmap(wxImage(_T("./img/avatar_prueba.jpg")).Rescale(wxSize(89,89).GetWidth(),wxSize(89,89).GetHeight())), wxPoint(0,0), wxSize(89,89), 0, _T("ID_STATICBITMAP1"));
	label_name = new wxStaticText(Panel2, ID_STATICTEXT1, _("Name"), wxPoint(104,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	label_location = new wxStaticText(Panel2, ID_STATICTEXT2, _("City, Country"), wxPoint(104,40), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	label_email = new wxStaticText(Panel2, ID_STATICTEXT3, _("email"), wxPoint(104,72), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(8,112), wxSize(384,424), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(0,16), wxSize(384,112), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxPoint(0,160), wxSize(384,112), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(0,304), wxSize(384,112), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Medication:"), wxPoint(0,0), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont StaticText2Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Intern notes:"), wxPoint(0,288), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	wxFont StaticText1Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Important notification:"), wxPoint(0,144), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont StaticText3Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	//*)


    SF = sf;
    userName = un;
}

SkypeWindow2::~SkypeWindow2()
{
	//(*Destroy(SkypeWindow2)
	//*)
}

