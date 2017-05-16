#include "Genetic.h"
#include "Utils.h"
#include <thread>

using namespace std;

Genetic::Genetic(Epoch *e, bool debug, int populationLength) : Algorithm(e,debug)
{
    statistics = new Statistics(GENETIC);
    statistics->addNPopulation(populationLength);

    this->populationLength = populationLength;

    statistics->startStage();
    populate(e->getExams());
    statistics->endStage(POPULATE);
}

void Genetic::populate(vector<Exam *> exams)
{
    vector<Exam *> exams2 = randomExams(exams);

    for (int i = 0; i < this->populationLength; ++i)
    {
        Schedule * s = createRandomSchedule(exams2);
        this->population.push_back(s);

        if(debug)   s->printExams();
    }
}

void Genetic::run()
{
    statistics->startAlgorithm();
    int rep = REPETITIONS;

    while(rep > 0)
    {
        //Statistics
        new thread([&] (Statistics *s) { s->startIteration();}, statistics);

        if(debug) cout << endl << "-- New repetition : --" << rep<< endl;

        //stage: SELECTION
        new thread([&] (Statistics *s) { s->startStage();}, statistics);
        calculateFitness();
        selectNextPopulation();
        new thread([&] (Statistics *s, int fitness){s->endStage(SELECTION);s->addFitnessSelection(fitness);
                s->startStage();}, statistics,getPopulationFitness());

        //stage: CROSSOVER
        crossover();
        new thread([&] (Statistics *s, int fitness){s->endStage(CROSSOVER);s->addFitnessSelection(fitness);
                s->startStage();}, statistics,getPopulationFitness());

        mutation();
        new thread([&] (Statistics *s, int fitness){s->endStage(MUTATION);s->addFitnessSelection(fitness);
                s->startStage();}, statistics,getPopulationFitness());

        rep--;

        //Statistics
       new thread([&] (Statistics *s) { s->endIteration(population.at(getBestSchedule(population))->getFitness());}, statistics);
    }

    calculateFitness();
    int best = getBestSchedule(population);

    if(debug) cout << endl << "Best Schedule is " << population.at(best)->getID() << " with fitness = " << population.at(best)->getFitness();

    this->epoch->setSchedule(population.at(best));
    statistics->endAlgorithm();

    statistics->displayStatistics();
}

void Genetic::calculateFitness()
{
    //calculate schedule fitness
    for (int i = 0; i < population.size(); ++i)
    {
        int fitness = population.at(i)->calculateFitness();

        if(debug)
        {
            if(fitness == -1)
                cout << "Invalid Schedule!" << endl;

             cout << * population.at(i) << "Fitness : " << population.at(i)->getFitness() << endl << endl;
        }
    }
}

int Genetic::getPopulationFitness() {
    return calculatePopulationFitness(population);
}

int Genetic::calculatePopulationFitness(vector<Schedule *> population){
    int populationFitness = 0;
    for (int i = 0; i < population.size(); ++i)
    {
        populationFitness += population.at(i)->getFitness();
    }
    return populationFitness;
}

int Genetic::getBestSchedule(std::vector<Schedule *> schedules)
{
    int mybest = 0;
    for(int j = 0; j < schedules.size() ; ++j)
    {
        if((schedules.at(j)->getFitness() > schedules.at(mybest)->getFitness()))
            mybest = j;
    }
    return mybest;
}

