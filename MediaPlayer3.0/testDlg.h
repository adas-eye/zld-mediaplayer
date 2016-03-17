// testDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "page1.h"
#include "page2.h"
#include "afxwin.h"
#include "CPlayer\wmpplayer4.h"
#include "CPlayer\wmpmedia.h"
#include "FoldWatch.h"

// CtestDlg dialog
class CtestDlg : public CDialog
{
// Construction
public:
	CtestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
    int m_CurSelTab;
	Cpage1 m_page1;
	Cpage2 m_page2;
	CDialog *pDialog[2];
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	
	
};
