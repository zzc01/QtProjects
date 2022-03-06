#include "myserver.h"

MyServer::MyServer(QObject *parent) : QTcpServer(parent)
{

}

void MyServer::StartServer()
{
    if(listen(QHostAddress::Any, 1234))
    {
        qInfo() << "Server Started! Listening ... ";
    }
    else
    {
        qInfo() << "Server Start Failed!";
    }
}

void MyServer::incomingConnection(qintptr handle)
{
    MyClient *client = new MyClient(this);
    client->SetSocket(handle);
}
