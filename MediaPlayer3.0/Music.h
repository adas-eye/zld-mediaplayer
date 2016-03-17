#pragma once
#include "DB.h"
class Music
{
public:
	Music(void);
	~Music(void);
   	int	iMusicID	;            //音频文件ID
	CString	CStrArtist;        //艺术家
	CString	CStrAlbum	;        //专辑
	CString	CStrGenre;        //主题
	CString	CStrYear	;            //年份
	CString	CStrPath	;        //音频文件全路径
	CString	CStrFileName;  //音频文件文件名
 void AnalyzeMusic(const char *SrcUrl);

//int GetArtist(char *pcArtist[],int iArtistNum);//获取艺术家数组
//int GetMusicByArtist(Music *pstMusic,char *pcArtist,int iMusicNum);//获取某位艺术家的所有歌曲结构体数组
//
//int GetAlbum(char *pcAlbum [],int iAlbumNum);//获取专辑数组
//int GetMusicByAlbum (Music *pstMusic,char *pcAlbum,int iMusicNum);//获取某个专辑的所有歌曲结构体数组
//
//int GetGenre(char *pcGenre[],int iGenreNum);//获取风格数组
//int GetMusicByGenre (Music *pstMusic,char *pcGenre,int iMusicNum);//获取某种风格的所有歌曲结构体数组
//
//int GetYear(char *pcYear[],int iYearNum);//获取年份数组
//int GetMusicByYear (Music *pstMusic,char *pcYear,int iMusicNum);//获取某个年份的所有歌曲结构体数组
//
//int GetPathByID(Music *pstMusic,char *pcPath,int iID);//先通过全局Music结构体数组下标获得MusicID，再通过musicID获得音频全路径
//
//int PlayMusic(char * pcPath); //播放播放音频文件

  int GetArtist(CStringArray &csaArtists);//获取艺术家数组
  int GetArtist(CStringArray &csaArtists,char c);//获取艺术家数组
  int GetMusicByArtist(Music *pclsMusic,CString csArtist,int * piMusicNum);//获取某位艺术家的所有歌曲结构体数组
  int Music::GetMusicByMusicID(Music &clsMusic,int iMusicID);
};
