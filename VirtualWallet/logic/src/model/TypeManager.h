//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_TYPE_MANAGER_H
#define PROJECT_TYPE_MANAGER_H

#include <string>
#include <list>

using namespace std;

namespace project {

class TypeManager {
public:
    TypeManager();
    ~TypeManager();

    list<string> getReleaseTypes();
    list<string> getPaymentTypes();

    bool addReleaseType(string _type);
    void deleteReleaseType(string _type);
    bool changeReleaseType(string _old, string _new);

    bool releaseTypeExists(string _name);

private:
    list<string> releaseTypes, paymentTypes;

};

}  // namespace project

#endif
