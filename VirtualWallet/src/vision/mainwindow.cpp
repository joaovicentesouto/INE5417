#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdio.h>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    facade("Usuario", "123456")
{
    ui->setupUi(this);
    ui->Menu->hide();
    ui->WMenu->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Limpar_clicked()
{
    nome = false;
    senha = false;
    ui->Nome->setText("Nome");
    ui->Senha->setText("Senha");
    ui->Nome->setStyleSheet("color: #565656; border: none;");
    ui->Senha->setStyleSheet("color: #565656; border: none;");
    ui->MsgErro->setText("");
}

void MainWindow::on_Confirmar_clicked()
{
    QString name = ui->Nome->text();
    QString password = ui->Senha->text();
    if (facade.login(name.toStdString(), password.toStdString())) {
        ui->Menu->show();
        ui->WMenu->hide();
        ui->MUser->setText(name);
        ui->stack->setCurrentWidget(ui->home);
    } else {
        on_Limpar_clicked();
        ui->MsgErro->setText("Usuario ou Senha Invalidos!");
        ui->MsgErro->setStyleSheet("color: rgb(250, 0, 0); border: none;");
    }
}

void MainWindow::on_Nome_textEdited(const QString &arg1)
{
    if (!nome) {
        QString last(arg1.toStdString().back());
        ui->Nome->setText(last);
    }
    nome = true;
    ui->Nome->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void MainWindow::on_Senha_textEdited(const QString &arg1)
{
    if (!senha) {
        QString last(arg1.toStdString().back());
        ui->Senha->setText(last);
    }
    senha = true;
    ui->Senha->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void MainWindow::on_MenuButton_clicked()
{
    if (ui->WMenu->isHidden()) {
        ui->WMenu->show();
    } else {
        ui->WMenu->hide();
    }
}
