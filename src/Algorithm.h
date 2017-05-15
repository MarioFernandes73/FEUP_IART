//
// Created by gomes on 22/03/2017.
//

#ifndef EXAMSCHEDULER_ALGORITHM_H
#define EXAMSCHEDULER_ALGORITHM_H

#include "Epoch.h"

using namespace std;

class Algorithm {
private:
    Epoch *epoch;
    vector<Schedule *> population;
    int populationLength;
    int maxSlots;
public:
    Algorithm(Epoch *epoch, int populationLength);
    void populate(vector<Exam *> exams);
    Schedule * createRandomSchedule(vector<Exam *> exams);
    static vector<Exam *> randomExams(vector<Exam *> exams);

    void run();

    void calculateFitness();
    int getPopulationFitness();
    void createRandomProbs(double * randomProbs,int i);

    void selectNextPopulation();
    vector<Schedule *> selectElitistPopulation();
    void fitnessProbabilities(int populationFitness);
    void selectRemainingPopulation(double pDouble[], vector<Schedule *> vector);

    void crossover();
    vector<Schedule *> selectCrossoverPopulation();

    void mutation();

    int getBestSchedule(vector<Schedule *> schedules);

    void executeCrossover(vector<Schedule *> vector);


    vector<pair<Exam *, int>> createMap(vector<pair<Exam *, int>> map1, vector<pair<Exam *, int>> map2, int pos);

};

#endif //EXAMSCHEDULER_ALGORITHM_H
