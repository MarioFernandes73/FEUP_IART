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
    this->myClass = Class(name,0);
    currentId++;
}

Exam::Exam(int id, Class myClass) {
    this->id=id;
    currentId++;

    this->myClass = myClass;

    this->fitness = 0;
    this->duration = 2; //TODO receber este valor como parametro
}

Exam::~Exam() {
	// TODO Auto-generated destructor stub
}

string Exam::getInfo() const
{
    return (to_string(this->id) + " - " + this->myClass.getName() + ", " + to_string(this->myClass.getYear()) + "\n");
}

bool Exam::operator ==(const Exam * e1)const
{
    return (this->myClass.getName() == (*e1).myClass.getName()) && (e1->getId() == this->id);
}

int Exam::getDuration() const {
    return this->duration;
}

std::string Exam::getClassName() const {
    return this->myClass.getName();
}

void Exam::setClassName(std::string className) {
    this->myClass.setName(className);
}

long Exam::getYear() const{
    return this->myClass.getYear();
}

void Exam::setFitness(int i) {
    this->fitness = i;
}

int Exam::getId() const {
    return this->id;
}
