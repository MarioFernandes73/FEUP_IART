//
// Created by gomes on 22/03/2017.
//

#ifndef EXAMSCHEDULER_ALGORITHM_H
#define EXAMSCHEDULER_ALGORITHM_H

#include "Schedule.h"
#include "University.h"

#define HOURS_PER_DAY 8;
#define REPETITIONS 10;

class Algorithm {
private:
    std::vector<Schedule *> population;
    int populationLength;
public:
    Algorithm(University u, int populationLength);
    void populate(std::vector<Exam *> exams, int maxSlots);
    Schedule * createRandomSchedule(std::vector<Exam *> exams, int slots);

    void run();

    void calculateFitness();
};


#endif //EXAMSCHEDULER_ALGORITHM_H
