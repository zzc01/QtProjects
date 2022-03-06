#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>


class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr);


public slots:
    void newConnection();

signals:

private:
    QTcpServer *server;


};

#endif // MYSERVER_H
