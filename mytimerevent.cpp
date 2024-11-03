#include "mytimerevent.h"
#include "ui_mytimerevent.h"

#include <QDebug>
MyTimerEvent::MyTimerEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyTimerEvent)
{
    ui->setupUi(this);

    id1 = startTimer(1000);
    id2 = startTimer(1500);
    id3 = startTimer(2200);
}

MyTimerEvent::~MyTimerEvent()
{
    delete ui;
}

void MyTimerEvent::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1)
        qDebug() << "timer1";
    else if(event->timerId() == id2)
        qDebug() << "timer2";
    else if(event->timerId() == id3)
        qDebug() << "timer3";
}
