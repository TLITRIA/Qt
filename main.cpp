#include "mainwindow.h"
#include "futext.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FuText w;
    w.show();
    return a.exec();
}
