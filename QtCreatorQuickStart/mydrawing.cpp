#include "mydrawing.h"
#include "ui_mydrawing.h"

#include <QPainter>

MyDrawing::MyDrawing(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyDrawing)
{
    ui->setupUi(this);
}

MyDrawing::~MyDrawing()
{
    delete ui;
}

void MyDrawing::paintEvent(QPaintEvent *event)
{
    QPainter painter(this); // 必须指定绘图设备
    // painter.begin(this); painter会自动调用begin end
    painter.drawLine(QPoint(0,0), QPoint(100,100));
    // painter.end();

    QPen pen(Qt::green, 5, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
    /*        画刷    线宽  画笔风格    画笔端点风格  画笔连接风格    */
    painter.setPen(pen);
    QRectF rectangle(70.0, 40.0, 80.0, 60.0);
    int startAngle = 30*16;
    int spanAngle = 120*16;
    painter.drawArc(rectangle, startAngle, spanAngle); // 绘制圆弧

    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.drawRect(160, 20, 50, 40);
    QBrush brush(QColor(0,0,225), Qt::Dense4Pattern);
    painter.setBrush(brush);
    painter.drawEllipse(220,20,50,50);
    brush.setTexture(QPixmap("D:/Documents/QtCreatorQuick/QtCreatorQuickStart/mydrawing/yafeilinux.png"));
    painter.setBrush(brush);
    static const QPointF points[4] = {
        QPointF(270.0, 80.0),
        QPointF(290.0, 10.0),
        QPointF(350.0, 30.0),
        QPointF(390.0, 70.0)
    };
    painter.drawPolygon(points, 4);  // 使用点的数组绘制多边形

    painter.fillRect(QRect(10, 100, 150, 20), QBrush(Qt::darkYellow));
    painter.eraseRect(QRect(50, 0, 50, 120));
}
