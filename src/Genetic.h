#ifndef GENETIC_H
#define GENETIC_H

#include "Algorithm.h"

using namespace std;

class Genetic : public Algorithm {
private:
    int populationLength;
    vector<Schedule *> population;
public:
    Genetic(Epoch *epoch, int populationLength);
    void run();

    void populate(vector<Exam *> exams);
    void calculateFitness();
    int getPopulationFitness();
    void createRandomProbs(double * randomProbs,int i);
    void selectNextPopulation();
    vector<Schedule *> selectElitistPopulation();
    void fitnessProbabilities(int populationFitness);
    void selectRemainingPopulation(double pDouble[], vector<Schedule *> vector);
    void crossover();
    void executeCrossover(vector<Schedule *> vector);
    vector<Schedule *> selectCrossoverPopulation();
    void mutation();
    int getBestSchedule(vector<Schedule *> schedules);
    vector<pair<Exam *, int>> createMap(vector<pair<Exam *, int>> map1, vector<pair<Exam *, int>> map2, int pos);
};
#endif // GENETIC_H
