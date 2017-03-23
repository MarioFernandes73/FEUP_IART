/*
 * Schedule.cpp
 *
 *  Created on: 21 Feb 2017
 *
 */

#include "Schedule.h"
#include <cmath>

using namespace std;

Schedule::Schedule() {

}

Schedule::~Schedule() {
	// TODO Auto-generated destructor stub
}

void Schedule::addExams(std::vector<Exam *> vector, std::unordered_map<Exam *, int> examSlot)
{
    this->schedule = vector;
    this->examSlot = examSlot;
    this->fitness = 0;
}

void Schedule::printExams()
{

    cout << "Schedule " << endl;
    for (int i = 0; i < schedule.size(); ++i)
    {
        if(schedule.at(i) == NULL)
            cout << "   " << endl;
        else
            cout << "   " << i << " : " << schedule.at(i)->getInfo();
    }
    cout << "  slots " << endl;
    for (pair<Exam *const, int> & x: examSlot)
        cout << "   " << x.first->getClassName() << " : " << x.second << endl;

}

void Schedule::calculateFitness()
{
    for (pair<Exam *const, int> & x: examSlot)
    {
        int fitness = 0;
        int multiplier = 0;
        int distance = 0;
        Exam * currExam = x.first;

        //compares current exam with all the other exams
        for (pair<Exam *const, int> & y: examSlot)
        {
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
        cout << currExam->getClassName() << " " << fitness<<endl;
    }
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
