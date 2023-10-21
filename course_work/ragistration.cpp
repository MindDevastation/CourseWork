#include "ragistration.h"
#include "ui_ragistration.h"

ragistration::ragistration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ragistration)
{
    ui->setupUi(this);

}

ragistration::~ragistration()
{
    delete ui;
}

void ragistration::on_pushButton_clicked()
{
    emit signal(ui->lineEdit->text());
    close();
}

