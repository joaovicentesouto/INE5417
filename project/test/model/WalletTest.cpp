//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_WALLET_TEST_H
#define PROJECT_WALLET_TEST_H

#include <catch.hpp>
#include "../../src/model/Wallet.h"

using namespace project;

namespace
{

class WalletFixture
{
public:
    string name{"João"};
    double balance{100};
    list<Release*> releases;
    
    WalletFixture()
    {
        
    }
};
} // namespace

TEST_CASE_METHOD(WalletFixture, "Wallet: Checking attributes after the construction", "[attribute]")
{
    Wallet account(name, balance);
    
    REQUIRE(name == account.getName());
    REQUIRE(balance == account.getBalance());
}

TEST_CASE_METHOD(WalletFixture, "Wallet: Changing name", "[attribute]")
{
    Wallet account(name, balance);
    
    name = "Bruno";
    account.changeName(name);
    
    REQUIRE(name == account.getName());
}

TEST_CASE_METHOD(WalletFixture, "Wallet: Inserting releases", "[releases]")
{
    Wallet account(name, balance);
    
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

TEST_CASE_METHOD(WalletFixture, "Wallet: Removing releases", "[releases]")
{
    Wallet account(name, balance);
    
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
