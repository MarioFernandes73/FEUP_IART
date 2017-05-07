#ifndef DIALOGLISTSTATISTICS_H
#define DIALOGLISTSTATISTICS_H

#include <QDialog>

namespace Ui {
class DialogListStatistics;
}

class DialogListStatistics : public QDialog
{
    Q_OBJECT

public:
    explicit DialogListStatistics(QWidget *parent = 0);
    ~DialogListStatistics();

private:
    Ui::DialogListStatistics *ui;
};

#endif // DIALOGLISTSTATISTICS_H
