#include "myudp.h"

MyUDP::MyUDP(QObject *parent)
    : QObject{parent}
{
    socket = new QUdpSocket();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void MyUDP::bind()
{
    qInfo() << (QHostAddress)_localIP;
    qInfo() << _localPort;
    socket->bind((QHostAddress)_localIP, _localPort);
}

void MyUDP::send(QString data)
{
    QByteArray Buffer;
    Buffer.append(data.toUtf8());
    socket->writeDatagram(Buffer, Buffer.size(),
                          (QHostAddress)_targetIP, _targetPort);
}

void MyUDP::readyRead()
{
    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());

    if(Buffer.size()==0) return;

    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(), Buffer.size(),
                         &sender, &senderPort);
    QString str = "Received from " + sender.toString() + ":" + QString::number(senderPort) +
            " : " + Buffer;

    emit displaySignal(str);
}

void MyUDP::setLocalPort(int newLocalPort)
{
    _localPort = newLocalPort;
}

void MyUDP::setLocalIP(const QString &newLocalIP)
{
    _localIP = newLocalIP;
}

void MyUDP::setTargetPort(int newTargetPort)
{
    _targetPort = newTargetPort;
}

void MyUDP::setTargetIP(const QString &newTargetIP)
{
    _targetIP = newTargetIP;
}
