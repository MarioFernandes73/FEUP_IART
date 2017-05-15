//
// Created by gomes on 22/03/2017.
//

#include "Algorithm.h"
#include "Utils.h"

using namespace std;

Algorithm::Algorithm(Epoch *e, int populationLength)
{
    this->epoch = e;
    this->populationLength = populationLength;
    this->maxSlots = e->getNumdays() * HOURS_PER_DAY;

    populate(e->getExams());
}

void Algorithm::populate(vector<Exam *> exams)
{
    vector<Exam *> exams2 = randomExams(exams);

    for (int i = 0; i < this->populationLength; ++i)
    {
        Schedule * s = createRandomSchedule(exams2);
        s->printExams();
        this->population.push_back(s);
    }
}

Schedule * Algorithm::createRandomSchedule(vector<Exam *> exams)
{
    Schedule *s = new Schedule();
    s->setSubscriptions(this->epoch->getSubscriptions());

    bool valid = true;
    do{
        valid = s->createRandomSchedule(exams, this->maxSlots);
        cout << endl << valid << endl<< endl;
    }while(!valid);

    return s;
}

vector<Exam *> Algorithm::randomExams(std::vector<Exam *> vector)
{
    std::vector<Exam *> exams1 = vector;
    std::vector<Exam *> exams2;

    int i = 0;
    while(i < exams1.size())
    {
        int random = rand() % exams1.size();
        exams2.push_back((Exam *&&) exams1.at(random));
        exams1.erase(exams1.begin()+random);
    }

    return exams2;
}

void Algorithm::run()
{
    int rep = REPETITIONS;

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
    //this->epoch->setSchedule(population.at(best));
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

int Algorithm::getBestSchedule(std::vector<Schedule *> schedules)
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
    double *randomProbs = new double[population.size()-numElitists];
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
    int size = population.size();
    double *randomProbs = new double[size];
    createRandomProbs(randomProbs,size);

    //DEBUG
    cout << endl << " Selected population :" << endl;
    //if probability <= 90% the schedule will be chosen to "crossover"
    for (int i = 0; i < size; ++i) {
        if(randomProbs[i] <= crossoverProb)
        {
            //DEBUG
            cout << population.at(i)->getID() << " , ";

            selectedPopulation.push_back((Schedule *&&) population.at(i));
        }
    }

    //delete selected population from "population" arrray
    for (int j = 0; j < selectedPopulation.size(); ++j)
        for (int i = 0; i < population.size(); ++i)
            if(selectedPopulation.at(j)->getID() == population.at(i)->getID()){
                population.erase(population.begin()+i);
                break;
            }

    return selectedPopulation;
}

void Algorithm::executeCrossover(std::vector<Schedule *> pop)
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
        int position = rand() % (epoch->getExams().size()-1) +1;

//debug
        cout << pop.at(i)->getID() << " + " << pop.at(i+1)->getID() << " at "<< position << endl;

//create the 2 new schedules
        vector<pair<Exam *, int>> new1 = createMap(pop.at(i)->getExamSlot(),pop.at(i+1)->getExamSlot(), position);
        vector<pair<Exam *, int>> new2 = createMap(pop.at(i+1)->getExamSlot(),pop.at(i)->getExamSlot(), position);

//update the schedule object
        Schedule *s1 = new Schedule();
        s1->setSubscriptions(epoch->getSubscriptions());
        s1->updateSchedule(new1,this->maxSlots);
        population.push_back(s1);

        Schedule *s2 = new Schedule();
        s2->setSubscriptions(epoch->getSubscriptions());
        s2->updateSchedule(new2,this->maxSlots);
        population.push_back(s2);

        i += 2;
    }
}

vector<pair<Exam *, int>> Algorithm::createMap(std::vector<pair<Exam *, int>> map1, std::vector<pair<Exam *, int>> map2, int pos) {
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
    int numExams = epoch->getExams().size();

    double mutNum = (mut / 100) * population.size() * numExams;

    double scheduleNum = mutNum / numExams;
    int examNum = mutNum - (int)scheduleNum*numExams;

    //DEBUG
    cout << "Mutation on schedule "<< population.at((int)scheduleNum)->getID()
         << " at " << population.at((int)scheduleNum)->getExamSlot().at(examNum).first->getClassName()
         << " exam ( " << (int)scheduleNum << " , " << examNum << " )"<< endl;

    population.at((int)scheduleNum)->mutate(examNum);
}
