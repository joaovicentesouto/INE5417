#include "BankAccountBuilder.h"

namespace project {

BankAccountBuilder::BankAccountBuilder(std::string _name, double _balance, std::string _accountNumber, std::string _agency, std::string _bank) :
    name(_name),
    balance(_balance),
    accountNumber(_accountNumber),
    agency(_agency),
    bank(_bank)
{

}

BankAccountBuilder::~BankAccountBuilder() {
    
}

bool BankAccountBuilder::isValid() {
    return !name.empty() && balance >= 0 && !accountNumber.empty() && !agency.empty() && !bank.empty();
}

BankAccount* BankAccountBuilder::build() {
    if (!isValid())
        throw std::out_of_range("Os parâmetros para a criação não são validos!");
    return new BankAccount(name, balance, accountNumber, agency, bank);
}

}  // namespace project