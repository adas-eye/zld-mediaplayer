#pragma once
#include "afxwin.h"

class Photo 
{
public:
	Photo(void);
	~Photo(void);
	int	iPictureID;        //图片文件ID
	int	iLength;            //图片长度（单位：像素）
	int	iWidth;            //图片宽度（单位：像素）
	CString	CStrCameraModel	;//相机类型
	CString	CStrYear	;            //年份
	CString	CStrPhotoType;    //图片类型（扩名），支持的扩展名：jpg/bmp/png/gif
	CString	CStrPath;        //图片文件全路径
	CString	CStrFileName;     //图片文件文件名


int GetSize(char *pcSize[],int iSizeNum);//获取图片大小的数组
int GetPictureBySize(Picture *pstPicture,char *pcSize,int iPictureNum);//获取某个大小范围的所有歌曲结构体数组

int GetYear(char *pcYear[],int iYearNum);//获取年份数组
int GetPictureByYear (Picture *pstPicture,char *pcYear,int iMusicNum);//获取某个年份的所有歌曲结构体数组

int GetCameraModel(char *pcCameraModel [],int iCameraModelNum);//获取相机类型数组
int GetPictureByCameraModel (Picture *pstPicture,char *pcCameraModel,int iMusicNum);//获取某个相机类型的所有歌曲结构体数组

int GetPhotoType(char *pcPhotoType [],int iPhotoType);//获取图片类型数组
int GetPictureByPhotoType (Picture *pstPicture,char *pcPhotoType,int iMusicNum);//获取某种图片类型的所有歌曲结构体数组

int GetPathByID(Picture *pstPicture,char *pcPath,int iID);//先通过全局Picture结构体数组下标获得PictureID，再通过PictureID获得图片全路径
int PlayPicture(char * pcPath);//播放播放图片文件



};
