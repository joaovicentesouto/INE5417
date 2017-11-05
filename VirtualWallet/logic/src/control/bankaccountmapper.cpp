#include "bankaccountmapper.h"

namespace project {

BankAccountMapper::BankAccountMapper(QSqlDatabase & _conn) :
    conn(_conn)
{

}

BankAccountMapper::~BankAccountMapper()
{

}

BankAccount * BankAccountMapper::getById(int id)
{
    return nullptr;
}

BankAccount * BankAccountMapper::getByName(string name)
{
    return nullptr;
}

list<BankAccount*> BankAccountMapper::getAllBankAccounts()
{
    return list<BankAccount*>();
}

void BankAccountMapper::put(BankAccount * bankAccount)
{

}

void BankAccountMapper::putExistUser(BankAccount * bankAccount)
{

}

void BankAccountMapper::putNewUser(BankAccount * bankAccount)
{

}

void BankAccountMapper::remove(int id)
{

}

} // namespace
