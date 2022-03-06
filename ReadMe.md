# Qt Practice Prorjects

* These practice projects are created by QtCreator 6.0.2. 
* Practicing the usage of Qt Network, QTcpSocket, QTcpServer, QUdpSocket, QThread, and QThreadPool. 
* These are mainly based on tutorials from VoidRealms[1] youtube channel. 
* I also built a simple windows app that sends message between two users using UDP packages. 


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

#### [Qt QTcpSocket Basics](/Qt_QTcpSocketBasics)
* Use QTcpSocket to simply send message to host and receive return message from host. 
* Use SocketTest::stateChanged to observe the different states during connecting and disconnecting to host. 
* Use waitForConnected, waitForBytesWritten, and waitForReadyRead to make sure actions are done. 

#### [Qt QTcpSocket Using Signals And Slots](/Qt_QTcpSocketUsingSignalsAndSlots)
* Use QTcpSocket and signals and slots to send message to host and receive return message from host. 
* Instead of using the waitFor methods, here the function sits in the eventloop and waits for signals to trigger slots. 

#### [Qt QTcpServer A Basic Tcp Server App](/Qt_QTcpServerABasicTcpServerApplication)
* Use QTcpServer to create a server and listen to incoming connections from client. 
* Use listen and nextPendingConnection to communicate with client. 
* Use telnet as client to test communication with server. 

#### [Qt QTcpServer Using Multiple Threads](/Qt_QTcpServerUsingMultipleThreads)
* Use QTcpServer to create an echo server. When a new connections comes the server would new a MyThread object inhierted from QThread. The MyThread object then takes responsibility to communucate with the client on a seperated thread than the main thread. 
* Override incomingConnection method of QTcpSocket to handle new thread, thread start, and pass the socket descriptor to the MyThread object. 
* Override run method of QThread. Creates new QTcpSocket and assign its socket descriptor. Echos back the recevied message to the client. 

<br/>


# References 
[1] VoidRealms, https://www.youtube.com/channel/UCYP0nk48grsMwO3iL8YaAKA/. <br/>
