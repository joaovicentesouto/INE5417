//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_BANK_ACCOUNT_BUILDER_TEST_H
#define PROJECT_BANK_ACCOUNT_BUILDER_TEST_H

#include <catch.hpp>
#include "../../src/model/BankAccount.h"
#include "../../src/control/BankAccountBuilder.h"


using namespace project;

namespace {

class BankAccountBuilderFixture {
public:
    string name{"João"}, accountNumber{"123"}, agency{"0000-8"}, bank{"BB"};
    double balance{100};
    
    BankAccountBuilderFixture() {
        
    }
};
} // namespace

TEST_CASE_METHOD(BankAccountBuilderFixture, "BankAccountBuilder: Create a valid account", "[method]")
{
    BankAccountBuilder builder(name, balance, accountNumber, agency, bank);
    
    REQUIRE(builder.isValid());

    BankAccount * account = builder.build();

    REQUIRE(name == account->getName());
    REQUIRE(balance == account->getBalance());
    REQUIRE(accountNumber == account->getAccountNumber());
    REQUIRE(agency == account->getAgency());
    REQUIRE(bank == account->getBank());

    delete account;
}

TEST_CASE_METHOD(BankAccountBuilderFixture, "BankAccountBuilder: don't create a invalid account", "[method]")
{
    BankAccountBuilder builder(name, balance, accountNumber, agency, "");
    
    REQUIRE(!builder.isValid());
}

#endif
