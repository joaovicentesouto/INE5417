//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_BANK_ACCOUNT_CREATOR_TEST_H
#define PROJECT_BANK_ACCOUNT_CREATOR_TEST_H

#include <catch.hpp>
#include "../../src/model/BankAccount.h"
#include "../../src/control/BankAccountCreator.h"


using namespace project;

namespace {

class BankAccountCreatorFixture {
public:
    string name{"João"}, accountNumber{"123"}, agency{"0000-8"}, bank{"BB"};
    double balance{100};
    
    BankAccountCreatorFixture() {
        
    }
};
} // namespace

TEST_CASE_METHOD(BankAccountCreatorFixture, "BankAccountCreator: Create a valid account", "[method]")
{
    BankAccountCreator creator(name, balance, accountNumber, agency, bank);
    
    REQUIRE(creator.isValid());

    BankAccount * account = creator.build();

    REQUIRE(name == account->getName());
    REQUIRE(balance == account->getBalance());
    REQUIRE(accountNumber == account->getAccountNumber());
    REQUIRE(agency == account->getAgency());
    REQUIRE(bank == account->getBank());

    delete account;
}

TEST_CASE_METHOD(BankAccountCreatorFixture, "BankAccountCreator: don't create a invalid account", "[method]")
{
    BankAccountCreator creator(name, balance, accountNumber, agency, "");
    
    REQUIRE(!creator.isValid());
}

#endif
