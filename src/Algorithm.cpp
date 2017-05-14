#include "Algorithm.h"
#include "Utils.h"

using namespace std;

Algorithm::Algorithm(Epoch *epoch)
{
    this->epoch = epoch;
    this->maxSlots = epoch->getNumdays() * HOURS_PER_DAY;
}

Schedule * Algorithm::createRandomSchedule(vector<Exam *> exams)
{
    Schedule *s = new Schedule();
    s->setSubscriptions(this->epoch->getSubscriptions());
    s->setFirstWeekDay(this->epoch->getInitWeekDay());

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

void Algorithm::run(){};
