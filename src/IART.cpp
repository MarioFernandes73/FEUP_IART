//============================================================================
// Name        : IART.cpp
// Author      : Catarina Ramos, Ines Gomes and Mario Fernandes
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <sstream>

#include "Database.h"
#include "University.h"
#include "Genetic.h"
#include "SimulatedAnnealing.h"
#include "mainwindow.h"
#include <QApplication>

using namespace std;

vector<Student *> loadStudents(vector<vector<string>> studentsInfo);
vector<Exam *> loadExams(vector<vector<string>> examsInfo);
vector<Epoch *> loadEpochs(vector<vector<string>> epochsInfo);
void loadSubscriptions(vector<vector<string>> subscribeInfo, University * university);

int main(int argc, char* argv[]) {

    //random numbers
    srand ((unsigned int) time(NULL));

    // database variables
    Database *db;

    char *filename = (char *) "../iart3.db";         // QT
    //char *filename = (char *) "../proj/iart.db";  //clion
    //char * filename = (char*)"iart.db";           //eclipse

    char *selectStudentQuery = (char *) "SELECT * FROM Student";
    char *selectExamQuery = (char *) "SELECT * FROM Exam";
    char *selectSubscribeQuery = (char *) "SELECT * FROM Subscription";
    char *selectEpochQuery = (char *) "SELECT * FROM Epoch";

    // database operations
    db = new Database(filename);
    db->open();

    //load students and exams
    vector<Student *> students = loadStudents(db->query(selectStudentQuery));
    vector<Exam *> exams = loadExams(db->query(selectExamQuery));

    // university initialization and epoch
    University * university = new University(students,exams);
    vector<Epoch *> epochs = loadEpochs(db->query(selectEpochQuery));
    for(vector<Epoch * >::iterator it = epochs.begin(); it < epochs.end(); ++it){
        university->addEpoch(*it);
    }

    //load subscriptions of students to exams
    loadSubscriptions(db->query(selectSubscribeQuery), university);

    db->close();

    //interface
    //initialOptions(university);

    //TESTE
/*
    Schedule *s = Algorithm::createRandomSchedule(false,e);
    vector<Schedule *> pop = Genetic::populate(e,40,false);
    s->calculateFitness();

    cout << "Fitness: " << s->getFitness() << endl;
    cout << *s << endl;
*/
    /*for(Schedule * s: pop){
        cout << *s << endl;
    }*/

   //genetic algorithm
    /*
    Epoch * temp = university->getEpochByName("Normal");
    Genetic algorithm1(temp,false,40);
    algorithm1.run();
    //e->getSchedule()->printExams();
    //Simulated Annealing

    cout << endl << "1 iteration" << endl << endl;
    Schedule *s1 = new Schedule(false);
    *s1 = *s;
    Epoch *e1 = new Epoch("Normal",8,5,2017,26,5,2017);
    *e1 = *e;
    SimulatedAnnealing algorithm2(e1,false,40,1,0,s1);
    algorithm2.run();

    cout << endl << "2 iteration" << endl << endl;
    Schedule *s2 = new Schedule(false);
    *s2 = *s;
    Epoch *e2 = new Epoch("Normal",8,5,2017,26,5,2017);
    *e2 = *e;
    SimulatedAnnealing algorithm3(e2,false,40,1,10,s2);
    algorithm3.run();

    cout << endl << "3 iteration" << endl << endl;
    Schedule *s3 = new Schedule(false);
    *s3 = *s;
    Epoch *e3 = new Epoch("Normal",8,5,2017,26,5,2017);
    *e3 = *e;
    SimulatedAnnealing algorithm4(e3,false,40,1,20,s3);
    algorithm4.run();

    cout << endl << "4 iteration" << endl << endl;
    Schedule *s4 = new Schedule(false);
    *s4 = *s;
    Epoch *e4 = new Epoch("Normal",8,5,2017,26,5,2017);
    *e4 = *e;
    SimulatedAnnealing algorithm5(e4,false,40,1,30,s4);
    algorithm5.run();

    cout << endl << "5 iteration" << endl << endl;
    Schedule *s5 = new Schedule(false);
    *s5 = *s;
    Epoch *e5 = new Epoch("Normal",8,5,2017,26,5,2017);
    *e5 = *e;
    SimulatedAnnealing algorithm6(e5,false,40,1,40,s5);
    algorithm6.run();


    cout << endl << "6 iteration" << endl << endl;
    Schedule *s6 = new Schedule(false);
    *s6 = *s;
    Epoch *e6 = new Epoch("Normal",8,5,2017,26,5,2017);
    *e6 = *e;
    SimulatedAnnealing algorithm7(e6,false,40,1,50,s6);
    algorithm7.run();*/

    //save .db

    //Qt setup
    QApplication a(argc, argv);
    MainWindow w;
    w.setUniversity(university);
    w.show();

    return a.exec();
}

