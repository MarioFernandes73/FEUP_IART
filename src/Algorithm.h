//
// Created by gomes on 22/03/2017.
//

#ifndef EXAMSCHEDULER_ALGORITHM_H
#define EXAMSCHEDULER_ALGORITHM_H

#include "Schedule.h"
#include "University.h"

class Algorithm {
private:
    std::vector<Schedule *> population;
    int populationLength;
public:
    Algorithm(University u, int populationLength);
    void populate(std::vector<Exam *> exams, int maxSlots);
    Schedule * createRandomSchedule(std::vector<Exam *> exams, int slots);

    void run();

    int calculateFitness();
    void selectNextPopulation(int popFitness);
    vector<Schedule *> selectElitistPopulation();

    void fitnessProbabilities(int populationFitness);

    void selectRemainingPopulation(double pDouble[], vector<Schedule *> vector);
};


#endif //EXAMSCHEDULER_ALGORITHM_H
