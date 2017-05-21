#include "dialogeditexams.h"
#include "ui_dialogeditexams.h"
#include <sstream>
#include <time.h>

DialogEditExams::DialogEditExams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditExams)
{
    ui->setupUi(this);
}

DialogEditExams::~DialogEditExams()
{
    delete ui;
}

void DialogEditExams::on_pushButton_clicked()
{
    Epoch * epoch = this->university->getEpochByName(ui->epochName->text().toUtf8().constData());

    if(!epoch){
        stringstream ss;
        ss << "Please insert epoch's " << endl << "name.";
        ui->dateLabel->setText(QString::fromStdString(ss.str()));
        return;
    }

    if(!validateDates()){
        stringstream ss;
        ss << "Starting date has " << endl << " to be after" << endl <<"Ending date.";
        ui->dateLabel->setText(QString::fromStdString(ss.str()));
        return;
    }

    stringstream ss;
    if(!checkAllDates())
        ss << "Success but epoch" << endl << "happens at the same" << endl <<"time has another one.";
    else
        ss << "Success!" << endl;

    ui->dateLabel->setText(QString::fromStdString(ss.str()));

    setDates();
}

bool DialogEditExams::checkAllDates(){
    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();
    Epoch * epoch = this->university->getEpochByName(ui->epochName->text().toUtf8().constData());
    for(unsigned int i = 0; i< this->university->getEpochs().size(); i++){
        Epoch * currentEpoch = this->university->getEpochs()[i];
        if(currentEpoch->getName() == epoch->getName())
            continue;
        QDate currentEpochStart = QDate(currentEpoch->getInitDate().tm_year+1900,currentEpoch->getInitDate().tm_mon+1, currentEpoch->getInitDate().tm_mday);
        QDate currentEpochEnd = QDate(currentEpoch->getEndDate().tm_year+1900,currentEpoch->getEndDate().tm_mon+1, currentEpoch->getEndDate().tm_mday);
        if((currentEpochStart < startDate && startDate < currentEpochEnd) || (currentEpochStart < endDate && endDate < currentEpochEnd) || (startDate < currentEpochStart && currentEpochStart < endDate))
            return false;
    }

    return true;
}

void DialogEditExams::setDates(){
    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();
    Epoch * epoch = this->university->getEpochByName(ui->epochName->text().toUtf8().constData());
    epoch->setInitDate(startDate.year(), startDate.month(), startDate.day());
    epoch->setEndDate(endDate.year(), endDate.month(), endDate.day());
}

bool DialogEditExams::validateDates(){
    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();

    if(startDate > endDate){
        return false;
    }
    return true;
}


void DialogEditExams::on_pushButton_2_clicked()
{
    Epoch * epoch = this->university->getEpochByName(ui->epochName->text().toUtf8().constData());

    if(!epoch)
        return;

    for(unsigned int i = 0; i < this->university->getEpochs().size(); i++){
        if(epoch->getName() == this->university->getEpochs()[i]->getName())
            continue;
        bool check = checkDate(epoch->getInitDate(), epoch->getEndDate(), this->university->getEpochs()[i]->getInitDate(), this->university->getEpochs()[i]->getEndDate());
        if(!check){
            stringstream ss;
            ss << "Epoch happens at" << endl << "the same time as" << endl << this->university->getEpochs()[i]->getName();
            ui->dateLabel->setText(QString::fromStdString(ss.str()));
            return;
        }
    }
    stringstream ss;
    ss << "Epoch doesn't" << endl << "have a problem.";
    ui->dateLabel->setText(QString::fromStdString(ss.str()));


    QDate t1 = QDate(epoch->getInitDate().tm_year+1900, epoch->getInitDate().tm_mon+1, epoch->getInitDate().tm_mday);
    QDate t2 = QDate(epoch->getEndDate().tm_year+1900, epoch->getEndDate().tm_mon+1, epoch->getEndDate().tm_mday);
    ui->startDateEdit->setDate(t1);
    ui->endDateEdit->setDate(t2);
}

bool DialogEditExams::checkDate( struct tm  initDate1, struct tm  endDate1, struct tm  initDate2, struct tm  endDate2){

    QDate t1 = QDate(initDate1.tm_year+1900, initDate1.tm_mon+1, initDate1.tm_mday);
    QDate t2 = QDate(endDate1.tm_year+1900, endDate1.tm_mon+1, endDate1.tm_mday);
    QDate t3 = QDate(initDate2.tm_year+1900, initDate2.tm_mon+1, initDate2.tm_mday);
    QDate t4 = QDate(endDate2.tm_year+1900, endDate2.tm_mon+1, endDate2.tm_mday);

    if((t1 < t3 && t3 < t2) || (t1 < t4 && t4 < t2) || (t3 < t1 && t1 < t4) )
        return false;

    return true;
}
