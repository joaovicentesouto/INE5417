#include "database.h"

#include <iostream>

using namespace std;

namespace project {

DataBase::DataBase()
{
    conn = QSqlDatabase::addDatabase("QPSQL");
    conn.setUserName("postgres");
    conn.setPassword("senha");
    conn.setHostName("localhost");
    conn.setDatabaseName("engenharia");
    conn.setPort(5432);
}

DataBase::~DataBase()
{

}

User * DataBase::getUser(int _id)
{
    return user;
}

User * DataBase::getUserByNameAndPass(string _name, string _password)
{
    if (!_name.compare(user->getName()) && !_password.compare(user->getPassword()))
        return user;

    return nullptr;
}

User * DataBase::getUserByCodeAndPass(string _code, string _password)
{
    if (!_code.compare(user->getCode()) && !_password.compare(user->getPassword()))
        return user;

    return nullptr;
}

User * DataBase::getUserByNameAndCode(string _name, string _code)
{
    if (!_code.compare(user->getCode()) && !_name.compare(user->getName()))
        return user;

    return nullptr;
}

bool DataBase::put(User * _user)
{
    counterUser++;
    user = _user;
    return true;
}

list<Wallet*> DataBase::getWallets(int _userId)
{
    list<Wallet*> wallets;
    for (auto acc : user->getAccounts())
        if (!acc->getType())
            wallets.push_back(static_cast<Wallet*>(acc));

    return wallets;
}

list<Account*> DataBase::getAccounts(int _userId)
{
    return user->getAccounts();
}

list<BankAccount*> DataBase::getBankAccounts(int _userId)
{
    list<BankAccount*> banksAcc;
    for (auto & acc : user->getAccounts())
        if (acc->getType())
            banksAcc.push_back(static_cast<BankAccount*>(acc));

    return banksAcc;
}

list<Release*> DataBase::getReleases(int _userId)
{
    list<Release*> releases;

    for (auto & acc : user->getAccounts())
        for (auto & rel : acc->getReleases())
            releases.push_front(rel);

    return releases;
}

list<ReleaseType*> DataBase::getReleaseTypes(int _userId)
{
    return user->getReleaseTypes();
}

list<string> DataBase::getPaymentTypes(int _userId)
{
    return user->getPaymentTypes();
}

Account * DataBase::getAccount(string _accName, int _userId)
{
    return user->getAccount(_accName);
}

bool DataBase::put(ReleaseType * _type, int _userId)
{
    for (auto it : user->getReleaseTypes()) {
        if (!it->getName().compare(_type->getName()))
            return false;

        if (it->getId() == _type->getId()) {
            user->removeReleaseType(it);
            break;
        }
    }

    if (_type->getId() == -1)
        _type->setId(counterReleaseTypes++);

    return user->insertReleaseType(_type);
}

void DataBase::removeReleaseType(int _typeId, int _userId)
{
    for (auto it: user->getReleaseTypes())
        if (it->getId() == _typeId) {
            removeReleasesByType(it->getName(), _userId);
            user->removeReleaseType(it);
            break;
        }
}

void DataBase::removeReleasesByType(string _type, int _userId)
{
    user->removeReleases(_type);
}

void DataBase::removeRelease(int _relId, int _userId)
{
    for (auto & acc : user->getAccounts())
        for (auto & rel : acc->getReleases())
            if (rel->getId() == _relId) {
                acc->removeRelease(rel);
                break;
            }
}

bool DataBase::put(Wallet * _account, int _userId)
{
    for (auto & it: user->getAccounts()) {
        if (!it->getName().compare(_account->getName()))
            return false;

        if (it->getId() == _account->getId()) {
            user->removeAccount(it);
            break;
        }
    }

    if (_account->getId() == -1)
        _account->setId(counterAccounts++);

    return user->insertAccount(_account);
}

void DataBase::removeAccount(int _accId, int _userId)
{
    for (auto & it: user->getAccounts())
        if (it->getId() == _accId) {
            user->removeAccount(it->getName());
            break;
        }
}

bool DataBase::put(BankAccount * _account, int _userId)
{
    for (auto & it: user->getAccounts()) {
        if (!it->getName().compare(_account->getName()))
            return false;

        if (it->getId() == _account->getId()) {
            user->removeAccount(it);
            break;
        }
    }

    if (_account->getId() == -1)
        _account->setId(counterAccounts++);

    return user->insertAccount(_account);
}

bool DataBase::put(Release * _release, int _userId)
{
    for (auto & i : getAccounts(_userId))
        for (auto & j : i->getReleases())
            if (j->getId() == _release->getId()) {
                i->removeRelease(j);
                i->insertRelease(_release);
                return true;
            }

    if (_release->getId() == -1)
        _release->setId(counterReleases++);

    _release->getAccount()->insertRelease(_release);
    return true;
}

}
