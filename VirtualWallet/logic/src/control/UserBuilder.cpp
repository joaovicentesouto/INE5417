#include "UserBuilder.h"

namespace project {

UserBuilder::UserBuilder(string _name, string _code, string _password, string _confirm) :
    name(_name),
    code(_code),
    password(_password),
    confirm(_confirm)
{

}

UserBuilder::~UserBuilder() {
    
}

bool UserBuilder::isValid() {
    return !name.empty() && !code.empty() && !password.empty() && password == confirm;
}

User* UserBuilder::build() {
    if (!isValid())
        throw std::out_of_range("Os parâmetros para a criação não são validos!");
    return new User(name, password, code);
}

}
