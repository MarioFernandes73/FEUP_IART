/*
 * Database.cpp
 *
 *  Created on: 22 Feb 2017
 *      Author: M�rio
 */

#include "Database.h"
#include <iostream>

using namespace std;

Database::Database(char * filename)
{
	this->database = NULL;
	this->filename = filename;
}

bool Database::open()
{
	if(sqlite3_open(filename, &database) == SQLITE_OK)
		return true;
	return false;
}

void Database::close()
{
	sqlite3_close(database);
}

vector<vector<string> > Database::query(char* query)
{
    sqlite3_stmt *statement;
    vector<vector<string> > results;
    if(sqlite3_prepare_v2(database, query, -1, &statement, 0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(statement);
        int result = 0;
        while(true)
        {
            result = sqlite3_step(statement);
            if(result == SQLITE_ROW)
            {
                vector<string> values;
                for(int col = 0; col < cols; col++)
                {
                    values.push_back((char*)sqlite3_column_text(statement, col));
                }
               results.push_back(values);
            }
            else
            {
                break;
            }
        }
        sqlite3_finalize(statement);
    }
    string error = sqlite3_errmsg(database);
    if(error != "not an error") cout << query << " " << error << endl;
    return results;
}

