// page1.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "page1.h"
#include "CPlayer\wmpplayer4.h"

// Cpage1 dialog

IMPLEMENT_DYNAMIC(Cpage1, CDialog)

Cpage1::Cpage1(CWnd* pParent /*=NULL*/)
	: CDialog(Cpage1::IDD, pParent)
{

}

Cpage1::Cpage1(CWMPPlayer4* cwmpp,CWnd* pParent /*=NULL*/)
	: CDialog(Cpage1::IDD, pParent)
	,m_cwmpp(cwmpp)
{

}
Cpage1::~Cpage1()
{

}

void Cpage1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_combo1);
    DDX_Control(pDX, IDC_COMBO3, m_combo2); 
    DDX_Control(pDX, IDC_TREE3, m_tree2);
  m_tree2.ModifyStyle(NULL,TVS_HASBUTTONS| TVS_HASLINES | TVS_LINESATROOT);
  m_tree2.SetBkColor(RGB(200, 250, 0));
  m_tree2.SetTextColor(RGB(0, 0, 255));
  
//  //CImageList m_myImageList;
//  ////CBitmap bm;
//  ////bm.LoadBitmap(IDB_BITMAP1);
//  ////m_myImageList.Add(&bm, RGB(0, 0, 0));
//  //m_myImageList.Create(IDB_BITMAP1,16,5,RGB(0,0,0));
//  //m_tree2.SetImageList(&m_myImageList, TVSIL_NORMAL);
//
///*设置五个节点*/
//HTREEITEM hFirst = m_tree2.InsertItem(_T("A-G"),NULL,NULL,NULL,NULL);
//HTREEITEM hSecond = m_tree2.InsertItem(_T("H-N"),NULL,NULL,NULL,NULL);
//HTREEITEM hThree = m_tree2.InsertItem(_T("O-T"),NULL,NULL,NULL,NULL);
//HTREEITEM hFour = m_tree2.InsertItem(_T("U-Z"),NULL,NULL,NULL,NULL);
//HTREEITEM hFive = m_tree2.InsertItem(_T("Other"),NULL,NULL,NULL,NULL);
////m_tree2.SetItemText(hFive, _T("OOOther"));
//
//
///*为A-G节点里面添加内容*/
//HTREEITEM A = m_tree2.InsertItem(TVIF_TEXT,_T("A"),0,0,0,0,0,hFirst,NULL);
//HTREEITEM B= m_tree2.InsertItem(TVIF_TEXT,_T("B"),0,0,0,0,0,hFirst,NULL);
//HTREEITEM C= m_tree2.InsertItem(TVIF_TEXT,_T("C"),0,0,0,0,0,hFirst,NULL);
//HTREEITEM D= m_tree2.InsertItem(TVIF_TEXT,_T("D"),0,0,0,0,0,hFirst,NULL);
//HTREEITEM E = m_tree2.InsertItem(TVIF_TEXT,_T("E"),0,0,0,0,0,hFirst,NULL);
//HTREEITEM F = m_tree2.InsertItem(TVIF_TEXT,_T("F"),0,0,0,0,0,hFirst,NULL);
//HTREEITEM G= m_tree2.InsertItem(TVIF_TEXT,_T("G"),0,0,0,0,0,hFirst,NULL);
//
///*为H-N节点里面添加内容*/
//HTREEITEM H = m_tree2.InsertItem(TVIF_TEXT,_T("H"),0,0,0,0,0,hSecond,NULL);
//HTREEITEM I = m_tree2.InsertItem(TVIF_TEXT,_T("I"),0,0,0,0,0,hSecond,NULL);
//HTREEITEM J = m_tree2.InsertItem(TVIF_TEXT,_T("J"),0,0,0,0,0,hSecond,NULL);
//HTREEITEM K = m_tree2.InsertItem(TVIF_TEXT,_T("K"),0,0,0,0,0,hSecond,NULL);
//HTREEITEM L = m_tree2.InsertItem(TVIF_TEXT,_T("L"),0,0,0,0,0,hSecond,NULL);
//HTREEITEM M = m_tree2.InsertItem(TVIF_TEXT,_T("M"),0,0,0,0,0,hSecond,NULL);
//HTREEITEM N = m_tree2.InsertItem(TVIF_TEXT,_T("N"),0,0,0,0,0,hSecond,NULL);
//
///*为O-T节点里面添加内容*/
//HTREEITEM O = m_tree2.InsertItem(TVIF_TEXT,_T("O"),0,0,0,0,0,hThree,NULL);
//HTREEITEM P = m_tree2.InsertItem(TVIF_TEXT,_T("P"),0,0,0,0,0,hThree,NULL);
//HTREEITEM Q = m_tree2.InsertItem(TVIF_TEXT,_T("Q"),0,0,0,0,0,hThree,NULL);
//HTREEITEM R = m_tree2.InsertItem(TVIF_TEXT,_T("R"),0,0,0,0,0,hThree,NULL);
//HTREEITEM S = m_tree2.InsertItem(TVIF_TEXT,_T("S"),0,0,0,0,0,hThree,NULL);
//HTREEITEM T = m_tree2.InsertItem(TVIF_TEXT,_T("T"),0,0,0,0,0,hThree,NULL);
//
///*为U-Z节点里面添加内容*/
//HTREEITEM U = m_tree2.InsertItem(TVIF_TEXT,_T("U"),0,0,0,0,0,hFour,NULL);
//HTREEITEM V = m_tree2.InsertItem(TVIF_TEXT,_T("V"),0,0,0,0,0,hFour,NULL);
//HTREEITEM W = m_tree2.InsertItem(TVIF_TEXT,_T("W"),0,0,0,0,0,hFour,NULL);
//HTREEITEM X = m_tree2.InsertItem(TVIF_TEXT,_T("X"),0,0,0,0,0,hFour,NULL);
//HTREEITEM Y = m_tree2.InsertItem(TVIF_TEXT,_T("Y"),0,0,0,0,0,hFour,NULL);
//HTREEITEM Z = m_tree2.InsertItem(TVIF_TEXT,_T("Z"),0,0,0,0,0,hFour,NULL);
//
///*为Other节点里面添加内容*/
//HTREEITEM h5 = m_tree2.InsertItem(TVIF_TEXT,_T("Other"),0,0,0,0,0,hFive,NULL);

	
}
BEGIN_MESSAGE_MAP(Cpage1, CDialog)
    
	ON_CBN_SELCHANGE(IDC_COMBO2, &Cpage1::OnCbnSelchangeCombo2)
