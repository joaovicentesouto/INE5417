#include "wnewreleasetype.h"
#include "ui_wnewreleasetype.h"

WNewReleaseType::WNewReleaseType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WNewReleaseType)
{
    ui->setupUi(this);
    ui->Name->setPlaceholderText("Nome");
}

WNewReleaseType::~WNewReleaseType()
{
    delete ui;
}

void WNewReleaseType::setFacade(Facade &_facade) {
    facade = &_facade;
}

void WNewReleaseType::on_Clean_clicked()
{
    ui->Name->setText("");
    ui->Erro->setText("");
}

void WNewReleaseType::on_Confirm_clicked()
{
    std::string name = ui->Name->text().toStdString();

    if (facade->registerReleaseType(name)) {
        on_Clean_clicked();
        emit goToHome();
    } else {
        ui->Erro->setText("Nome invalido!");
    }
}
