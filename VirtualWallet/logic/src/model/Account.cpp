//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "Account.h"

namespace project {

Account::Account(int _id, string _name, double _balance, bool _type) :
    id(_id),
    balance(_balance),
    type(_type),
    name(_name)
{
    
}

Account::~Account() {
    
}

int Account::getId() {
    return id;
}


bool Account::getType() {
    return type;
}

string Account::getName() {
    return name;
}

double Account::getBalance() {
    return balance;
}

list<Release*> Account::getReleases() {
    return releases;
}

void Account::setId(int _id)
{
    id = _id;
}

void Account::changeName(string _newName) {
    name = _newName;
}

void Account::insertRelease(Release * _release) {
    releases.push_front(_release);
    balance += _release->getValue();
}

void Account::removeRelease(Release * _release) {
    releases.remove(_release);
    balance -= _release->getValue();
}

}  // namespace project
