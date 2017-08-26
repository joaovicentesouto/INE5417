//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "bank_account.h"

namespace project
{

BankAccount::BankAccount(string _name) :
  Account::Account(_name)
{

}

BankAccount::BankAccount(string _name, double _balance) :
  Account::Account(_name, _balance)
{

}

BankAccount::BankAccount(string _name, string _number, string _agency, string _bank) :
  Account::Account(_name)
{
  agency = _agency;
  account_number = _number;
  bank = _bank;
}

BankAccount::BankAccount(string _name, string _number, string _agency, string _bank, double _balance) :
  Account::Account(_name, _balance)
{
  agency = _agency;
  account_number = _number;
  bank = _bank;
}

BankAccount::~BankAccount()
{

}

int BankAccount::test()
{
  return 0;
}

}  // namespace project
