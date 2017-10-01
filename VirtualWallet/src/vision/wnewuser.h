#ifndef WNEWUSER_H
#define WNEWUSER_H

#include <QWidget>
#include "./src/control/Facade.h"

using namespace project;

namespace Ui {
class WNewUser;
}

class WNewUser : public QWidget
{
    Q_OBJECT

public:
    explicit WNewUser(QWidget *parent = 0);
    ~WNewUser();

    void setFacade(Facade & _facade);

public slots:
    void on_Clean_clicked();

private slots:
    void on_Name_textEdited(const QString &arg1);

    void on_Code_textEdited(const QString &arg1);

    void on_Password_textEdited(const QString &arg1);

    void on_PassConfirm_textEdited(const QString &arg1);

    void on_Confirm_clicked();

signals:
    void userRegistred();
    void changeStack(int _stack);

private:
    Ui::WNewUser *ui;
    Facade * facade;
    bool name{false}, code{false}, password{false}, confirm{false};
};

#endif // WNEWUSER_H
