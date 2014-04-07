#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebKit>
#include <iostream>
//#include <QtWebKitWidgets/QtWebKitWidgets>
#include "dialogmenu.h"

namespace Ui {
class MainWindow;
}
/**
 * @brief Main window of the application, implements view and user actions
 * inherits from QMainWindow
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    /**
     * @brief main constructor
     *
     * @param parent the parent creating the window (no parent in our caseà
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * @brief destructor
     *
     */
    ~MainWindow();

private slots:
    /**
     * @brief callback when user click on menu button
     *
     */
    void on_menuButton_clicked();

    /**
     * @brief callback which emit a Qt signal when user click on X+ button
     *
     */
    void on_xPlusButton_clicked();

    /**
     * @brief callback which emit a Qt signal when user click on X- button
     *
     */
    void on_xMinusButton_clicked();

    /**
     * @brief callback which emit a Qt signal when user click on Y+ button
     *
     */
    void on_yPlusButton_clicked();

    /**
     * @brief callback which emit a Qt signal when user click on Y- button
     *
     */
    void on_yMinusButton_clicked();

    /**
     * @brief callback which emit a Qt signal when user click on Z+ button
     *
     */
    void on_zPlusButton_clicked();

    /**
     * @brief callback which emit a Qt signal when user click on Z- button
     *
     */
    void on_zMinusButton_clicked();

private:
    Ui::MainWindow *ui; /**< pointer on the Qt UI */
    UserData* user; /**< pointer on the user's data */

signals:
    /**
     * @brief signal emiting on user action which need to be sent to the server
     *
     * @param val the string to emit
     */
    void valueToSend(QString val);
};

#endif // MAINWINDOW_H
