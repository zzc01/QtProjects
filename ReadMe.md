# Qt Practice Projects

* These practice projects are created by QtCreator 6.0.2. 
* Some research and study about the usage of Qt Network, QTcpSocket, QTcpServer, QUdpSocket, QThread, and QThreadPool. 
* These are mainly based on tutorials from VoidRealms[1] Youtube channel. 
* I also built a simple windows app that sends messages between two users using UDP packages. 


<br/>

## Install Qt 
* Followed instructions from VoidRealms[1]. 
* Need registration to download Qt from [Qt website](https://www.qt.io/). 
* Choose Qt for Open Source Development. [Open Source Usage Obligations](https://www.qt.io/download-open-source?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5).
* In the future if want to add packages can use Qt MaintenanceTool to add them. 
* There are some other resources that demonstrate how to install and use openCV with QT. <br/><br/>


## Notes
#### [Qt Download File From Web](/Qt_QhttpDownloadFilesFromWeb)
* Use QNetworkAccessManager, QNetworkRequest, QNetworkReply, QUrl to send a simple get command to an http host. 
* Use QEventLoop to wait for the finished signal to be emitted. 
* Use readAll and QFile to retrieve the data and save to text.txt file. 

#### [Qt QTcpSocket Basics](/Qt_QTcpSocketBasics)
* Use QTcpSocket to simply send message to host and receive return message from host. 
* Use SocketTest::stateChanged to observe the different states during connecting and disconnecting to the host. 
* Use waitForConnected, waitForBytesWritten, and waitForReadyRead to make sure actions are done. 

#### [Qt QTcpSocket Using Signals And Slots](/Qt_QTcpSocketUsingSignalsAndSlots)
* Use QTcpSocket and signals and slots to send message to host and receive return message from host. 
* Instead of using the waitFor methods, here the function sits in the eventloop and waits for signals to trigger slots. 

#### [Qt QTcpServer A Basic Tcp Server App](/Qt_QTcpServerABasicTcpServerApplication)
* Use QTcpServer to create a server and listen to incoming connections from clients. 
* Use listen and nextPendingConnection to communicate with clients. 
* Use telnet as client to test communication with server. 

#### [Qt QTcpServer Using Multiple Threads](/Qt_QTcpServerUsingMultipleThreads)
* Use QTcpServer to create an echo server. When a new connection comes the server would create a MyThread object inherited from QThread. The MyThread object then takes responsibility to communicate with the client on a separate thread than the main thread. 
* Override the incomingConnection method of QTcpSocket to handle new thread, thread start, and pass the socket descriptor to the MyThread object. 
* Override the run method of QThread. Creates new QTcpSocket and assigns its socket descriptor. Echoes back the received message to the client. 

#### [Qt QTcpServer Using QThreadPool](/Qt_QTcpServerUsingQThreadPool)
* Use QThreadPool to handle the incoming connections instead of QThread as in previous practice. 
* The threadpool helps manage the amount of threads created. When the max thread count limit is reached, the function will wait till a thread is freed and then use it to handle the new connection. 
* Use MySocket object which inherits QObject and Qrunnable. 

#### [Qt Advanced Asynchronous QTcpServer With QThreadPool](/Qt_AdvancedAsynchronousQTcpServerWithQThreadPool)
* In this practice, similar to the previous one, the server object creates a MyClient object for each incoming client connection. But here the MyClient object uses QThreadPool to handle each read message task, which can take milliseconds to finish. 
* The main difference of this practice and the previous one are the followings: 
  *  In the previous practice each client connection and its whole connection read and write tasks were handled in a thread of threadpool.
  *  In this practice it is the client's read message task that is handled in a thread of threadpool. This way the read message task, which can take milliseconds to finish, would not block any other read or write tasks with the same client. 

#### [Qt QudpSocket](/Qt_QudpSocket)
* Use QUdpSocket to bind to a local ip and port, and use writeDatagram to send packets to the target ip and port. 
* Use QByteArray buffer, readDatagram, and pendingDatagramSize to read received UDP packets. 




<br/>


# References 
[1] VoidRealms, https://www.youtube.com/channel/UCYP0nk48grsMwO3iL8YaAKA/. <br/>
