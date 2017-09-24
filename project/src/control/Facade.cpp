#include "Facade.h"

namespace project {

Facade::Facade() {

}

Facade::~Facade() {
    
}

bool Facade::registerWallet(std::string _name, double _balance) {
    return true;
}

bool Facade::registerBankAccount(std::string _name, double _balance, std::string _accountNumber, std::string _agency, std::string _bank) {
    return true;
}

bool Facade::registerReleaseType(std::string _name) {
    return true;
}

}