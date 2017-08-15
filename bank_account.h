//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_BANK_ACCOUNT_H
#define PROJECT_BANK_ACCOUNT_H

#include "account.h"

namespace project {

class BankAccount : private Account  {
public:
  BankAccount(std:string _name);
  BankAccount(std:string _name, double _balance);
  BankAccount(std:string _name, std::string _number, std::string _agency, std::string _bank);
  BankAccount(std:string _name, std::string _number, std::string _agency, std::string _bank, double _balance);

private:
  std::string account_number, agency, bank;
};

}  // namespace project

#endif
