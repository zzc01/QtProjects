#include "myserver.h"

MyServer::MyServer(QObject *parent)
    : QObject{parent}
{
    server = new QTcpServer(this);

    connect(server, &QTcpServer::newConnection, this, &MyServer::newConnection);

    if(!server->listen(QHostAddress::Any, 1234))
    {
        qInfo() << "Server could not start!";
    }
    else
    {
        qInfo() << "Server started";
    }

}

void MyServer::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    // want to look at this socket's stateChanged
    socket->write("Hello Client\r\n");
    socket->flush();

    socket->waitForBytesWritten(3000);

    // why close this socket?
    socket->close();
}
