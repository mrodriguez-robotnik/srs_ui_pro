#ifndef OBJECTINFO_H
#define OBJECTINFO_H

//(*Headers(ObjectInfo)
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "RosInterface.h"

class ObjectInfo: public wxFrame
{
	public:

        RosInterface *Ri;
		ObjectInfo(wxWindow* parent, RosInterface *Ri, cob_object_detection_msgs::Detection object_info, wxWindowID id=wxID_ANY);
		virtual ~ObjectInfo();
        void objectInfo(cob_object_detection_msgs::Detection object_info);

		//(*Declarations(ObjectInfo)
		wxTextCtrl* box_oY;
		wxStaticText* StaticText22;
		wxTextCtrl* box_object_name;
		wxTextCtrl* box_oZ;
		wxStaticText* StaticText21;
		wxStaticText* StaticText13;
		wxStaticText* StaticText14;
		wxStaticText* StaticText15;
		wxTextCtrl* box_oW;
		wxStaticText* StaticText17;
		wxTextCtrl* box_tpX;
		wxTextCtrl* box_toY;
		wxTextCtrl* box_tpZ;
		wxTextCtrl* box_oX;
		wxTextCtrl* box_reference_link;
		wxStaticText* StaticText20;
		wxStaticText* StaticText18;
		wxStaticText* StaticText1;
		wxStaticText* StaticText10;
		wxStaticText* StaticText16;
		wxTextCtrl* box_pY;
		wxStaticText* StaticText3;
		wxStaticText* StaticText23;
		wxStaticText* StaticText8;
		wxStaticText* StaticText12;
		wxTextCtrl* box_pX;
		wxTextCtrl* box_tpY;
		wxStaticText* StaticText7;
		wxTextCtrl* box_toX;
		wxTextCtrl* box_frame_id;
		wxStaticText* StaticText4;
		wxTextCtrl* box_toW;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxTextCtrl* box_pZ;
		wxStaticText* StaticText19;
		wxTextCtrl* box_toZ;
		wxStaticText* StaticText9;
		wxStaticText* StaticText11;
		//*)

	protected:

		//(*Identifiers(ObjectInfo)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT15;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT16;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL11;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT17;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT20;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT18;
		static const long ID_STATICTEXT10;
		static const long ID_STATICTEXT21;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT19;
		static const long ID_STATICTEXT11;
		static const long ID_STATICTEXT22;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL13;
		static const long ID_TEXTCTRL7;
		static const long ID_TEXTCTRL12;
		static const long ID_TEXTCTRL6;
		static const long ID_TEXTCTRL15;
		static const long ID_TEXTCTRL17;
		static const long ID_TEXTCTRL18;
		static const long ID_TEXTCTRL19;
		static const long ID_TEXTCTRL8;
		static const long ID_TEXTCTRL9;
		static const long ID_TEXTCTRL10;
		static const long ID_TEXTCTRL5;
		static const long ID_TEXTCTRL14;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT23;
		static const long ID_STATICTEXT12;
		static const long ID_STATICTEXT13;
		static const long ID_STATICTEXT14;
		//*)

	private:

		//(*Handlers(ObjectInfo)
		void OnRightDClick(wxMouseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
