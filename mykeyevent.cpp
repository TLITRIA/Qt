#include "mykeyevent.h"
#include "ui_mykeyevent.h"

#include <QKeyEvent>

MyKeyEvent::MyKeyEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyKeyEvent)
{
    ui->setupUi(this);
}

MyKeyEvent::~MyKeyEvent()
{
    delete ui;
}

void MyKeyEvent::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)   // 是否按下ctrl
    {
        if(event->key() == Qt::Key_M)
            setWindowState(Qt::WindowMaximized); // 窗口最大化
    }
    else
        QWidget::keyPressEvent(event);
}

void MyKeyEvent::keyReleaseEvent(QKeyEvent *event)
{

}
