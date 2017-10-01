#include "wnewwallet.h"
#include "ui_wnewwallet.h"
#include <iostream>

WNewWallet::WNewWallet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WNewWallet)
{
    ui->setupUi(this);
}

WNewWallet::~WNewWallet()
{
    delete ui;
}

void WNewWallet::setFacade(Facade &_facade)
{
    facade = &_facade;
}

void WNewWallet::on_Name_textEdited(const QString &arg1)
{
    if (!name) {
        QString last(arg1.toStdString().back());
        ui->Name->setText(last);
        name = true;
    }

    ui->Name->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WNewWallet::on_Clean_clicked()
{
    ui->Name->setText("Nome");
    ui->Name->setStyleSheet("color: #565656; border: none;");
    ui->Balance->setValue(0.0);
    ui->Balance->setStyleSheet("color: #565656; border: none;");
    ui->Erro->setText("");
    name = balance = false;
}

void WNewWallet::on_Balance_valueChanged(const QString &arg1)
{
    if (!balance) {
        QString last(arg1.toStdString().back());
        ui->Balance->setValue(last.toInt()*1.0);
    }
    balance = true;
    ui->Balance->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WNewWallet::on_Confirm_clicked()
{
    if (!name) {
        return ;
    }

    std::string finalName = ui->Name->text().toStdString();
    double _balance = ui->Balance->value();

    if (finalName != "") {
        if (facade->registerWallet(finalName, _balance)) {
            on_Clean_clicked();
            emit goToHome();
        } else {
            ui->Erro->setText("Nome invalido!");
        }
    } else {
        ui->Erro->setText("Nome invalido!");
    }
}
