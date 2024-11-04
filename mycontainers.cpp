#include "mycontainers.h"
#include <QDebug>
#include <QList>
#include <QMap>
#include <QMultiMap>

#include <QListIterator>
#include <QMutableListIterator>
#include <QMapIterator>
#include <QMutableMapIterator>


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

void MyContainers::iterator_1()
{
    QList<QString> list;
    list << "A" << "B" << "C" << "D";
    QListIterator<QString> i(list);
    qDebug() << "the forwardis :";
    while(i.hasNext())
        qDebug() << i.next();
    qDebug() << "the backwardis :";
    while(i.hasPrevious())
        qDebug() << i.previous();

    QMutableListIterator<QString> j(list);
    j.toBack();
    while(j.hasPrevious())
    {
        QString str = j.previous();
        if(str == "B")
            j.remove();
    }
    j.insert("Q");
    j.toBack();
    if(j.hasPrevious())
        j.previous() = "N";
    j.previous();
    j.setValue("M");
    j.toFront();
    qDebug() << "the forward is:";
    while(j.hasNext())
        qDebug() << j.next();
}

void MyContainers::iterator_2()
{
    QMap<QString, QString> map;
    map.insert("Paries", "France");
    map.insert("Guatemala City", "Guatemala");
    map.insert("Mexico City", "Mexico");
    map.insert("Moscow", "Russia");
    QMapIterator<QString, QString> i(map);
    while(i.hasNext())
    {
        i.next();
        qDebug() << i.key() << ":" << i.value();
    }
    if(i.findPrevious("Mexico"))
        qDebug() << "find Mexico";
    QMutableMapIterator<QString, QString> j(map);
    while(j.hasNext())
    {
        if(j.next().key().endsWith("City"))
            j.remove();
    }
    while(j.hasPrevious())
    {
        j.previous();
        qDebug() << j.key() << ":" << j.value();
    }
}

void MyContainers::iterator_3()
{
    QList<QString> list;
    list << "A" << "B" << "C" << "D";
    QList<QString>::iterator i;
    qDebug() << "the forward is:";
    for(i = list.begin(); i!=list.end(); i++)
    {
        *i = (*i).toLower();
        qDebug() << *i;
    }
    qDebug() << "the backwards is:";
    while(i != list.begin())
    {
        --i;
        qDebug() << *i;
    }

    QList<QString>::const_iterator j;
    qDebug() << "the forward is:";
    for(j = list.constBegin(); j!=list.constEnd(); ++j)
    {
        qDebug() << *j;
    }

    QMap<QString, int> map;
    map.insert("one", 1);
    map.insert("two", 2);
    map.insert("three", 3);
    QMap<QString, int>::const_iterator p;
    qDebug() << "the forward is:";
    for(p = map.constBegin(); p!=map.constEnd(); ++p)
    {
        qDebug() << p.key() << ":" << p.value();
    }
}

void MyContainers::myforeach()
{
    QList<QString> list;
    list.insert(0, "A");
    list.insert(1, "B");
    list.insert(2, "C");
    qDebug() << "the list is:";
    foreach(QString str, list)
        qDebug() << str;

    QMap<QString, int> map;
    map.insert("first", 1);
    map.insert("second", 2);
    map.insert("third", 3);
    qDebug() << "the map is:";
    foreach(QString str, map.keys())
        qDebug() << str << ":" << map.value(str);

    QMultiMap<QString, int> map2;
    map2.insert("first", 1);
    map2.insert("first", 2);
    map2.insert("first", 3);
    map2.insert("second", 2);
    qDebug() << "the map2 is:";
    QList<QString> keys = map2.uniqueKeys();
    foreach(QString str, keys)
        foreach(int i, map2.values(str))
            qDebug() << str << ":" << i;
}
