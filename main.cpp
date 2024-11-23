#include <QApplication>

#include <QDebug>
#include <QString>
#include <QtCreatorQuickStart/databasedriver.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseDriver w;
    w.InitDB("", "", "");
    if(!w.openDB())
        qDebug() << w.getDBErrorStr();

    return a.exec();
}
