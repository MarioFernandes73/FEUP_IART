#include <vector>

#include "University.h"
#include "MyExceptions.h"
#include "Epoch.h"

#include <iostream>

using namespace std;

University::University(vector<Student *> students, vector<Exam *> exams)
{
    this->students = students;
    this->exams = exams;
}

vector<Student *> University::getStudents()
{
    return this->students;
}

Student *University::findStudent(Student *tempStudent)
{
    for (vector<Student *>::iterator it = this->students.begin(); it != this->students.end(); it++) {
        if ((**it) == tempStudent) {
            return (*it);
        }
    }

    throw elementNotInVectorException<Student *>(tempStudent);

    return NULL;
}

void University::addStudent(Student *newStudent)
{
    this->students.push_back(newStudent);
    return;
}

void University::removeStudent(Student *oldStudent)
{
    for (vector<Student *>::iterator it = this->students.begin(); it != this->students.end(); it++) {
        if ((**it) == oldStudent) {
            this->students.erase(it);
            return;
        }
    }
    throw elementNotInVectorException<Student *>(oldStudent);
}

void University::addExam(Exam *newExam)
{
    this->exams.push_back(newExam);
    return;
}

vector<Exam *> University::getExams()
{
    return this->exams;
}

Exam *University::findExam(Exam *tempExam)
{
    for (vector<Exam *>::iterator it = this->exams.begin(); it != this->exams.end(); it++) {
        if ((**it) == tempExam) {
            return (*it);
        }
    }

    throw elementNotInVectorException<Exam *>(tempExam);

    return NULL;
}

void University::removeExam(Exam *oldExam)
{
    for (vector<Exam *>::iterator it = this->exams.begin(); it != this->exams.end(); it++) {
        if ((**it) == oldExam) {
            this->exams.erase(it);
            return;
        }
    }
    throw elementNotInVectorException<Exam *>(oldExam);
}

void University::addEpoch(Epoch * e) {
    epochs.push_back(e);
}

Epoch * University::getEpochByName(string name)
{
    for (unsigned int i = 0; i < epochs.size(); ++i) {
        if(name == epochs.at(i)->getName())
            return epochs.at(i);
    }
    return NULL;
}

std::vector<Epoch *> University::getEpochs(){
    return epochs;
}

void University::addSubscription(int epochId, int examId, int studentId)
{

    Exam *e = findById(exams,examId);
    Student *s = findById(students,studentId);
    Epoch *epoch = findById(epochs,epochId);

    epoch->addSubscription(new Subscription(s,e));

}

template<typename T>
T* University::findById(vector<T*> vec, int id)
{
    for (unsigned int i = 0; i < vec.size(); ++i)
        if(vec.at(i)->getId() == id)
            return vec.at(i);
    return nullptr;
}

int University::getExamId(string examName){
    for(unsigned int i = 0; i < this->getEpochs().size(); i++){
        for(unsigned int j = 0; j < this->getEpochs()[i]->getExams().size(); j++){
            if(this->getEpochs()[i]->getExams()[j]->getClassName() == examName){
                return this->getEpochs()[i]->getExams()[j]->getId();

            }
        }
    }
    return -1;
}

int University::getStudentId(string studentName){
    for(unsigned int i = 0; i < this->getStudents().size(); i++){
        if(this->getStudents()[i]->getName() == studentName){
            return this->getStudents()[i]->getId();
        }
    }
    return -1;
}

Epoch * University::deleteStudent(string studentName, string examName){
    for(unsigned int i = 0; i < this->getEpochs().size(); i++){
        if(this->getEpochs()[i]->deleteStudent(examName,studentName))
            return this->getEpochs()[i];
    }
    return NULL;
}

Epoch * University::addStudentExam(string studentName, string examName){

    Student * student = NULL;
    Exam * exam = NULL;
    for(unsigned int i = 0; i<  this->getStudents().size(); i++){
        if(this->getStudents()[i]->getName() == studentName){
            student = this->getStudents()[i];
            break;
        }
    }
    if(!student)
        return NULL;

    for(unsigned int i = 0; i < this->getExams().size(); i++){
        if(this->getExams()[i]->getClassName() == examName){
            exam = this->getExams()[i];
            break;
        }
    }

    if(!exam)
        return NULL;

    for(unsigned int i = 0; i < this->getEpochs().size(); i++){
        this->getEpochs()[i]->addStudentExam(student, exam);
    }

    return this->getEpochs()[0];
}
