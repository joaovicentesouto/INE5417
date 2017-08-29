//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_ACCOUNT_TEST_H
#define PROJECT_ACCOUNT_TEST_H

#include <catch.hpp>
#include "../../src/model/release.h"
#include "../../src/model/account.h"


using namespace project;

namespace {

class AccountFixture {
public:
    string name{"João"};
    double balance{100};
    list<Release*> releases;
    
    AccountFixture() {
        
    }
};
} // namespace

TEST_CASE_METHOD(AccountFixture, "Account: Checking attributes after the construction", "[attribute]")
{
    Account account(name, balance);
    
    REQUIRE(name == account.getName());
    REQUIRE(balance == account.getBalance());
}

TEST_CASE_METHOD(AccountFixture, "Account: Changing name", "[attribute]")
{
    Account account(name, balance);
    
    name = "Bruno";
    account.changeName(name);
    
    REQUIRE(name == account.getName());
}

TEST_CASE_METHOD(AccountFixture, "Account: Inserting releases", "[releases]")
{
    Account account(name, balance);
    
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

TEST_CASE_METHOD(AccountFixture, "Account: Removing releases", "[releases]")
{
    Account account(name, balance);
    
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
