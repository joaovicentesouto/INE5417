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

namespace project {

class WalletMapper
{
public:
    WalletMapper(QSqlDatabase & _conn);
    ~WalletMapper();

private:
    QSqlDatabase & conn;
};

} // namespace

#endif // WALLETMAPPER_H
