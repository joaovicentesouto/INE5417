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

    ui->AccountTable->setColumnCount(5);
    ui->AccountTable->setColumnWidth(0, 85);
    ui->AccountTable->setColumnWidth(1, 85);
    ui->AccountTable->setColumnWidth(2, 85);
    ui->AccountTable->setColumnWidth(3, 85);
    ui->AccountTable->setColumnWidth(4, 85);
    ui->AccountTable->setHorizontalHeaderLabels(titles);
    ui->AccountTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
    ui->AccountTable->setCurrentCell(-1,-1);
    ui->AccountTable->clearSelection();
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
    tableBuilder();
}

void WNewBankAccount::tableBuilder()
{
    ui->AccountTable->setRowCount(0);
    list<BankAccount*> * bankAccounts = facade->userBankAccounts();
    for (list<BankAccount*>::iterator i = bankAccounts->begin(); i != bankAccounts->end(); ++i) {
        ui->AccountTable->insertRow(ui->AccountTable->rowCount());
        ui->AccountTable->setItem(ui->AccountTable->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString((*i)->getName())));
        ui->AccountTable->setItem(ui->AccountTable->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString((*i)->getAccountNumber())));
        ui->AccountTable->setItem(ui->AccountTable->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString((*i)->getAgency())));
        ui->AccountTable->setItem(ui->AccountTable->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString((*i)->getBank())));
        ui->AccountTable->setItem(ui->AccountTable->rowCount() - 1, 4, new QTableWidgetItem(QString::number((*i)->getBalance())));
    }
    delete bankAccounts;
}

void WNewBankAccount::on_Delete_clicked()
{

}
