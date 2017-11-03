#include "database.h"

using namespace std;

namespace project {

DataBase::DataBase()
{

}

DataBase::~DataBase()
{

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

void DataBase::put(User * _user)
{
    user = _user;
}

list<Account*> DataBase::getAccounts(int _userId)
{
    return user->getAccounts();
}

list<Release*> * DataBase::getAllReleases(int _userId)
{
    list<Release*> * releases = new list<Release*>();
    list<Account*> accounts = user->getAccounts();
    for (std::list<Account*>::iterator i = accounts.begin(); i != accounts.end(); ++i) {
        list<Release*> release = (*i)->getReleases();
        for (std::list<Release*>::iterator j = release.begin(); j != release.end(); ++j)
            releases->push_front(*j);
    }

    return releases;
}

list<ReleaseType*> DataBase::getReleaseTypes(int _userId)
{
    return user->getReleaseTypes();
}

bool DataBase::put(ReleaseType * _type, int _userId)
{
    list<ReleaseType*> types = user->getReleaseTypes();
    for (auto & it: types) {
        if (!it->getName().compare(_type->getName()))
            return false;

        if (it->getId() == _type->getId()) {
            user->removeReleaseType(it);
            break;
        }
    }

    return user->insertReleaseType(_type);
}

void DataBase::removeReleaseType(string _name, int _userId)
{
    user->removeReleaseType(_name);
}













bool DataBase::put(Wallet * _account, int _userId)
{
    return user->insertAccount(_account);
}

void DataBase::removeReleasesByType(string _type, int _userId)
{
    user->removeReleases(_type);
}

Account * DataBase::getAccount(string _name, int _userId)
{
    return user->getAccount(_name);
}

}
