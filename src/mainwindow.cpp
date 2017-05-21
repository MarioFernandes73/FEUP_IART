#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainmenu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(720, 480));
    ui->Background->setPixmap(QPixmap("schedule.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MenuButton_clicked()
{
    University * university = loadUniversity();
    MainMenu menuDialog; 
    menuDialog.setUniversity(university);
    menuDialog.setModal(true);
    this->hide();
    menuDialog.exec();
    this->show();
}

University * MainWindow::loadUniversity(){
    //random numbers
    srand ((unsigned int) time(NULL));

    // database variables
    Database *db;

    //char *filename = (char *) "iart3.db";       // release
    char *filename;
    if(ui->comboBox->currentIndex() == 0)
        filename = (char *) "../iart3.db";
    else if(ui->comboBox->currentIndex()==1)
        filename = (char *) "../iart.db";


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

    return university;
}

//read students
vector<Student *> MainWindow::loadStudents(vector<vector<string>> studentsInfo)
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
vector<Exam *> MainWindow::loadExams(vector<vector<string>> examsInfo)
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
void MainWindow::loadSubscriptions(vector<vector<string>> subscribeInfo, University * university)
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

vector<Epoch *> MainWindow::loadEpochs(vector<vector<string>> epochsInfo)
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
