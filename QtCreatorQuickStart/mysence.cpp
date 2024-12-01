#include "mysence.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>


MySence::MySence() {


    QGraphicsScene sence;
    QGraphicsRectItem* item = new QGraphicsRectItem(0, 0, 100, 100);
    sence.addItem(item);
    qDebug() << sence.itemAt(50, 50, QTransform());
}
