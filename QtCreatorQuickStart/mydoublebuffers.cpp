#include "mydoublebuffers.h"
#include "ui_mydoublebuffers.h"

#include <QMouseEvent>
#include <QPainter>>

MyDoubleBuffers::MyDoubleBuffers(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyDoubleBuffers)
    , isDrawing(false)
{
    ui->setupUi(this);
    pix = QPixmap(400, 300);
    pix.fill(Qt::white);
    tempPix = pix;
}

MyDoubleBuffers::~MyDoubleBuffers()
{
    delete ui;
}

void MyDoubleBuffers::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        startPoint = event->pos();
        isDrawing = true;
    }
}

void MyDoubleBuffers::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        endPoint = event->pos();
        isDrawing = false;
        update();
    }
}

void MyDoubleBuffers::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        endPoint = event->pos();
        tempPix = pix;
        update();
    }
}

void MyDoubleBuffers::paintEvent(QPaintEvent *event)
{
    int x = startPoint.x();
    int y = startPoint.y();
    int w = endPoint.x() - x;
    int h = endPoint.y() - y;
    QPainter painter;
    painter.begin(&tempPix);
    painter.drawRect(x, y, w, h);
    painter.end();
    painter.begin(this);
    painter.drawPixmap(0, 0, tempPix);
    if(!isDrawing)
        pix = tempPix;
}
