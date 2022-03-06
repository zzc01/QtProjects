#include "mythread.h"

// uses : QThread(parent)
// to initialize base class's member initialization list

MyThread::MyThread(int ID, QObject *parent) :
    QThread(parent)
{
    this ->socketDescriptor = ID;
}

void MyThread::run()
{
    //thread starts here
    qDebug() << "Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, &QTcpSocket::readyRead, this, &MyThread::readyRead, Qt::DirectConnection);
    connect(socket, &QTcpSocket::disconnected, this, &MyThread::disconnected, Qt::DirectConnection);
    connect(socket, &QTcpSocket::stateChanged, this, &MyThread::stateChanged, Qt::DirectConnection);

    qInfo() << socketDescriptor << "Client Connected.";

    exec();
}

void MyThread::readyRead()
{
    QByteArray Data = socket->readAll();
    qInfo() << socketDescriptor << ", Data in: " << Data;
    socket->write(Data);
}

void MyThread::disconnected()
{
    qInfo() << socketDescriptor << ", Disconnected!";
    socket->deleteLater();
    exit(0);
}

void MyThread::stateChanged(QAbstractSocket::SocketState socketState)
{
    switch(socketState)
    {
    case 0:
        qInfo() << "Unconnected State";
        break;
    case 1:
        qInfo() << "HostLookup State";
        break;
    case 2:
        qInfo() << "Connecting State";
        break;
    case 3:
        qInfo() << "Connected State";
        break;
    case 4:
        qInfo() << "Bounded State";
        break;
    case 5:
        qInfo() << "Listening State";
        break;
    case 6:
        qInfo() << "Closing State";
        break;
    }
}
