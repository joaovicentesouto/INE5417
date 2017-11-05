#ifndef RELEASETYPEMAPPER_H
#define RELEASETYPEMAPPER_H

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

class ReleaseTypeMapper
{
public:
    ReleaseTypeMapper(QSqlDatabase & _conn);
    ~ReleaseTypeMapper();

private:
    QSqlDatabase & conn;
};

} // namespace

#endif // RELEASETYPEMAPPER_H
