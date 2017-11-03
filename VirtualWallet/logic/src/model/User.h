//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#include <string>
#include <list>
#include "Account.h"
#include "releasetype.h"

using namespace std;

namespace project {

class User {
public:
    User(string _name, string _password, string _code);
    ~User();

    int getId();
    string getCode();
    string getName();
    string getPassword();
    list<Account*> getAccounts();
    list<ReleaseType*> getReleaseTypes();
    Account * getAccount(string _accountName);

    bool verifyUser(std::string _name, std::string _password);

    void changeName(string _newName);
    void changePassword(string _newPassword);

    bool insertAccount(Account * _account);
    void removeAccount(Account * _account);
    void removeAccount(std::string _name);
    void changeAccount(std::string _old, std::string _new);
    bool accountExist(std::string _name);

    bool insertReleaseType(ReleaseType * _type);
    void removeReleaseType(ReleaseType * _type);
    void removeReleases(ReleaseType * _type);

private:
    int id;
    string name, password, code;
    list<ReleaseType*> releaseTypes;
    list<string> paymentTypes;
    list<Account*> accounts;
};

}  // namespace project

#endif
