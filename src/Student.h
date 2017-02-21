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
	static int currentId;
	int id;
	std::string name;
	std::vector<Course *> courses;
public:
	Student(){}
	Student(std::string name);
	virtual ~Student(){}
	std::string getName()const;
	void setName(std::string name);
	friend bool operator==(const Student &s1, const Student &s2);
	bool operator==(const Student &s1);
};

#endif /* STUDENT_H_ */
