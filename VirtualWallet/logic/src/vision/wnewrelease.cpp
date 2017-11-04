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
    titles << "Id" << "Conta/Carteira" << "Tipo de Lcto." << "Tipo de Pgto." << "Operaçao" << "Data" << "Valor (R$)";

    ui->ReleaseTable->setColumnCount(7);
    ui->ReleaseTable->setColumnWidth(0, 40);
    ui->ReleaseTable->setColumnWidth(1, 100);
    ui->ReleaseTable->setColumnWidth(2, 100);
    ui->ReleaseTable->setColumnWidth(3, 100);
    ui->ReleaseTable->setColumnWidth(4, 100);
    ui->ReleaseTable->setColumnWidth(5, 100);
    ui->ReleaseTable->setColumnWidth(6, 100);
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

    for (auto & acc : facade->userAccounts()) {
        ui->Accounts->addItem(QString::fromStdString(acc->getName()));
    }

    for (auto & release : facade->userReleaseTypes()) {
        ui->ReleaseType->addItem(QString::fromStdString(release->getName()));
    }

    for (auto & payT : facade->userPaymentTypes()) {
        ui->PaymentType->addItem(QString::fromStdString(payT));
    }

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

    on_Clean_clicked();

    int row = ui->ReleaseTable->currentRow();

    if (row > -1)
        int row = ui->ReleaseTable->item(row, 0)->text().toInt();

    if (facade->registerRelease(row, value, account, releaseType, paymenteType, description, operation, date)) {
        on_Clean_clicked();
        emit build();
    } else {
        ui->Erro->setText("Dados invalidos!");
    }
    tableBuilder();
}

void WNewRelease::tableBuilder()
{
    titles << "Id" << "Conta/Carteira" << "Tipo de Lcto." << "Tipo de Pgto." << "Operaçao" << "Data" << "Valor (R$)";

    ui->ReleaseTable->setRowCount(0);
    list<Release*> releases = facade->userReleases();
    for (auto & rel : releases) {
        ui->ReleaseTable->insertRow(ui->ReleaseTable->rowCount());
        ui->ReleaseTable->setItem(ui->ReleaseTable->rowCount() - 1, 0, new QTableWidgetItem(QString::number(rel->getId())));
        ui->ReleaseTable->setItem(ui->ReleaseTable->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(rel->getAccount()->getName())));
        ui->ReleaseTable->setItem(ui->ReleaseTable->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(rel->getReleaseType())));
        ui->ReleaseTable->setItem(ui->ReleaseTable->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(rel->getPaymentType())));
        ui->ReleaseTable->setItem(ui->ReleaseTable->rowCount() - 1, 4, new QTableWidgetItem(QString::fromStdString(rel->getOperation())));
        ui->ReleaseTable->setItem(ui->ReleaseTable->rowCount() - 1, 5, new QTableWidgetItem(QString::fromStdString(rel->getDate())));
        ui->ReleaseTable->setItem(ui->ReleaseTable->rowCount() - 1, 6, new QTableWidgetItem(QString::number(rel->getValue()));
    }
}

void WNewRelease::on_Delete_clicked()
{
    int row = ui->ReleaseTable->currentRow();

    if (row < 0) {
        ui->Erro->setStyleSheet("color: red");
        ui->Erro->setText("Nenhum Lancamento Selecionado!");
    } else {
        facade->deleteRelease(ui->ReleaseTable->item(row, 0)->text().toInt());
        on_Clean_clicked();
        ui->Erro->setStyleSheet("color: green");
        ui->Erro->setText("Lancamento Excluido com Sucesso!");
        tableBuilder();
        emit build();
    }
}

void WNewRelease::on_ReleaseTable_clicked(const QModelIndex &index)
{
    int id = ui->ReleaseTable->item(index.row(), 0)->text().toInt();
    Release * release;
    for (auto & rel : facade->userReleases())
        if (rel->getId() == id) {
            release = rel;
            break;
        }

    ui->ValueBox->setValue(release->getValue());
    ui->DateEdit->setDate(QDate::fromString(QString::fromStdString(release->getDate()), "dd/MM/yyyy"));
    ui->DescRelease->setText(release->getDescription());
    ui->Erro->setText("");
    if (release->getOperation() == in)
        ui->In->setChecked(true);
    else
        ui->Out->setChecked(true);

    int i = 0;
    for (auto & acc : facade->userAccounts()) {
        if (release->getAccount()->getId() == acc->getId()) {
            ui->Accounts->setCurrentIndex(i);
            break;
        }
        i++;
    }

    i = 0;
    for (auto & rel : facade->userReleaseTypes()) {
        if (release->getReleaseType()->getName() == rel->getName()) {
            ui->ReleaseType->setCurrentIndex(i);
            break;
        }
        i++;
    }

    i = 0;
    for (auto & payT : facade->userPaymentTypes()) {
        if (release->getPaymentType() == payT) {
            ui->PaymentType->setCurrentIndex(i);
            break;
        }
        i++;
    }
}
