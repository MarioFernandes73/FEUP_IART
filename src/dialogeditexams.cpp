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


    string startDate = ui->startingDate->text().toUtf8().constData();
    int code1 = checkDateFormat(startDate);
    if(code1 == -1){
        ui->dateLabel->setText(QString::fromStdString("Wrong date format."));
        return;
    }
    string endDate = ui->endingDate->text().toUtf8().constData();
    int code2 = checkDateFormat(endDate);
    if(code2 == -1){
        ui->dateLabel->setText(QString::fromStdString("Wrong date format."));
        return;
    }
            setDate(epoch, code1, code2);
            ui->dateLabel->setText(QString::fromStdString("Success."));
}

int DialogEditExams::checkDateFormat(string date){

    if(date == "")
        return 0;

    if(date.size() != 10){
        return -1;
    }

    for(unsigned int i = 0; i < date.size(); i++){
        if(i<=3 || i==5 || i==6 || i>=8)
            if(!isdigit(date[i]))
                return -1;
    }

    stringstream ss;
    int year, month, day;
    ss << date.substr(0,4);
    ss >> year;
    if(year < 1900 || year > 2100)
        return -1;
    ss.clear();
    ss.str("");
    ss << date.substr(5,7);
    ss >> month;
    if(month < 1 || month > 12)
        return -1;
    ss.clear();
    ss.str("");
    ss << date.substr(8,10);
    ss >> day;
    if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31))
        return -1;
    else if((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
        return -1;

    return 1;
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
        if(check){
            stringstream ss;
            ss << "Epoch happens at" << endl << "the same time as" << endl << this->university->getEpochs()[i]->getName();
            ui->dateLabel->setText(QString::fromStdString(ss.str()));
            return;
        }
    }
    stringstream ss;
    ss << "Epoch doesn't" << endl << "have a problem.";
    ui->dateLabel->setText(QString::fromStdString(ss.str()));
}

bool DialogEditExams::checkDate( struct tm  initDate1, struct tm  endDate1, struct tm  initDate2, struct tm  endDate2){

    struct tm * temp = &initDate1;
    time_t t1 = mktime(temp);
    temp = &endDate1;
    time_t t2 = mktime(temp);
    temp = &initDate2;
    time_t t3 = mktime(temp);
    temp = &endDate2;
    time_t t4 = mktime(temp);

    if(((difftime(t1, t3) >= 0) && (difftime(t3, t2) < 0)) || ((difftime(t1, t4) >= 0) && (difftime(t4, t2) < 0)) )
        return true;


    return false;
}

void DialogEditExams::setDate(Epoch * epoch, int code1, int code2){

    struct tm initDate;
    struct tm endDate;
    if(code1 == 0){
        initDate = epoch->getInitDate();
    } else {
        initDate = convertStringDate(ui->startingDate->text().toUtf8().constData());

    }

    if(code2 == 0){
        endDate = epoch->getEndDate();
    } else {
        endDate = convertStringDate(ui->endingDate->text().toUtf8().constData());
    }


    struct tm * temp = &initDate;
    time_t t1 = mktime(temp);
    temp = &endDate;
    time_t t2 = mktime(temp);

    cout << initDate.tm_year << endl;
    cout << endDate.tm_year << endl;
    cout << t1 << endl;
    cout << t2 << endl;
    cout << difftime(t1, t2) << endl;
    if(difftime(t1, t2) >= 0){
        stringstream ss;
        ss << "Ending date can't" << endl << "be lower than" << endl << "starting date.";

        ui->dateLabel->setText(QString::fromStdString(ss.str()));
        return;
    }

    if(code1 == 1)
    epoch->setEndDate(endDate.tm_year, endDate.tm_mon, endDate.tm_mday);
    if(code2 == 1)
    epoch->setInitDate(initDate.tm_year, initDate.tm_mon, initDate.tm_mday);
}

struct tm DialogEditExams::convertStringDate(string date){
    struct tm temp;
    stringstream ss;
    ss << date.substr(0,4);
    int tempYear;
    ss >> tempYear;
    temp.tm_year = tempYear-1900;

    ss.clear();
    ss.str("");
    ss << date.substr(5,7);
    int tempMonth;
    ss >> tempMonth;
    temp.tm_mon = tempMonth-1;

    ss.clear();
    ss.str("");
    ss << date.substr(8,10);
    ss >> temp.tm_mday;

    temp.tm_wday = (temp.tm_mday + 2*temp.tm_mon + 3*(temp.tm_mon+1)/5 + temp.tm_year + temp.tm_year/4 - temp.tm_year/100 + temp.tm_year/400 + 1) % 7;

    return temp;
}
