//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_RELEASE_H
#define PROJECT_RELEASE_H

#include <string>
#include <ctime>
#include "account.h"

using namespace std;

namespace project {

class Release {
public:
  Release(double _value, Account& _account, string _typeRelease, string _typePayment, string _description, time_t _date);
  ~Release();

  size_t getId();
  double getValue();
  Account& getAccount();
  string getTypeRelease();
  string getTypePayment();
  string getDescription();
  time_t getDate();

  void changeValue(double _value);
  void changeAccount(Account& _account);
  void changeTypeRelease(string _type);
  void changeTypePayment(string _type);
  void changeDescription(string _description);
  void changeDate(time_t _date);

private:
  size_t id{0};
  double value;
  Account* account;
  string typeRelease, typePayment, description;
  time_t date;

};

}  // namespace project

#endif
