#ifndef EXAMSCHEDULER_CLASS_H
#define EXAMSCHEDULER_CLASS_H

#include <iostream>
#include <string>
using namespace std;

class Class {
private:
    std::string name;
    int year;
public:
    Class(std::string name, int year);
    Class();
    string getName() const;
    void setName(string name);
    int getYear() const;
    void setYear(int y);
};

#endif //EXAMSCHEDULER_CLASS_H
