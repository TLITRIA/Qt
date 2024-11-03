#include "mykeyevent.h"
#include "ui_mykeyevent.h"

#include <QKeyEvent>
#include <QDebug>

MyKeyEvent::MyKeyEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyKeyEvent)
{
    ui->setupUi(this);

    setFocus();     // 使主界面获得焦点

    // keyLeft = false;
    // keyUp = false;
    // keyMove = false;
}

MyKeyEvent::~MyKeyEvent()
{
    delete ui;
}

void MyKeyEvent::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
        qDebug() << "press:" << event->isAutoRepeat();
}

void MyKeyEvent::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        qDebug() << "release:" << event->isAutoRepeat();
        qDebug() << "up";
    }
}
