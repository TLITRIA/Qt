#ifndef MYKEYEVENT_H
#define MYKEYEVENT_H

#include <QWidget>

namespace Ui {
class MyKeyEvent;
}

class MyKeyEvent : public QWidget
{
    Q_OBJECT

public:
    explicit MyKeyEvent(QWidget *parent = nullptr);
    ~MyKeyEvent();
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    Ui::MyKeyEvent *ui;
    // bool keyUp;
    // bool keyLeft;
    // bool keyMove;
};

#endif // MYKEYEVENT_H
