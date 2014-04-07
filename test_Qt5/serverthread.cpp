#include "serverthread.h"
#include <QDebug>
#include <QByteArray>

using namespace std;

/**************** Sending thread *********************/
ThreadSending::ThreadSending() : QThread()
{
    serverIP = "192.168.0.4";
    portWrite = 1234;
}

void ThreadSending::addValueToList(QString val)
{
    mutex.lock();
    toSend.append(val);
    qDebug()<<"new value to send : "<<val;
    mutex.unlock();
}

void ThreadSending::run()
{
    QTcpSocket* sckWrite = new QTcpSocket();
    sckWrite->connectToHost(serverIP,portWrite);
    if(sckWrite->waitForConnected(-1))
    {
        qDebug()<<"connect sending";
        while (true)
        {
            string data = "";
            if(!toSend.isEmpty())
            {
                mutex.lock();
                data = toSend.first().toStdString();

                toSend.removeFirst();
                mutex.unlock();

                QString dt = QString::fromStdString(data+"\n");
                QByteArray array;
                array.append(dt);

                qDebug()<<"state "<<sckWrite->state();

                qDebug()<<"send "<<sckWrite->write(array)<<" bytes";

                //sckWrite->flush();
                //sckWrite->close();
            }
        }
    }
    else
        qDebug()<<"fail to connect sending";
}

/*********************** receiving thread **************/
ThreadReceiving::ThreadReceiving() : QThread()
{
    serverIP = "192.168.0.4";
    portRead = 1235;
    //serverSckRead = new QTcpSocket();
    //this->connectToServer();
}
void ThreadReceiving::run()
{
    QTcpSocket sckRead;
    sckRead.connectToHost(serverIP,portRead);
    if(sckRead.waitForConnected(-1))
    {
        qDebug()<<"success when connecting receiving";
        while(true)
        {
            QString obj = sckRead.readLine();
            //qDebug()<<"receive : "<<obj;
        }
    }
    else
        qDebug()<<"fail to connect receiving";
    //qDebug()<<"receiving connected";

}
