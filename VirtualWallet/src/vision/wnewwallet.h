#ifndef WNEWWALLET_H
#define WNEWWALLET_H

#include <QWidget>
#include "./src/control/Facade.h"

using namespace project;

namespace Ui {
class WNewWallet;
}

class WNewWallet : public QWidget
{
    Q_OBJECT

public:
    explicit WNewWallet(QWidget *parent = 0);
    ~WNewWallet();

    void setFacade(Facade &_facade);

private slots:
    void on_Name_textEdited(const QString &arg1);

    void on_Clean_clicked();

    void on_Balance_valueChanged(const QString &arg1);

    void on_Confirm_clicked();

signals:
    void goToHome();

private:
    Ui::WNewWallet *ui;
    Facade * facade;
    bool name{false}, balance{false};

};

#endif // WNEWWALLET_H
