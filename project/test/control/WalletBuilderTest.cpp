//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_WALLET_BUILDER_TEST_H
#define PROJECT_WALLET_BUILDER_TEST_H

#include <catch.hpp>
#include "../../src/model/Wallet.h"
#include "../../src/control/WalletBuilder.h"


using namespace project;

namespace {

class WalletBuilderFixture {
public:
    string name{"João"};
    double balance{100};
    
    WalletBuilderFixture() {
        
    }
};
} // namespace

TEST_CASE_METHOD(WalletBuilderFixture, "WalletBuilder: Create a valid wallet", "[method]")
{
    WalletBuilder builder(name, balance);
    
    REQUIRE(builder.isValid());

    Wallet * account = builder.build();

    REQUIRE(name == account->getName());
    REQUIRE(balance == account->getBalance());

    delete account;
}

TEST_CASE_METHOD(WalletBuilderFixture, "WalletBuilder: don't create a invalid wallet", "[method]")
{
    WalletBuilder builder(name, -1);
    
    REQUIRE(!builder.isValid());
}

#endif
