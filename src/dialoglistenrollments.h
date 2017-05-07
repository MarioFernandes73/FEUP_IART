#ifndef DIALOGLISTENROLLMENTS_H
#define DIALOGLISTENROLLMENTS_H

#include <QDialog>

namespace Ui {
class Dialoglistenrollments;
}

class Dialoglistenrollments : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoglistenrollments(QWidget *parent = 0);
    ~Dialoglistenrollments();

private:
    Ui::Dialoglistenrollments *ui;
};

#endif // DIALOGLISTENROLLMENTS_H
