#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
//#include "mainwindow.h"
#include "data.h"
#include"bus.h"
#include "train.h"
#include "ship.h"
#include "plane.h"

namespace Ui {
class Add_info;
}

class Add_info : public QDialog
{
    Q_OBJECT

public:
    explicit Add_info(QWidget *parent = nullptr);
    ~Add_info();
    int test;
    class data MyData;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Add_info *ui;

    class Bus bus;
    Train train;
    Ship ship;
    Plane plane;

};

#endif // REGISTRATION_H
