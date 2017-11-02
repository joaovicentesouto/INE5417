#include "Facade.h"
#include <iostream>

using namespace std;

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

    return user->insertAccount(*creator.build());
}

bool Facade::registerBankAccount(std::string _name, double _balance, std::string _accountNumber, std::string _agency, std::string _bank)
{
    BankAccountBuilder creator(_name, _balance, _accountNumber, _agency, _bank);

    if (!creator.isValid())
        return false;

    return user->insertAccount(*creator.build());
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

void Facade::deleteAccount(std::string _name)
{
    user->removeAccount(_name);
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

Report * Facade::createReport(list<string> accounts, list<string> releaseTypes, list<string> paymentTypes,
                      string begin, string end, double lower, double upper, bool in, bool out)
{
    list<Account*> accs;
    for (auto & name : accounts)
        accs.push_back(user->getAccount(name));

    ReportBuilder builder(accs, releaseTypes, paymentTypes, begin, end, lower, upper, in, out);

    if (!builder.isValid())
        return nullptr;

    return builder.build();
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

list<std::string> * Facade::walletsNames()
{
    list<std::string> *names = new list<std::string>();
    list<Account*> &&accounts = user->getAccounts();
    for (list<Account*>::iterator it = accounts.begin(); it != accounts.end(); ++it) {
        if (dynamic_cast<Wallet*>(*it) != nullptr)
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

list<double> * Facade::walletsValues()
{
    list<double> * values = new list<double>();
    list<Account*> accounts = user->getAccounts();
    for (std::list<Account*>::iterator i = accounts.begin(); i != accounts.end(); ++i) {
        if (dynamic_cast<Wallet*>(*i) != nullptr)
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

list<BankAccount*> * Facade::bankAccounts()
{
    list<BankAccount*> * bankAccounts = new list<BankAccount*>();
    list<Account*> accounts = user->getAccounts();
    BankAccount * temp;
    for (std::list<Account*>::iterator i = accounts.begin(); i != accounts.end(); ++i)
        if (dynamic_cast<BankAccount*>(*i) != nullptr)
            bankAccounts->push_front((BankAccount*) (*i));

    return bankAccounts;
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

bool Facade::refreshReleaseType(std::string _oldName, std::string _newName)
{
    return user->changeReleaseType(_oldName, _newName);
}

bool Facade::refreshWallet(std::string _oldName, std::string _newName)
{
    if (user->accountExist(_newName))
        return false;

    user->changeAccount(_oldName, _newName);
    return true;
}

bool Facade::refreshAccount(std::string _oldName, std::string _newName, std::string _newNumber, std::string _newAgency, std::string _newBank, double _balance)
{
    if (user->accountExist(_newName) && _newName.compare(_oldName))
        return false;

    BankAccountBuilder creator(_newName, _balance, _newNumber, _newAgency, _newBank);

    if (!creator.isValid())
        return false;

    user->removeAccount(_oldName);
    user->insertAccount(*creator.build());

    return true;
}

void Facade::insertUser(User* _user) {
    user = _user;
}

}
