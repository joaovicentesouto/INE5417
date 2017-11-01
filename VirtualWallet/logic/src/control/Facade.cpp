#include "Facade.h"
#include <iostream>

namespace project {

Facade::Facade()
{

}

Facade::Facade(std::string _name, std::string _password, std::string _code)
{
    user = new User(_name, _password, _code);
}

Facade::~Facade()
{

}

bool Facade::registerWallet(std::string _name, double _balance)
{
    WalletBuilder creator(_name, _balance);

    if (!creator.isValid())
        return false;

    user->insertAccount(*creator.build());
    return true;

}

bool Facade::registerBankAccount(std::string _name, double _balance, std::string _accountNumber, std::string _agency, std::string _bank)
{
    BankAccountBuilder creator(_name, _balance, _accountNumber, _agency, _bank);

    if (!creator.isValid())
        return false;

    user->insertAccount(*creator.build());
    return true;
}

bool Facade::registerReleaseType(std::string _name)
{
    ReleaseTypeBuilder builder(_name);

    if (!builder.isValid())
        return false;

    return user->insertReleaseType(_name);
}

void Facade::deleteReleaseType(std::string _name)
{
    user->removeReleaseType(_name);
}

bool Facade::registerUser(std::string _name, std::string _code, std::string _password, std::string _confirm)
{
    UserBuilder creator(_name, _code, _password, _confirm);

    if (!creator.isValid())
        return false;

    insertUser(creator.build());
    return true;
}

bool Facade::registerRelease(double _value, std::string _accountName, std::string _releaseT, std::string _paymentT,
                     std::string _description, std::string _op, std::string _date)
{
    Account * _account = user->getAccount(_accountName);

    if (_account == nullptr)
        return false;

    if (_op == "out")
        _value = - _value;

    ReleaseBuilder builder(_value, _account, _releaseT, _paymentT, _description, _op, _date);
    if (!builder.isValid())
        return false;

    _account->insertRelease(*builder.build());
    return true;
}

bool Facade::containsAccount(std::string name)
{
    return user->getAccount(name) != nullptr;
}

size_t Facade::accountsAmount() {
    return user->getAccounts().size();
}

double Facade::accountsBalance() {
    double totalBalance = 0;
    list<Account*> accounts = user->getAccounts();
    for (std::list<Account*>::iterator i = accounts.begin(); i != accounts.end(); ++i) {
        totalBalance += (*i)->getBalance();
    }
    return totalBalance;
}

size_t Facade::releasesAmount(std::string name) {
    return user->getAccount(name)->getReleases().size();
}

bool Facade::login(std::string _name, std::string _password)
{
    return user->verifyUser(_name, _password);
}

std::string Facade::getUserName()
{
    return user->getName();
}

list<std::string> * Facade::accountsNames()
{
    list<std::string> *names = new list<std::string>();
    list<Account*> &&accounts = user->getAccounts();
    for (list<Account*>::iterator it = accounts.begin(); it != accounts.end(); ++it) {
        names->push_front((*it)->getName());
    }

    names->sort();
    return names;
}

list<std::string> * Facade::releaseTypesNames()
{
    list<std::string> *names = new list<std::string>();
    *names = user->getReleaseTypesNames();

    names->sort();
    return names;
}

list<double> * Facade::accountsValues()
{
    list<double> * values = new list<double>();
    list<Account*> accounts = user->getAccounts();
    for (std::list<Account*>::iterator i = accounts.begin(); i != accounts.end(); ++i) {
        values->push_front((*i)->getBalance());
    }
    return values;
}

list<std::string> * Facade::paymentTypesNames()
{
    list<std::string> *names = new list<std::string>();
    *names = user->getPaymentTypesNames();

    names->sort();
    return names;
}

list<Account*> Facade::userAccounts()
{
    return user->getAccounts();
}

bool Facade::verifyNewPass(std::string _name, std::string _code, std::string _newPassword, std::string _confirm) {
    return _name == user->getName() && _code == user->getCode() && _newPassword == _confirm;
}

void Facade::refreshPass(std::string _newPassword) {
    user->changePassword(_newPassword);
}

bool Facade::verifyNewName(std::string _code, std::string _password, std::string _newName, std::string _confirm) {
    return _code == user->getCode() && _password == user->getPassword() && _newName == _confirm;
}

void Facade::refreshName(std::string _newName) {
    user->changeName(_newName);
}

void Facade::refreshReleaseType(std::string _oldName, std::string _newName)
{
    user->changeReleaseType(_oldName, _newName);
}

void Facade::insertUser(User* _user) {
    user = _user;
}

}
