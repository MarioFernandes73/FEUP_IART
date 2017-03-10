/*
 * Interaction.cpp
 *
 *  Created on: 21 Feb 2017
 *
 */

#include <string>
#include <iostream>

#include "Interaction.h"
#include "University.h"
#include "Auxiliary.h"

using namespace std;

Student *createStudent() {
    string name;

    cout << "Please insert the student's name: ";
    getline(cin, name);

    return new Student(name);
}

void editStudent(Student *student) {

    cout << "Would you like to edit " << student->getName() << "'s name?" << endl;
    if (confirm()) {
        string name;
        cout << "Please insert the student's name: ";
        getline(cin, name);
        student->setName(name);
    }
    return;
}

bool confirmDeleteStudent(Student *student) {
    cout << "You are about to delete" << student->getName() << endl;
    return confirm();
}

void printStudents(vector<Student *> students) {
    for (vector<Student *>::iterator it = students.begin(); it < students.end(); it++) {
        cout << (*it)->getInfo();
    }

}

Exam *createExam() {
    string name;

    cout << "Please insert the exam's class name: ";    //temporario
    getline(cin, name);

    return new Exam(name);
}

void printExams(vector<Exam *> exams) {
    for (vector<Exam *>::iterator it = exams.begin(); it < exams.end(); it++) {
        cout << (*it)->getInfo();
    }
}

void editExam(Exam *exam) {

    cout << "Would you like to edit " << exam->getClassName() << "'s name?" << endl;
    if (confirm()) {
        string name;
        cout << "Please insert the exam's name: ";
        getline(cin, name);
        exam->setClassName(name);
    }
    return;
}