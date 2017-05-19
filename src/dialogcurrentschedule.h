#ifndef DIALOGCURRENTSCHEDULE_H
#define DIALOGCURRENTSCHEDULE_H

#include <QDialog>
#include <QTableWidget>
#include "University.h"

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
public:
    explicit DialogCurrentSchedule(string epoch, QWidget *parent = 0);
    void setUniversity(University * university){this->university = university;}
    void createSchedule(string epochName);
    void addTable(int i, int size);
    void setHeader(int tableNum, struct tm initDate);
    int setContent(int tableNum, Schedule *s, int init, int totalDays);
    QString getDate(struct tm date, int i);
    ~DialogCurrentSchedule();
private slots:
    void on_pushButton_clicked();
};

#endif // DIALOGCURRENTSCHEDULE_H
