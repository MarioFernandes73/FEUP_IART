/*
 * Schedule.h
 *
 *  Created on: 21 Feb 2017
 *      Author: Mário
 */

#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "time.h"
#include <string>

const static std::string weekDay[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


class Schedule {
private:
	time_t startingTime;
	time_t endingTime;
public:
	Schedule();
	virtual ~Schedule();
};

#endif /* SCHEDULE_H_ */
