#include "releasemapper.h"

namespace project {

ReleaseMapper::ReleaseMapper(QSqlDatabase & _conn) :
    conn(_conn)
{

}

ReleaseMapper::~ReleaseMapper()
{

}

} // namespace
