#include "mytransformation.h"
#include "ui_mytransformation.h"


#include <QPainter>
#include <QToolTip>
#include <QMouseEvent>
#include <QTimer>

MyTransformation::MyTransformation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyTransformation)
    ,  timer(new QTimer(this))
    , angle(0)
{
    ui->setupUi(this);

    setMouseTracking(true); // 不用按下鼠标按键也能触发鼠标移动事件

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

MyTransformation::~MyTransformation()
{
    delete ui;
}

void MyTransformation::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
#if 0 // 各种绘制
    painter.fillRect(rect(), Qt::white);
    painter.setPen(QPen(Qt::red, 11));
    painter.drawLine(QPoint(5, 6), QPoint(100, 99));
    painter.translate(200, 150);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawLine(QPoint(5, 6), QPoint(100, 99));

    painter.save();
    painter.rotate(90);
    painter.setPen(Qt::cyan);
    painter.drawLine(QPoint(5, 6), QPoint(100, 99));
    painter.restore();

    painter.setBrush(Qt::darkGreen);
    painter.drawRect(-50, -50, 100, 50);
    painter.save();
    painter.scale(0.5, 0.4);
    painter.setBrush(Qt::yellow);
    painter.drawRect(-50, -50, 100, 50);
    painter.restore();

    painter.setPen(Qt::blue);
    painter.setBrush(Qt::darkYellow);
    painter.drawEllipse(QRect(60, -100, 50, 50));
    painter.shear(1.5, -0.7);
    painter.setBrush(Qt::darkGray);
    painter.drawEllipse(QRect(60, -100, 50, 50));
#endif
#if 0
#if 0 // 视口与窗口
    painter.setWindow(-50, -50, 100, 100); // 现在逻辑坐标的（-50， -50）对应窗口左上角的原点
    painter.setBrush(Qt::green);
    painter.drawRect(0, 0, 20, 20);
    // 拖动窗口可以发现矩形长宽比变化
#else
    int side = qMin(width(), height());
    int x = (width() / 2);
    int y = (height() / 2);
    // 设置视口
    painter.setViewport(x, y, side, side);
    painter.setWindow(0,0,100,100);
    painter.setBrush(Qt::green);
    painter.drawRect(0,0,20,20);
    // 拖动窗口可以发现矩形长宽比不发生`变化
#endif
#endif
    angle += 10;
    if(angle == 360)
        angle = 0;
    int side = qMin(width(), height());
    painter.setRenderHint(QPainter::Antialiasing);
    QTransform transform;
    transform.translate(width() /2 , height() / 2);
    transform.scale(side/300.0, side/300.0);
    transform.rotate(angle);
    painter.setWorldTransform(transform);
    painter.drawEllipse(-120, -120, 240, 240);
    painter.drawLine(0, 0, 100, 0);
}

void MyTransformation::mouseMoveEvent(QMouseEvent *event)
{
    QString pos = QString("%1, %2")
                      .arg(event->pos().x())
                      .arg(event->pos().y()); // 获取物理坐标
    QToolTip::showText(event->globalPosition().toPoint(), pos, this);

}
