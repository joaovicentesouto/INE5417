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
    
    void addReleaseType(string _type);
    void deleteReleaseType(string _type);
    void changeReleaseType(string _old, string _new);
    
private:
    list<string> releaseTypes, paymentTypes;
    
};

}  // namespace project

#endif
