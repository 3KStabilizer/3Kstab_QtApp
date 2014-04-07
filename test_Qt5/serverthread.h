#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include <QMutex>
#include <QTcpSocket>
#include <iostream>

/**
 * @brief thread establishing connection with server and sends data to the server
 * inherits from QThread
 */
class ThreadSending : public QThread
{
    Q_OBJECT
public:
    /**
     * @brief constructor, initiliaze IP and port
     *
     */
    ThreadSending();

public slots:
    /**
     * @brief the slot which receives signals sent by MainWindow
     *
     * @param val the string emitted
     */
    void addValueToList(QString val);

private:
    /**
     * @brief method call when the thread starts
     *
     */
    void run();

    QString serverIP; /**< the IP of the server */
    int portWrite; /**< the port where it connects */
    QList <QString> toSend; /**< list of data to send */
    QMutex mutex; /**< mutex used to avoid concurrent access on list */
};

/**
 * @brief thread establishing connections and receives data from the server
 */
class ThreadReceiving : public QThread
{
public:
    /**
     * @brief constructor initialize IP and port
     *
     */
    ThreadReceiving();

private:
    /**
     * @brief method call when the thread starts
     *
     */
    void run();

    QString serverIP; /**< the server IP */
    int portRead; /**< port used for connection */
};


#endif // SERVERTHREAD_H
