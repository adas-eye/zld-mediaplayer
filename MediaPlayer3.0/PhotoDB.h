#pragma once
#include "PhotoDB.h"
#include "DB.h"
#include "Photo.h"

class PhotoDB
{
public:
	PhotoDB(void);
	~PhotoDB(void);
	int InsertPhoto(Photo clsPhoto);
	int UpdatePath(CString csOldPath , CString csNewPath);
	int DeletePhoto(CString csPath);
};
