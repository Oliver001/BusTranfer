#if !defined(AFX_SEEKSITEDLG_H__2800B47D_7897_4EEC_BA5B_0E11014FD53F__INCLUDED_)
#define AFX_SEEKSITEDLG_H__2800B47D_7897_4EEC_BA5B_0E11014FD53F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SeekSiteDlg.h : header file
//
#include "ADO.h"

/////////////////////////////////////////////////////////////////////////////
// CSeekSiteDlg dialog

class CSeekSiteDlg : public CDialog
{
// Construction
public:

// Dialog Data
	//{{AFX_DATA(CSeekSiteDlg)
	enum { IDD = IDD_SEEKSITE_DIALOG };
	CTreeCtrl	m_CtrlSkstTree;
	CComboBox	m_CtrlSkstCmb;
	CButton	m_SkstButton;
	afx_msg void OnSkstButton();
	//}}AFX_DATA
    ADO ado;
	ADO ado2;
    CString s;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeekSiteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSeekSiteDlg)
	afx_msg void OnEditchangeSkstCombo();
	afx_msg void OnClickSkstTree(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnSetfocusSkstCombo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEEKSITEDLG_H__2800B47D_7897_4EEC_BA5B_0E11014FD53F__INCLUDED_)
