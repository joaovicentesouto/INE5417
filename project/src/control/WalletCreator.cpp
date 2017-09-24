#include "WalletCreator.h"

namespace project {

WalletCreator::WalletCreator(std::string _name, double _balance) :
    name(_name),
    balance(_balance)
{

}

WalletCreator::~WalletCreator() {
    
}

bool WalletCreator::isValid() {
    return !name.empty() && balance >= 0;
}

Wallet* WalletCreator::build() {
    if (!isValid())
        throw std::out_of_range("Os parâmetros para a criação não são validos!");
    return new Wallet(name, balance);
}

}