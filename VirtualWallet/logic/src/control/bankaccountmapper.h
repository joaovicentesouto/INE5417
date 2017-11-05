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

#include "src/model/BankAccount.h"
#include "src/model/Release.h"
#include "src/control/releasemapper.h"

namespace project {

class BankAccountMapper
{
public:
    BankAccountMapper(QSqlDatabase & _conn);
    ~BankAccountMapper();

    BankAccount * getById(int id);
    BankAccount * getByName(string name);
    list<BankAccount*> getAllBankAccounts();

    void put(BankAccount * bankAccount);
    void remove(int id);

private:
    void putExistUser(BankAccount * bankAccount);
    void putNewUser(BankAccount * bankAccount);

    QSqlDatabase & conn;
    ReleaseMapper releaseMapper;
};

} // namespace

#endif // BANKACCOUNTMAPPER_H