//	ON_CBN_SELCHANGE(IDC_COMBO3, &Cpage1::OnCbnSelchangeCombo3)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE3, &Cpage1::OnTvnSelchangedTree3)
	ON_CBN_SELCHANGE(IDC_COMBO3, &Cpage1::OnCbnSelchangeCombo3)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE3, &Cpage1::OnNMDblclkTree3)
	ON_NOTIFY(NM_CLICK, IDC_TREE3, &Cpage1::OnNMClickTree3)
END_MESSAGE_MAP()


// Cpage1 message handlers

void Cpage1::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
    CString m_str1,m_str2;
	m_combo1.GetLBText(m_combo1.GetCurSel(),m_str1);
	if(m_str1==("视频"))
	{
		for(int i = m_combo2.GetCount() - 1; i >= 0; i--)
		{
			m_combo2.DeleteString(i);
		}
        m_combo2.AddString("Year");
		m_combo2.AddString("Size");
		m_combo2.AddString("Movie Type");
     }
	else if(m_str1==("图片"))
	{

      for(int i = m_combo2.GetCount() - 1; i >= 0; i--)
		{
			m_combo2.DeleteString(i);
		}
	    m_combo2.AddString("Year");
		m_combo2.AddString("Size");
		m_combo2.AddString("Photo Type");
		m_combo2.AddString("Camera Model");
		
	}
	else
	{
    for(int i = m_combo2.GetCount() - 1; i >= 0; i--)
		{
			m_combo2.DeleteString(i);
		}
        m_combo2.AddString("Year");
		m_combo2.AddString("Artist");
		m_combo2.AddString("Album");
		m_combo2.AddString("Genre");
	}
}



void Cpage1::OnTvnSelchangedTree2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	//MessageBox("OK");
}


