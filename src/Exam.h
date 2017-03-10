/*
 * Exam.h
 *
 *  Created on: 21 Feb 2017
 *
 */

#ifndef EXAM_H_
#define EXAM_H_

#include <string>

class Exam {
private:
    time_t startingTime;    //data e hora?
    int duration;
    int schoolYear;
    std::string className;
    int fitness;
    //epoca Normal/Recurso
public:
	Exam();
	virtual ~Exam();
};

#endif /* EXAM_H_ */
