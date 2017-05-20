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
    int duration;
    int fitness;
public:
    Exam(string name);
    Exam(int id, Class myClass, int duration);
    virtual ~Exam();
    std::string getInfo() const;
    std::string displayExam() const;
    std::string displayInfo() const;
    int getDuration() const;
    int getId() const;
    long getYear() const;
    std::string getClassName()const;
    void setClassName(std::string className);
    void setFitness(int i);

    bool operator==(const Exam * e1)const;
};

#endif /* EXAM_H_ */
