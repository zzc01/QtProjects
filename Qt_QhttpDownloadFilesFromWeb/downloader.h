#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QDebug>
#include <QEventLoop>
#include <QThread>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = nullptr);
    void Do_Download();

signals:

private:
    QNetworkAccessManager *manager;

};

#endif // DOWNLOADER_H