//下拉框选中相应事件
//
void Cpage1::OnCbnSelchangeCombo3()
{
	// TODO: Add your control notification handler code here
	CString m_str1,m_str2;
	m_combo2.GetLBText(m_combo2.GetCurSel(),m_str1);
	if(m_str1==("Album"))
	{
		MessageBox(m_str1);
     }
	else if(m_str1==("Artist"))
	{
		InsertStaticArtists();
	}
	else if(m_str1==("Genre"))
	{

	}
	else 
	{

	}
}

//选中树节点，相应事件
//
void Cpage1::OnTvnSelchangedTree3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here	

	*pResult = 0;
}
//相应树控件的双击事件
//
void Cpage1::OnNMDblclkTree3(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HTREEITEM  hCurrent=SelectedItem(m_tree2);
	
	if(m_tree2.ItemHasChildren(hCurrent)==0)//没有孩子结点
	{
		//MessageBox("OK");
		//PlayMusic("C:\\Documents and Settings\\new\\桌面\\6.1资源\\天天想你-张雨生.wma");
		int iMusicID=m_tree2.GetItemData(hCurrent);
		CString c;
		c.Format("%d",iMusicID);
		MessageBox(c);
		Music clsMusic;
		if(clsMusic.GetMusicByMusicID(clsMusic,iMusicID)==1)
		{
			MessageBox(clsMusic.CStrPath);
			PlayMusic(clsMusic.CStrPath);
		}
		/*CString csTemp=m_tree2.GetItemText(hCurrent);*/
	/*	for(int i=0;i<m_MusicNum;i++)
		{
			if(csTemp==m_aclsMusic[i].CStrFileName)
			{
				MessageBox(m_aclsMusic[i].CStrArtist);
				MessageBox(m_aclsMusic[i].CStrAlbum);
				MessageBox(m_aclsMusic[i].CStrGenre);
				MessageBox(m_aclsMusic[i].CStrYear);
				MessageBox(m_aclsMusic[i].CStrPath);
				MessageBox(m_aclsMusic[i].CStrFileName);
			}
		}*/
	}
	*pResult = 0;
}


//相应树控件的单击事件
//
void Cpage1::OnNMClickTree3(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	HTREEITEM  hCurrent=SelectedItem(m_tree2);
	HTREEITEM hCurrentParent=m_tree2.GetParentItem(hCurrent);
	//点击Ａ，Ｂ，Ｃ。。。加载每位歌手的歌曲
	if(hCurrentParent==hAG||hCurrentParent==hHN||hCurrentParent==hOT||hCurrentParent==hUZ||hCurrent==hOther)
	{	
		Music clsMusic;
		HTREEITEM hChild=m_tree2.GetChildItem(hCurrent);
		HTREEITEM hBrother=hChild;
////////////////////////////////////////////////////////////
		//HTREEITEM hDelete=m_tree2.GetChildItem(hChild);
		//if(hDelete!=NULL)
		//{
  //         m_tree2.DeleteItem(hDelete);
		//   hBrother=hDelete;
		//}      
		//while((hBrother=m_tree2.GetNextSiblingItem(hBrother))!=NULL)//还有兄弟节点，依次加载
		//{
		//	m_tree2.DeleteItem(hBrother);
		//}
///////////////////////////////////////////////////////         
		hBrother=hChild;
		CString csTemp=m_tree2.GetItemText(hChild);	
    	clsMusic.GetMusicByArtist(m_aclsMusic,csTemp,&m_MusicNum);
		for(int i=0;i<m_MusicNum;i++)
		{
			InsertFilenameByAcharrtist(hChild,m_aclsMusic[i]);
		}
		while((hBrother=m_tree2.GetNextSiblingItem(hBrother))!=NULL)//还有兄弟节点，依次加载
		{
			csTemp=m_tree2.GetItemText(hBrother);
            //根据艺术家获取其所有的歌曲
			clsMusic.GetMusicByArtist(m_aclsMusic,csTemp,&m_MusicNum);
			for(int i=0;i<m_MusicNum;i++)
			{
				InsertFilenameByAcharrtist(hBrother,m_aclsMusic[i]);
			}
		}			
	}
	if(hCurrent==hAG||hCurrent==hHN||hCurrent==hOT||hCurrent==hUZ)//加载孙子节点对应的歌手名
	{
		HTREEITEM hChild=m_tree2.GetChildItem(hCurrent);
		HTREEITEM hBrother=hChild;

		////////////////////////////////////////////////////////////
		//HTREEITEM hDelete=m_tree2.GetChildItem(hChild);
		//if(hDelete!=NULL)
		//{
  //         m_tree2.DeleteItem(hDelete);
		//   hBrother=hDelete;
		//}      
		//while((hBrother=m_tree2.GetNextSiblingItem(hBrother))!=NULL)//还有兄弟节点，依次加载
		//{
		//	m_tree2.DeleteItem(hBrother);
		//}
		///////////////////////////////////////////////////////   

		hBrother=hChild;
		CString csTemp=m_tree2.GetItemText(hChild);
        InsertDynamicArtists(csTemp.GetAt(0));
		while((hBrother=m_tree2.GetNextSiblingItem(hBrother))!=NULL)
		{
			csTemp=m_tree2.GetItemText(hBrother);
            InsertDynamicArtists(csTemp.GetAt(0));
		}

	}
	*pResult = 0;
}


