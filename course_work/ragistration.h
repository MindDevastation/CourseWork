#ifndef RAGISTRATION_H
#define RAGISTRATION_H

#include <QDialog>

namespace Ui {
class ragistration;
}

class ragistration : public QDialog
{
    Q_OBJECT

public:
    explicit ragistration(QWidget *parent = nullptr);
    ~ragistration();

private:
    Ui::ragistration *ui;

signals:
    void signal(QString);


private slots:
    void on_pushButton_clicked();
};

#endif // RAGISTRATION_H
