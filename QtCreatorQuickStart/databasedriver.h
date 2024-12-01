#ifndef DATABASEDRIVER_H
#define DATABASEDRIVER_H

#include <QSqlDatabase>
#include <QSqlQuery>

class DatabaseDriver
{
public:
    DatabaseDriver();

    void InitDB(const QString& baseName = "",
                const QString& userName = "",
                const QString& userPsd = "",
                const QString& baseType = "QMYSQL",
                const QString& hostname = "127.0.0.1",
                const unsigned int& port = 3306,
                const QString& connectionName = QLatin1StringView(QSqlDatabase::defaultConnection));
    QString getDBErrorStr();

    bool openDB();
    bool closeDB();

    bool exec(const QString& sql);
private:
    QSqlDatabase db;
    QSqlQuery query;
};

#endif // DATABASEDRIVER_H
