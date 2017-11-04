#include "UserMapper.h"

UserMapper::UserMapper(mysqlpp::Connection & _conn) :
    conn(_conn)
{

}

UserMapper::~UserMapper()
{

}

void UserMapper::put(User * user)
{

}

void UserMapper::putNew(User * user)
{

}

void UserMapper::putUpdate(User * user)
{

}

User * UserMapper::get(std::string nomeChavePrimaria)
{

}

void UserMapper::remove(std::string nomeChavePrimaria)
{

}
