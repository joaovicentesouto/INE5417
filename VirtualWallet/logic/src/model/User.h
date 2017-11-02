//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#include <string>
#include <list>
#include "Account.h"
#include "TypeManager.h"

using namespace std;

namespace project {

class User {
public:
    User(string _name, string _password, string _code);
    ~User();

    size_t getId();
    string getCode();
    string getName();
    string getPassword();
    Account * getAccount(string _accountName);
    list<Account*> getAccounts();
    list<string> getReleaseTypesNames();
    list<string> getPaymentTypesNames();

    bool verifyUser(std::string _name, std::string _password);

    void changeName(string _newName);
    void changePassword(string _newPassword);

    bool insertAccount(Account& _account);
    void removeAccount(Account& _account);
    void removeAccount(std::string _name);
    void changeAccount(std::string _old, std::string _new);
    bool accountExist(std::string _name);

    bool insertReleaseType(std::string _type);
    void removeReleaseType(std::string _type);
    bool changeReleaseType(std::string _old, std::string _new);

private:
    size_t id{0};
    string name, password, code;
    TypeManager manager;
    list<Account*> accounts;

};

}  // namespace project

#endif
