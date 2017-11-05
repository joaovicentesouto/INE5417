#ifndef USERMAPPER_H
#define USERMAPPER_H

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

class UserMapper
{
public:
    UserMapper(QSqlDatabase & _conn);
    ~UserMapper();

private:
    QSqlDatabase & conn;
};

} // namespace

#endif // USERMAPPER_H
