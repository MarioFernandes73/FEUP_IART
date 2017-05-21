#include "Statistics.h"
#include <numeric>
#include <iostream>
#include <iomanip>

/*
 * Statistics
 */

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

void Statistics::endIteration(float best){
    float duration = (float)(clock() - iterationTimer)/ ((float) CLOCKS_PER_SEC) * 1000.0f; //ms
    iterationsTimes.push_back(duration);
    bestFitness.push_back(best);
}

string Statistics::displayStatistics() const{
    stringstream ss;

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

    ss << "#########################" << endl
       << "#             STATISTICS                     #" << endl
       << "#########################" << endl
       << endl << fixed << setprecision(2)
       << "Number of Iterations     : " << iterationsTimes.size() << endl
       << endl
       << "Average Iteration Time   : " << avgTime << " ms" << endl
       << "Algorithm Total Time     : " << algorithmExecTime << " ms" << endl
       << "Longest Time             : " << longestTime << " ms" << endl
       << endl
       << "Starting Fitness         : " << initialFitness << endl;
        if(algorithm != GENETIC)
            ss << "WorstFitness             : " << worstFitness << endl;
       ss<< endl
       << "Ending Fitness           : " << lastFitness << endl;
       if(algorithm != GENETIC)
            ss << "BestFitness              : " << bestFitness << endl;
       ss << endl
       << "Fitness Improvement      : " << improvement << endl;
       if(algorithm != GENETIC)
            ss << "Max Fitness Improvement  : " << maxImprovement << endl;
       ss << endl
       << "Improvement/StartFitness : " << improvement/this->bestFitness[0] * ((float) 100) << " %" << endl
       << "MaxImprov/StartFitness   : " << maxImprovement/this->bestFitness[0] * ((float) 100) << " %" << endl
       << endl;

    return ss.str();
}

/*
 * SimulatedAnnealing
 */

SAStatistics::SAStatistics() : Statistics(SIMULATED_ANNEALING){}

void SAStatistics::addWorst(float probability, float random){
    bool accepted = false;
    if(probability > random)
        accepted = true;
    worstAccepted.push_back(accepted);
}

void SAStatistics::addScheduleAboveCurrent(){
    this->schedulesAboveCurrent++;
}

void SAStatistics::addSchedulesGenerated(){
    this->schedulesGenerated++;
}

string SAStatistics::displayStatistics() const{

    stringstream ss;
    ss << Statistics::displayStatistics();

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

    ss << "#########################" << endl
       << "#           SIMULATED ANNEALING       #" << endl
       << "#########################" << endl << fixed << setprecision(2)
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

    return ss.str();
}

/*
 * Genetic
 */

GStatistics::GStatistics() : Statistics(GENETIC){
}

void GStatistics::startStage(){
    stageTimer = clock();
}

void GStatistics::endStage(GeneticStages stage){

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

void GStatistics::addBestElite(int fitness){
    bestEliteFitness.push_back(fitness);
}

void GStatistics::addWorstElite(int fitness){
    worstEliteFitness.push_back(fitness);
}

void GStatistics::addPopulationFitness(int fitness){
    populationFitness.push_back(fitness);
}

void GStatistics::addNPopulation(int np){
    populationN = np;
}

void GStatistics::addNMutations(int nm){
    mutationN.push_back(nm);
}

void GStatistics::addFitnessSelection(int fitness){
    fitnessSelection.push_back(fitness);
}

void GStatistics::addFitnessCrossover(int fitness){
    fitnessCrossover.push_back(fitness);
}

void GStatistics::addFitnessMutation(int fitness){
    fitnessMutation.push_back(fitness);
}


string GStatistics::displayStatistics() const{


    stringstream ss;
    ss << Statistics::displayStatistics();

    float perc = ((float) 100);

    float sumWorstElite = 0.0f, sumPopFitness = 0.0f, sumBestElite = 0.0f;
    float sumFitnessSelection = 0.0f, sumFitnessCrossover = 0.0f,sumFitnessMutation = 0.0f;
    float sumSelectionTimes = 0.0f,sumCrossoverTimes = 0.0f,sumMutationTimes = 0.0f;
    float sumMutationN = 0.0f;

    float iterations = (float)iterationsTimes.size();

    for(int fitness : worstEliteFitness)    sumWorstElite += fitness;
    for(int fitness : bestEliteFitness)     sumBestElite += fitness;
    for(int fitness : populationFitness)    sumPopFitness += fitness;
    for(int fitness : fitnessSelection)     sumFitnessSelection += fitness;
    for(int fitness : fitnessCrossover)     sumFitnessCrossover += fitness;
    for(int fitness : fitnessMutation)      sumFitnessMutation += fitness;
    for(int time : selectionTimes)          sumSelectionTimes += time;
    for(int time : crossoverTimes)          sumCrossoverTimes += time;
    for(int time : mutationTimes)           sumMutationTimes += time;
    for(int n : mutationN)                  sumMutationN += n;

    float avgPopFit = sumPopFitness/iterations;
    float avgSelFit = sumFitnessSelection/iterations;
    float avgCroFil = sumFitnessCrossover/iterations;
    float avgMutFit = sumFitnessMutation/iterations;

    float imprvOnSel = (avgSelFit - avgPopFit)/avgPopFit * perc;
    float imprvOnCro = (avgCroFil - avgSelFit)/avgSelFit * perc;
    float imprvOnMut = (avgMutFit - avgCroFil)/avgCroFil * perc;

    float avgMutN = sumMutationN/iterations;

    float avgSelTim = sumSelectionTimes/iterations;
    float avgCroTim = sumCrossoverTimes/iterations;
    float avgMutTim = sumMutationTimes/iterations;

    float avgBestEliteFit = sumBestElite/iterations;
    float avgWorstEliteFit = sumWorstElite/iterations;

    ss << "#########################" << endl
       << "#              GENETIC                         #" << endl
       << "#########################" << endl << fixed << setprecision(2)
       << "Population               : " << populationN << endl
       << endl
       << "Avg population fitness   : " << avgPopFit << endl
       << "Avg selection fitness    : " << avgSelFit << endl
       << "Avg crossover fitness    : " << avgCroFil << endl
       << "Avg mutation fitness     : " << avgMutFit << endl
       << endl
       << "Improvement on selection : " << imprvOnSel << " %" << endl
       << "Improvement on crossover : " << imprvOnCro << " %" << endl
       << "Improvement on mutation  : " << imprvOnMut << " %" << endl
       << endl
       << "Avg mutation number      : " << avgMutN << endl
       << endl
       << "Avg selection time       : " << avgSelTim << " ms" << endl
       << "Avg crossover time       : " << avgCroTim << " ms" << endl
       << "Avg mutation time        : " << avgMutTim << " ms" << endl
       << endl
       << "Avg best elite fitness   : " << avgBestEliteFit << endl
       << "Avg worst elite fitness  : " << avgWorstEliteFit << endl
       << endl;

    return ss.str();
}
