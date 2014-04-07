#include "dialogmenu.h"
#include "ui_dialogmenu.h"

DialogMenu::DialogMenu(UserData* dat,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMenu)
{
    ui->setupUi(this);
    ud = dat;
    this->ui->spinBox_X->setValue(ud->getX());
    this->ui->spinBox_Y->setValue(ud->getY());
    this->ui->spinBox_Z->setValue(ud->getZ());
}

DialogMenu::~DialogMenu()
{
    delete ui;
}

void DialogMenu::on_okButton_clicked()
{
    ud->setX(this->ui->spinBox_X->value());
    ud->setY(this->ui->spinBox_Y->value());
    ud->setZ(this->ui->spinBox_Z->value());
    this->accept();
}

void DialogMenu::on_cancelButton_clicked()
{
    this->reject();
}
