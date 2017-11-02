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

public slots:
    void tableBuilder();

private slots:
    void on_Clean_clicked();

    void on_Confirm_clicked();

    void on_WalletTable_clicked(const QModelIndex &index);

    void on_Delete_clicked();

signals:
    void build();

private:
    Ui::WNewWallet *ui;
    Facade * facade;

};

#endif // WNEWWALLET_H
