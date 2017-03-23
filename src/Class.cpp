//
// Created by gomes on 23/03/2017.
//

#include "Class.h"

Class::Class() {}

Class::Class(std::string name, int year) {
    this->name = name;
    this->year = year;
}

string Class::getName()const
{
    return this->name;
}

void Class::setName(string className)
{
    this->name = className;
}

void Class::setYear(int y) {
    this->year = y;
}

int Class::getYear() const {
    return this->year;
}
