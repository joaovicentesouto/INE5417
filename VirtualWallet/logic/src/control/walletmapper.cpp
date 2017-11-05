#include "walletmapper.h"

namespace project {

WalletMapper::WalletMapper(QSqlDatabase & _conn) :
    conn(_conn)
{

}

WalletMapper::~WalletMapper()
{

}

} // namespace
