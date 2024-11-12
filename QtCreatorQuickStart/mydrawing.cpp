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
    painter.setPen(pen);
    QRectF rectangle(70.0, 40.0, 80.0, 60.0);
    int startAngle = 30*16;
    int spanAngle = 120*16;
    painter.drawArc(rectangle, startAngle, spanAngle); // 绘制圆弧
}
