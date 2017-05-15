#include "SimulatedAnnealing.h"
#include "Utils.h"
#include <math.h>
#include <thread>

using namespace std;

SimulatedAnnealing::SimulatedAnnealing(Epoch * epoch, float temperature,float temperatureRed, float acceptance){
    this->epoch = epoch;
    this->maxSlots = epoch->getNumdays() * HOURS_PER_DAY
    this->temperature = temperature;
    this->temperatureReduction = temperatureRed;
    this->acceptance = acceptance;
    this->statistics = new Statistics("SimultatedAnnealing");

    currentSolution = generateRandomSchedule();
    currentSolution->calculateFitness();
}

void SimulatedAnnealing::run(){

    while(temperature > 0){
        new thread([&] (Statistics *s) { s->startIteration();}, statistics);
        currentSolution = chooseNextSolution(temperature);
        temperature -= temperatureReduction;
        cout << endl << "NEW SOLUTION, F = " << currentSolution->getFitness() << " ,T = " << temperature << endl;
        new thread([&] (Statistics *s,float best) { s->endIteration(best);}, statistics, currentSolution->getFitness());
    }

    cout << "Solution: " << *currentSolution << endl;
    cout << "Fitness Function: " << currentSolution->getFitness() << endl;

    statistics->displayStatistics();
}

Schedule * SimulatedAnnealing::generateRandomSchedule(){
    vector<Exam *> exams = Algorithm::randomExams(this->epoch->getExams());

    Schedule *s = new Schedule();
    s->setSubscriptions(this->epoch->getSubscriptions());

    bool valid = true;
    do{
        valid = s->createRandomSchedule(exams, this->maxSlots);
        cout << endl << valid << endl<< endl;
    }while(!valid);

    return s;
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
        Schedule * solution = new Schedule();

        new thread([&] (Statistics *s) { s->addSchedulesGenerated();}, statistics);

        number = solution->getID();
        *solution = *currentSolution;
        solution->setID(number);

        applyRandomChanges(solution,temperature/5 + 1);
        solution->calculateFitness();

        cout << endl << solution->getID() << " : " << solution->getFitness() << endl;

        //Probability of being the next solution
        if(solution->getFitness() > currentSolution->getFitness()){
            cout << "BIGGER Solutions" << endl;
            new thread([&] (Statistics *s) { s->addScheduleAboveCurrent();}, statistics);
            return solution;
        }
        else if(chooseWorstSolution(solution,temperature))
            return solution;
    }


}

bool SimulatedAnnealing::chooseWorstSolution(Schedule * worst, float temperature) const{
    //Probability of choosing a worst solution
    //div by x if we want to make it easier
    float deltaE = fabs(worst->getFitness() - (float)currentSolution->getFitness())/acceptance;
    float probability = exp(-deltaE/temperature);

    //random probability
    float random = (float)(rand() % 10000)/10000;

    cout << "WORST Solutions" << endl;
    cout << "Delta: " << deltaE << endl;
    cout << "d/t: " << deltaE/temperature << endl;
    cout <<"prob: " << probability << endl;
    cout <<"random: " << random << endl;

    new thread([&] (Statistics *s,float p,float r) { s->addWorst(p,r);}, statistics,probability,random);

    if(random <= probability)
        return true;
    else
        return false;
}
