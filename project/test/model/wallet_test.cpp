//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "wallet_test.h"

using namespace project;

namespace
{
class WalletFixture
{
public:
  string name{"João"};
  double balance{100};
  list<string> releases;

	WalletFixture()
  {
    releases.push_front("Água");
    releases.push_front("Comida");
    releases.push_front("Netflix");
	}
};
} // namespace

TEST_CASE_METHOD(WalletFixture, "Wallet: Checking attributes after the construction", "[attribute]")
{
  Wallet account(name, balance);

  REQUIRE(name == account.getName());
	REQUIRE(balance == account.getBalance());
}

TEST_CASE_METHOD(WalletFixture, "Wallet: Changing name", "[attribute]")
{
  Wallet account(name, balance);

	name = "Bruno";
	account.changeName(name);

	REQUIRE(name == account.getName());
}

TEST_CASE_METHOD(WalletFixture, "Wallet: Inserting releases", "[releases]")
{
  Wallet account(name, balance);
  account.insertRelease("Água");
  account.insertRelease("Comida");
  account.insertRelease("Netflix");

	REQUIRE(releases == account.getReleases());
}

TEST_CASE_METHOD(WalletFixture, "Wallet: Removing releases", "[releases]")
{
  Wallet account(name, balance);
  account.insertRelease("Água");
  account.insertRelease("Comida");
  account.insertRelease("Netflix");

	releases.remove("Netflix");
	account.removeRelease("Netflix");

	REQUIRE(releases == account.getReleases());
}
