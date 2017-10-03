#include "wnewreleasetype.h"
#include "ui_wnewreleasetype.h"
#include <stdio.h>

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
    ui->Erro->setText("");
}

void WNewReleaseType::on_Confirm_clicked()
{
    std::string name = ui->Name->text().toStdString();

    if (facade->registerReleaseType(name)) {
        on_Clean_clicked();
        ui->TypeList->insertRow(ui->TypeList->rowCount());
        ui->TypeList->setItem(ui->TypeList->rowCount() - 1, 0, new QTableWidgetItem("     " + QString::fromStdString(name)));
        emit build();
    } else {
        ui->Erro->setText("Nome invalido!");
    }
    tableBuilder();
}

void WNewReleaseType::tableBuilder()
{
    ui->TypeList->setRowCount(0);
    list<std::string> * names = facade->releaseTypesNames();
    for (list<string>::iterator it = names->begin(); it != names->end(); ++it) {
        ui->TypeList->insertRow(ui->TypeList->rowCount());
        ui->TypeList->setItem(ui->TypeList->rowCount() - 1, 0, new QTableWidgetItem("     " + QString::fromStdString(*it)));
    }
    delete names;
}
