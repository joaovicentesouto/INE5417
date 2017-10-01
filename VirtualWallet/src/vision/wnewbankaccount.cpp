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
    //std::cout << "aaa" << std::endl;
    std::string name = ui->Name->text().toStdString();
    std::string number = ui->Number->text().toStdString();
    std::string agency = ui->Agency->text().toStdString();
    std::string bank = ui->Bank->text().toStdString();
    double balance = ui->Balance->value();
    //std::cout << "bbb" << std::endl;
    if (facade->registerBankAccount(name, balance, number, agency, bank)) {
        on_Clean_clicked();
        emit goToH();
    } else {
        ui->Erro->setText("Dados Invalidos");
    }
}
