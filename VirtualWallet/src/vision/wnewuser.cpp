#include "wnewuser.h"
#include "ui_wnewuser.h"

WNewUser::WNewUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WNewUser)
{
    ui->setupUi(this);
}

WNewUser::~WNewUser()
{
    delete ui;
}

void WNewUser::on_Name_textEdited(const QString &arg1)
{
    if (!name) {
        QString last(arg1.toStdString().back());
        ui->Name->setText(last);
    }
    name = true;
    ui->Name->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WNewUser::on_Code_textEdited(const QString &arg1)
{
    if (!code) {
        QString last(arg1.toStdString().back());
        ui->Code->setText(last);
    }
    code = true;
    ui->Code->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WNewUser::on_Password_textEdited(const QString &arg1)
{
    if (!password) {
        QString last(arg1.toStdString().back());
        ui->Password->setText(last);
    }
    password = true;
    ui->Password->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WNewUser::on_PassConfirm_textEdited(const QString &arg1)
{
    if (!confirm) {
        QString last(arg1.toStdString().back());
        ui->PassConfirm->setText(last);
    }
    confirm = true;
    ui->PassConfirm->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void WNewUser::on_Clean_clicked()
{
    name = false;
    code = false;
    confirm = false;
    password = false;
    ui->Name->setText("Nome");
    ui->Code->setText("Codigo");
    ui->Password->setText("Senha");
    ui->PassConfirm->setText("Confirme a Senha");
    ui->Name->setStyleSheet("color: #565656; border: none;");
    ui->Code->setStyleSheet("color: #565656; border: none;");
    ui->Password->setStyleSheet("color: #565656; border: none;");
    ui->PassConfirm->setStyleSheet("color: #565656; border: none;");
    ui->Msg->setText("");
}

void WNewUser::on_Confirm_clicked()
{
    std::string name = ui->Name->text().toStdString();
    std::string code = ui->Code->text().toStdString();
    std::string password = ui->Password->text().toStdString();
    std::string confirm = ui->PassConfirm->text().toStdString();
    on_Clean_clicked();
    if (facade->registerUser(name, code, password, confirm)) {
        emit userRegistred();
        emit changeStack(3);
    } else {
        ui->Msg->setStyleSheet("color: rgb(250, 0, 0); border: none;");
        ui->Msg->setText("Dados Invalidos!");
    }
}

void WNewUser::setFacade(Facade & _facade) {
    facade = &_facade;
}
