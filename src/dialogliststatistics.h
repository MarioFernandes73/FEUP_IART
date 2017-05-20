#ifndef DIALOGLISTSTATISTICS_H
#define DIALOGLISTSTATISTICS_H

#include <QDialog>
#include "University.h"

namespace Ui {
class DialogListStatistics;
}

class DialogListStatistics : public QDialog
{
    Q_OBJECT



private:
    Ui::DialogListStatistics *ui;
    University * university;

public:
    explicit DialogListStatistics(string text, QWidget *parent = 0);
    void setUniversity(University * university){this->university = university;}
    ~DialogListStatistics();
};

#endif // DIALOGLISTSTATISTICS_H
