#include "wreport.h"
#include "ui_wreport.h"

#include <iostream>

WReport::WReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WReport)
{
    ui->setupUi(this);

    QStringList titles;
    titles << "Conta";

    ui->AccTable->setColumnCount(1);
    ui->AccTable->setColumnWidth(0, 441);
    ui->AccTable->setHorizontalHeaderLabels(titles);
    ui->AccTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    titles.clear();
    titles << "Tipo de Lancamento";
    ui->TypesTable->setColumnCount(1);
    ui->TypesTable->setColumnWidth(0, 441);
    ui->TypesTable->setHorizontalHeaderLabels(titles);
    ui->TypesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    titles.clear();
    titles << "Tipo de Pagamento";
    ui->PayTable->setColumnCount(1);
    ui->PayTable->setColumnWidth(0, 441);
    ui->PayTable->setHorizontalHeaderLabels(titles);
    ui->PayTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->In->setAutoExclusive(false);
    ui->Out->setAutoExclusive(false);
    ui->DateEdit_1->setDate(QDate::currentDate());
    ui->DateEdit_2->setDate(QDate::currentDate());
}

WReport::~WReport()
{
    delete ui;
}

void WReport::setFacade(Facade &_facade)
{
    facade = &_facade;
}

void WReport::on_ValueBox_1_valueChanged(double arg1)
{
    if (ui->ValueBox_2->value() <= arg1)
        ui->ValueBox_2->setValue(arg1);
    ui->ValueBox_1->setValue(arg1);
}

void WReport::on_ValueBox_2_valueChanged(double arg1)
{
    if (ui->ValueBox_1->value() >= arg1)
        ui->ValueBox_1->setValue(arg1);
    ui->ValueBox_2->setValue(arg1);
}

void WReport::tableBuilder()
{
    // Accounts
    ui->AccTable->setRowCount(0);
    list<std::string> * names = facade->accountsNames();

    for (list<string>::iterator i = names->begin(); i != names->end(); ++i) {
        ui->AccTable->insertRow(ui->AccTable->rowCount());
        ui->AccTable->setItem(ui->AccTable->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(*i)));
    }
    delete names;

    ui->TypesTable->setRowCount(0);
    names = facade->releaseTypesNames();
    for (list<string>::iterator it = names->begin(); it != names->end(); ++it) {
        ui->TypesTable->insertRow(ui->TypesTable->rowCount());
        ui->TypesTable->setItem(ui->TypesTable->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(*it)));
    }
    delete names;

    ui->PayTable->setRowCount(0);
    names = facade->paymentTypesNames();
    for (list<string>::iterator it = names->begin(); it != names->end(); ++it) {
        ui->PayTable->insertRow(ui->PayTable->rowCount());
        ui->PayTable->setItem(ui->PayTable->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(*it)));
    }
    delete names;

    on_Clean_clicked();
}

void WReport::on_AccTable_clicked(const QModelIndex &index)
{
    auto item = ui->AccTable->item(index.row(), index.column());
    QColor c = item->background().color();

    if (c == QColor("#a3f48a")) {
        accounts.remove(item->text().toStdString());
        item->setBackground(QColor("#ffffff"));
    } else {
        accounts.push_back(item->text().toStdString());
        item->setBackground(QColor("#a3f48a"));
    }

    ui->AccTable->setCurrentCell(-1,-1);
    ui->AccTable->clearSelection();

}

void WReport::on_TypesTable_clicked(const QModelIndex &index)
{
    auto item = ui->TypesTable->item(index.row(), index.column());
    QColor c = item->background().color();

    if (c == QColor("#a3f48a")) {
        typesReleases.remove(item->text().toStdString());
        item->setBackground(QColor("#ffffff"));
    } else {
        typesReleases.push_back(item->text().toStdString());
        item->setBackground(QColor("#a3f48a"));
    }

    ui->TypesTable->setCurrentCell(-1,-1);
    ui->TypesTable->clearSelection();
}

void WReport::on_PayTable_clicked(const QModelIndex &index)
{
    auto item = ui->PayTable->item(index.row(), index.column());
    QColor c = item->background().color();

    if (c == QColor("#a3f48a")) {
        typesPayments.remove(item->text().toStdString());
        item->setBackground(QColor("#ffffff"));
    } else {
        typesPayments.push_back(item->text().toStdString());
        item->setBackground(QColor("#a3f48a"));
    }

    ui->PayTable->setCurrentCell(-1,-1);
    ui->PayTable->clearSelection();
}

void WReport::on_AllAccs_clicked()
{
    if (ui->AccTable->rowCount() == accounts.size()) {
        accounts.clear();
        for (int i = 0; i < ui->AccTable->rowCount(); i++)
            ui->AccTable->item(i, 0)->setBackground(QColor("#ffffff"));
    } else {
        accounts.clear();
        for (int i = 0; i < ui->AccTable->rowCount(); i++) {
            ui->AccTable->item(i, 0)->setBackground(QColor("#a3f48a"));
            accounts.push_back(ui->AccTable->item(i, 0)->text().toStdString());
        }
    }
}

void WReport::on_AllTypes_clicked()
{
    if (ui->TypesTable->rowCount() == typesReleases.size()) {
        typesReleases.clear();
        for (int i = 0; i < ui->TypesTable->rowCount(); i++)
            ui->TypesTable->item(i, 0)->setBackground(QColor("#ffffff"));
    } else {
        typesReleases.clear();
        for (int i = 0; i < ui->TypesTable->rowCount(); i++) {
            ui->TypesTable->item(i, 0)->setBackground(QColor("#a3f48a"));
            typesReleases.push_back(ui->TypesTable->item(i, 0)->text().toStdString());
        }
    }
}

void WReport::on_AllPay_clicked()
{
    if (ui->PayTable->rowCount() == typesPayments.size()) {
        typesPayments.clear();
        for (int i = 0; i < ui->PayTable->rowCount(); i++)
            ui->PayTable->item(i, 0)->setBackground(QColor("#ffffff"));
    } else {
        typesPayments.clear();
        for (int i = 0; i < ui->PayTable->rowCount(); i++) {
            ui->PayTable->item(i, 0)->setBackground(QColor("#a3f48a"));
            typesPayments.push_back(ui->PayTable->item(i, 0)->text().toStdString());
        }
    }
}

void WReport::on_Clean_clicked()
{
    accounts.clear();
    typesReleases.clear();
    typesPayments.clear();

    for (int i = 0; i < ui->AccTable->rowCount(); i++)
        ui->AccTable->item(i, 0)->setBackground(QColor("#ffffff"));

    for (int i = 0; i < ui->TypesTable->rowCount(); i++)
        ui->TypesTable->item(i, 0)->setBackground(QColor("#ffffff"));

    for (int i = 0; i < ui->PayTable->rowCount(); i++)
        ui->PayTable->item(i, 0)->setBackground(QColor("#ffffff"));

    ui->In->setChecked(false);
    ui->Out->setChecked(false);
    ui->ValueBox_1->setValue(0);
    ui->ValueBox_2->setValue(0);
    ui->DateEdit_1->setDate(QDate::currentDate());
    ui->DateEdit_2->setDate(QDate::currentDate());
}

void WReport::on_DateEdit_1_dateChanged(const QDate &date)
{
    if (ui->DateEdit_2->date() <= date)
        ui->DateEdit_2->setDate(date);
    ui->DateEdit_1->setDate(date);
}

void WReport::on_DateEdit_2_dateChanged(const QDate &date)
{
    if (ui->DateEdit_1->date() >= date)
        ui->DateEdit_1->setDate(date);
    ui->DateEdit_2->setDate(date);
}
