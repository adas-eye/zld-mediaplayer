#pragma once

class PlayItem
{
public:
	PlayItem(void);
	~PlayItem(void);
	int	iPlayItemID	;           //�����ļ�ID
	CString	CStrPlayItemDate;   //��������
	int	iFlag	;               //�Ƿ�����ļ���0��ʾ�����ڣ�1��ʾ���ڣ�
	CString	CStrPath;           //�����ļ�ȫ·��
	CString	CStrFileName;       //�����ļ��ļ���
	int	iPlayListID;	           //�����б�ID

int GetMediaFromPlayList(struct	PlayItem **playItem,int *length);//��ȡ�����б��µ�ý��
int InsertMediaToPlayList(struct PlayItem *mediaItem,struct PlayList *playlist);//�����б��²���ý���ļ�


};
