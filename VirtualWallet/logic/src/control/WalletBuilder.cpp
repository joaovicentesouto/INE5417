#include "WalletBuilder.h"

namespace project {

WalletBuilder::WalletBuilder(int _id, std::string _name, double _balance) :
    id(_id),
    name(_name),
    balance(_balance)
{

}

WalletBuilder::~WalletBuilder() {
    
}

bool WalletBuilder::isValid() {
    return !name.empty() && balance >= 0;
}

Wallet* WalletBuilder::build() {
    if (!isValid())
        throw std::out_of_range("Os parâmetros para a criação não são validos!");
    return new Wallet(id, name, balance);
}

}
