//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_RELEASE_TYPE_CREATOR_TEST_H
#define PROJECT_RELEASE_TYPE_CREATOR_TEST_H

#include <catch.hpp>
#include <string>
#include "../../src/control/ReleaseTypeCreator.h"

using namespace project;

namespace {

class ReleaseTypeCreatorFixture {
public:
    std::string type{"João"};
    
    ReleaseTypeCreatorFixture() {
        
    }
};
} // namespace

TEST_CASE_METHOD(ReleaseTypeCreatorFixture, "ReleaseTypeCreator: Create a valid type", "[method]")
{
    ReleaseTypeCreator creator(type);
    
    REQUIRE(creator.isValid());

    std::string new_type = creator.build();

    REQUIRE(type == new_type);
}

TEST_CASE_METHOD(ReleaseTypeCreatorFixture, "ReleaseTypeCreator: don't create a invalid type", "[method]")
{
    ReleaseTypeCreator creator("");
    
    REQUIRE(!creator.isValid());
}

#endif
