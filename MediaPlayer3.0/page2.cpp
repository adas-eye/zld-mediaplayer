// page2.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "page2.h"


// Cpage2 dialog

IMPLEMENT_DYNAMIC(Cpage2, CDialog)

Cpage2::Cpage2(CWnd* pParent /*=NULL*/)
	: CDialog(Cpage2::IDD, pParent)
{

}

Cpage2::~Cpage2()
{
}

void Cpage2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_tree);
 m_tree.ModifyStyle(NULL,TVS_HASBUTTONS| TVS_HASLINES | TVS_LINESATROOT);
HTREEITEM hFirst = m_tree.InsertItem(_T("最近播放列表"),NULL,NULL,NULL,NULL);
HTREEITEM hSecond = m_tree.InsertItem(_T("Playlist"),NULL,NULL,NULL,NULL);

HTREEITEM A = m_tree.InsertItem(TVIF_TEXT,_T("色即是空"),0,0,0,0,0,hFirst,NULL);
HTREEITEM B= m_tree.InsertItem(TVIF_TEXT,_T("B"),0,0,0,0,0,hSecond,NULL);
}

BEGIN_MESSAGE_MAP(Cpage2, CDialog)
END_MESSAGE_MAP()


// Cpage2 message handlers
