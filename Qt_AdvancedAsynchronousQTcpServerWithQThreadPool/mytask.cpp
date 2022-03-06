#include "mytask.h"

MyTask::MyTask()
{
}

void MyTask::run()
{
    qInfo() << "Task Start: " << Q_FUNC_INFO << QThread::currentThread();

    int iNumber = 0;
    //for(int i=0; i<10000; i++)
    //{
    //    iNumber += i;
    //}
    QThread::msleep(1000);

    iNumber = QRandomGenerator::global()->bounded(1000);

    qInfo() << "Task Done";

    emit Result(iNumber);
}
