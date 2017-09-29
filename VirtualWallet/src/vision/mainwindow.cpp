#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    facade("Usuario", "123456")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Limpar_clicked()
{
    ui->Nome->setText("Nome");
    ui->Senha->setText("Senha");
}

void MainWindow::on_Confirmar_clicked()
{
    std::string name = ui->Nome->text().toStdString();
    std::string password = ui->Nome->text().toStdString();


}
