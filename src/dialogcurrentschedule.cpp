#include "dialogcurrentschedule.h"
#include "ui_dialogcurrentschedule.h"

#include <sstream>

DialogCurrentSchedule::DialogCurrentSchedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCurrentSchedule)
{
    ui->setupUi(this);
}

DialogCurrentSchedule::~DialogCurrentSchedule()
{
    delete ui;
}

void DialogCurrentSchedule::createSchedule()
{
    Epoch *epoch = this->university->getEpochByName("Normal");
    Schedule *s = epoch->getSchedule();
    struct tm initDate = epoch->getInitDate();
    int totalDays = epoch->getNumdays();
    int totalWeeks = (initDate.tm_wday+totalDays) / 7;

    if(totalWeeks%7 != 0)
        totalWeeks++;

    for (int var = 0; var < totalWeeks; ++var)
    {
        addTable(var);
        setHeader(var,initDate);
        setContent(var,s,initDate.tm_wday,totalDays);
    }

}

QString DialogCurrentSchedule::getDate(struct tm date, int i)
{
    int delta = i - date.tm_wday;

    time_t secs = mktime(&date)+delta*24*60*60;

    struct tm *newDate = gmtime(&secs);

    stringstream ss;
    ss << "\n" << newDate->tm_mday << "-" << newDate->tm_mon+1 << "-" << newDate->tm_year+1900;

    return QString::fromStdString(ss.str());
}

void DialogCurrentSchedule::addTable(int i)
{
    stringstream ss;
    ss << "table"<< i;

    QTableWidget *tableWidget = new QTableWidget(this);
    tableWidget->setObjectName(QString::fromStdString(ss.str()));
    tableWidget->setGeometry(QRect(10, 10, 720, 150));
    tableWidget->move(0,i*170);
    this->myTables.push_back(tableWidget);
}

void DialogCurrentSchedule::setHeader(int tableNum, struct tm initDate)
{
    //header
    QStringList header;
    QStringList weekday;
    weekday <<"Sunday" << "Monday" << "Tuesday"<< "Wenesday"<< "Thursady"<< "Friday"<<"Saturday";

    for(int i = 0; i < 7; i++)
    {
        QString name = weekday.at(i);
        QString date = getDate(initDate,i+tableNum*7);
        header << name.append(date);
    }

    myTables.at(tableNum)->setColumnCount(7);
    myTables.at(tableNum)->setHorizontalHeaderLabels(header);
}

void DialogCurrentSchedule::setContent(int tableNum, Schedule *s, int init, int totalDays)
{
    //conteudo
    int delta,row;
    int lastRow = -1;

    for(int col = 0; col < 7; col++)
    {
        row = -1;
        delta = col+tableNum*7 - init;

        //dias em que pode preencher o schedule
        if(delta >= 0 && delta < totalDays)
        {
            //exames desse dia
            vector<string> exams = s->getExamsAtDay(delta);

            for (int j = 0; j < exams.size(); ++j)
            {
                //so devemos inserir novas rows se ainda não foram inseridas (noutras colunas p.e)
                row++;
                if(row > lastRow){
                    lastRow = row;
                    myTables.at(tableNum)->insertRow(row);
                }
                QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(exams.at(j)));

                myTables.at(tableNum)->setItem(row,col,item);
            }
        }
    }
}
