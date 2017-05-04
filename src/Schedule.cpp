/*
 * Schedule.cpp
 *
 *  Created on: 21 Feb 2017
 *
 */

#include "Schedule.h"
#include <cmath>

using namespace std;

int Schedule::currentId = 1;

Schedule::Schedule() {
    this->id = currentId;
    currentId++;

    cout << "Create schedule "<< id << endl;
}

Schedule::~Schedule() {
	// TODO Auto-generated destructor stub
}

int Schedule::getID() const {
    return this->id;
}

int Schedule::getFitness() const {
    return fitness;
}

void Schedule::setFitness(int f) {
    this->fitness = f;
}

double Schedule::getmaxRouletteProb() const{
    return this->maxRouletteProb;
}
void Schedule::setmaxRouletteProb(double mrp){
    this->maxRouletteProb = mrp;
}

int Schedule::getNumExams() const {
    return this->examSlot.size();
}

std::vector<pair<Exam *, int>> Schedule::getExamSlot() const {
    return this->examSlot;
}

void Schedule::addExams(std::vector<Exam *> vector, std::vector<pair<Exam *, int>> examSlot)
{
    this->schedule = vector;
    this->examSlot = examSlot;
    this->fitness = 0;
    this->maxRouletteProb = 0;
}

int Schedule::calculateFitness()
{
    //reinit this values every time
    this->fitness = 0;
    this->maxRouletteProb = 0;

    if(malformedSchedule())
        return -1;

    for (int i = 0; i < examSlot.size(); ++i)
    {
        pair<Exam *,int> x = (pair<Exam *, int> &&) examSlot.at(i);
        int fitness = 0;
        int multiplier = 0;
        int distance = 0;
        Exam * currExam = x.first;

        //compares current exam with all the other exams
        for (int j = 0; j < examSlot.size(); ++j)
        {
            pair<Exam *,int> y = (pair<Exam *, int> &&) examSlot.at(j);
            Exam * exam = y.first;

            if(!(currExam == exam)) //nao se esta a comparar consigo proprio
            {
                //TODO : mais tarde, introduzir o numero de alunos em comum como fator para o calculo do fitness
                //exams have student in common and aren't at the same day or at consecutive days
                if(inCommonStudents(currExam, exam) && !consecutiveDaysExams(x.second, y.second))
                {
                    multiplier = 5 - abs(currExam->getYear() - exam->getYear());
                    distance = abs(x.second - y.second);
                    fitness += distance*multiplier;
                }
            }
        }
        this->fitness += fitness;       //fitness schedule
        currExam->setFitness(fitness);   //fitness exam
    }

    return fitness;
}

bool Schedule::malformedSchedule()
{
    std::vector<bool> boolSchedule;
    for (int k = 0; k < schedule.size(); ++k) {
        boolSchedule.push_back(false);
    }

    for (int i = 0; i < examSlot.size(); ++i)
    {
        pair<Exam *,int> x = (pair<Exam *, int> &&) examSlot.at(i);

        if(x.second+x.first->getDuration() > schedule.size()){
            return true;
        }

        for (int j = 0; j < x.first->getDuration(); ++j) {
            if(boolSchedule.at(x.second+j)) {
                return true;
            }
            boolSchedule.at(x.second+j) = true;
        }
    }
    return false;
}

bool Schedule::inCommonStudents(Exam *currExam, Exam *exam) {
    return true;
}

bool Schedule::consecutiveDaysExams(int currExam, int exam)
{
    int day1 = currExam / HOURS_PER_DAY;
    int day2 = exam / HOURS_PER_DAY;
    return (abs(day1-day2) < 2);
}

double Schedule::calculateMaxRouletteProb(double minRouletteProb, double total) {
    this->maxRouletteProb = (double) this->fitness / total + minRouletteProb;
    return  this->maxRouletteProb;
}

void Schedule::updateSchedule(std::vector<pair<Exam *, int>> examSlot, int maxSlots)
{
    //exam slot
    this->examSlot = examSlot;

    //schedule
    for (int i = 0; i < maxSlots; ++i)
        schedule.push_back(NULL);

    for(auto &it: examSlot)
    {
        Exam * e = it.first;
        for (int i = 0; i < e->getDuration(); ++i) {
            schedule.at(it.second+i) = e;
        }
    }
    printExams();

    //fitness
    this->fitness = 0;

    //maxRouletteProb
    this->maxRouletteProb = 0;
}

void Schedule::printExams()
{
    cout << "Schedule " << id << endl;
    for (int i = 0; i < schedule.size(); ++i)
    {
        if(schedule.at(i) == NULL)
            cout << "   " << endl;
        else
            cout << "   " << i << " : " << schedule.at(i)->getInfo();
    }
    cout << "  slots " << endl;
    for (int j = 0; j < examSlot.size(); ++j)
    {
        pair<Exam *,int> x = (pair<Exam *, int> &&) examSlot.at(j);
        cout << "   " << x.first->getClassName() << " : " << x.second << endl;
    }

}

void Schedule::mutate(int slot)
{
    int random = rand() % schedule.size();
    this->examSlot.at(slot).second = random;
}

ostream& operator<<(ostream& out, const Schedule& s)
{
    out << "Schedule " << s.getID() << " : " << endl;
    for (int i = 0; i < s.getExamSlot().size(); ++i) {
        out << "   " << s.getExamSlot().at(i).first->getClassName() << " - " << s.getExamSlot().at(i).second << endl;
    }
    return out;
}
