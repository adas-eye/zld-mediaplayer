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
	int DirectoryList(const char *path);//遍历文件夹下面的媒体文件
	int AnalyMusic(char *music);
	int MediaType(char *music);//解析音频文件的类型
	vector<string> GetFoldFileList();  //获得字符串数组
	void PrintFoidList();////输出文件夹下的媒体绝对路径
    int InsertMedia();//
	vector<string> fileVector;
private:
   
};
