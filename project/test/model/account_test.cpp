//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "account_test.h"
//#include "../../src/model/account.h"


using namespace project;

namespace {

class AccountFixture {
public:
	string name{"João"};
	double balance{100};
	list<string> releases;

	AccountFixture() {
    releases.push_front("Água");
    releases.push_front("Comida");
    releases.push_front("Netflix");
	}
};
} // namespace

TEST_CASE_METHOD(AccountFixture, "Account: Checking attributes after the construction", "[attribute]")
{
  Account account(name, balance);

  REQUIRE(name == account.getName());
	REQUIRE(balance == account.getBalance());
}

TEST_CASE_METHOD(AccountFixture, "Account: Changing name", "[attribute]")
{
  Account account(name, balance);

	name = "Bruno";
	account.changeName(name);

	REQUIRE(name == account.getName());
}

TEST_CASE_METHOD(AccountFixture, "Account: Inserting releases", "[releases]")
{
  Account account(name, balance);
  account.insertRelease("Água");
  account.insertRelease("Comida");
  account.insertRelease("Netflix");

	REQUIRE(releases == account.getReleases());
}

TEST_CASE_METHOD(AccountFixture, "Account: Removing releases", "[releases]")
{
  Account account(name, balance);
  account.insertRelease("Água");
  account.insertRelease("Comida");
  account.insertRelease("Netflix");

	releases.remove("Netflix");
	account.removeRelease("Netflix");

	REQUIRE(releases == account.getReleases());
}
