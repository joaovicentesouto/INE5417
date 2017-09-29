#include "Facade.h"

namespace project {

Facade::Facade() {

}

Facade::Facade(std::string _name, std::string _password) {
    user = new User(_name, _password);
}

Facade::~Facade() {
    
}



bool Facade::registerWallet(std::string _name, double _balance) {
    WalletBuilder creator(_name, _balance);
    user->insertAccount(*creator.build());
    return true;
}

bool Facade::registerBankAccount(std::string _name, double _balance, std::string _accountNumber, std::string _agency, std::string _bank) {
    BankAccountBuilder creator(_name, _balance, _accountNumber, _agency, _bank);
    user->insertAccount(*creator.build());
    return true;
}

bool Facade::registerReleaseType(std::string _name) {
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

size_t Facade::releasesAmount(std::string name) {
    //user->getAccount(name).getReleases().size();
    return 0;
}

bool Facade::login(std::string _name, std::string _password)
{
    return user->verifyUser(_name, _password);
}

}
