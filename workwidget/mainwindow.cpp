#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //  createConnection();
    createDatabase();
  //  sqlQueryModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("addressbook");
    db.setUserName("admin");
//    db.setHostName("epica");
    db.setPassword("admin");
    if (!db.open()) {
        qDebug() << "Cannot open database: " <<db.lastError();
        return false;
    }
    qDebug() << "open database";
    return true;
}

int MainWindow::createDatabase()
{
    if (!createConnection()) {
        return -1;
    }

    QSqlQuery query;
    QString str = "CREATE TABLE addressbook ("
                    "number INTEGER PRIMARY KEY NOT NULL, "
                    "name VARCHAR(15), "
                    "phone VARCHAR(12), "
                    "email VARCHAR(15) "
                  ");";

    if (!query.exec(str)){
        qDebug()<<"Unable to create a table";
    }

    QString strF =
            "INSERT INTO addressbook (number, name, phone, email) "
            "VALUES('%1', '%2', '%3', '%4');";

    str = strF.arg("1")
            .arg("Piggy")
            .arg("+49 631322187")
            .arg("piggy@mega.de");
    if(!query.exec(str)){
        qDebug()<<"Unable to make insert operation";
    }

    if(!query.exec("SELECT * FROM addressbook;")){
        qDebug()<<"Unable to execute query - exiting";
        return 1;
    }

    QSqlRecord rec = query.record();
    int nNumber = 0;
    QString strName;
    QString strPhone;
    QString strEmail;

    while (query.next()) {
        nNumber = query.value(rec.indexOf("number")).toInt();
        strName = query.value(rec.indexOf("name")).toString();
        strPhone = query.value(rec.indexOf("phone")).toString();
        strEmail = query.value(rec.indexOf("email")).toString();
        qDebug()<<nNumber << " " <<strName << ";\t"
               <<strPhone << ";\t"<<strEmail;
    }

    return 0;

}

int MainWindow::sqlQueryModel()
{
   static QTableView *view = new QTableView();
   static QSqlTableModel *model = new QSqlTableModel();


    model->setTable("addressbook");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    view->setMinimumWidth(600);
    view->setModel(model);
    view->show();
    ui->areaTable->setModel(model);
//    this->setAttribute(Qt::WA_DeleteOnClose);
    //view->setWindowFlags(Qt::WA_DeleteOnClose);
   // model->setWindowFlags(Qt::WA_DeleteOnClose);

    return 0;
}

void MainWindow::on_pushButton_3_clicked()
{
    sqlQueryModel();
}

void MainWindow::on_pushButton_clicked()
{
    DialogAddData *dialogAdd = new DialogAddData();
    dialogAdd->setModal(true);
    dialogAdd->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    this->close();
}
