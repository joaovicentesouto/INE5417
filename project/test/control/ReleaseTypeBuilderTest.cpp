//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_RELEASE_TYPE_BUILDER_TEST_H
#define PROJECT_RELEASE_TYPE_BUILDER_TEST_H

#include <catch.hpp>
#include <string>
#include "../../src/control/ReleaseTypeBuilder.h"

using namespace project;

namespace {

class ReleaseTypeBuilderFixture {
public:
    std::string type{"João"};
    
    ReleaseTypeBuilderFixture() {
        
    }
};
} // namespace

TEST_CASE_METHOD(ReleaseTypeBuilderFixture, "ReleaseTypeBuilder: Create a valid type", "[method]")
{
    ReleaseTypeBuilder builder(type);
    
    REQUIRE(builder.isValid());

    std::string new_type = builder.build();

    REQUIRE(type == new_type);
}

TEST_CASE_METHOD(ReleaseTypeBuilderFixture, "ReleaseTypeBuilder: don't create a invalid type", "[method]")
{
    ReleaseTypeBuilder builder("");
    
    REQUIRE(!builder.isValid());
}

#endif