void Genetic::selectNextPopulation()
{
    int populationFitness = getPopulationFitness();

    //Statistics
    new thread([&] (Statistics *s,int fitness) { s->addPopulationFitness(fitness);}, statistics,populationFitness);

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

vector<Schedule *> Genetic::selectElitistPopulation()
{
    int numElitists = NUM_ELITISTS;
    vector<Schedule *> nextPopulation;
    vector<Schedule *> oldPopulation = population;

    //elitist selection : select the 6 schedules with higher fitness function
    for(int i = 0; i < numElitists; i++)
    {
        int mybest = getBestSchedule(oldPopulation);

        if(i == 0)
            new thread([&] (Statistics *s, int fitness) { s->addBestElite(fitness);}, statistics,oldPopulation.at(mybest)->getFitness());
        else if(i == numElitists - 1)
            new thread([&] (Statistics *s, int fitness) { s->addWorstElite(fitness);}, statistics,oldPopulation.at(mybest)->getFitness());


        //add to next population
        nextPopulation.push_back((Schedule *&&) oldPopulation.at(mybest));
        //delete from old population (to do not be select twice)
        oldPopulation.erase(oldPopulation.begin()+mybest);

    }
    if(debug)
    {
        cout << endl << "Elitist selection : " << endl;
        for (int i = 0; i < nextPopulation.size(); ++i)
            cout << "id " << nextPopulation.at(i)->getID()<< " fitness " << nextPopulation.at(i)->getFitness() << endl;
    }

    return nextPopulation;
}

void Genetic::fitnessProbabilities(int populationFitness)
{
    if(debug)   cout << "Roulette : "<< populationFitness<< endl;

    double minRouletteProb = 0, currRouletteProb = 0;
    for(int k = 0; k < population.size(); k++)
    {
        currRouletteProb = population.at(k)->calculateMaxRouletteProb(minRouletteProb,populationFitness);

        if(debug)   cout << "( " << minRouletteProb << " , " << currRouletteProb << " ) " << endl;

        minRouletteProb = currRouletteProb;
    }
}

void Genetic::createRandomProbs(double * randomProbs, int size) {

    if(debug)   cout << "Random Probs : " << endl;

    for(int k = 0; k < size; ++k)
    {
        randomProbs[k] = (double) (rand() % 100) / 100;

        if(debug)   cout << randomProbs[k] << " , ";
    }
}

void Genetic::selectRemainingPopulation(double *randomProbs, vector<Schedule *> nextPopulation) {
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

    if(debug)
    {
        cout << endl << "My new Population : " << endl;
        for(int i = 0; i < population.size(); i++)
            cout << population.at(i)->getID() << " , ";
    }
}

void Genetic::crossover()
{
    if(debug)   cout <<endl << endl << "Cross over" << endl;

    vector<Schedule *> pop = selectCrossoverPopulation();
    executeCrossover(pop);
}

vector<Schedule *> Genetic::selectCrossoverPopulation()
{
    vector<Schedule *> selectedPopulation;
    double crossoverProb = CROSSING_PROB;
    crossoverProb /= 100;

    //create random probabilities
    int size = population.size();
    double *randomProbs = new double[size];
    createRandomProbs(randomProbs,size);

    if(debug)   cout << endl << " Selected population :" << endl;

    //if probability <= 90% the schedule will be chosen to "crossover"
    for (int i = 0; i < size; ++i)
        if(randomProbs[i] <= crossoverProb)
        {
            if(debug)   cout << population.at(i)->getID() << " , ";

            selectedPopulation.push_back((Schedule *&&) population.at(i));
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

void Genetic::executeCrossover(std::vector<Schedule *> pop)
{

    if(debug)   cout<< endl << "Execute crossover : " << endl;

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

        if(debug)   cout << pop.at(i)->getID() << " + " << pop.at(i+1)->getID() << " at "<< position << endl;

        //create the 2 new schedules
        vector<pair<Exam *, int>> new1 = createMap(pop.at(i)->getExamSlot(),pop.at(i+1)->getExamSlot(), position);
        vector<pair<Exam *, int>> new2 = createMap(pop.at(i+1)->getExamSlot(),pop.at(i)->getExamSlot(), position);

    //update the schedule object
        Schedule *s1 = new Schedule(debug);
        s1->setSubscriptions(epoch->getSubscriptions());
        s1->setFirstWeekDay(this->epoch->getInitDate().tm_wday);
        s1->updateSchedule(new1,this->maxSlots);
        population.push_back(s1);

        Schedule *s2 = new Schedule(debug);
        s2->setSubscriptions(epoch->getSubscriptions());
        s2->setFirstWeekDay(this->epoch->getInitDate().tm_wday);
        s2->updateSchedule(new2,this->maxSlots);
        population.push_back(s2);

        i += 2;
    }
}

vector<pair<Exam *, int>> Genetic::createMap(std::vector<pair<Exam *, int>> map1, std::vector<pair<Exam *, int>> map2, int pos) {
    vector<pair<Exam *, int>> newMap;

    for (int i = 0; i < pos; ++i) {
        newMap.push_back((pair<Exam *, int> &&) map1.at(i));
    }

    for (int k = pos; k < map2.size(); ++k) {
        newMap.push_back((pair<Exam *, int> &&) map2.at(k));
    }

    return newMap;
}

void Genetic::mutation()
{
    int numExams = epoch->getExams().size();
    int size = population.size() * numExams;   //number of random numbers to generate

    double * examsProbs = new double[size];
    createRandomProbs(examsProbs,size);

    int mutationN = 0;
    double mutProb = MUTATION_PROB;

    mutProb /= ((double) 100);

    cout << endl << "PROB: " << mutProb << endl;

    //Statistics
    new thread([&] (Statistics *s, int mutN) { s->addNMutations(mutN);}, statistics,mutationN);

    int scheduleNum,examNum;

    for(int i = 0; i < size; i++){

        if(examsProbs[i] < mutProb){
            mutationN++;

            //-1 because it starts on 0
            scheduleNum = i/numExams;
            examNum = i - scheduleNum * numExams;

            if(debug){
                cout << "Mutation on schedule "<< population.at(scheduleNum)->getID()
                     << " at " << population.at((int)scheduleNum)->getExamSlot().at(examNum).first->getClassName()
                     << " exam ( " << (int)scheduleNum << " , " << examNum << " )"<< endl;
            }

           population.at(scheduleNum)->mutate(examNum);
        }
    }
}
