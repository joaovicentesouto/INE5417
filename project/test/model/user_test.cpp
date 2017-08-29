//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_USER_TEST_H
#define PROJECT_ACCOUNT_TEST_H

#include <catch.hpp>
#include "../../src/model/user.h"
#include "../../src/model/account.h"

using namespace project;

namespace {

class UserFixture {
public:
    string name{"João"};
    string password{"1234"};
    list<Account*> accounts;
    
    AccountFixture() {
        
    }
};
} // namespace

TEST_CASE_METHOD(AccountFixture, "User: Checking attributes after the construction", "[attribute]")
{
    User user(name, password);
    
    REQUIRE(name == user.getName());
    REQUIRE(password == user.getPassword());
}

TEST_CASE_METHOD(AccountFixture, "User: Changing name", "[attribute]")
{
    User user(name, password);
    
    name = "Bruno";
    user.changeName(name);
    
    REQUIRE(name == user.getName());
}

TEST_CASE_METHOD(AccountFixture, "User: Inserting accounts", "[user]")
{
    User user(name, password);
    
    Account one("João", 100);
    Account two("Bruno", 200);
    Account three("Fabiola", 300);
    
    accounts.push_front(&one);
    accounts.push_front(&two);
    accounts.push_front(&three);
    
    user.insertRelease(one);
    user.insertRelease(two);
    user.insertRelease(three);
    
    REQUIRE(accounts == user.getReleases());
}

TEST_CASE_METHOD(AccountFixture, "User: Removing accounts", "[user]")
{
    User user(name, password);
    
    Account one("João", 100);
    Account two("Bruno", 200);
    Account three("Fabiola", 300);
    
    accounts.push_front(&one);
    accounts.push_front(&two);
    accounts.push_front(&three);
    
    user.insertRelease(one);
    user.insertRelease(two);
    user.insertRelease(three);
    
    accounts.remove(&three);
    user.removeRelease(three);
    
    REQUIRE(accounts == user.getReleases());
}

#endif
