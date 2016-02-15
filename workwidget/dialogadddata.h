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
    QString number() const;
    QString name() const;
    QString phone() const;
    QString email() const;
    ~DialogAddData();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::DialogAddData *ui;
};

#endif // DIALOGADDDATA_H
