#include "dialogcurrentschedule.h"
#include "ui_dialogcurrentschedule.h"

#include <sstream>

DialogCurrentSchedule::DialogCurrentSchedule(string epoch,string statistics,string student,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCurrentSchedule)
{
    this->student = student;
    this->statisticsText = statistics;
    ui->setupUi(this);
    ui->lineEdit->setText(QString::fromStdString(epoch));
}

DialogCurrentSchedule::~DialogCurrentSchedule()
{
    delete ui;
}

void DialogCurrentSchedule::createSchedule(string epochName)
{
    bool isStud = false;
    Epoch *epoch = this->university->getEpochByName(epochName);
    if(!epoch)
        return;

    vector<string> filter;
    if(student != "")
    {
        isStud = true;
        filter = epoch->getStudentExams(student);
    }

    Schedule *s = epoch->getSchedule();
    if(s == NULL)
        return;

    struct tm initDate = epoch->getInitDate();
    int totalDays = epoch->getNumdays();
    int totalWeeks = (initDate.tm_wday+totalDays) / 7;

    if(totalWeeks%7 != 0)
        totalWeeks++;

    int size = 0;
    for (int var = 0; var < totalWeeks; ++var)
    {
        addTable(var,size);
        setHeader(var,initDate);
        size = setContent(var,s,initDate.tm_wday,totalDays,filter,isStud);
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

void DialogCurrentSchedule::addTable(int i, int size)
{
    stringstream ss;
    ss << "table"<< i;

    QTableWidget *tableWidget = new QTableWidget(this);
    tableWidget->setObjectName(QString::fromStdString(ss.str()));
    tableWidget->setGeometry(QRect(10, 10, 600, 200));
    tableWidget->move(0,250*i);
    this->myTables.push_back(tableWidget);
    tableWidget->show();
}

void DialogCurrentSchedule::setHeader(int tableNum, struct tm initDate)
{
    //header
    QStringList header;
    QStringList weekday;
    weekday <<"Sunday" << "Monday" << "Tuesday"<< "Wednesday"<< "Thursday"<< "Friday"<<"Saturday";

    for(int i = 0; i < 7; i++)
    {
        QString name = weekday.at(i);
        QString date = getDate(initDate,i+tableNum*7);
        header << name.append(date);
    }

    myTables.at(tableNum)->setColumnCount(7);
    myTables.at(tableNum)->setHorizontalHeaderLabels(header);
}

int DialogCurrentSchedule::setContent(int tableNum, Schedule *s, int init, int totalDays, vector<string> filter,bool isStud)
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
            vector<string> exams = s->getExamsAtDay(delta,filter,isStud);

            for (int j = 0; j < exams.size(); ++j)
            {
                //so devemos inserir novas rows se ainda não foram inseridas (noutras colunas p.e)
                row++;
                if(row > lastRow){
                    lastRow = row;
                    myTables.at(tableNum)->insertRow(row);
                    myTables.at(tableNum)->verticalHeader()->resizeSection(row, 80);
                }
                QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(exams.at(j)));

                myTables.at(tableNum)->setItem(row,col,item);
            }
        }
    }

     myTables.at(tableNum)->resizeColumnsToContents();
     myTables.at(tableNum)->resizeRowsToContents();

     return myTables.at(tableNum)->verticalHeader()->length();
}

void DialogCurrentSchedule::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    this->createSchedule(text.toLocal8Bit().constData());
}

void DialogCurrentSchedule::on_pushButton_2_clicked()
{
    DialogListStatistics dialogStatistics(this->statisticsText);
    dialogStatistics.setModal(true);
    dialogStatistics.exec();
}
