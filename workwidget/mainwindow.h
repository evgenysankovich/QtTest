#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QTableView>
#include <QApplication>
#include <QSqlTableModel>
#include <QWidget>
#include "dialogadddata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_areaTable_objectNameChanged(const QString &objectName);

private:
    Ui::MainWindow *ui;
    bool createConnection();
    int createDatabase();
    int sqlQueryModel();
};

#endif // MAINWINDOW_H
