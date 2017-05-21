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
    bool checkDate( struct tm initDate1, struct tm endDate1, struct tm initDate2, struct tm endDate2);
    int checkDateFormat(string date);
    void setDate(Epoch * epoch, int code1, int code2);
    struct tm convertStringDate(string date);
    ~DialogEditExams();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // DIALOGEDITEXAMS_H
