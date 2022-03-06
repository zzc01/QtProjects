#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QRunnable>
#include <QTcpSocket>
#include <QDebug>
#include <QThread>

class Mysocket : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Mysocket(QObject *parent);
    ~Mysocket();
    int SocketDescriptor;

protected:
    void run();

private:
    void stateChanged(QAbstractSocket::SocketState socketState);
};

#endif // MYSOCKET_H
