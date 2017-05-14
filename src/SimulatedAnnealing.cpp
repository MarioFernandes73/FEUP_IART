#include "SimulatedAnnealing.h"
#include "Utils.h"
#include <math.h>

using namespace std;

SimulatedAnnealing::SimulatedAnnealing(Epoch * epoch, float temperature,float acceptance) : Algorithm(epoch)
{
    this->temperature = temperature;
    this->acceptance = acceptance;

    vector<Exam *> exams = randomExams(this->epoch->getExams());
    currentSolution = createRandomSchedule(exams);
    currentSolution->calculateFitness();
}

void SimulatedAnnealing::run(){

    int rep = REPETITIONS;
    float tempRed = temperature/(float)rep;

    while(rep != 0){
        currentSolution = chooseNextSolution(temperature);
        temperature -= tempRed;
        rep--;
    }

    cout << "Solution: " << *currentSolution << endl;
    cout << "Fitness Function: " << currentSolution->getFitness() << endl;

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

        number = solution->getID();
        *solution = *currentSolution;
        solution->setID(number);

        applyRandomChanges(solution,temperature/5 + 1);
        solution->calculateFitness();

        cout << solution->getID() << " : " << solution->getFitness() << endl;

        //Probability of being the next solution
        if(solution->getFitness() > currentSolution->getFitness()){
            cout << "Bigger Solutions" << endl;
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

    cout << "Delta: " << deltaE << endl;
    cout << "d/t: " << deltaE/temperature << endl;
    cout <<"prob: " << probability << endl;
    cout <<"random: " << random << endl << endl;

    if(random <= probability)
        return true;
    else
        return false;
}
