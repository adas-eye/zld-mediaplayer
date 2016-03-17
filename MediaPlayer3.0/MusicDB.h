#pragma once
#include "Music.h"
class MusicDB
{
public:
	MusicDB(void);
	~MusicDB(void);
	int InsertMusic(Music &clsMusic);
	int UpdatePath(CString csOldPath , CString csNewPath);
	int DeleteMusic(CString csPath);
};
