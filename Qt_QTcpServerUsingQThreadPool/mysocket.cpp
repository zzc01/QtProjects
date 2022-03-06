#include "mysocket.h"


Mysocket::Mysocket(QObject *parent) : QObject(parent)
{
    qInfo() << "Mysocket Constructed! " << this << Q_FUNC_INFO << QThread::currentThread();
}

Mysocket::~Mysocket()
{
    qInfo() << "Mysocket Deconstructed! " << this << Q_FUNC_INFO << QThread::currentThread();
}

void Mysocket::run()
{
    if(!SocketDescriptor) return;

    QTcpSocket socket;

    socket.setSocketDescriptor(SocketDescriptor);

    connect(&socket, &QTcpSocket::stateChanged, this, &Mysocket::stateChanged, Qt::DirectConnection);

    qInfo() << "Write Hello! " << this << Q_FUNC_INFO << QThread::currentThread();

    socket.write("hello world");
    socket.flush();
    socket.waitForBytesWritten();
    socket.close();
}


void Mysocket::stateChanged(QAbstractSocket::SocketState socketState)
{
    //qInfo() << this << Q_FUNC_INFO << QThread::currentThread();
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
