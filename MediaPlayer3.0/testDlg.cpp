// testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "page1.h"
#include "page2.h"
#include "SkinPPWTL.h" 
#include "FoldWatch.h"
#include "Music.h"
#include "MusicDB.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern CWMPPlayer4 g_player;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };


    
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CtestDlg dialog




CtestDlg::CtestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CtestDlg::IDD, pParent)
	,m_page1(&g_player,NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);

	DDX_Control(pDX, IDC_OCX1, g_player);
}

BEGIN_MESSAGE_MAP(CtestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CtestDlg::OnTcnSelchangeTab1)

END_MESSAGE_MAP()


// CtestDlg message handlers

BOOL CtestDlg::OnInitDialog()
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
	m_tab.InsertItem(0,_T(" 资源库 "));
	m_tab.InsertItem(1,_T("播放列表"));
	m_page1.Create(IDD_DIALOG1,&m_tab);
	m_page2.Create(IDD_DIALOG2,&m_tab);
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top+=20;
	m_page1.MoveWindow(&rc);
	m_page2.MoveWindow(&rc);
	pDialog[0]=&m_page1;
	pDialog[1]=&m_page2;
	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);
	m_CurSelTab=0;
    int i=0;

	FoldWatch m_fw;
	m_fw.DirectoryList("D:\\资源");
	
    Music music;
	MusicDB musicdb;
	vector<string> vecFilePath=	m_fw.GetFoldFileList();
	for(i=0;i<vecFilePath.size();++i)
	{
		music.AnalyzeMusic(vecFilePath[i].c_str());
		musicdb.InsertMusic(music);
		//cout<<vecFilePath[i]<<endl;
		/*AnalyMusic(vecFilePath[i].c_str());
		cout<<Smusic.Path<<endl;
		cout<<Smusic.ID3v1TAG<<endl;
		cout<<Smusic.MUSIC_NAME<<endl;
		cout<<Smusic.Artist<<endl;
		cout<<Smusic.Album<<endl;
		cout<<Smusic.YEAR<<endl;
		cout<<Smusic.Comments<<endl;
		cout<<Smusic.Genre<<endl;
		cout<<Smusic.Reserved<<endl; 
		cout<<Smusic.Track<<endl; */
	}
	//m_page1.m_tree2.InsertItem(_T("co"),NULL,NULL,NULL,NULL);
    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CtestDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	m_CurSelTab = m_tab.GetCurSel();
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	*pResult = 0;
}

