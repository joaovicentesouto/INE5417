#ifndef BANKACCOUNTMAPPER_H
#define BANKACCOUNTMAPPER_H

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

class BankAccountMapper
{
public:
    BankAccountMapper(QSqlDatabase & _conn);
    ~BankAccountMapper();

private:
    QSqlDatabase & conn;
};

} // namespace

#endif // BANKACCOUNTMAPPER_H
