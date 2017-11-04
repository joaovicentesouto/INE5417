//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "Release.h"

using namespace std;

namespace project {

Release::Release(int _id, double _value, Account* _account,
                 ReleaseType * _releaseType, string _paymentType,
                 string _description, string _operation, string _date) :
    id(_id),
    value(_value),
    account(_account),
    releaseType(_releaseType),
    paymentType(_paymentType),
    description(_description),
    operation(_operation),
    date(_date)
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

Account * Release::getAccount() {
    return account;
}

ReleaseType * Release::getReleaseType() {
    return releaseType;
}

string Release::getPaymentType() {
    return paymentType;
}

string Release::getDescription() {
    return description;
}

string Release::getOperation() {
    return operation;
}

string Release::getDate() {
    return date;
}

void Release::changeValue(double _value) {
    value = _value;
}

void Release::changeAccount(Account *_account) {
    account = _account;
}

void Release::changeReleaseType(ReleaseType * _type) {
    releaseType = _type;
}

void Release::changePaymentType(string _type) {
    paymentType = _type;
}

void Release::changeDescription(string _description) {
    description = _description;
}

void Release::changeOperation(string _operation) {
    operation = _operation;
}

void Release::changeDate(string _date) {
    date = _date;
}

}  // namespace project
