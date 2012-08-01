#include "ObjectInfo.h"

//(*InternalHeaders(ObjectInfo)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(ObjectInfo)
const long ObjectInfo::ID_STATICTEXT1 = wxNewId();
const long ObjectInfo::ID_STATICTEXT2 = wxNewId();
const long ObjectInfo::ID_STATICTEXT3 = wxNewId();
const long ObjectInfo::ID_STATICTEXT15 = wxNewId();
const long ObjectInfo::ID_STATICTEXT4 = wxNewId();
const long ObjectInfo::ID_STATICTEXT16 = wxNewId();
const long ObjectInfo::ID_STATICTEXT5 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL1 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL11 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL4 = wxNewId();
const long ObjectInfo::ID_STATICTEXT17 = wxNewId();
const long ObjectInfo::ID_STATICTEXT9 = wxNewId();
const long ObjectInfo::ID_STATICTEXT20 = wxNewId();
const long ObjectInfo::ID_STATICTEXT6 = wxNewId();
const long ObjectInfo::ID_STATICTEXT18 = wxNewId();
const long ObjectInfo::ID_STATICTEXT10 = wxNewId();
const long ObjectInfo::ID_STATICTEXT21 = wxNewId();
const long ObjectInfo::ID_STATICTEXT7 = wxNewId();
const long ObjectInfo::ID_STATICTEXT19 = wxNewId();
const long ObjectInfo::ID_STATICTEXT11 = wxNewId();
const long ObjectInfo::ID_STATICTEXT22 = wxNewId();
const long ObjectInfo::ID_STATICTEXT8 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL13 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL7 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL12 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL6 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL15 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL17 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL18 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL19 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL8 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL9 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL10 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL5 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL14 = wxNewId();
const long ObjectInfo::ID_TEXTCTRL2 = wxNewId();
const long ObjectInfo::ID_STATICTEXT23 = wxNewId();
const long ObjectInfo::ID_STATICTEXT12 = wxNewId();
const long ObjectInfo::ID_STATICTEXT13 = wxNewId();
const long ObjectInfo::ID_STATICTEXT14 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ObjectInfo,wxFrame)
	//(*EventTable(ObjectInfo)
	//*)
END_EVENT_TABLE()

