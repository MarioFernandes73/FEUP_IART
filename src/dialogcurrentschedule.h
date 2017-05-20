#ifndef DIALOGCURRENTSCHEDULE_H
#define DIALOGCURRENTSCHEDULE_H

#include <QDialog>
#include <QTableWidget>
#include "University.h"
#include "dialogliststatistics.h"

namespace Ui {
class DialogCurrentSchedule;
}

class DialogCurrentSchedule : public QDialog
{
    Q_OBJECT



private:
    Ui::DialogCurrentSchedule *ui;
    University * university;
    std::vector<QTableWidget *> myTables;
    std::string statisticsText;
    std::string student;
public:
    explicit DialogCurrentSchedule(string epoch, string statistics, string student, QWidget *parent = 0);
    void setUniversity(University * u);
    void createSchedule(string epochName);
    void addTable(int i, int size);
    void setHeader(int tableNum, struct tm initDate);
    int setContent(int tableNum, Schedule *s, int init, int totalDays, vector<string> filter, bool isStud);
    QString getDate(struct tm date, int i);
    vector<string> filterMyExams(vector<string> schedule, vector<string> subscriptions);
    ~DialogCurrentSchedule();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // DIALOGCURRENTSCHEDULE_H
