#include "downloader.h"

Downloader::Downloader(QObject *parent)
    : QObject{parent}
{

}

void Downloader::Do_Download()
{
    QNetworkAccessManager qnam;
    QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> reply;

    //const QString urlSpec = "https://www.qt.io/";
    //const QString urlSpec = "www.qt.io";
    const QString urlSpec = "https://www.digikey.com/en/products/detail/kyocera-avx/CK05BX103K/3451931";
    const QUrl newUrl = QUrl::fromUserInput(urlSpec);
    qInfo() << "The URL is : " << newUrl;

    // First time see this. Using the smart pointer's member function using dot
    // and accessing reply member function using ->
    reply.reset(qnam.get(QNetworkRequest(newUrl)));

    QEventLoop loop;
    // connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(reply.get(), &QNetworkReply::finished, &loop, &QEventLoop::quit);
    // connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), &loop, SLOT(quit()));
    connect(reply.get(), &QNetworkReply::errorOccurred, &loop, &QEventLoop::quit);
    loop.exec();

    // only allows read once usage of readAll()
    QByteArray bts = reply->readAll();
    QString str(bts);

    QString fileName = "test.txt";
    std::unique_ptr<QFile> file = std::make_unique<QFile>(fileName);
    if(file->open(QIODevice::Append))
    {
        file->write(bts);
        file->flush();
        file->close();
    }
    //qInfo() << bts;
    qInfo() << Q_FUNC_INFO << QThread::currentThread();

}
