#include "wnewuser.h"
#include "ui_wnewuser.h"

WNewUser::WNewUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WNewUser)
{
    ui->setupUi(this);
    ui->Name->setPlaceholderText("Nome");
    ui->Password->setPlaceholderText("Senha");
    ui->PassConfirm->setPlaceholderText("Cofirma Senha");
    ui->Code->setPlaceholderText("Codigo");
    ui->Password->setEchoMode(QLineEdit::Password);
    ui->PassConfirm->setEchoMode(QLineEdit::Password);
}

WNewUser::~WNewUser()
{
    delete ui;
}

void WNewUser::setFacade(Facade * _facade) {
    facade = _facade;
}

void WNewUser::on_Clean_clicked()
{
    ui->Name->setText("");
    ui->Code->setText("");
    ui->Password->setText("");
    ui->PassConfirm->setText("");
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
