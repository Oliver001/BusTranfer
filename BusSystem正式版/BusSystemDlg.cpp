// BusSystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BusSystem.h"
#include "BusSystemDlg.h"
#include "ADO.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBusSystemDlg dialog

CBusSystemDlg::CBusSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBusSystemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBusSystemDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBusSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBusSystemDlg)
	DDX_Control(pDX, IDC_TAB1, m_tabctrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBusSystemDlg, CDialog)
	//{{AFX_MSG_MAP(CBusSystemDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBusSystemDlg message handlers

BOOL CBusSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	TCITEM item;
	CRect r;
		
	m_tabctrl.GetClientRect (&r);
	
	item.mask = TCIF_TEXT;

	item.pszText = "线路";
	m_tabctrl.InsertItem(0,&item);
	
	item.pszText = "换乘";
	m_tabctrl.InsertItem(1,&item);


    item.pszText = "站点";
	m_tabctrl.InsertItem(2,&item);

    m_busln.Create (IDD_BUSLN_DIALOG,&m_tabctrl);
	m_changeln.Create (IDD_CHANGELN_DIALOG,&m_tabctrl);
    m_seeksite.Create (IDD_SEEKSITE_DIALOG,&m_tabctrl);
	
// 	m_busln.SetWindowPos(NULL,10,30,400,100,SWP_SHOWWINDOW);
// 	m_changeln.SetWindowPos(NULL,10,30,400,100,SWP_SHOWWINDOW);
// 	m_seeksite.SetWindowPos (NULL,10,30,400,100,SWP_SHOWWINDOW);

	m_busln.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_SHOWWINDOW);
	
    m_changeln.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW ); 

	m_seeksite.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW ); 

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBusSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBusSystemDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBusSystemDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

HBRUSH CBusSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	if (nCtlColor == CTLCOLOR_EDIT) 
	{
		pDC->SetBkColor(RGB(255, 255, 0));  // yellow
		return   CreateSolidBrush(RGB(255,255,0));
	}
	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(51,102,153));    
		return CreateSolidBrush(RGB(51,102,153));
	}

	hbr = CreateSolidBrush(RGB(51,102,153));
	return hbr;
}

void CBusSystemDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CRect r;
	
	m_tabctrl.GetClientRect (&r);
	
	switch(m_tabctrl.GetCurSel())	
	{
		
	case 0:     //选中第一个页面
		
		m_busln.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_SHOWWINDOW);//显示第一个窗口
		m_changeln.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW ); //隐藏第二、三个窗口
	    m_seeksite.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW ); 
		break;
		
	case 1:
		
		m_busln.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW);
		m_changeln.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_SHOWWINDOW); 
     	m_seeksite.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW ); 

		break;
	
	case 2:
		m_busln.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW );
		m_changeln.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW ); 
		m_seeksite.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_SHOWWINDOW); 

		break;
	}
	
	*pResult = 0;
}
