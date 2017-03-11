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
    vector<vector<string>> examsInfo;
    vector<Student *> students;
    vector<Exam *> exams;
    char *filename = (char *) "../proj/iart.db";
    //char * filename = (char*)"iart.db";
    char *selectStudentQuery = (char *) "SELECT * FROM Student";
    char *selectExamQuery = (char *) "SELECT * FROM Exam";

    // database operations
    db = new Database(filename);
    db->open();
    studentsInfo = db->query(selectStudentQuery);
    examsInfo = db->query(selectExamQuery);

    //read students
    for (vector<vector<string> >::iterator it = studentsInfo.begin(); it < studentsInfo.end(); ++it) {
        vector<string> row = *it;
        int student_id;
        string name;
        stringstream ss;
        for (vector<string>::iterator it2 = (*it).begin(); it2 < (*it).end(); it2++) {
            ss << (*it2);
        }
        ss >> student_id >> name;
        students.push_back(new Student(student_id, name));
    }

    //read exams
    for (vector<vector<string> >::iterator it = examsInfo.begin(); it < examsInfo.end(); ++it) {
        vector<string> row = *it;
        int exam_id;
        string className;
        stringstream ss;
        for (vector<string>::iterator it2 = (*it).begin(); it2 < (*it).end(); it2++) {
            ss << (*it2);
        }
        ss >> exam_id >> className;
        exams.push_back(new Exam(exam_id, className));
    }

    db->close();

    // university initialization
    University university(students,exams);

    //interface
    initialOptions(university);

    //save .db

    return 0;
}
