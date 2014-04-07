#include "dialogmenu.h"
#include "ui_dialogmenu.h"

DialogMenu::DialogMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMenu)
{
    ui->setupUi(this);
}

DialogMenu::~DialogMenu()
{
    delete ui;
}

void DialogMenu::on_okButton_clicked()
{
    this->close();
}

void DialogMenu::on_cancelButton_clicked()
{
    this->close();
}
