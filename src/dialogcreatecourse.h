#ifndef DIALOGCREATECOURSE_H
#define DIALOGCREATECOURSE_H

#include <QDialog>

namespace Ui {
class DialogCreateCourse;
}

class DialogCreateCourse : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreateCourse(QWidget *parent = 0);
    ~DialogCreateCourse();

private:
    Ui::DialogCreateCourse *ui;
};

#endif // DIALOGCREATECOURSE_H
