// BusLnDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "BusSystem.h"
#include "BusSystem.h"
#include "BusLnDlg.h"
#include "ADO.h"
#include "BitmapTabCtrl.h"
#include "BusSystemdlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////////////
// CBusLnDlg dialog


CBusLnDlg::CBusLnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBusLnDlg::IDD, pParent)
	,m_direction(false)
{
	//{{AFX_DATA_INIT(CBusLnDlg)
	s = "Provider=SQLOLEDB.1;Password=a;Persist Security Info=True;User ID=sa;Initial Catalog=XIAN;Data Source=ASH_BOY";
	//}}AFX_DATA_INIT
	ado.InitData(s.AllocSysString());
}


void CBusLnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBusLnDlg)
	DDX_Control(pDX, IDC_BUSLN_LIST, m_CtrlBusLnList);
	DDX_Control(pDX, IDC_BUSLN_INFO_LIST, m_CtrlBusLnInfoList);
	DDX_Control(pDX, IDC_BUSLN_COMBO, m_CtrlBusLnCmb);
	DDX_Control(pDX, IDC_GO_BUTTON, m_GoButton);
	DDX_Control(pDX, IDC_COME_BUTTON, m_ComeButton);
	DDX_Control(pDX, IDC_BUSLN_TREE, m_BusLnTree);
	DDX_Control(pDX, IDC_BUSLN_BUTTON, m_BusLnButton);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBusLnDlg, CDialog)
	//{{AFX_MSG_MAP(CBusLnDlg)
	ON_NOTIFY(NM_CLICK, IDC_BUSLN_TREE, OnClickBuslnTree)
	ON_CBN_SELCHANGE(IDC_BUSLN_COMBO, OnSelchangeBuslnCombo)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUSLN_BUTTON, OnBuslnButton)
	ON_BN_CLICKED(IDC_GO_BUTTON, OnGoButton)
	ON_BN_CLICKED(IDC_COME_BUTTON, OnComeButton)
	ON_NOTIFY(TVN_SELCHANGED, IDC_BUSLN_TREE, OnSelchangedBuslnTree)
	ON_CBN_SETFOCUS(IDC_BUSLN_COMBO, OnSetfocusBuslnCombo)
	ON_CBN_EDITCHANGE(IDC_BUSLN_COMBO, OnEditchangeBuslnCombo)
	ON_LBN_SELCHANGE(IDC_BUSLN_LIST, OnSelchangeBuslnList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBusLnDlg message handlers

void CBusLnDlg::OnClickBuslnTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
    //HTREEITEM m_Root, m_Child;
    

	*pResult = 0;
}


void CBusLnDlg::OnSelchangeBuslnCombo() 
{
	// TODO: Add your control notification handler code here
   /*在这里需要从数据库中筛选的公交线路显示在列表框中 ,筛选的信息以文件的形式储存*/

// 	int pos = m_CtrlBusLnCmb.GetCurSel(); //获取列表框当前选择的索引存入到pos中
// 	CString  str;//用来存储从列表框中选中的字符串
// 	m_CtrlBusLnCmb.GetLBText(pos,str);  // 获取列表框中的字符串
//     m_CtrlBusLnCmb.SetEditSel(0,10);   //选中组合框的编辑控件中的字符
}


HBRUSH CBusLnDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
// 	if (nCtlColor = CTLCOLOR_LISTBOX )  //是组合控件
// 	{
// 		int ItemNum = 9;//m_CtrlBusLnCmb.GetCount();   //获取列表项个数
// 	    CString strItem ; ////////
// 		int Width;
// 		CClientDC dc(this);  //获取客户设备上下文
// 		int Savedc = dc.SaveDC();  //保存设备上下文
// 	    dc.SelectObject(GetFont());//设置字体
// 		int VSWidth = ::GetSystemMetrics(SM_CXVSCROLL);//垂直滚动条的宽度
// 	
// 		for (int i = 0; i < ItemNum; i++)
// 		{
// 			m_CtrlBusLnCmb.GetLBText(i, strItem);//获取列表项字符串///////////

