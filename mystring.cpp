#include "mystring.h"


#include <QString>
#include <QStringList>
#include <QDebug>

MyString::MyString() {}

void MyString::implicitSharing()
{
    /* 隐式共享 */
}

void MyString::edit()
{
    QString str = "hello";      qDebug() << str.size();
    str[0] = 'H';               qDebug() << str[0];
    str.append(" Qt");
    str.replace(1,4,"i");
    str.insert(2, " my");       qDebug() << str;
    str += "!!!";               qDebug() << str;
    str = "   hi\r\n Qt? \n  "; qDebug() << str;
    QString str1 = str.trimmed();       qDebug() << str1;
    QString str2 = str.simplified();    qDebug() << str2;
    str = "hi,my,,Qt";
    QStringList list = str.split(",", Qt::SkipEmptyParts);
                                qDebug() << list;
    str = list.join(" ");       qDebug() << str;
    qDebug() << QString().isNull();
    qDebug() << QString().isEmpty();
    qDebug() << QString("").isNull();
    qDebug() << QString("").isEmpty();
}

void MyString::find()
{
    QString str = "yafeilinux";
    qDebug() << str;
    qDebug() << str.right(5);
    qDebug() << str.left(5);
    qDebug() << str.mid(2, 3);
    qDebug() << str.indexOf("fei");
    qDebug() << str.count("i");
    qDebug() << str.startsWith("ya");
    qDebug() << str.endsWith("linux");
    qDebug() << str.contains("lin");
    qDebug() << (str < "hello");
}

void MyString::modify()
{
/*
 * QString::toXXX toUpper toLower
 * QString::number()
 * QString().arg()
 * str.arg(, )
 * qreal
 * qPrintable
*/
}
