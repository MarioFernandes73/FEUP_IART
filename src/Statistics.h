#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include "Utils.h"
#include <sstream>
using namespace std;

class Statistics {
protected:
    vector<float> iterationsTimes;
    vector<float> bestFitness;
    clock_t iterationTimer;
    clock_t algorithmTimer;
    float algorithmExecTime;

    //Algortihm
    AlgorithmType algorithm;
public:
    Statistics(AlgorithmType algorithm);
    void startIteration();
    void startAlgorithm();
    void endIteration(float best);
    void endAlgorithm();
    virtual string displayStatistics() const;
};

class SAStatistics: public Statistics{
protected:
    //SimulatedAnnealing
    vector<bool> worstAccepted; //records if a worstSolution was accepted
    int schedulesGenerated = 1;
    int schedulesAboveCurrent = 0;  //Number of schedules that have the fitness above the current fitness

public:
    SAStatistics();
    //Simulated Annealing
    void addWorst(float probability, float random);
    void addSchedulesGenerated();
    void addScheduleAboveCurrent();
    string displayStatistics() const;

};

class GStatistics : public Statistics{
protected:
    //Genetic
    clock_t stageTimer;
    int populationN;

    vector<int> bestEliteFitness;
    vector<int> worstEliteFitness;    //initial
    vector<int> populationFitness;    //initial

    vector<int> mutationN;

    vector<int> fitnessSelection;   //fitness after stage
    vector<int> fitnessCrossover;
    vector<int> fitnessMutation;

    float populateTime;                 //algorithm stages
    vector<float> selectionTimes;
    vector<float> crossoverTimes;
    vector<float> mutationTimes;

public:
    GStatistics();
    //Genetic
    void startStage();
    void endStage(GeneticStages stage);
    void addBestSpeciment(int fitness);
    void addBestElite(int fitness);
    void addWorstElite(int fitness);
    void addPopulationFitness(int fitness);
    void addNPopulation(int np);
    void addNMutations(int nm);
    void addFitnessSelection(int fitness);
    void addFitnessCrossover(int fitness);
    void addFitnessMutation(int fitness);
    string displayStatistics() const;

};

#endif // STATISTICS_H