//获得树控件中，选中结点的唯一标识符
//
HTREEITEM Cpage1::SelectedItem(CTreeCtrl & tree1)
{
	CPoint   pt; 
	GetCursorPos(&pt); 
	tree1.ScreenToClient(&pt); 
	return tree1.HitTest(pt,NULL);
}
//静态插入A-G，及A、B等；
//动态插入other的歌手
//下拉框中选中Artist时，调用该函数
int Cpage1::InsertStaticArtists()
{
    	m_tree2.DeleteAllItems();
		//CImageList m_myImageList;
		//CBitmap bm;
		//bm.LoadBitmap(IDB_BITMAP1);
		////m_myImageList.Add(&bm, RGB(0, 0, 0));
		////m_myImageList.Create(IDB_BITMAP1,16,5,RGB(0,0,0));
		//m_tree2.SetImageList(&m_myImageList, TVSIL_NORMAL);
		hAG= m_tree2.InsertItem(_T("A-G"),0,0,NULL,NULL);
		hHN= m_tree2.InsertItem(_T("H-N"),NULL,NULL,NULL,NULL);
		hOT= m_tree2.InsertItem(_T("O-T"),NULL,NULL,NULL,NULL);
		hUZ= m_tree2.InsertItem(_T("U-Z"),NULL,NULL,NULL,NULL);
		hOther= m_tree2.InsertItem(_T("Other"),NULL,NULL,NULL,NULL);
        
		/*为A-G节点里面添加内容*/
		hA = m_tree2.InsertItem(TVIF_TEXT,_T("A"),0,0,0,0,0,hAG,NULL);
		hB= m_tree2.InsertItem(TVIF_TEXT,_T("B"),0,0,0,0,0,hAG,NULL);
		hC= m_tree2.InsertItem(TVIF_TEXT,_T("C"),0,0,0,0,0,hAG,NULL);
		hD= m_tree2.InsertItem(TVIF_TEXT,_T("D"),0,0,0,0,0,hAG,NULL);
		hE = m_tree2.InsertItem(TVIF_TEXT,_T("E"),0,0,0,0,0,hAG,NULL);
		hF = m_tree2.InsertItem(TVIF_TEXT,_T("F"),0,0,0,0,0,hAG,NULL);
		hG= m_tree2.InsertItem(TVIF_TEXT,_T("G"),0,0,0,0,0,hAG,NULL);

		/*为H-N节点里面添加内容*/
		hH = m_tree2.InsertItem(TVIF_TEXT,_T("H"),0,0,0,0,0,hHN,NULL);
		hI = m_tree2.InsertItem(TVIF_TEXT,_T("I"),0,0,0,0,0,hHN,NULL);
		hJ = m_tree2.InsertItem(TVIF_TEXT,_T("J"),0,0,0,0,0,hHN,NULL);
		hK = m_tree2.InsertItem(TVIF_TEXT,_T("K"),0,0,0,0,0,hHN,NULL);
		hL = m_tree2.InsertItem(TVIF_TEXT,_T("L"),0,0,0,0,0,hHN,NULL);
		hM = m_tree2.InsertItem(TVIF_TEXT,_T("M"),0,0,0,0,0,hHN,NULL);
		hN = m_tree2.InsertItem(TVIF_TEXT,_T("N"),0,0,0,0,0,hHN,NULL);

		/*为O-T节点里面添加内容*/
		hO = m_tree2.InsertItem(TVIF_TEXT,_T("O"),0,0,0,0,0,hOT,NULL);
		hP = m_tree2.InsertItem(TVIF_TEXT,_T("P"),0,0,0,0,0,hOT,NULL);
		hQ = m_tree2.InsertItem(TVIF_TEXT,_T("Q"),0,0,0,0,0,hOT,NULL);
		hR = m_tree2.InsertItem(TVIF_TEXT,_T("R"),0,0,0,0,0,hOT,NULL);
		hS = m_tree2.InsertItem(TVIF_TEXT,_T("S"),0,0,0,0,0,hOT,NULL);
		hT = m_tree2.InsertItem(TVIF_TEXT,_T("T"),0,0,0,0,0,hOT,NULL);
		
		/*为U-Z节点里面添加内容*/
		hU = m_tree2.InsertItem(TVIF_TEXT,_T("U"),0,0,0,0,0,hUZ,NULL);
		hV = m_tree2.InsertItem(TVIF_TEXT,_T("V"),0,0,0,0,0,hUZ,NULL);
		hW = m_tree2.InsertItem(TVIF_TEXT,_T("W"),0,0,0,0,0,hUZ,NULL);
		hX = m_tree2.InsertItem(TVIF_TEXT,_T("X"),0,0,0,0,0,hUZ,NULL);
		hY = m_tree2.InsertItem(TVIF_TEXT,_T("Y"),0,0,0,0,0,hUZ,NULL);
		hZ = m_tree2.InsertItem(TVIF_TEXT,_T("Z"),0,0,0,0,0,hUZ,NULL);

		InsertDynamicOtherArtists();
		//InsertDynamicArtists('A');
		//InsertDynamicArtists('B');
		//InsertDynamicArtists('C');
		//InsertDynamicArtists('D');
		//InsertDynamicArtists('E');
		//InsertDynamicArtists('F');
		//InsertDynamicArtists('G');
		//InsertDynamicArtists('H');
		//InsertDynamicArtists('I');
		//InsertDynamicArtists('G');
		//InsertDynamicArtists('J');
		//InsertDynamicArtists('L');
		//InsertDynamicArtists('M');
		//InsertDynamicArtists('N');
		//InsertDynamicArtists('O');
		//InsertDynamicArtists('P');
		//InsertDynamicArtists('Q');
		//InsertDynamicArtists('R');
		//InsertDynamicArtists('S');
		//InsertDynamicArtists('T');
		//InsertDynamicArtists('U');
		//InsertDynamicArtists('V');
		//InsertDynamicArtists('W');
		//InsertDynamicArtists('X');
		//InsertDynamicArtists('Y');
		//InsertDynamicArtists('Z');
	return 1;
}



