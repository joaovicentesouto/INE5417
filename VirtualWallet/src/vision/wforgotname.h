#ifndef WFORGOTNAME_H
#define WFORGOTNAME_H

#include <QWidget>
#include "./src/control/Facade.h"

using namespace project;

namespace Ui {
class WForgotName;
}

class WForgotName : public QWidget
{
    Q_OBJECT

public:
    explicit WForgotName(QWidget *parent = 0);
    ~WForgotName();

    void setFacade(Facade & _facade);

public slots:
    void on_Clean_clicked();

private slots:
    void on_Code_textEdited(const QString &arg1);

    void on_Password_textEdited(const QString &arg1);

    void on_NewName_textEdited(const QString &arg1);

    void on_NameConfirm_textEdited(const QString &arg1);

    void on_Confirm_clicked();

    void on_Back_clicked();

signals:
    void cleanLogin();
    void changeStack(int _stack);

private:
    Ui::WForgotName *ui;
    Facade * facade;
    bool name{false}, code{false}, password{false}, confirm{false};
};

#endif // WFORGOTNAME_H
