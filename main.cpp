#include <QApplication>

#include <QDebug>
#include <QString>
#include "QtCreatorQuickStart/myprocess.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyProcess w;
    w.resize(400, 300);
    w.show();

    return a.exec();
}
