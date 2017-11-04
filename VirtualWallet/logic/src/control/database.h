#ifndef DATABASE_H
#define DATABASE_H

#include "src/model/User.h"
#include "src/model/Wallet.h"
#include "src/model/Release.h"
#include "src/model/BankAccount.h"
#include <string>
#include <list>

using namespace std;

namespace project {

class DataBase
{
public:
    DataBase();
    ~DataBase();

    User * getUserByNameAndPass(string _name, string _password);
    User * getUserByCodeAndPass(string _code, string _password);
    User * getUserByNameAndCode(string _name, string _code);

    void put(User * _user);

    list<Wallet*> getWallets(int _userId);
    list<Account*> getAccounts(int _userId);
    list<BankAccount*> getBankAccounts(int _userId);
    list<Release*> * getAllReleases(int _userId);
    list<ReleaseType*> getReleaseTypes(int _userId);

    bool put(ReleaseType * _type, int _userId);
    void removeReleaseType(int _typeId, int _userId);
    void removeReleasesByType(string _type, int _userId);

    bool put(Wallet * _account, int _userId);
    void removeAccount(int _accId, int _userId);

    bool put(BankAccount * _account, int _userId);







    int accountId{0}, releaseId{0}, releaseTypeId{0};

private:
    User * user;

};

} // namespace

#endif // DATABASE_H
