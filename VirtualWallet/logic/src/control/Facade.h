//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_CONTROL_FACADE_H
#define PROJECT_CONTROL_FACADE_H

#include <list>
#include <string>
#include "../model/User.h"
#include "../model/Wallet.h"
#include "./src/model/Account.h"
#include "WalletBuilder.h"
#include "BankAccountBuilder.h"
#include "ReleaseTypeBuilder.h"
#include "UserBuilder.h"
#include "ReleaseBuilder.h"
#include "ReportBuilder.h"

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
    bool registerRelease(double _value, std::string _accountName, std::string _releaseT, std::string _paymentT,
                         std::string _description, std::string _op, std::string _date);
    Report * createReport(list<string> accounts, list<string> releaseTypes, list<string> paymentTypes,
                          string begin, string end, double lower, double upper, bool in, bool out);

    void deleteReleaseType(std::string _name);
    void deleteAccount(std::string _name);

    bool containsAccount(std::string name);
    size_t accountsAmount();
    size_t releasesAmount(std::string name);
    bool login(std::string _name, std::string _password);

    double accountsBalance();
    std::string getUserName();
    list<std::string> * accountsNames();
    list<std::string> * walletsNames();
    list<std::string> * releaseTypesNames();
    list<std::string> * paymentTypesNames();
    list<BankAccount*> * bankAccounts();
    list<Account*> userAccounts();
    list<BankAccount*> * userBankAccounts();
    list<double> * accountsValues();
    list<double> * walletsValues();

    bool verifyNewPass(std::string _name, std::string _code, std::string _newPassword, std::string _confirm);
    void refreshPass(std::string _newPassword);
    bool verifyNewName(std::string _code, std::string _password, std::string _newName, std::string _confirm);
    void refreshName(std::string _newName);
    bool refreshReleaseType(std::string _oldName, std::string _newName);
    bool refreshWallet(std::string _oldName, std::string _newName);
    bool refreshAccount(std::string _oldName, std::string _newName, std::string _newNumber, std::string _newAgency, std::string _newBank, double _balance);

    void insertUser(User* _user);

private:
    User * user;
};
    
}  // namespace project

#endif
