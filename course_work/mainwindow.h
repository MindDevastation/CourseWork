#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data.h"
#include"bus.h"
#include "ragistration.h"
#include "train.h"
#include "ship.h"
#include "plane.h"
#include "ui_mainwindow.h"
#include<QPixmap>


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
    int indexx = 3;
    int count = 0;



    enum transport{
       Bus = 1,
       Ship,
       Plane,
       Train
   };

private slots:
    void on_Search_clicked();

    void on_Transport_activated(int index);

    void on_Add_clicked();

    void on_Edit_clicked();

    void on_TypeOfTransport_2_activated(int index);

    void on_TypeOfTransport_activated(int index);

    void on_Delete_clicked();

    void on_TypeOfTransport_3_activated(int index);

    void on_Exit_clicked();

    void on_Register_clicked();

private:
    Ui::MainWindow *ui;
    ragistration *registration;

public slots:
    void slot(QString a);
};
#endif // MAINWINDOW_H
