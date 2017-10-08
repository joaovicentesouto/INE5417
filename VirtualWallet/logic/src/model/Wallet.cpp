//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "Wallet.h"

namespace project {

Wallet::Wallet(string _name, double _balance) :
    Account::Account(_name, _balance, false)
{
    
}

Wallet::~Wallet()
{
    
}

}  // namespace project
