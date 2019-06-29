/***************************************************************
 * Name:      Calculator2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Bikash Sah (sahbikash999@gmail.com)
 * Created:   2019-06-27
 * Copyright: Bikash Sah (aakashsky.com)
 * License:
 **************************************************************/

#include "Calculator2Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Calculator2Frame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

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

//(*IdInit(Calculator2Frame)
const long Calculator2Frame::ID_STATICTEXT1 = wxNewId();
const long Calculator2Frame::ID_STATICTEXT2 = wxNewId();
const long Calculator2Frame::ID_TEXTCTRL1 = wxNewId();
const long Calculator2Frame::ID_TEXTCTRL2 = wxNewId();
const long Calculator2Frame::ID_STATICTEXT3 = wxNewId();
const long Calculator2Frame::ID_STATICTEXT4 = wxNewId();
const long Calculator2Frame::ID_STATICTEXT5 = wxNewId();
const long Calculator2Frame::ID_STATICTEXT6 = wxNewId();
const long Calculator2Frame::ID_TEXTCTRL3 = wxNewId();
const long Calculator2Frame::ID_TEXTCTRL4 = wxNewId();
const long Calculator2Frame::ID_TEXTCTRL5 = wxNewId();
const long Calculator2Frame::ID_TEXTCTRL6 = wxNewId();
const long Calculator2Frame::ID_BUTTON1 = wxNewId();
const long Calculator2Frame::idMenuQuit = wxNewId();
const long Calculator2Frame::idMenuAbout = wxNewId();
const long Calculator2Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Calculator2Frame,wxFrame)
    //(*EventTable(Calculator2Frame)
    //*)
END_EVENT_TABLE()

Calculator2Frame::Calculator2Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Calculator2Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(300,238));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("X ="), wxPoint(32,16), wxSize(56,16), wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
    StaticText1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Y ="), wxPoint(32,40), wxSize(56,16), wxALIGN_CENTRE|wxNO_BORDER, _T("ID_STATICTEXT2"));
    StaticText2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    StaticText2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(152,16), wxSize(100,16), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(152,40), wxSize(100,16), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Sum"), wxPoint(32,80), wxSize(56,16), wxALIGN_CENTRE, _T("ID_STATICTEXT3"));
    StaticText3->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    StaticText3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Difference"), wxPoint(32,112), wxSize(56,16), wxALIGN_CENTRE, _T("ID_STATICTEXT4"));
    StaticText4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Multiply"), wxPoint(32,144), wxSize(56,16), wxALIGN_CENTRE, _T("ID_STATICTEXT5"));
    StaticText5->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Divide"), wxPoint(32,176), wxSize(56,16), wxALIGN_CENTRE, _T("ID_STATICTEXT6"));
    StaticText6->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(152,80), wxSize(100,16), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(152,112), wxSize(100,16), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(152,144), wxSize(100,16), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(152,176), wxSize(100,16), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Calculate"), wxPoint(96,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator2Frame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Calculator2Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Calculator2Frame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Calculator2Frame::OnClose);
    //*)
}

Calculator2Frame::~Calculator2Frame()
{
    //(*Destroy(Calculator2Frame)
    //*)
}

void Calculator2Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Calculator2Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Calculator2Frame::OnClose(wxCloseEvent& event)
{
}

void Calculator2Frame::OnButton1Click(wxCommandEvent& event)
{
   double x=0, y=0;
   wxString res=wxT("");
   wxString res1=wxT("");
   wxString res2=wxT("");
   wxString res3=wxT("");
   if(TextCtrl1->GetValue() .ToDouble ((&x)) and TextCtrl2->GetValue() .ToDouble ((&y))){
    res<<(x+y);
    res1<<(x-y);
    res2<<(x*y);
    res3<<(x/y);
    TextCtrl3->SetValue(res);
    TextCtrl4->SetValue(res1);
    TextCtrl5->SetValue(res2);
    TextCtrl6->SetValue(res3);
   }
}
