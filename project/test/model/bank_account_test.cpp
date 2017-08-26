//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "bank_account_test.h"

using namespace project;

namespace
{
class BankAccountFixture
{
public:
  string name{"João"}, accountNumber{"123"}, agency{"0000-8"}, bank{"BB"};
  double balance{100};
  list<string> releases;

	BankAccountFixture()
  {
    releases.push_front("Água");
    releases.push_front("Comida");
    releases.push_front("Netflix");
	}
};
} // namespace

TEST_CASE_METHOD(BankAccountFixture, "BankAccount: Checking attributes after the construction", "[attribute]")
{
  BankAccount account(name, balance, accountNumber, agency, bank);

  REQUIRE(name == account.getName());
	REQUIRE(balance == account.getBalance());
  REQUIRE(accountNumber == account.getAccountNumber());
  REQUIRE(agency == account.getAgency());
  REQUIRE(bank == account.getBank());
}

TEST_CASE_METHOD(BankAccountFixture, "BankAccount: Changing name, number, agency and bank", "[attribute]")
{
  BankAccount account(name, balance, accountNumber, agency, bank);

	name = "Bruno";
  accountNumber = "456";
  agency = "1111-0";
  bank = "Caixa";

	account.changeName(name);
  account.changeAccountNumber(accountNumber);
  account.changeAgency(agency);
  account.changeBank(bank);

	REQUIRE(name == account.getName());
  REQUIRE(accountNumber == account.getAccountNumber());
  REQUIRE(agency == account.getAgency());
  REQUIRE(bank == account.getBank());
}

TEST_CASE_METHOD(BankAccountFixture, "BankAccount: Inserting releases", "[releases]")
{
  BankAccount account(name, balance, accountNumber, agency, bank);
  account.insertRelease("Água");
  account.insertRelease("Comida");
  account.insertRelease("Netflix");

	REQUIRE(releases == account.getReleases());
}

TEST_CASE_METHOD(BankAccountFixture, "BankAccount: Removing releases", "[releases]")
{
  BankAccount account(name, balance, accountNumber, agency, bank);
  account.insertRelease("Água");
  account.insertRelease("Comida");
  account.insertRelease("Netflix");

	releases.remove("Netflix");
	account.removeRelease("Netflix");

	REQUIRE(releases == account.getReleases());
}
