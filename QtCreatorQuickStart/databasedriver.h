#ifndef DATABASEDRIVER_H
#define DATABASEDRIVER_H

#include <QSqlDatabase>

class DatabaseDriver
{
public:
    DatabaseDriver();

    // setter
    void InitDB(const QString& baseName = "",
                const QString& userName = "",
                const QString& userPsd = "",
                const QString& baseType = "QMYSQL",
                const QString& hostname = "127.0.0.1",
                const unsigned int& port = 3306);

    // getter
    QString getDBErrorStr();
    bool openDB();
private:
    QSqlDatabase db;
};

#endif // DATABASEDRIVER_H
