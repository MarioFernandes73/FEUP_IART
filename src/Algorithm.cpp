//
// Created by gomes on 22/03/2017.
//

#include "Algorithm.h"
#include "Utils.h"

using namespace std;

Algorithm::Algorithm(University u, int populationLength)
{
    this->populationLength = populationLength;
    this->numExams = u.getExams().size();
    this->maxSlots = u.getEpochByName("Normal")->getNumdays() * HOURS_PER_DAY;

    populate(u.getExams());
    run();
}

void Algorithm::populate(std::vector<Exam *> exams)
{
    for (int i = 0; i < this->populationLength; ++i)
    {
        Schedule * s = createRandomSchedule(exams);
        s->printExams();

        this->population.push_back(s);
    }
}

Schedule * Algorithm::createRandomSchedule(std::vector<Exam *> exams)
{
    //schedule
    Schedule *s = new Schedule();
    std::vector<Exam *> schedule;
    std::vector<bool> boolSchedule;
    std::vector<pair<Exam *, int>> examSlot;

    //initialize all booleans = false and exams to NULL
    for (int i = 0; i < this->maxSlots; ++i) {
        boolSchedule.push_back(false);
        schedule.push_back(NULL);
    }

    int j = 0;
    while(j < numExams)
    {
        Exam * chosen = exams.at(j);

        //random position
        int random = rand() % this->maxSlots;
        int duration = chosen->getDuration();

        //possible position
        if((duration + random) <= this->maxSlots)
        {
            //free slots
            bool free = true;
            for (int i = random; i < random+duration; ++i)
            {
                if(boolSchedule.at(i))
                {
                    free = false;
                    break;
                }
            }

            //occupy slots
            if(free)
            {
                examSlot.push_back(std::make_pair<Exam *,int>((Exam *&&) chosen, (int &&) random));
                for (int i = 0; i < duration; ++i)
                {
                    boolSchedule.at(random+i) = true;
                    schedule.at(random+i) = chosen;
                }
                j++;
            }
        }
    }

    s->addExams(schedule,examSlot);

    return s;
}

void Algorithm::run()
{
    int rep = 2;//REPETITIONS;

    while(rep > 0)
    {
        //DEBUG
        cout << endl << "-- New repetition : --" << endl;

        calculateFitness();
        selectNextPopulation();
        crossover();
        mutation();

        rep--;
    }

    calculateFitness();
    //DEBUG
    int best = getBestSchedule(population);
    cout << endl << "Best Schedule is " << population.at(best)->getID() << " with fitness = " << population.at(best)->getFitness();
}

void Algorithm::calculateFitness()
{
    //calculate schedule fitness
    for (int i = 0; i < population.size(); ++i)
    {
        if(population.at(i)->calculateFitness() == -1)
            cout << "Invalid Schedule!" << endl;

        //DEBUG
        cout << * population.at(i) << "Fitness : " << population.at(i)->getFitness() << endl << endl;
        //population.at(i)->printExams();
    }
}

int Algorithm::getPopulationFitness() {
    int populationFitness = 0;
    for (int i = 0; i < population.size(); ++i)
    {
        populationFitness += population.at(i)->getFitness();
    }
    return populationFitness;
}

int Algorithm::getBestSchedule(vector<Schedule *> schedules)
{
    int mybest = 0;
    for(int j = 0; j < schedules.size() ; ++j)
    {
        if((schedules.at(j)->getFitness() > schedules.at(mybest)->getFitness()))
            mybest = j;
    }
    return mybest;
}

void Algorithm::selectNextPopulation()
{
    int populationFitness = getPopulationFitness();
    int numElitists = NUM_ELITISTS;
    vector<Schedule *> nextPopulation = selectElitistPopulation();

    //calculate population fitness probabilities to the roulette
    fitnessProbabilities(populationFitness);

    //create random probabilities
    double randomProbs[population.size()-numElitists];
    createRandomProbs(randomProbs,population.size()-numElitists);

    //select new population considering random probs
    selectRemainingPopulation(randomProbs,nextPopulation);
}

vector<Schedule *> Algorithm::selectElitistPopulation()
{
    int numElitists = NUM_ELITISTS;
    vector<Schedule *> nextPopulation;
    vector<Schedule *> oldPopulation = population;

    //elitist selection : select the 6 schedules with higher fitness function
    for(int i = 0; i < numElitists; i++)
    {
        int mybest = getBestSchedule(oldPopulation);
        //add to next population
        nextPopulation.push_back((Schedule *&&) oldPopulation.at(mybest));
        //delete from old population (to do not be select twice)
        oldPopulation.erase(oldPopulation.begin()+mybest);
    }

    //DEBUG : os 6 melhores
    cout << endl << "Elitist selection : " << endl;
    for (int i = 0; i < nextPopulation.size(); ++i) {
        cout << "id " << nextPopulation.at(i)->getID()<< " fitness " << nextPopulation.at(i)->getFitness() << endl;
    }

    return nextPopulation;
}

