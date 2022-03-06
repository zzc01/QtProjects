#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{

}

void MyServer::StartServer()
{
    if(!this->listen(QHostAddress::Any, 1234))
    {
        qInfo() << "Could not start server";
    }
    else
    {
        qInfo() << "Listening ... ";
    }
}

//void MyServer::incomingConnection(int socketDescriptor)
// this is function has in QTcpServer already, but he is "rewrite" it.
// This function is calling "automatically" when connection is set.

// This virtual function is called by QTcpServer when a new connection is available.
// The socketDescriptor argument is the native socket descriptor for the accepted connection.
// The base implementation creates a QTcpSocket, sets the socket descriptor and then stores
// the QTcpSocket in an internal list of pending connections. Finally newConnection() is emitted.
// Reimplement this function to alter the server's behavior when a connection is available.
void MyServer::incomingConnection(qintptr socketDescriptor)
{
    qInfo() << socketDescriptor << " Connecting ... ";
    MyThread *thread = new MyThread(socketDescriptor, this);
    connect(thread, &MyThread::finished, thread, &MyThread::deleteLater);
    thread->start();
}

