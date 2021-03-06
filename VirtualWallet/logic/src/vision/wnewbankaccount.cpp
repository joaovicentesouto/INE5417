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
    titles << "Id" << "Nome" << "Numero" << "Agencia" << "Banco" << "Montante (R$)";

    ui->AccountTable->setColumnCount(6);
    ui->AccountTable->setColumnWidth(0, 40);
    ui->AccountTable->setColumnWidth(1, 85);
    ui->AccountTable->setColumnWidth(2, 85);
    ui->AccountTable->setColumnWidth(3, 85);
    ui->AccountTable->setColumnWidth(4, 85);
    ui->AccountTable->setColumnWidth(5, 85);
    ui->AccountTable->setHorizontalHeaderLabels(titles);
    ui->AccountTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

WNewBankAccount::~WNewBankAccount()
{
    delete ui;
}

void WNewBankAccount::setFacade(Facade * _facade)
{
    facade = _facade;
}

void WNewBankAccount::on_Clean_clicked()
{
    ui->Name->setText("");
    ui->Number->setText("");
    ui->Agency->setText("");
    ui->Bank->setText("");
    ui->Balance->setValue(0.0);
    ui->Msg->setText("");
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

    int row = ui->AccountTable->currentRow();

    if (row > -1)
        row = ui->AccountTable->item(row, 0)->text().toInt();

    on_Clean_clicked();

    if (facade->registerBankAccount(row, name, balance, number, agency, bank)) {
        ui->Msg->setStyleSheet("color: green");
        ui->Msg->setText("Operaçao Realizada com Sucesso!");
        emit build();
    } else {
        ui->Msg->setStyleSheet("color: red");
        ui->Msg->setText("Dados Invalidos!");
    }
    tableBuilder();
}

void WNewBankAccount::tableBuilder()
{
    ui->AccountTable->setRowCount(0);
    for (auto bankAcc : facade->userBankAccounts()) {
        ui->AccountTable->insertRow(ui->AccountTable->rowCount());
        ui->AccountTable->setItem(ui->AccountTable->rowCount() - 1, 0, new QTableWidgetItem(QString::number(bankAcc->getId())));
        ui->AccountTable->setItem(ui->AccountTable->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(bankAcc->getName())));
        ui->AccountTable->setItem(ui->AccountTable->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(bankAcc->getAccountNumber())));
        ui->AccountTable->setItem(ui->AccountTable->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(bankAcc->getAgency())));
        ui->AccountTable->setItem(ui->AccountTable->rowCount() - 1, 4, new QTableWidgetItem(QString::fromStdString(bankAcc->getBank())));
        ui->AccountTable->setItem(ui->AccountTable->rowCount() - 1, 5, new QTableWidgetItem(QString::number(bankAcc->getBalance())));
    }
}

void WNewBankAccount::on_AccountTable_clicked(const QModelIndex &index)
{
    ui->Name->setText(ui->AccountTable->item(index.row(), 1)->text());
    ui->Number->setText(ui->AccountTable->item(index.row(), 2)->text());
    ui->Agency->setText(ui->AccountTable->item(index.row(), 3)->text());
    ui->Bank->setText(ui->AccountTable->item(index.row(), 4)->text());
    ui->Balance->setValue(ui->AccountTable->item(index.row(), 5)->text().toDouble());
}

void WNewBankAccount::on_Delete_clicked()
{
    int row = ui->AccountTable->currentRow();

    if (row < 0) {
        ui->Msg->setStyleSheet("color: red");
        ui->Msg->setText("Nenhuma Conta Selecionada!");
    } else {
        facade->deleteAccount(ui->AccountTable->item(row, 0)->text().toInt());
        on_Clean_clicked();
        ui->Msg->setStyleSheet("color: green");
        ui->Msg->setText("Conta Excluida com Sucesso!");
        tableBuilder();
        emit build();
    }
}
