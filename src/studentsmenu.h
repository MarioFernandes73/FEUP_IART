#ifndef STUDENTSMENU_H
#define STUDENTSMENU_H

#include <QDialog>

namespace Ui {
class StudentsMenu;
}

class StudentsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StudentsMenu(QWidget *parent = 0);
    ~StudentsMenu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StudentsMenu *ui;
};

#endif // STUDENTSMENU_H
