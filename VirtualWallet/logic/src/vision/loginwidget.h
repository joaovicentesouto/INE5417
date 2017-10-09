#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "./src/control/Facade.h"

using namespace project;

namespace Ui {
class loginwidget;
}

class loginwidget : public QWidget
{
    Q_OBJECT

public:
    explicit loginwidget(QWidget *parent = 0);
    ~loginwidget();

    void setFacade(Facade & _facade);

public slots:
    void on_CleanButton_clicked();

    void changeToNewUserMsg();

private slots:
    void on_ConfirmButton_clicked();

    void on_LoginPasswordForgot_clicked();

    void on_LoginNameForgot_clicked();

signals:
    void configureMenu();
    void cleanForgotName();
    void cleanForgotPassword();
    void changeStack(int _stack);

private:
    Ui::loginwidget *ui;
    Facade * facade;
};

#endif // LOGINWIDGET_H
