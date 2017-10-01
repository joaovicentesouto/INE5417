#ifndef WNEWBANKACCOUNT_H
#define WNEWBANKACCOUNT_H

#include <QWidget>
#include "./src/control/Facade.h"

using namespace project;

namespace Ui {
class WNewBankAccount;
}

class WNewBankAccount : public QWidget
{
    Q_OBJECT

public:
    explicit WNewBankAccount(QWidget *parent = 0);
    ~WNewBankAccount();

    void setFacade(Facade &_facade);

private slots:
    void on_Clean_clicked();

    void on_Confirm_clicked();

signals:
    void goToH();

private:
    Ui::WNewBankAccount *ui;
    Facade * facade;
};

#endif // WNEWBANKACCOUNT_H
