#ifndef DIALOGLISTSTUDENTS_H
#define DIALOGLISTSTUDENTS_H

#include <QDialog>
#include <QListWidgetItem>
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

private slots:
    void currentSchedule(QListWidgetItem* item);

public:
    explicit DialogListStudents(QWidget *parent = 0);
    void setUniversity(University * university){this->university = university;}
    void fillList();
    ~DialogListStudents();
};

#endif // DIALOGLISTSTUDENTS_H
