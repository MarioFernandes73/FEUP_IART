#include "dialogliststudents.h"
#include "ui_dialogliststudents.h"
#include "DialogCurrentSchedule.h"
#include <sstream>

DialogListStudents::DialogListStudents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListStudents)
{
    ui->setupUi(this);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(currentSchedule(QListWidgetItem*)));
}

void DialogListStudents::currentSchedule(QListWidgetItem* item)
{
    stringstream ss;
    ss << "No statistics to be shown." << endl << "Please generate a schedule.";
    DialogCurrentSchedule dialog(ss.str(),item->text().toLocal8Bit().constData());
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

    for (unsigned int i = 0; i < students.size(); ++i)
    {
        ui->listWidget->insertItem(i,QString::fromStdString(students.at(i)->getName()));
    }
}
