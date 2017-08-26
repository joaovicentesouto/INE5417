//! Copyright [2017] Bruno Bonotto and João Vicente Souto

#ifndef PROJECT_REPORT_H
#define PROJECT_REPORT_H

#include <string>
#include <list>
#include <ctime>

#include "account.h"
#include "release.h"

using namespace std;

namespace project {

class Report {
public:
  Report(list<Account*> &_accounts);
  ~Report();

  void searchByReleasesType(list<string> &_releasesTypes);
  void searchByPaymentType(list<string> &_paymentTypes);
  void searchByDate(time_t _begin, time_t _end);
  void searchByValue(double _lowerValue, double _upperValue);

private:
  time_t begin, end;
  double lowerValue, upperValue;
  list<Account*> accounts;        //!< Immutables
  list<Release*> releases;
  list<string> releasesTypes, paymentTypes;

};

}  // namespace project

#endif