//传入歌手名首字母
//调用数据库，获得首字母一致的歌手名数组，使用unique过滤掉相同的歌手名
//将将歌手名插入到相应的结点
int Cpage1::InsertDynamicArtists(char cArtists)
{      
		Music clsMusic;
		CStringArray csaArtists;
		if(cArtists=='#')//从数据库中获取所有艺术家数组
		{
			clsMusic.GetArtist(csaArtists);
		}
		else//根据艺术家首字母获取艺术家数组
		{
			clsMusic.GetArtist(csaArtists,cArtists);
		}
        int i=csaArtists.GetCount();
		for(int j=0;j<i;j++)
		{
			CString csTemp=csaArtists.GetAt(j);	
			//MessageBox(csTemp);
			switch(csTemp.GetAt(0))
			{
			    case 'a':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hA,NULL);break;
				case 'A':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hA,NULL);break;
				case 'b':
				case 'B':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hB,NULL);break;
				case 'c':
				case 'C':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hC,NULL);break;
				case 'd':
				case 'D':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hD,NULL);break;
				case 'e':
				case 'E':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hE,NULL);break;
				case 'f':
				case 'F':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hF,NULL);break;
				case 'g':
				case 'G':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hG,NULL);break;
				case 'h':
				case 'H':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hH,NULL);break;
		        case 'i':
				case 'I':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hI,NULL);break;
				case 'j':
				case 'J':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hJ,NULL);break;
				case 'k':
				case 'K':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hK,NULL);break;
				case 'l':
				case 'L':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hL,NULL);break;
				case 'm':
				case 'M':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hM,NULL);break;
				case 'n':
				case 'N':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hN,NULL);break;
				case 'o':
				case 'O':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hO,NULL);break;
				case 'p':
				case 'P':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hP,NULL);break;
				case 'q':
				case 'Q':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hQ,NULL);break;
				case 'r':
				case 'R':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hR,NULL);break;
				case 's':
				case 'S':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hS,NULL);break;
				case 't':
				case 'T':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hT,NULL);break;
				case 'u':
				case 'U':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hU,NULL);break;
				case 'v':
				case 'V':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hV,NULL);break;
				case 'w':
				case 'W':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hW,NULL);break;
				case 'x':
				case 'X':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hX,NULL);break;
				case 'y':
				case 'Y':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hY,NULL);break;
				case 'z':
				case 'Z':m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hZ,NULL);break;
				default:m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hOther,NULL);break;
			}
		}

	return 1;
}

