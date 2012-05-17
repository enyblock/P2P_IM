; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMESSAGEBOX
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Enyblock_IM.h"

ClassCount=6
Class1=CEnyblock_IMApp
Class2=CEnyblock_IMDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ENYBLOCK_IM_DIALOG
Resource2=IDR_MAINFRAME
Class4=loging
Resource3=IDD_Register
Class5=Register
Resource4=IDD_ABOUTBOX
Class6=CMESSAGEBOX
Resource5=IDD_MESSAGE_BOX

[CLS:CEnyblock_IMApp]
Type=0
HeaderFile=Enyblock_IM.h
ImplementationFile=Enyblock_IM.cpp
Filter=N

[CLS:CEnyblock_IMDlg]
Type=0
HeaderFile=Enyblock_IMDlg.h
ImplementationFile=Enyblock_IMDlg.cpp
Filter=D
LastObject=CEnyblock_IMDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Enyblock_IMDlg.h
ImplementationFile=Enyblock_IMDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,button,1342177287

[DLG:IDD_ENYBLOCK_IM_DIALOG]
Type=1
Class=CEnyblock_IMDlg
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631584
Control5=IDC_BUTTON1,button,1342242816
Control6=IDC_BUTTON2,button,1342242816
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,button,1342177287
Control9=IDC_PROGRESS1,msctls_progress32,1350565888
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352

[CLS:loging]
Type=0
HeaderFile=loging.h
ImplementationFile=loging.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_PROGRESS1
VirtualFilter=dWC

[DLG:IDD_Register]
Type=1
Class=Register
ControlCount=12
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,button,1342177287
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT3,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT4,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,button,1342177287
Control11=IDC_BUTTON4,button,1342242816
Control12=IDC_BUTTON5,button,1342242816

[CLS:Register]
Type=0
HeaderFile=Register.h
ImplementationFile=Register.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON4
VirtualFilter=dWC

[DLG:IDD_MESSAGE_BOX]
Type=1
Class=CMESSAGEBOX
ControlCount=8
Control1=IDC_EDIT1,edit,1352728708
Control2=IDC_EDIT3,edit,1350631552
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_BUTTON2,button,1342242816
Control6=IDC_BUTTON3,button,1342242816
Control7=IDC_BUTTON6,button,1342242816
Control8=IDC_BUTTON4,button,1342242816

[CLS:CMESSAGEBOX]
Type=0
HeaderFile=MESSAGEBOX.h
ImplementationFile=MESSAGEBOX.cpp
BaseClass=CDialog
Filter=D
LastObject=CMESSAGEBOX

