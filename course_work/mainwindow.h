#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data.h"
#include"bus.h"
#include "train.h"
#include "ship.h"
#include "plane.h"
#include "add_info.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    class data MyData;
    class Bus bus;
    Train train;
    Ship ship;
    Plane plane;
   Add_info info;

private slots:
    void on_pushButton_clicked();

    void on_Transport_activated(int index);

    void on_Add_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