//传入树控件唯一标识符、音乐类对象
//
int Cpage1::InsertFilenameByAcharrtist(HTREEITEM  hCurrent,Music clsMusic)
{
	/*	for(int j=0;j<*piMusicNum;j++)
		{*/
			CString csTempArtist=clsMusic.CStrArtist;
			CString csTempFilename=clsMusic.CStrFileName;
			
		    HTREEITEM hItem=m_tree2.InsertItem(TVIF_TEXT,csTempFilename,0,0,0,0,(LPARAM )3,hCurrent,NULL);	
			m_tree2.SetItemData(hItem, (DWORD_PTR)(clsMusic.iMusicID));
		//	CtestDlg::m_player.SetUrl(pclsMusic[j].CStrPath);
		/*}*/

	return 1;
}

//向Other结点动态插入艺术家数组
//
int Cpage1::InsertDynamicOtherArtists()
{      
	    //从数据库中获取所有艺术家数组
	    Music clsMusic;
		CStringArray csaArtists;
		clsMusic.GetArtist(csaArtists);
        int  i=csaArtists.GetCount();
		for(int j=0;j<i;j++)
		{
			CString csTemp=csaArtists.GetAt(j);	
			//MessageBox(csTemp);
			switch(csTemp.GetAt(0))
			{
			    case 'a':break;
				case 'A':break;
				case 'b':
				case 'B':break;
				case 'c':
				case 'C':break;
				case 'd':
				case 'D':break;
				case 'e':
				case 'E':break;
				case 'f':
				case 'F':break;
				case 'g':
				case 'G':break;
				case 'h':
				case 'H':break;
		        case 'i':
				case 'I':break;
				case 'j':
				case 'J':break;
				case 'k':
				case 'K':break;
				case 'l':
				case 'L':break;
				case 'm':
				case 'M':break;
				case 'n':
				case 'N':break;
				case 'o':
				case 'O':break;
				case 'p':
				case 'P':break;
				case 'q':
				case 'Q':break;
				case 'r':
				case 'R':break;
				case 's':
				case 'S':break;
				case 't':
				case 'T':break;
				case 'u':
				case 'U':break;
				case 'v':
				case 'V':break;
				case 'w':
				case 'W':break;
				case 'x':
				case 'X':break;
				case 'y':
				case 'Y':break;
				case 'z':
				case 'Z':break;
				default:m_tree2.InsertItem(TVIF_TEXT,csTemp,0,0,0,0,0,hOther,NULL);break;
			}
		}

	return 1;
}


//播放音乐
//
int Cpage1::PlayMusic(CString csPath)
{
	m_cwmpp->SetUrl(csPath);
	return 0;
}

