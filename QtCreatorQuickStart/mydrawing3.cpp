#include "mydrawing3.h"
#include "ui_mydrawing3.h"

#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QBitMap>
#include <QPicture>

#include <QLabel>
#include <QWindow>
#include <QScreen>


MyDrawing3::MyDrawing3(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyDrawing3)
{
    ui->setupUi(this);
#if 0
    // 截图
    QWindow window;
    QPixmap grab =  window.screen()->grabWindow();
    grab.save("../QtCreatorQuickStart/mydrawing/screen.png");
    QLabel *label = new QLabel(this);
    label->resize(400, 200);
    QPixmap pix = grab.scaled(label->size(), Qt::KeepAspectRatio,
                              Qt::SmoothTransformation);
    label->setPixmap(pix);
    label->move(0, 100);
#endif
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

#if 0
    QImage image;
    image.load("../QtCreatorQuickStart/myimages/image.png");
    qDebug() << image.size() << image.format() << image.depth();

    painter.drawImage(QPoint(10, 10), image);
    QImage mirror = image.mirrored();
    QTransform transform;
    transform.shear(0.2, 0);
    QImage image2 = mirror.transformed(transform);
    image2.save("../QtCreatorQuickStart/mydrawing/mirror.png");
#endif
#if 0
    QPixmap pix;
    pix.load("../QtCreatorQuickStart/mydrawing/yafeilinux.png");
    painter.drawPixmap(0, 0, pix.width(), pix.height(), pix);
    painter.setBrush(QColor(255, 255, 255, 100));
    painter.drawRect(0, 0, pix.width(), pix.height());
    painter.drawPixmap(100, 0, pix.width(), pix.height(), pix);
    painter.setBrush(QColor(0, 0, 255, 100));
    painter.drawRect(100, 0, pix.width(), pix.height());
#endif

#if 0 // QPicture
    QPicture picture;
    painter.begin(&picture);
    painter.drawEllipse(10, 20, 80, 70);
    painter.end();
    picture.save("../QtCreatorQuickStart/mydrawing/drawing.pic");
#else
    QPicture picture;
    qDebug() << picture.load("../QtCreatorQuickStart/mydrawing/drawing.pic");
    painter.drawPicture(0, 0, picture);
#endif
}
