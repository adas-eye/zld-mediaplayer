#include "stdafx.h"
#include "FoldWatch.h"
#include<io.h>


FoldWatch::FoldWatch(void)
{
}

FoldWatch::~FoldWatch(void)
{
}


int FoldWatch::DirectoryList(const char *path)
{
	int type=0;
	long handle;
	struct _finddata_t fileinfo;
	int  FileCount=0;
	char FilePathName[512];
	char FullPathName[512];
	int len=1;

	strcpy(FilePathName,path);
	strcat(FilePathName,"\\*.*");

	handle=_findfirst(FilePathName,&fileinfo);
	if(-1==handle)
	{
        //printf("搜索失败\n");
		return -1;
	}
	//printf("%s\n",fileinfo.name);
	while(!_findnext(handle,&fileinfo))
	{
		if(strcmp(fileinfo.name,".")==0||strcmp(fileinfo.name,"..")==0)
		{
			continue;
		}
		FileCount++;
		sprintf(FullPathName,"%s\\%s",path,fileinfo.name);	
		//printf("%d %s\n",FileCount,FullPathName);//输出文件的  数目和绝对路径
		if((fileinfo.attrib & _A_SUBDIR)==_A_SUBDIR)//判断是否问文件夹
		{
			//printf("<dir>\n");
			DirectoryList(FullPathName);
		}
		else //不是文件夹则判断文件
		{
		   if(MediaType(FullPathName))//判断是否为媒体文件
		   {
		     fileVector.push_back(FullPathName);
		   }
		   else
		   {
			   ;
		   }
		}
		
	}
	_findclose(handle);
	return 1;

}

int FoldWatch::AnalyMusic(char *music)
{
	return 0;
}

vector<string> FoldWatch::GetFoldFileList()
{

	return fileVector;
}



////输出文件夹下的媒体绝对路径
void FoldWatch::PrintFoidList()
{
  vector<string>::iterator c1_Iter;
  c1_Iter = fileVector.begin();
	for (; c1_Iter != fileVector.end(); c1_Iter++) 
	{
		cout << *c1_Iter << endl;
	}
}

/*
功能：解析音频文件的类型
参数：带后缀的文件名
返回值：mp3格式返回1，wma格式返回2，其他类型返回0
*/
int FoldWatch::MediaType(char *music)//解析音频文件的类型
{
	char *type=NULL;
	type=strchr(music,'.');//函数返回一个指针，他指向字符ch在字符串str末次出现的位置，如果匹配失败，则返回NULL
	if(type!=NULL)
	{
		if(strcmp(type,".mp3")==0)
		{
			return 1;
		}
		else if(strcmp(type,".wma")==0)
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}


/*

int FoldWatch::InsertMedia()
{
 	
	return 0;
}*/
