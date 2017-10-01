#ifndef WACCOUNT_H
#define WACCOUNT_H

#include <QWidget>
#include "./src/model/BankAccount.h"
#include "./src/model/Wallet.h"

using namespace project;

namespace Ui {
class WAccount;
}

class WAccount : public QWidget
{
    Q_OBJECT

public:
    explicit WAccount(QWidget *parent = 0);
    WAccount(Account *account, QWidget *parent = 0);
    WAccount(BankAccount *account, QWidget *parent = 0);
    WAccount(Wallet *account, QWidget *parent = 0);
    ~WAccount();

private:
    Ui::WAccount *ui;
};

#endif // WACCOUNT_H
