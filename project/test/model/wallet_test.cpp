//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "wallet_test.h"

using namespace project;

namespace
{
class WalletFixture
{
public:
  double balance{0.0};
  string name;
  vector<string> releases;

	WalletFixture()
    : balance(100),
      name("João")
  {
    releases.push_back("Água");
    releases.push_back("Comida");
    releases.push_back("Netflix");
	}
};
} // namespace

TEST_CASE_METHOD(WalletFixture, "Test: w", "[attribute]")
{
  Wallet conta("João");
  REQUIRE(0 == conta.test());
}
