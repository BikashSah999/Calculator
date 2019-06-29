/***************************************************************
 * Name:      CalculatorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Bikash Sah (sahbikash999@gmail.com)
 * Created:   2019-06-27
 * Copyright: Bikash Sah (aakashsky.com)
 * License:
 **************************************************************/

#include "CalculatorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(CalculatorFrame)
#include <wx/intl.h>
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

//(*IdInit(CalculatorFrame)
const long CalculatorFrame::ID_TEXTCTRL1 = wxNewId();
const long CalculatorFrame::ID_BUTTON1 = wxNewId();
const long CalculatorFrame::ID_BUTTON2 = wxNewId();
const long CalculatorFrame::ID_BUTTON3 = wxNewId();
const long CalculatorFrame::ID_BUTTON4 = wxNewId();
const long CalculatorFrame::ID_BUTTON5 = wxNewId();
const long CalculatorFrame::ID_BUTTON6 = wxNewId();
const long CalculatorFrame::ID_BUTTON7 = wxNewId();
const long CalculatorFrame::ID_BUTTON8 = wxNewId();
const long CalculatorFrame::ID_BUTTON9 = wxNewId();
const long CalculatorFrame::ID_BUTTON11 = wxNewId();
const long CalculatorFrame::ID_BUTTON10 = wxNewId();
const long CalculatorFrame::ID_TEXTCTRL2 = wxNewId();
const long CalculatorFrame::ID_TEXTCTRL3 = wxNewId();
const long CalculatorFrame::ID_BUTTON13 = wxNewId();
const long CalculatorFrame::ID_BUTTON12 = wxNewId();
const long CalculatorFrame::ID_BUTTON14 = wxNewId();
const long CalculatorFrame::ID_BUTTON15 = wxNewId();
const long CalculatorFrame::idMenuQuit = wxNewId();
const long CalculatorFrame::idMenuAbout = wxNewId();
const long CalculatorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CalculatorFrame,wxFrame)
    //(*EventTable(CalculatorFrame)
    //*)
END_EVENT_TABLE()

CalculatorFrame::CalculatorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(CalculatorFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(310,215));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("0"), wxPoint(0,0), wxSize(96,56), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("1"), wxPoint(0,56), wxSize(48,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("2"), wxPoint(48,56), wxSize(48,40), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button3 = new wxButton(this, ID_BUTTON3, _("3"), wxPoint(96,56), wxSize(48,40), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button4 = new wxButton(this, ID_BUTTON4, _("4"), wxPoint(0,96), wxSize(48,40), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button5 = new wxButton(this, ID_BUTTON5, _("5"), wxPoint(48,96), wxSize(48,40), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button6 = new wxButton(this, ID_BUTTON6, _("6"), wxPoint(96,96), wxSize(48,40), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    Button7 = new wxButton(this, ID_BUTTON7, _("7"), wxPoint(0,136), wxSize(48,40), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    Button8 = new wxButton(this, ID_BUTTON8, _("8"), wxPoint(48,136), wxSize(48,40), 0, wxDefaultValidator, _T("ID_BUTTON8"));
    Button9 = new wxButton(this, ID_BUTTON9, _("9"), wxPoint(96,136), wxSize(48,40), 0, wxDefaultValidator, _T("ID_BUTTON9"));
    Button11 = new wxButton(this, ID_BUTTON11, _("0"), wxPoint(0,176), wxSize(48,40), 0, wxDefaultValidator, _T("ID_BUTTON11"));
    Button10 = new wxButton(this, ID_BUTTON10, _("+ (ADD)"), wxPoint(144,56), wxSize(168,40), 0, wxDefaultValidator, _T("ID_BUTTON10"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("0"), wxPoint(96,0), wxSize(104,56), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("0"), wxPoint(200,0), wxSize(112,56), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    Button13 = new wxButton(this, ID_BUTTON13, _("CLR"), wxPoint(48,176), wxSize(96,40), 0, wxDefaultValidator, _T("ID_BUTTON13"));
    Button12 = new wxButton(this, ID_BUTTON12, _("- (SUB)"), wxPoint(144,96), wxSize(168,40), 0, wxDefaultValidator, _T("ID_BUTTON12"));
    Button14 = new wxButton(this, ID_BUTTON14, _("* (MUL)"), wxPoint(144,136), wxSize(168,40), 0, wxDefaultValidator, _T("ID_BUTTON14"));
    Button15 = new wxButton(this, ID_BUTTON15, _("/ (DIV)"), wxPoint(144,176), wxSize(168,40), 0, wxDefaultValidator, _T("ID_BUTTON15"));
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

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CalculatorFrame::OnTextCtrl1Text);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton2Click1);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton5Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton6Click);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton7Click);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton8Click);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton9Click);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton11Click);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton10Click);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CalculatorFrame::OnTextCtrl2Text);
    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton13Click);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton12Click);
    Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton14Click);
    Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CalculatorFrame::OnButton15Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CalculatorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CalculatorFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&CalculatorFrame::OnClose1);
    //*)
}

CalculatorFrame::~CalculatorFrame()
{
    //(*Destroy(CalculatorFrame)
    //*)
}

void CalculatorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CalculatorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void CalculatorFrame::OnButton1Click(wxCommandEvent& event)
{
    double x=1;
    wxString res=wxT("");
    res << (x);
    if(TextCtrl1->GetValue() .ToDouble ((&x))){
    if(x!=0){
    TextCtrl2->SetValue(res);
    }
    else{
       TextCtrl1->SetValue(res);
    }
    }

}

