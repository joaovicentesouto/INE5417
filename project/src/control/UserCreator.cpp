#include "UserCreator.h"

namespace project {

UserCreator::UserCreator(string _name, string _password) :
    name(_name),
    password(_password)
{

}

UserCreator::~UserCreator() {
    
}

bool UserCreator::isValid() {
    return !name.empty() && !password.empty();
}

User* UserCreator::build() {
    if (!isValid())
        throw std::out_of_range("Os parâmetros para a criação não são validos!");
    return new User(name, password);
}

}