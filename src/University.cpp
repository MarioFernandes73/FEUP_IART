/*
 * University.cpp
 *
 *  Created on: 21 Feb 2017
 *
 */

#include <vector>

#include "University.h"
#include "MyExceptions.h"
#include "Epoch.h"

#include <iostream>

using namespace std;

University::University(vector<Student *> students, vector<Exam *> exams) {
    this->students = students;
    this->exams = exams;
}

vector<Student *> University::getStudents() {
    return this->students;
}

Student *University::findStudent(Student *tempStudent) {

    for (vector<Student *>::iterator it = this->students.begin(); it != this->students.end(); it++) {
        if ((**it) == tempStudent) {
            return (*it);
        }
    }

    throw elementNotInVectorException<Student *>(tempStudent);

    return NULL;
}

void University::addStudent(Student *newStudent) {
    this->students.push_back(newStudent);
    return;
}

void University::removeStudent(Student *oldStudent) {
    for (vector<Student *>::iterator it = this->students.begin(); it != this->students.end(); it++) {
        if ((**it) == oldStudent) {
            this->students.erase(it);
            return;
        }
    }
    throw elementNotInVectorException<Student *>(oldStudent);
}

void University::addExam(Exam *newExam) {
    this->exams.push_back(newExam);
    return;
}

vector<Exam *> University::getExams() {
    return this->exams;
}

Exam *University::findExam(Exam *tempExam) {

    for (vector<Exam *>::iterator it = this->exams.begin(); it != this->exams.end(); it++) {
        if ((**it) == tempExam) {
            return (*it);
        }
    }

    throw elementNotInVectorException<Exam *>(tempExam);

    return NULL;
}

void University::removeExam(Exam *oldExam) {
    for (vector<Exam *>::iterator it = this->exams.begin(); it != this->exams.end(); it++) {
        if ((**it) == oldExam) {
            this->exams.erase(it);
            return;
        }
    }
    throw elementNotInVectorException<Exam *>(oldExam);
}

void University::addEpoch(Epoch * e) {
    epochs.push_back(e);
}

Epoch * University::getEpochByName(string name)
{
    for (int i = 0; i < epochs.size(); ++i) {
      if(name == epochs.at(i)->getName())
          return epochs.at(i);
    }
    return NULL;
}

void University::addSubscription(int epochId, int examId, int studentId)
{
    Exam *e = findById(exams,examId);
    Student *s = findById(students,studentId);
    Epoch *epoch = findById(epochs,epochId);

    epoch->addSubscription(new Subscription(s,e));
}

template<typename T>
T* University::findById(vector<T*> vec, int id)
{
    for (int i = 0; i < vec.size(); ++i)
        if(vec.at(i)->getId() == id)
            return vec.at(i);
    return nullptr;
}