#include <Spider/spiderwidget.h>
#include <Spider/spider.h>
#include <QApplication>

#include <QDebug>

#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
// #if 0
//     SpiderWidget w;
// #else
//     Spider spider;
//     if(!spider.Initialize())
//     {
//         qDebug() << "Initialize failed.\n";
//         return 0;
//     }
//     spider.Request();
// #endif

    Spider spider;
    spider.getMessageWithRE(spider.tempGetHtml());





    return a.exec();
}
