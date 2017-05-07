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
#include "Algorithm.h"

void subscribe(int id, int student_id);

using namespace std;

int main() {

    //random numbers
    srand ((unsigned int) time(NULL));

    // database variables
    Database *db;
    vector<vector<string>> studentsInfo;
    vector<vector<string>> examsInfo;
    vector<vector<string>> subscribeInfo;
    vector<Student *> students;
    vector<Exam *> exams;
    char *filename = (char *) "../iart.db";         // QT
    //char *filename = (char *) "../proj/iart.db";
    //char * filename = (char*)"iart.db";
    char *selectStudentQuery = (char *) "SELECT * FROM Student";
    char *selectExamQuery = (char *) "SELECT * FROM Exam";
    char *selectSubscribeQuery = (char *) "SELECT * FROM Subscription";

    // database operations
    db = new Database(filename);
    db->open();
    studentsInfo = db->query(selectStudentQuery);
    examsInfo = db->query(selectExamQuery);
    subscribeInfo = db->query(selectSubscribeQuery);

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
        int exam_id, year;
        string className;
        stringstream ss;
        for (vector<string>::iterator it2 = (*it).begin(); it2 < (*it).end(); it2++) {
            ss << (*it2);
        }
        stringstream ss2;
        ss2 << ss.str().at(ss.str().length()-1);
        ss2 >> year;
        ss2.clear();
        ss2.str("");
        string temp = ss.str();
        temp.erase(temp.length()-1);
        ss2 << temp;
        ss2 >> exam_id >> className;
        exams.push_back(new Exam(exam_id, Class(className,year)));
    }

    // university initialization
    University university(students,exams);
    //criacao das epocas (nome + numero de dias)
    Epoch * e = new Epoch("Normal",15);
    university.addEpoch(e);

    //read subscribes
    for (vector<vector<string> >::iterator it = subscribeInfo.begin(); it < subscribeInfo.end(); ++it) {
        vector<string> row = *it;
        int exam_id = 0, student_id = 0, epoch_id = 0;
        char c;
        stringstream ss;
        for (vector<string>::iterator it2 = (*it).begin(); it2 < (*it).end(); it2++) {
            ss << (*it2) << ",";
        }
        ss >> epoch_id >> c >> exam_id >> c >> student_id;
        university.addSubscription(epoch_id,exam_id,student_id);
    }

    db->close();

    //interface
    //initialOptions(university);

    Algorithm algorithm(e,20);
    algorithm.run();

    //save .db

    return 0;
}
