#ifndef EXAMSCHEDULER_SUBSCRIPTION_H
#define EXAMSCHEDULER_SUBSCRIPTION_H


#include "Exam.h"
#include "Student.h"

class Subscription{

private:
    Exam* exam;
    Student* student;

public:
    Subscription(Student* student, Exam* exam);
    Exam * getExam() const;
    Student * getStudent() const;
};


#endif //EXAMSCHEDULER_SUBSCRIPTION_H


