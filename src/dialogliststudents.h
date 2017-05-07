#ifndef DIALOGLISTSTUDENTS_H
#define DIALOGLISTSTUDENTS_H

#include <QDialog>

namespace Ui {
class DialogListStudents;
}

class DialogListStudents : public QDialog
{
    Q_OBJECT

public:
    explicit DialogListStudents(QWidget *parent = 0);
    ~DialogListStudents();

private:
    Ui::DialogListStudents *ui;
};

#endif // DIALOGLISTSTUDENTS_H
