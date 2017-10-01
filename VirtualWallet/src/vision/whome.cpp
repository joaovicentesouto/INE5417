#include "whome.h"
#include "ui_whome.h"

WHome::WHome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WHome)
{
    ui->setupUi(this);
}

void WHome::setFacade(Facade &_facade)
{
    facade = &_facade;
}

WHome::~WHome()
{
    delete ui;
}

void WHome::update()
{
    list<Account*> accts = facade->userAccounts();
    while (!accts.empty()) {
        WHome *acc = new WHome(dynamic_cast<QWidget*>(ui->Accounts));
        ui->Accounts->setWidget(acc);
        //accts.pop_front();
    }
}
