#pragma once
#include "afxwin.h"

class Photo 
{
public:
	Photo(void);
	~Photo(void);
	int	iPictureID;        //ͼƬ�ļ�ID
	int	iLength;            //ͼƬ���ȣ���λ�����أ�
	int	iWidth;            //ͼƬ��ȣ���λ�����أ�
	CString	CStrCameraModel	;//�������
	CString	CStrYear	;            //���
	CString	CStrPhotoType;    //ͼƬ���ͣ���������֧�ֵ���չ����jpg/bmp/png/gif
	CString	CStrPath;        //ͼƬ�ļ�ȫ·��
	CString	CStrFileName;     //ͼƬ�ļ��ļ���


int GetSize(char *pcSize[],int iSizeNum);//��ȡͼƬ��С������
int GetPictureBySize(Picture *pstPicture,char *pcSize,int iPictureNum);//��ȡĳ����С��Χ�����и����ṹ������

int GetYear(char *pcYear[],int iYearNum);//��ȡ�������
int GetPictureByYear (Picture *pstPicture,char *pcYear,int iMusicNum);//��ȡĳ����ݵ����и����ṹ������

int GetCameraModel(char *pcCameraModel [],int iCameraModelNum);//��ȡ�����������
int GetPictureByCameraModel (Picture *pstPicture,char *pcCameraModel,int iMusicNum);//��ȡĳ��������͵����и����ṹ������

int GetPhotoType(char *pcPhotoType [],int iPhotoType);//��ȡͼƬ��������
int GetPictureByPhotoType (Picture *pstPicture,char *pcPhotoType,int iMusicNum);//��ȡĳ��ͼƬ���͵����и����ṹ������

int GetPathByID(Picture *pstPicture,char *pcPath,int iID);//��ͨ��ȫ��Picture�ṹ�������±���PictureID����ͨ��PictureID���ͼƬȫ·��
int PlayPicture(char * pcPath);//���Ų���ͼƬ�ļ�



};
