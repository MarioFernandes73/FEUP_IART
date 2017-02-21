/*
 * Exam.h
 *
 *  Created on: 21 Feb 2017
 *      Author: Mário
 */

#ifndef EXAM_H_
#define EXAM_H_

#include "Course.h"
#include "Schedule.h"

class Exam {
private:
	Schedule schedule;
public:
	Exam();
	virtual ~Exam();
};

#endif /* EXAM_H_ */
