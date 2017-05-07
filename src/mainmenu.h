#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include "University.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT


private slots:

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::MainMenu *ui;
    University * university;

public:
    explicit MainMenu(QWidget *parent = 0);
    void setUniversity(University * university){this->university = university;}
    ~MainMenu();
};

#endif // MAINMENU_H
