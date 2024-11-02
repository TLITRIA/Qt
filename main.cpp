#include "mainwindow.h"
#include "futext.h"
#include "mydragdrop.h"
#include "imagedragdrop.h"
#include "myevent.h"
#include "mymouseevent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMouseEvent w;
    w.show();
    return a.exec();
}
