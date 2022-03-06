# Qt Practice Prorjects

* Qt practice projects about QThread, QThreadPool, Qt Network, QTcpSocket, QUdpSocket usage. 
* These are mainly based on tutorials from VoidRealms[1] youtube channel. 
* Built a simple windows app that sends message between two users using UDP packages. 
* These practice projects are created by QtCreator 6.0.2. 


<br/>

## Install Qt 
* Followed intructions from VoidRealms[1]. 
* Need registration to download Qt from [Qt website](https://www.qt.io/). 
* Chose Qt for Open Source Development. [Open Source Usage Obligations](https://www.qt.io/download-open-source?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5).
* In the future if want to add packages can use Qt MaintenanceTool to add them. 
* There are some other resources that demonstrate how to install and use openCV with QT. <br/><br/>


## Notes
#### [Qt Download File From Web](/Qt_QhttpDownloadFilesFromWeb)
* Use QNetworkAccessManager, QNetworkRequest, QNetworkReply, QUrl to send a simple get command to a http host. 
* Use QEventLoop to wait for finished signal to be emitted. 
* Use readAll and QFile to retrieve the data and save to text.txt file. 
#### [Qt Tcp Socket Basics](/Qt_QTcpSocketBasics)
* Use QTcpSocket to simply send message to host and receive return message from host. 
* Use SocketTest::stateChanged to observe the different states during connecting and disconnecting to host. 
* Use waitForConnected, waitForBytesWritten, and waitForReadyRead to make sure actions are done. 
<br/>


# References 
[1] VoidRealms, https://www.youtube.com/channel/UCYP0nk48grsMwO3iL8YaAKA/. <br/>
