//
// Created by gomes on 23/03/2017.
//

#include "Epoch.h"

int Epoch::currentId = 1;

Epoch::Epoch(std::string name, int numDays)
{
    this->schoolYear = name;
    this->numDays = numDays;
    this->id = currentId;
    currentId++;
}

int Epoch::getNumdays() const{
    return this->numDays;
}

std::string Epoch::getName() const{
    return this->schoolYear;
}

int Epoch::getId() const{
    return id;
}

void Epoch::addSubscription(Subscription *s) {
    subs.push_back(s);
}

/*
void Epoch::setSchedule(Schedule *pSchedule) {
    this->global = pSchedule;
}
 */

std::vector<Subscription *> Epoch::getSubscriptions() const {
    return this->subs;
}

vector<Student *> Epoch::getStudents(Exam *e) const {
    vector<Student *> students;

    for (int i = 0; i < subs.size(); ++i)
    {
        Student *s = subs.at(i)->getStudent();
        if(subs.at(i)->getExam() == e)
            if(notFound(students,s))
                students.push_back(s);
    }
    return students;
}

std::vector<Exam *> Epoch::getExams() const {
    vector<Exam *> exams;

    for (int i = 0; i < subs.size(); ++i)
    {
        Exam *e = subs.at(i)->getExam();
        if(notFound(exams, e))
            exams.push_back(e);
    }
    return exams;
}

template<typename T>
bool Epoch::notFound(vector<T *> vector, T *temp) const {
    for (int i = 0; i < vector.size(); ++i)
        if(vector.at(i) == temp)
            return false;
    return true;
}

