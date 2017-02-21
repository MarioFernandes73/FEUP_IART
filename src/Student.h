/*
 * Student.h
 *
 *  Created on: 21 Feb 2017
 *      Author: Mário
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "Course.h"
#include <string>
#include <vector>

class Student {
private:
	int id;
	std::string nome;
	std::vector<Course *> courses;
public:
	Student();
	virtual ~Student();
};

#endif /* STUDENT_H_ */
