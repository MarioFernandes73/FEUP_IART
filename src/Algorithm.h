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
    int maxSlots;
public:
    Algorithm(University u, int populationLength);
    void populate(std::vector<Exam *> exams);
    Schedule * createRandomSchedule(std::vector<Exam *> exams);

    void run();

    void calculateFitness();
    int getPopulationFitness();
    int getBestSchedule(vector<Schedule *> schedules);
    void createRandomProbs(double * randomProbs,int i);

    void selectNextPopulation();
    vector<Schedule *> selectElitistPopulation();
    void fitnessProbabilities(int populationFitness);
    void selectRemainingPopulation(double pDouble[], vector<Schedule *> vector);

    void crossover();
    vector<Schedule *> selectCrossoverPopulation();
    void executeCrossover(vector<Schedule *> vector);
    vector<pair<Exam *, int>> createMap(vector<pair<Exam *, int>> map1, vector<pair<Exam *, int>> map2, int pos);
};


#endif //EXAMSCHEDULER_ALGORITHM_H
