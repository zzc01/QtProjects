#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QObject>
#include <QDebug>
#include <QTcpSocket>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int ID, QObject *parent = 0);
    void run();
    QTcpSocket *socket;
    int socketDescriptor;


signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState socketState);

};

#endif // MYTHREAD_H
