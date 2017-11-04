#include "WalletMapper.h"

WalletMapper::WalletMapper(mysqlpp::Connection & _conn) :
    conn(_conn)
{

}

WalletMapper::~WalletMapper()
{

}

void WalletMapper::put(Wallet * wallet)
{

}

void WalletMapper::putNew(Wallet * wallet)
{

}

void WalletMapper::putUpdate(Wallet * wallet)
{

}

Wallet * WalletMapper::get(std::string nomeChavePrimaria)
{

}

void WalletMapper::remove(std::string nomeChavePrimaria)
{

}
