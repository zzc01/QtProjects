#include <QCoreApplication>
#include "myserver.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QThread::currentThread()->setObjectName("Main Thread");
    QCoreApplication a(argc, argv);

    MyServer Server;
    Server.StartServer();

    return a.exec();
}
