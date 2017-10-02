#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    //facade("Nome", "Senha", "Codigo")
    facade("", "", "")
{
    ui->setupUi(this);
    ui->Menu->hide();
    ui->MenuWidget->hide();

    if(facade.getUserName() == "")
        ui->Stack->setCurrentWidget(ui->NewUser);

    ui->NewWallet->setFacade(facade);
    ui->LoginCenterWidget->setFacade(facade);
    ui->ForgotPassCenter->setFacade(facade);
    ui->ForgotNameCenter->setFacade(facade);
    ui->NewUserCenter->setFacade(facade);
    ui->NewBankAccount->setFacade(facade);
    ui->NewReleaseType->setFacade(facade);
    ui->NewRelease->setFacade(facade);
    ui->Home->setFacade(facade);

    // Connects

    connect(ui->NewWallet, SIGNAL(goToHome()), this, SLOT(goToHome()));
    connect(ui->NewBankAccount, SIGNAL(goToHome()), this, SLOT(goToHome()));
    connect(ui->NewReleaseType, SIGNAL(goToHome()), this, SLOT(goToHome()));
    connect(ui->NewRelease, SIGNAL(goToHome()), this, SLOT(goToHome()));

    connect(ui->LoginCenterWidget, SIGNAL(configureMenu()), this, SLOT(configureMenu()));
    connect(ui->LoginCenterWidget, SIGNAL(changeStack(int)), this, SLOT(changeStack(int)));
    connect(ui->LoginCenterWidget, SIGNAL(cleanForgotName()), ui->ForgotNameCenter, SLOT(on_Clean_clicked()));
    connect(ui->LoginCenterWidget, SIGNAL(cleanForgotPassword()), ui->ForgotPassCenter, SLOT(on_Clean_clicked()));

    connect(ui->ForgotPassCenter, SIGNAL(changeStack(int)), this, SLOT(changeStack(int)));
    connect(ui->ForgotPassCenter, SIGNAL(cleanLogin()), ui->LoginCenterWidget, SLOT(on_CleanButton_clicked()));

    connect(ui->ForgotNameCenter, SIGNAL(changeStack(int)), this, SLOT(changeStack(int)));
    connect(ui->ForgotNameCenter, SIGNAL(cleanLogin()), ui->LoginCenterWidget, SLOT(on_CleanButton_clicked()));

    connect(ui->NewUserCenter, SIGNAL(changeStack(int)), this, SLOT(changeStack(int)));
    connect(ui->NewUserCenter, SIGNAL(userRegistred()), ui->LoginCenterWidget, SLOT(changeToNewUserMsg()));

    connect(this, SIGNAL(update()), ui->NewRelease, SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MenuButton_clicked()
{
    if (ui->MenuWidget->isHidden()) {
        ui->MenuWidget->show();
    } else {
        ui->MenuWidget->hide();
    }
}

void MainWindow::configureMenu()
{
    std::string accauntsBalance(24, '\0');
    std::snprintf(&accauntsBalance[0], 24, "%.2f", facade.accountsBalance());

    ui->Menu->show();
    ui->MenuButton->setIcon(QIcon("../Images/menubutton.png"));
    ui->MenuUser->setText(QString::fromStdString(facade.getUserName()));
    ui->MenuTotal->setText(QString::fromStdString("Total R$ " + accauntsBalance));
    ui->Stack->setCurrentWidget(ui->Home);
    ui->MenuWidget->hide();

    emit update();
}

void MainWindow::on_MenuNewReleaseType_clicked()
{
    ui->Stack->setCurrentWidget(ui->NewReleaseType);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuNewRelease_clicked()
{
    ui->Stack->setCurrentWidget(ui->NewRelease);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuReport_clicked()
{
    ui->Stack->setCurrentWidget(ui->Report);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuBankAccounts_clicked()
{
    ui->Stack->setCurrentWidget(ui->NewBankAccount);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuWallets_clicked()
{
    ui->Stack->setCurrentWidget(ui->NewWallet);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuUserDatas_clicked()
{
    ui->Stack->setCurrentWidget(ui->UserData);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuAbout_clicked()
{
    ui->Stack->setCurrentWidget(ui->AppAbout);
    ui->MenuWidget->hide();
}

void MainWindow::on_MenuOut_clicked()
{
    ui->Menu->hide();
    ui->MenuWidget->hide();
    ui->Stack->setCurrentWidget(ui->Login);

}

void MainWindow::goToHome()
{
    emit update();
    ui->Stack->setCurrentWidget(ui->Home);
}

void MainWindow::changeStack(int _stack)
{
    switch(_stack) {
        case 1: ui->Stack->setCurrentWidget(ui->ForgotPassword); break;
        case 2: ui->Stack->setCurrentWidget(ui->ForgotName); break;
        case 3: ui->Stack->setCurrentWidget(ui->Login); break;
    }
}

void MainWindow::on_MenuHome_clicked()
{
    goToHome();
    ui->MenuWidget->hide();
}
