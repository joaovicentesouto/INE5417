#ifndef WNEWBANKACCOUNT_H
#define WNEWBANKACCOUNT_H

#include <QWidget>

namespace Ui {
class WNewBankAccount;
}

class WNewBankAccount : public QWidget
{
    Q_OBJECT

public:
    explicit WNewBankAccount(QWidget *parent = 0);
    ~WNewBankAccount();

private slots:
    void on_Clean_clicked();

private:
    Ui::WNewBankAccount *ui;
};

#endif // WNEWBANKACCOUNT_H
