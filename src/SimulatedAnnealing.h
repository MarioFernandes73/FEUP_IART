#ifndef SIMULATEDANNEALING_H
#define SIMULATEDANNEALING_H

#include "Algorithm.h"
#include "Statistics.h"

using namespace std;

class SimulatedAnnealing : public Algorithm
{
private:
    Statistics *statistics;
    float temperature;
    float temperatureReduction;
    Schedule * currentSolution;
    float acceptance;     //best value -> 40 -> influencia a rejeição
                        //de soluções com uma função fitness pior do
                        //a da solução atual. Quando menor o valor,
                        //maior a rejeição
public:
    SimulatedAnnealing(Epoch *epoch, bool debug, float temperature, float reduction, float acceptance);
    void run();
    void applyRandomChanges(Schedule * originalSchedule, int numberOfChanges);
    Schedule * chooseNextSolution(float temperature);
    bool chooseWorstSolution(Schedule * worst, float temperature) const;
};

#endif // SIMULATEDANNEALING_H
