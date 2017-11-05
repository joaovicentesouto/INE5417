#include "bankaccountmapper.h"

namespace project {

BankAccountMapper::BankAccountMapper(QSqlDatabase & _conn) :
    conn(_conn)
{

}

BankAccountMapper::~BankAccountMapper()
{

}

} // namespace
