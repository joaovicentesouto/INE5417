//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_CONTROL_WALLET_CREATOR_H
#define PROJECT_CONTROL_WALLET_CREATOR_H

#include <string>

#include "../model/Wallet.h"

namespace project {

class WalletCreator {
public:
    WalletCreator(std::string _name, double _balance);
    ~WalletCreator();

    bool isValid();
    Wallet* build();
    
private:
    double balance;
    std::string name;

};
    
}  // namespace project

#endif
