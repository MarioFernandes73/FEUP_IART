#include "dialoglistenrollments.h"
#include "ui_dialoglistenrollments.h"

Dialoglistenrollments::Dialoglistenrollments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoglistenrollments)
{
    ui->setupUi(this);
}

Dialoglistenrollments::~Dialoglistenrollments()
{
    delete ui;
}
