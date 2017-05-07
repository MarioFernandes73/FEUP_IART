#ifndef DIALOGLISTCOURSES_H
#define DIALOGLISTCOURSES_H

#include <QDialog>

namespace Ui {
class DialogListCourses;
}

class DialogListCourses : public QDialog
{
    Q_OBJECT

public:
    explicit DialogListCourses(QWidget *parent = 0);
    ~DialogListCourses();

private:
    Ui::DialogListCourses *ui;
};

#endif // DIALOGLISTCOURSES_H
