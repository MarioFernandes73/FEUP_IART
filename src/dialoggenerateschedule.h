#ifndef DIALOGGENERATESCHEDULE_H
#define DIALOGGENERATESCHEDULE_H

#include <QDialog>
#include "University.h"

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
    void setUniversity(University * university){this->university = university;}
    ~DialogGenerateSchedule();
};

#endif // DIALOGGENERATESCHEDULE_H
