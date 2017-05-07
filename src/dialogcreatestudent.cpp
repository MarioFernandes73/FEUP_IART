#include "dialogcreatestudent.h"
#include "ui_dialogcreatestudent.h"

DialogCreateStudent::DialogCreateStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCreateStudent)
{
    ui->setupUi(this);
}

DialogCreateStudent::~DialogCreateStudent()
{
    delete ui;
}

void DialogCreateStudent::on_pushButton_2_clicked()
{
    QString text = ui->studentName->toPlainText();
    string studentname = text.toLocal8Bit().constData();
    this->university->addStudent(new Student(studentname));
    this->close();
}
