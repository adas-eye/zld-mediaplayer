#pragma once

class Movie
{
public:
	Movie(void);
	~Movie(void);
	int	iMovieID	;             //视频文件ID
	int	iTimeLength	;     //视频播放耗时（单位：秒）
	int	iLength	;             //视频长度（单位：像素）
	int	iWidth	;             //视频宽度（单位：像素）
	CString	CStrYear;             //年份
	CString	CStrMovieType;     //视频类型（扩名），支持的扩展名：wmv/avi/rmvb/rm
	CString	CStrPath	;         //视频全路径
	CString	CStrFileName ;    //视频文件文件名


int GetSize(char *pcSize[],int* iSizeNum);//获取大小数组
int GetMovieBySize(Movie *pstMovie,char *pcSize,int* iPictureNum);//获取某个大小范围的所有歌曲结构体数组
int GetYear(char *pcYear[],int* iYearNum);//获取年份数组
int GetMovieByYear (Movie*pstMovie,char *pcYear,int* iMusicNum);//获取某个年份的所有歌曲结构体数组
int GetMovieType(char *pcMovieType[],int* iMovieType);//获取图片类型数组
int GetMovieByMovieType (Movie *pstMovie,char *pcMovieType,int* iMusicNum);//获取某种图片类型的所有歌曲结构体数组
int GetPathByID(Movie *pstMovie,char *pcPath,int iID);//先通过全局Picture结构体数组下标获得PictureID，再通过MovieID获得图片全路径
int PlayMovie(char * pcPath);//播放视频文件

};
