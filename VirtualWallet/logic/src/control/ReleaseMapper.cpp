#include "ReleaseMapper.h"

ReleaseMapper::ReleaseMapper(mysqlpp::Connection & _conn) :
    conn(_conn)
{

}

ReleaseMapper::~ReleaseMapper()
{

}

void ReleaseMapper::put(Release * release)
{

}

void ReleaseMapper::putNew(Release * release)
{

}

void ReleaseMapper::putUpdate(Release * release)
{

}

Release * ReleaseMapper::get(std::string nomeChavePrimaria)
{

}

void ReleaseMapper::remove(std::string nomeChavePrimaria)
{

}
