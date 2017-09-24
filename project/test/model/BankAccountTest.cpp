//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_BANK_ACCOUNT_TEST_H
#define PROJECT_BANK_ACCOUNT_TEST_H

#include <catch.hpp>
#include "../../src/model/BankAccount.h"

using namespace project;

namespace
{
    
class BankAccountFixture {
public:
    string name{"João"}, accountNumber{"123"}, agency{"0000-8"}, bank{"BB"};
    double balance{100};
    list<Release*> releases;
    
    BankAccountFixture()
    {
        
    }
};

} // namespace

TEST_CASE_METHOD(BankAccountFixture, "BankAccount: Checking attributes after the construction", "[attribute]")
{
    BankAccount account(name, balance, accountNumber, agency, bank);
    
    REQUIRE(name == account.getName());
    REQUIRE(balance == account.getBalance());
    REQUIRE(accountNumber == account.getAccountNumber());
    REQUIRE(agency == account.getAgency());
    REQUIRE(bank == account.getBank());
}

TEST_CASE_METHOD(BankAccountFixture, "BankAccount: Changing name, number, agency and bank", "[attribute]")
{
    BankAccount account(name, balance, accountNumber, agency, bank);
    
    name = "Bruno";
    accountNumber = "456";
    agency = "1111-0";
    bank = "Caixa";
    
    account.changeName(name);
    account.changeAccountNumber(accountNumber);
    account.changeAgency(agency);
    account.changeBank(bank);
    
    REQUIRE(name == account.getName());
    REQUIRE(accountNumber == account.getAccountNumber());
    REQUIRE(agency == account.getAgency());
    REQUIRE(bank == account.getBank());
}

TEST_CASE_METHOD(BankAccountFixture, "BankAccount: Inserting releases", "[releases]")
{
    BankAccount account(name, balance, accountNumber, agency, bank);
    
    Release agua(100, account, "Água", "Dinheiro", "Teste1", time(0));
    Release comida(100, account, "Comida", "Crédito", "Teste1", time(0));
    Release netflix(100, account, "Netflix", "Débito", "Teste1", time(0));
    
    releases.push_front(&agua);
    releases.push_front(&comida);
    releases.push_front(&netflix);
    
    account.insertRelease(agua);
    account.insertRelease(comida);
    account.insertRelease(netflix);
    
    REQUIRE(releases == account.getReleases());
}

TEST_CASE_METHOD(BankAccountFixture, "BankAccount: Removing releases", "[releases]")
{
    BankAccount account(name, balance, accountNumber, agency, bank);
    
    Release agua(100, account, "Água", "Dinheiro", "Teste1", time(0));
    Release comida(100, account, "Comida", "Crédito", "Teste1", time(0));
    Release netflix(100, account, "Netflix", "Débito", "Teste1", time(0));
    
    releases.push_front(&agua);
    releases.push_front(&comida);
    releases.push_front(&netflix);
    
    account.insertRelease(agua);
    account.insertRelease(comida);
    account.insertRelease(netflix);
    
    releases.remove(&netflix);
    account.removeRelease(netflix);
    
    REQUIRE(releases == account.getReleases());
}

#endif
