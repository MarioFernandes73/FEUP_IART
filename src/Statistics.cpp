#include "Statistics.h"
#include <numeric>
#include <iostream>
#include <iomanip>

Statistics::Statistics(AlgorithmType algorithm){
    this->algorithm = algorithm;
}

void Statistics::startIteration(){
    iterationTimer = clock();
}

void Statistics::startAlgorithm(){
    algorithmTimer = clock();
}

void Statistics::endAlgorithm(){
    algorithmExecTime = (float)(clock() - algorithmTimer)/((float) CLOCKS_PER_SEC) * 1000.0f;//ms
}

void Statistics::displayStatistics() const{
    //times
    float avgTime = 0.0f;
    float longestTime = 0.0f;
    //fitness
    int improvement = 0;
    int maxImprovement = 0; //with best value in the fitness
    int initialFitness = this->bestFitness[0];
    int lastFitness = this->bestFitness[this->bestFitness.size() - 1];
    int bestFitness = 0;
    int worstFitness = 9999999;

    for(float time : iterationsTimes){
        if(time > longestTime) longestTime = time;
    }

    for(int fitness : this->bestFitness){
        if(fitness > bestFitness) bestFitness = fitness;
        else if(fitness < worstFitness) worstFitness = fitness;
    }

    avgTime = algorithmExecTime/((float) iterationsTimes.size());
    improvement = (lastFitness - initialFitness);
    maxImprovement = (bestFitness - initialFitness);

    cout << "#######################################" << endl
         << "#             STATISTICS              #" << endl
         << "#######################################" << endl
         << endl << fixed << setprecision(2)
         << "Number of Iterations     : " << iterationsTimes.size() << endl
         << endl
         << "Average Iteration Time   : " << avgTime << " ms" << endl
         << "Algorithm Total Time     : " << algorithmExecTime << " ms" << endl
         << "Longest Time             : " << longestTime << " ms" << endl
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

    if(this->algorithm == SIMULATED_ANNEALING){
        displaySimulatedAnnealingStat();
    }
    else if(this->algorithm == GENETIC){
        displayGeneticStat();
    }
}

/*
 * SimulatedAnnealing
 */

void Statistics::endIteration(float best){
    float duration = (float)(clock() - iterationTimer)/ ((float) CLOCKS_PER_SEC) * 1000.0f; //ms
    iterationsTimes.push_back(duration);
    bestFitness.push_back(best);
}

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

/*
 * Genetic
 */

void Statistics::startStage(){
    stageTimer = clock();
}

void Statistics::endStage(GeneticStages stage){

    float duration = (float)(clock() - stageTimer)/((float) CLOCKS_PER_SEC) * 1000.0f; //ms

    switch (stage) {
    case POPULATE:{
        populateTime = duration;
        break;
    }
    case SELECTION:{
        selectionTimes.push_back(duration);
        break;
    }
    case CROSSOVER:{
        crossoverTimes.push_back(duration);
        break;
    }
    case MUTATION:{
        mutationTimes.push_back(duration);
        break;
    }
    default:
        break;
    }
}

void Statistics::addBestSpeciment(int fitness){
    bestFitness.push_back(fitness);
}

void Statistics::addBestElite(int fitness){
    bestEliteFitness.push_back(fitness);
}

void Statistics::addWorstElite(int fitness){
    worstEliteFitness.push_back(fitness);
}

void Statistics::addPopulationFitness(int fitness){
    populationFitness.push_back(fitness);
}

void Statistics::addNPopulation(int np){
    populationN = np;
}

void Statistics::addNMutations(int nm){
    mutationN.push_back(nm);
}

void Statistics::addFitnessSelection(int fitness){
    fitnessSelection.push_back(fitness);
}

void Statistics::addFitnessCrossover(int fitness){
    fitnessCrossover.push_back(fitness);
}

void Statistics::addFitnessMutation(int fitness){
    fitnessMutation.push_back(fitness);
}

void Statistics::displayGeneticStat() const{

    float sumWorstElite = 0.0f;
    float sumPopFitness = 0.0f;
    float sumFitnessSelection = 0.0f;
    float sumFitnessCrossover = 0.0f;
    float sumFitnessMutation = 0.0f;
    float sumSelectionTimes = 0.0f;
    float sumCrossoverTimes = 0.0f;
    float sumMutationTimes = 0.0f;
    float iterations = iterationsTimes.size();


    for(int fitness : worstEliteFitness)    sumWorstElite += fitness;

    for(int fitness : populationFitness)    sumPopFitness += fitness;

    for(int fitness : fitnessSelection)     sumFitnessSelection += fitness;

    for(int fitness : fitnessCrossover)     sumFitnessCrossover += fitness;

    for(int fitness : fitnessMutation)      sumFitnessMutation += fitness;

    for(int fitness : selectionTimes)       sumSelectionTimes += fitness;

    for(int fitness : crossoverTimes)       sumCrossoverTimes += fitness;

    for(int fitness : mutationTimes)        sumMutationTimes += fitness;

    cout << "#######################################" << endl
         << "#              GENETIC                #" << endl
         << "#######################################" << endl << fixed << setprecision(2)
         << "Population               : " << populationN << endl
         << endl;
}
