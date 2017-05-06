/*
 * Student.cpp
 *
 *  Created on: 21 Feb 2017
 *
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
Student::Student(int id, std::string name)
{
	this->id = id;
	this->name = name;
	currentId++;
}

int Student::getId()const
{
	return this->id;
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

string Student::getInfo()
{
	string info = (to_string(this->id) + " - " + this->name + "\n");
	return info;
}
