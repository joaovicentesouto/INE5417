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
    void on_Confirm_clicked();

signals:
    void userRegistred();
    void changeStack(int _stack);

private:
    Ui::WNewUser *ui;
    Facade * facade;
};

#endif // WNEWUSER_H
