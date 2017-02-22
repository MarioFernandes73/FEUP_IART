/*
 * Student.cpp
 *
 *  Created on: 21 Feb 2017
 *      Author: M�rio
 */

#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

int Student::currentId = 1;

Student::Student(std::string name)
{
	this->id = currentId;
	this->name = name;
	currentId++;
}

string Student::getName()const
{
	return this->name;
}

void Student::setName(string name)
{
	this->name = name;
}

bool Student::operator ==(const Student * s1)const
{
	return this->getName() == (*s1).getName();
}
