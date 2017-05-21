#ifndef DIALOGGENERATESCHEDULE_H
#define DIALOGGENERATESCHEDULE_H

#include <QDialog>
#include "University.h"
#include "Genetic.h"
#include "SimulatedAnnealing.h"
#include "dialogcurrentschedule.h"

namespace Ui {
class DialogGenerateSchedule;
}

class DialogGenerateSchedule : public QDialog
{
    Q_OBJECT

private:
    Ui::DialogGenerateSchedule *ui;
    University * university;

public:
    explicit DialogGenerateSchedule(QWidget *parent = 0);
    void setUniversity(University * university);
    void showSchedule(string epoch, string stats);
    ~DialogGenerateSchedule();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // DIALOGGENERATESCHEDULE_H
