#include "dialoglistcourses.h"
#include "ui_dialoglistcourses.h"

DialogListCourses::DialogListCourses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListCourses)
{
    ui->setupUi(this);
}

DialogListCourses::~DialogListCourses()
{
    delete ui;
}

void DialogListCourses::fillList()
{
    vector<Exam *> exams = this->university->getExams();

    QStringList header;
    header << "ID"<<"Class Name" << "Year"<< "Duration";
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(header);

    for(unsigned int i = 0; i < exams.size(); ++i)
    {
        ui->tableWidget->insertRow(i);

        QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(exams.at(i)->getId()));
        ui->tableWidget->setItem(i,0,item1);
        QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString(exams.at(i)->getClassName()));
        ui->tableWidget->setItem(i,1,item2);
        QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(exams.at(i)->getYear()));
        ui->tableWidget->setItem(i,2,item3);
        QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(exams.at(i)->getDuration()));
        ui->tableWidget->setItem(i,3,item4);
    }
}