void CalculatorFrame::OnClose(wxCloseEvent& event)
{
}

void CalculatorFrame::OnButton2Click(wxCommandEvent& event)
{
    double x=2;
    wxString res=wxT("");
    res << (x);
    TextCtrl1->SetValue(res);
}

void CalculatorFrame::OnButton2Click1(wxCommandEvent& event)
{
    double x=2;
    wxString res=wxT("");
    res << (x);
    if(TextCtrl1->GetValue() .ToDouble ((&x))){
    if(x!=0){
    TextCtrl2->SetValue(res);
    }
    else{
       TextCtrl1->SetValue(res);
    }
    }
}

void CalculatorFrame::OnClose1(wxCloseEvent& event)
{
}

void CalculatorFrame::OnButton10Click(wxCommandEvent& event)
{
    double x=0,y=0;
    wxString res=wxT("");
    if(TextCtrl1->GetValue() .ToDouble ((&x)) and TextCtrl2->GetValue() .ToDouble ((&y))){
       res<<(x+y);
       TextCtrl3->SetValue(res);
    }
}

void CalculatorFrame::OnTextCtrl2Text(wxCommandEvent& event)
{
}

void CalculatorFrame::OnButton3Click(wxCommandEvent& event)
{
    double x=3;
    wxString res=wxT("");
    res << (x);
    if(TextCtrl1->GetValue() .ToDouble ((&x))){
    if(x!=0){
    TextCtrl2->SetValue(res);
    }
    else{
       TextCtrl1->SetValue(res);
    }
    }
}

void CalculatorFrame::OnButton4Click(wxCommandEvent& event)
{
    double x=4;
    wxString res=wxT("");
    res << (x);
    if(TextCtrl1->GetValue() .ToDouble ((&x))){
    if(x!=0){
    TextCtrl2->SetValue(res);
    }
    else{
       TextCtrl1->SetValue(res);
    }
    }
}

void CalculatorFrame::OnButton5Click(wxCommandEvent& event)
{
    double x=5;
    wxString res=wxT("");
    res << (x);
    if(TextCtrl1->GetValue() .ToDouble ((&x))){
    if(x!=0){
    TextCtrl2->SetValue(res);
    }
    else{
       TextCtrl1->SetValue(res);
    }
    }
}

void CalculatorFrame::OnButton6Click(wxCommandEvent& event)
{
    double x=6;
    wxString res=wxT("");
    res << (x);
    if(TextCtrl1->GetValue() .ToDouble ((&x))){
    if(x!=0){
    TextCtrl2->SetValue(res);
    }
    else{
       TextCtrl1->SetValue(res);
    }
    }
}

void CalculatorFrame::OnButton7Click(wxCommandEvent& event)
{
    double x=7;
    wxString res=wxT("");
    res << (x);
    if(TextCtrl1->GetValue() .ToDouble ((&x))){
    if(x!=0){
    TextCtrl2->SetValue(res);
    }
    else{
       TextCtrl1->SetValue(res);
    }
    }
}

void CalculatorFrame::OnButton8Click(wxCommandEvent& event)
{
    double x=8;
    wxString res=wxT("");
    res << (x);
    if(TextCtrl1->GetValue() .ToDouble ((&x))){
    if(x!=0){
    TextCtrl2->SetValue(res);
    }
    else{
       TextCtrl1->SetValue(res);
    }
    }
}

void CalculatorFrame::OnButton9Click(wxCommandEvent& event)
{
    double x=9;
    wxString res=wxT("");
    res << (x);
    if(TextCtrl1->GetValue() .ToDouble ((&x))){
    if(x!=0){
    TextCtrl2->SetValue(res);
    }
    else{
       TextCtrl1->SetValue(res);
    }
    }
}

void CalculatorFrame::OnButton11Click(wxCommandEvent& event)
{
    double x=0;
    wxString res=wxT("");
    res << (x);
    if(TextCtrl1->GetValue() .ToDouble ((&x))){
    if(x!=0){
    TextCtrl2->SetValue(res);
    }
    else{
       TextCtrl1->SetValue(res);
    }
    }
}

void CalculatorFrame::OnButton13Click(wxCommandEvent& event)
{
    double x=NULL, y=0;
    wxString res=wxT("");
    res << (x);
    TextCtrl1->SetValue(res);
    TextCtrl2->SetValue(res);
    TextCtrl3->SetValue(res);

}

void CalculatorFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void CalculatorFrame::OnButton12Click(wxCommandEvent& event)
{
    double x=0,y=0;
    wxString res=wxT("");
    if(TextCtrl1->GetValue() .ToDouble ((&x)) and TextCtrl2->GetValue() .ToDouble ((&y))){
       res<<(x-y);
       TextCtrl3->SetValue(res);
    }
}

void CalculatorFrame::OnButton14Click(wxCommandEvent& event)
{
    double x=0,y=0;
    wxString res=wxT("");
    if(TextCtrl1->GetValue() .ToDouble ((&x)) and TextCtrl2->GetValue() .ToDouble ((&y))){
       res<<(x*y);
       TextCtrl3->SetValue(res);
    }
}

void CalculatorFrame::OnButton15Click(wxCommandEvent& event)
{
    double x=0,y=0;
    wxString res=wxT("");
    if(TextCtrl1->GetValue() .ToDouble ((&x)) and TextCtrl2->GetValue() .ToDouble ((&y))){
       res<<(x/y);
       TextCtrl3->SetValue(res);
    }
}
