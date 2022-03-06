#ifndef MYTASK_H
#define MYTASK_H

#include <QRunnable>
#include <QObject>
#include <QThread>
#include <QDebug>
#include <QRandomGenerator>

class MyTask : public QObject, public QRunnable
{
    Q_OBJECT;
public:
    MyTask();

signals:
    void Result(int Number);

protected:
    void run();

};

#endif // MYTASK_H
