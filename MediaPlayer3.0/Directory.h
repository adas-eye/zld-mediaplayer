#pragma once

class Directory
{
public:
	Directory(void);
	~Directory(void);

int SetDefaultDir(char **pcPath,int* piLength,char * pcDirectory);//��ȱ���Ŀ¼�ļ�
int AnalyseMedia(char *pcPath[],int iLength);//�����ļ�
int AnalyseMusic(char *path);//������Ƶ,���ýӿڣ�����
int AnalysePhoto(char *path);//����ͼƬ,���ýӿڣ�����
int AnalyseVideo(char *path);//������Ƶ,���ýӿڣ�����

};
