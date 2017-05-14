//
// Created by gomes on 22/03/2017.
//

#ifndef EXAMSCHEDULER_ALGORITHM_H
#define EXAMSCHEDULER_ALGORITHM_H

#include "Epoch.h"

using namespace std;

class Algorithm
{
protected:
    Epoch *epoch;
    int maxSlots;
public:
    Algorithm(Epoch *epoch);
    Schedule * createRandomSchedule(vector<Exam *> exams);
    static vector<Exam *> randomExams(vector<Exam *> exams);
    virtual void run();
};

#endif //EXAMSCHEDULER_ALGORITHM_H
