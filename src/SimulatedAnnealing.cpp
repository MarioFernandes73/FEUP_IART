#include "SimulatedAnnealing.h"
#include "Utils.h"
#include <math.h>
#include <thread>

using namespace std;

SimulatedAnnealing::SimulatedAnnealing(Epoch *epoch, bool debug, float temperature, float reduction, float acceptance, Schedule *current) : Algorithm(epoch,debug){
    this->temperature = temperature;
    this->acceptance = acceptance;
    this->statistics = new SAStatistics();
    this->temperatureReduction = reduction;

    //Does not count for statistics
    currentSolution = current;
    currentSolution->calculateFitness();

    bestSolutionEver = new Schedule(debug);
    *bestSolutionEver = *currentSolution;
}

SimulatedAnnealing::SimulatedAnnealing(Epoch * epoch, bool debug, float temperature, float reduction, float acceptance) : Algorithm(epoch,debug)
{
    this->temperature = temperature;
    this->acceptance = acceptance;
    this->statistics = new SAStatistics();
    this->temperatureReduction = reduction;

    vector<Exam *> exams = randomExams(this->epoch->getExams());
    currentSolution = createRandomSchedule(exams);
    currentSolution->calculateFitness();

    bestSolutionEver = new Schedule(debug);
    *bestSolutionEver = *currentSolution;
}

void SimulatedAnnealing::run(){

    statistics->startAlgorithm();

    while(temperature > 0){
        new thread([&] (SAStatistics *s) { s->startIteration();}, statistics);

        currentSolution = chooseNextSolution(temperature);
        temperature -= temperatureReduction;

        if(debug){
            cout << endl << "NEW SOLUTION, F = " << currentSolution->getFitness() << " ,T = " << temperature << endl;
        }
        new thread([&] (SAStatistics *s,float best) { s->endIteration(best);}, statistics, currentSolution->getFitness());
    }

    statistics->endAlgorithm();

    if(debug)
    {
        cout << "Solution: " << *bestSolutionEver << endl;
        cout << "Fitness Function: " << bestSolutionEver->getFitness() << endl;
    }

    statistics->displayStatistics();
}

void SimulatedAnnealing::applyRandomChanges(Schedule *originalSchedule, int numberOfChanges){
    int exam;
    int examsSize = epoch->getExams().size();

    while(numberOfChanges != 0){
        exam = rand() % examsSize;
        originalSchedule->mutate(exam);
        numberOfChanges--;
    }
}

Schedule * SimulatedAnnealing::chooseNextSolution(float temperature){

    int number;

    //while there is no next solution
    while(true){

        //new solution with modifications based on the current solution
        Schedule * solution = new Schedule(debug);
        solution->setFirstWeekDay(epoch->getInitDate().tm_wday);

        new thread([&] (SAStatistics *s) { s->addSchedulesGenerated();}, statistics);

        number = solution->getID();
        *solution = *currentSolution;
        solution->setID(number);

        applyRandomChanges(solution,temperature/5 + 1);
        solution->calculateFitness();

        if(debug)   cout << solution->getID() << " : " << solution->getFitness() << endl;

        //Probability of being the next solution
        if(solution->getFitness() > currentSolution->getFitness())
        {
            if(debug)   cout << "BIGGER Solutions" << endl;
            this->epoch->setSchedule(solution);
            new thread([&] (SAStatistics *s) { s->addScheduleAboveCurrent();}, statistics);

            if(bestSolutionEver->getFitness() < solution->getFitness())
                *bestSolutionEver = *solution;

            return solution;
        }
        else if(chooseWorstSolution(solution,temperature)){
            this->epoch->setSchedule(solution);
            return solution;
        }
    }
}

bool SimulatedAnnealing::chooseWorstSolution(Schedule * worst, float temperature) const{
    //Probability of choosing a worst solution
    //div by x if we want to make it easier
    float deltaE = fabs(worst->getFitness() - (float)currentSolution->getFitness())/acceptance;
    float probability = exp(-deltaE/temperature);

    //random probability
    float random = (float)(rand() % 10000)/((float)10000);

    if(debug)
    {
        cout << "WORST Solution" << endl;
        cout << "Delta: " << deltaE << endl;
        cout << "d/t: " << deltaE/temperature << endl;
        cout <<"prob: " << probability << endl;
        cout <<"random: " << random << endl << endl;
    }

    new thread([&] (SAStatistics *s,float p,float r) { s->addWorst(p,r);}, statistics,probability,random);

    if(random <= probability)
        return true;
    else
        return false;
}
