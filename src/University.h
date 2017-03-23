/*
 * University.h
 *
 *  Created on: 21 Feb 2017
 *     
 */

#ifndef UNIVERSITY_H_
#define UNIVERSITY_H_

#include "Student.h"
#include "Schedule.h"
#include "Epoch.h"
#include <string>

class University {
private:
    Schedule globalSchedule;
    std::string name;
    std::vector<Student *> students;
    std::vector<Exam *> exams;
    std::vector<Epoch *> epochs;
public:
    University(std::vector<Student *> students,std::vector<Exam *> exams);
    virtual ~University() {}

    void addEpoch(Epoch * e);

    std::vector<Student *> getStudents();
    Student *findStudent(Student *tempStudent);
    void addStudent(Student *newStudent);
    void removeStudent(Student *oldStudent);

    std::vector<Exam *> getExams();
    Exam *findExam(Exam *tempExam);
    void addExam(Exam *newExam);
    void removeExam(Exam *oldExam);

    Epoch * getEpochByName(std::string name);
};

#endif /* UNIVERSITY_H_ */
