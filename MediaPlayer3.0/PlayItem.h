#pragma once

class PlayItem
{
public:
	PlayItem(void);
	~PlayItem(void);
	int	iPlayItemID	;           //播放文件ID
	CString	CStrPlayItemDate;   //播放日期
	int	iFlag	;               //是否存在文件（0表示不存在，1表示存在）
	CString	CStrPath;           //播放文件全路径
	CString	CStrFileName;       //播放文件文件名
	int	iPlayListID;	           //播放列表ID

int GetMediaFromPlayList(struct	PlayItem **playItem,int *length);//获取播放列表下的媒体
int InsertMediaToPlayList(struct PlayItem *mediaItem,struct PlayList *playlist);//播放列表下插入媒体文件


};
