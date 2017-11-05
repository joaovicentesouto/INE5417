#ifndef RELEASEMAPPER_H
#define RELEASEMAPPER_H

#include <QDebug>
#include <QDir>
#include <QtSql>
#include <QSqlDriver>
#include <qsqldatabase.h>
#include <QSqlError>
#include <QPluginLoader>

#include <string>
#include <list>

#include "src/model/Release.h"
#include "src/model/releasetype.h"
#include "src/control/releasetypemapper.h"

namespace project {

class ReleaseMapper
{
public:
    ReleaseMapper(QSqlDatabase & _conn);
    ~ReleaseMapper();

    Release * getById(int id);
    list<Release*> getAllReleases();

    void put(Release * release);
    void remove(int id);

private:
    void putExistUser(Release * release);
    void putNewUser(Release * release);

    QSqlDatabase & conn;
    ReleaseTypeMapper releaseTypeMapper;
};

} // namespace

#endif // RELEASEMAPPER_H
