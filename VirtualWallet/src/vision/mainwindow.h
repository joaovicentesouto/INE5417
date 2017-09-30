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

private slots:
    void on_CleanButton_clicked();

    void on_ConfirmButton_clicked();

    void on_LoginName_textEdited(const QString &arg1);

    void on_LoginPassword_textEdited(const QString &arg1);

    void on_MenuButton_clicked();

    void configureMenu();

    void on_MenuNewReleaseType_clicked();

    void on_MenuNewRelease_clicked();

    void on_MenuReport_clicked();

    void on_MenuBankAccounts_clicked();

    void on_MenuWallets_clicked();

    void on_MenuUserDatas_clicked();

    void on_MenuAbout_clicked();

    void on_MenuOut_clicked();

    void on_LoginPasswordForgot_clicked();

    void on_ForgotPassCleanButton_clicked();

    void on_ForgotPassName_textEdited(const QString &arg1);

    void on_ForgotPassCode_textEdited(const QString &arg1);

    void on_ForgotPassNewPass_textEdited(const QString &arg1);

    void on_ForgotPassConfirm_textEdited(const QString &arg1);

    void on_ForgotPassBack_clicked();

    void on_ForgotPassConfirmButton_clicked();

    void on_ForgotNameCode_textEdited(const QString &arg1);

    void on_ForgotNamePassword_textEdited(const QString &arg1);

    void on_ForgotNameNewName_textEdited(const QString &arg1);

    void on_ForgotNameConfirm_textEdited(const QString &arg1);

    void on_ForgotNameCleanButton_clicked();

    void on_LoginNameForgot_clicked();

    void on_ForgotNameBack_clicked();

    void on_ForgotNameConfirmButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
