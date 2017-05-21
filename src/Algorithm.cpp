#include "Algorithm.h"
#include "Utils.h"

using namespace std;

Algorithm::Algorithm(Epoch *epoch, bool debug)
{
    this->epoch = epoch;
    this->maxSlots = epoch->getNumdays() * HOURS_PER_DAY;
    this->debug = debug;
}

Schedule * Algorithm::createRandomSchedule(vector<Exam *> exams)
{
    Schedule *s = new Schedule(debug);
    s->setSubscriptions(this->epoch->getSubscriptions());
    s->setFirstWeekDay(this->epoch->getInitDate().tm_wday);

    bool valid = true;
    do{
        valid = s->createRandomSchedule(exams, this->maxSlots);
        if(debug)   cout << endl << valid << endl<< endl;
    }while(!valid);

    return s;
}

Schedule * Algorithm::createRandomSchedule(bool debug, Epoch *epoch)
{
    Schedule *s = new Schedule(debug);
    s->setSubscriptions(epoch->getSubscriptions());
    s->setFirstWeekDay(epoch->getInitDate().tm_wday);
    int maxSlots = epoch->getNumdays() * HOURS_PER_DAY;

    //try to create new schedules until it's valid
    bool valid = true;
    do{
        valid = s->createRandomSchedule(epoch->getExams(), maxSlots);
        if(debug)   cout << endl << valid << endl<< endl;
    }while(!valid);

    return s;
}

vector<Exam *> Algorithm::randomExams(std::vector<Exam *> vector)
{
    std::vector<Exam *> exams1 = vector;
    std::vector<Exam *> exams2;

    unsigned int i = 0;
    while(i < exams1.size())
    {
        int random = rand() % exams1.size();
        exams2.push_back((Exam *&&) exams1.at(random));
        exams1.erase(exams1.begin()+random);
    }

    return exams2;
}

void Algorithm::run(){};
