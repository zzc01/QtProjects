#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QObject>
#include <QThreadPool>
#include <QDebug>
#include "mysocket.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    void StartServer();

protected:
    void incomingConnection(qintptr handle);

signals:

public slots:

private:
    QThreadPool *pool;
};

#endif // MYSERVER_H
