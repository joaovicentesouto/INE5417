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
    bool nome{false};
    bool senha{false};

private slots:
    void on_Limpar_clicked();

    void on_Confirmar_clicked();

    void on_Nome_textEdited(const QString &arg1);

    void on_Senha_textEdited(const QString &arg1);

    void on_MenuButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
