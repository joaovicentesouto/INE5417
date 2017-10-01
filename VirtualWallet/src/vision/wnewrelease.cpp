#include "wnewrelease.h"
#include "ui_wnewrelease.h"

WNewRelease::WNewRelease(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WNewRelease)
{
    ui->setupUi(this);
    ui->DescRelease->setPlaceholderText("Descricao");
}

WNewRelease::~WNewRelease()
{
    delete ui;
}

void WNewRelease::setFacade(Facade &_facade) {
    facade = &_facade;
}

void WNewRelease::update() {

    ui->Accounts->clear();
    ui->ReleaseType->clear();
    ui->PaymentType->clear();

    ui->Accounts->addItem("Conta");
    ui->ReleaseType->addItem("Tipo de Lancamento");
    ui->PaymentType->addItem("Tipo de Pagamento");

    list<std::string> * names = facade->accountsNames();
    for (list<string>::iterator it = names->begin(); it != names->end(); ++it) {
        ui->Accounts->addItem(QString::fromStdString(*it));
    }
    delete names;

    names = facade->releaseTypesNames();
    for (list<string>::iterator it = names->begin(); it != names->end(); ++it) {
        ui->ReleaseType->addItem(QString::fromStdString(*it));
    }
    delete names;

    names = facade->paymentTypesNames();
    for (list<string>::iterator it = names->begin(); it != names->end(); ++it) {
        ui->PaymentType->addItem(QString::fromStdString(*it));
    }
    delete names;

    ui->DateEdit->setDate(QDate::currentDate());
}
