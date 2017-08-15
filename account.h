//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_ACCOUNT_H
#define PROJECT_ACCOUNT_H

#include <string>
#include <vector>

namespace project {

class Account {
public:
  Account(std:string _name);
  Account(std:string _name, double _balance);
  ~Account();

private:
  double balance{0.0};
  std::string name;
  std::vector<T> releases;

};

}  // namespace project

#endif
