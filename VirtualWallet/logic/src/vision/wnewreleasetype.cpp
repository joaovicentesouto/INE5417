#include "wnewreleasetype.h"
#include "ui_wnewreleasetype.h"

WNewReleaseType::WNewReleaseType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WNewReleaseType)
{
    ui->setupUi(this);
    ui->Name->setPlaceholderText("Nome");

    QStringList titles;
    titles << "Id" << "Tipos de Lançamentos";

    ui->TypeList->setColumnCount(2);
    ui->TypeList->setColumnWidth(0, 40);
    ui->TypeList->setColumnWidth(1, 400);
    ui->TypeList->setHorizontalHeaderLabels(titles);
    ui->TypeList->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

WNewReleaseType::~WNewReleaseType()
{
    delete ui;
}

void WNewReleaseType::setFacade(Facade &_facade) {
    facade = &_facade;
}

void WNewReleaseType::on_Clean_clicked()
{
    ui->Name->setText("");
    ui->Msg->setText("");
    ui->TypeList->setCurrentCell(-1,-1);
    ui->TypeList->clearSelection();
}

void WNewReleaseType::on_Confirm_clicked()
{
    int row = ui->TypeList->currentRow();

    if (row > -1)
        row = ui->TypeList->item(row, 0)->text().toInt();

    if (facade->registerReleaseType(ui->Name->text().toStdString(), row)) {
        ui->Msg->setStyleSheet("color: green");
        ui->Msg->setText("Operaçao Realizada com Sucesso!");
        emit build();
    } else {
        ui->Msg->setStyleSheet("color: red");
        ui->Msg->setText("Nome Invalido!");
    }

    on_Clean_clicked();
    tableBuilder();
}

void WNewReleaseType::tableBuilder()
{
    ui->TypeList->setRowCount(0);
    list<ReleaseType*> _types = facade->releaseTypes();
    for (auto & it: _types) {
        ui->TypeList->insertRow(ui->TypeList->rowCount());
        ui->TypeList->setItem(ui->TypeList->rowCount() - 1, 0, new QTableWidgetItem(QString::number(it->getId())));
        ui->TypeList->setItem(ui->TypeList->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(it->getName())));
    }
}

void WNewReleaseType::on_TypeList_clicked(const QModelIndex &index)
{
    ui->Name->setText(ui->TypeList->item(index.row(), index.column())->text());
}

void WNewReleaseType::on_Delete_clicked()
{
    if (ui->TypeList->currentRow() < 0) {
        ui->Msg->setStyleSheet("color: red");
        ui->Msg->setText("Nenhum Tipo de Lançamento Selecionado!");
    } else {
        facade->deleteReleaseType(ui->TypeList->item(ui->TypeList->currentRow(), 0)->text().toInt());
        on_Clean_clicked();
        ui->Msg->setStyleSheet("color: green");
        ui->Msg->setText("Tipo de Lançamento Excluido com Sucesso!");
        tableBuilder();
        emit build();
    }
}
