/***************************************************************
 * Name:      srs_ui_proApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Roman Navarro (rnavarro@robotnik.es)
 * Created:   2012-03-13
 * Copyright: Roman Navarro ()
 * License:
 **************************************************************/

#include "srs_ui_proApp.h"

//(*AppHeaders
#include "srs_ui_proMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(srs_ui_proApp);

bool srs_ui_proApp::OnInit()
{
    wxShell(wxString("reset", wxConvUTF8));

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	srs_ui_proFrame* Frame = new srs_ui_proFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
