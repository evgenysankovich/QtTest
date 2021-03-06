#include "dialogadddata.h"
#include "ui_dialogadddata.h"

DialogAddData::DialogAddData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddData)
{
    ui->setupUi(this);
}

QString DialogAddData::number() const
{

    return ui->lineEdit->text();
}

QString DialogAddData::name() const
{
    return ui->lineEdit_2->text();
}

QString DialogAddData::phone() const
{
    return ui->lineEdit_3->text();
}

QString DialogAddData::email() const
{
    return ui->lineEdit_4->text();
}

DialogAddData::~DialogAddData()
{
    delete ui;
}

void DialogAddData::on_pushButton_clicked()
{

}

void DialogAddData::on_pushButton_2_clicked()
{
    this->close();
}