//read students
vector<Student *> loadStudents(vector<vector<string>> studentsInfo)
{
    vector<Student *> students;

    for (vector<vector<string> >::iterator it = studentsInfo.begin(); it < studentsInfo.end(); ++it)
    {
        int student_id;
        string name="";
        stringstream ss;

        for (vector<string>::iterator it2 = (*it).begin(); it2 < (*it).end(); it2++){
            ss << (*it2);
        }

        int i = 0;
        while(!ss.eof()){
            if(i==0){
                ss >> student_id;
                i++;
            }
            else{
                string temp;
                ss >> temp;
                if(ss.eof()){
                    name+=temp;
                } else {
                    name += temp + " ";
                }

            }
        }

        students.push_back(new Student(student_id, name));
    }

    return students;
}

 //read exams
vector<Exam *> loadExams(vector<vector<string>> examsInfo)
{
    vector<Exam *> exams;

    for (vector<vector<string> >::iterator it = examsInfo.begin(); it < examsInfo.end(); ++it)
    {   
        int exam_id, year, duration;
        string className;
        char c;
        stringstream ss;

        int i = 0;
        for (vector<string>::iterator it2 = (*it).begin(); it2 < (*it).end(); it2++){
            if(i == 1)
               className = (*it2);
            else
                ss << (*it2) << "x";
            i++;
        }
        ss >> exam_id >> c >> year >> c >> duration;

        exams.push_back(new Exam(exam_id, Class(className,year),duration));
    }

    return exams;
}

//read subscribes
void loadSubscriptions(vector<vector<string>> subscribeInfo, University * university)
{
    for (vector<vector<string> >::iterator it = subscribeInfo.begin(); it < subscribeInfo.end(); ++it)
    {
        int exam_id = 0, student_id = 0, epoch_id = 0;
        char c;
        stringstream ss;

        for (vector<string>::iterator it2 = (*it).begin(); it2 < (*it).end(); it2++)
            ss << (*it2) << ",";

        ss >> epoch_id >> c >> exam_id >> c >> student_id;

        university->addSubscription(epoch_id,exam_id,student_id);
    }
}

vector<Epoch *> loadEpochs(vector<vector<string>> epochsInfo)
{
    vector<Epoch *> epochs;

    for (vector<vector<string> >::iterator it = epochsInfo.begin(); it < epochsInfo.end(); ++it)
    {
        char c;
        int day1, month1, year1;
        int day2, month2, year2;
        string name;
        stringstream ss, ss2;

        int i = 0;
        for (vector<string>::iterator it2 = (*it).begin(); it2 < (*it).end(); it2++){
            if( i == 0)
                name = *it2;
            else if(i == 1)
                ss << *it2;
            else
                ss2 << *it2;
            i++;
        }
        ss >> year1 >> c >> month1 >> c >> day1;
        ss2 >> year2 >> c >> month2 >> c >> day2;
        //cout << name << " " << day1 << " " << month1 << " " << year1 << " " << day2 << " " << month2 << " " << year2 <<endl;
        epochs.push_back(new Epoch(name, day1, month1, year1, day2, month2, year2));
    }

    return epochs;
}
