#pragma once
#include "Movie.h"
class MovieDB
{
public:
	MovieDB(void);
	~MovieDB(void);
	int InsertMovie(Movie clsMovie);
	int UpdatePath(CString csOldPath , CString csNewPath);
	int DeleteMovie(CString csPath);
};
