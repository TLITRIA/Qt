#include "myvariant.h"

#include <QVariant>
#include <QDebug>
#include <QColor>

MyVariant::MyVariant() {
    QColor color = QColor(Qt::red);
    QString str = "hello";
    QVariant v1(15), v2(12.3), v3("nihao"), v4(color), v5(str);
    qDebug() << v1.toInt() << v2.toFloat() << v3.toString()
             << v4.value<QColor>();

    qDebug() << v5.canConvert(QVariant::Int)
             << v5.toString()
            << v5.convert(QVariant::Int)
             << v5.toString();





}
