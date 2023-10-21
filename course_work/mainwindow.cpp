#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ship.h"
#include <QString>
#include <iostream>
#include <QLineEdit>
#include <QtNumeric>
#include "ragistration.h"
#include <QPixmap>
#include <QMessageBox>
#include <QApplication>
#include <QDate>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    registration = new ragistration(this);
    connect(registration, &ragistration::signal, this, &MainWindow::slot);

    ui->TransportNum->setEnabled(false);
    ui->TransportNameIndex->setEnabled(false);
    ui->TransportNameIndex_3->setEnabled(false);

    ui->tableWidget_2->setColumnCount(7);
    ui->tableWidget_2->setRowCount(15);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "First Station" << "Second Station"<< "Third Station" << "Fourth Station" << "Third Station" << "Second Station" << "First Station");

    ui->Add->setEnabled(false);
    ui->Edit->setEnabled(false);
    ui->Delete->setEnabled(false);
    ui->Search->setEnabled(false);

    ui->Transport->addItem("Bus");
    ui->Transport->addItem("Ship");
    ui->Transport->addItem("Plane");
    ui->Transport->addItem("Train");

    ui->TypeOfTransport->addItem("Bus");
    ui->TypeOfTransport->addItem("Ship");
    ui->TypeOfTransport->addItem("Plane");
    ui->TypeOfTransport->addItem("Train");

    ui->TypeOfTransport_2->addItem("Bus");
    ui->TypeOfTransport_2->addItem("Ship");
    ui->TypeOfTransport_2->addItem("Plane");
    ui->TypeOfTransport_2->addItem("Train");

    ui->TypeOfTransport_3->addItem("Bus");
    ui->TypeOfTransport_3->addItem("Ship");
    ui->TypeOfTransport_3->addItem("Plane");
    ui->TypeOfTransport_3->addItem("Train");

    QDateTime qdt = QDateTime::currentDateTime();
    ui->label_3->setText(qdt.toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Search_clicked()
{
    //clear table & set header lables
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "First Station" << "Second Station"<< "Third Station" << "Fourth Station" << "Third Station" << "Second Station" << "First Station");

    //Working part
    int current_TransportNum_index = ui->TransportNum->currentIndex();  //get index of Transport name
    int current_comboBox_index = ui->Transport->currentIndex();         //get index of Transport type

    //Fill table
    int s = 0;
    double time = 0;
    switch (current_comboBox_index) {
    case 0:
        for(int i = 0; i<ui->tableWidget_2->rowCount();i++){
            for(int j = 0; j<ui->tableWidget_2->columnCount();j++){
                QTableWidgetItem *tab = new QTableWidgetItem ("Error");
                ui->tableWidget_2->setItem(i, j, tab);
            }
        }
        break;
    case Bus:
        for(int i = 0, count = 0; i<ui->tableWidget_2->rowCount();i++){
            for(int j = 0; j<ui->tableWidget_2->columnCount();j++){
                time = bus.bus.decTOsix(this->bus.bus.getHr(current_TransportNum_index), this->bus.bus.getMin(current_TransportNum_index) + (this->bus.bus.getPeriod(current_TransportNum_index)* s));
                if(time >= 24 && count == 0){
                    i++;
                    count++;
                    time -=24;
                    QTableWidgetItem *tabNewDay = new QTableWidgetItem ("New day --->");
                    ui->tableWidget_2->setItem(i, j - 1, tabNewDay);
                }else if(time >= 24 && count != 0){
                    time -=24;
                }
                QTableWidgetItem *tab = new QTableWidgetItem (QString::number(time));
                ui->tableWidget_2->setItem(i, j, tab);
                s++;
            }
        }
        break;
    case Ship:
        for(int i = 0, count = 0; i<ui->tableWidget_2->rowCount();i++){
            for(int j = 0; j<ui->tableWidget_2->columnCount();j++){
                time = ship.ship.decTOsix(this->train.train.getHr(current_TransportNum_index), this->ship.ship.getMin(current_TransportNum_index) + (this->ship.ship.getPeriod(current_TransportNum_index) * s));
                if(time >= 24 && count == 0){
                    i++;
                    count++;
                    time -=24;
                    QTableWidgetItem *tabNewDay = new QTableWidgetItem ("New day --->");
                    ui->tableWidget_2->setItem(i, j - 1, tabNewDay);
                }else if(time >= 24 && count != 0){
                    time -=24;
                }
                QTableWidgetItem *tab = new QTableWidgetItem (QString::number(time));
                ui->tableWidget_2->setItem(i, j, tab);
                s++;
            }
        }
        break;
    case Plane:
        for(int i = 0, count = 0; i<ui->tableWidget_2->rowCount();i++){
            for(int j = 0; j<ui->tableWidget_2->columnCount();j++){
                time = plane.plane.decTOsix(this->plane.plane.getHr(current_TransportNum_index), this->plane.plane.getMin(current_TransportNum_index) + (this->plane.plane.getPeriod(current_TransportNum_index) * s));
                if(time >= 24 && count == 0){
                    i++;
                    count++;
                    time -=24;
                    QTableWidgetItem *tabNewDay = new QTableWidgetItem ("New day --->");
                    ui->tableWidget_2->setItem(i, j - 1, tabNewDay);
                }else if(time >= 24 && count != 0){
                    time -=24;
                }
                QTableWidgetItem *tab = new QTableWidgetItem (QString::number(time));
                ui->tableWidget_2->setItem(i, j, tab);
                s++;
            }
        }
        break;
    case Train:
        for(int i = 0, count = 0; i<ui->tableWidget_2->rowCount();i++){
            for(int j = 0; j<ui->tableWidget_2->columnCount();j++){
                time = train.train.decTOsix(this->train.train.getHr(current_TransportNum_index), this->train.train.getMin(current_TransportNum_index) + (this->train.train.getPeriod(current_TransportNum_index) * s));
                if(time >= 24 && count == 0){
                    i++;
                    count++;
                    time -=24;
                    QTableWidgetItem *tabNewDay = new QTableWidgetItem ("New day --->");
                    ui->tableWidget_2->setItem(i, j - 1, tabNewDay);
                }else if(time >= 24 && count != 0){
                    time -=24;
                }
                QTableWidgetItem *tab = new QTableWidgetItem (QString::number(time));
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
    std::string variable = "0";

    //set image
    QPixmap myBus(":/img/bus.png");
    QPixmap myPlane(":/img/plane.png");
    QPixmap myShip(":/img/ship.png");
    QPixmap myTrain(":/img/train.png");
    int width = ui->labet_image->width();
    int hight = ui->labet_image->height();

    //choose transport type
    if (index != 0){
        ui->TransportNum->setEnabled(true);
        switch (index) {
        case Bus:
            ui->labet_image->setPixmap(myBus.scaled(width, hight, Qt::KeepAspectRatio));
                ui->TransportNum->clear();
            for (int i = 0; i<this->bus.bus.getTransportIndex() ; i++){
                call = QString::fromStdString(this->bus.bus.getName(i));
                ui->TransportNum->addItem(call);
            }
            break;
        case Ship:
            ui->labet_image->setPixmap(myShip.scaled(width, hight, Qt::KeepAspectRatio));
            ui->TransportNum->clear();
            for (int i = 0; i<this->ship.ship.getTransportIndex() ; i++){
                call = QString::fromStdString(this->ship.ship.getName(i));
                ui->TransportNum->addItem(call);
            }
            break;
        case Plane:
            ui->labet_image->setPixmap(myPlane.scaled(width, hight, Qt::KeepAspectRatio));
            ui->TransportNum->clear();
            for (int i = 0; i<this->plane.plane.getTransportIndex() ; i++){
                call = QString::fromStdString(this->plane.plane.getName(i));
                ui->TransportNum->addItem(call);
            }
            break;
        case Train:
            ui->labet_image->setPixmap(myTrain.scaled(width, hight, Qt::KeepAspectRatio));
            ui->TransportNum->clear();
            for (int i = 0; i < this->train.train.getTransportIndex() ; i++){
                call = QString::fromStdString(this->train.train.getName(i));
                ui->TransportNum->addItem(call);
            }
        default:
            break;
        }

    }else{
        ui->TransportNum->setEnabled(false);
        ui->Add->setEnabled(false);
        ui->labet_image->setText("◉_◉");
        ui->TransportNum->clear();
    }
}

void MainWindow::on_Add_clicked()
{
    int current_Transport_index = ui->TypeOfTransport->currentIndex();
    std::string value = "0";
    switch (current_Transport_index){
    case Bus:
        value = ui ->TransportNameEdit->text().toStdString();
        this->bus.bus.tempName[0] = value;
        this->bus.bus.setName(this->bus.bus.getTransportIndex(), this->bus.bus.tempName);
        this->bus.bus.setHr(this->bus.bus.getTransportIndex(),ui->HrEdit->text().toInt());
        this->bus.bus.setMin(this->bus.bus.getTransportIndex(),ui->MinEdit->text().toInt());
        this->bus.bus.setPeriod(this->bus.bus.getTransportIndex(),ui->PeriodEdit->text().toInt());
        this->bus.bus.setTransportIndexIncr();

        ui->Progress->setText("Added successfully");
        ui->TransportNameEdit->clear();
        ui->HrEdit->clear();
        ui->MinEdit->clear();
        ui->PeriodEdit->clear();
        ui->TypeOfTransport->setCurrentIndex(0);
        ui->Add->setEnabled(false);

        break;
    case Ship:
        value = ui ->TransportNameEdit->text().toStdString();
        this->ship.ship.tempName[0] = value;
        this->ship.ship.setName(this->ship.ship.getTransportIndex(), this->ship.ship.tempName);
        this->ship.ship.setHr(this->ship.ship.getTransportIndex(),ui->HrEdit->text().toInt());
        this->ship.ship.setMin(this->ship.ship.getTransportIndex(),ui->MinEdit->text().toInt());
        this->ship.ship.setPeriod(this->ship.ship.getTransportIndex(),ui->PeriodEdit->text().toInt());
        this->ship.ship.setTransportIndexIncr();

        ui->Progress->setText("Added successfully");
        ui->TransportNameEdit->clear();
        ui->HrEdit->clear();
        ui->MinEdit->clear();
        ui->PeriodEdit->clear();
        ui->TypeOfTransport->setCurrentIndex(0);
        ui->Add->setEnabled(false);

        break;
    case Plane:
        value = ui ->TransportNameEdit->text().toStdString();
        this->plane.plane.tempName[0] = value;
        this->plane.plane.setName(this->plane.plane.getTransportIndex(), this->plane.plane.tempName);
        this->plane.plane.setHr(this->plane.plane.getTransportIndex(),ui->HrEdit->text().toInt());
        this->plane.plane.setMin(this->plane.plane.getTransportIndex(),ui->MinEdit->text().toInt());
        this->plane.plane.setPeriod(this->plane.plane.getTransportIndex(),ui->PeriodEdit->text().toInt());
        this->plane.plane.setTransportIndexIncr();

        ui->Progress->setText("Added successfully");
        ui->TransportNameEdit->clear();
        ui->HrEdit->clear();
        ui->MinEdit->clear();
        ui->PeriodEdit->clear();
        ui->TypeOfTransport->setCurrentIndex(0);
        ui->Add->setEnabled(false);

        break;
    case Train:
        value = ui ->TransportNameEdit->text().toStdString();
        this->train.train.tempName[0] = value;
        this->train.train.setName(this->train.train.getTransportIndex(), this->train.train.tempName);
        this->train.train.setHr(this->train.train.getTransportIndex(),ui->HrEdit->text().toInt());
        this->train.train.setMin(this->train.train.getTransportIndex(),ui->MinEdit->text().toInt());
        this->train.train.setPeriod(this->train.train.getTransportIndex(),ui->PeriodEdit->text().toInt());
        this->train.train.setTransportIndexIncr();

        ui->Progress->setText("Added successfully");
        ui->TransportNameEdit->clear();
        ui->HrEdit->clear();
        ui->MinEdit->clear();
        ui->PeriodEdit->clear();
        ui->TypeOfTransport->setCurrentIndex(0);
        ui->Add->setEnabled(false);

        break;
    }

}


void MainWindow::on_Edit_clicked()
{
    int current_Transport_index = ui->TypeOfTransport_2->currentIndex();
    int current_TransportName_index = ui->TransportNameIndex->currentIndex();

    switch (current_Transport_index){
    case Bus:
        if(ui->HrEdit_2->text().toInt() != 0) this->bus.bus.setHr(current_TransportName_index,ui->HrEdit_2->text().toInt());
        if(ui->MinEdit_2->text().toInt() != 0)this->bus.bus.setMin(current_TransportName_index,ui->MinEdit_2->text().toInt());
        if(ui->PeriodEdit_2->text().toInt() != 0)this->bus.bus.setPeriod(current_TransportName_index,ui->PeriodEdit_2->text().toInt());

        ui->Progress_2->setText("Edited successfully");
        ui->HrEdit_2->clear();
        ui->MinEdit_2->clear();
        ui->PeriodEdit_2->clear();
        ui->TransportNameIndex->clear();
        ui->TransportNameIndex->setEnabled(false);
        ui->TypeOfTransport_2->setCurrentIndex(0);
        ui->Edit->setEnabled(false);

        break;
    case Ship:
        if(ui->HrEdit_2->text().toInt() != 0)this->ship.ship.setHr(current_TransportName_index,ui->HrEdit_2->text().toInt());
        if(ui->HrEdit_2->text().toInt() != 0)this->ship.ship.setMin(current_TransportName_index,ui->MinEdit_2->text().toInt());
        if(ui->HrEdit_2->text().toInt() != 0)this->ship.ship.setPeriod(current_TransportName_index,ui->PeriodEdit_2->text().toInt());

        ui->Progress_2->setText("Edited successfully");
        ui->HrEdit_2->clear();
        ui->MinEdit_2->clear();
        ui->PeriodEdit_2->clear();
        ui->TransportNameIndex->clear();
        ui->TransportNameIndex->setEnabled(false);
        ui->TypeOfTransport_2->setCurrentIndex(0);
        ui->Edit->setEnabled(false);

        break;
    case Plane:
        if(ui->HrEdit_2->text().toInt() != 0)this->plane.plane.setHr(current_TransportName_index,ui->HrEdit_2->text().toInt());
        if(ui->HrEdit_2->text().toInt() != 0)this->plane.plane.setMin(current_TransportName_index,ui->MinEdit_2->text().toInt());
        if(ui->HrEdit_2->text().toInt() != 0)this->plane.plane.setPeriod(current_TransportName_index,ui->PeriodEdit_2->text().toInt());

        ui->Progress_2->setText("Edited successfully");
        ui->HrEdit_2->clear();
        ui->MinEdit_2->clear();
        ui->PeriodEdit_2->clear();
        ui->TransportNameIndex->clear();
        ui->TransportNameIndex->setEnabled(false);
        ui->TypeOfTransport_2->setCurrentIndex(0);
        ui->Edit->setEnabled(false);

        break;
    case Train:
        if(ui->HrEdit_2->text().toInt() != 0)this->train.train.setHr(current_TransportName_index,ui->HrEdit_2->text().toInt());
        if(ui->HrEdit_2->text().toInt() != 0)this->train.train.setMin(current_TransportName_index,ui->MinEdit_2->text().toInt());
        if(ui->HrEdit_2->text().toInt() != 0)this->train.train.setPeriod(current_TransportName_index,ui->PeriodEdit_2->text().toInt());

        ui->Progress_2->setText("Edited successfully");
        ui->HrEdit_2->clear();
        ui->MinEdit_2->clear();
        ui->PeriodEdit_2->clear();
        ui->TransportNameIndex->clear();
        ui->TransportNameIndex->setEnabled(false);
        ui->TypeOfTransport_2->setCurrentIndex(0);

        ui->Edit->setEnabled(false);
        break;
    }
}


void MainWindow::on_TypeOfTransport_2_activated(int index)
{
    QString call = "0";
    ui->Edit->setEnabled(true);
    //choose transport type to edit
    if (index != 0){
        ui->TransportNameIndex->setEnabled(true);
        switch (index) {
        case Bus:
            ui->TransportNameIndex->clear();
            for (int i = 0; i<this->bus.bus.getTransportIndex() ; i++){
                call = QString::fromStdString(this->bus.bus.getName(i));
                ui->TransportNameIndex->addItem(call);
            }
            break;
        case Ship:
            ui->TransportNameIndex->clear();
            for (int i = 0; i<this->ship.ship.getTransportIndex() ; i++){
                call = QString::fromStdString(this->ship.ship.getName(i));
                ui->TransportNameIndex->addItem(call);
            }
            break;
        case Plane:
            ui->TransportNameIndex->clear();
            for (int i = 0; i<this->plane.plane.getTransportIndex() ; i++){
                call = QString::fromStdString(this->plane.plane.getName(i));
                ui->TransportNameIndex->addItem(call);
            }
            break;
        case Train:
            ui->TransportNameIndex->clear();
            for (int i = 0; i < this->train.train.getTransportIndex() ; i++){
                call = QString::fromStdString(this->train.train.getName(i));
                ui->TransportNameIndex->addItem(call);
            }
        default:
            break;
        }

    }else{
        ui->TransportNameIndex->setEnabled(false);
        ui->Edit->setEnabled(false);
    }
}


void MainWindow::on_TypeOfTransport_activated(int index)
{
    ui->Add->setEnabled(true);
}


void MainWindow::on_Delete_clicked()
{
    int current_Transport_index = ui->TypeOfTransport_3->currentIndex();
    int current_TransportName_index = ui->TransportNameIndex_3->currentIndex();

    switch (current_Transport_index){
    case Bus:
        this->bus.bus.delHr(current_TransportName_index);
        this->bus.bus.delMin(current_TransportName_index);
        this->bus.bus.delPeriod(current_TransportName_index);
        this->bus.bus.delName(current_TransportName_index);

        ui->Progress_3->setText("Deleted successfully");
        this->bus.bus.setTransportIndexDecr();

        ui->TypeOfTransport_3->setCurrentIndex(0);
        ui->TransportNameIndex_3->clear();
        ui->TransportNameIndex_3->setEditable(false);
        ui->Delete->setEnabled(false);

        break;
    case Ship:
        this->ship.ship.delHr(current_TransportName_index);
        this->ship.ship.delMin(current_TransportName_index);
        this->ship.ship.delPeriod(current_TransportName_index);
        this->ship.ship.delName(current_TransportName_index);

        ui->Progress_3->setText("Deleted successfully");
        this->ship.ship.setTransportIndexDecr();

        ui->TypeOfTransport_3->setCurrentIndex(0);
        ui->TransportNameIndex_3->clear();
        ui->TransportNameIndex_3->setEditable(false);
        ui->Delete->setEnabled(false);

        break;
    case Plane:
        this->plane.plane.delHr(current_TransportName_index);
        this->plane.plane.delMin(current_TransportName_index);
        this->plane.plane.delPeriod(current_TransportName_index);
        this->plane.plane.delName(current_TransportName_index);

        ui->Progress_3->setText("Deleted successfully");
        this->plane.plane.setTransportIndexDecr();

        ui->TypeOfTransport_3->setCurrentIndex(0);
        ui->TransportNameIndex_3->clear();
        ui->TransportNameIndex_3->setEditable(false);
        ui->Delete->setEnabled(false);

        break;
    case Train:
        this->train.train.delHr(current_TransportName_index);
        this->train.train.delMin(current_TransportName_index);
        this->train.train.delPeriod(current_TransportName_index);
        this->train.train.delName(current_TransportName_index);

        ui->Progress_3->setText("Deleted successfully");
        this->train.train.setTransportIndexDecr();

        ui->TypeOfTransport_3->setCurrentIndex(0);
        ui->TransportNameIndex_3->clear();
        ui->TransportNameIndex_3->setEditable(false);
        ui->Delete->setEnabled(false);

        break;
    }
}


void MainWindow::on_TypeOfTransport_3_activated(int index)
{
    QString call = "0";
    ui->Delete->setEnabled(true);
    //choose transport type to delete
    if (index != 0){
        ui->TransportNameIndex_3->setEnabled(true);
        switch (index) {
        case Bus:
            ui->TransportNameIndex_3->clear();
            for (int i = 0; i<this->bus.bus.getTransportIndex() ; i++){
                call = QString::fromStdString(this->bus.bus.getName(i));
                ui->TransportNameIndex_3->addItem(call);
            }
            break;
        case Ship:
            ui->TransportNameIndex_3->clear();
            for (int i = 0; i<this->ship.ship.getTransportIndex() ; i++){
                call = QString::fromStdString(this->ship.ship.getName(i));
                ui->TransportNameIndex_3->addItem(call);
            }
            break;
        case Plane:
            ui->TransportNameIndex_3->clear();
            for (int i = 0; i<this->plane.plane.getTransportIndex() ; i++){
                call = QString::fromStdString(this->plane.plane.getName(i));
                ui->TransportNameIndex_3->addItem(call);
            }
            break;
        case Train:
                ui->TransportNameIndex_3->clear();
            for (int i = 0; i < this->train.train.getTransportIndex() ; i++){
                call = QString::fromStdString(this->train.train.getName(i));
                ui->TransportNameIndex_3->addItem(call);
            }
        default:
            break;
        }

    }else{
        ui->TransportNameIndex_3->setEnabled(false);
        ui->Delete->setEnabled(false);
    }
}





void MainWindow::on_Exit_clicked()
{
    QMessageBox::StandardButton answer = QMessageBox::question(this, "Exit", "Are you sure you want to exit?", QMessageBox::Yes | QMessageBox::No);

    if(answer == QMessageBox::Yes){
        QApplication::exit();
    }
}


void MainWindow::on_Register_clicked()
{
    registration->show();

}

void MainWindow::slot(QString a)
{
    ui->label_2->setText("Login: ");
    ui->label->setText(a);
    //verification
    if(a == "BARUX"){
        ui->Search->setEnabled(true);
    }
}

