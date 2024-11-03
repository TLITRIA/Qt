#include "mainwindow.h"
#include "futext.h"
#include "mydragdrop.h"
#include "imagedragdrop.h"
#include "myevent.h"
#include "mymouseevent.h"
#include "mykeyevent.h"
#include "mytimerevent.h"
#include "myeventfilter.h"
#include "mysignalslot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySignalSlot w;
    w.show();
    return a.exec();
}
