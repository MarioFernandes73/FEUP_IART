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
