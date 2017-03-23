//
// Created by gomes on 23/03/2017.
//

#ifndef EXAMSCHEDULER_EPOCH_H
#define EXAMSCHEDULER_EPOCH_H

#include <string>

class Epoch {
private:
    std::string name;
    int numDays; // vai ser tranformado em 2 datas
public:
    Epoch(std::string name, int numDays);
    int getNumdays();
    std::string getName();
};


#endif //EXAMSCHEDULER_EPOCH_H
