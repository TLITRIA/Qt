#include "mycontainers.h"
#include <QDebug>
#include <QList>
#include <QMap>
#include <QMultiMap>

MyContainers::MyContainers() {}

void MyContainers::qlist()
{
    QList <QString> list;

    list << "aa" << "bb" << "cc";
    if(list[1] == "bb") list[1] = "ab";
    list.replace(2, "bc");
    qDebug() << "the list is:";
    for(int i = 0; i < list.size(); i++)
    {
        qDebug() << list[i]; // aa ab bc
    }

    list.append("dd");
    list.prepend("mm");
    QString str = list.takeAt(2);
    qDebug() << "at(2) item is" << str;
    qDebug() << "the list is:";
    for(int i = 0; i < list.size(); i++)
    {
        qDebug() << list[i]; // mm aa bc dd
    }

    list.insert(2, "mm");
    list[1].swap(list[3]); // qt版本
    qDebug() << "the list is:";
    for(int i = 0; i < list.size(); i++)
    {
        qDebug() << list[i]; // mm bc mm aa dd
    }

    qDebug() << "contain mm" << list.contains("mm");
    qDebug() << "mm count" << list.count("mm");
    qDebug() << "the first mm" << list.indexOf("mm");
    qDebug() << "the second mm" << list.indexOf("mm", 1);
}

void MyContainers::qmap()
{
    QMap <QString, int> map;
    map["one"] = 1;
    map["there"] = 3;
    map.insert("seven", 7);

    // 【】获取值时，如果没有就会自动插入
    qDebug() << "six:" << (int)map["six"];
    qDebug() << "contain six:" << map.contains("six");
    // value获取值时，如果没有不会自动插入
    qDebug() << "five:" << (int)map.value("five");
    qDebug() << "contain five:" << map.contains("five");
    qDebug() << "nine:" << (int)map.value("nine", 9);
    map.insert("ten", 10);
    map.insert("ten", 100);
    qDebug() << "ten:" << (int)map.value("ten");
    // map.insertMulti("two", 2); 高版本删除
    // map.insertMulti("two", 2);
    QMultiMap <QString, int> map1, map2, map3;
    map1.insert("values", 1);
    map1.insert("values", 2);
    map2.insert("values", 3);
    map3 = map1 + map2; // QMultiMap实现一键多值
    qDebug() << "the values are:" << map3.values("values");

}
