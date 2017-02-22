//============================================================================
// Name        : IART.cpp
// Author      : Catarina Ramos, Inês Gomes and Mário Fernandes
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>

#include "sqlite3.h"
#include "University.h"
#include "Menu.h"
using namespace std;

int main() {

	//declare variables
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc = sqlite3_open("iart.db", &db);

	//initialize University
	University university;

	// load .db
	if(rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return 0;
	}
	else
	{
		fprintf(stderr, "Opened database successfully\n");
	}


	//interface
	initialOptions(university);

	//save .db


	sqlite3_close(db);
	return 0;
}
