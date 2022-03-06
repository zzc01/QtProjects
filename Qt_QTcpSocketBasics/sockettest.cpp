#include "sockettest.h"
#include <QThread>

SocketTest::SocketTest(QObject *parent)
    : QObject{parent}
{

}

void SocketTest::Connect()
{
    // connect
    socket = new QTcpSocket(this);

    // what to be able to read the states change
    // connect socket's statechange to this's statechange with parameter statechange
    connect(socket, &QAbstractSocket::stateChanged, this, &SocketTest::stateChanged);

    socket->connectToHost("google.com", 80);
    if(socket->waitForConnected(3000))
    {
        // what does socket level connected mean?
        qInfo() << "Connected!" << Q_FUNC_INFO << ", " << QThread::currentThread();
        // send
        socket->write("Hello Server\r\n\r\n\r\n\r\n");

        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qInfo() << "Reading: " << socket->bytesAvailable();
        qInfo() << socket->readAll();

        // close
        socket->close();
    }else
    {
        qInfo()<< "Not Connected!" << Q_FUNC_INFO << ", " << QThread::currentThread();
    }


    // get

}

void SocketTest::stateChanged(int state)
{
    switch(state)
    {
    case 0:
        qInfo() << "UnconnectedState";
        break;
    case 1:
        qInfo() << "HostLookupState";
        break;
    case 2:
        qInfo() << "ConnectingState";
        break;
    case 3:
        qInfo() << "ConnectedState";
        break;
    case 4:
        qInfo() << "BoundedState";
        break;
    case 5:
        qInfo() << "ListeningState";
        break;
    case 6:
        qInfo() << "ClosingState";
        break;
    }
}
