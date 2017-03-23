//
// Created by gomes on 23/03/2017.
//

#include "Epoch.h"

Epoch::Epoch(std::string name, int numDays)
{
    this->name = name;
    this->numDays = numDays;
}



int Epoch::getNumdays() {
    return this->numDays;
}

std::string Epoch::getName() {
    return this->name;
}

