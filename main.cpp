#include <QApplication>

#include <QDebug>
#include <QString>
#include "QtCreatorQuickStart/mydrawing.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyDrawing w;
    w.show();

    return a.exec();
}
