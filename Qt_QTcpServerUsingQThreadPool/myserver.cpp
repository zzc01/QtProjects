#include "myserver.h"

MyServer::MyServer(QObject *parent) : QTcpServer(parent)
{
    pool = new QThreadPool(this);
    pool->setMaxThreadCount(5);
}

void MyServer::StartServer()
{
    if(this->listen(QHostAddress::Any, 1234))
    {
        qInfo() << "Server Started";
    }
    else
    {
        qDebug() << "Server did not start!";
    }

}

void MyServer::incomingConnection(qintptr handle)
{
    Mysocket *task = new Mysocket(nullptr);
    task->setAutoDelete(true);
    task->SocketDescriptor = handle;
    pool->start(task);
}
