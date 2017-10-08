#include "whome.h"
#include "ui_whome.h"

WHome::WHome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WHome)
{
    ui->setupUi(this);

    QStringList titles;
    titles << "Conta" << "Montante";

    ui->Table->setColumnCount(2);
    ui->Table->setColumnWidth(0, 228);
    ui->Table->setColumnWidth(1, 228);
    ui->Table->setHorizontalHeaderLabels(titles);
}

void WHome::setFacade(Facade &_facade)
{
    facade = &_facade;
}

WHome::~WHome()
{
    delete ui;
}

void WHome::tableBuilder()
{
    ui->Table->setRowCount(0);
    list<std::string> * names = facade->accountsNames();
    list<double> * balances = facade->accountsValues();
    list<double>::iterator j = balances->begin();
    for (list<string>::iterator i = names->begin(); i != names->end(); ++i) {
        ui->Table->insertRow(ui->Table->rowCount());
        ui->Table->setItem(ui->Table->rowCount() - 1, 0, new QTableWidgetItem("     " + QString::fromStdString(*i)));
        ui->Table->setItem(ui->Table->rowCount() - 1, 1, new QTableWidgetItem("     R$ " + QString::number(*j)));
        ++j;
    }
    delete names;
    delete balances;
}
