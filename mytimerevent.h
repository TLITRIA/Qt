#ifndef MYTIMEREVENT_H
#define MYTIMEREVENT_H

#include <QWidget>

namespace Ui {
class MyTimerEvent;
}

class MyTimerEvent : public QWidget
{
    Q_OBJECT

public:
    explicit MyTimerEvent(QWidget *parent = nullptr);
    ~MyTimerEvent();
protected:
    void timerEvent(QTimerEvent *event);

private:
    Ui::MyTimerEvent *ui;
    int id1, id2, id3;
};

#endif // MYTIMEREVENT_H
