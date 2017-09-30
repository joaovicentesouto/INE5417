#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    facade("Nome", "Senha", "Codigo"),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Menu->hide();
    ui->MenuWidget->hide();
    ui->NewWallet->setFacade(facade);

    connect(ui->NewWallet, SIGNAL(goToHome()), this, SLOT(goToHome()));
    ui->AccountAmount->setText(QString::number(facade.accountsAmount()));
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

void MainWindow::on_MenuNewReleaseType_clicked()
{
    ui->Stack->setCurrentWidget(ui->NewTypeRelease);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuNewRelease_clicked()
{
    ui->Stack->setCurrentWidget(ui->NewRelease);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuReport_clicked()
{
    ui->Stack->setCurrentWidget(ui->Report);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuBankAccounts_clicked()
{
    ui->Stack->setCurrentWidget(ui->NewBankAccount);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuWallets_clicked()
{
    ui->Stack->setCurrentWidget(ui->NewWallet);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuUserDatas_clicked()
{
    ui->Stack->setCurrentWidget(ui->UserData);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuAbout_clicked()
{
    ui->Stack->setCurrentWidget(ui->AppAbout);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuOut_clicked()
{
    ui->Menu->hide();
    ui->MenuWidget->hide();
    ui->Stack->setCurrentWidget(ui->Login);

}

void MainWindow::on_LoginPasswordForgot_clicked()
{
    on_ForgotPassCleanButton_clicked();
    ui->Stack->setCurrentWidget(ui->ForgotPassword);
}

void MainWindow::on_ForgotPassCleanButton_clicked()
{
    name = false;
    code = false;
    confirm = false;
    password = false;
    ui->ForgotPassName->setText("Nome");
    ui->ForgotPassCode->setText("Codigo");
    ui->ForgotPassNewPass->setText("Nova Senha");
    ui->ForgotPassConfirm->setText("Confirme a Nova Senha");
    ui->ForgotPassName->setStyleSheet("color: #565656; border: none;");
    ui->ForgotPassCode->setStyleSheet("color: #565656; border: none;");
    ui->ForgotPassNewPass->setStyleSheet("color: #565656; border: none;");
    ui->ForgotPassConfirm->setStyleSheet("color: #565656; border: none;");
    ui->ForgotPassErrorMsg->setText("");
}

void MainWindow::on_ForgotPassName_textEdited(const QString &arg1)
{
    if (!name) {
        QString last(arg1.toStdString().back());
        ui->ForgotPassName->setText(last);
    }
    name = true;
    ui->ForgotPassName->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void MainWindow::on_ForgotPassCode_textEdited(const QString &arg1)
{
    if (!code) {
        QString last(arg1.toStdString().back());
        ui->ForgotPassCode->setText(last);
    }
    code = true;
    ui->ForgotPassCode->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void MainWindow::on_ForgotPassNewPass_textEdited(const QString &arg1)
{
    if (!password) {
        QString last(arg1.toStdString().back());
        ui->ForgotPassNewPass->setText(last);
    }
    password = true;
    ui->ForgotPassNewPass->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void MainWindow::on_ForgotPassConfirm_textEdited(const QString &arg1)
{
    if (!confirm) {
        QString last(arg1.toStdString().back());
        ui->ForgotPassConfirm->setText(last);
    }
    confirm = true;
    ui->ForgotPassConfirm->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void MainWindow::on_ForgotPassBack_clicked()
{
    on_ForgotPassCleanButton_clicked();
    on_CleanButton_clicked();
    ui->Stack->setCurrentWidget(ui->Login);
}

void MainWindow::on_ForgotPassConfirmButton_clicked()
{
    std::string name = ui->ForgotPassName->text().toStdString();
    std::string code = ui->ForgotPassCode->text().toStdString();
    std::string newpass = ui->ForgotPassNewPass->text().toStdString();
    std::string confirm = ui->ForgotPassConfirm->text().toStdString();
    if (facade.verifyNewPass(name, code, newpass, confirm)) {
        facade.refreshPass(newpass);
        on_ForgotPassCleanButton_clicked();
        ui->ForgotPassErrorMsg->setStyleSheet("color: #00c10d; border: none;");
        ui->ForgotPassErrorMsg->setText("Alteraçao Realizada com Sucesso!");
    } else {
        on_ForgotPassCleanButton_clicked();
        ui->ForgotPassErrorMsg->setStyleSheet("color: rgb(250, 0, 0); border: none;");
        ui->ForgotPassErrorMsg->setText("Dados Invalidos!");
    }
}

void MainWindow::on_ForgotNameCode_textEdited(const QString &arg1)
{
    if (!code) {
        QString last(arg1.toStdString().back());
        ui->ForgotNameCode->setText(last);
    }
    code = true;
    ui->ForgotNameCode->setStyleSheet("color: rgb(0, 0, 0); border: none;");

}

void MainWindow::on_ForgotNamePassword_textEdited(const QString &arg1)
{
    if (!password) {
        QString last(arg1.toStdString().back());
        ui->ForgotNamePassword->setText(last);
    }
    password = true;
    ui->ForgotNamePassword->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void MainWindow::on_ForgotNameNewName_textEdited(const QString &arg1)
{
    if (!name) {
        QString last(arg1.toStdString().back());
        ui->ForgotNameNewName->setText(last);
    }
    name = true;
    ui->ForgotNameNewName->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void MainWindow::on_ForgotNameConfirm_textEdited(const QString &arg1)
{
    if (!confirm) {
        QString last(arg1.toStdString().back());
        ui->ForgotNameConfirm->setText(last);
    }
    confirm = true;
    ui->ForgotNameConfirm->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void MainWindow::on_ForgotNameCleanButton_clicked()
{
    name = false;
    code = false;
    confirm = false;
    password = false;
    ui->ForgotNameCode->setText("Codigo");
    ui->ForgotNamePassword->setText("Senha");
    ui->ForgotNameNewName->setText("Novo Nome");
    ui->ForgotNameConfirm->setText("Confirme o Novo Nome");
    ui->ForgotNameCode->setStyleSheet("color: #565656; border: none;");
    ui->ForgotNamePassword->setStyleSheet("color: #565656; border: none;");
    ui->ForgotNameNewName->setStyleSheet("color: #565656; border: none;");
    ui->ForgotNameConfirm->setStyleSheet("color: #565656; border: none;");
    ui->ForgotNameErrorMsg->setText("");
}

void MainWindow::on_LoginNameForgot_clicked()
{
    ui->Stack->setCurrentWidget(ui->ForgotName);
}

void MainWindow::on_ForgotNameBack_clicked()
{
    on_ForgotNameCleanButton_clicked();
    on_CleanButton_clicked();
    ui->Stack->setCurrentWidget(ui->Login);
}

void MainWindow::on_ForgotNameConfirmButton_clicked()
{
    std::string code = ui->ForgotNameCode->text().toStdString();
    std::string password = ui->ForgotNamePassword->text().toStdString();
    std::string newName = ui->ForgotNameNewName->text().toStdString();
    std::string confirm = ui->ForgotNameConfirm->text().toStdString();
    if (facade.verifyNewName(code, password, newName, confirm)) {
        facade.refreshName(newName);
        on_ForgotNameCleanButton_clicked();
        ui->ForgotNameErrorMsg->setStyleSheet("color: #00c10d; border: none;");
        ui->ForgotNameErrorMsg->setText("Alteraçao Realizada com Sucesso!");
    } else {
        on_ForgotNameCleanButton_clicked();
        ui->ForgotNameErrorMsg->setStyleSheet("color: rgb(250, 0, 0); border: none;");
        ui->ForgotNameErrorMsg->setText("Dados Invalidos!");
    }
}

void MainWindow::goToHome()
{
    ui->Stack->setCurrentWidget(ui->Home);
    ui->AccountAmount->setText(QString::number(facade.accountsAmount()));
}
