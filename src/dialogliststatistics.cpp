#include "dialogliststatistics.h"
#include "ui_dialogliststatistics.h"

DialogListStatistics::DialogListStatistics(string text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListStatistics)
{
    ui->setupUi(this);
    ui->textBrowser->setText(QString::fromStdString(text));
}

DialogListStatistics::~DialogListStatistics()
{
    delete ui;
}
