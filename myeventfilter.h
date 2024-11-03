#ifndef MYEVENTFILTER_H
#define MYEVENTFILTER_H

#include <QWidget>

namespace Ui {
class MyEventFilter;
}

class MyEventFilter : public QWidget
{
    Q_OBJECT

public:
    explicit MyEventFilter(QWidget *parent = nullptr);
    ~MyEventFilter();

    bool eventFilter(QObject *obj, QEvent *event);
private:
    Ui::MyEventFilter *ui;
};

#endif // MYEVENTFILTER_H
