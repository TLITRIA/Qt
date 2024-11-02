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
}

MyEvent::~MyEvent()
{
    delete ui;
}

void MyEvent::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("Widget键盘按下事件");
}
