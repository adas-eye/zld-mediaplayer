#pragma once

class Directory
{
public:
	Directory(void);
	~Directory(void);

int SetDefaultDir(char **pcPath,int* piLength,char * pcDirectory);//深度遍历目录文件
int AnalyseMedia(char *pcPath[],int iLength);//解析文件
int AnalyseMusic(char *path);//解析音频,调用接口，插入
int AnalysePhoto(char *path);//解析图片,调用接口，插入
int AnalyseVideo(char *path);//解析视频,调用接口，插入

};
