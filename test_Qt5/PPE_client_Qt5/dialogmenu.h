#ifndef DIALOGMENU_H
#define DIALOGMENU_H

#include <QDialog>

namespace Ui {
class DialogMenu;
}

class DialogMenu : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogMenu(QWidget *parent = 0);
    ~DialogMenu();
    
private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::DialogMenu *ui;
};

#endif // DIALOGMENU_H
