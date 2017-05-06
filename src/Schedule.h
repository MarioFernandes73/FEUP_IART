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
	std::vector<Exam *> schedule;
    std::vector<pair<Exam *, int>> examSlot;
    int fitness;
    double maxRouletteProb;

    vector<Subscription *> subs;
public:
	Schedule();
	virtual ~Schedule();
    int getFitness() const;
    void setFitness(int f);
    double getmaxRouletteProb() const;
    void setmaxRouletteProb(double mrp);
    int getID() const;
    int getNumExams() const;
    std::vector<pair<Exam *, int>> getExamSlot() const;
	void addExams(std::vector<Exam *> vector, std::vector<pair<Exam *, int>> examSlot);
    void setSubscriptions(vector<Subscription *> vector);
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
