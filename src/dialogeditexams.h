#ifndef DIALOGEDITEXAMS_H
#define DIALOGEDITEXAMS_H

#include <QDialog>
#include "University.h"

namespace Ui {
class DialogEditExams;
}

class DialogEditExams : public QDialog
{
    Q_OBJECT



private:
    Ui::DialogEditExams *ui;
    University * university;

public:
    explicit DialogEditExams(QWidget *parent = 0);
    void setUniversity(University * university){this->university = university;}
    ~DialogEditExams();
};

#endif // DIALOGEDITEXAMS_H
