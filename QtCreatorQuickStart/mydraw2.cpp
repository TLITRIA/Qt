#include "mydraw2.h"
#include "ui_mydraw2.h"

#include <QPainter>
#include <QPainterPath>
MyDraw2::MyDraw2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyDraw2)
{
    ui->setupUi(this);
}

MyDraw2::~MyDraw2()
{
    delete ui;
}

void MyDraw2::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
#if 0 // 绘制文字
    QRectF rect(10.0, 10.0, 380.0, 280.0);
    painter.setPen(Qt::red);
    painter.drawRect(rect);
    painter.setPen(Qt::blue);
    painter.drawText(rect, Qt::AlignHCenter, tr("AlignHCenter"));
    painter.drawText(rect, Qt::AlignLeft, tr("AlignLeft"));
    painter.drawText(rect, Qt::AlignRight, tr("AlignRight"));
    painter.drawText(rect, Qt::AlignVCenter, tr("AlignVCenter"));
    painter.drawText(rect, Qt::AlignBottom, tr("AlignBottom"));
    painter.drawText(rect, Qt::AlignCenter, tr("AlignCenter"));
    painter.drawText(rect, Qt::AlignBottom | Qt::AlignRight
                     , tr("Qt::AlignBottom \n Qt::AlignRight"));
    /*      所在矩形        对齐方式    内容*/


    QFont font("宋体", 15, QFont::Bold, true); /*字体   字号  加粗  倾斜*/
    font.setUnderline(true);
    font.setOverline(true);
    font.setCapitalization(QFont::SmallCaps);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 10); //
    // 使用字体
    painter.setFont(font);
    painter.setPen(Qt::green);
    painter.drawText(120, 80, tr("yafeilinux"));
    painter.translate(100, 100);
    painter.rotate(90);
    painter.drawText(0, 0, tr("hello"));
#endif


#if 0 // 绘制路径 -组成一个路径
    QPainterPath path;
    path.moveTo(50, 250);   //  移动当前点到
    path.lineTo(50, 230);   // 从当前点绘制一条直线到
    path.cubicTo(QPointF(105, 40), QPointF(115, 80), QPointF(120, 60)); // 从当前点到点120,60绘制一条三次贝塞尔曲线
    path.lineTo(130, 130);

    path.addEllipse(QPoint(130, 130), 30, 30);
    painter.drawPath(path);
    path.translate(200, 0);
    painter.setPen(Qt::darkBlue);
    painter.drawPath(path);
#endif

    // #if 0 // 绘制路径 -填充原则
    QPainterPath path;
    path.addEllipse(10, 50, 100, 100);
    path.addRect(50, 100, 100, 100);
    painter.setBrush(Qt::cyan);
    painter.drawPath(path);

    painter.translate(180, 0);
    path.setFillRule(Qt::WindingFill);
    painter.drawPath(path);

}
