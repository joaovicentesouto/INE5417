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

private slots:
    void on_Limpar_clicked();

    void on_Confirmar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
