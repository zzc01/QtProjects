#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "myudp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_SetAddressButton_clicked();
    void on_SendMessageButton_clicked();
    void displaySlot(QString data);

private:
    Ui::MainWindow *ui;
    MyUDP* worker;

};
#endif // MAINWINDOW_H
