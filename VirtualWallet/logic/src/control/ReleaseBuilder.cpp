#include "ReleaseBuilder.h"

namespace project {

ReleaseBuilder::ReleaseBuilder(double _value, Account* _account, string _releaseType,
                               string _paymentType, string _description, string _operation, string _date) :
    value(_value),
    account(_account),
    releaseType(_releaseType),
    paymentType(_paymentType),
    description(_description),
    operation(_operation),
    date(_date)
{

}

ReleaseBuilder::~ReleaseBuilder()
{

}

bool ReleaseBuilder::isValid()
{
    return (account != nullptr) && !date.empty() &&
           !releaseType.empty() && (releaseType != "Tipo de Lancamento") &&
           !paymentType.empty() && (paymentType != "Tipo de Pagamento") &&
           ((operation == "in") || (operation == "out"));
}

Release * ReleaseBuilder::build()
{
    if (!isValid())
        throw std::out_of_range("Os parâmetros para a criação não são validos!");
    return new Release(value, account, releaseType, paymentType, description, operation, date);
}

}
