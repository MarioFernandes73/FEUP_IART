#include "Statistics.h"
#include <numeric>
#include <iostream>
#include <iomanip>

Statistics::Statistics(string algorithm_name){
    this->algorithm = algorithm_name;
}

void Statistics::startIteration(){
    timer = clock();
}

void Statistics::endIteration(float best){
    float duration = (clock() - timer)/ (float) CLOCKS_PER_SEC;
    iterationsTimes.push_back(duration);
    bestFitness.push_back(best);
}

void Statistics::displayStatistics() const{
    //times
    float totalTime = 0.0f;
    float avgTime = 0.0f;
    float shortestTime = 100.0f;
    float longestTime = 0.0f;
    //fitness
    int improvement = 0;
    int maxImprovement = 0; //with best value in the fitness
    int initialFitness = this->bestFitness[0];
    int lastFitness = this->bestFitness[this->bestFitness.size() - 1];
    int bestFitness = 0;
    int worstFitness = 9999999;

    for(float time : iterationsTimes){
        totalTime += time;
        if(time < shortestTime) shortestTime = time;
        else if(time > longestTime) longestTime = time;
    }

    for(int fitness : this->bestFitness){
        if(fitness > bestFitness) bestFitness = fitness;
        else if(fitness < worstFitness) worstFitness = fitness;
    }

    avgTime = totalTime/((float) iterationsTimes.size());
    improvement = (lastFitness - initialFitness);
    maxImprovement = (bestFitness - initialFitness);

    cout << "#######################################" << endl
         << "#             STATISTICS              #" << endl
         << "#######################################" << endl
         << endl << fixed << setprecision(2)
         << "Average Iteration Time   : " << avgTime * ((float) 1000) << " ms" << endl
         << "Algorithm Total Time     : " << totalTime * ((float) 1000) << " ms" << endl
         << "Shortest Time            : " << shortestTime * ((float) 1000) << " ms" << endl
         << "Longest Time             : " << longestTime * ((float) 1000) << " ms" << endl
         << endl
         << "Starting Fitness         : " << initialFitness << endl
         << "WorstFitness             : " << worstFitness << endl
         << endl
         << "Ending Fitness           : " << lastFitness << endl
         << "BestFitness              : " << bestFitness << endl
         << endl
         << "Fitness Improvement      : " << improvement << endl
         << "Max Fitness Improvement  : " << maxImprovement << endl
         << endl
         << "Improvement/StartFitness : " << improvement/this->bestFitness[0] * ((float) 100) << " %" << endl
         << "MaxImprov/StartFitness   : " << maxImprovement/this->bestFitness[0] * ((float) 100) << " %" << endl
         << endl;

    if(this->algorithm.compare("SimultatedAnnealing") == 0){
        displaySimulatedAnnealingStat();
    }
}

/*
 * SimulatedAnnealing
 */

void Statistics::addWorst(float probability, float random){
    bool accepted = false;
    if(probability > random)
        accepted = true;
    worstAccepted.push_back(accepted);
}

void Statistics::addScheduleAboveCurrent(){
    this->schedulesAboveCurrent++;
}

void Statistics::addSchedulesGenerated(){
    this->schedulesGenerated++;
}

void Statistics::displaySimulatedAnnealingStat() const{
    float worstAcceptedN = 0.0f;
    float worstRejectedN = 0.0f;
    float iterationsN = (float)iterationsTimes.size();
    float worstN = (float)this->worstAccepted.size();
    float bestN = (float)schedulesAboveCurrent;
    float generatedN = (float)schedulesGenerated;
    float perc = 100.0f;

    for(bool accepted : this->worstAccepted){
        if(accepted)    worstAcceptedN+=1.0f;
        else            worstRejectedN+=1.0f;
    }

    cout << "#######################################" << endl
         << "#           SIMULATED ANNEALING       #" << endl
         << "#######################################" << endl << fixed << setprecision(2)
         << endl
         << "Generated                : " << (int) generatedN << endl
         << "Iterations               : " << (int)iterationsN << endl
         << "Total Worst              : " << (int) worstN << endl
         << "Worst accepted           : " << (int) worstAcceptedN << endl
         << "Worst rejected           : " << (int) worstRejectedN << endl
         << "Best                     : " << (int) bestN << endl
         << endl
         << "WorstAccepted/TotalWorst : " << worstAcceptedN/worstN * perc << " %" << endl
         << "WorstRejected/TotalWorst : " << worstRejectedN/worstN * perc << " %" << endl
         << endl
         << "Generated/Iterations     : " << generatedN/iterationsN << "  %" << endl
         << "WorstAccepted/Iterations : " << worstAcceptedN/iterationsN * perc << " %" << endl
         << "Best/Iterations          : " << bestN/iterationsN * perc << " %" << endl
         << endl
         << "TotalWorst/Generated     : " << worstN/generatedN * perc << " %" << endl
         << "WorstAccepted/Generated  : " << worstAcceptedN/generatedN * perc << " %" << endl
         << "WorstRejected/Generated  : " << worstRejectedN/generatedN * perc << " %" << endl
         << "Best/Generated           : " << bestN/generatedN * perc << " %" << endl;


}

