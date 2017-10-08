//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_CONTROL_WALLET_CREATOR_H
#define PROJECT_CONTROL_WALLET_CREATOR_H

#include <string>
#include <stdexcept>

#include "../model/Wallet.h"

namespace project {

class WalletBuilder {
public:
    WalletBuilder(std::string _name, double _balance);
    ~WalletBuilder();

    bool isValid();
    Wallet* build();

private:
    double balance;
    std::string name;

};

}  // namespace project

#endif
