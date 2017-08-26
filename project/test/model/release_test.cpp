//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "release_test.h"

using namespace project;

namespace
{
class ReleaseFixture
{
public:
  size_t id{0};
  double value{100};
  Account account{"João", 100};
  string typeRelease{"Água"}, typePayment{"Cartão"}, description{"Teste"};
  time_t date{time(0)};

};
} // namespace

TEST_CASE_METHOD(ReleaseFixture, "Attributes after construction", "[attribute]")
{
  Release rel(value, account, typeRelease, typePayment, description, date);

  REQUIRE(value == rel.getValue());
  REQUIRE(&account == &(rel.getAccount()));
  REQUIRE(typeRelease == rel.getReleaseType());
  REQUIRE(typePayment == rel.getPaymentType());
  REQUIRE(description == rel.getDescription());
  REQUIRE(date == rel.getDate());
}

TEST_CASE_METHOD(ReleaseFixture, "Changes", "[attribute]")
{
  Release rel(value, account, typeRelease, typePayment, description, date);

  value = 200;
  Account newAccount("Bruno", 200);
  typeRelease = "Netflix";
  typePayment = "Boleto";
  description = "Outro teste";
  date = time(0);

  rel.changeValue(value);
  rel.changeAccount(newAccount);
  rel.changeReleaseType(typeRelease);
  rel.changePaymentType(typePayment);
  rel.changeDescription(description);
  rel.changeDate(date);

  REQUIRE(value == rel.getValue());
  REQUIRE(&newAccount == &(rel.getAccount()));
  REQUIRE(typeRelease == rel.getReleaseType());
  REQUIRE(typePayment == rel.getPaymentType());
  REQUIRE(description == rel.getDescription());
  REQUIRE(date == rel.getDate());
}
