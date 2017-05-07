#include "dialogcreatecourse.h"
#include "ui_dialogcreatecourse.h"

DialogCreateCourse::DialogCreateCourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCreateCourse)
{
    ui->setupUi(this);
}

DialogCreateCourse::~DialogCreateCourse()
{
    delete ui;
}
