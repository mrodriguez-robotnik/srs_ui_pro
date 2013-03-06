#ifndef DM_WINDOW_H
#define DM_WINDOW_H

//(*Headers(DM_window)
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include <ros/ros.h>
#include <srs_ui_pro/srs_ui_proEcho.h>
#include "RosInterface.h"
class DM_window: public wxFrame
{
	public:

		DM_window(wxWindow* parent, std::string msg, wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DM_window();

		//(*Declarations(DM_window)
		wxTextCtrl* box_feedback;
		wxButton* but_suc;
		wxTextCtrl* box_message;
		wxButton* but_fail;
		wxButton* but_feedback;
		wxPanel* user_intervention_window;
		wxStaticText* label_title;
		wxStaticLine* line_separator;
		wxStaticText* label_feedback;
		//*)

	protected:

		//(*Identifiers(DM_window)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_STATICLINE1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(DM_window)
		void sendFeedback(wxCommandEvent& event);
		void sendSucceeded(wxCommandEvent& event);
		void sendFailed(wxCommandEvent& event);
        std::string getMsgInformation(std::string msg);
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()

        ros::NodeHandle n;
        ros::Publisher srs_ui_pro_pub;

};

#endif
