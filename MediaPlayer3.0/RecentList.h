#pragma once

class RecentList
{
public:
	RecentList(void);
	~RecentList(void);
	int	iRecentID	;              //最近播放文件ID
	CString	CStrPlayDate	;      //播放日期
	int	iFlag	;              //是否存在文件（0表示不存在，1表示存在）
	CString	CStrPath	;          //最近播放文件全路径
	CString	CStrFileName ;    //最近播放文件文件名


int GetRecentTable(struct	RecentList **RecentList , int *length);//获取最近播放列表
int InsertRecentTable(struct	RecentList *  STRecent);//插入最近播放列表
int UpdateRecentTable(struct	RecentList *  STRecent);//更新最近播放列表

};
