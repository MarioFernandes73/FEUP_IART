/*
 * Database.h
 *
 *  Created on: 22 Feb 2017
 *
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <vector>
#include <string>

#include "sqlite3.h"

class Database {
private:
	sqlite3 *database;
	char * filename;
public:
	Database(char * filename);
	virtual ~Database(){}

	bool open();
	void close();
	std::vector<std::vector <std::string>> query(char * query);
};

#endif /* DATABASE_H_ */
