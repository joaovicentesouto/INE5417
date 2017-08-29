//! Copyright [2017] Bruno Bonotto and João Vicente Souto
#include "type_manager.h"

using namespace std;

namespace project {

TypeManager::TypeManager() {
    // Add default types
    // Payment Types don't change
    paymentTypes.push_front("Dinheiro");
    paymentTypes.push_front("Crédito");
    paymentTypes.push_front("Débito");
    paymentTypes.push_front("Cheque");
    
    // Release Types possible change
    releaseTypes.push_front("Água");
    releaseTypes.push_front("Comida");
    releaseTypes.push_front("Transporte");
}

TypeManager::~TypeManager() {

}

void TypeManager::addReleaseType(string _type) {
    releaseTypes.push_front(_type);
}

void TypeManager::deleteReleaseType(string _type) {
    releaseTypes.remove(_type);
}

void TypeManager::changeReleaseType(string _old, string _new) {
    releaseTypes.remove(_old);
    releaseTypes.push_front(_new);
}
    
}  // namespace project
