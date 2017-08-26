//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_ACCOUNT_H
#define PROJECT_ACCOUNT_H

#include <string>
#include <vector>

using namespace std;

namespace project {

class Account {
public:
  explicit Account(string _name);
  Account(string _name, double _balance);
  ~Account();

  int test();

private:
  double balance{0.0};
  string name;
  vector<string> releases;

};

}  // namespace project

#endif
