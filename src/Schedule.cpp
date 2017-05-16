/*
 * Schedule.cpp
 *
 *  Created on: 21 Feb 2017
 *
 */

#include "Schedule.h"
#include "Utils.h"
#include <cmath>

using namespace std;

int Schedule::currentId = 1;

Schedule::Schedule(bool debug) {
    this->id = currentId;
    currentId++;
    this->debug = debug;
}

Schedule::~Schedule() {
    // TODO Auto-generated destructor stub
}

void Schedule::setID(int id){
    this->id = id;
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

void Schedule::setSubscriptions(std::vector<Subscription *>subs){
    this->subs = subs;
}

void Schedule::setFirstWeekDay(int i){
    this->firstWeekDay = i;
}

void Schedule::setDebug(bool d){
    debug = d;
}

void Schedule::addExams(std::vector<Exam *> vector, std::vector<pair<Exam *, int>> examSlot)
{
    this->schedule = vector;
    this->examSlot = examSlot;
    this->fitness = 0;
    this->maxRouletteProb = 0;
}

vector<string> Schedule::getExamsAtDay(int day)
{
    int hours = HOURS_PER_DAY;
    vector<string> exams;

    for (int var = 0; var < examSlot.size(); ++var)
    {
        int slot = examSlot.at(var).second;
        int initHour = 10+slot%hours;
        if(slot/hours == day)
        {
            string date = examSlot.at(var).first->displayExam()+
                    "\n"+to_string(initHour)+":00\n"+to_string(initHour+examSlot.at(var).first->getDuration())+":00";
            exams.push_back(date);

            cout << date << endl;
        }
    }
    return exams;
}

bool Schedule::createRandomSchedule(std::vector<Exam *> exams, int maxSlots)
{
    if(debug)
        cout << "Filling schedule " << this->id<< endl;

    int hours = HOURS_PER_DAY;

    this->schedule.clear();
    this->examSlot.clear();

    //initialize all booleans = false and exams to NULL
    for (int i = 0; i < maxSlots; ++i) {
        schedule.push_back(NULL);
    }

    int j = 0;
    while(j < exams.size())
    {
        Exam * chosen = exams.at(j);

        //random position
        pair<Exam *,int> myPair = std::make_pair<Exam *,int>((Exam *&&) chosen, (int &&) -1);
        vector<int> possiblePos = getPossiblePositions(myPair);

        if(possiblePos.size() == 0)
            return false;

        int random = rand() % possiblePos.size();
        myPair.second = possiblePos.at(random);

        //update examSlot
        examSlot.push_back(myPair);

        //update schedule
        for (int i = 0; i < chosen->getDuration(); ++i)
            schedule.at(myPair.second+i) = chosen;

        j++;
    }
    return true;
}

void Schedule::optimize()
{
    if(debug)
        cout << "Optimizing...\n";

    for (int i = 0; i < examSlot.size(); ++i)
    {
        Exam *e1 = examSlot.at(i).first;
        for (int j = 0; j < examSlot.size(); ++j)
        {
            Exam *e2 = examSlot.at(j).first;

            if(!(e1 == e2))                                                             //not the same exam
                if(consecutiveDaysExams(examSlot.at(i).second,examSlot.at(j).second))   //consecutive days
                    if(commonStudents(e1,e2))                                           //common students
                        updateExamPosition(examSlot.at(j));                             //incompatible
        }
    }
}

void Schedule::updateExamPosition(pair<Exam *,int> exam)
{
    vector<int> possiblePos = getPossiblePositions(exam);

    //escolher aleatoriamente a posicao
    if (possiblePos.size() > 0) {
        int random = rand() % possiblePos.size();

        if(debug)
            cout << "  New pos : " << possiblePos.at(random) << endl;

        //retiro o exame da sua posicao atual no schedule
        //colocar na sua nova posicao
        for (int k = 0; k < exam.first->getDuration(); ++k) {
            schedule.at(exam.second + k) = NULL;
            schedule.at(possiblePos.at(random) + k) = exam.first;
        }

        //atualizar os slots
        for (int l = 0; l < examSlot.size(); ++l) {
            if (examSlot.at(l).first == exam.first)
                examSlot.at(l).second = possiblePos.at(random);
        }
    }
    else if(debug)
        cout << "Problem with " << exam.first->getClassName() << endl;
}

vector<int> Schedule::getPossiblePositions(pair<Exam *,int> exam) {
    vector<int> pos;
    int hours = HOURS_PER_DAY;
    int currWeekDay = firstWeekDay;

    //cria vetor com todas as posicoes exceto fins de semana
    for (int i = 0; i < schedule.size(); ++i)
    {
        if(i % hours == 0)  //new day
            if(i != 0)     //not the first one
                currWeekDay = (currWeekDay +1) % 7;

        //0 - SUNDAY and 6 - SATURDAY
         if(!(currWeekDay == 0 || currWeekDay == 6))
              pos.push_back(i);
    }

    //retirar aqueles cuja duracao excede o dia
    int l = 0;
    while(l < pos.size())
    {
        int day1 = pos.at(l) / hours;
        int day2 = (pos.at(l) + exam.first->getDuration()-1) / hours;

        if (day1 != day2)
            pos = removeFromVector(pos,pos.at(l),pos.at(l)+exam.first->getDuration()-1);
        else
            l++;
    }

    for (int j = 0; j < examSlot.size(); ++j)
    {
        if(!(examSlot.at(j).first == exam.first))
        {
            //retira as posicoes do exame com que estamos a compara
            pos = removeFromVector(pos,examSlot.at(j).second,examSlot.at(j).second+examSlot.at(j).first->getDuration());

            //se tiver estudantes em comum, as posicoes deixam de ser possiveis
            if(commonStudents(examSlot.at(j).first,exam.first))
            {
                int currDay = examSlot.at(j).second / hours;
                int a,b;
                a = (currDay-1)*hours;
                b = (currDay+2)*hours-1;
                if(a < 0)
                    a = 0;
                if(b >= schedule.size())
                    b = schedule.size()-1;

                pos = removeFromVector(pos,a,b);
            }
        }
    }

    //retirar os que podem sobrepor exames
    l=0;
    while(l < pos.size())
    {
        bool removed = false;
        int firstPos = pos.at(l);

        for (int i = 0; i < exam.first->getDuration(); ++i)
        {
                if(l+i >= pos.size())
                    removed = true;
                else if(firstPos+i != pos.at(l+i))
                    removed = true;

                if(removed)
                {
                    pos = removeFromVector(pos,firstPos,firstPos+i-1);
                    break;
                }
        }

        if(!removed)
            l++;
    }

    if(debug)
    {
        cout << "  Possible positions : ";
        for (int k = 0; k < pos.size(); ++k) {
            cout << pos.at(k) << " , ";
        }
        cout << endl;
    }

    return pos;
}

std::vector<int> Schedule::removeFromVector(std::vector<int>vector,int a,int b){
    int i = 0;
    while (i < vector.size())
    {
        if(vector.at(i) >= a && vector.at(i) <= b){
            vector.erase(vector.begin()+i);
        }
        else
            i++;
    }
    return vector;
}


bool Schedule::commonStudents(Exam *e1, Exam *e2)
{
    vector<Student *> s1;
    vector<Student *> s2;
    for (int k = 0; k < subs.size(); ++k) {
        if(e1 == subs.at(k)->getExam())
            s1.push_back(subs.at(k)->getStudent());
        else if(e2 == subs.at(k)->getExam())
            s2.push_back(subs.at(k)->getStudent());
    }

    for (int i = 0; i < s1.size(); ++i) {
        for (int j = 0; j < s2.size(); ++j) {
            if(s1.at(i) == s2.at(j)) {
                return true;
            }
        }
    }
    return false;
}

int Schedule::calculateFitness()
{
    //reinit this values every time
    this->fitness = 0;
    this->maxRouletteProb = 0;

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
                //exams have student in common and aren't at the same day or at consecutive days
                if(commonStudents(exam,currExam))
                {
                    if(!consecutiveDaysExams(x.second, y.second))
                    {
                        multiplier = 5 - abs(currExam->getYear() - exam->getYear());
                        distance = abs(x.second - y.second);
                        fitness += distance*multiplier;
                    } else
                    {
                        this->fitness = 0;
                        return -1;  //isto nao deve acontecer
                    }
                }
            }
        }

        if(debug)
            cout << x.first->getClassName() << " "<< fitness << endl;

        this->fitness += fitness;       //fitness schedule
        currExam->setFitness(fitness);   //fitness exam
    }

    return fitness;
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
    if(debug)
        cout << "Updating schedule...\n";

    std::vector<pair<Exam *, int>> malformedExams;

    //fitness
    this->fitness = 0;

    //maxRouletteProb
    this->maxRouletteProb = 0;

    //exam slot
    this->examSlot = examSlot;

    //schedule
    for (int i = 0; i < maxSlots; ++i)
        schedule.push_back(NULL);

    for(auto &it: examSlot)
    {
        Exam * e = it.first;
        for (int i = 0; i < e->getDuration(); ++i)
        {
            if(schedule.at(it.second+i) == NULL)
                schedule.at(it.second+i) = e;
            else{
                if(debug)
                    cout << " - " << it.first->getClassName() << endl;

                malformedExams.push_back(it);
                if(i != 0)
                    for (int j = i-1; j >= 0; j--)
                        schedule.at(it.second+j) = NULL;
                break;
            }
        }
    }
    //new place for malformed exams
    for (int k = 0; k < malformedExams.size(); ++k)
        updateExamPosition(malformedExams.at(k));

    optimize();
}

void Schedule::printExams()
{
    cout << "Print exams from Schedule " << id << endl;
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
    pair<Exam *,int> myPair = std::make_pair<Exam *,int>((Exam *&&) this->examSlot.at(slot), (int &&) -1);
    vector<int> possiblePos = getPossiblePositions(myPair);
    int random = rand() % possiblePos.size();
    this->examSlot.at(slot).second = possiblePos.at(random);

    optimize();
}

ostream& operator<<(ostream& out, const Schedule& s)
{
    out << "Schedule " << s.getID() << " : " << endl;
    for (int i = 0; i < s.getExamSlot().size(); ++i) {
        out << "   " << s.getExamSlot().at(i).first->getClassName() << " - " << s.getExamSlot().at(i).second << endl;
    }
    return out;
}
