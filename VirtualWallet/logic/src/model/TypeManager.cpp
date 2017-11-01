//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "TypeManager.h"

using namespace std;

namespace project {

TypeManager::TypeManager() {
    // Add default types
    // Payment Types don't change
    paymentTypes.push_front("Dinheiro");
    paymentTypes.push_front("Crédito");
    paymentTypes.push_front("Débito");
    paymentTypes.push_front("Cheque");
    paymentTypes.push_front("Outros");

    // Release Types possible change
    releaseTypes.push_front("Água");
    releaseTypes.push_front("Energia");
    releaseTypes.push_front("Internet");
    releaseTypes.push_front("Transporte");
    releaseTypes.push_front("Alimentação");
}

TypeManager::~TypeManager() {

}

list<string> TypeManager::getReleaseTypes() {
  return releaseTypes;
}

list<string> TypeManager::getPaymentTypes() {
  return paymentTypes;
}

bool TypeManager::addReleaseType(string _type) {
    for (list<string>::iterator it = releaseTypes.begin(); it != releaseTypes.end(); it++)
        if (!it->compare(_type))
            return false;

    releaseTypes.push_front(_type);
    return true;
}

void TypeManager::deleteReleaseType(string _type) {
    releaseTypes.remove(_type);
}

void TypeManager::changeReleaseType(string _old, string _new) {
    releaseTypes.remove(_old);
    releaseTypes.push_front(_new);
}

}  // namespace project
