//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_BANK_ACCOUNT_H
#define PROJECT_BANK_ACCOUNT_H

#include "account.h"

using namespace std;

namespace project {

class BankAccount : private Account  {
public:
  explicit BankAccount(string _name);
  BankAccount(string _name, double _balance);
  BankAccount(string _name, string _number, string _agency, string _bank);
  BankAccount(string _name, string _number, string _agency, string _bank, double _balance);
  ~BankAccount();

  int test();

private:
  string account_number, agency, bank;
};

}  // namespace project

#endif
