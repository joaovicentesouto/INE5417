//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#ifndef PROJECT_TYPE_MANAGER_TEST_H
#define PROJECT_TYPE_MANAGER_TEST_H

#include <catch.hpp>
#include "../../src/model/type_manager.h"

using namespace project;

namespace {

class TypeManagerFixture {
public:
    list<string> releaseTypes, paymentTypes;

    TypeManagerFixture() {
      paymentTypes.push_front("Dinheiro");
      paymentTypes.push_front("Crédito");
      paymentTypes.push_front("Débito");
      paymentTypes.push_front("Cheque");
      paymentTypes.push_front("Outros");

      releaseTypes.push_front("Água");
      releaseTypes.push_front("Energia");
      releaseTypes.push_front("Internet");
      releaseTypes.push_front("Transporte");
      releaseTypes.push_front("Alimentação");
    }

};
} // namespace

TEST_CASE_METHOD(TypeManagerFixture, "Type Manager: Construction", "[attribute]")
{
    TypeManager manager = TypeManager();

    REQUIRE(releaseTypes == manager.getReleaseTypes());
    REQUIRE(paymentTypes == manager.getPaymentTypes());
}

TEST_CASE_METHOD(TypeManagerFixture, "Type Manager: Inserting release types", "[attribute]")
{
    TypeManager manager = TypeManager();
    manager.addReleaseType("Teste");
    releaseTypes.push_front("Teste");

    REQUIRE(releaseTypes == manager.getReleaseTypes());
}

TEST_CASE_METHOD(TypeManagerFixture, "Type Manager: Removing release types", "[attribute]")
{
    TypeManager manager = TypeManager();
    manager.deleteReleaseType("Energia");
    releaseTypes.remove("Energia");

    REQUIRE(releaseTypes == manager.getReleaseTypes());
}

TEST_CASE_METHOD(TypeManagerFixture, "Type Manager: Changing release types", "[attribute]")
{
    TypeManager manager = TypeManager();
    manager.changeReleaseType("Energia", "Teste");
    releaseTypes.remove("Energia");
    releaseTypes.push_front("Teste");

    REQUIRE(releaseTypes == manager.getReleaseTypes());
}

#endif
