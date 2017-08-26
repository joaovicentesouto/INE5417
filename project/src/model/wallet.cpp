//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "wallet.h"

namespace project
{

Wallet::Wallet(string _name) :
  Account::Account(_name)
{

}

Wallet::Wallet(string _name, double _balance) :
  Account::Account(_name, _balance)
{

}

Wallet::~Wallet()
{

}

int Wallet::test()
{
  return 0;
}


}  // namespace project
