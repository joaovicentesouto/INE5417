#include "ReleaseTypeBuilder.h"

namespace project {

ReleaseTypeBuilder::ReleaseTypeBuilder(std::string _name) :
    name(_name)
{

}

ReleaseTypeBuilder::~ReleaseTypeBuilder() {
    
}

bool ReleaseTypeBuilder::isValid() {
    return !name.empty();
}

std::string ReleaseTypeBuilder::build() {
    if (!isValid())
        throw std::out_of_range("Os parâmetros para a criação não são validos!");
    return name;
}

}