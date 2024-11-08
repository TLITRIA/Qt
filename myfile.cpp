#include "myfile.h"

#include <QFileInfo>
#include <QStringList>
#include <QDateTime>
#include <QDebug>

MyFile::MyFile() {
    QFile file("myfile.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << file.errorString();
    file.write("hello\nyafeillinux");
    file.close();

    QFileInfo info(file);
    qDebug() << info.absoluteFilePath()
             << info.fileName()
             << info.baseName()
             << info.suffix()
             << info.birthTime()
             << info.size();
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << file.errorString();
    qDebug() << file.readAll() << file.pos();

    file.seek(0);
    QByteArray array;
    array = file.read(5);
    qDebug() << array << file.pos();
    file.seek(15);
    array = file.read(5);
    qDebug() << array;
    file.close();
}
