#ifndef MYMOUSEEVENT_H
#define MYMOUSEEVENT_H

#include <QWidget>

namespace Ui {
class MyMouseEvent;
}

class MyMouseEvent : public QWidget
{
    Q_OBJECT

public:
    explicit MyMouseEvent(QWidget *parent = nullptr);
    ~MyMouseEvent();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void whellEvent(QWheelEvent *event);
private:
    Ui::MyMouseEvent *ui;
    QPoint offset;      // 鼠标指针与窗口的差值
};

#endif // MYMOUSEEVENT_H
