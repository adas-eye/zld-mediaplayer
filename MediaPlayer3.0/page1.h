#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Music.h"
#include "CPlayer\wmpplayer4.h"
// Cpage1 dialog

class Cpage1 : public CDialog
{
	DECLARE_DYNAMIC(Cpage1)

public:
	Cpage1(CWnd* pParent = NULL);   // standard constructor
	Cpage1(CWMPPlayer4* cwmpp,CWnd* pParent = NULL);  
	virtual ~Cpage1();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo1;


	afx_msg void OnTvnSelchangedTree2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeCombo2();

	CComboBox m_combo2;
//	afx_msg void OnCbnSelchangeCombo3();
	CTreeCtrl m_tree2;
	afx_msg void OnTvnSelchangedTree3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeCombo3();
	int InsertStaticArtists();
	
	HTREEITEM hAG;//以艺术家首字母命名
	HTREEITEM hHN;
	HTREEITEM hOT;
	HTREEITEM hUZ;
	HTREEITEM hOther;

	HTREEITEM hA;
	HTREEITEM hB;
	HTREEITEM hC;
	HTREEITEM hD;
	HTREEITEM hE;
	HTREEITEM hF;
	HTREEITEM hG;

    HTREEITEM hH;
	HTREEITEM hI;
	HTREEITEM hJ;
	HTREEITEM hK;
	HTREEITEM hL;
	HTREEITEM hM;
	HTREEITEM hN;

	HTREEITEM hO;
	HTREEITEM hP;
	HTREEITEM hQ;
	HTREEITEM hR;
	HTREEITEM hS;
	HTREEITEM hT;
	
	HTREEITEM hU;
	HTREEITEM hV;
	HTREEITEM hW;
	HTREEITEM hX;
	HTREEITEM hY;
	HTREEITEM hZ;

	
	HTREEITEM SelectedItem(CTreeCtrl & tree1);
	int InsertDynamicArtists(char cArtists);
	int InsertDynamicOtherArtists();
	Music m_aclsMusic[20];
	int m_MusicNum;
	int InsertFilenameByAcharrtist(HTREEITEM  hCurrent,Music clsMusic);
	int PlayMusic(CString csPath);
	afx_msg void OnNMDblclkTree3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickTree3(NMHDR *pNMHDR, LRESULT *pResult);

	CWMPPlayer4* m_cwmpp;
};
