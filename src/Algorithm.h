#ifndef EXAMSCHEDULER_ALGORITHM_H
#define EXAMSCHEDULER_ALGORITHM_H

#include "Epoch.h"

using namespace std;

class Algorithm
{
protected:
    Epoch *epoch;
    int maxSlots;
    bool debug;
public:
    Algorithm(Epoch *epoch, bool debug);
    Schedule * createRandomSchedule(vector<Exam *> exams);
    static Schedule * createRandomSchedule(bool debug,Epoch *epoch);
    static vector<Exam *> randomExams(vector<Exam *> exams);
    virtual void run();
};

#endif //EXAMSCHEDULER_ALGORITHM_H
