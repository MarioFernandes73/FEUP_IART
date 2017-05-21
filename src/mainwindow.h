#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "University.h"
#include "Database.h"
#include <sstream>

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

public:
    explicit MainWindow(QWidget *parent = 0);
    University * loadUniversity();
    vector<Epoch *> loadEpochs(vector<vector<string>> epochsInfo);
    void loadSubscriptions(vector<vector<string>> subscribeInfo, University * university);
    vector<Exam *> loadExams(vector<vector<string>> examsInfo);
    vector<Student *> loadStudents(vector<vector<string>> studentsInfo);
    ~MainWindow();

};

#endif // MAINWINDOW_H
