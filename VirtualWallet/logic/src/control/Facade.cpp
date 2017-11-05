#include "Facade.h"
#include <iostream>

using namespace std;

namespace project {

Facade::Facade() :
    currentUser(-1),
    bd(new DataBase())
{

}

Facade::~Facade()
{

}

int Facade::getCurrentId()
{
    return currentUser;
}

bool Facade::registerUser(std::string _name, std::string _code, std::string _password, std::string _confirm)
{
    UserBuilder builder(_name, _code, _password, _confirm);

    if (!builder.isValid())
        return false;

    return bd->put(builder.build());
}

bool Facade::login(std::string _name, std::string _password)
{
    User * _user = bd->getUserByNameAndPass(_name, _password);
    if (_user == nullptr)
        return false;

    currentUser = _user->getId();
    return true;
}

bool Facade::refreshName(std::string _code, std::string _password, std::string _newName, std::string _confirm) {
    User * _user = bd->getUserByCodeAndPass(_code, _password);
    if (_user == nullptr)
        return false;

    if (_confirm.compare(_newName))
        return false;

    bd->put(new User(_newName, _password, _code));
    delete _user;
    return true;
}

bool Facade::refreshPass(std::string _name, std::string _code, std::string _newPass, std::string _confirm) {
    User * _user = bd->getUserByNameAndCode(_name, _code);
    if (_user == nullptr)
        return false;

    if (_confirm.compare(_newPass))
        return false;

    bd->put(new User(_name, _newPass, _code));
    delete _user;
    return true;
}

list<Account*> * Facade::userAccounts()
{
    return bd->getAccounts(currentUser);
}

list<Wallet*> * Facade::userWallets()
{
    return bd->getWallets(currentUser);
}

list<BankAccount*> * Facade::userBankAccounts()
{
    return bd->getBankAccounts(currentUser);
}

list<Release*> * Facade::userReleases()
{
    return bd->getReleases(currentUser);
}

list<ReleaseType*> * Facade::userReleaseTypes()
{
    return bd->getReleaseTypes(currentUser);
}

list<string> * Facade::userPaymentTypes()
{
    return bd->getPaymentTypes(currentUser);
}

bool Facade::registerReleaseType(std::string _name, int _typeId)
{
    ReleaseTypeBuilder builder(_name, _typeId);

    if (!builder.isValid())
        return false;

    return bd->put(builder.build(), currentUser);
}

void Facade::deleteReleaseType(int _typeId) {
    bd->removeReleaseType(_typeId, currentUser);
}

bool Facade::registerWallet(std::string _name, double _balance, int _accId)
{
    WalletBuilder creator(_accId, _name, _balance);

    if (!creator.isValid())
        return false;

    return bd->put(creator.build(), currentUser);
}

void Facade::deleteAccount(int _accId)
{
    bd->removeAccount(_accId, currentUser);
}

bool Facade::registerBankAccount(int _accId, std::string _name, double _balance, std::string _accountNumber, std::string _agency, std::string _bank)
{
    BankAccountBuilder builder(_accId, _name, _balance, _accountNumber, _agency, _bank);

    if (!builder.isValid())
        return false;

    return bd->put(builder.build(), currentUser);
}

bool Facade::registerRelease(int _relId, double _value, std::string _accountName, std::string _releaseT, std::string _paymentT,
                     std::string _description, std::string _op, std::string _date)
{
    Account * account = nullptr;
    for (auto & acc : (* bd->getAccounts(currentUser)))
        if (acc->getName() == _accountName) {
            account = acc;
            break;
        }

    ReleaseType * releaseT = nullptr;
    for (auto rel : (* bd->getReleaseTypes(currentUser)))
        if (rel->getName() == _releaseT) {
            releaseT = rel;
            break;
        }

    if (_op == "out")
        _value = - _value;

    ReleaseBuilder builder(_relId, _value, account, releaseT, _paymentT, _description, _op, _date);

    if (!builder.isValid())
        return false;

    return bd->put(builder.build(), currentUser);
}

void Facade::deleteRelease(int _id)
{
    bd->removeRelease(_id, currentUser);
}

Report * Facade::createReport(list<int> accountIds, list<int> releaseTypeIds, list<string> paymentTypes,
                      string begin, string end, double lower, double upper, bool in, bool out)
{
    list<Account*> accounts;
    for (auto & acc : (* bd->getAccounts(currentUser)))
        for (auto & accId : accountIds)
            if (acc->getId() == accId) {
                accounts.push_back(acc);
                break;
            }

    list<ReleaseType*> releaseTypes;
    for (auto & relT : (* bd->getReleaseTypes(currentUser)))
        for (auto & relTId : releaseTypeIds)
            if (relT->getId() == relTId) {
                releaseTypes.push_back(relT);
                break;
            }

    ReportBuilder builder(accounts, releaseTypes, paymentTypes, begin, end, lower, upper, in, out);

    if (!builder.isValid())
        return nullptr;

    return builder.build();
}

double Facade::accountsBalance() {
    if (userAccounts() == nullptr || !userAccounts()->size())
        return 0;

    double totalBalance = 0;

    for (auto i: (* userAccounts())) {
        totalBalance += i->getBalance();
    }
    return totalBalance;
}

std::string Facade::getUserName()
{
    return bd->getUser(currentUser)->getName();
}

}
