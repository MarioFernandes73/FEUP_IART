#include "dialoggenerateschedule.h"
#include "ui_dialoggenerateschedule.h"

DialogGenerateSchedule::DialogGenerateSchedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGenerateSchedule)
{
    ui->setupUi(this);
}

DialogGenerateSchedule::~DialogGenerateSchedule()
{
    delete ui;
}
