#include "add_info.h"
#include "ui_add_info.h"

Add_info::Add_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_info)
{
    ui->setupUi(this);
}

Add_info::~Add_info()
{
    delete ui;
}



void Add_info::on_pushButton_clicked()
{
    QString value1=ui->TransportName->text();
    int value2 = ui->Period->text().toInt();

    this->MyData.k1 = value2;
    ui->label->setNum(this->MyData.k1);
    //hide();
}

