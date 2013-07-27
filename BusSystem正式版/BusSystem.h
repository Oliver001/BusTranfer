// BusSystem.h : main header file for the BUSSYSTEM application
//

#if !defined(AFX_BUSSYSTEM_H__A0F16FBD_6494_4C94_A3CA_C0D87DC8BCE3__INCLUDED_)
#define AFX_BUSSYSTEM_H__A0F16FBD_6494_4C94_A3CA_C0D87DC8BCE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBusSystemApp:
// See BusSystem.cpp for the implementation of this class
//

class CBusSystemApp : public CWinApp
{
public:
	CBusSystemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBusSystemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBusSystemApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
// 
// extern const CString BusKinds;
// extern const CString BusCollection;
// extern const CString nearBus;
// extern const CString queryByBusName;
// extern const CString fuzzyMatchingBusWay;
// extern const CString fuzzyMatchingBusStation;
/////////////////////////////////////////////////////////////////////////////
extern CBusSystemApp theApp;
const CString BusKinds="exec BusKinds";
const CString BusCollection="exec BusCollection '";
const CString nearBus="exec nearBus '";
const CString queryByBusName="exec queryByBusName '";
const CString fuzzyMatchingBusWay="exec fuzzyMatchingBusWay '";
const CString fuzzyMatchingBusStation="exec fuzzyMatchingBusStation '";
const CString queryBusWayInfo="exec queryBusWayInfo '";
const CString PreTransfer="exec PreTransfer '";
const CString transfer="exec transfer '";
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUSSYSTEM_H__A0F16FBD_6494_4C94_A3CA_C0D87DC8BCE3__INCLUDED_)
