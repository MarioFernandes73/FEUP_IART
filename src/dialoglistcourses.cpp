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
