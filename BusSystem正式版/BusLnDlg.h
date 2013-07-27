#if !defined(AFX_BUSLNDLG1_H__089A1F49_C97B_4613_8983_6C7FB26DA41D__INCLUDED_)
#define AFX_BUSLNDLG1_H__089A1F49_C97B_4613_8983_6C7FB26DA41D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BusLnDlg1.h : header file
//
#include "ADO.h"
/////////////////////////////////////////////////////////////////////////////
// CBusLnDlg dialog

class CBusLnDlg : public CDialog
{
// Construction
public:
	bool m_direction;
	CBusLnDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBusLnDlg)
	enum { IDD = IDD_BUSLN_DIALOG };
	CListBox	m_CtrlBusLnList;
	CListBox	m_CtrlBusLnInfoList;
	CComboBox	m_CtrlBusLnCmb;
	CButton	m_GoButton;     //公交线路去方向
	CButton	m_ComeButton;   //公交线路回方向
	CTreeCtrl	m_BusLnTree; //公交种类显示（城际，市区……）
	CButton	m_BusLnButton;   // 公交线路查询响应按钮
	//}}AFX_DATA
	ADO ado;
	CString s;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBusLnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBusLnDlg)
	afx_msg void OnClickBuslnTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeBuslnCombo();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBuslnButton();
	afx_msg void OnGoButton();
	afx_msg void OnComeButton();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangedBuslnTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetfocusBuslnCombo();
	afx_msg void OnEditchangeBuslnCombo();
	afx_msg void OnSelchangeBuslnList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUSLNDLG1_H__089A1F49_C97B_4613_8983_6C7FB26DA41D__INCLUDED_)
