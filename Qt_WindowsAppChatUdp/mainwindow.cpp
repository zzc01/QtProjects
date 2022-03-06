#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SetAddressButton_clicked()
{
    QString local_address = ui->plainTextEditLocalIp->toPlainText();
    QString local_port = ui->plainTextEditLocalPort->toPlainText();
    QString target_address = ui->plainTextEditTargetIp->toPlainText();
    QString target_port = ui->plainTextEditTargetPort->toPlainText();

    displaySlot("Set local address to: " + local_address + ":" + local_port);
    displaySlot("Set target address to: " + target_address + ":" + target_port);

    //if(worker != nullptr)
    //    worker->~MyUDP();

    worker = new MyUDP();
    worker->setLocalIP(local_address);
    worker->setLocalPort(local_port.toInt());
    worker->setTargetIP(target_address);
    worker->setTargetPort(target_port.toInt());
    worker->bind();

    connect(worker, SIGNAL(displaySignal(QString)), this, SLOT(displaySlot(QString)));
    //connect(worker, &MyUDP::displaySignal, this, &MainWindow::displaySlot);
}


void MainWindow::on_SendMessageButton_clicked()
{
    QString message = ui->plainTextEditToSend->toPlainText();
    displaySlot("Sent message: " + message);
    ui->plainTextEditToSend->clear();
    worker->send(message);
}

void MainWindow::displaySlot(QString data)
{

    //auto textCursor = ui->textBrowser->textCursor();
    //textCursor.movePosition(QTextCursor::End);
    //ui->textBrowser->setTextCursor(textCursor);
    ui->textBrowser->append(data);
}

