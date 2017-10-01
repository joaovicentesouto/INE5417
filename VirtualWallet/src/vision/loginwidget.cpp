#include "loginwidget.h"
#include "ui_loginwidget.h"

loginwidget::loginwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginwidget)
{
    ui->setupUi(this);
}

loginwidget::~loginwidget()
{
    delete ui;
}

void loginwidget::on_LoginName_textEdited(const QString &arg1)
{
    if (!name) {
        QString last(arg1.toStdString().back());
        ui->LoginName->setText(last);
    }
    name = true;
    ui->LoginName->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void loginwidget::on_LoginPassword_textEdited(const QString &arg1)
{
    if (!password) {
        QString last(arg1.toStdString().back());
        ui->LoginPassword->setText(last);
    }
    password = true;
    ui->LoginPassword->setStyleSheet("color: rgb(0, 0, 0); border: none;");
}

void loginwidget::on_CleanButton_clicked()
{
    name = false;
    password = false;
    ui->LoginName->setText("Nome");
    ui->LoginPassword->setText("Senha");
    ui->LoginName->setStyleSheet("color: #565656; border: none;");
    ui->LoginPassword->setStyleSheet("color: #565656; border: none;");
    ui->LoginMsg->setText("");
}

void loginwidget::on_ConfirmButton_clicked()
{
    std::string name = ui->LoginName->text().toStdString();
    std::string password = ui->LoginPassword->text().toStdString();
    on_CleanButton_clicked();
    if (facade->login(name, password)) {
        emit configureMenu();
    } else {
        ui->LoginMsg->setStyleSheet("color: rgb(250, 0, 0); border: none;");
        ui->LoginMsg->setText("Usuario ou Senha Invalidos!");
    }
}

void loginwidget::on_LoginPasswordForgot_clicked()
{
    emit cleanForgotPassword();
    emit changeStack(1);
}

void loginwidget::on_LoginNameForgot_clicked()
{
    emit cleanForgotName();
    emit changeStack(2);
}

void loginwidget::setFacade(Facade & _facade) {
    facade = &_facade;
}

void loginwidget::changeToNewUserMsg()
{
    on_CleanButton_clicked();
    ui->LoginMsg->setStyleSheet("color: #00c10d; border: none;");
    ui->LoginMsg->setText("Usuario Criado com Sucesso!");
}
