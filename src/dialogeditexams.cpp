#include "dialogeditexams.h"
#include "ui_dialogeditexams.h"

DialogEditExams::DialogEditExams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditExams)
{
    ui->setupUi(this);
}

DialogEditExams::~DialogEditExams()
{
    delete ui;
}
