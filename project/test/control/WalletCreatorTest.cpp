//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_WALLET_CREATOR_TEST_H
#define PROJECT_WALLET_CREATOR_TEST_H

#include <catch.hpp>
#include "../../src/model/Wallet.h"
#include "../../src/control/WalletCreator.h"


using namespace project;

namespace {

class WalletCreatorFixture {
public:
    string name{"João"};
    double balance{100};
    
    WalletCreatorFixture() {
        
    }
};
} // namespace

TEST_CASE_METHOD(WalletCreatorFixture, "WalletCreator: Create a valid wallet", "[method]")
{
    WalletCreator creator(name, balance);
    
    REQUIRE(creator.isValid());

    Wallet * account = creator.build();

    REQUIRE(name == account->getName());
    REQUIRE(balance == account->getBalance());

    delete account;
}

TEST_CASE_METHOD(WalletCreatorFixture, "WalletCreator: don't create a invalid wallet", "[method]")
{
    WalletCreator creator(name, -1);
    
    REQUIRE(!creator.isValid());
}

#endif
