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

void DialogEditExams::setUniversity(University * university)
{
    this->university = university;

    vector<Epoch *> epochs = this->university->getEpochs();
    for (unsigned int i = 0; i < epochs.size(); ++i){
        ui->comboBox->addItem(QString::fromStdString(epochs.at(i)->getName()));
    }
}

void DialogEditExams::on_comboBox_currentIndexChanged(const QString &arg1)
{
    Epoch *e = university->getEpochByName(arg1.toUtf8().constData());

    stringstream ss1;
    struct tm start = e->getInitDate();
    ss1 << start.tm_mday << "-" << start.tm_mon+1<< "-"<< start.tm_year+1900;
    ui->startLabel->setText(QString::fromStdString(ss1.str()));

    stringstream ss2;
    struct tm end = e->getEndDate();
    ss2 << end.tm_mday << "-" << end.tm_mon +1<< "-"<< end.tm_year+1900;
    ui->endLabel->setText(QString::fromStdString(ss2.str()));
}

void DialogEditExams::on_pushButton_clicked()
{
    Epoch * epoch = this->university->getEpochByName(ui->comboBox->currentText().toUtf8().constData());

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

bool DialogEditExams::checkAllDates()
{
    QDate startDate = ui->widgetStart->selectedDate();
            //ui->widgetStart->date();
    QDate endDate = ui->widgetEnd->selectedDate();
    Epoch * epoch = this->university->getEpochByName(ui->comboBox->currentText().toUtf8().constData());

    for(unsigned int i = 0; i< this->university->getEpochs().size(); i++)
    {
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

void DialogEditExams::setDates()
{
    QDate startDate = ui->widgetStart->selectedDate();
    QDate endDate = ui->widgetEnd->selectedDate();
    Epoch * epoch = this->university->getEpochByName(ui->comboBox->currentText().toUtf8().constData());
    epoch->setInitDate(startDate.year(), startDate.month(), startDate.day());
    epoch->setEndDate(endDate.year(), endDate.month(), endDate.day());
}

bool DialogEditExams::validateDates()
{
    QDate startDate = ui->widgetStart->selectedDate();
    QDate endDate = ui->widgetEnd->selectedDate();

    if(startDate > endDate){
        return false;
    }
    return true;
}


void DialogEditExams::on_pushButton_2_clicked()
{
    Epoch * epoch = this->university->getEpochByName(ui->comboBox->currentText().toUtf8().constData());

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
    /*ui->widgetStart->setDate(t1);
    ui->widgetEnd->setDate(t2);*/
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
