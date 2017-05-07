#ifndef DIALOGLISTSTUDENTS_H
#define DIALOGLISTSTUDENTS_H

#include <QDialog>
#include "University.h"

namespace Ui {
class DialogListStudents;
}

class DialogListStudents : public QDialog
{
    Q_OBJECT



private:
    Ui::DialogListStudents *ui;
    University * university;

public:
    explicit DialogListStudents(QWidget *parent = 0);
    void setUniversity(University * university){this->university = university;}
    ~DialogListStudents();
};

#endif // DIALOGLISTSTUDENTS_H
