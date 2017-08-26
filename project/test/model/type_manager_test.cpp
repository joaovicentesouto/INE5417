//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "type_manager_test.h"

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

    releaseTypes.push_front("Água");
    releaseTypes.push_front("Comida");
    releaseTypes.push_front("Transporte");
	}

};
} // namespace

TEST_CASE_METHOD(TypeManagerFixture, "Type Manager: Construction", "[attribute]")
{
  TypeManager manager = TypeManager();

	REQUIRE(0 == 0);
}
