#ifndef DIALOGCURRENTSCHEDULE_H
#define DIALOGCURRENTSCHEDULE_H

#include <QDialog>
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

public:
    explicit DialogCurrentSchedule(QWidget *parent = 0);
    void setUniversity(University * university){this->university = university;}
    ~DialogCurrentSchedule();
};

#endif // DIALOGCURRENTSCHEDULE_H
