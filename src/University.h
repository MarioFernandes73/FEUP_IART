/*
 * University.h
 *
 *  Created on: 21 Feb 2017
 *      Author: Mário
 */

#ifndef UNIVERSITY_H_
#define UNIVERSITY_H_

#include "Student.h"

class University {
private:
	std::string name;
	std::vector<Student *> students;
public:
	University(){}
	virtual ~University(){}
	std::vector<Student *> getStudents();
};

#endif /* UNIVERSITY_H_ */
