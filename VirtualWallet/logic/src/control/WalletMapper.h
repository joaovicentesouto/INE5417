//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_CONTROL_WALLET_MAPPER_H
#define PROJECT_CONTROL_WALLET_MAPPER_H

#include "../model/Wallet.h"

namespace project {

class WalletMapper  {
public:
    WalletMapper(mysqlpp::Connection & _conn);
    ~WalletMapper();

    void put(Wallet * wallet);
    Wallet * get(std::string nomeChavePrimaria);
    void remove(std::string nomeChavePrimaria);

private:
    void putNew(Wallet * wallet);
    void putUpdate(Wallet * wallet);

    mysqlpp::Connection conn(false); // ou o query??

};

}  // namespace project

#endif
