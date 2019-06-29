/***************************************************************
 * Name:      Calculator2App.cpp
 * Purpose:   Code for Application Class
 * Author:    Bikash Sah (sahbikash999@gmail.com)
 * Created:   2019-06-27
 * Copyright: Bikash Sah (aakashsky.com)
 * License:
 **************************************************************/

#include "Calculator2App.h"

//(*AppHeaders
#include "Calculator2Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Calculator2App);

bool Calculator2App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Calculator2Frame* Frame = new Calculator2Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
