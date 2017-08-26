//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "release.h"

using namespace std;

namespace project {

Release::Release(double _value,
                 Account& _account,
                 string _typeRelease,
                 string _typePayment,
                 string _description,
                 time_t _date) :
  value{_value},
  account{&_account},
  typeRelease{_typeRelease},
  typePayment{_typePayment},
  description{_description},
  date{_date}
{

}

Release::~Release() {}

size_t Release::getId() {
    return id;
}

double Release::getValue() {
  return value;
}

Account& Release::getAccount() {
  return *account;
}

string Release::getTypeRelease() {
  return typeRelease;
}

string Release::getTypePayment() {
  return typePayment;
}

string Release::getDescription() {
  return description;
}

time_t Release::getDate() {
  return date;
}

void Release::changeValue(double _value) {
  value = _value;
}

void Release::changeAccount(Account& _account) {
    account = &_account;
}

void Release::changeTypeRelease(string _type) {
  typeRelease = _type;
}

void Release::changeTypePayment(string _type) {
  typePayment = _type;
}

void Release::changeDescription(string _description) {
  description = _description;
}

void Release::changeDate(time_t _date) {
  date = _date;
}

}  // namespace project
