//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_ACCOUNT_H
#define PROJECT_ACCOUNT_H

#include <string>
#include <list>

using namespace std;

namespace project {

class Account {
public:
  Account(string _name, double _balance);
  ~Account();

  size_t getId();
  string getName();
  double getBalance();
  list<string> getReleases();

  void changeName(string _newName);
  void insertRelease(string _release);
  void removeRelease(string _release);

private:
  size_t id{0};
  double balance{0.0};
  string name;
  list<string> releases;

};

}  // namespace project

#endif
