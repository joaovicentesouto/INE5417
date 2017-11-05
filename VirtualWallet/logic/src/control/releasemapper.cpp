#include "releasemapper.h"

namespace project {

ReleaseMapper::ReleaseMapper(QSqlDatabase & _conn) :
    conn(_conn)
{

}

ReleaseMapper::~ReleaseMapper()
{

}

Release * ReleaseMapper::getById(int id)
{
    return nullptr;
}

list<Release*> ReleaseMapper::getAllReleases()
{
    return list<Release*>();
}

void ReleaseMapper::put(Release * release)
{

}

void ReleaseMapper::putExistUser(Release * release)
{

}

void ReleaseMapper::putNewUser(Release * release)
{

}

void ReleaseMapper::remove(int id)
{

}

} // namespace
