#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "University.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



private slots:
    void on_MenuButton_clicked();

private:
    Ui::MainWindow *ui;
    University * university;

public:
    explicit MainWindow(QWidget *parent = 0);
    void setUniversity(University * university){this->university = university;}
    ~MainWindow();

};

#endif // MAINWINDOW_H
