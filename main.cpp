#include "mainwindow.h"
#include "futext.h"
#include "mydragdrop.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyDragDrop w;
    w.show();
    return a.exec();
}
