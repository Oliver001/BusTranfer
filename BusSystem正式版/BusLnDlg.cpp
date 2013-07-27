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
   /*��������Ҫ�����ݿ���ɸѡ�Ĺ�����·��ʾ���б���� ,ɸѡ����Ϣ���ļ�����ʽ����*/

// 	int pos = m_CtrlBusLnCmb.GetCurSel(); //��ȡ�б��ǰѡ����������뵽pos��
// 	CString  str;//�����洢���б����ѡ�е��ַ���
// 	m_CtrlBusLnCmb.GetLBText(pos,str);  // ��ȡ�б���е��ַ���
//     m_CtrlBusLnCmb.SetEditSel(0,10);   //ѡ����Ͽ�ı༭�ؼ��е��ַ�
}


HBRUSH CBusLnDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
// 	if (nCtlColor = CTLCOLOR_LISTBOX )  //����Ͽؼ�
// 	{
// 		int ItemNum = 9;//m_CtrlBusLnCmb.GetCount();   //��ȡ�б������
// 	    CString strItem ; ////////
// 		int Width;
// 		CClientDC dc(this);  //��ȡ�ͻ��豸������
// 		int Savedc = dc.SaveDC();  //�����豸������
// 	    dc.SelectObject(GetFont());//��������
// 		int VSWidth = ::GetSystemMetrics(SM_CXVSCROLL);//��ֱ�������Ŀ��
// 	
// 		for (int i = 0; i < ItemNum; i++)
// 		{
// 			m_CtrlBusLnCmb.GetLBText(i, strItem);//��ȡ�б����ַ���///////////

// 		    int WholeWidth = dc.GetTextExtent(strItem).cx + VSWidth;  //�����б�����
// 			Width = max(Width,WholeWidth);//��ȡ�б��������
// 			
// 		
// 		}
// 
// 		dc.RestoreDC(Savedc);
// 
//         if (Width > 0)
//         {
//          CRect rc;
// 		 pWnd->GetWindowRect(&rc);//��ô�������
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
		AfxMessageBox("������·����Ϊ�գ�");
		return;
	}
	
   //	m_CtrlBusLnList.DeleteItem();
   //���������Ļ�����Ϣ��ӵ�list�ؼ�����
	CString  PiaoJia;
	CString  Time;
	CString  UpdateTime;
	CString  Note;
	CString  Firm;
	CString  note;
	CString zxdate;
	CString gjgs;
    int RowNum = 5;//���б����ʾ������
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
		PiaoJia="Ʊ�ۣ�"  + PiaoJia;
   
		Time =  "ʱ�䣺" + Time;
		UpdateTime = "����ʱ�䣺" + zxdate;
		Note = "��ע��" + note;
		Firm = "������˾��" + gjgs;
 
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
			//����ѯ�����list�ؼ�����ʾ
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

	m_BusLnTree.SetTextColor(RGB(0,255,255));//�������ο������ֵ���ɫ
	m_BusLnTree.SetBkColor(RGB(51,102,153));//�������ο��еı�����ɫ
	ado.Execute(_bstr_t(BusKinds)); //ִ��BusKinds�洢����
	CString str;
	HTREEITEM hItem;

	try
	{
		while (!ado.pRecordset->adoEOF)//�ж��Ƿ����
		{
			str=(LPCTSTR)(_bstr_t)ado.pRecordset->GetCollect("kind");//�����ݿ��kind�ֶ���ȡֵ
			hItem=m_BusLnTree.InsertItem(str,TVI_ROOT);
			ado2.Execute(_bstr_t(BusCollection + str +"'"));
			while (!ado2.pRecordset->adoEOF)
			{
				str=(LPCTSTR)(_bstr_t)ado2.pRecordset->GetCollect("busw");
				m_BusLnTree.InsertItem(_bstr_t(str),hItem);   //�����¼�������һ���ֶε�ֵ
				ado2.pRecordset->MoveNext();//ת�����ݿ���һ��¼
			}
			ado.pRecordset->MoveNext();//ת�����ݿ���һ��¼
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
	//���������Ҫ�ǴӴ�����Ͽ��л���û���������ݣ�Ϊ�û��ṩ�������ܷ����û�����
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
			MessageBox("�޴���·��");
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