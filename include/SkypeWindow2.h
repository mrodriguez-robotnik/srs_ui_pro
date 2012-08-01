#ifndef SKYPEWINDOW2_H
#define SKYPEWINDOW2_H

//(*Headers(SkypeWindow2)
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbmp.h>
//*)

#include "SkypeFunctions.h"

class SkypeWindow2: public wxFrame
{
	public:

        SkypeFunctions *SF;
        std::string userName;

		SkypeWindow2(wxWindow* parent, SkypeFunctions *SF, std::string userName, wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);

		virtual ~SkypeWindow2();

		//(*Declarations(SkypeWindow2)
		wxTextCtrl* TextCtrl3;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxPanel* Panel2;
		wxStaticText* StaticText3;
		wxStaticText* label_email;
		wxStaticBitmap* img_avatar;
		wxTextCtrl* TextCtrl1;
		wxStaticText* StaticText2;
		wxStaticText* label_name;
		wxStaticText* label_location;
		wxTextCtrl* TextCtrl2;
		//*)

	protected:

		//(*Identifiers(SkypeWindow2)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_PANEL2;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT6;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(SkypeWindow2)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
