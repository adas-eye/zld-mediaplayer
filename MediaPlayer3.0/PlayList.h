#pragma once


class PlayList
{
public:
	PlayList(void);
	~PlayList(void);
	int	iPlayListID	;           //�����б�ID
	CString	CStrPlayListName;	   //�����б�����
    

int InsertPlayList(struct PlayList *playlist);//�½������б�
int SelectPlayList(char **PlayList,int *length);//���Ҳ����б�
int UpdatePlayList(char *PlayListName);//���²����б�
int DeletePlayList(char *PlayListName);//ɾ�������б�


};
