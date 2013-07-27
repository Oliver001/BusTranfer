// ChangeLnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BusSystem.h"
#include "ChangeLnDlg.h"
#include "ADO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangeLnDlg dialog


CChangeLnDlg::CChangeLnDlg(CWnd* pParent /*=NULL*/)
: CDialog(CChangeLnDlg::IDD, pParent)
,m_bReverse(false)
{
	//{{AFX_DATA_INIT(CChangeLnDlg)
	//}}AFX_DATA_INIT
}


void CChangeLnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeLnDlg)
	DDX_Control(pDX, IDC_CHLN_QUERY_BTN, m_CtrlChLnQueryBtn);
	DDX_Control(pDX, IDC_CHLN_TREE, m_CtrlChLnTree);
	DDX_Control(pDX, IDC_CHLNSTART_COMBO, m_CtrlChLnStartCmb);
	DDX_Control(pDX, IDC_CHLNEND_COMBO, m_CtrlChLnEndCmb);
	//}}AFX_DATA_MAP
	
	s = "Provider=SQLOLEDB.1;Password=a;Persist Security Info=True;User ID=sa;Initial Catalog=XIAN;Data Source=ASH_BOY";
	ado.InitData(s.AllocSysString());
}


BEGIN_MESSAGE_MAP(CChangeLnDlg, CDialog)
//{{AFX_MSG_MAP(CChangeLnDlg)
ON_BN_CLICKED(IDC_CHLN_QUERY_BTN, OnChlnQueryBtn)
	ON_BN_CLICKED(IDC_SWITCH_BUTTON, OnSwitchButton)
	ON_CBN_EDITCHANGE(IDC_CHLNSTART_COMBO, OnEditchangeChlnstartCombo)
	ON_CBN_SETFOCUS(IDC_CHLNSTART_COMBO, OnSetfocusChlnstartCombo)
	ON_CBN_EDITCHANGE(IDC_CHLNEND_COMBO, OnEditchangeChlnendCombo)
	ON_CBN_SETFOCUS(IDC_CHLNEND_COMBO, OnSetfocusChlnendCombo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CChangeLnDlg message handlers

void CChangeLnDlg::OnChlnQueryBtn() 
{
	// TODO: Add your control notification handler code here
	CString strStart,strEnd,str;
	int i=0;
	int count = 0;
	m_CtrlChLnStartCmb.GetWindowText(strStart);
	m_CtrlChLnEndCmb.GetWindowText(strEnd);
	strEnd.TrimLeft();
	strEnd.TrimRight();
	strStart.TrimLeft();
	strStart.TrimRight();
	if (strStart =="" ||strEnd =="")
	{
		AfxMessageBox("输入站点不能为空!");
		return;
	}
	if (strStart==strEnd)
	{
		AfxMessageBox("起点站和终点站不能为同一站点。");
		return;
	}
	if (strStart != strEnd)
	{
		m_CtrlChLnTree.DeleteAllItems();
		try
		{	
			if (m_bReverse)
			{
				ado.Execute(_bstr_t("declare @count int;exec Pretransfer '"+strEnd+"','"+strStart+"',@count output;select @count count;"));
			}
			else
			{
				ado.Execute(_bstr_t("declare @count int;exec Pretransfer '"+strStart+"','"+strEnd+"',@count output;select @count count;"));
			}
			
			int count = ado.pRecordset->GetCollect("count").intVal;
			if (count==0)
			{
				MessageBox("系统提示：不能到达。请联系管理员。");
				return;
			}
			else
			{
				if (m_bReverse)
				{
					ado.Execute(_bstr_t(transfer+strEnd+"','"+strStart+"';"));
				}
				else
				{
					ado.Execute(_bstr_t(transfer+strStart+"','"+strEnd+"';"));
				}
				if (count == 1)
				{
					while (!ado.pRecordset->adoEOF)
					{
						
						str=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("busway");		
						str+="(直达)";			
						m_CtrlChLnTree.InsertItem(str,TVI_ROOT);			
						ado.pRecordset->MoveNext();
						i++;
					}
				}
				else if (count == 2)
				{
					while (!ado.pRecordset->adoEOF)
					{
						str=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan1");
						str+="→";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("busw1");	
						str+="(";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("total1");	
						str+="站)";
					    str+="→";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan2");
						str+="→";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("busw2");
						str+="(";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("total2");	
						str+="站)";
						str+="→";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan4");
						m_CtrlChLnTree.InsertItem(str,TVI_ROOT);			
						ado.pRecordset->MoveNext();
						i++;
					}
				}
				else if (count == 3)
				{
					while (!ado.pRecordset->adoEOF)
					{
						str=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan1");
						str+="→";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("busw1");	
						str+="(";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("total1");	
						str+="站)";
						str+="→";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan2");
						str+="→";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("busw2");
						str+="(";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("total2");	
						str+="站)";
						str+="→";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan3");
						str+="→";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("busw2");
						str+="(";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("total2");	
						str+="站)";
						str+="→";
						str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan4");
						m_CtrlChLnTree.InsertItem(str,TVI_ROOT);			
						ado.pRecordset->MoveNext();
						i++;
					}
				}
			}
			m_bReverse=false;
		}
		
		catch (_com_error e)
		{
			_bstr_t bstrSource(e.Source()); 
			_bstr_t bstrDescription(e.Description());  
			AfxMessageBox(bstrSource + bstrDescription);  
		}
	}
	else
	{
		AfxMessageBox("输入起止站不能相同！");
		return;
	}
}

BOOL CChangeLnDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_CtrlChLnTree.SetTextColor(RGB(0,255,255));
	m_CtrlChLnTree.SetBkColor(RGB(51,102,153));
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CChangeLnDlg::OnSwitchButton() 
{
	// TODO: Add your control notification handler code here
	m_bReverse=true;
	OnChlnQueryBtn();
}

void CChangeLnDlg::OnEditchangeChlnstartCombo() 
{
	// TODO: Add your control notification handler code here
	CString s;
	m_CtrlChLnStartCmb.GetWindowText(s);
	m_CtrlChLnStartCmb.ResetContent();
	m_CtrlChLnStartCmb.SetWindowText(s);
	
	m_CtrlChLnStartCmb.SetEditSel(s.GetLength(),s.GetLength());
	try
	{
		ado.Execute(_bstr_t(fuzzyMatchingBusStation+s+"'"));
		int i=0;
		while (!ado.pRecordset->adoEOF)
		{
			s=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan");
			m_CtrlChLnStartCmb.InsertString(i,s);
			
			++i;
			ado.pRecordset->MoveNext();
		}
		if (i==0)
		{
			MessageBox("无此站点");
			m_CtrlChLnStartCmb.ResetContent();
			OnSetfocusChlnstartCombo();
		}
	}
	
	catch (_com_error e)
	{
		_bstr_t bstrSource(e.Source()); 
		_bstr_t bstrDescription(e.Description());  
		AfxMessageBox(bstrSource + bstrDescription);  
		
	}
	m_CtrlChLnStartCmb.ShowDropDown();
}

void CChangeLnDlg::OnSetfocusChlnstartCombo() 
{
	// TODO: Add your control notification handler code here
	try
	{
		CString s;
		m_CtrlChLnStartCmb.GetWindowText(s);
		//	MessageBox(s);
		
		m_CtrlChLnStartCmb.ResetContent();
		m_CtrlChLnStartCmb.SetWindowText(s);
		ado.Execute(_bstr_t(fuzzyMatchingBusStation+s+"'"));
		int i=0;
		while (!ado.pRecordset->adoEOF)
		{
			s=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan");
			m_CtrlChLnStartCmb.InsertString(i,s);
			
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
	m_CtrlChLnStartCmb.ShowDropDown();
}

void CChangeLnDlg::OnEditchangeChlnendCombo() 
{
	// TODO: Add your control notification handler code here
	CString s;
	m_CtrlChLnEndCmb.GetWindowText(s);
	m_CtrlChLnEndCmb.ResetContent();
	m_CtrlChLnEndCmb.SetWindowText(s);
	
	m_CtrlChLnEndCmb.SetEditSel(s.GetLength(),s.GetLength());
	try
	{
		ado.Execute(_bstr_t(fuzzyMatchingBusStation+s+"'"));
		int i=0;
		while (!ado.pRecordset->adoEOF)
		{
			s=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan");
			m_CtrlChLnEndCmb.InsertString(i,s);
			
			++i;
			ado.pRecordset->MoveNext();
		}
		if (i==0)
		{
			MessageBox("无此站点");
			m_CtrlChLnEndCmb.ResetContent();
			OnSetfocusChlnstartCombo();
		}
	}
	
	catch (_com_error e)
	{
		_bstr_t bstrSource(e.Source()); 
		_bstr_t bstrDescription(e.Description());  
		AfxMessageBox(bstrSource + bstrDescription);  
		
	}
	m_CtrlChLnEndCmb.ShowDropDown();
}

void CChangeLnDlg::OnSetfocusChlnendCombo() 
{
	// TODO: Add your control notification handler code here
	try
	{
		CString s;
		m_CtrlChLnEndCmb.GetWindowText(s);
		//	MessageBox(s);
		
		m_CtrlChLnEndCmb.ResetContent();
		m_CtrlChLnEndCmb.SetWindowText(s);
		ado.Execute(_bstr_t(fuzzyMatchingBusStation+s+"'"));
		int i=0;
		while (!ado.pRecordset->adoEOF)
		{
			s=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan");
			m_CtrlChLnEndCmb.InsertString(i,s);
			
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
	m_CtrlChLnEndCmb.ShowDropDown();
}
