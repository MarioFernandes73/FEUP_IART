/*
 * Exam.cpp
 *
 *  Created on: 21 Feb 2017
 *
 */

#include "Exam.h"
#include <iostream>
using namespace std;

int Exam::currentId = 1;

Exam::Exam(string name) {
    this->id = currentId;
    this->className = name;
    currentId++;
}

Exam::Exam(int id, std::string name)
{
    this->id=id;
    this->className = name;
    currentId++;
}

Exam::~Exam() {
	// TODO Auto-generated destructor stub
}

string Exam::getClassName()const
{
    return this->className;
}

void Exam::setClassName(string className)
{
    this->className = className;
}

string Exam::getInfo()
{
    string info = (to_string(this->id) + " - " + this->className + "\n");
    return info;
}

bool Exam::operator ==(const Exam * e1)const
{
    return this->getClassName() == (*e1).getClassName();
}

