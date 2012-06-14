; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEnyblock_IMDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Enyblock_IM.h"

ClassCount=6
Class1=CEnyblock_IMApp
Class2=CEnyblock_IMDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_ENYBLOCK_IM_DIALOG
Resource2=IDR_MAINFRAME
Class4=loging
Resource3=IDD_MESSAGE_BOX
Class5=Register
Resource4=IDD_ABOUTBOX
Class6=CMESSAGEBOX
Resource5=IDD_Register
Resource6=IDD_ENYBLOCK_IM_CONTACT

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
LastObject=IDC_TREE_CONTACT
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
ControlCount=12
Control1=IDC_STATIC_USERNAME,static,1342308352
Control2=IDC_STATIC_PASSWORD,static,1342308352
Control3=IDC_EDIT_USERNAME,edit,1350762624
Control4=IDC_EDIT_PASSWORD,edit,1350762656
Control5=IDC_BUTTON1,button,1342242816
Control6=IDC_BUTTON2,button,1342242817
Control7=IDC_STATIC_LOG_ON,button,1342308359
Control8=IDC_STATIC_INFORMATINO,button,1342308359
Control9=IDC_PROGRESS1,msctls_progress32,1350565888
Control10=IDC_STATIC_AUTHOR,static,1342308352
Control11=IDC_STATIC_DATE,static,1342308352
Control12=IDC_TREE_CONTACT,SysTreeView32,1350635527

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
Control1=IDC_EDIT_USERNAME_REGISTER,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,button,1342177287
Control4=IDC_EDIT_PASSWORD_REGISTER,edit,1350631584
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_PASSWORD_C_REGISTER,edit,1350631584
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_EMAIL_REGISTER,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,button,1342177287
Control11=IDC_BUTTON4,button,1342242817
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
ControlCount=9
Control1=IDC_EDIT_RECV,edit,1352728580
Control2=IDC_EDIT_SEND,edit,1350631552
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_BUTTON_SEND,button,1342242817
Control6=IDC_BUTTON_CANCLE,button,1342242816
Control7=IDC_BUTTON6,button,1342242816
Control8=IDC_BUTTON4,button,1342242816
Control9=IDC_IPADDRESS1,SysIPAddress32,1073807360

[CLS:CMESSAGEBOX]
Type=0
HeaderFile=MESSAGEBOX.h
ImplementationFile=MESSAGEBOX.cpp
BaseClass=CDialog
Filter=D
LastObject=CMESSAGEBOX
VirtualFilter=dWC

[DLG:IDD_ENYBLOCK_IM_CONTACT]
Type=1
Class=?
ControlCount=1
Control1=IDC_TREE1,SysTreeView32,1350631424

