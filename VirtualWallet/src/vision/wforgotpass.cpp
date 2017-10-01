#include "wforgotpass.h"
#include "ui_wforgotpass.h"

WForgotPass::WForgotPass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WForgotPass)
{
    ui->setupUi(this);
}

WForgotPass::~WForgotPass()
{
    delete ui;
}

void WForgotPass::on_Name_textEdited(const QString &arg1)
{
    if (!name) {
        QString last(arg1.toStdString().back());
        ui->Name->setText(last);
    }
    name = true;
    ui->Name->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WForgotPass::on_Code_textEdited(const QString &arg1)
{
    if (!code) {
        QString last(arg1.toStdString().back());
        ui->Code->setText(last);
    }
    code = true;
    ui->Code->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WForgotPass::on_NewPass_textEdited(const QString &arg1)
{
    if (!password) {
        QString last(arg1.toStdString().back());
        ui->NewPass->setText(last);
    }
    password = true;
    ui->NewPass->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WForgotPass::on_PassConfirm_textEdited(const QString &arg1)
{
    if (!confirm) {
        QString last(arg1.toStdString().back());
        ui->PassConfirm->setText(last);
    }
    confirm = true;
    ui->PassConfirm->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WForgotPass::on_Clean_clicked()
{
    name = false;
    code = false;
    confirm = false;
    password = false;
    ui->Name->setText("Nome");
    ui->Code->setText("Codigo");
    ui->NewPass->setText("Nova Senha");
    ui->PassConfirm->setText("Confirme a Nova Senha");
    ui->Name->setStyleSheet("color: #565656; border: none;");
    ui->Code->setStyleSheet("color: #565656; border: none;");
    ui->NewPass->setStyleSheet("color: #565656; border: none;");
    ui->PassConfirm->setStyleSheet("color: #565656; border: none;");
    ui->Msg->setText("");
}

void WForgotPass::on_Confirm_clicked()
{
    std::string name = ui->Name->text().toStdString();
    std::string code = ui->Code->text().toStdString();
    std::string newpass = ui->NewPass->text().toStdString();
    std::string confirm = ui->PassConfirm->text().toStdString();
    on_Clean_clicked();
    if (facade->verifyNewPass(name, code, newpass, confirm)) {
        facade->refreshPass(newpass);
        ui->Msg->setStyleSheet("color: #00c10d; border: none;");
        ui->Msg->setText("Alteraçao Realizada com Sucesso!");
    } else {
        ui->Msg->setStyleSheet("color: rgb(250, 0, 0); border: none;");
        ui->Msg->setText("Dados Invalidos!");
    }
}

void WForgotPass::on_Back_clicked()
{
    on_Clean_clicked();
    emit cleanLogin();
    emit changeStack(3);
}

void WForgotPass::setFacade(Facade & _facade) {
    facade = &_facade;
}
