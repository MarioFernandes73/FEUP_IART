#ifndef EXAMSCHEDULER_EPOCH_H
#define EXAMSCHEDULER_EPOCH_H

#include <string>
#include <ctime>
#include "Schedule.h"

class Epoch {
private:
    int id;
    static int currentId;
    std::string epochName;  //normal ou recurso
    struct tm initDate;
    struct tm endDate;
    int numDays;
    std::vector<Subscription *> subs;
    Schedule *global;
public:
    Epoch(std::string name, int day1, int month1, int year1, int day2, int month2, int year2);

    std::string getName() const;
    int getId() const ;
    Schedule * getSchedule();
    void setSchedule(Schedule *pSchedule);

    struct tm getInitDate() const;
    struct tm getEndDate() const{return this->endDate;}
    void setInitDate(int year, int month, int day);
    void setEndDate(int year, int month, int day);
    int getNumdays() const;

    std::vector<Subscription *> getSubscriptions() const;
    std::vector<Exam *> getExams() const;
    vector<Student *> getStudents(Exam *pExam) const;
    vector<string> getStudentExams(string student);

    bool deleteStudent(string examName, string studentName);
    bool addStudentExam(Student * student, Exam * exam );
    void addSubscription(Subscription *s);

    template<typename T>
    bool notFound(vector<T *> vector, T *temp) const;
    bool commonStudents(Exam *pExam, Exam *pExam1);

    int getWeekDay(int d, int m, int y);
};


#endif //EXAMSCHEDULER_EPOCH_H
