//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "account.h"

namespace project
{

Account::Account(string _name, double _balance) :
name(_name),
balance(_balance)
{
    
}

Account::~Account() {
    
}

size_t Account::getId() {
    return id;
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

void Account::changeName(string _newName) {
    name = _newName;
}

void Account::insertRelease(Release& _release) {
    releases.push_front(&_release);
}

void Account::removeRelease(Release& _release) {
    releases.remove(&_release);
}
    
}  // namespace project
