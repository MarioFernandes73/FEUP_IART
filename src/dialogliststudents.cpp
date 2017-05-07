#include "dialogliststudents.h"
#include "ui_dialogliststudents.h"

DialogListStudents::DialogListStudents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListStudents)
{
    ui->setupUi(this);
}

DialogListStudents::~DialogListStudents()
{
    delete ui;
}
