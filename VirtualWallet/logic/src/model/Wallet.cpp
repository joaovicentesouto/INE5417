//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "Wallet.h"

namespace project {

Wallet::Wallet(int _id, string _name, double _balance) :
    Account::Account(_id, _name, _balance, false)
{
    
}

Wallet::~Wallet()
{
    
}

}  // namespace project
