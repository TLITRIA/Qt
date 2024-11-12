#ifndef MYEVENT_H
#define MYEVENT_H

#include <QWidget>

namespace Ui {
class MyEvent;
}

class MyLineEdit;

class MyEvent : public QWidget
{
    Q_OBJECT

public:
    explicit MyEvent(QWidget *parent = nullptr);
    ~MyEvent();

    bool eventFilter(QObject *obj, QEvent *event);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MyEvent *ui;
    MyLineEdit *lineEdit;
};

#endif // MYEVENT_H
