#include "Subscription.h"

Subscription::Subscription(Student *student, Exam *exam) {
    this->student = student;
    this->exam = exam;
}

Exam *Subscription::getExam() const {
    return exam;
}

Student *Subscription::getStudent() const {
    return student;
}
