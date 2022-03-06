#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QThread>


class MyUDP : public QObject
{
    Q_OBJECT
public:
    explicit MyUDP(QObject *parent = nullptr);
    void bind(void);
    void send(QString data);

    void setTargetIP(const QString &newTargetIP);
    void setTargetPort(int newTargetPort);
    void setLocalIP(const QString &newLocalIP);
    void setLocalPort(int newLocalPort);

signals:
    void displaySignal(QString data);

public slots:
    void readyRead();

private:
    QUdpSocket *socket;
    QString _targetIP;
    int _targetPort;
    QString _localIP;
    int _localPort;
};

#endif // MYUDP_H
