#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <ctime>
#include <cmath>
#include <string>


using namespace std;

class Statistics {
private:
    vector<float> iterationsTimes;
    vector<float> bestFitness;
    clock_t timer;

    //Algortihm
    string algorithm;

    //SimulatedAnnealing
    vector<bool> worstAccepted; //records if a worstSolution was accepted
    int schedulesGenerated = 1;
    int schedulesAboveCurrent = 0;  //Number of schedules that have the fitness above the current fitness


public:
    Statistics(string algorithm_name);
    void startIteration();
    void endIteration(float best);
    void displayStatistics() const;

    //Simulated Annealing
    void addWorst(float probability, float random);
    void addSchedulesGenerated();
    void addScheduleAboveCurrent();
    void displaySimulatedAnnealingStat() const;
};

#endif // STATISTICS_H
