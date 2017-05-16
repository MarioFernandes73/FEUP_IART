#include "SimulatedAnnealing.h"
#include "Utils.h"
#include <math.h>

using namespace std;

SimulatedAnnealing::SimulatedAnnealing(Epoch * epoch, bool debug, float temperature, float reduction, float acceptance) : Algorithm(epoch,debug)
{
    this->temperature = temperature;
    this->temperatureReduction = reduction;
    this->acceptance = acceptance;

    vector<Exam *> exams = randomExams(this->epoch->getExams());
    currentSolution = createRandomSchedule(exams);
    currentSolution->calculateFitness();
}

void SimulatedAnnealing::run(){

    while(temperature > 0){
        currentSolution = chooseNextSolution(temperature);
        temperature -= temperatureReduction;

        if(debug){
            cout << endl << "NEW SOLUTION, F = " << currentSolution->getFitness() << " ,T = " << temperature << endl;
        }
    }

    if(debug)
    {
        cout << "Solution: " << *currentSolution << endl;
        cout << "Fitness Function: " << currentSolution->getFitness() << endl;
    }

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
    float random = (float)(rand() % 10000)/10000;

    if(debug)
    {
        cout << "WORST Solution" << endl;
        cout << "Delta: " << deltaE << endl;
        cout << "d/t: " << deltaE/temperature << endl;
        cout <<"prob: " << probability << endl;
        cout <<"random: " << random << endl << endl;
    }

    if(random <= probability)
        return true;
    else
        return false;
}
