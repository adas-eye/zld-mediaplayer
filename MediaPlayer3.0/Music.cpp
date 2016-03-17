#include "StdAfx.h"
#include "Music.h"
#include "CPlayer\wmpplayer4.h"
#include "CPlayer\wmpmedia.h"
extern CWMPMedia g_media;
extern CWMPPlayer4 g_player;
Music::Music(void)
{
}

Music::~Music(void)
{
}

void Music::AnalyzeMusic(const char *SrcUrl)
{
	g_media=g_player.newMedia(SrcUrl);
	CStrArtist=g_media.getItemInfo("Author");
	CStrAlbum=g_media.getItemInfo("WM/AlbumTitle");
	CStrGenre=g_media.getItemInfo("WM/Genre");
	CStrYear=g_media.getItemInfo("WM/Year");
	CStrFileName=g_media.getItemInfo("Title");
}

int Music::GetArtist(CStringArray &csaArtists)//获取艺术家数组
{
	DB db;
	db.Connect();
	db.SelectMulitCol("select distinct Artist from MusicTable",csaArtists);
	db.CloseRecordset();
	db.DisConnect();
	return 1;
}


int Music::GetArtist(CStringArray &csaArtists,char c)//获取艺术家数组
{
	DB db;
	db.Connect();
	CString csTemp;
	char cTemp='a';
	char sql[300]={0};
	if(c=='#')
	{
		sprintf(sql,"select distinct Artist from MusicTable where Artist like'%c%%' or Artist like'%c%%'",c,cTemp);
	}
	else
	{
		if(c<='Z')
		{
			cTemp=c+32;
			sprintf(sql,"select distinct Artist from MusicTable where Artist like'%c%%' or Artist like'%c%%'",c,cTemp);
		}
		else 
		{
			 cTemp=c-32;
			 sprintf(sql,"select distinct Artist from MusicTable where Artist like'%c%%' or Artist like'%c%%'",c,cTemp);
		}
	}
	//csTemp.Format("select Artist from MusicTable where Artist like'a%' or Artist like'a%'",c,cTemp);
   // AfxMessageBox("hshdhshdhg"); 
	//AfxMessageBox(sql);
	db.SelectMulitCol(sql,csaArtists);
	db.CloseRecordset();
	db.DisConnect();
	return 1;
}




int Music::GetMusicByArtist(Music *pclsMusic,CString csArtist,int * piMusicNum)
{ 
	if(pclsMusic==NULL||piMusicNum==NULL)
	{
		return 0;
	}
	DB db;
	db.Connect();
	CString csTemp;
	CStringArray csaArtists;
	csTemp.Format("select * from MusicTable where Artist='%s'",csArtist);
	//AfxMessageBox(csTemp);
	db.SelectMulitCol(csTemp,csaArtists);
	int iPadding=csaArtists.GetCount();
	int iCol=7;//db.GetResultCol();
	//csTemp.Format("%d",iCol);
	//AfxMessageBox(csTemp);
    int iRow=iPadding/iCol;//db.GetResultRow();
	int iC=0;
	int iR=0;
	for(int i=0;i<iPadding,iR<iRow;)
	{
		pclsMusic[iR].iMusicID=atoi(csaArtists.GetAt(i));i++;
		pclsMusic[iR].CStrArtist=csaArtists.GetAt(i);i++;
		pclsMusic[iR].CStrAlbum=csaArtists.GetAt(i);i++;
		pclsMusic[iR].CStrGenre=csaArtists.GetAt(i);i++;
		pclsMusic[iR].CStrYear=csaArtists.GetAt(i);i++;
		pclsMusic[iR].CStrPath=csaArtists.GetAt(i);i++;
		pclsMusic[iR].CStrFileName=csaArtists.GetAt(i);i++;
		iR++;
	}
	*piMusicNum=iRow;
	db.CloseRecordset();
	db.DisConnect();
	return 1;
}
int Music::GetMusicByMusicID(Music &clsMusic,int iMusicID)
{

  	DB db;
	db.Connect();
	CString csTemp;
	CStringArray csaArtists;
	csTemp.Format("select * from MusicTable where MusicID=%d",iMusicID);
	db.SelectMulitCol(csTemp,csaArtists);
	int iPadding=csaArtists.GetCount();
	if(iPadding!=7)
	{
		return 0;
	}
	clsMusic.iMusicID=atoi(csaArtists.GetAt(0));
	clsMusic.CStrArtist=csaArtists.GetAt(1);
	clsMusic.CStrAlbum=csaArtists.GetAt(2);
	clsMusic.CStrGenre=csaArtists.GetAt(3);
	clsMusic.CStrYear=csaArtists.GetAt(4);
	clsMusic.CStrPath=csaArtists.GetAt(5);
	clsMusic.CStrFileName=csaArtists.GetAt(6);
	db.CloseRecordset();
	db.DisConnect();
  return 1;
}