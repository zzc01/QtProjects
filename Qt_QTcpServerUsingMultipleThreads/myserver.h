#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QObject>
#include "mythread.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent=0);
    void StartServer();

protected:
    //void incomingConnection(int socketDescriptor);
    // appear that something will trigger this slot
    void incomingConnection(qintptr socketDescriptor);



};

#endif // MYSERVER_H
