#include "myudp.h"

MyUDP::MyUDP(QObject *parent)
    : QObject{parent}
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 1234);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void MyUDP::SayHello()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    QByteArray Data;
    Data.append("Hello from UDP Land");
    socket->writeDatagram(Data, Data.size(), QHostAddress::LocalHost, 1234);
    //192.168.1.10
    //192.168.1.255
}

void MyUDP::readyRead()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(), Buffer.size(),
                         &sender, &senderPort);
    qInfo() << "Message from address: " << sender.toString();
    qInfo() << "Message from prot: " << senderPort;
    qInfo() << "Message: " << Buffer;

}
