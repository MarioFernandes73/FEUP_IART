#ifndef DIALOGLISTCOURSES_H
#define DIALOGLISTCOURSES_H

#include <QDialog>
#include "University.h"

namespace Ui {
class DialogListCourses;
}

class DialogListCourses : public QDialog
{
    Q_OBJECT

private:
    Ui::DialogListCourses *ui;
    University * university;

public:
    explicit DialogListCourses(QWidget *parent = 0);
    void setUniversity(University * university){this->university = university;}
    void fillList();
    ~DialogListCourses();
};

#endif // DIALOGLISTCOURSES_H
