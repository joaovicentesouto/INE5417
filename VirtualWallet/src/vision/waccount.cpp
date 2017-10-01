#include "waccount.h"
#include "ui_waccount.h"

WAccount::WAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WAccount)
{
    ui->setupUi(this);
}

WAccount::WAccount(Account *account, QWidget *parent) :
    WAccount(parent)
{
    ui->Name->setText(QString::fromStdString(account->getName()));
    ui->Number->setText("");
    ui->Agency->setText("");
    ui->Bank->setText("");
}

WAccount::WAccount(BankAccount *account, QWidget *parent) :
    WAccount(parent)
{
    ui->Name->setText(QString::fromStdString(account->getName()));
    ui->Number->setText(QString::fromStdString(account->getAccountNumber()));
    ui->Agency->setText(QString::fromStdString(account->getAgency()));
    ui->Bank->setText(QString::fromStdString(account->getBank()));
}

WAccount::WAccount(Wallet *account, QWidget *parent) :
    WAccount(parent)
{
    ui->Name->setText(QString::fromStdString(account->getName()));
    ui->Number->setText("");
    ui->Agency->setText("");
    ui->Bank->setText("");
}

WAccount::~WAccount()
{
    delete ui;
}
