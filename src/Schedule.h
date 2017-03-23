/*
 * Schedule.h
 *
 *  Created on: 21 Feb 2017
 *
 */

#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "time.h"
#include "Exam.h"
#include <string>
#include <vector>
#include <unordered_map>

const static std::string weekDay[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


class Schedule {
private:
	std::vector<Exam *> schedule;
    std::unordered_map<Exam *, int> examSlot;
    int fitness;
public:
	Schedule();
	virtual ~Schedule();

	void addExams(std::vector<Exam *> vector, std::unordered_map<Exam *, int> examSlot);
	void printExams();

    void calculateFitness();
    bool inCommonStudents(Exam * currExam, Exam * exam);
    bool consecutiveDaysExams(Exam * currExam, Exam * exam);
};

#endif /* SCHEDULE_H_ */
