#include "databasedriver.h"

#include <QDebug>
#include <QStringList>
#include <QSqlError>

DatabaseDriver::DatabaseDriver() {
    qDebug() << QObject::tr("可用的数据库") << QSqlDatabase::drivers();
}

void DatabaseDriver::InitDB(const QString &baseName, const QString &userName, const QString &userPsd, const QString &baseType, const QString &hostname, const unsigned int &port)
{
    db = QSqlDatabase::addDatabase(baseType);
    db.setHostName(hostname);
    db.setPort(port);
    db.setDatabaseName(baseName);
    db.setUserName(userName);
    db.setPassword(userPsd);
}

QString DatabaseDriver::getDBErrorStr()
{
    return db.lastError().text();
}

bool DatabaseDriver::openDB()
{
    return db.open();
}
