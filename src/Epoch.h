//
// Created by gomes on 23/03/2017.
//

#ifndef EXAMSCHEDULER_EPOCH_H
#define EXAMSCHEDULER_EPOCH_H

#include <string>
#include <ctime>
#include "Schedule.h"

class Epoch {
private:
    int id;
    static int currentId;
    //std::string schoolYear;
    int semester;
    std::string epochName;  //normal ou recurso
    struct tm initDate;
    struct tm endDate;
    int numDays;
    std::vector<Subscription *> subs;
    Schedule *global;
public:
    Epoch(std::string name, int day1, int month1, int year1, int day2, int month2, int year2);

    int getNumdays() const;
    std::string getName() const;
    int getId() const ;
    std::vector<Exam *> getExams() const;
    std::vector<Subscription *> getSubscriptions() const;
    int getWeekDay(int d, int m, int y);
    struct tm getInitDate() const;
    vector<Student *> getStudents(Exam *pExam) const;
    vector<string> getStudentExams(string student);
    Schedule * getSchedule();
    void setSchedule(Schedule *pSchedule);
    void addSubscription(Subscription *s);
    template<typename T>
    bool notFound(vector<T *> vector, T *temp) const;
    bool commonStudents(Exam *pExam, Exam *pExam1);
    bool deleteStudent(string examName, string studentName);
};


#endif //EXAMSCHEDULER_EPOCH_H
