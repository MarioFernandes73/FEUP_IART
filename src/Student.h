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
	Student(int id, std::string name);
	virtual ~Student(){}
	int getId()const;
	std::string getName()const;
	void setName(std::string name);
	std::string getInfo();
	bool operator==(const Student * s1)const;
};

#endif /* STUDENT_H_ */
