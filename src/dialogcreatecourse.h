#ifndef DIALOGCREATECOURSE_H
#define DIALOGCREATECOURSE_H

#include <QDialog>
#include "University.h"

namespace Ui {
class DialogCreateCourse;
}

class DialogCreateCourse : public QDialog
{
    Q_OBJECT



private:
    Ui::DialogCreateCourse *ui;
    University * university;

public:
    explicit DialogCreateCourse(QWidget *parent = 0);
    void setUniversity(University * university){this->university = university;}
    ~DialogCreateCourse();
};

#endif // DIALOGCREATECOURSE_H
