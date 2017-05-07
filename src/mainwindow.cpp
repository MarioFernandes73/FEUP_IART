#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainmenu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(720, 480));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MenuButton_clicked()
{
    MainMenu menuDialog;
    menuDialog.setModal(true);
    this->hide();
    menuDialog.exec();
    this->show();
}
