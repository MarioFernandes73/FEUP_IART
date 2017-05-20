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

    for (int i = 0; i < exams.size(); ++i)
    {
        ui->listWidget->insertItem(i,QString::fromStdString(exams.at(i)->displayInfo()));
    }
}
