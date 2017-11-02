#include "wnewbankaccount.h"
#include "ui_wnewbankaccount.h"
#include <iostream>

WNewBankAccount::WNewBankAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WNewBankAccount)
{
    ui->setupUi(this);
    ui->Name->setPlaceholderText("Nome");
    ui->Number->setPlaceholderText("Numero da Conta");
    ui->Agency->setPlaceholderText("Agencia");
    ui->Bank->setPlaceholderText("Banco");

    QStringList titles;
    titles << "Nome" << "Numero" << "Agencia" << "Banco" << "Montante (R$)";

    /*ui->WalletTable->setColumnCount(5);
    ui->WalletTable->setColumnWidth(0, 85);
    ui->WalletTable->setColumnWidth(1, 85);
    ui->WalletTable->setColumnWidth(2, 85);
    ui->WalletTable->setColumnWidth(3, 85);
    ui->WalletTable->setColumnWidth(4, 85);
    ui->WalletTable->setHorizontalHeaderLabels(titles);
    ui->WalletTable->setEditTriggers(QAbstractItemView::NoEditTriggers);*/
}

WNewBankAccount::~WNewBankAccount()
{
    delete ui;
}

void WNewBankAccount::setFacade(Facade &_facade)
{
    facade = &_facade;
}

void WNewBankAccount::on_Clean_clicked()
{
    ui->Name->setText("");
    ui->Number->setText("");
    ui->Agency->setText("");
    ui->Bank->setText("");
    ui->Balance->setValue(0.0);
    ui->Erro->setText("");
}

void WNewBankAccount::on_Confirm_clicked()
{
    std::string name = ui->Name->text().toStdString();
    std::string number = ui->Number->text().toStdString();
    std::string agency = ui->Agency->text().toStdString();
    std::string bank = ui->Bank->text().toStdString();
    double balance = ui->Balance->value();

    if (facade->registerBankAccount(name, balance, number, agency, bank)) {
        on_Clean_clicked();
        emit build();
    } else {
        ui->Erro->setText("Dados invalidos!");
    }

}

void WNewBankAccount::on_Delete_clicked()
{

}
