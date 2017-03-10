/*
 * Exam.h
 *
 *  Created on: 21 Feb 2017
 *
 */

#ifndef EXAM_H_
#define EXAM_H_

#include <string>

class Exam {
private:
    static int currentId;
    int id;

    time_t startingTime;    //data e hora?
    int duration;
    int schoolYear;
    std::string className;

    int fitness;
    //epoca Normal/Recurso
public:
    Exam(std::string className);
    virtual ~Exam();
    std::string getClassName()const;
    void setClassName(std::string className);
    std::string getInfo();
    bool operator==(const Exam * e1)const;
};

#endif /* EXAM_H_ */
