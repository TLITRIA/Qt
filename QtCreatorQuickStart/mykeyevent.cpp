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

    keyLeft = false;
    keyUp = false;
    move = false;
}

MyKeyEvent::~MyKeyEvent()
{
    delete ui;
}

void MyKeyEvent::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        if(event->isAutoRepeat())
            return;
        keyUp = true;
    }
    else if(event->key() == Qt::Key_Left)
    {
        if(event->isAutoRepeat()) return;
        keyLeft = true;
    }
}

void MyKeyEvent::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        if(event->isAutoRepeat()) return;
        keyUp = false;
        if(move)
        {
            move = false;
            return;
        }
        if(keyLeft)
        {
            ui->pushButton->move(30, 80);
            move = true;
        } else {
            ui->pushButton->move(120, 80);
        }
    } else if(event->key() == Qt::Key_Left)
    {
        if(event->isAutoRepeat()) return;
        keyLeft = false;
        if(move)
        {
            move = false;
            return;
        }
        if(keyUp)
        {
            ui->pushButton->move(30, 80);
            move = true;
        } else {
            ui->pushButton->move(30, 120);
        }
    } else if(event->key() == Qt::Key_Down)
    {
        ui->pushButton->move(120, 120);
    }
}
