//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_CONTROL_BANK_ACCOUNT_MAPPER_H
#define PROJECT_CONTROL_BANK_ACCOUNT_MAPPER_H

#include "../model/BankAccount.h"

namespace project {

class BankAccountMapper  {
public:
    BankAccountMapper(mysqlpp::Connection & _conn);
    ~BankAccountMapper();

    void put(BankAccount * bankAccount);
    BankAccount * get(std::string nomeChavePrimaria);
    void remove(std::string nomeChavePrimaria);

private:
    void putNew(BankAccount * bankAccount);
    void putUpdate(BankAccount * bankAccount);

    mysqlpp::Connection conn(false); // ou o query??

};

}  // namespace project

#endif
