#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    Facade facade;
    bool name{false};
    bool code{false};
    bool confirm{false};
    bool password{false};

signals:
    void update();

private slots:
    void on_MenuButton_clicked();

    void on_MenuNewReleaseType_clicked();

    void on_MenuNewRelease_clicked();

    void on_MenuReport_clicked();

    void on_MenuBankAccounts_clicked();

    void on_MenuWallets_clicked();

    void on_MenuUserDatas_clicked();

    void on_MenuAbout_clicked();

    void on_MenuOut_clicked();

    void goToHome();

    void configureMenu();

    void changeStack(int _stack);

    void on_MenuHome_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
