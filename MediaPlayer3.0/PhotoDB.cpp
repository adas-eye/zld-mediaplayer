#include "StdAfx.h"
#include "PhotoDB.h"
#include "DB.h"
#include "Photo.h"

PhotoDB::PhotoDB(void)
{
}

PhotoDB::~PhotoDB(void)
{
	
}
int PhotoDB::InsertPhoto(Photo clsPhoto)
{
	DB db;
	db.Connect();
	CStringArray csaMaxID;
	CString csSQL;
	db.Select("select top 1 PictureID from PictureTable order by PictureID desc",csaMaxID);	
    db.CloseRecordset();	
	csSQL.Format("insert into PhotoTableb values(%d,%d,%d,'%s','%s','%s','%s','%s')",atoi(csaMaxID.GetAt(0))+1,
		clsPhoto.iLength,clsPhoto.iWidth,clsPhoto.CStrCameraModel,clsPhoto.CStrYear,clsPhoto.CStrPhotoType,clsPhoto.CStrPath,clsPhoto.CStrFileName);
    if(db.Execute(csSQL)==FALSE)
	{
		return 0;
	}
	db.DisConnect();
	return 1;
}

int PhotoDB::UpdatePath(CString csOldPath , CString csNewPath)
{
	DB db;
	db.Connect();
	CString csSQL;
	csSQL.Format("update PhotoTable set Path='%s' where Path='%s'",csNewPath,csOldPath);
    if(db.Execute(csSQL)==FALSE)
	{
		return 0;
	}
	db.DisConnect();
	return 1;
}

int PhotoDB::DeletePhoto(CString csPath)
{
	DB db;
	db.Connect();
	CString csSQL;
	csSQL.Format("delete from PhotoTable where Path='%s' ",csPath);
    if(db.Execute(csSQL)==FALSE)
	{
		return 0;
	}
	db.DisConnect();
	return 1;
}

