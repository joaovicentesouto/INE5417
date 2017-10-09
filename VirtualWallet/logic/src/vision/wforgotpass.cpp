#include "wforgotpass.h"
#include "ui_wforgotpass.h"

WForgotPass::WForgotPass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WForgotPass)
{
    ui->setupUi(this);
    ui->Code->setPlaceholderText("Codigo");
    ui->Name->setPlaceholderText("Nome");
    ui->NewPass->setPlaceholderText("Nova Senha");
    ui->PassConfirm->setPlaceholderText("Confirme a Senha");
    ui->PassConfirm->setEchoMode(QLineEdit::Password);
    ui->NewPass->setEchoMode(QLineEdit::Password);
}

WForgotPass::~WForgotPass()
{
    delete ui;
}

void WForgotPass::on_Clean_clicked()
{
    ui->Name->setText("");
    ui->Code->setText("");
    ui->NewPass->setText("");
    ui->PassConfirm->setText("");
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
