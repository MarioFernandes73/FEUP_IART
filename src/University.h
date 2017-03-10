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

class University {
private:
    Schedule globalSchedule;
    std::string name;
    std::vector<Student *> students;
    std::vector<Exam *> exams;
public:
    University(std::vector<Student *> students);
    virtual ~University() {}

    std::vector<Student *> getStudents();
    Student *findStudent(Student *tempStudent);
    void addStudent(Student *newStudent);
    void removeStudent(Student *oldStudent);

    std::vector<Exam *> getExams();
    Exam *findExam(Exam *tempExam);
    void addExam(Exam *newExam);
    void removeExam(Exam *oldExam);

};

#endif /* UNIVERSITY_H_ */
