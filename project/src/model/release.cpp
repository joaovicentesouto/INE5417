//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "Release.h"

using namespace std;

namespace project {

Release::Release(double _value, Account& _account,
                 string _releaseType, string _paymentType,
                 string _description, time_t _date) :
    value{_value},
    account{&_account},
    releaseType{_releaseType},
    paymentType{_paymentType},
    description{_description},
    date{_date}
{
    
}

Release::~Release() {

}

size_t Release::getId() {
    return id;
}

double Release::getValue() {
    return value;
}

Account& Release::getAccount() {
    return *account;
}

string Release::getReleaseType() {
    return releaseType;
}

string Release::getPaymentType() {
    return paymentType;
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

void Release::changeReleaseType(string _type) {
    releaseType = _type;
}

void Release::changePaymentType(string _type) {
    paymentType = _type;
}

void Release::changeDescription(string _description) {
    description = _description;
}

void Release::changeDate(time_t _date) {
    date = _date;
}

}  // namespace project
