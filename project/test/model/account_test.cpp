//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "account_test.h"
//#include "../../src/model/account.h"


using namespace project;

namespace
{
class AccountFixture
{
public:
  double balance{0.0};
  string name;
  vector<string> releases;

	AccountFixture()
    : balance(100),
      name("João")
  {
    releases.push_back("Água");
    releases.push_back("Comida");
    releases.push_back("Netflix");
	}
};
} // namespace

TEST_CASE_METHOD(AccountFixture, "Test: a", "[attribute]")
{
  Account conta("João");
  REQUIRE(0 == conta.test());
}
