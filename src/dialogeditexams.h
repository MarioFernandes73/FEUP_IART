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
    void setUniversity(University * university);
    bool validateDates();
    bool checkDate( struct tm  initDate1, struct tm  endDate1, struct tm  initDate2, struct tm  endDate2);
    bool checkAllDates();
    void setDates();
    ~DialogEditExams();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_comboBox_currentIndexChanged(const QString &arg1);
};

#endif // DIALOGEDITEXAMS_H
