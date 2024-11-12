#ifndef MYDRAW2_H
#define MYDRAW2_H

#include <QWidget>

namespace Ui {
class MyDraw2;
}

class MyDraw2 : public QWidget
{
    Q_OBJECT

public:
    explicit MyDraw2(QWidget *parent = nullptr);
    ~MyDraw2();
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::MyDraw2 *ui;
};

#endif // MYDRAW2_H
