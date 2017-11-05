#include "usermapper.h"

namespace project {

UserMapper::UserMapper(QSqlDatabase & _conn) :
    conn(_conn)
{

}

UserMapper::~UserMapper()
{

}

} // namespace
