#include "dialogliststatistics.h"
#include "ui_dialogliststatistics.h"

DialogListStatistics::DialogListStatistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListStatistics)
{
    ui->setupUi(this);
}

DialogListStatistics::~DialogListStatistics()
{
    delete ui;
}
