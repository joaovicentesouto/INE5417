//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "report_test.h"

using namespace project;

namespace {

class ReportFixture {
public:
  time_t begin{time(0)}, end{time(0)};
  double lowerValue{100}, upperValue{200};
  list<Account*> accounts;        //!< Immutables
  list<Release*> releases;
  list<string> releasesTypes, paymentTypes;

	ReportFixture() {
    accounts.push_front((new Account("João", 100)));
    accounts.push_front((new Account("Bruno", 200)));
	}

  ~ReportFixture() {
	}
};
} // namespace

TEST_CASE_METHOD(ReportFixture, "Report: mConstruction", "[attribute]")
{
  Report rep(accounts);

	REQUIRE(0 == 0);
}
