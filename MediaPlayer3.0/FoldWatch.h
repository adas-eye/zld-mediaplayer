#pragma once
#include<vector>
#include<iostream>
#include<string>
using namespace std;
class FoldWatch
{
public:
	FoldWatch(void);
	~FoldWatch(void);
	int DirectoryList(const char *path);//�����ļ��������ý���ļ�
	int AnalyMusic(char *music);
	int MediaType(char *music);//������Ƶ�ļ�������
	vector<string> GetFoldFileList();  //����ַ�������
	void PrintFoidList();////����ļ����µ�ý�����·��
    int InsertMedia();//
	vector<string> fileVector;
private:
   
};
