#ifndef WALLETMAPPER_H
#define WALLETMAPPER_H

#include <QDebug>
#include <QDir>
#include <QtSql>
#include <QSqlDriver>
#include <qsqldatabase.h>
#include <QSqlError>
#include <QPluginLoader>

#include <string>
#include <list>

#include "src/model/Wallet.h"
#include "src/model/Release.h"
#include "src/control/releasemapper.h"

namespace project {

class WalletMapper
{
public:
    WalletMapper(QSqlDatabase & _conn);
    ~WalletMapper();

    Wallet * getById(int id);
    Wallet * getByName(string name);
    list<Wallet*> getAllWallets();

    void put(Wallet * wallet);
    void remove(int id);

private:
    void putExistUser(Wallet * wallet);
    void putNewUser(Wallet * wallet);

    QSqlDatabase & conn;
    ReleaseMapper releaseMapper;

};

} // namespace

#endif // WALLETMAPPER_H
