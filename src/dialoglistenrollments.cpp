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

void Dialoglistenrollments::createList(Epoch * epoch){
int lineCounter = 0;
    for(unsigned int i = 0; i< epoch->getExams().size(); i++){
        ui->list->insertItem(lineCounter,QString::fromStdString(epoch->getExams()[i]->displayInfo()));
        lineCounter ++;
        for(unsigned int j = 0; j < epoch->getStudents(epoch->getExams()[i]).size(); j++){
            lineCounter ++;
            ui->list->insertItem(lineCounter,QString::fromStdString("   * " + epoch->getStudents(epoch->getExams()[i])[j]->getInfo()));
        }
        lineCounter++;
    }

}

void Dialoglistenrollments::on_pushButton_clicked()
{
    string epochName = this->ui->comboBox->currentText().toUtf8().constData();
    Epoch * epoch = this->university->getEpochByName(epochName);
    if(epoch)
        createList(epoch);
}

void Dialoglistenrollments::on_pushButton_2_clicked()
{
    //add
    string studentName = ui->studentName->text().toUtf8().constData();
    string examName = ui->examName->text().toUtf8().constData();

    Epoch * currentEpoch = this->university->addStudentExam(studentName, examName);

    if(!currentEpoch)
        return;

    ui->list->clear();
    this->createList(currentEpoch);
}

void Dialoglistenrollments::on_pushButton_3_clicked()
{
    //remove
    string studentName = ui->studentName->text().toUtf8().constData();
    string examName = ui->examName->text().toUtf8().constData();

    Epoch * currentEpoch = this->university->deleteStudent(studentName,examName);

    if(!currentEpoch)
        return;

    ui->list->clear();
    this->createList(currentEpoch);


}
