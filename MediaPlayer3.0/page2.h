#pragma once
#include "afxcmn.h"


// Cpage2 dialog

class Cpage2 : public CDialog
{
	DECLARE_DYNAMIC(Cpage2)

public:
	Cpage2(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cpage2();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_tree;
};
