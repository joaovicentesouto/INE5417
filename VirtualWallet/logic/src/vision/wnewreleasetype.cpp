#include "wnewreleasetype.h"
#include "ui_wnewreleasetype.h"

WNewReleaseType::WNewReleaseType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WNewReleaseType)
{
    ui->setupUi(this);
    ui->Name->setPlaceholderText("Nome");

    QStringList titles;
    titles << "Tipos de Lançamentos";

    ui->TypeList->setColumnCount(1);
    ui->TypeList->setColumnWidth(0, 441);
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
    std::string name = ui->Name->text().toStdString();
    bool temp = true;

    if (ui->TypeList->currentRow() > -1)
        temp = facade->refreshReleaseType(ui->TypeList->currentItem()->text().toStdString(), name);
    else
        temp = facade->registerReleaseType(name);

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

void WNewReleaseType::tableBuilder()
{
    ui->TypeList->setRowCount(0);
    list<std::string> * names = facade->releaseTypesNames();
    for (list<string>::iterator it = names->begin(); it != names->end(); ++it) {
        ui->TypeList->insertRow(ui->TypeList->rowCount());
        ui->TypeList->setItem(ui->TypeList->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(*it)));
    }
    delete names;
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
        facade->deleteReleaseType(ui->TypeList->currentItem()->text().toStdString());
        on_Clean_clicked();
        ui->Msg->setStyleSheet("color: green");
        ui->Msg->setText("Tipo de Lançamento Excluido com Sucesso!");
        tableBuilder();
        emit build();
    }
}
