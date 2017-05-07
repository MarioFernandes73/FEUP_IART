#ifndef DIALOGEDITEXAMS_H
#define DIALOGEDITEXAMS_H

#include <QDialog>

namespace Ui {
class DialogEditExams;
}

class DialogEditExams : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditExams(QWidget *parent = 0);
    ~DialogEditExams();

private:
    Ui::DialogEditExams *ui;
};

#endif // DIALOGEDITEXAMS_H
