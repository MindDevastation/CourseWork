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

}

