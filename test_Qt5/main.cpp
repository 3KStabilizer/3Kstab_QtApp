#include "mainwindow.h"
#include <QApplication>
#include <QtCore>
#include "serverthread.h"
#include "readingprocess.h"
#include "sendingprocess.h"

#include <iostream>

using namespace std;

void debugOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
}

int main(int argc, char *argv[])
{   
    qInstallMessageHandler(debugOutput);

    QApplication a(argc, argv);
    MainWindow w;
    SendingProcess* sp = new SendingProcess();
    ReadingProcess* rp = new ReadingProcess();
    w.show();
    QObject::connect(&w, SIGNAL( valueToSend(QString) ), sp, SLOT( addValueToList(QString) ));
    /*ThreadSending* ts = new ThreadSending();
    ThreadReceiving* tr = new ThreadReceiving();
    QObject::connect(&w, SIGNAL( valueToSend(QString) ), ts, SLOT( addValueToList(QString) ));
    ts->start();
    tr->start();*/

    return a.exec();
}
