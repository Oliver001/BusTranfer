#if !defined(AFX_CHANGELNDLG_H__0764063E_C044_4BC0_8AC7_E7BB6C1A1644__INCLUDED_)
#define AFX_CHANGELNDLG_H__0764063E_C044_4BC0_8AC7_E7BB6C1A1644__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChangeLnDlg.h : header file
//
#include "ADO.h"


/////////////////////////////////////////////////////////////////////////////
// CChangeLnDlg dialog

class CChangeLnDlg : public CDialog
{
// Construction
public:
	bool m_bReverse;
	CChangeLnDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChangeLnDlg)
	enum { IDD = IDD_CHANGELN_DIALOG };
	CButton	m_CtrlChLnQueryBtn;
	CTreeCtrl	m_CtrlChLnTree;
	CComboBox	m_CtrlChLnStartCmb;
	CComboBox	m_CtrlChLnEndCmb;
	//}}AFX_DATA
    ADO ado;
    CString s;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeLnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChangeLnDlg)
	afx_msg void OnChlnQueryBtn();
	virtual BOOL OnInitDialog();
	afx_msg void OnSwitchButton();
	afx_msg void OnEditchangeChlnstartCombo();
	afx_msg void OnSetfocusChlnstartCombo();
	afx_msg void OnEditchangeChlnendCombo();
	afx_msg void OnSetfocusChlnendCombo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGELNDLG_H__0764063E_C044_4BC0_8AC7_E7BB6C1A1644__INCLUDED_)
