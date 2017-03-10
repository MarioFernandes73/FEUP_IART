//============================================================================
// Name        : IART.cpp
// Author      : Catarina Ramos, Ines Gomes and Mario Fernandes
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <sstream>

#include "Database.h"
#include "University.h"
#include "Menu.h"
using namespace std;


int main() {

	// database variables
	Database *db;
	vector<vector<string>> studentsInfo;
	vector<Student *> students;
	char * filename = (char*)"../proj/iart.db";
	//char * filename = (char*)"iart.db";
	char * selectStudentQuery = (char*)"SELECT * FROM Student";

	// database operations
	db = new Database(filename);
	db->open();
	studentsInfo = db->query(selectStudentQuery);

	for(vector<vector<string> >::iterator it = studentsInfo.begin(); it < studentsInfo.end(); ++it)
	{
		vector<string> row = *it;
		int student_id;
		string name;
		stringstream ss;
		for(vector<string>::iterator it2 = (*it).begin(); it2 < (*it).end(); it2++)
		{
			ss << (*it2);
		}
		ss >> student_id >> name;
		students.push_back(new Student(student_id, name));
	}

	db->close();


	// university initialization
	University university(students);

	//interface
	initialOptions(university);

	//save .db

	return 0;
}
