#ifndef READINGPROCESS_H
#define READINGPROCESS_H

#include <QTcpSocket>

class ReadingProcess : public QObject
{
    Q_OBJECT
public:
    ReadingProcess();

private slots:
    void readingLoop();
    void displayError(QAbstractSocket::SocketError);

private:
    QTcpSocket* readSck;
    QString ip;
    int port;
};

#endif // READINGPROCESS_H
