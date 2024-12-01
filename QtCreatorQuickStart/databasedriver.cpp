#include "databasedriver.h"

#include <QDebug>
#include <QStringList>
#include <QSqlError>

DatabaseDriver::DatabaseDriver() {
    // qDebug() << QObject::tr("可用的数据库") << QSqlDatabase::drivers();
}

void DatabaseDriver::InitDB(const QString &baseName, const QString &userName, const QString &userPsd,
                            const QString &baseType, const QString &hostname, const unsigned int &port,
                            const QString& connectionName)
{
    db = QSqlDatabase::addDatabase(baseType, connectionName); // 设置默认连接 是怎么得到qt_sql_default_connection的？
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
    bool ret = db.open();
    query = QSqlQuery(db);
    return ret;
}

bool DatabaseDriver::closeDB()
{
    db.close();
    QSqlDatabase::removeDatabase(db.databaseName());
    return !db.isOpen();
}
