#ifndef DIALOGCURRENTSCHEDULE_H
#define DIALOGCURRENTSCHEDULE_H

#include <QDialog>

namespace Ui {
class DialogCurrentSchedule;
}

class DialogCurrentSchedule : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCurrentSchedule(QWidget *parent = 0);
    ~DialogCurrentSchedule();

private:
    Ui::DialogCurrentSchedule *ui;
};

#endif // DIALOGCURRENTSCHEDULE_H
