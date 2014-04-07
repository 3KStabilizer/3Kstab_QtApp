#ifndef SENDINGPROCESS_H
#define SENDINGPROCESS_H

#include <QTcpSocket>
#include <QMutex>

class SendingProcess : public QObject
{
    Q_OBJECT
public:
    SendingProcess();

public slots:
    /**
     * @brief the slot which receives signals sent by MainWindow
     *
     * @param val the string emitted
     */
    void addValueToList(QString val);

private slots:
    void sendingLoop();
    void displayError(QAbstractSocket::SocketError);

private:
    QTcpSocket* sendSck;
    QString ip;
    int port;
    QList <QString> toSend; /**< list of data to send */
    QMutex mutex; /**< mutex used to avoid concurrent access on list */
};

#endif // SENDINGPROCESS_H
