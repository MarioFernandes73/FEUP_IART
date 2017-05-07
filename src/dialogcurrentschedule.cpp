#include "dialogcurrentschedule.h"
#include "ui_dialogcurrentschedule.h"

DialogCurrentSchedule::DialogCurrentSchedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCurrentSchedule)
{
    ui->setupUi(this);
}

DialogCurrentSchedule::~DialogCurrentSchedule()
{
    delete ui;
}
