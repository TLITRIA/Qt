#include <QApplication>

#include <QDebug>
#include <QString>
#include "QtCreatorQuickStart/mydrawing.h"
#include "QtCreatorQuickStart/mytransformation.h"
#include "QtCreatorQuickStart/mydraw2.h"
#include "QtCreatorQuickStart/mydrawing3.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyDrawing3 w;
    w.show();

    return a.exec();
}
