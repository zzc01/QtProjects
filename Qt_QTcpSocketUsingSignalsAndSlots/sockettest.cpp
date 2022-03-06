#include "sockettest.h"

SocketTest::SocketTest(QObject *parent)
    : QObject{parent}
{

}

void SocketTest::test()
{
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &SocketTest::connected);
    connect(socket, &QTcpSocket::disconnected, this, &SocketTest::disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &SocketTest::readyRead);
    connect(socket, &QTcpSocket::bytesWritten, this, &SocketTest::bytesWritten);
    connect(socket, &QTcpSocket::stateChanged, this, &SocketTest::stateChanged);

    qInfo() << "Connecting ... ";

    socket->connectToHost("voidrealms.com", 80);

    if(!socket->waitForConnected(500))
    {
        qInfo() << "Error: " << socket->errorString();
    }
}

void SocketTest::connected()
{
    qInfo() << "Connected!";
    //socket->disconnectFromHost();
    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n");
}

void SocketTest::disconnected()
{
    qInfo() << "Disconnected!";
}

void SocketTest::bytesWritten(qint64 bytes)
{
    qInfo() << "We Wrote: " << bytes;
}

void SocketTest::readyRead()
{
    qInfo() << "Reading...";
    qInfo() << socket->readAll();

}

void SocketTest::stateChanged(QAbstractSocket::SocketState socketState)
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
