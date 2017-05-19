#include "dialoggenerateschedule.h"
#include "ui_dialoggenerateschedule.h"

DialogGenerateSchedule::DialogGenerateSchedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGenerateSchedule)
{
    ui->setupUi(this);
}

DialogGenerateSchedule::~DialogGenerateSchedule()
{
    delete ui;
}

void DialogGenerateSchedule::on_pushButton_clicked()
{
    QString text = ui->epochName->text();
    Epoch * epoch = university->getEpochByName(text.toLocal8Bit().constData());
    if(epoch){
        Genetic algorithm(epoch,false,ui->populationLength->value());
        algorithm.run();
        this->close();
    }
}

void DialogGenerateSchedule::on_pushButton_2_clicked()
{
    QString text = ui->epochName->text();
    Epoch * epoch = university->getEpochByName(text.toLocal8Bit().constData());
    if(epoch){
        SimulatedAnnealing algorithm(epoch,true,ui->temp->value(),ui->red->value(),ui->acc->value());
        algorithm.run();
        cout << "ALL DONE" << endl;
        this->close();
    }
}
