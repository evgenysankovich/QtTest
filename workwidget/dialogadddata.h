#ifndef DIALOGADDDATA_H
#define DIALOGADDDATA_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class DialogAddData;
}

class DialogAddData : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddData(QWidget *parent = 0);
    ~DialogAddData();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogAddData *ui;
};

#endif // DIALOGADDDATA_H
