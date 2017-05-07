#ifndef DIALOGCREATESTUDENT_H
#define DIALOGCREATESTUDENT_H

#include <QDialog>

namespace Ui {
class DialogCreateStudent;
}

class DialogCreateStudent : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreateStudent(QWidget *parent = 0);
    ~DialogCreateStudent();

private:
    Ui::DialogCreateStudent *ui;
};

#endif // DIALOGCREATESTUDENT_H
