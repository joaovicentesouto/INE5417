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
};

} // namespace

#endif // BANKACCOUNTMAPPER_H
