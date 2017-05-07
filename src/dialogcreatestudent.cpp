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
