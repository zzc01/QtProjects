#include <QCoreApplication>
#include "myudp.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyUDP client;
    MyUDP Server;

    qInfo() << Q_FUNC_INFO << QThread::currentThread();
    client.SayHello();

    return a.exec();
}
