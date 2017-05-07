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
    ~Dialoglistenrollments();
};

#endif // DIALOGLISTENROLLMENTS_H
