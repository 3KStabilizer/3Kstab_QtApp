#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    user = new UserData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menuButton_clicked()
{
    DialogMenu* menu = new DialogMenu(user,this);
    int res = menu->exec();
    qDebug()<<"res is "<<res;
    char toSendX[6];
    sprintf(toSendX,"x:%d",this->user->getX());
    char toSendY[6];
    sprintf(toSendY,"y:%d",this->user->getY());
    char toSendZ[6];
    sprintf(toSendZ,"z:%d",this->user->getZ());

    qDebug() <<"debug x :" << toSendX;
    emit valueToSend(QString(toSendX));
    emit valueToSend(QString(toSendY));
    emit valueToSend(QString(toSendZ));
}

void MainWindow::on_xPlusButton_clicked()
{
    this->user->setX(this->user->getX()+1);
    char toSend[6];
    sprintf(toSend,"x:%d",this->user->getX());
    emit valueToSend(QString(toSend));
}

void MainWindow::on_xMinusButton_clicked()
{
    this->user->setX(this->user->getX()-1);
    char toSend[6];
    sprintf(toSend,"x:%d",this->user->getX());
    emit valueToSend(QString(toSend));
}

void MainWindow::on_yPlusButton_clicked()
{
    this->user->setY(this->user->getY()+1);
    char toSend[6];
    sprintf(toSend,"y:%d",this->user->getY());
    emit valueToSend(QString(toSend));
}

void MainWindow::on_yMinusButton_clicked()
{
    this->user->setY(this->user->getY()-1);
    char toSend[6];
    sprintf(toSend,"y:%d",this->user->getY());
    emit valueToSend(QString(toSend));
}

void MainWindow::on_zPlusButton_clicked()
{
    this->user->setZ(this->user->getZ()+1);
    char toSend[6];
    sprintf(toSend,"z:%d",this->user->getZ());
    emit valueToSend(QString(toSend));
}

void MainWindow::on_zMinusButton_clicked()
{
    this->user->setZ(this->user->getZ()-1);
    char toSend[6];
    sprintf(toSend,"z:%d",this->user->getZ());
    emit valueToSend(QString(toSend));
}
