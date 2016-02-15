#include "dialogadddata.h"
#include "ui_dialogadddata.h"

DialogAddData::DialogAddData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddData)
{
    ui->setupUi(this);
}

DialogAddData::~DialogAddData()
{
    delete ui;
}

void DialogAddData::on_pushButton_clicked()
{
    QString number, name, phone, email;
    number = ui->lineEdit->text();
    name = ui->lineEdit_2->text();
    phone = ui->lineEdit_3->text();
    email = ui->lineEdit_4->text();
}
