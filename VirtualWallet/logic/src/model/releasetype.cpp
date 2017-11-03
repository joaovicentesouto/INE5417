#include "releasetype.h"

namespace project {

ReleaseType::ReleaseType()
{

}
ReleaseType::ReleaseType(string _name, int _id):
    name(_name),
    id(_id)
{

}

ReleaseType::~ReleaseType()
{

}

void ReleaseType::setId(int _id)
{
    id = _id;
}

int ReleaseType::getId()
{
    return id;
}

void ReleaseType::setTypeName(string _typeName)
{
    typeName = _typeName;
}

string ReleaseType::getName()
{
    return typeName;
}

}  // namespace
