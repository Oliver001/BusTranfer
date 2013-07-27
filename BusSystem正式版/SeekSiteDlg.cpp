// SeekSiteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BusSystem.h"
#include "SeekSiteDlg.h"
#include "ADO.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSeekSiteDlg dialog


//DEL CSeekSiteDlg::CSeekSiteDlg(CWnd* pParent /*=NULL*/)
//DEL 	: CDialog(CSeekSiteDlg::IDD, pParent)
//DEL {
//DEL 	//{{AFX_DATA_INIT(CSeekSiteDlg)
//DEL 	//}}AFX_DATA_INIT
//DEL }


void CSeekSiteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSeekSiteDlg)
	DDX_Control(pDX, IDC_SKST_TREE, m_CtrlSkstTree);
	DDX_Control(pDX, IDC_SKST_COMBO, m_CtrlSkstCmb);
	DDX_Control(pDX, IDC_SKST_BUTTON, m_SkstButton);
	//}}AFX_DATA_MAP
	s = "Provider=SQLOLEDB.1;Password=a;Persist Security Info=True;User ID=sa;Initial Catalog=XIAN;Data Source=ASH_BOY";
	ado.InitData(s.AllocSysString());
    ado2.InitData(s.AllocSysString());
	m_CtrlSkstTree.SetTextColor(RGB(0,255,255));
	m_CtrlSkstTree.SetBkColor(RGB(51,102,153));
	/*ado.InitData(s.AllocSysString());*/
}


BEGIN_MESSAGE_MAP(CSeekSiteDlg, CDialog)
//{{AFX_MSG_MAP(CSeekSiteDlg)
ON_CBN_EDITCHANGE(IDC_SKST_COMBO, OnEditchangeSkstCombo)
ON_BN_CLICKED(IDC_SKST_BUTTON, OnSkstButton)
ON_NOTIFY(NM_CLICK, IDC_SKST_TREE, OnClickSkstTree)
	ON_CBN_SETFOCUS(IDC_SKST_COMBO, OnSetfocusSkstCombo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSeekSiteDlg message handlers

void CSeekSiteDlg::OnEditchangeSkstCombo() 
{
	CString s;
	m_CtrlSkstCmb.GetWindowText(s);
	m_CtrlSkstCmb.ResetContent();
	m_CtrlSkstCmb.SetWindowText(s);

	m_CtrlSkstCmb.SetEditSel(s.GetLength(),s.GetLength());
	try
	{
		ado.Execute(_bstr_t(fuzzyMatchingBusStation+s+"'"));
		int i=0;
		while (!ado.pRecordset->adoEOF)
		{
			s=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan");
			m_CtrlSkstCmb.InsertString(i,s);
			
			++i;
			ado.pRecordset->MoveNext();
		}
		if (i==0)
		{
			MessageBox("нч╢ку╬╣Ц");
			m_CtrlSkstCmb.ResetContent();
			OnSetfocusSkstCombo();
		}
	}

	catch (_com_error e)
	{
		_bstr_t bstrSource(e.Source()); 
		_bstr_t bstrDescription(e.Description());  
		AfxMessageBox(bstrSource + bstrDescription);  
		
	}
	m_CtrlSkstCmb.ShowDropDown();
}

void CSeekSiteDlg::OnSkstButton() 
{
	
	// TODO: Add your control notification handler code here
	CString str ,str1;
	int i = 0;
	HTREEITEM hItem;
	m_CtrlSkstCmb.GetWindowText(str);
	if (str=="")
	{
		return;
	}
	
	m_CtrlSkstTree.DeleteAllItems();
	try  
	{
		ado.Execute(_bstr_t(nearBus  + str +"'"));		
		while (!ado.pRecordset->adoEOF)
		{
			str1=str=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("busw");
			str+='\n';
			str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("shijian");
			hItem=m_CtrlSkstTree.InsertItem(str,TVI_ROOT);
             str1+="','0'";
			ado2.Execute(_bstr_t(queryBusWayInfo+str1));
			while (!ado2.pRecordset->adoEOF)
			{
				str=(LPCTSTR)(_bstr_t)ado2.pRecordset->GetCollect("zhan");
				m_CtrlSkstTree.InsertItem(_bstr_t(str),hItem);
				ado2.pRecordset->MoveNext();
			}

			ado.pRecordset->MoveNext();			
		}
	}
	catch (_com_error e)
	{
		_bstr_t bstrSource(e.Source()); 
		_bstr_t bstrDescription(e.Description());  
		AfxMessageBox(bstrSource + bstrDescription);  
	}
}


void CSeekSiteDlg::OnClickSkstTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

BOOL CSeekSiteDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_CtrlSkstTree.SetTextColor(RGB(0,255,255));
	m_CtrlSkstTree.SetBkColor(RGB(51,102,153));
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

LRESULT CSeekSiteDlg::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
// 	if (wParam==VK_TAB)
// 	{
// 		MessageBox("asasasas");
// 	}
	return CDialog::DefWindowProc(message, wParam, lParam);
}

void CSeekSiteDlg::OnSetfocusSkstCombo() 
{
	// TODO: Add your control notification handler code here
	try
	{
		CString s;
		m_CtrlSkstCmb.GetWindowText(s);
		//	MessageBox(s);
		
		m_CtrlSkstCmb.ResetContent();
		m_CtrlSkstCmb.SetWindowText(s);
		ado.Execute(_bstr_t(fuzzyMatchingBusStation+s+"'"));
		int i=0;
		while (!ado.pRecordset->adoEOF)
		{
			s=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan");
			m_CtrlSkstCmb.InsertString(i,s);
			
			++i;
			ado.pRecordset->MoveNext();
		}
	}
	catch (_com_error e)
	{
		_bstr_t bstrSource(e.Source()); 
		_bstr_t bstrDescription(e.Description());  
		AfxMessageBox(bstrSource + bstrDescription);  
	}
	m_CtrlSkstCmb.ShowDropDown(TRUE);
}
