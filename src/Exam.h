/*
 * Exam.h
 *
 *  Created on: 21 Feb 2017
 *
 */

#ifndef EXAM_H_
#define EXAM_H_

#include <string>
#include "Class.h"

class Exam {
private:
    static int currentId;
    int id;

    Class myClass;

    time_t startingTime;    //data e hora?
    int duration;

    int fitness;
    //epoca Normal/Recurso
public:
    Exam(string name);
    Exam(int id, Class myClass);
    virtual ~Exam();
    std::string getInfo();
    int getDuration();
    bool operator==(const Exam * e1)const;

    std::string getClassName()const;
    void setClassName(std::string className);

    long getYear();
};

#endif /* EXAM_H_ */
