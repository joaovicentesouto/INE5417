#ifndef RELEASEBUILDER_H
#define RELEASEBUILDER_H

#include <string>
#include <stdexcept>

#include "./src/model/Release.h"
#include "./src/model/Account.h"

namespace project {

class ReleaseBuilder
{
public:
    ReleaseBuilder(double _value, Account* _account, string _releaseType,
                   string _paymentType, string _description, string operation, string _date);
    ~ReleaseBuilder();

    bool isValid();
    Release * build();

private:
    double value;
    Account* account;
    std::string releaseType, paymentType, description, operation, date;
};

}

#endif // RELEASEBUILDER_H
