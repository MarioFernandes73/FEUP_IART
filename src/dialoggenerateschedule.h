#ifndef DIALOGGENERATESCHEDULE_H
#define DIALOGGENERATESCHEDULE_H

#include <QDialog>

namespace Ui {
class DialogGenerateSchedule;
}

class DialogGenerateSchedule : public QDialog
{
    Q_OBJECT

public:
    explicit DialogGenerateSchedule(QWidget *parent = 0);
    ~DialogGenerateSchedule();

private:
    Ui::DialogGenerateSchedule *ui;
};

#endif // DIALOGGENERATESCHEDULE_H
