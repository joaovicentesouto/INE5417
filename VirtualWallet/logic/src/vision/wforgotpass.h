#ifndef WFORGOTPASS_H
#define WFORGOTPASS_H

#include <QWidget>
#include "./src/control/Facade.h"

using namespace project;

namespace Ui {
class WForgotPass;
}

class WForgotPass : public QWidget
{
    Q_OBJECT

public:
    explicit WForgotPass(QWidget *parent = 0);
    ~WForgotPass();

    void setFacade(Facade * _facade);

public slots:
    void on_Clean_clicked();

private slots:
    void on_Confirm_clicked();

    void on_Back_clicked();

signals:
    void cleanLogin();
    void changeStack(int _stack);

private:
    Ui::WForgotPass * ui;
    Facade * facade;
};

#endif // WFORGOTPASS_H
