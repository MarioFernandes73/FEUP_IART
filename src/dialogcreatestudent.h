#ifndef DIALOGCREATESTUDENT_H
#define DIALOGCREATESTUDENT_H

#include <QDialog>
#include "University.h"

namespace Ui {
class DialogCreateStudent;
}

class DialogCreateStudent : public QDialog
{
    Q_OBJECT



private slots:
    void on_pushButton_2_clicked();

private:
    Ui::DialogCreateStudent *ui;
    University * university;
public:
    explicit DialogCreateStudent(QWidget *parent = 0);
    void setUniversity(University * university){this->university = university;}
    ~DialogCreateStudent();
};

#endif // DIALOGCREATESTUDENT_H
