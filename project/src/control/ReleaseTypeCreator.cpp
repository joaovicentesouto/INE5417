#include "ReleaseTypeCreator.h"

namespace project {

ReleaseTypeCreator::ReleaseTypeCreator(std::string _name) :
    name(_name)
{

}

ReleaseTypeCreator::~ReleaseTypeCreator() {
    
}

bool ReleaseTypeCreator::isValid() {
    return !name.empty();
}

std::string ReleaseTypeCreator::build() {
    if (!isValid())
        throw std::out_of_range("Os parâmetros para a criação não são validos!");
    return name;
}

}