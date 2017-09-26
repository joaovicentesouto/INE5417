//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_BANK_ACCOUNT_CREATOR_TEST_H
#define PROJECT_BANK_ACCOUNT_CREATOR_TEST_H

#include <catch.hpp>
#include "../../src/model/BankAccount.h"
#include "../../src/model/Wallet.h"
#include "../../src/model/TypeManager.h"
#include "../../src/control/Facade.h"

using namespace project;

namespace {

class FacadeFixture {
public:
    string name{"João"}, accountNumber{"123"}, agency{"0000-8"}, bank{"BB"};
    double balance{100};
    
    FacadeFixture() {
        
    }
};
} // namespace

TEST_CASE_METHOD(FacadeFixture, "Facade: Create with user default with 0 accounts", "[init]")
{
    Facade facade("Test");

    REQUIRE(facade.accountsAmount() == 0);
    REQUIRE(facade.releasesAmount("Test") == 0);
}

TEST_CASE_METHOD(FacadeFixture, "Facade: Create wallet", "[method]")
{
    Facade facade("Test");
    
    facade.registerWallet(name, balance);
    
    REQUIRE(facade.containsAccount(name));
    REQUIRE(facade.accountsAmount() == 1);
}

TEST_CASE_METHOD(FacadeFixture, "Facade: Create bank account", "[method]")
{
    Facade facade("Test");
    
    facade.registerBankAccount(name, balance, accountNumber, agency, bank);
    
    REQUIRE(facade.containsAccount(name));
    REQUIRE(facade.accountsAmount() == 1);
}

TEST_CASE_METHOD(FacadeFixture, "Facade: Create wallets and Bank accounts", "[method]")
{
    Facade facade("Test");
    
    facade.registerWallet("1", balance);    
    facade.registerBankAccount("2", balance, accountNumber, agency, bank);
    facade.registerWallet("3", balance);    
    facade.registerBankAccount("4", balance, accountNumber, agency, bank);
    
    REQUIRE(facade.containsAccount("1"));
    REQUIRE(facade.containsAccount("2"));
    REQUIRE(facade.containsAccount("3"));
    REQUIRE(facade.containsAccount("4"));
    REQUIRE(facade.accountsAmount() == 4);
}

#endif
