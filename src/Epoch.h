//
// Created by gomes on 23/03/2017.
//

#ifndef EXAMSCHEDULER_EPOCH_H
#define EXAMSCHEDULER_EPOCH_H

#include <string>
#include "Schedule.h"

class Epoch {
private:
    int id;
    static int currentId;
    std::string schoolYear;
    int semester;
    std::string epoch;
    //begin and end date
    int numDays;
    Schedule *global;
    std::vector<Subscription *> subs;
public:
    Epoch(std::string name, int numDays);
    int getNumdays() const;
    std::string getName() const;
    int getId() const ;
    std::vector<Exam *> getExams() const;
    std::vector<Subscription *> getSubscriptions() const;
//    void setSchedule(Schedule *newSched);

    void addSubscription(Subscription *s);
    template<typename T>
    bool notFound(vector<T *> vector, T *temp) const;

    bool commonStudents(Exam *pExam, Exam *pExam1);

    vector<Student *> getStudents(Exam *pExam) const ;
};


#endif //EXAMSCHEDULER_EPOCH_H
