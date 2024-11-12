#include "mytimerevent.h"
#include "ui_mytimerevent.h"

#include <QTimer>
#include <QTime>
#include <QDebug>

MyTimerEvent::MyTimerEvent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyTimerEvent)
{
    ui->setupUi(this);

    id1 = startTimer(1000);
    id2 = startTimer(1500);
    id3 = startTimer(2200);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MyTimerEvent::timerUpdate);
    timer->start(1000);

    srand(QTime(0,0,0).secsTo(QTime::currentTime())); // secsTo两时间点之间的描述设置初始值使得每次启动程序都有不同的值初始化srand

    QTimer::singleShot(10000, this, &QWidget::close); // 一次只运行一次的定时器
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

void MyTimerEvent::timerUpdate()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if((time.second() % 2) == 0) text[2] = ' '; // 每隔1S闪烁":"
    ui->lcdNumber->display(text);

    int rrand = rand() % 300;
    ui->lcdNumber->move(rrand, rrand);
}


