//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_WALLET_H
#define PROJECT_WALLET_H

#include "account.h"

using namespace std;

namespace project {

class Wallet : private Account  {
public:
  explicit Wallet(string _name);
  Wallet(string _name, double _balance);
  ~Wallet();

  int test();
};

}  // namespace project

#endif
