// BusSystemDlg.h : header file
//

#if !defined(AFX_BUSSYSTEMDLG_H__6A925506_F70C_4C1B_84A3_D3E8B9BD348C__INCLUDED_)
#define AFX_BUSSYSTEMDLG_H__6A925506_F70C_4C1B_84A3_D3E8B9BD348C__INCLUDED_

#include "BusLnDlg.h"	// Added by ClassView
#include "ChangeLnDlg.h"	// Added by ClassView
#include "SeekSiteDlg.h"	// Added by ClassView
#include "BitmapTabCtrl.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBusSystemDlg dialog

class CBusSystemDlg : public CDialog
{
// Construction
public:
	CSeekSiteDlg m_seeksite;
	CChangeLnDlg m_changeln;
	CBusLnDlg m_busln;
	CBusSystemDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBusSystemDlg)
	enum { IDD = IDD_BUSSYSTEM_DIALOG };
	CBitmapTabCtrl	m_tabctrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBusSystemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBusSystemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUSSYSTEMDLG_H__6A925506_F70C_4C1B_84A3_D3E8B9BD348C__INCLUDED_)
