#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    facade("Nome", "Senha")
{
    ui->setupUi(this);
    ui->Menu->hide();
    ui->MenuWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CleanButton_clicked()
{
    name = false;
    password = false;
    ui->LoginName->setText("Nome");
    ui->LoginPassword->setText("Senha");
    ui->LoginName->setStyleSheet("color: #565656; border: none;");
    ui->LoginPassword->setStyleSheet("color: #565656; border: none;");
    ui->LoginErrorMessage->setText("");
}

void MainWindow::on_ConfirmButton_clicked()
{
    std::string name = ui->LoginName->text().toStdString();
    std::string password = ui->LoginPassword->text().toStdString();
    if (facade.login(name, password)) {
        configureMenu();
    } else {
        on_CleanButton_clicked();
        ui->LoginErrorMessage->setText("Usuario ou Senha Invalidos!");
    }
}

void MainWindow::on_LoginName_textEdited(const QString &arg1)
{
    if (!name) {
        QString last(arg1.toStdString().back());
        ui->LoginName->setText(last);
    }
    name = true;
    ui->LoginName->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void MainWindow::on_LoginPassword_textEdited(const QString &arg1)
{
    if (!password) {
        QString last(arg1.toStdString().back());
        ui->LoginPassword->setText(last);
    }
    password = true;
    ui->LoginPassword->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void MainWindow::on_MenuButton_clicked()
{
    if (ui->MenuWidget->isHidden()) {
        ui->MenuWidget->show();
    } else {
        ui->MenuWidget->hide();
    }
}

void MainWindow::configureMenu()
{
    std::string accauntsBalance(24, '\0');
    std::snprintf(&accauntsBalance[0], 24, "%.2f", facade.accountsBalance());

    ui->Menu->show();
    ui->MenuButton->setIcon(QIcon("../Images/menubutton.png"));
    ui->MenuUser->setText(QString::fromStdString(facade.getUserName()));
    ui->MenuTotal->setText(QString::fromStdString("Total R$ " + accauntsBalance));
    ui->Stack->setCurrentWidget(ui->Home);
}
