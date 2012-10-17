#ifndef LOGGINSCREEN_H
#define LOGGINSCREEN_H

//(*Headers(LogginScreen)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbmp.h>
//*)

#include "ProcessManager.h"
#include "RosInterface.h"
#include "ObjectInfo.h"
#include "SkypeFunctions.h"
#include "SkypeWindow.h"
#include "SkypeWindow2.h"
#include "srs_ui_proMain.h"

class LogginScreen: public wxFrame
{
	public:

		LogginScreen(wxWindow* parent,wxWindowID id=-1);
		virtual ~LogginScreen();

		//(*Declarations(LogginScreen)
		wxStaticText* label_user;
		wxStaticBitmap* img_background;
		wxTextCtrl* box_user;
		wxStaticText* label_pass;
		wxTextCtrl* box_pass;
		wxButton* but_init;
		//*)

        SkypeFunctions *SF;
        ProcessManager *PM;

	protected:

		//(*Identifiers(LogginScreen)
		static const long ID_STATICBITMAP1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(LogginScreen)
		void Onbut_initClick(wxCommandEvent& event);
		//*)

        void InitSkype();
		DECLARE_EVENT_TABLE()
};

#endif
