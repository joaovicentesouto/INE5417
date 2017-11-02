#include "wreport.h"
#include "ui_wreport.h"

WReport::WReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WReport)
{
    ui->setupUi(this);

    QStringList titles;
    titles << "Conta";

    ui->AccTable->setColumnCount(1);
    ui->AccTable->setColumnWidth(0, 441);
    ui->AccTable->setHorizontalHeaderLabels(titles);


    titles.clear();
    titles << "Tipos de Lancamento";
    ui->TypesTable->setColumnCount(1);
    ui->TypesTable->setColumnWidth(0, 441);
    ui->TypesTable->setHorizontalHeaderLabels(titles);
}

WReport::~WReport()
{
    delete ui;
}
