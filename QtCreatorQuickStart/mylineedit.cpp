#include "mylineedit.h"

#include <QKeyEvent>
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent):
    QLineEdit(parent)
{

}

bool MyLineEdit::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
        qDebug() <<  tr("MyLineEvent的event函数");
    return QLineEdit::event(event);
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("MyLineEdit键盘按下事件");
    QLineEdit::keyPressEvent(event); // 执行QlineEdit类默认事件处理
    event->ignore();
}
