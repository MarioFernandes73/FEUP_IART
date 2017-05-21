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

void DialogCreateCourse::on_pushButton_clicked()
{
    this->university->addExam(new Exam(Class(ui->courseName->text().toUtf8().constData(),ui->examYear->value()),ui->examDuration->value()));
}