// 		    int WholeWidth = dc.GetTextExtent(strItem).cx + VSWidth;  //计算列表项宽度
// 			Width = max(Width,WholeWidth);//获取列表项最大宽度
// 			
// 		
// 		}
// 
// 		dc.RestoreDC(Savedc);
// 
//         if (Width > 0)
//         {
//          CRect rc;
// 		 pWnd->GetWindowRect(&rc);//获得窗口区域
// 		 
// 		 if (rc.Width() != Width)
// 		 {
// 			 rc.right = rc.left + Width;
// 			 pWnd->MoveWindow(&rc);
// 		 }
// 
//         }
// 
// 	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CBusLnDlg::OnBuslnButton() 
{
	// TODO: Add your control notification handler code here
	int i =0;
	UpdateData(TRUE);
	m_CtrlBusLnInfoList.ResetContent();
	m_CtrlBusLnList.ResetContent();
	CString str;
    m_CtrlBusLnCmb.GetWindowText(str); 
	if (str=="")
	{
		AfxMessageBox("输入线路不能为空！");
		return;
	}
	
   //	m_CtrlBusLnList.DeleteItem();
   //将公交车的基本信息添加到list控件里面
	CString  PiaoJia;
	CString  Time;
	CString  UpdateTime;
	CString  Note;
	CString  Firm;
	CString  note;
	CString zxdate;
	CString gjgs;
    int RowNum = 5;//在列表框显示的组数
	try
	{
		ado.Execute(_bstr_t(queryByBusName + str +"'"));

		str = (LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("busw");
		PiaoJia =  (LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("piao");
		Time =  (LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("shijian");
		if (ado.pRecordset->GetCollect("note").vt != VT_NULL)
		{
			note = (LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("note");
		}
		
		zxdate = (LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zxdate");
		gjgs = (LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("gjgs");
		PiaoJia="票价："  + PiaoJia;
   
		Time =  "时间：" + Time;
		UpdateTime = "更新时间：" + zxdate;
		Note = "备注：" + note;
		Firm = "公交公司：" + gjgs;
 
		m_CtrlBusLnInfoList.InsertString(0, PiaoJia);
		m_CtrlBusLnInfoList.InsertString(1, Time);
		m_CtrlBusLnInfoList.InsertString(2, UpdateTime);
		m_CtrlBusLnInfoList.InsertString(3, Note);
		m_CtrlBusLnInfoList.InsertString(4, Firm);
		::SendMessage (AfxGetApp()->m_pMainWnd-> m_hWnd,LB_SETHORIZONTALEXTENT,100,0);
		//////////////////////////////////////////////////////////////////////////
   
		m_CtrlBusLnInfoList.InsertString(0, str);

		if (m_direction)
		{
			str+="','1'";
		}
		else
		{
			str+="','0'";
		}	
		ado.Execute(_bstr_t(queryBusWayInfo+str));

		while (!ado.pRecordset->adoEOF)
		{
			str=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("pm");
			str+="    ";
			str+=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan");
			//将查询结果在list控件中显示
			m_CtrlBusLnList.InsertString(i, str);			
			ado.pRecordset->MoveNext();
			i++;
		}

		CString begin;
		CString end;
		ado.pRecordset->MoveFirst();
		begin=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan");
		while (!ado.pRecordset->adoEOF)
		{
			end=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("zhan");
			ado.pRecordset->MoveNext();
		}
		if (m_direction==0)
		{
			GetDlgItem(IDC_GO_BUTTON)->SetWindowText(begin+"->"+end);
			GetDlgItem(IDC_COME_BUTTON)->SetWindowText(end+"->"+begin);
		}
		else
		{
			GetDlgItem(IDC_GO_BUTTON)->SetWindowText(end+"->"+begin);
			GetDlgItem(IDC_COME_BUTTON)->SetWindowText(begin+"->"+end);
		}
		
	}
	catch (_com_error e)
	{
		_bstr_t bstrSource(e.Source()); 
		_bstr_t bstrDescription(e.Description());  
		AfxMessageBox(bstrSource + bstrDescription);  
	}

	GetDlgItem(IDC_BUSLN_INFO_LIST)->SetWindowText(_T(""));
	GetDlgItem(IDC_BUSLN_LIST)->SetWindowText(_T(""));
	UpdateData(FALSE);
}

void CBusLnDlg::OnGoButton() 
{
	// TODO: Add your control notification handler code here
	m_direction=0;
	OnBuslnButton();
}

void CBusLnDlg::OnComeButton() 
{
	// TODO: Add your control notification handler code here
	m_direction=1;
	OnBuslnButton();
}

BOOL CBusLnDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	ADO ado2;
	ado2.InitData(s.AllocSysString());

	m_BusLnTree.SetTextColor(RGB(0,255,255));//设置树形框中文字的颜色
	m_BusLnTree.SetBkColor(RGB(51,102,153));//设置树形框中的背景颜色
	ado.Execute(_bstr_t(BusKinds)); //执行BusKinds存储过程
	CString str;
	HTREEITEM hItem;

	try
	{
		while (!ado.pRecordset->adoEOF)//判断是否读到
		{
			str=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("kind");//从数据库的kind字段中取值
			hItem=m_BusLnTree.InsertItem(str,TVI_ROOT);
			ado2.Execute(_bstr_t(BusCollection + str +"'"));
			while (!ado2.pRecordset->adoEOF)
			{
				str=(LPCTSTR)(_bstr_t)ado2.pRecordset->GetCollect("busw");
				m_BusLnTree.InsertItem(_bstr_t(str),hItem);   //插入记录并填入第一个字段的值
				ado2.pRecordset->MoveNext();//转入数据库下一记录
			}
			ado.pRecordset->MoveNext();//转入数据库下一记录
		}
	}
	catch (_com_error e)
	{
		_bstr_t bstrSource(e.Source()); 
		_bstr_t bstrDescription(e.Description());  
		AfxMessageBox(bstrSource + bstrDescription);  
		return false;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBusLnDlg::OnSelchangedBuslnTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	TVITEM item0=pNMTreeView->itemNew;
	CString str=m_BusLnTree.GetItemText(item0.hItem);
	if(!m_BusLnTree.ItemHasChildren(item0.hItem))
	{
		m_CtrlBusLnCmb.SetWindowText(str);
		UpdateData(FALSE);
		OnBuslnButton();
	}
	*pResult = 0;
}


void CBusLnDlg::OnSetfocusBuslnCombo() 
{
	// TODO: Add your control notification handler code here
	//////////////////////////////////////////////////////////////////////////
	//这个函数主要是从窗口组合框中获得用户输入的数据，为用户提供索引功能方便用户操作
	//////////////////////////////////////////////////////////////////////////
	CString s;
	m_CtrlBusLnCmb.GetWindowText(s);
	//	MessageBox(s);
	
	m_CtrlBusLnCmb.ResetContent();
	try
	{
		ado.Execute(_bstr_t(fuzzyMatchingBusWay+s+"'"));
		int i=0;
		while (!ado.pRecordset->adoEOF)
		{
			s=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("busw");
			m_CtrlBusLnCmb.InsertString(i,s);
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
	m_CtrlBusLnCmb.ShowDropDown(TRUE);
}

void CBusLnDlg::OnEditchangeBuslnCombo() 
{
	// TODO: Add your control notification handler code here
	CString s;
	m_CtrlBusLnCmb.GetWindowText(s);
	//	MessageBox(s);
	m_CtrlBusLnCmb.ResetContent();
	m_CtrlBusLnCmb.SetWindowText(s);
	m_CtrlBusLnCmb.SetEditSel(s.GetLength(),s.GetLength());
	try
	{
		ado.Execute(_bstr_t(fuzzyMatchingBusWay+s+"'"));
		int i=0;
		while (!ado.pRecordset->adoEOF)
		{
			s=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("busw");
			m_CtrlBusLnCmb.InsertString(i,s);
			
			++i;
			ado.pRecordset->MoveNext();
		}
		if (i==0)
		{
			MessageBox("无此线路。");
			m_CtrlBusLnCmb.ResetContent();
			OnSetfocusBuslnCombo();
		}
	}
	catch (_com_error e)
	{
		_bstr_t bstrSource(e.Source()); 
		_bstr_t bstrDescription(e.Description());  
		AfxMessageBox(bstrSource + bstrDescription);  
	}

	m_CtrlBusLnCmb.ShowDropDown(TRUE);
}

void CBusLnDlg::OnSelchangeBuslnList() 
{
	// TODO: Add your control notification handler code here
	CString s;
//	m_Cursel=m_LsFileShow.GetCurSel();
	m_CtrlBusLnList.GetText(m_CtrlBusLnList.GetCurSel(),s);
	s=s.Right(s.GetLength()-s.ReverseFind(' ')-1);
	CBusSystemDlg* dlg =(CBusSystemDlg*) GetParent()->GetParent();
	CRect r;
	dlg->m_tabctrl.GetClientRect (&r);
	dlg->m_busln.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW );
	dlg->m_changeln.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW ); 
	dlg->m_seeksite.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_SHOWWINDOW); 

	dlg->m_seeksite.GetDlgItem(IDC_SKST_COMBO)->SetWindowText(s);
	dlg->m_seeksite.OnSkstButton();
}