#include "BankAccountMapper.h"

BankAccountMapper::BankAccountMapper(mysqlpp::Connection & _conn) :
    conn(_conn)
{

}

BankAccountMapper::~BankAccountMapper()
{

}

void BankAccountMapper::put(BankAccount * bankAccount)
{

}

void BankAccountMapper::putNew(BankAccount * bankAccount)
{

}

void BankAccountMapper::putUpdate(BankAccount * bankAccount)
{

}

BankAccount * BankAccountMapper::get(std::string nomeChavePrimaria)
{

}

void BankAccountMapper::remove(std::string nomeChavePrimaria)
{

}
