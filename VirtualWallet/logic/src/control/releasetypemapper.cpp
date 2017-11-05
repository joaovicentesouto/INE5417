#include "releasetypemapper.h"

namespace project {

ReleaseTypeMapper::ReleaseTypeMapper(QSqlDatabase & _conn) :
    conn(_conn)
{

}

ReleaseTypeMapper::~ReleaseTypeMapper()
{

}

} // namespace
