//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "User.h"

namespace project {

User::User(string _name, string _password, string _code) :
    name(_name),
    password(_password),
    code(_code),
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

string User::getCode() {
    return code;
}

string User::getPassword() {
    return password;
}

list<Account*> User::getAccounts() {
    return accounts;
}

Account * User::getAccount(string _accountName) {
    for (Account * account : accounts) {
        if (_accountName == account->getName())
            return account;
    }
    return nullptr;
}

bool User::verifyUser(std::string _name, std::string _password) {
    return (name == _name && password == _password);
}

void User::changeName(string _newName) {
    name = _newName;
}

void User::changePassword(string _newPassword) {
    password = _newPassword;
}

void User::insertAccount(Account& _account) {
    accounts.push_front(&_account);
}

void User::removeAccount(Account& _account) {
    accounts.remove(&_account);
}

bool User::insertReleaseType(std::string _type) {
    return manager.addReleaseType(_type);
}

void User::removeReleaseType(std::string _type) {
    manager.deleteReleaseType(_type);
}

void User::changeReleaseType(std::string _old, std::string _new) {
    manager.changeReleaseType(_old, _new);
}

list<string> User::getReleaseTypesNames() {
    return manager.getReleaseTypes();
}

list<string> User::getPaymentTypesNames() {
    return manager.getPaymentTypes();
}

}  // namespace project
