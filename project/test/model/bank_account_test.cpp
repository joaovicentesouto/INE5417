//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "bank_account_test.h"

using namespace project;

namespace
{
class BankAccountFixture
{
public:
  double balance{0.0};
  string name, account_number, agency, bank;
  vector<string> releases;

	BankAccountFixture()
    : balance(100),
      name("João"),
      account_number("123"),
      agency("4455-6"),
      bank("BB")
  {
    releases.push_back("Água");
    releases.push_back("Comida");
    releases.push_back("Netflix");
	}
};
} // namespace

TEST_CASE_METHOD(BankAccountFixture, "Test: b", "[attribute]")
{
  BankAccount conta("João");
  REQUIRE(0 == conta.test());
}
