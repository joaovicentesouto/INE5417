//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_USER_CREATOR_TEST_H
#define PROJECT_USER_CREATOR_TEST_H

#include <catch.hpp>
#include "../../src/control/UserCreator.h"
#include "../../src/model/User.h"

using namespace project;

namespace {

class UserCreatorFixture {
public:
    std::string name{"João"};
    std::string password{"1234"};

    UserCreatorFixture() {

    }
};
} // namespace

TEST_CASE_METHOD(UserCreatorFixture, "UserCreator: Create a valid user", "[method]")
{
    UserCreator creator(name, password);

    REQUIRE(creator.isValid());

    User * user = creator.build();

    REQUIRE(name == user->getName());
    REQUIRE(password == user->getPassword());

    delete user;
}

TEST_CASE_METHOD(UserCreatorFixture, "UserCreator: Create invalid user", "[method]")
{
    UserCreator creator(name, "");

    REQUIRE(!creator.isValid());
}

#endif
