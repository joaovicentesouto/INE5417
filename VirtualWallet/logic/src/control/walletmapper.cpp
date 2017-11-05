#include "walletmapper.h"

namespace project {

WalletMapper::WalletMapper(QSqlDatabase & _conn) :
    conn(_conn),
    releaseMapper(_conn)
{

}

WalletMapper::~WalletMapper()
{

}

Wallet * WalletMapper::getById(int id)
{
    return nullptr;
}

Wallet * WalletMapper::getByName(string name)
{
    return nullptr;
}

list<Wallet*> WalletMapper::getAllWallets()
{
    return list<Wallet*>();
}

void WalletMapper::put(Wallet * wallet)
{

}

void WalletMapper::putExistUser(Wallet * wallet)
{

}

void WalletMapper::putNewUser(Wallet * wallet)
{

}

void WalletMapper::remove(int id)
{

}

} // namespace
