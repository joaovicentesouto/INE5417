#include "wnewbankaccount.h"
#include "ui_wnewbankaccount.h"

WNewBankAccount::WNewBankAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WNewBankAccount)
{
    ui->setupUi(this);
    ui->Name->setPlaceholderText("Nome");
    ui->Number->setPlaceholderText("Numero da Conta");
    ui->Agency->setPlaceholderText("Agencia");
    ui->Bank->setPlaceholderText("Banco");
}

WNewBankAccount::~WNewBankAccount()
{
    delete ui;
}

void WNewBankAccount::on_Clean_clicked()
{
    ui->Name->setText("");
    ui->Number->setText("");
    ui->Agency->setText("");
    ui->Bank->setText("");
    ui->Balance->setValue(0.0);
}
