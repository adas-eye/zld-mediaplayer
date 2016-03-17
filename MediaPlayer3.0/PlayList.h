#pragma once


class PlayList
{
public:
	PlayList(void);
	~PlayList(void);
	int	iPlayListID	;           //播放列表ID
	CString	CStrPlayListName;	   //播放列表名称
    

int InsertPlayList(struct PlayList *playlist);//新建播放列表
int SelectPlayList(char **PlayList,int *length);//查找播放列表
int UpdatePlayList(char *PlayListName);//更新播放列表
int DeletePlayList(char *PlayListName);//删除播放列表


};
