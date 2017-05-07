#include "studentsmenu.h"
#include "ui_studentsmenu.h"

StudentsMenu::StudentsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentsMenu)
{
    ui->setupUi(this);
}

StudentsMenu::~StudentsMenu()
{
    delete ui;
}

void StudentsMenu::on_pushButton_clicked()
{
    this->close();
}
