; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBusLnDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BusSystem.h"

ClassCount=6
Class1=CBusSystemApp
Class2=CBusSystemDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_BUSLN_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_CHANGELN_DIALOG
Resource5=IDD_BUSSYSTEM_DIALOG
Class4=CSeekSiteDlg
Class5=CChangeLnDlg
Class6=CBusLnDlg
Resource6=IDD_SEEKSITE_DIALOG

[CLS:CBusSystemApp]
Type=0
HeaderFile=BusSystem.h
ImplementationFile=BusSystem.cpp
Filter=N
LastObject=IDC_BUSLN_INFO_LIST

[CLS:CBusSystemDlg]
Type=0
HeaderFile=BusSystemDlg.h
ImplementationFile=BusSystemDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_TAB1

[CLS:CAboutDlg]
Type=0
HeaderFile=BusSystemDlg.h
ImplementationFile=BusSystemDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BUSSYSTEM_DIALOG]
Type=1
Class=CBusSystemDlg
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342177280

[DLG:IDD_BUSLN_DIALOG]
Type=1
Class=CBusLnDlg
ControlCount=7
Control1=IDC_BUSLN_BUTTON,button,1342242816
Control2=IDC_BUSLN_TREE,SysTreeView32,1342242819
Control3=IDC_BUSLN_COMBO,combobox,1344340034
Control4=IDC_GO_BUTTON,button,1342242816
Control5=IDC_COME_BUTTON,button,1342242816
Control6=IDC_BUSLN_LIST,listbox,1352728835
Control7=IDC_BUSLN_INFO_LIST,listbox,1353777408

[DLG:IDD_CHANGELN_DIALOG]
Type=1
Class=CChangeLnDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_CHLNSTART_COMBO,combobox,1344340226
Control3=IDC_CHLNEND_COMBO,combobox,1344340226
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CHLN_QUERY_BTN,button,1342242816
Control6=IDC_SWITCH_BUTTON,button,1342242816
Control7=IDC_CHLN_TREE,SysTreeView32,1342242819

[DLG:IDD_SEEKSITE_DIALOG]
Type=1
Class=CSeekSiteDlg
ControlCount=3
Control1=IDC_SKST_BUTTON,button,1342242816
Control2=IDC_SKST_COMBO,combobox,1344340290
Control3=IDC_SKST_TREE,SysTreeView32,1342242819

[CLS:CChangeLnDlg]
Type=0
HeaderFile=ChangeLnDlg.h
ImplementationFile=ChangeLnDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_CHLNSTART_COMBO

[CLS:CSeekSiteDlg]
Type=0
HeaderFile=SeekSiteDlg.h
ImplementationFile=SeekSiteDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSeekSiteDlg

[CLS:CBusLnDlg]
Type=0
HeaderFile=buslndlg.h
ImplementationFile=buslndlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUSLN_COMBO

