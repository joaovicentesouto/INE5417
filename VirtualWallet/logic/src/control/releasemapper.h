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

namespace project {

class ReleaseMapper
{
public:
    ReleaseMapper(QSqlDatabase & _conn);
    ~ReleaseMapper();

private:
    QSqlDatabase & conn;
};

} // namespace

#endif // RELEASEMAPPER_H
