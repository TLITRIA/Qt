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
#include "mysignalslot2.h"
#include "myproperty.h"
#include "myownership.h"
#include "mycontainers.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyContainers w;
    w.myalgorithm();
    // w.show();
    // return a.exec();
    return 0;
}
