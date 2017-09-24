//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_CONTROL_FACADE_H
#define PROJECT_CONTROL_FACADE_H

#include <list>
#include "../model/User.h"
#include "WalletCreator.h"
#include "BankAccountCreator.h"
#include "ReleaseTypeCreator.h"

namespace project {

class Facade {
public:
    Facade();
    ~Facade();

    bool registerWallet(std::string _name, double _balance);
    bool registerBankAccount(std::string _name, double _balance, std::string _accountNumber, std::string _agency, std::string _bank);
    bool registerReleaseType(std::string _name);

    bool performRelease();
    bool showRelease();
    
private:
    User * user;

};
    
}  // namespace project

#endif
