{//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_WALLET_H
#define PROJECT_WALLET_H

#include "account.h"

namespace project {

class Wallet : private Account  {
public:
  Wallet(std:string _name);
  Wallet(std:string _name, double _balance);
  ~Wallet();

};

}  // namespace project

#endif
}
