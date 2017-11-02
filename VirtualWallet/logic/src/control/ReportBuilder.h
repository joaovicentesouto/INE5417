#ifndef REPORTBUILDER_H
#define REPORTBUILDER_H

#include "./src/model/Report.h"

namespace project {

using namespace std;

class ReportBuilder
{
public:
    ReportBuilder(list<Account*> &_accounts, list<string> &_releasesTypes, list<string> &_paymentTypes,
                  string _begin, string _end, double _lowerValue, double _upperValue, bool _in, bool _out);
    ~ReportBuilder();

    bool isValid();
    Report * build();

private:
    list<Account*> accounts;
    list<string> releasesTypes, paymentTypes;
    string begin, end;
    double lowerValue, upperValue;
    bool in, out;
};

} // namespace project


#endif // REPORTBUILDER_H
