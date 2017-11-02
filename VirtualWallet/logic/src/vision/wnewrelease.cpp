#include "wnewrelease.h"
#include "ui_wnewrelease.h"

WNewRelease::WNewRelease(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WNewRelease)
{
    ui->setupUi(this);
    ui->DescRelease->setPlaceholderText("Descricao");
    ui->DateEdit->setDisplayFormat("dd/MM/yyyy");

    QStringList titles;
    titles << "Conta/Carteira" << "Tipo de Lcto." << "Tipo de Pgto." << "Operaçao" << "Data" << "Valor (R$)";

    ui->ReleaseTable->setColumnCount(6);
    ui->ReleaseTable->setColumnWidth(0, 100);
    ui->ReleaseTable->setColumnWidth(1, 100);
    ui->ReleaseTable->setColumnWidth(2, 100);
    ui->ReleaseTable->setColumnWidth(3, 100);
    ui->ReleaseTable->setColumnWidth(4, 100);
    ui->ReleaseTable->setColumnWidth(5, 100);
    ui->ReleaseTable->setHorizontalHeaderLabels(titles);
    ui->ReleaseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

WNewRelease::~WNewRelease()
{
    delete ui;
}

void WNewRelease::setFacade(Facade &_facade) {
    facade = &_facade;
}

void WNewRelease::update() {

    on_Clean_clicked();
    ui->Accounts->clear();
    ui->ReleaseType->clear();
    ui->PaymentType->clear();

    ui->Accounts->addItem("Conta");
    ui->ReleaseType->addItem("Tipo de Lancamento");
    ui->PaymentType->addItem("Tipo de Pagamento");

    list<std::string> * names = facade->accountsNames();
    for (list<string>::iterator it = names->begin(); it != names->end(); ++it) {
        ui->Accounts->addItem(QString::fromStdString(*it));
    }
    delete names;

    names = facade->releaseTypesNames();
    for (list<string>::iterator it = names->begin(); it != names->end(); ++it) {
        ui->ReleaseType->addItem(QString::fromStdString(*it));
    }
    delete names;

    names = facade->paymentTypesNames();
    for (list<string>::iterator it = names->begin(); it != names->end(); ++it) {
        ui->PaymentType->addItem(QString::fromStdString(*it));
    }
    delete names;

    ui->DateEdit->setDate(QDate::currentDate());
}

void WNewRelease::on_Clean_clicked()
{
    ui->ValueBox->setValue(0.0);
    ui->Accounts->setCurrentIndex(0);
    ui->ReleaseType->setCurrentIndex(0);
    ui->PaymentType->setCurrentIndex(0);
    ui->DateEdit->setDate(QDate::currentDate());
    ui->DescRelease->setText("");
    ui->Erro->setText("");
    ui->In->setAutoExclusive(false);
    ui->In->setChecked(false);
    ui->Out->setChecked(false);
    ui->In->setAutoExclusive(true);
    ui->ReleaseTable->setCurrentCell(-1,-1);
    ui->ReleaseTable->clearSelection();
}

void WNewRelease::on_Confirm_clicked()
{
    std::string account = ui->Accounts->currentText().toStdString();
    std::string releaseType = ui->ReleaseType->currentText().toStdString();
    std::string paymenteType = ui->PaymentType->currentText().toStdString();
    std::string description = ui->DescRelease->toPlainText().toStdString();
    std::string operation = ui->In->isChecked()? "in" : ui->Out->isChecked()? "out" : "error";
    std::string date = ui->DateEdit->date().toString("dd/MM/yyyy").toStdString();
    double value = ui->ValueBox->value();

    if (facade->registerRelease(value, account, releaseType, paymenteType, description, operation, date)) {
        on_Clean_clicked();
        emit build();
    } else {
        ui->Erro->setText("Dados invalidos!");
    }
}

void WNewRelease::tableBuilder()
{
    /*ui->ReleaseTable->setRowCount(0);
    list<std::string> * names = facade->walletsNames();
    list<double> * amounts = facade->walletsValues();
    list<double>::iterator j = amounts->begin();
    for (list<string>::iterator i = names->begin(); i != names->end(); ++i, ++j) {
        ui->WalletTable->insertRow(ui->WalletTable->rowCount());
        ui->WalletTable->setItem(ui->WalletTable->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(*i)));
        ui->WalletTable->setItem(ui->WalletTable->rowCount() - 1, 1, new QTableWidgetItem(QString::number(*j)));
    }
    delete names;
    delete amounts;*/
}
