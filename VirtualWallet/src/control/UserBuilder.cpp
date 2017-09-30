#include "UserBuilder.h"

namespace project {

UserBuilder::UserBuilder(string _name, string _password, string _code) :
    name(_name),
    password(_password),
    code(_code)
{

}

UserBuilder::~UserBuilder() {
    
}

bool UserBuilder::isValid() {
    return !name.empty() && !password.empty() && !code.empty();
}

User* UserBuilder::build() {
    if (!isValid())
        throw std::out_of_range("Os parâmetros para a criação não são validos!");
    return new User(name, password, code);
}

}
