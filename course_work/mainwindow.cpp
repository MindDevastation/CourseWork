#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ship.h"
#include <QString>
#include <iostream>
#include <QLineEdit>
#include <QtNumeric>
#include "add_info.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_2->setColumnCount(7);
    ui->tableWidget_2->setRowCount(5);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "First Station" << "Second Station"<< "Third Station" << "Fourth Station" << "Third Station" << "Second Station" << "First Station");
    ui->TransportNum->setEnabled(false);
    ui->Transport->addItem("Bus");
    ui->Transport->addItem("Autobus");
    ui->Transport->addItem("Plane");
    ui->Transport->addItem("Train");
    ui->TypeOfTransport->addItem("Bus");
    ui->TypeOfTransport->addItem("Autobus");
    ui->TypeOfTransport->addItem("Plane");
    ui->TypeOfTransport->addItem("Train");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //Testing fields:
    QString n = QString::fromStdString(this->MyData.transport[1]);
    int k;
    ui->label->setNum(this->train.train.decTOsix(this->train.train.hr[3], this->train.train.min[3]));
    ui->label_2->setNum(this->bus.bus.decTOsix(this->bus.bus.hr[3], this->bus.bus.min[3]));
//    int value = ui->lineEdit->text().toInt();
//    if (value + 5 == 5){
//        ui->label_3->setText("Error");
//    }else {
//        ui->label_3->setNum(value+5);
//    }
    int value = ui->HrEdit->text().toInt();
    this->bus.bus.setHr(1, value);  //set value to hr[1]
    ui->label_3->setNum(this->bus.bus.getHr(1));  //write value of hr[1] to label_3

    //Working part
    int current_TransportNum_index = ui->TransportNum->currentIndex();  //get index of Transport name
    int current_comboBox_index = ui->Transport->currentIndex();         //get index of Transport type

    //Fill table
    int s = 1;
    switch (current_comboBox_index) {
    case 0:
        for(int i = 0; i<ui->tableWidget_2->rowCount();i++){
            for(int j = 0; j<ui->tableWidget_2->columnCount();j++){
                QTableWidgetItem *tab = new QTableWidgetItem ("Error");
                ui->tableWidget_2->setItem(i, j, tab);
            }
        }
        break;
    case 1:
        for(int i = 0; i<ui->tableWidget_2->rowCount();i++){
            for(int j = 0; j<ui->tableWidget_2->columnCount();j++){
                QTableWidgetItem *tab = new QTableWidgetItem (QString::number(bus.bus.decTOsix(this->bus.bus.hr[current_TransportNum_index], this->bus.bus.min[current_TransportNum_index] + (this->bus.bus.period[current_TransportNum_index] * s))));
                ui->tableWidget_2->setItem(i, j, tab);
                s++;
            }
        }
        break;
    case 2:
        for(int i = 0; i<ui->tableWidget_2->rowCount();i++){
            for(int j = 0; j<ui->tableWidget_2->columnCount();j++){
                QTableWidgetItem *tab = new QTableWidgetItem (QString::number(ship.ship.decTOsix(this->train.train.hr[current_TransportNum_index], this->ship.ship.min[current_TransportNum_index] + (this->ship.ship.period[current_TransportNum_index] * s))));
                ui->tableWidget_2->setItem(i, j, tab);
                s++;
            }
        }
        break;
    case 3:
        for(int i = 0; i<ui->tableWidget_2->rowCount();i++){
            for(int j = 0; j<ui->tableWidget_2->columnCount();j++){
                QTableWidgetItem *tab = new QTableWidgetItem (QString::number(plane.plane.decTOsix(this->plane.plane.hr[current_TransportNum_index], this->plane.plane.min[current_TransportNum_index] + (this->plane.plane.period[current_TransportNum_index] * s))));
                ui->tableWidget_2->setItem(i, j, tab);
                s++;
            }
        }
        break;
    case 4:
        for(int i = 0; i<ui->tableWidget_2->rowCount();i++){
            for(int j = 0; j<ui->tableWidget_2->columnCount();j++){
                QTableWidgetItem *tab = new QTableWidgetItem (QString::number(train.train.decTOsix(this->train.train.hr[current_TransportNum_index], this->train.train.min[current_TransportNum_index] + (this->train.train.period[current_TransportNum_index] * s))));
                ui->tableWidget_2->setItem(i, j, tab);
                s++;
            }

        }
        break;
    }
}




void MainWindow::on_Transport_activated(int index)
{
    QString call = "0";

    if (index != 0){
        ui->TransportNum->setEnabled(true);
        switch (index) {
        case 1:
            for (int i = 3; i>=0 ; i--){
                ui->TransportNum->removeItem(i);
            }
            for (int i = 0; i<4 ; i++){
                call = QString::fromStdString(this->bus.bus.name[i]);
                ui->TransportNum->addItem(call);
            }
            break;
        case 2:
            for (int i = 3; i>=0 ; i--){
                ui->TransportNum->removeItem(i);
            }
            for (int i = 0; i<4 ; i++){
                call = QString::fromStdString(this->ship.ship.name[i]);
                ui->TransportNum->addItem(call);
            }
            break;
        case 3:
            for (int i = 3; i>=0 ; i--){
                ui->TransportNum->removeItem(i);
            }
            for (int i = 0; i<4 ; i++){
                call = QString::fromStdString(this->plane.plane.name[i]);
                ui->TransportNum->addItem(call);
            }
            break;
        case 4:
            for (int i = 3; i>=0 ; i--){
                ui->TransportNum->removeItem(i);
            }
            for (int i = 0; i < 4 ; i++){
                call = QString::fromStdString(this->train.train.name[i]);
                ui->TransportNum->addItem(call);
            }
        default:
            break;
        }

    }else{
        ui->TransportNum->setEnabled(false);
    }
}

//test
void MainWindow::on_Add_clicked()
{
    Add_info add;
    add.setModal(true);
    add.exec();
}

