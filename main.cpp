#include <QApplication>

#include <QDebug>
#include <QString>
#include "QtCreatorQuickStart/mydrawing.h"
#include "QtCreatorQuickStart/mytransformation.h"
#include "QtCreatorQuickStart/mydraw2.h"
#include "QtCreatorQuickStart/mydrawing3.h"
#include "QtCreatorQuickStart/mycomposition.h"
#include "QtCreatorQuickStart/mydoublebuffers.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyDoubleBuffers w;
    w.show();

    return a.exec();
}
