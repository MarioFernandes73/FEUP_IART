#ifndef DIALOGLISTENROLLMENTS_H
#define DIALOGLISTENROLLMENTS_H

#include <QDialog>
#include "University.h"

namespace Ui {
class Dialoglistenrollments;
}

class Dialoglistenrollments : public QDialog
{
    Q_OBJECT



private:
    Ui::Dialoglistenrollments *ui;
    University * university;

public:
    explicit Dialoglistenrollments(QWidget *parent = 0);
    void setUniversity(University * university){this->university = university;}
    void createList(Epoch * epoch);
    ~Dialoglistenrollments();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // DIALOGLISTENROLLMENTS_H
