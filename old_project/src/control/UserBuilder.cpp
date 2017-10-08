#include "UserBuilder.h"

namespace project {

UserBuilder::UserBuilder(string _name, string _password) :
    name(_name),
    password(_password)
{

}

UserBuilder::~UserBuilder() {
    
}

bool UserBuilder::isValid() {
    return !name.empty() && !password.empty();
}

User* UserBuilder::build() {
    if (!isValid())
        throw std::out_of_range("Os parâmetros para a criação não são validos!");
    return new User(name, password);
}

}