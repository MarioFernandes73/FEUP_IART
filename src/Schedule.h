/*
 * Schedule.h
 *
 *  Created on: 21 Feb 2017
 *
 */

#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "time.h"
#include "Subscription.h"
#include <string>
#include <vector>

const static std::string weekDay[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

class Schedule {

private:
    static int currentId;
    int id;
    vector<Exam *> schedule;
    vector<pair<Exam *, int>> examSlot;
    int fitness;
    double maxRouletteProb;
    int firstWeekDay;
    bool debug;
    vector<Subscription *> subs;
public:
    Schedule(bool debug);
	virtual ~Schedule();
    int getFitness() const;
    void setFitness(int f);
    double getmaxRouletteProb() const;
    void setmaxRouletteProb(double mrp);
    void setID(int id);
    int getID() const;
    int getNumExams() const;
    std::vector<pair<Exam *, int>> getExamSlot() const;
	void addExams(std::vector<Exam *> vector, std::vector<pair<Exam *, int>> examSlot);
    void setSubscriptions(vector<Subscription *> vector);
    void setFirstWeekDay(int i);
    void setDebug(bool debug);
    std::vector<string> getExamsAtDay(int day);
	void printExams();

    bool createRandomSchedule(vector<Exam *> vector, int maxSlots);

    void optimize();
    void updateExamPosition(pair<Exam *,int> exam);
	bool commonStudents(Exam *e1, Exam *e2);
    vector<int> getPossiblePositions(pair<Exam *,int> exam);
    vector<int> removeFromVector(vector<int> vector, int a, int b);

    int calculateFitness();
    bool consecutiveDaysExams(int currExam, int exam);
    double calculateMaxRouletteProb(double minRouletteProb, double total);

    void updateSchedule(std::vector<pair<Exam *, int>> examSlot, int maxSlots);
    void mutate(int slot);

    friend ostream& operator<<(ostream& os, const Schedule& s);
};

#endif /* SCHEDULE_H_ */
