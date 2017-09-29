//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_CONTROL_USER_CREATOR_H
#define PROJECT_CONTROL_USER_CREATOR_H

#include <string>
#include <stdexcept>
#include "../model/User.h"

namespace project {

class UserBuilder {
public:
    UserBuilder(std::string _name, std::string _password);
    ~UserBuilder();

    bool isValid();
    User* build();

private:
    std::string name, password;

};

}  // namespace project

#endif
