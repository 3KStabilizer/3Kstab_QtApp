#include "sendingprocess.h"
#include <QMessageBox>
#include <QDebug>

SendingProcess::SendingProcess()
{
    ip = "192.168.0.10";
    port = 1234;
    sendSck = new QTcpSocket();
    sendSck->connectToHost(ip,port);
    connect(sendSck, SIGNAL(connected()), this, SLOT(sendingLoop()));
    connect(sendSck, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
}

void SendingProcess::sendingLoop()
{
    qDebug()<<"connect sending";
    while (!toSend.isEmpty())
    {
        QString data = "";
        if(!toSend.isEmpty())
        {
            mutex.lock();
            data = toSend.first();

            toSend.removeFirst();
            mutex.unlock();

            QByteArray array;
            array.append(data);

            qDebug()<<"state "<<sendSck->state();

            qDebug()<<"send "<<sendSck->write(array)<<" bytes";

            //sckWrite->flush();
            //sckWrite->close();
        }
    }
}

void SendingProcess::displayError(QAbstractSocket::SocketError err)
{
    QMessageBox warn;
    QString msg;
    msg = QString("Connection error : ");
    switch(err){
        case QAbstractSocket::ConnectionRefusedError:
            msg += "The connection was refused by the peer (or timed out).";
            break;
        case QAbstractSocket::RemoteHostClosedError:
            msg += "The remote host closed the connection. Note that the client socket (i.e., this socket) will be closed after the remote close notification has been sent.";
            break;
        case QAbstractSocket::HostNotFoundError:
            msg += "The host address was not found.";
            break;
        case QAbstractSocket::SocketAccessError	:
            msg += "The socket operation failed because the application lacked the required privileges.";
            break;
        case QAbstractSocket::SocketResourceError :
            msg += "The local system ran out of resources (e.g., too many sockets).";
            break;
        case QAbstractSocket::SocketTimeoutError :
            msg += "The socket operation timed out.";
            break;
        case QAbstractSocket::DatagramTooLargeError	:
            msg += "The datagram was larger than the operating system's limit (which can be as low as 8192 bytes).";
            break;
        case QAbstractSocket::NetworkError:
            msg += "An error occurred with the network (e.g., the network cable was accidentally plugged out).";
            break;
        case QAbstractSocket::AddressInUseError	:
            msg += "The address specified to QAbstractSocket::bind() is already in use and was set to be exclusive.";
            break;
        case QAbstractSocket::SocketAddressNotAvailableError:
            msg += "The address specified to QAbstractSocket::bind() does not belong to the host.";
            break;
        case QAbstractSocket::UnsupportedSocketOperationError:
            msg += "The requested socket operation is not supported by the local operating system (e.g., lack of IPv6 support).";
            break;
        case QAbstractSocket::ProxyAuthenticationRequiredError:
            msg += "The socket is using a proxy, and the proxy requires authentication.";
            break;
        case QAbstractSocket::SslHandshakeFailedError:
            msg += "The SSL/TLS handshake failed, so the connection was closed (only used in QSslSocket)";
            break;
        case QAbstractSocket::UnfinishedSocketOperationError:
            msg += "Used by QAbstractSocketEngine only, The last operation attempted has not finished yet (still in progress in the background).";
            break;
        case QAbstractSocket::ProxyConnectionRefusedError:
            msg += "Could not contact the proxy server because the connection to that server was denied";
            break;
        case QAbstractSocket::ProxyConnectionClosedError:
            msg += "The connection to the proxy server was closed unexpectedly (before the connection to the final peer was established)";
            break;
        case QAbstractSocket::ProxyConnectionTimeoutError:
            msg += "The connection to the proxy server timed out or the proxy server stopped responding in the authentication phase.";
            break;
        case QAbstractSocket::ProxyNotFoundError:
            msg += "The proxy address set with setProxy() (or the application proxy) was not found.";
            break;
        case QAbstractSocket::ProxyProtocolError:
            msg += "The connection negotiation with the proxy server failed, because the response from the proxy server could not be understood.";
            break;
        case QAbstractSocket::OperationError:
            msg += "An operation was attempted while the socket was in a state that did not permit it.";
            break;
        case QAbstractSocket::SslInternalError:
            msg += "The SSL library being used reported an internal error. This is probably the result of a bad installation or misconfiguration of the library.";
            break;
        case QAbstractSocket::SslInvalidUserDataError:
            msg += "Invalid data (certificate, key, cypher, etc.) was provided and its use resulted in an error in the SSL library.";
            break;
        case QAbstractSocket::TemporaryError:
            msg += "A temporary error occurred (e.g., operation would block and socket is non-blocking).";
            break;
        case QAbstractSocket::UnknownSocketError:
            msg += "An unidentified error occurred.";
            break;
    }
    msg += err;
    warn.setText(msg);
    warn.exec();
}

void SendingProcess::addValueToList(QString val)
{
    if(sendSck->state()==QAbstractSocket::ConnectedState)
    {
        QByteArray array;
        array.append(val);
        qDebug()<<"send "<<sendSck->write(array)<<" bytes";
    }
    else
    {
        mutex.lock();
        toSend.append(val);
        qDebug()<<"new value to send : "<<val;
        mutex.unlock();
    }

}
