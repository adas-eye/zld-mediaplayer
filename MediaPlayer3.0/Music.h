#pragma once
#include "DB.h"
class Music
{
public:
	Music(void);
	~Music(void);
   	int	iMusicID	;            //��Ƶ�ļ�ID
	CString	CStrArtist;        //������
	CString	CStrAlbum	;        //ר��
	CString	CStrGenre;        //����
	CString	CStrYear	;            //���
	CString	CStrPath	;        //��Ƶ�ļ�ȫ·��
	CString	CStrFileName;  //��Ƶ�ļ��ļ���
 void AnalyzeMusic(const char *SrcUrl);

//int GetArtist(char *pcArtist[],int iArtistNum);//��ȡ����������
//int GetMusicByArtist(Music *pstMusic,char *pcArtist,int iMusicNum);//��ȡĳλ�����ҵ����и����ṹ������
//
//int GetAlbum(char *pcAlbum [],int iAlbumNum);//��ȡר������
//int GetMusicByAlbum (Music *pstMusic,char *pcAlbum,int iMusicNum);//��ȡĳ��ר�������и����ṹ������
//
//int GetGenre(char *pcGenre[],int iGenreNum);//��ȡ�������
//int GetMusicByGenre (Music *pstMusic,char *pcGenre,int iMusicNum);//��ȡĳ�ַ������и����ṹ������
//
//int GetYear(char *pcYear[],int iYearNum);//��ȡ�������
//int GetMusicByYear (Music *pstMusic,char *pcYear,int iMusicNum);//��ȡĳ����ݵ����и����ṹ������
//
//int GetPathByID(Music *pstMusic,char *pcPath,int iID);//��ͨ��ȫ��Music�ṹ�������±���MusicID����ͨ��musicID�����Ƶȫ·��
//
//int PlayMusic(char * pcPath); //���Ų�����Ƶ�ļ�

  int GetArtist(CStringArray &csaArtists);//��ȡ����������
  int GetArtist(CStringArray &csaArtists,char c);//��ȡ����������
  int GetMusicByArtist(Music *pclsMusic,CString csArtist,int * piMusicNum);//��ȡĳλ�����ҵ����и����ṹ������
  int Music::GetMusicByMusicID(Music &clsMusic,int iMusicID);
};