ObjectInfo::ObjectInfo(wxWindow* parent, RosInterface *Ri, cob_object_detection_msgs::Detection object_info, wxWindowID id)
{
    Ri = this->Ri;

	//(*Initialize(ObjectInfo)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(416,542));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Object name:"), wxPoint(16,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Detected pose:"), wxPoint(16,56), wxSize(136,17), 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("frame_id:"), wxPoint(32,80), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText15 = new wxStaticText(this, ID_STATICTEXT15, _("position:"), wxPoint(32,112), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("position:"), wxPoint(32,352), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText16 = new wxStaticText(this, ID_STATICTEXT16, _("orientation:"), wxPoint(32,204), wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("orientation:"), wxPoint(32,442), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	box_object_name = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(120,12), wxSize(280,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	box_reference_link = new wxTextCtrl(this, ID_TEXTCTRL11, _("/base_link"), wxPoint(192,328), wxSize(208,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
	box_frame_id = new wxTextCtrl(this, ID_TEXTCTRL4, _("Text"), wxPoint(120,76), wxSize(280,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticText17 = new wxStaticText(this, ID_STATICTEXT17, _("X"), wxPoint(159,136), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("X"), wxPoint(159,376), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	StaticText20 = new wxStaticText(this, ID_STATICTEXT20, _("X"), wxPoint(147,228), wxDefaultSize, 0, _T("ID_STATICTEXT20"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("X"), wxPoint(147,466), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText18 = new wxStaticText(this, ID_STATICTEXT18, _("Y"), wxPoint(255,136), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Y"), wxPoint(255,376), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	StaticText21 = new wxStaticText(this, ID_STATICTEXT21, _("Y"), wxPoint(219,228), wxDefaultSize, 0, _T("ID_STATICTEXT21"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Y"), wxPoint(219,466), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StaticText19 = new wxStaticText(this, ID_STATICTEXT19, _("Z"), wxPoint(351,136), wxDefaultSize, 0, _T("ID_STATICTEXT19"));
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Z"), wxPoint(351,376), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	StaticText22 = new wxStaticText(this, ID_STATICTEXT22, _("Z"), wxPoint(292,228), wxDefaultSize, 0, _T("ID_STATICTEXT22"));
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Z"), wxPoint(292,466), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	box_pY = new wxTextCtrl(this, ID_TEXTCTRL13, _("Text"), wxPoint(216,152), wxSize(88,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
	box_tpY = new wxTextCtrl(this, ID_TEXTCTRL7, _("Text"), wxPoint(216,392), wxSize(88,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	box_pX = new wxTextCtrl(this, ID_TEXTCTRL12, _("Text"), wxPoint(120,152), wxSize(88,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
	box_tpX = new wxTextCtrl(this, ID_TEXTCTRL6, _("Text"), wxPoint(120,392), wxSize(88,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	box_oX = new wxTextCtrl(this, ID_TEXTCTRL15, _("Text"), wxPoint(120,244), wxSize(64,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
	box_toX = new wxTextCtrl(this, ID_TEXTCTRL17, _("Text"), wxPoint(120,482), wxSize(64,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
	box_toY = new wxTextCtrl(this, ID_TEXTCTRL18, _("Text"), wxPoint(192,482), wxSize(64,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
	box_toZ = new wxTextCtrl(this, ID_TEXTCTRL19, _("Text"), wxPoint(264,482), wxSize(64,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
	box_toW = new wxTextCtrl(this, ID_TEXTCTRL8, _("Text"), wxPoint(336,482), wxSize(64,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	box_oY = new wxTextCtrl(this, ID_TEXTCTRL9, _("Text"), wxPoint(192,244), wxSize(64,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	box_oW = new wxTextCtrl(this, ID_TEXTCTRL10, _("Text"), wxPoint(336,244), wxSize(64,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	box_oZ = new wxTextCtrl(this, ID_TEXTCTRL5, _("Text"), wxPoint(264,244), wxSize(64,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	box_pZ = new wxTextCtrl(this, ID_TEXTCTRL14, _("Text"), wxPoint(312,152), wxSize(88,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
	box_tpZ = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxPoint(312,392), wxSize(88,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticText23 = new wxStaticText(this, ID_STATICTEXT23, _("W"), wxPoint(361,228), wxDefaultSize, 0, _T("ID_STATICTEXT23"));
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("W"), wxPoint(361,466), wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Transformed pose:"), wxPoint(16,296), wxSize(144,17), 0, _T("ID_STATICTEXT13"));
	StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("Reference link:"), wxPoint(32,320), wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	//*)

    objectInfo(object_info);

}

ObjectInfo::~ObjectInfo()
{
	//(*Destroy(ObjectInfo)
	//*)
}

void ObjectInfo::objectInfo(cob_object_detection_msgs::Detection object_info)
{
    box_object_name->SetValue(wxString(object_info.label.c_str(), wxConvUTF8));
    box_frame_id->SetValue(wxString(object_info.pose.header.frame_id.c_str(), wxConvUTF8));

	box_pX->SetValue(wxString::Format(wxT("%f"), object_info.pose.pose.position.x));
	box_pY->SetValue(wxString::Format(wxT("%f"), object_info.pose.pose.position.y));
	box_pZ->SetValue(wxString::Format(wxT("%f"), object_info.pose.pose.position.z));

    box_oX->SetValue(wxString::Format(wxT("%f"), object_info.pose.pose.orientation.x));
	box_oY->SetValue(wxString::Format(wxT("%f"), object_info.pose.pose.orientation.y));
	box_oZ->SetValue(wxString::Format(wxT("%f"), object_info.pose.pose.orientation.z));
	box_oW->SetValue(wxString::Format(wxT("%f"), object_info.pose.pose.orientation.w));


    geometry_msgs::Pose p = Ri->transformPose(object_info.pose);

    box_tpX->SetValue(wxString::Format(wxT("%f"), p.position.x));
	box_tpY->SetValue(wxString::Format(wxT("%f"), p.position.y));
	box_tpZ->SetValue(wxString::Format(wxT("%f"), p.position.z));

    box_toX->SetValue(wxString::Format(wxT("%f"), p.orientation.x));
	box_toY->SetValue(wxString::Format(wxT("%f"), p.orientation.y));
	box_toZ->SetValue(wxString::Format(wxT("%f"), p.orientation.z));
	box_toW->SetValue(wxString::Format(wxT("%f"), p.orientation.w));
}
