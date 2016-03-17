#include "StdAfx.h"
#include "MusicDB.h"
#include "DB.h"
#include "Music.h"

MusicDB::MusicDB(void)
{
}

MusicDB::~MusicDB(void)
{
}

int MusicDB::InsertMusic(Music &clsMusic)
{
	DB db;
	db.Connect();
	CStringArray csaMaxID;
	CString csSQL;
	db.Select("select top 1 MusicID from MusicTable order by MusicID desc",csaMaxID);	
    db.CloseRecordset();	
	csSQL.Format("insert into MusicTable  values(%d,'%s','%s','%s','%s','%s','%s')",atoi(csaMaxID.GetAt(0))+1,
		clsMusic.CStrArtist,clsMusic.CStrAlbum,clsMusic.CStrGenre,clsMusic.CStrYear,clsMusic.CStrPath,clsMusic.CStrFileName);
    if(db.Execute(csSQL)==FALSE)
	{
		return 0;
	}
	db.DisConnect();
	return 1;
}

int MusicDB::UpdatePath(CString csOldPath , CString csNewPath)
{
	DB db;
	db.Connect();
	CString csSQL;
	csSQL.Format("update MusicTable set Path='%s' where Path='%s'",csNewPath,csOldPath);
    if(db.Execute(csSQL)==FALSE)
	{
		return 0;
	}
	db.DisConnect();
	return 1;
}

int MusicDB::DeleteMusic(CString csPath)
{
	DB db;
	db.Connect();
	CString csSQL;
	csSQL.Format("delete from MusicTable where Path='%s' ",csPath);
    if(db.Execute(csSQL)==FALSE)
	{
		return 0;
	}
	db.DisConnect();
	return 1;
}
