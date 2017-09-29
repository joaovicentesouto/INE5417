//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "User.h"

namespace project {

User::User(string _name, string _password) :
    name(_name),
    password(_password),
    manager(),
    accounts()
{

}

User::~User() {
    //while (!accounts.empty()) {
    //    delete accounts.front();
    //    accounts.pop_front();
    //}
}

size_t User::getId() {
    return id;
}

string User::getName() {
    return name;
}

string User::getPassword() {
    return password;
}

list<Account*> User::getAccounts() {
    return accounts;
}

bool User::verifyUser(std::string _name, std::string _password) {
    return (name == _name && password == _password);
}

void User::changeName(string _newName) {
    name = _newName;
}

void User::insertAccount(Account& _account) {
    accounts.push_front(&_account);
}

void User::removeAccount(Account& _account) {
    accounts.remove(&_account);
}

}  // namespace project
