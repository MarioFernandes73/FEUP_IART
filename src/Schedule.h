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

const static std::string weekDay[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


class Schedule {
private:
	std::vector<Exam *> schedule;
    int fitness;
public:
	Schedule();
	virtual ~Schedule();
};

#endif /* SCHEDULE_H_ */
