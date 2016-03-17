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
        //printf("����ʧ��\n");
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
		//printf("%d %s\n",FileCount,FullPathName);//����ļ���  ��Ŀ�;���·��
		if((fileinfo.attrib & _A_SUBDIR)==_A_SUBDIR)//�ж��Ƿ����ļ���
		{
			//printf("<dir>\n");
			DirectoryList(FullPathName);
		}
		else //�����ļ������ж��ļ�
		{
		   if(MediaType(FullPathName))//�ж��Ƿ�Ϊý���ļ�
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



////����ļ����µ�ý�����·��
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
���ܣ�������Ƶ�ļ�������
����������׺���ļ���
����ֵ��mp3��ʽ����1��wma��ʽ����2���������ͷ���0
*/
int FoldWatch::MediaType(char *music)//������Ƶ�ļ�������
{
	char *type=NULL;
	type=strchr(music,'.');//��������һ��ָ�룬��ָ���ַ�ch���ַ���strĩ�γ��ֵ�λ�ã����ƥ��ʧ�ܣ��򷵻�NULL
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
