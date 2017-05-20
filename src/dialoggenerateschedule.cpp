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
        string stats = algorithm.getStatistics()->displayStatistics();
        showSchedule(text.toLocal8Bit().constData(), stats);
    }
}

void DialogGenerateSchedule::on_pushButton_2_clicked()
{
    QString text = ui->epochName->text();
    Epoch * epoch = university->getEpochByName(text.toLocal8Bit().constData());
    if(epoch){
        SimulatedAnnealing algorithm(epoch,false,ui->temp->value(),ui->red->value(),ui->acc->value());
        algorithm.run();
        this->close();
        string stats = algorithm.getStatistics()->displayStatistics();
        showSchedule(text.toLocal8Bit().constData(), stats);
    }
}

void DialogGenerateSchedule::showSchedule(string epoch, string stats){
    DialogCurrentSchedule dialog(epoch,stats,"");
    dialog.setUniversity(this->university);
    dialog.setModal(true);
    dialog.createSchedule(epoch);
    dialog.exec();
}
