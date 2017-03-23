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

    while(rep > 0)
    {
        //calcular funcao de adaptacao por exame e do schedule
        calculateFitness();
        //selecao
        //emparelhamento
        //cruzamento
        //mutacao
        rep--;
        cout << endl << "fim da iteracao " << endl;
    }
}

void Algorithm::calculateFitness()
{
    for (int i = 0; i < population.size(); ++i)
    {
        population.at(i)->calculateFitness();
    }
}
