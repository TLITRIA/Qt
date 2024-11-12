#include "mydrawing3.h"
#include "ui_mydrawing3.h"

#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QBitMap>
#include <QPicture>>


MyDrawing3::MyDrawing3(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyDrawing3)
{
    ui->setupUi(this);
}

MyDrawing3::~MyDrawing3()
{
    delete ui;
}

void MyDrawing3::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
#if 0
    QImage image(100, 100, QImage::Format_ARGB32);
    painter.begin(&image);
    painter.setPen(QPen(Qt::green, 3));
    painter.setBrush(Qt::yellow);
    painter.drawRect(10, 10, 60, 60);
    painter.drawText(10, 10, 60, 60, Qt::AlignCenter, tr("QImage"));
    painter.setBrush(QColor(0, 0, 0, 100));
    painter.drawRect(50, 50, 40, 40);
    painter.end();

    QPixmap pix(100, 100);
    painter.begin(&pix);
    painter.setPen(QPen(Qt::green, 3));
    painter.setBrush(Qt::yellow);
    painter.drawRect(10, 10, 60, 60);
    painter.drawText(10, 10, 60, 60, Qt::AlignCenter, tr("QPixmap"));
    painter.setBrush(QColor(0, 0, 0, 100));
    painter.drawRect(50, 50, 40, 40);
    painter.end();

    QBitmap bit(100, 100);
    painter.begin(&bit);
    painter.setPen(QPen(Qt::green, 3));
    painter.setBrush(Qt::yellow);
    painter.drawRect(10, 10, 60, 60);
    painter.drawText(10, 10, 60, 60, Qt::AlignCenter, tr("QBitmap"));
    painter.setBrush(QColor(0, 0, 0, 100));
    painter.drawRect(50, 50, 40, 40);
    painter.end();

    QPicture picture;
    painter.begin(&picture);
    painter.setPen(QPen(Qt::green, 3));
    painter.setBrush(Qt::yellow);
    painter.drawRect(10, 10, 60, 60);
    painter.drawText(10, 10, 60, 60, Qt::AlignCenter, tr("QPicture"));
    painter.setBrush(QColor(0, 0, 0, 100));
    painter.drawRect(50, 50, 40, 40);
    painter.end();

    painter.begin(this);
    painter.drawImage(50, 20, image);
    painter.drawPixmap(200, 20, pix);
    painter.drawPixmap(50, 170, bit);
    painter.drawPicture(200, 170, picture);
#endif


    QImage image;
    image.load("D:/Documents/QtCreatorQuick/QtCreatorQuickStart/image.png");
    qDebug() << image.size() << image.format() << image.depth();

    painter.drawImage(QPoint(10, 10), image);
    QImage mirror = image.mirrored();
    QTransform transform;
    transform.shear(0.2, 0);
    QImage image2 = mirror.transformed(transform);
    image2.save("../mirror.png");
}
