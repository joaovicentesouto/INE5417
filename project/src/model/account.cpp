//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "account.h"

namespace project
{

Account::Account(string _name) :
  name(_name)
{

}

Account::Account(string _name, double _balance) :
  name(_name),
  balance(_balance)
{

}

Account::~Account()
{

}

int Account::test()
{
  return 0;
}

}  // namespace project
