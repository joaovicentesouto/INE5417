#include "wnewwallet.h"
#include "ui_wnewwallet.h"

WNewWallet::WNewWallet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WNewWallet)
{
    ui->setupUi(this);
    ui->Name->setPlaceholderText("Nome");

    QStringList titles;
    titles << "Id" << "Nome" << "Montante (R$)";

    ui->WalletTable->setColumnCount(3);
    ui->WalletTable->setColumnWidth(0, 40);
    ui->WalletTable->setColumnWidth(1, 220);
    ui->WalletTable->setColumnWidth(2, 220);
    ui->WalletTable->setHorizontalHeaderLabels(titles);
    ui->WalletTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

WNewWallet::~WNewWallet()
{
    delete ui;
}

void WNewWallet::setFacade(Facade &_facade)
{
    facade = &_facade;
}

void WNewWallet::on_Clean_clicked()
{
    ui->Msg->setText("");
    ui->Name->setText("");
    ui->Balance->setValue(0.0);
    ui->WalletTable->setCurrentCell(-1,-1);
    ui->WalletTable->clearSelection();
}

void WNewWallet::on_Confirm_clicked()
{
    std::string name = ui->Name->text().toStdString();
    double balance = ui->Balance->value();

    int row = ui->WalletTable->currentRow();

    if (row > -1)
        row =

    if (facade->registerWallet(name, balance)) {
        if ( > -1)
            facade->refreshWallet(ui->WalletTable->item(ui->WalletTable->currentRow(), 0)->text().toStdString(), name, balance);

    }

    on_Clean_clicked();

    if (temp) {
        ui->Msg->setStyleSheet("color: green");
        ui->Msg->setText("Operaçao Realizada com Sucesso!");
        emit build();
    } else {
        ui->Msg->setStyleSheet("color: red");
        ui->Msg->setText("Nome Invalido!");
    }
    tableBuilder();
}

void WNewWallet::tableBuilder()
{
    ui->WalletTable->setRowCount(0);
    list<std::string> * names = facade->walletsNames();
    list<double> * amounts = facade->walletsValues();
    list<double>::iterator j = amounts->begin();
    for (list<string>::iterator i = names->begin(); i != names->end(); ++i, ++j) {
        ui->WalletTable->insertRow(ui->WalletTable->rowCount());
        ui->WalletTable->setItem(ui->WalletTable->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(*i)));
        ui->WalletTable->setItem(ui->WalletTable->rowCount() - 1, 1, new QTableWidgetItem(QString::number(*j)));
    }
    delete names;
    delete amounts;
}

void WNewWallet::on_WalletTable_clicked(const QModelIndex &index)
{
    ui->Name->setText(ui->WalletTable->item(index.row(), 0)->text());
    ui->Balance->setValue(ui->WalletTable->item(index.row(), 1)->text().toDouble());
}

void WNewWallet::on_Delete_clicked()
{
    if (ui->WalletTable->currentRow() < 0) {
        ui->Msg->setStyleSheet("color: red");
        ui->Msg->setText("Nenhuma Carteira Selecionada!");
    } else {
        facade->deleteAccount(ui->WalletTable->item(ui->WalletTable->currentRow(), 0)->text().toStdString());
        on_Clean_clicked();
        ui->Msg->setStyleSheet("color: green");
        ui->Msg->setText("Carteira Excluida com Sucesso!");
        tableBuilder();
        emit build();
    }
}
