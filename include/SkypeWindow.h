#ifndef SKYPEWINDOW_H
#define SKYPEWINDOW_H

//(*Headers(SkypeWindow)
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbmp.h>
//*)

#include "SkypeFunctions.h"

class SkypeWindow: public wxFrame
{
	public:

        SkypeFunctions *SF;
        std::string userName;
        wxTextCtrl *log_box;

		SkypeWindow(wxWindow* parent, SkypeFunctions *SF, std::string userName,  wxTextCtrl *log_box, wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);

		virtual ~SkypeWindow();

		//(*Declarations(SkypeWindow)
		wxBitmapButton* img_micro;
		wxPanel* Panel1;
		wxButton* button_chat;
		wxPanel* panel_mute;
		wxTextCtrl* chat_send;
		wxBitmapButton* img_sound;
		wxBitmapButton* img_call;
		wxTextCtrl* chat_log;
		wxPanel* Panel2;
		wxStaticBitmap* img_avatar;
		wxPanel* panel_call;
		wxStaticText* label_name;
		wxStaticText* label_location;
		//*)

        void muteMicro();
        void muteSound();
        void setUserInfo();

	protected:

		//(*Identifiers(SkypeWindow)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_STATICBITMAP1;
		static const long ID_BITMAPBUTTON1;
		static const long ID_PANEL3;
		static const long ID_BITMAPBUTTON3;
		static const long ID_PANEL4;
		static const long ID_BITMAPBUTTON2;
		static const long ID_PANEL2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(SkypeWindow)
		void callButton(wxCommandEvent& event);
		void muteButton(wxCommandEvent& event);
		void Onbutton_chatClick(wxCommandEvent& event);
		void Onchat_sendTextEnter(wxCommandEvent& event);
		void soundButton(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
