#include "wforgotname.h"
#include "ui_wforgotname.h"

WForgotName::WForgotName(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WForgotName)
{
    ui->setupUi(this);
}

WForgotName::~WForgotName()
{
    delete ui;
}

void WForgotName::on_Code_textEdited(const QString &arg1)
{
    if (!code) {
        QString last(arg1.toStdString().back());
        ui->Code->setText(last);
    }
    code = true;
    ui->Code->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WForgotName::on_Password_textEdited(const QString &arg1)
{
    if (!password) {
        QString last(arg1.toStdString().back());
        ui->Password->setText(last);
    }
    password = true;
    ui->Password->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WForgotName::on_NewName_textEdited(const QString &arg1)
{
    if (!name) {
        QString last(arg1.toStdString().back());
        ui->NewName->setText(last);
    }
    name = true;
    ui->NewName->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WForgotName::on_NameConfirm_textEdited(const QString &arg1)
{
    if (!confirm) {
        QString last(arg1.toStdString().back());
        ui->NameConfirm->setText(last);
    }
    confirm = true;
    ui->NameConfirm->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WForgotName::on_Clean_clicked()
{
    name = false;
    code = false;
    confirm = false;
    password = false;
    ui->Code->setText("Codigo");
    ui->Password->setText("Senha");
    ui->NewName->setText("Novo Nome");
    ui->NameConfirm->setText("Confirme o Novo Nome");
    ui->Code->setStyleSheet("color: #565656; border: none;");
    ui->Password->setStyleSheet("color: #565656; border: none;");
    ui->NewName->setStyleSheet("color: #565656; border: none;");
    ui->NameConfirm->setStyleSheet("color: #565656; border: none;");
    ui->Msg->setText("");
}

void WForgotName::on_Confirm_clicked()
{
    std::string code = ui->Code->text().toStdString();
    std::string password = ui->Password->text().toStdString();
    std::string newName = ui->NewName->text().toStdString();
    std::string confirm = ui->NameConfirm->text().toStdString();
    on_Clean_clicked();
    if (facade->verifyNewName(code, password, newName, confirm)) {
        facade->refreshName(newName);
        ui->Msg->setStyleSheet("color: #00c10d; border: none;");
        ui->Msg->setText("Alteraçao Realizada com Sucesso!");
    } else {
        ui->Msg->setStyleSheet("color: rgb(250, 0, 0); border: none;");
        ui->Msg->setText("Dados Invalidos!");
    }
}

void WForgotName::on_Back_clicked()
{
    on_Clean_clicked();
    emit cleanLogin();
    emit changeStack(3);
}

void WForgotName::setFacade(Facade & _facade) {
    facade = &_facade;
}
