#include "StdAfx.h"
#include "MovieDB.h"
#include "DB.h"
#include "Movie.h"

MovieDB::MovieDB(void)
{
}

MovieDB::~MovieDB(void)
{
}

int MovieDB::InsertMovie(Movie clsMovie)
{
	DB db;
	db.Connect();
	CString csSQL;
	CStringArray csaMaxID;
	db.Select("select top 1 MovieID from MovieTable order by MovieID desc",csaMaxID);	
    db.CloseRecordset();
	csSQL.Format("insert into MovieTable values(,%d,%d,%d,%d,'%s','%s','%s','%s')",atoi(csaMaxID.GetAt(0))+1,
		clsMovie.iTimeLength,clsMovie.iLength,clsMovie.iWidth,clsMovie.CStrYear,clsMovie.CStrMovieType,clsMovie.CStrPath,clsMovie.CStrFileName);
    if(db.Execute(csSQL)==FALSE)
	{
		return 0;
	}
	db.DisConnect();
	return 1;
}

int MovieDB::UpdatePath(CString csOldPath , CString csNewPath)
{
	DB db;
	db.Connect();
	CString csSQL;
	csSQL.Format("update MovieTable set Path='%s' where Path='%s'",csNewPath,csOldPath);
    if(db.Execute(csSQL)==FALSE)
	{
		return 0;
	}
	db.DisConnect();
	return 1;
}

int MovieDB::DeleteMovie(CString csPath)
{
	DB db;
	db.Connect();
	CString csSQL;
	csSQL.Format("delete from MovieTable where Path='%s' ",csPath);
    if(db.Execute(csSQL)==FALSE)
	{
		return 0;
	}
	db.DisConnect();
	return 1;
}

