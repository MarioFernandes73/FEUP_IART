/*
 * University.cpp
 *
 *  Created on: 21 Feb 2017
 *      Author: Mário
 */

#include <vector>

#include "University.h"
#include "MyExceptions.h"

#include <iostream>

using namespace std;

vector<Student *> University::getStudents()
{
	return this->students;
}

Student * University::findStudent(Student * tempStudent)
{

	for(vector<Student *>::iterator it = this->students.begin(); it != this->students.end(); it++)
	{
		//if((*it)->getName() == tempStudent->getName())
		if((*it) == tempStudent)
		{
			return (*it);
		}
	}

	throw elementNotInVectorException<Student *>(tempStudent);

	return NULL;
}

void University::addStudent(Student * newStudent)
{
	this->students.push_back(newStudent);
	return;
}

void University::removeStudent(Student * oldStudent)
{
	for(vector<Student *>::iterator it = this->students.begin(); it != this->students.end(); it++)
	{
		if((*it) == oldStudent)
		{
				this->students.erase(it);
				return;
		}
	}
	throw elementNotInVectorException<Student *>(oldStudent);
}
