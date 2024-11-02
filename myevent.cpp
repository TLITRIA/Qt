#include "myevent.h"
#include "ui_myevent.h"

#include "mylineedit.h"

#include <QKeyEvent>
#include <QDebug>

MyEvent::MyEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyEvent)
{
    ui->setupUi(this);
    lineEdit = new MyLineEdit(this);
    lineEdit->move(100, 100);
    lineEdit->installEventFilter(this); // 在widget上为lineEvent安装事件过滤器
}

MyEvent::~MyEvent()
{
    delete ui;
}

bool MyEvent::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == lineEdit)
        if(event->type() == QEvent::KeyPress)
            qDebug() << tr("Widget的事件过滤器");
    return QWidget::eventFilter(obj, event);
}

void MyEvent::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("Widget键盘按下事件");
}
