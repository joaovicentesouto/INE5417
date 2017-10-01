//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_CONTROL_FACADE_H
#define PROJECT_CONTROL_FACADE_H

#include <list>
#include <string>
#include "../model/User.h"
#include "./src/model/Account.h"
#include "WalletBuilder.h"
#include "BankAccountBuilder.h"
#include "ReleaseTypeBuilder.h"
#include "UserBuilder.h"

namespace project {

class Facade {
public:
    Facade();
    Facade(std::string _name, std::string _password, std::string _code);
    ~Facade();

    bool registerWallet(std::string _name, double _balance);
    bool registerBankAccount(std::string _name, double _balance, std::string _accountNumber, std::string _agency, std::string _bank);
    bool registerReleaseType(std::string _name);
    bool registerUser(std::string _name,std::string _code, std::string _password, std::string _confirm);

    bool containsAccount(std::string name);
    size_t accountsAmount();
    size_t releasesAmount(std::string name);
    bool login(std::string _name, std::string _password);

    double accountsBalance();
    std::string getUserName();
    list<std::string> * accountsNames();
    list<std::string> * releaseTypesNames();
    list<std::string> * paymentTypesNames();

    bool verifyNewPass(std::string _name, std::string _code, std::string _newPassword, std::string _confirm);
    void refreshPass(std::string _newPassword);
    bool verifyNewName(std::string _code, std::string _password, std::string _newName, std::string _confirm);
    void refreshName(std::string _newName);
    
    void insertUser(User* _user);

private:
    User * user;
};
    
}  // namespace project

#endif
