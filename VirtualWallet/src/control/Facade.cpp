#include "Facade.h"

namespace project {

Facade::Facade() {

}

Facade::Facade(std::string _name, std::string _password, std::string _code) {
    user = new User(_name, _password, _code);
}

Facade::~Facade() {
    
}

bool Facade::registerWallet(std::string _name, double _balance) {
    WalletBuilder creator(_name, _balance);

    if (creator.isValid())
        return false;

    user->insertAccount(*creator.build());
    return true;

}

bool Facade::registerBankAccount(std::string _name, double _balance, std::string _accountNumber, std::string _agency, std::string _bank) {
    BankAccountBuilder creator(_name, _balance, _accountNumber, _agency, _bank);

    if (!creator.isValid())
        return false;

    user->insertAccount(*creator.build());
    return true;
}

bool Facade::registerReleaseType(std::string _name) {
    ReleaseTypeBuilder builder(_name);

    if (!builder.isValid())
        return false;

    user->insertReleaseType(_name);
    return true;
}

bool Facade::registerUser(std::string _name, std::string _code, std::string _password, std::string _confirm) {
    UserBuilder creator(_name, _code, _password, _confirm);

    if (!creator.isValid())
        return false;

    insertUser(creator.build());
    return true;
}

bool Facade::containsAccount(std::string name) {
    list<Account*> accounts = user->getAccounts();
    for (std::list<Account*>::iterator i = accounts.begin(); i != accounts.end(); ++i) {
        if ((*i)->getName() == name)
            return true;
    }
    return false;
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
    //user->getAccount(name).getReleases().size();
    return 0;
}

bool Facade::login(std::string _name, std::string _password)
{
    return user->verifyUser(_name, _password);
}

std::string Facade::getUserName()
{
    return user->getName();
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

void Facade::insertUser(User* _user) {
    user = _user;
}

}
