#include "mymouseevent.h"
#include "ui_mymouseevent.h"

#include <QMouseEvent>


MyMouseEvent::MyMouseEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyMouseEvent)
{
    ui->setupUi(this);

    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor); // 设置光标形状
    setCursor(cursor); // 使用光标

    setMouseTracking(true);
}

MyMouseEvent::~MyMouseEvent()
{
    delete ui;
}

void MyMouseEvent::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPos() - pos();    // deprecated
    }
    else if(event->button() == Qt::RightButton)
    {
        QCursor cursor(QPixmap(":/myimages/logo.png"));
        QApplication::setOverrideCursor(cursor);
    }
}

void MyMouseEvent::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);        // 编译时不会出现event相关的警告？
    QApplication::restoreOverrideCursor();  // 恢复鼠标指针形状
}

void MyMouseEvent::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(windowState() != Qt::WindowFullScreen) // 现在不是全屏
            setWindowState(Qt::WindowFullScreen);
        else
            setWindowState(Qt::WindowNoState);  // 恢复以前的大小
    }
}

void MyMouseEvent::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton) // 注意使用buttons
    {
        QPoint temp;
        temp = event->globalPos() - offset;
        move(temp);
    }
}

void MyMouseEvent::whellEvent(QWheelEvent *event)
{
    qDebug() << tr("hello");
    if(event->angleDelta().y() > 0) // 新版delta已经移除
        ui->textEdit->zoomIn();
    else
        ui->textEdit->zoomOut();
}
