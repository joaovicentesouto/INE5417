#include "usermapper.h"

namespace project {

UserMapper::UserMapper(QSqlDatabase & _conn) :
    conn(_conn)
{

}

UserMapper::~UserMapper()
{

}

User * UserMapper::getById(int id)
{
    return nullptr;
}

User * UserMapper::getByName(string name)
{
    return nullptr;
}

list<User*> UserMapper::getAllUsers()
{
    return list<User*>();
}

void UserMapper::put(User * user)
{

}

void UserMapper::putExistUser(User * user)
{

}

void UserMapper::putNewUser(User * user)
{

}

void UserMapper::remove(int id)
{

}

} // namespace
