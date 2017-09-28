//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "Report.h"

namespace project {

Report::Report(list<Account*> &_accounts) :
    accounts{_accounts}
{
    
}

Report::~Report() {

}

void Report::searchByReleasesType(list<string> &_releasesTypes) {
    releasesTypes = _releasesTypes;
    //...
}

void Report::searchByPaymentType(list<string> &_paymentTypes) {
    paymentTypes = _paymentTypes;
    //...
}

void Report::searchByDate(time_t _begin, time_t _end) {
    begin = _begin;
    end = _end;
    //...
}

void Report::searchByValue(double _lowerValue, double _upperValue) {
    lowerValue = _lowerValue;
    upperValue = _upperValue;
    //...
}

}  // namespace project
