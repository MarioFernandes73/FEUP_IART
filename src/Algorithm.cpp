//
// Created by gomes on 22/03/2017.
//

#include "Algorithm.h"
#include "Utils.h"

using namespace std;

Algorithm::Algorithm(University u, int populationLength)
{
    this->populationLength = populationLength;

    int maxSlots = u.getEpochByName("Normal")->getNumdays() * HOURS_PER_DAY;
    populate(u.getExams(), maxSlots);
    run();
}

void Algorithm::populate(std::vector<Exam *> exams, int maxSlots)
{
    for (int i = 0; i < this->populationLength; ++i)
    {
        Schedule * s = createRandomSchedule(exams, maxSlots);
        s->printExams();

        this->population.push_back(s);
    }
}

Schedule * Algorithm::createRandomSchedule(std::vector<Exam *> exams, int slots)
{
    //schedule
    Schedule *s = new Schedule();
    std::vector<Exam *> schedule;
    std::vector<bool> boolSchedule;
    std::unordered_map<Exam *, int> examSlot;

    //initialize all booleans = false and exams to NULL
    for (int i = 0; i < slots; ++i) {
        boolSchedule.push_back(false);
        schedule.push_back(NULL);
    }

    int j = 0;
    while(j < exams.size())
    {
        Exam * chosen = exams.at(j);

        //random position
        int random = rand() % slots;
        int duration = chosen->getDuration();

        //possible position
        if((duration + random) <= slots)
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
                examSlot.insert(std::make_pair<Exam *,int>((Exam *&&) chosen, (int &&) random));
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
    int rep = REPETITIONS;

    /* while(rep > 0)
     {*/
    //calcular funcao de adaptacao por exame e do schedule
    int populationFitness = calculateFitness();
    //selecao
    selectNextPopulation(populationFitness);
    //emparelhamento
    //cruzamento
    //mutacao
    /*     rep--;
         cout << endl << "fim da iteracao " << endl;
     }*/
}

int Algorithm::calculateFitness()
{
    //calculate schedule fitness
    int populationFitness = 0;
    for (int i = 0; i < population.size(); ++i)
    {
        cout << "Schedule : " << population.at(i)->getID() << endl;
        populationFitness += population.at(i)->calculateFitness();
    }

    return populationFitness;
}

void Algorithm::selectNextPopulation(int populationFitness)
{
    int numElitists = NUM_ELITISTS;
    vector<Schedule *> nextPopulation = selectElitistPopulation();

    //calculate population fitness probabilities to the roulette
    fitnessProbabilities(populationFitness);

    //create random probabilities
    double randomProbs[population.size()];
    cout << "Random Probs : " << endl;
    for(int k = 0; k < population.size(); ++k)
    {
        randomProbs[k] = (double) (rand() % 100) / 100;
        cout << randomProbs[k] << " , ";
    }

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
        int mybest = 0;
        for(int j = 0; j < oldPopulation.size() ; ++j)
        {
            if((oldPopulation.at(j)->getFitness() > oldPopulation.at(mybest)->getFitness()))
                mybest = j;
        }
        //add to next population
        nextPopulation.push_back(oldPopulation.at(mybest));
        //delete from old population (to do not be select twice)
        oldPopulation.erase(oldPopulation.begin()+mybest);
    }

    //DEBUG : os 6 melhores
    cout << "The best ones : " << endl;
    for (int i = 0; i < nextPopulation.size(); ++i) {
        cout << "id " << nextPopulation.at(i)->getID()<< " fitness " << nextPopulation.at(i)->getFitness() << endl;
    }

    return nextPopulation;
}

void Algorithm::fitnessProbabilities(int populationFitness)
{
    cout << "Roulette : "<< populationFitness<< endl;
    double minRouletteProb = 0, currRouletteProb = 0;
    for(int k = 0; k < population.size(); k++)
    {
        currRouletteProb = population.at(k)->calculateMaxRouletteProb(minRouletteProb,populationFitness);
        cout << "( " << minRouletteProb << " , " << currRouletteProb << " ) " << endl;
        minRouletteProb = currRouletteProb;
    }
}

void Algorithm::selectRemainingPopulation(double *randomProbs, vector<Schedule *> nextPopulation) {
    for(int l = 0; l < population.size(); ++l)     //iterate randomProbs
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

    //my next population
    cout << endl << "My new Population : " << endl;
    for(int i = 0; i < population.size(); i++)
        cout << population.at(i)->getID() << " , ";
}
