#pragma once

class RecentList
{
public:
	RecentList(void);
	~RecentList(void);
	int	iRecentID	;              //��������ļ�ID
	CString	CStrPlayDate	;      //��������
	int	iFlag	;              //�Ƿ�����ļ���0��ʾ�����ڣ�1��ʾ���ڣ�
	CString	CStrPath	;          //��������ļ�ȫ·��
	CString	CStrFileName ;    //��������ļ��ļ���


int GetRecentTable(struct	RecentList **RecentList , int *length);//��ȡ��������б�
int InsertRecentTable(struct	RecentList *  STRecent);//������������б�
int UpdateRecentTable(struct	RecentList *  STRecent);//������������б�

};
