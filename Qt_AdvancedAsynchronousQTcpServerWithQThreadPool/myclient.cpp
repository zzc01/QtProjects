#include "myclient.h"

MyClient::MyClient(QObject *parent)
    : QObject{parent}
{
    QThreadPool::globalInstance()->setMaxThreadCount(2);
}

void MyClient::SetSocket(int SocketDescriptor)
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(stateChanged(QAbstractSocket::SocketState)),
            Qt::DirectConnection);
    //connect(socket, &QTcpSocket::stateChanged, this, &MyClient::stateChanged, Qt::DirectConnection);

    socket->setSocketDescriptor(SocketDescriptor);

    qInfo() << "Client Connected!";
}

void MyClient::connected()
{
    qInfo() << "Client Connected Event!";
}

void MyClient::disconnected()
{
    qInfo() << "Client Disconnected!";
}

void MyClient::readyRead()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    qInfo() << socket->readAll();

    //Time Consumer
    MyTask *mytask = new MyTask();
    mytask->setAutoDelete(true);
    connect(mytask, SIGNAL(Result(int)), this, SLOT(TaskResult(int)), Qt::QueuedConnection);
    QThreadPool::globalInstance()->start(mytask);
}

void MyClient::TaskResult(int Number)
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    QByteArray Buffer;
    Buffer.append("\r\nTask Result = ");
    //QString str;
    //str.setNum(Number);
    QByteArray qb;
    qb.setNum(Number);
    Buffer.append(qb);
    socket->write(Buffer);
}

void MyClient::stateChanged(QAbstractSocket::SocketState socketState)
{
    switch(socketState)
    {
    case 0:
        qInfo() << "Unconnected State" << this << Q_FUNC_INFO << QThread::currentThread();
        break;
    case 1:
        qInfo() << "HostLookup State" << this << Q_FUNC_INFO << QThread::currentThread();
        break;
    case 2:
        qInfo() << "Connecting State" << this << Q_FUNC_INFO << QThread::currentThread();
        break;
    case 3:
        qInfo() << "Connected State" << this << Q_FUNC_INFO << QThread::currentThread();
        break;
    case 4:
        qInfo() << "Bounded State" << this << Q_FUNC_INFO << QThread::currentThread();
        break;
    case 5:
        qInfo() << "Listening State" << this << Q_FUNC_INFO << QThread::currentThread();
        break;
    case 6:
        qInfo() << "Closing State" << this << Q_FUNC_INFO << QThread::currentThread();
        break;
    }
}

