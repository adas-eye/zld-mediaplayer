#pragma once

class Movie
{
public:
	Movie(void);
	~Movie(void);
	int	iMovieID	;             //��Ƶ�ļ�ID
	int	iTimeLength	;     //��Ƶ���ź�ʱ����λ���룩
	int	iLength	;             //��Ƶ���ȣ���λ�����أ�
	int	iWidth	;             //��Ƶ��ȣ���λ�����أ�
	CString	CStrYear;             //���
	CString	CStrMovieType;     //��Ƶ���ͣ���������֧�ֵ���չ����wmv/avi/rmvb/rm
	CString	CStrPath	;         //��Ƶȫ·��
	CString	CStrFileName ;    //��Ƶ�ļ��ļ���


int GetSize(char *pcSize[],int* iSizeNum);//��ȡ��С����
int GetMovieBySize(Movie *pstMovie,char *pcSize,int* iPictureNum);//��ȡĳ����С��Χ�����и����ṹ������
int GetYear(char *pcYear[],int* iYearNum);//��ȡ�������
int GetMovieByYear (Movie*pstMovie,char *pcYear,int* iMusicNum);//��ȡĳ����ݵ����и����ṹ������
int GetMovieType(char *pcMovieType[],int* iMovieType);//��ȡͼƬ��������
int GetMovieByMovieType (Movie *pstMovie,char *pcMovieType,int* iMusicNum);//��ȡĳ��ͼƬ���͵����и����ṹ������
int GetPathByID(Movie *pstMovie,char *pcPath,int iID);//��ͨ��ȫ��Picture�ṹ�������±���PictureID����ͨ��MovieID���ͼƬȫ·��
int PlayMovie(char * pcPath);//������Ƶ�ļ�

};
