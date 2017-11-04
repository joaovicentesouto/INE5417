#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <string>
#include "./src/control/Facade.h"

using namespace project;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void update();

private slots:
    void on_MenuButton_clicked();
    void on_MenuNewReleaseType_clicked();
    void on_MenuNewRelease_clicked();
    void on_MenuReport_clicked();
    void on_MenuBankAccounts_clicked();
    void on_MenuWallets_clicked();
    void on_MenuAbout_clicked();
    void on_MenuOut_clicked();
    void build();
    void changeStack(int _stack);
    void on_MenuHome_clicked();
    void loginExecuted();

private:
    Ui::MainWindow * ui;
    Facade * facade;
};

#endif // MAINWINDOW_H
