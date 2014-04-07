#ifndef DIALOGMENU_H
#define DIALOGMENU_H

#include <QDialog>
#include "userdata.h"

namespace Ui {
class DialogMenu;
}

/**
 * @brief The menu window where the user can parametrize its stabilizer
 * inherits from QDialog
 */
class DialogMenu : public QDialog
{
    Q_OBJECT
    
public:
    /**
     * @brief constructor for the dialog menu window
     *
     * @param dat the user's data
     * @param parent the parent window
     */
    explicit DialogMenu(UserData* dat,QWidget *parent = 0);
    /**
     * @brief destructor
     *
     */
    ~DialogMenu();
    
private slots:
    /**
     * @brief callback called when the Ok button is clicked
     *
     */
    void on_okButton_clicked();

    /**
     * @brief callback called when the user click the cancel button
     *
     */
    void on_cancelButton_clicked();

private:
    Ui::DialogMenu *ui; /**< pointer on the Qt UI of the frame */

    UserData* ud; /**< pointer on the user's data */
};

#endif // DIALOGMENU_H
