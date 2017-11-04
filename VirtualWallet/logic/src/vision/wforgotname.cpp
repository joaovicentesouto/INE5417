#include "wforgotname.h"
#include "ui_wforgotname.h"

WForgotName::WForgotName(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WForgotName)
{
    ui->setupUi(this);
    ui->Code->setPlaceholderText("Codigo");
    ui->Password->setPlaceholderText("Senha");
    ui->NewName->setPlaceholderText("Novo Nome");
    ui->NameConfirm->setPlaceholderText("Confirme o Nome");
    ui->Password->setEchoMode(QLineEdit::Password);
}

WForgotName::~WForgotName()
{
    delete ui;
}

void WForgotName::setFacade(Facade & _facade) {
    facade = &_facade;
}

void WForgotName::on_Clean_clicked()
{
    ui->Code->setText("");
    ui->Password->setText("");
    ui->NewName->setText("");
    ui->NameConfirm->setText("");
    ui->Msg->setText("");
}

void WForgotName::on_Confirm_clicked()
{
    std::string code = ui->Code->text().toStdString();
    std::string password = ui->Password->text().toStdString();
    std::string newName = ui->NewName->text().toStdString();
    std::string confirm = ui->NameConfirm->text().toStdString();
    on_Clean_clicked();
    if (facade->refreshName(code, password, newName, confirm)) {
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
