#include "mainwindow.h"
#include "futext.h"
#include "mydragdrop.h"
#include "imagedragdrop.h".h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageDragDrop w;
    w.show();
    return a.exec();
}
