#include "dialogliststudents.h"
#include "ui_dialogliststudents.h"
#include "DialogCurrentSchedule.h"

DialogListStudents::DialogListStudents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListStudents)
{
    ui->setupUi(this);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(currentSchedule(QListWidgetItem*)));
}

void DialogListStudents::currentSchedule(QListWidgetItem* item)
{
    DialogCurrentSchedule dialog("");
    dialog.setUniversity(this->university);
    dialog.setModal(true);
    dialog.exec();
}

DialogListStudents::~DialogListStudents()
{
    delete ui;
}

void DialogListStudents::fillList()
{
    vector<Student *> students = this->university->getStudents();

    for (int i = 0; i < students.size(); ++i)
    {
        ui->listWidget->insertItem(i,QString::fromStdString(students.at(i)->getInfo()));
    }
}