void Algorithm::fitnessProbabilities(int populationFitness)
{
    //DEBUG
    cout << "Roulette : "<< populationFitness<< endl;

    double minRouletteProb = 0, currRouletteProb = 0;
    for(int k = 0; k < population.size(); k++)
    {
        currRouletteProb = population.at(k)->calculateMaxRouletteProb(minRouletteProb,populationFitness);
        //DEBUG
        cout << "( " << minRouletteProb << " , " << currRouletteProb << " ) " << endl;

        minRouletteProb = currRouletteProb;
    }
}

void Algorithm::createRandomProbs(double * randomProbs, int size) {
    //DEBUG
    cout << "Random Probs : " << endl;
    for(int k = 0; k < size; ++k)
    {
        randomProbs[k] = (double) (rand() % 100) / 100;
        //DEBUG
        cout << randomProbs[k] << " , ";
    }
}

void Algorithm::selectRemainingPopulation(double *randomProbs, vector<Schedule *> nextPopulation) {
    int randomSize = population.size() - NUM_ELITISTS;
    for(int l = 0; l < randomSize; ++l)     //iterate randomProbs
    {
        double lastProb = 0;
        for(int m = 0; m < population.size(); ++m) //iterate population
        {
            if (randomProbs[l] >= lastProb && randomProbs[l] <= population.at(m)->getmaxRouletteProb())
            {
                nextPopulation.push_back(population[m]);
                break;
            }
            lastProb = population.at(m)->getmaxRouletteProb();
        }
    }

    population = nextPopulation;

    //DEBUG
    cout << endl << "My new Population : " << endl;
    for(int i = 0; i < population.size(); i++)
        cout << population.at(i)->getID() << " , ";
}

void Algorithm::crossover()
{
    //DEBUG
    cout <<endl << endl << "Cross over" << endl;

    vector<Schedule *> pop = selectCrossoverPopulation();
    executeCrossover(pop);
}

vector<Schedule *> Algorithm::selectCrossoverPopulation()
{
    vector<Schedule *> selectedPopulation;
    double crossoverProb = CROSSING_PROB;
    crossoverProb /= 100;

    //create random probabilities
    double randomProbs[population.size()];
    createRandomProbs(randomProbs,population.size());

    //DEBUG
    cout << endl << "Selected population :" << endl;
    //if probability <= 40% the schedule will be chosen to "crossover"
    for (int i = 0; i < population.size(); ++i) {
        if(randomProbs[i] <= crossoverProb)
        {
            //DEBUG
            cout << population.at(i)->getID() << " , ";

            selectedPopulation.push_back((Schedule *&&) population.at(i));
            population.erase(population.begin()+i);
        }
    }

    return selectedPopulation;
}

void Algorithm::executeCrossover(vector<Schedule *> pop)
{
    //DEBUG
    cout<< endl << "Execute crossover : " << endl;

    int size = pop.size();
    if(pop.size() % 2 != 0)
    {
        size -= 1;
        population.push_back((Schedule *&&) pop.at(size));
    }

    int i = 0;
    while (i < size)
    {
        //chose random crossover point
        int position = rand() % numExams;

        //debug
        cout << pop.at(i)->getID() << " + " << pop.at(i+1)->getID() << " at "<< position << endl;

        //create the 2 new schedules
        vector<pair<Exam *, int>> new1 = createMap(pop.at(i)->getExamSlot(),pop.at(i+1)->getExamSlot(), position);
        vector<pair<Exam *, int>> new2 = createMap(pop.at(i+1)->getExamSlot(),pop.at(i)->getExamSlot(), position);

        //update the schedule object
        Schedule *s1 = new Schedule();
        s1->updateSchedule(new1,this->maxSlots);
        population.push_back(s1);

        Schedule *s2 = new Schedule();
        s2->updateSchedule(new2,this->maxSlots);
        population.push_back(s2);

        i += 2;
    }
}

vector<pair<Exam *, int>> Algorithm::createMap(vector<pair<Exam *, int>> map1, vector<pair<Exam *, int>> map2, int pos) {
    vector<pair<Exam *, int>> newMap;

    for (int i = 0; i < pos; ++i) {
        newMap.push_back((pair<Exam *, int> &&) map1.at(i));
    }

    for (int k = pos; k < map2.size(); ++k) {
        newMap.push_back((pair<Exam *, int> &&) map2.at(k));
    }

    return newMap;
}

void Algorithm::mutation()
{
    double mut = MUTATION_PROB;

    double mutNum = (mut / 100) * population.size() * numExams;

    double scheduleNum = mutNum / numExams;
    int examNum = mutNum - (int)scheduleNum*numExams;

    population.at((int)scheduleNum)->mutate(examNum);

    //DEBUG
    cout << "Mutation on schedule "<< population.at((int)scheduleNum)->getID()
         << " at " << population.at((int)scheduleNum)->getExamSlot().at(examNum).first->getClassName()
         << " exam ( " << (int)scheduleNum << " , " << examNum << " )"<< endl;
}
