#ifndef GENETIC_H
#define GENETIC_H

#include "Algorithm.h"
#include "Statistics.h"

using namespace std;

class Genetic : public Algorithm {
private:
    int numReps;
    int populationLength;
    vector<Schedule *> population;
    vector<Schedule *> elitistPop;
    GStatistics * statistics;
public:
    Genetic(Epoch *epoch, bool debug, int populationLength, vector<Schedule *> pop, int numReps);
    Genetic(Epoch *epoch, bool debug, int populationLength, int numReps);

    void run();

    void populate(vector<Exam *> exams);
    static vector<Schedule *> populate(Epoch *e, int poplength, bool debug);
    void calculateFitness();
    void static calculateFitness(vector<Schedule *> population);
    int getPopulationFitness();
    int static calculatePopulationFitness(vector<Schedule *> population);
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
    GStatistics * getStatistics(){return this->statistics;}
};
#endif // GENETIC_H
