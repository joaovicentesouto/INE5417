#ifndef DATABASE_H
#define DATABASE_H

#include "src/model/User.h"
#include "src/model/Wallet.h"
#include "src/model/Release.h"
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
    void removeUser(User * _user);

    list<Account*> getAccounts(int _userId);
    list<Release*> * getAllReleases(int _userId);
    list<ReleaseType*> getReleaseTypes(int _userId);












    bool put(ReleaseType * _type, int _userId);
    bool put(Wallet * _account, int _userId);

    void removeReleaseType(string _name, int _userId);
    void removeReleasesByType(string _type, int _userId);

    Account * getAccount(string _name, int _userId);

    /*void getRelease(int _id);
    void put(Release * _release);*/

    int accountId{0}, releaseId{0}, releaseTypeId{0};

private:
    User * user;

};

} // namespace

#endif // DATABASE_H
