//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_USER_TEST_H
#define PROJECT_USER_TEST_H

#include <catch.hpp>
#include "../../src/model/User.h"

#include "../../src/model/BankAccount.h"
#include "../../src/model/Wallet.h"

using namespace project;

namespace {

class UserFixture {
public:
    string name{"João"};
    string password{"1234"};
    list<Account*> accounts;

    UserFixture() {

    }
};
} // namespace

TEST_CASE_METHOD(UserFixture, "User: Checking attributes after the construction", "[attribute]")
{
    User user(name, password);

    REQUIRE(name == user.getName());
    REQUIRE(password == user.getPassword());
}

TEST_CASE_METHOD(UserFixture, "User: Changing name", "[attribute]")
{
    User user(name, password);

    name = "Bruno";
    user.changeName(name);

    REQUIRE(name == user.getName());
}

TEST_CASE_METHOD(UserFixture, "User: Inserting bank accounts", "[user]")
{
    User user(name, password);

    BankAccount one("João", 100);
    BankAccount two("Bruno", 200);
    BankAccount three("Fabiola", 300);

    accounts.push_front(&one);
    accounts.push_front(&two);
    accounts.push_front(&three);

    user.insertAccount(one);
    user.insertAccount(two);
    user.insertAccount(three);

    REQUIRE(accounts == user.getAccounts());
}

TEST_CASE_METHOD(UserFixture, "User: Removing bank accounts", "[user]")
{
    User user(name, password);

    BankAccount one("João", 100);
    BankAccount two("Bruno", 200);
    BankAccount three("Fabiola", 300);

    accounts.push_front(&one);
    accounts.push_front(&two);
    accounts.push_front(&three);

    user.insertAccount(one);
    user.insertAccount(two);
    user.insertAccount(three);

    accounts.remove(&three);
    user.removeAccount(three);

    REQUIRE(accounts == user.getAccounts());
}

TEST_CASE_METHOD(UserFixture, "User: Inserting Wallet accounts", "[user]")
{
    User user(name, password);

    Wallet one("João", 100);
    Wallet two("Bruno", 200);
    Wallet three("Fabiola", 300);

    accounts.push_front(&one);
    accounts.push_front(&two);
    accounts.push_front(&three);

    user.insertAccount(one);
    user.insertAccount(two);
    user.insertAccount(three);

    REQUIRE(accounts == user.getAccounts());
}

TEST_CASE_METHOD(UserFixture, "User: Removing Wallet accounts", "[user]")
{
    User user(name, password);

    Wallet one("João", 100);
    Wallet two("Bruno", 200);
    Wallet three("Fabiola", 300);

    accounts.push_front(&one);
    accounts.push_front(&two);
    accounts.push_front(&three);

    user.insertAccount(one);
    user.insertAccount(two);
    user.insertAccount(three);

    accounts.remove(&three);
    user.removeAccount(three);

    REQUIRE(accounts == user.getAccounts());
}

#endif
