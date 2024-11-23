#include "databasedriver.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>

DatabaseDriver::DatabaseDriver() {
    qDebug() << QObject::tr("可用的数据库");
    QStringList drivers = QSqlDatabase::drivers();
    foreach (QString driver, drivers) {
        qDebug() << driver;
    }
}
