#include "releasetypemapper.h"

namespace project {

ReleaseTypeMapper::ReleaseTypeMapper(QSqlDatabase & _conn) :
    conn(_conn)
{

}

ReleaseTypeMapper::~ReleaseTypeMapper()
{

}

ReleaseType * ReleaseTypeMapper::getById(int id)
{
    return nullptr;
}

ReleaseType * ReleaseTypeMapper::getByName(string name)
{
    return nullptr;
}

list<ReleaseType*> ReleaseTypeMapper::getAllReleasesTypes()
{
    return list<ReleaseType*>();
}

void ReleaseTypeMapper::put(ReleaseType * releaseType)
{

}

void ReleaseTypeMapper::putExistUser(ReleaseType * releaseType)
{

}

void ReleaseTypeMapper::putNewUser(ReleaseType * releaseType)
{

}

void ReleaseTypeMapper::remove(int id)
{

}

} // namespace
